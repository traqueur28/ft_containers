/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:27:30 by jgourlin          #+#    #+#             */
/*   Updated: 2022/09/29 11:29:12 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "../map.hpp"
#include <iostream>
#include <cstddef>

namespace ft
{
	template<typename Compare, typename node, typename T>
	class map_iterator
	{
		public:
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;
			typedef	std::ptrdiff_t					difference_type;
			typedef	std::size_t						size_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

		private:
			node 	*_current;
			Compare	_comp;

		public:
			map_iterator(): _current(NULL){}
			map_iterator(node *ptr): _current(ptr), _comp(Compare()) {}
			map_iterator( const map_iterator& other ) { _current = other._current; _comp = other._comp;};

			virtual ~map_iterator(){};

			// Operator

			map_iterator &operator=(map_iterator const &rhs)
			{
				if (this != &rhs)
					this->_current = rhs._current;
				return (*(this));
			}

			map_iterator &operator+=( difference_type n )
			{
				for (int i = 0; i < n; ++i)
					_current++;
				return (*this);
			}

			map_iterator &operator-=( difference_type n )
			{
				for (int i = 0; i < n; ++i)
					_current--;
				return (*this);
			}

			operator map_iterator<Compare, node, T const>() const{
				return (map_iterator<Compare, node, T const>(_current));
			}

			reference operator*() const{
				return (*(_current->_v));
			}
			pointer operator->() const{
				return _current->_v;
			}

			map_iterator &operator++()
			{
				if (_current->_r)
				{
					_current = _current->_r;
					while (_current->_l != NULL)
						_current = _current->_l;
				}
				else if (_current->_r == NULL)
				{
					node *temp = _current;

					if (_current->_p)
					{
						if (_comp(_current->_v->first, _current->_p->_v->first))
								_current = _current->_p;
						else
						{
							while (_current->_p && (!(_comp(_current->_v->first, _current->_p->_v->first))))
								_current = _current->_p;
							if (_current->_p && _comp(_current->_v->first, _current->_p->_v->first))
								_current = _current->_p;

							if (_comp(_current->_v->first, temp->_v->first))
								_current = NULL;
						}
					}
					else
						_current = NULL;
				}
				return *this;
			}

			map_iterator operator++(int)
			{
				node *temp = _current;
				++(*this);
				return (map_iterator(temp));
			}

			map_iterator &operator--()
			{
				if (_current->_l)
				{
					_current = _current->_l;
					while (_current->_r)
						_current = _current->_r;
				}
				else
				{
					while (_current->_p && (_comp(_current->_v->first, _current->_p->_v->first)))
						_current = _current->_p;
					if (_current->_p && (!_comp(_current->_v->first, _current->_p->_v->first)))
						_current = _current->_p;
				}
				return *this;
			}

			map_iterator operator--(int)
			{
				node *temp = _current;
				--(*this);
				return (map_iterator(temp));
			}

			friend bool operator==(const map_iterator& lhs, const map_iterator& rhs){
				return (lhs._current == rhs._current);
				}

			friend bool operator!=(const map_iterator& lhs, const map_iterator& rhs){
				return (lhs._current != rhs._current);
				}

			// node *find_end(node *N)
			// {
			// 	node *temp = N;

			// 	while (temp->_p)
			// 		temp = temp->_p;
			// 	while (temp->_r)
			// 		temp = temp->_r;
			// 	return temp->_end;
			// }

			// node *find_last(node *N)
			// {
			// 	node *temp = N;
			// 	while (temp->_p)
			// 		temp = temp->_p;
			// 	while (temp->_r)
			// 		temp = temp->_r;
			// 	return temp;
			// }

			node	*getnode(){
				return _current;
			}
	};
}

#endif
