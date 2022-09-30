/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:00:10 by jgourlin          #+#    #+#             */
/*   Updated: 2022/09/30 15:02:19 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

// https://en.cppreference.com/w/cpp/container/map
// https://cplusplus.com/reference/map/map/?kw=map

# include <iostream>
# include "Utility/pair.hpp"
# include "Map/node.hpp"
# include "Iterator/map_iterator.hpp"
# include "Iterator/map_reverse_iterator.hpp"
# include "Algorithm/lexicographical_compare.hpp"

namespace ft
{

	template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			// Member Types
			typedef	Key								key_type;
			typedef	T								mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef	std::size_t						size_type;
			typedef	std::ptrdiff_t					difference_type;
			typedef	Compare							key_compare;
			typedef	Allocator						allocator_type;

			typedef 			value_type&						reference;
			typedef 			const value_type&				const_reference;
			typedef typename 	allocator_type::pointer			pointer;
			typedef typename 	allocator_type::const_pointer	const_pointer;

			typedef typename	ft::map_iterator<Compare, node<value_type>, value_type >			iterator;
			typedef typename	ft::map_iterator<Compare, node<value_type>, const value_type > 		const_iterator;
			typedef typename	ft::map_reverse_iterator<iterator>						reverse_iterator;
			typedef typename	ft::map_reverse_iterator<const_iterator>			const_reverse_iterator;

			// Member classes
			class value_compare
			{
				public:
					value_compare(Compare c): comp(c){}
					bool operator()(const value_type &lhs, const value_type &rhs) const{
						return (comp(lhs.first, rhs.first));
					}
							
				protected:
					Compare	comp;
			};

			// Member functions

				// (constructor)
					// Empty
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _comp(comp), _root(NULL), _size(0){
					_Init_null();
				}
					
					// range
				template <class InputIterator>
  				map (InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()):
				_alloc(alloc), _comp(comp), _root(NULL), _size(0){
					_Init_null();
					insert(first, last);
				}
					// Copy
				map (const map& x): _alloc(x._alloc), _comp(x._comp), _root(NULL), _size(0)
				{
					_Init_null();
					insert(x.begin(), x.end());
				}


				// (destructor)
				~map(){
					clear();
				}
				// operator=
				// get_allocator
				allocator_type get_allocator() const{
					return (_alloc);
				}


			// Element access
				// at
				mapped_type &at(const key_type &k)
				{
					iterator it = find(k);
					if (it != end() && it->first == k)
						return it->second;
					else
						throw std::out_of_range("map");
				}
				const mapped_type &at(const key_type &k) const
				{
					iterator it = find(k);
					if (it != end() && it->first == k)
						return it->second;
					else
						throw std::out_of_range("map");
				}
				// operator[]
				mapped_type &operator[](const key_type &k)
				{
					iterator it = find(k);
					if (it != end() && it->first == k)
						return it->second;
					else
					{
						value_type	add(k,T());
						insert(add);
					}
					it = find(k);
					return it->second;
				}
			
			// Iterators
				// begin
				iterator begin(){
					if (!_size)
						return (iterator(_root, _end));
					return (iterator(_Min(_root), _end));
				}
				const_iterator begin() const{
					if (!_size)
						return (const_iterator(NULL, _end));
					return (const_iterator(_Min(_root), _end));
				}

				// end
				iterator end(){
					if (!_size)
					 	return (iterator(NULL, _end));
					return (iterator(_end, _end));
				}
				const_iterator end() const{
					if (!_size)
					 	return (const_iterator(NULL, _end));
					return (const_iterator(_end, _end));
				}

				// rbegin
				reverse_iterator rbegin(){
					return (reverse_iterator(end()));
				}
				const_reverse_iterator rbegin() const{
					return (const_reverse_iterator(end()));
				}
				// rend
				reverse_iterator rend(){
					return (reverse_iterator(begin()));
				}
				const_reverse_iterator rend() const{
					return (const_reverse_iterator(begin()));
				}


			// Capacity
				// empty
				bool empty() const{
					return (!_size);
				}
				// size
				size_type size() const{
					return (_size);
				}
				// max_size
				size_type max_size() const{
					return (_alloc_node.max_size());
				}


			// Modifiers
				// clear
				void clear()
				{
					if (_size)
					{
						_Clear_tree(_root);
						_size = 0;
					}	
				}
				// insert
					// single element
				pair<iterator,bool>	insert(const value_type &val)
				{
					size_type	size_tmp = _size;
					node	*tmp;
					if (empty())
					{
						_root = _New_node(val, NULL, 0);
						_size++;
					}
					else
					{
						tmp = _Insert_node(_root, val);
						if (!tmp)
							return pair<iterator, bool>(find(val.first), size_tmp != size());
						_size++;
						_Coloring(tmp);
					}
					if (_end->_p == NULL)
						_end->_p = _root;
					else
					{
						node *node_max = _Max(_root);
						if (_comp(_end->_p->_v->first, node_max->_v->first))
							_end->_p = node_max;
					}
					return pair<iterator, bool>(find(val.first), size_tmp != size());
				}

					// with hint
				iterator insert(iterator position, const value_type &val)
				{
					static_cast<void>(position);
					insert(val);
					return (find(val.first));
				}
					//range	
				template <class InputIterator>
				void	insert(InputIterator first, InputIterator last)
				{
					for (;first != last; first++)
						insert(*first);
				}
			
				// erase
				void	erase(iterator pos);
				
				// swap
				void swap(map &other)
				{
					std::swap(_comp, other._comp);
					std::swap(_root, other._root);
					std::swap(_alloc_pair, other._alloc_pair);
					std::swap(_alloc, other._alloc);
					std::swap(_alloc_node, other._alloc_node);
					std::swap(_size, other._size);
					std::swap(_end, other._end);
				}

			// Lookup
				// count
				size_type count(const Key &key) const
				{	
					size_t	res = 0;
					_Travel(_root, key, &res);
					return (res);
				}

				// find
				iterator find(const key_type &k)
				{
					node	*tmp = _root;

					 if (empty())
					 	return (end());
					while (1)
					{
						if (tmp->_v->first == k)
							return (iterator(tmp, _end));
						else if (k > tmp->_v->first && tmp->_r)
							tmp = tmp->_r;
						else if (k < tmp->_v->first && tmp->_l)
							tmp = tmp->_l;
						else
							return (iterator(_end, _end));
					}
					// while (tmp)
					// {
					// 	res = tmp;
					// 	if (tmp->_v->first == k)
					// 		return (iterator(tmp, _end));
					// 	tmp = _Next(tmp);
					// }
					// return (end());
				}
				
				const_iterator find(const key_type &k) const
				{
					node	*tmp;
					
					if (empty())
					return (end());
					tmp = _root;
					while (1)
					{
						if (tmp->_v->first == k)
							return (const_iterator(tmp, _end));
						else if (k > tmp->_v->first && tmp->_r)
							tmp = tmp->_r;
						else if (k < tmp->_v->first && tmp->_l)
							tmp = tmp->_l;
						else
							return (end());
					}
				}

				// equal_range
				ft::pair<iterator, iterator> equal_range(const key_type &k){
					return (ft::make_pair(lower_bound(k), upper_bound(k)));
				}
				ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const{
					return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
				}

				// lower_bound
				// iterator sur le premier >=
				iterator lower_bound (const key_type &k){
					node	*tmp;
					if (empty())
						return (end());
					tmp = _Min(_root);
					while (tmp)
					{
						if (!_comp(k, tmp->_v->first))
							return (iterator(tmp, _end));
						tmp = _Next(tmp);
					}
					return (end());
				}
				const_iterator lower_bound (const key_type &k) const{
					node	*tmp;

					if (empty())
						return (end());
					tmp = _Min(_root);
					while (tmp)
					{
						if (!_comp(k, tmp->_v->first))
							return (const_iterator(tmp, _end));
						tmp = _Next(tmp);
						
					}
					return (end());
				}

				// upper_bound
				// iterator sur le premier >
				iterator upper_bound (const key_type &k){
					node	*tmp;
					
					if (empty())
						return (end());
					tmp = _Min(_root);
					while (tmp)
					{
						if (!_comp(k, tmp->_v->first) && tmp->_v->first != k)
							return (iterator(tmp, _end));
						tmp = _Next(tmp);
					}
					return (end());
				}
				const_iterator upper_bound (const key_type &k) const{
					node	*tmp;
					
					if (empty())
						return (end());
					tmp = _Min(_root);
					while (tmp)
					{
						if (!_comp(k, tmp->_v->first) && tmp->_v->first != k)
							return (const_iterator(tmp, _end));
						tmp = _Next(tmp);
					}
					return (end());
				}


			// Observers
				// key_comp
				key_compare key_comp() const{
					return (_comp);
				}
				// value_comp
				value_compare value_comp() const{
					return (value_compare(Compare()));
				}




		private:
		
			typedef node<value_type>	node;
			typedef typename	allocator_type::template	rebind<node>::other	alloc_node;
			// typedef std::allocator<ft::node<T > >	alloc_node;



			allocator_type	_alloc;
			allocator_type	_alloc_pair;
			alloc_node		_alloc_node;
			key_compare		_comp;
			node			*_root;
			size_type		_size;
			node			*_end;

			node	*_New_node(const value_type &value, node *parent, bool color)
			{
				node *N = _alloc_node.allocate(1);
				_alloc_node.construct(N, node());
				N->_l = NULL;
				N->_r = NULL;
				N->_p = parent;
				N->_color = color;
				N->_v = _alloc_pair.allocate(1);
				_alloc_pair.construct(N->_v, value);
				return (N);
			}

			void	_Init_null(){
				_end = _New_node(value_type(key_type(), mapped_type()), NULL, 0);
			}

			void	_Free_node(node *N)
			{
				if (N->_v)
				{
					_alloc_pair.deallocate(N->_v, 1);
					N->_v = NULL;
				}
				_alloc_node.deallocate(N, 1);
				_alloc_node.destroy(N);
				N = NULL;
			}

			node	*_Right_rotate(node *current)
			{
				node	*left = current->_l;
				node	*right = left->_r;

				left->_r = current;
				current->_l = right;
				current->_p = left;
				if (right)
					right->_p = current;
				return (left);
			}

			node	*_Left_rotate(node *current)
			{
				node	*right = current->_r;
				node	*left = right->_l;

				right->_l = current;
				current->_r = left;
				current->_p = right;
				if (left)
					left->_p = current;
				return (right);
			}

			// -------------- current = grandfather
			void	_Left_left_case(node *current) // Right rotate grandParent
			{
				bool tmp = current->_color;
				current->_color = current->_l->_color;
				current->_l->_color = tmp;

				if (current == _root)
				{
					_root = _Right_rotate(current);
					_root->_p = NULL;
				}
				else
				{
					node	*parent = current->_p;
					if (parent->_r == current)
					{
						parent->_r = _Right_rotate(current);
						current->_p->_p = parent;
					}
					else
					{
						parent->_l = _Right_rotate(current);
						current->_p->_p = parent;
					}
				}
				//return (_Right_rotate(current));
			}	

			void	_Right_right_case(node *current) // Left rotate grandParent
			{
				bool tmp = current->_color;
				current->_color = current->_r->_color;
				current->_r->_color = tmp;

				if (current == _root)
				{
					_root = _Left_rotate(current);
					_root->_p = NULL;
				}
				else
				{
					node	*parent = current->_p;
					if (parent->_r == current)
					{
						parent->_r = _Left_rotate(current);
						current->_p->_p = parent;
					}
					else
					{
						parent->_l = _Left_rotate(current);
						current->_p->_p = parent;
					}
				}
				//return (Left_rotate(current));
			}

			void	_Left_right_case(node *current) // left par - right gp
			{
				bool tmp = current->_color;
				current->_color = current->_l->_r->_color;
				current->_l->_r->_color = tmp;

				current->_l = _Left_rotate(current->_l);

				if (current == _root)
				{
					_root = _Right_rotate(current);
					_root->_p = NULL;
				}
				else
				{
					node	*parent = current->_p;
					if (parent->_r == current)
					{
						parent->_r = _Right_rotate(current);
						current->_p->_p = parent;
					}
					else
					{
						parent->_l = _Right_rotate(current);
						current->_p->_p = parent;
					}
				}
				//return (_Right_rotate(current));
			}

			void	_Right_left_case(node *current) // right par - left gp
			{
				bool tmp = current->_color;
				current->_color = current->_r->_l->_color;
				current->_r->_l->_color = tmp;

				current->_r = _Right_rotate(current->_r);

				if (current == _root)
				{
					_root = _Left_rotate(current);
					_root->_p = NULL;
				}
				else
				{
					node	*parent = current->_p;
					if (parent->_r == current)
					{
						parent->_r = _Left_rotate(current);
						current->_p->_p = parent;
					}
					else
					{
						parent->_l = _Left_rotate(current);
						current->_p->_p = parent;
					}
				}
				//return (_Left_rotate(current));
			}	
			// --------------

			node	*_Insert_node(node *current, const value_type &val)
			{
				if (val.first == current->_v->first)
					return (NULL);

				if (val.first > current->_v->first && current->_r)
					return (_Insert_node(current->_r, val));
				else if (val.first > current->_v->first && !current->_r)
				{
					current->_r = _New_node(val, current, 1);
					return (current->_r); //right
				}
				else if (val.first < current->_v->first && current->_l)
					return (_Insert_node(current->_l, val));
				else if (val.first < current->_v->first && !current->_l)
				{
					current->_l = _New_node(val, current, 1);
					return (current->_l); //left
				}
				return (NULL);
			}

			node	*_Uncle(node *current)
			{
				node	*tmp;

				tmp = current->_p;
				if (tmp->_p->_r == tmp)
					return (tmp->_p->_l);
				return (tmp->_p->_r);
			}

			void	_Coloring(node *current)
			{
				node	*uncle;

				if (current == _root) // if root then black
					current->_color = 0;
				if (current != _root && current->_p->_color == 1) //if parent = red
				{
					uncle = _Uncle(current);
					if (uncle == NULL || !uncle->_color) //if uncle is black
					{
						if (current->_p == current->_p->_p->_l) // p == l
						{
							if (current == current->_p->_l) // current == l
								_Left_left_case(current->_p->_p);
							else // current == r
								_Left_right_case(current->_p->_p);
						}
						else // if p == r
						{
							if (current == current->_p->_l) // current == l
								_Right_left_case(current->_p->_p);
							else // current == r
								_Right_right_case(current->_p->_p);

						}
					}
					else //if uncle is red
					{
						uncle->_color = 0;			// uncle become black
						current->_p->_color = 0;	// paren become black
						uncle->_p->_color = 1;		// gd-pr become red
						_Coloring(uncle->_p);// grand-father coloring
					}
				}

			}

			void	_Travel(node *N, const Key &key, size_t *res) const
			{
				if (key == N->_v->first)
					(*res)++;
				if (N->_l)
					_Travel(N->_l, key, res);
				if (N->_r)
					_Travel(N->_r, key, res);
			}

			void	_Clear_tree(node *N)
			{
				if (N)
				{
					if (N->_l)
						_Clear_tree(N->_l);
					if (N->_r)
						_Clear_tree(N->_r);
					_Free_node(N);
				}
				_root = NULL;
			}

			// bool	_Equal(const Key &k1, const Key &k2) const{
			// 	return (!_comp(k1, k2) && !_comp(k2, k1));
			// }

			node	*_Min(node *p) const
			{
				node	*tmp = p;

				while (tmp->_l)
					tmp = tmp->_l;
				return (tmp);
			}

			node	*_Max(node *p) const
			{
				node	*tmp = p;

				while (tmp->_r)
					tmp = tmp->_r;
				return (tmp);
			}

			node	*_Next(node *p) const
			{
				node	*tmp = p;

				if (p->_r)
					return (_Min(p->_r));
				while (tmp->_p)
				{
					tmp = tmp->_p;
					if (tmp->_v >= p->_v)
						return (tmp);
				}
				return (NULL);
				
			}

			node	*_Prev(node *p) const
			{
				node	*tmp = p;

				if (p->_l)
					return (_Max(p->_l));
				while (tmp->_p)
				{
					tmp = tmp->_p;
					if (tmp->_v <= p->_v)
						return (tmp);
				}
				return (NULL);
		}



	}; // map

	// Non-member functions
		// operator==
		template < typename Key, typename T, typename Compare, typename Allocator >
		bool operator==(const ft::map<Key,T,Compare,Allocator> &lhs, const ft::map<Key,T,Compare,Allocator> &rhs)
		{
			if (lhs.size() != rhs.size())
				return (0);
			typename ft::map<Key, T, Compare, Allocator>::const_iterator it_r = rhs.begin();
			typename ft::map<Key, T, Compare, Allocator>::const_iterator it_l = lhs.begin();
			while (it_l != lhs.end())
			{
				if (*it_l != *it_r)
					return (0);
				it_l++;
				it_r++;
			}
			return (1);
		}

		// operator!=
		template < typename Key, typename T, typename Compare, typename Allocator >
		bool operator!=(const ft::map<Key,T,Compare,Allocator> &lhs, const ft::map<Key,T,Compare,Allocator> &rhs){
			return (!(lhs == rhs));
		}

		// operator<
		template < typename Key, typename T, typename Compare, typename Allocator >
		bool operator<(const ft::map<Key,T,Compare,Allocator> &lhs, const ft::map<Key,T,Compare,Allocator> &rhs){
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		// operator<=
		template < typename Key, typename T, typename Compare, typename Allocator >
		bool operator<=(const ft::map<Key,T,Compare,Allocator> &lhs, const ft::map<Key,T,Compare,Allocator> &rhs)
		{
			if (lhs == rhs)
				return (1);
			return (lhs < rhs);
		}
		// operator>
		template < typename Key, typename T, typename Compare, typename Allocator >
		bool operator>(const ft::map<Key,T,Compare,Allocator> &lhs, const ft::map<Key,T,Compare,Allocator> &rhs)
		{
			if (lhs == rhs)
				return (0);
			return (!(lhs < rhs));
		}

		// operator>=
		template < typename Key, typename T, typename Compare, typename Allocator >
		bool operator>=(const ft::map<Key,T,Compare,Allocator> &lhs, const ft::map<Key,T,Compare,Allocator> &rhs)
		{
			if (lhs == rhs)
				return (1);
			return (!(lhs < rhs));
		}

 		// ft::swap(ft::map)
		template < typename Key, typename T, typename Compare, typename Allocator >
		void swap(ft::map<Key,T,Compare,Allocator> &lhs, ft::map<Key,T,Compare,Allocator> &rhs ){
			lhs.swap(rhs);
		}
}//ft

#endif
