/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reverse_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:34:56 by jgourlin          #+#    #+#             */
/*   Updated: 2022/09/30 09:26:59 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REVERSE_ITERATOR
#define MAP_REVERSE_ITERATOR

#include "iterator_traits.hpp"

namespace ft
{
	template< class Iter >
	class map_reverse_iterator
	{
		public:
			typedef				Iter											iterator_type;
			typedef typename	std::random_access_iterator_tag					iterator_category;
			typedef typename	iterator_traits<Iter>::difference_type			difference_type;
			typedef typename	iterator_traits<Iter>::value_type				value_type;
			typedef typename	iterator_traits<Iter>::pointer					pointer;
			typedef typename	iterator_traits<Iter>::reference				reference;

			// Constructor
			map_reverse_iterator(): _it() {}
			explicit map_reverse_iterator( iterator_type x ) { _it = x;}
			map_reverse_iterator( map_reverse_iterator const & other ) { _it = other._it;};
			template <class U>
			map_reverse_iterator( const map_reverse_iterator<U>& other ) { _it = other.base();};

			map_reverse_iterator & operator=(map_reverse_iterator const  &rhs) { _it = rhs._it; return (*this);}
			map_reverse_iterator & operator+=( difference_type n ) { _it -=n; return (*this);}
			map_reverse_iterator & operator-=( difference_type n ) { _it +=n; return (*this);}

			// Accessor

			reference operator*()
			{
				Iter temp = _it;
				--temp;
				return *temp;
			}

			pointer operator->() const
			{
				Iter temp = base();
				temp--;
				return temp.operator->();
			}

			reference operator[](difference_type n) const
			{  return *(*this + n);}

			iterator_type base() const { return _it;}

			// Operator

			map_reverse_iterator &operator++() { _it--; return *this;}
			map_reverse_iterator &operator--() { _it++; return *this;}
			map_reverse_iterator operator++(int) { map_reverse_iterator temp = *this; _it--; return (temp);}
			map_reverse_iterator operator--(int) { map_reverse_iterator temp = *this; _it++; return (temp);}

			map_reverse_iterator operator+( difference_type n ) const
			{ return map_reverse_iterator(_it - n);}
			map_reverse_iterator operator-( difference_type n ) const
			{ return map_reverse_iterator(_it + n);}

			difference_type operator+(const map_reverse_iterator & x)  { return (this->base() + x.base());}
			difference_type operator-(const map_reverse_iterator & x)  { return (x.base() - this->base());}

			private:
				iterator_type	_it;
				typedef iterator_traits<Iter> traits_type;
	};

	// Non Members

	template <class _Iterator>
	bool operator==(const map_reverse_iterator<_Iterator> &lhs, const map_reverse_iterator<_Iterator> &rhs){
		return (lhs.base() == rhs.base());
	}

	template <class _Iterator>
	bool operator<(const map_reverse_iterator<_Iterator> &lhs, const map_reverse_iterator<_Iterator> &rhs){
		return (rhs.base() < lhs.base());
	}

	template <class _Iterator>
	bool operator!=(const map_reverse_iterator<_Iterator> &lhs, const map_reverse_iterator<_Iterator> &rhs){
		return (!(lhs == rhs));
	}

	template <class _Iterator>
	bool operator<=(const map_reverse_iterator<_Iterator> &lhs, const map_reverse_iterator<_Iterator> &rhs){
		return !(rhs < lhs);
	}

	template <class _Iterator>
	bool operator>(const map_reverse_iterator<_Iterator> &lhs, const map_reverse_iterator<_Iterator> &rhs){
		 return rhs < lhs;
	}

	template <class _Iterator>
	bool operator>=(const map_reverse_iterator<_Iterator> &lhs, const map_reverse_iterator<_Iterator> &rhs){
		return !(lhs < rhs);
	}

	template <class _IteratorL, class _IteratorR>
	bool operator==(const map_reverse_iterator<_IteratorL> &lhs, const map_reverse_iterator<_IteratorR> &rhs){
		return (lhs.base() == rhs.base());
	}

	template <class _IteratorL, class _IteratorR>
	bool operator<(const map_reverse_iterator<_IteratorL> &lhs, const map_reverse_iterator<_IteratorR> &rhs){
		return (rhs.base() < lhs.base());
	}

	template <class _IteratorL, class _IteratorR>
	bool operator!=(const map_reverse_iterator<_IteratorL> &lhs, const map_reverse_iterator<_IteratorR> &rhs){
		return (!(lhs == rhs));
	}

	template <class _IteratorL, class _IteratorR>
	bool operator<=(const map_reverse_iterator<_IteratorL> &lhs, const map_reverse_iterator<_IteratorR> &rhs){
		return !(rhs < lhs);
	}

	template <class _IteratorL, class _IteratorR>
	bool operator>(const map_reverse_iterator<_IteratorL> &lhs, const map_reverse_iterator<_IteratorR> &rhs){
		return rhs < lhs;
	}

	template <class _IteratorL, class _IteratorR>
	bool operator>=(const map_reverse_iterator<_IteratorL> &lhs, const map_reverse_iterator<_IteratorR> &rhs){
		return !(lhs < rhs);
	}

	template< class Iter >
	map_reverse_iterator<Iter>
	operator+( typename map_reverse_iterator<Iter>::difference_type n, const map_reverse_iterator<Iter>& it ){
		return map_reverse_iterator<Iter>(it.base() - n);
	}

	template< class Iter >
	map_reverse_iterator<Iter>
	operator-( typename map_reverse_iterator<Iter>::difference_type n, const map_reverse_iterator<Iter>& it ){
		return map_reverse_iterator<Iter>(it.base() + n);
	}

}

#endif