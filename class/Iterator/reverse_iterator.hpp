/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:54:02 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/18 12:21:54 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

//	https://cplusplus.com/reference/iterator/reverse_iterator/
//	https://en.cppreference.com/w/cpp/iterator/reverse_iterator

#include "iterator_traits.hpp"

namespace ft
{
	template <class It>
	class reverse_iterator
	{
		public:
			typedef It	iterator_type;
			typedef typename ft::iterator_traits<It>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<It>::value_type value_type;
			typedef typename ft::iterator_traits<It>::difference_type difference_type;
			typedef typename ft::iterator_traits<It>::pointer pointer;
			typedef typename ft::iterator_traits<It>::reference reference;
			
			//Default Constructor
			reverse_iterator(void) : _ptr(iterator_type()){}

			//Initialization Constructor
			explicit reverse_iterator(iterator_type x): _ptr(x){}


			//Copy Constructor
			
			template< class U >
			reverse_iterator(const reverse_iterator<U>& other){
				_ptr = other.base();
			}

			//Destructor
			virtual	~reverse_iterator(void){}

			//Operator
			template< class U >
			reverse_iterator	&operator=(const reverse_iterator<U>& other ){
				_ptr = other._ptr;
				return (*this);
			}
			
			// Accesses the underlying iterator

			iterator_type	base(void) const{
				return (_ptr);
			}

			//Accesses the pointed-to element

			reference	operator*() const{
				iterator_type	tmp = _ptr;
				return *(--tmp);
			}

			pointer		operator->() const{
				return &(operator*());
			}

			//Accesses an element by index

			reference	operator[] (difference_type n) const{
				return base()[-n - 1];
			}

			//Advances or decrements the iterator
			
			reverse_iterator	&operator++(){
				--_ptr;
				return (*this);
			}

			reverse_iterator	&operator--(){
				++_ptr;
				return (*this);
			}

			reverse_iterator	operator++(int){
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			reverse_iterator	operator--(int){
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			reverse_iterator	operator+( difference_type n ) const{
				return reverse_iterator(_ptr - n);
			}

			reverse_iterator	operator-( difference_type n ) const{
				return reverse_iterator(_ptr + n);
			}

			reverse_iterator	&operator+=( difference_type n ){
				_ptr -= n;
				return (*this);
			}

			reverse_iterator	&operator-=( difference_type n ){
				_ptr += n;
				return (*this);
			}
	
		private:
			iterator_type	_ptr;
	};

	// Compares the underlying iterators

	template< class Iterator1, class Iterator2 >
	bool	operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() == rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool	operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() != rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool	operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() > rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool	operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() >= rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool	operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() < rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool	operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it){
		return (rev_it + n);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){
		return (rhs.base() - lhs.base());
	}

};

#endif