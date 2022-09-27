/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:00:10 by jgourlin          #+#    #+#             */
/*   Updated: 2022/09/27 02:10:02 by jgourlin         ###   ########.fr       */
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
# include "Iterator/reverse_iterator.hpp"

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
			typedef typename	ft::reverse_iterator<iterator>						reverse_iterator;
			typedef typename	ft::reverse_iterator<const_iterator>			const_reverse_iterator;

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
				map (const map& x): _alloc(x._alloc), _comp(x._comp), _root(NULL), _size(0){}


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
				const mapped_type &at(const k_type &k) const
				{
					iterator it = find(k);
					if (it != end() && it->first == k)
						return it->second;
					else
						throw std::out_of_range("map");
				}
				// operator[]
				mapped_type &operator[](const k_type &k)
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
					return (iterator(_Min(_root)));
				}
				const_iterator begin() const{
					return (const_iterator(_Min(_root)));
				}

				// end
				iterator end(){
					iterator	it = begin();

					for (size_t i = 0; i <= _size; i++)
						it++;
					return (it);
				}
				const_iterator end() const{
					iterator	it = _Min(_root);

					for (size_t i = 0; i <= _size; i++)
						it++;
					const_iterator res = it;
					return (it);
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

				}

					// with hint
				iterator insert(iterator position, const value_type &val)
				{
					insert(val);
					return (find(val.first));
				}
					//range	
				template <class InputIterator>
				void	insert(InputIterator first, InputIterator last)
				{
					for (;first != last; first++;)
						insert(first);
				}
			
				// erase
				void	erase(iterator pos)
				{}
				// swap

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
					node	*tmp;
					
					if (empty())
						return (end());
					tmp = _Min(_root);
					while (tmp)
					{
						if (_Equal(k, tmp->v))
							return (iterator(tmp));
						tmp = _Next(tmp);
					}
					return (iterator(tmp));
				}
				
				const_iterator find(const key_type &k) const
				{
					node	*tmp;
					
					if (empty())
						
						return (end());
					tmp = _Min(_root);
					while (tmp)
					{
						if (_Equal(k, tmp->v))
							return (const_iterator(tmp));
						tmp = _Next(tmp);
					}
					return (const_iterator(tmp));
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
						if (!_comp(k, tmp->v.first))
							return (iterator(tmp));
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
						if (!_comp(k, tmp->v.first))
							return (const_iterator(tmp));
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
						if (!_comp(k, tmp->v.first) && tmp->v.first != k)
							return (iterator(tmp));
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
						if (!_comp(k, tmp->v.first) && tmp->v.first != k)
							return (const_iterator(tmp));
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

			node	*_New_node(const value_type &value, node *parent)
			{
				node *N = _alloc_node.allocate(1);
				_alloc_node.construct(N, node());
				N->_l = NULL;
				N->_r = NULL;
				N->_p = parent;
				N->_v = _alloc_pair.allocate(1);
				_alloc_pair.construct(N->_v, value);
				return (N);
			}

			void	_Init_null()
			{
				_root = _New_node(value_type(key_type(), mapped_type()), NULL);
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

			void	_Travel(node *N, const Key &key, size_t *res) const
			{
				if (_Equal(key, N->v))
					res++;
				if (N->l)
					_Travel(N->l, key, res);
				if (N->r)
					_Travel(N->r, key, res);
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

			bool	_Equal(const Key &k1, const value_type k2) const{
				return (!_comp(k1, k2.first) && !_comp(k2.first, k1));
			}

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
		// operator!=
		// operator<
		// operator<=
		// operator>
		// operator>=

 		// ft::swap(ft::map)
}//ft

#endif
