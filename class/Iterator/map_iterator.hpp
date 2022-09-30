/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:27:30 by jgourlin          #+#    #+#             */
/*   Updated: 2022/09/30 14:56:28 by jgourlin         ###   ########.fr       */
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
			node	*_end;
			Compare	_comp;

		public:
			map_iterator(): _current(NULL){}
			map_iterator(node *ptr, node *end): _current(ptr), _end(end),_comp(Compare()) {}
			map_iterator( const map_iterator& other )
			{
				_current = other._current;
				_end = other._end;
				_comp = other._comp;
			};

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
				return (map_iterator<Compare, node, T const>(_current, NULL));
			}

			reference operator*() const{
				return (*(_current->_v));
			}
			pointer operator->() const{
				return _current->_v;
			}

			map_iterator &operator++()
			{
//  std::cout << &_current << std::endl;
				if (_current == _end)
					return *this;

				if (_current->_r)
				{
					_current = _current->_r;
					while (_current->_l)
						_current = _current->_l;
				}
				else
				{
					while (_current->_p && _comp(_current->_p->_v->first, _current->_v->first))// ttant que fils> pere
						_current = _current->_p;
					if (_current->_p && _comp(_current->_v->first, _current->_p->_v->first)) //fils < pere
						_current = _current->_p;
					else // plus de pere alors current etait le plus grand
						_current = _end;//_end

	
				}
				// std::cout << &_current << std::endl;
				return *this;
			}

			map_iterator operator++(int)
			{
				map_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}

			map_iterator &operator--()
			{
				if (_current->_l != NULL)
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
				return (map_iterator(temp, NULL));
			}

			friend bool operator==(const map_iterator& lhs, const map_iterator& rhs){
				return (lhs._current == rhs._current);
				}

			friend bool operator!=(const map_iterator& lhs, const map_iterator& rhs){
				return (lhs._current != rhs._current);
				}
	};
}

#endif
