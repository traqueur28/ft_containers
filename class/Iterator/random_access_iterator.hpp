/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:25:44 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/19 17:49:26 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

// https://cplusplus.com/reference/iterator/RandomAccessIterator/

namespace ft
{
	template <class T>
	class random_access_iterator
	{
		public:
			typedef std::random_access_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef T*									pointer;
			typedef T&									reference;

			// Default Constructor
			random_access_iterator(void) : _ptr(NULL){}

			// Copy Constructor
			explicit random_access_iterator(pointer ptr) : _ptr(ptr){}

			// operator
			random_access_iterator(const random_access_iterator &x) : _ptr(x._ptr){}

			// copy assignable
			random_access_iterator &operator=(const random_access_iterator &x)
			{
				_ptr = x._ptr;
				return *this;
			}

			//D structor
			~random_access_iterator(void){}

			// Accessor
			pointer	getPtr(void){
				return _ptr;
			}

			// Const iterator cast
			operator random_access_iterator<T const>(void) const{
				return random_access_iterator<T const>(_ptr);
			}

			// equality and inequality operators
			bool	operator==(const random_access_iterator &rhs) const{
				return (_ptr == rhs._ptr);
			}

			bool	operator!=(const random_access_iterator &rhs) const{
				return (_ptr != rhs._ptr);
			}

			//Accesses the pointed-to element
			reference	operator*(void) const{
				return *_ptr;
			}

			pointer	operator->(void) const{
				return _ptr;
			}

			//Advances or decrements the iterator
			random_access_iterator	&operator++(void){
				++_ptr;
				return *this;
			}

			random_access_iterator	operator++(int){
				random_access_iterator	tmp = *this;
				++_ptr;
				return tmp;
			}

			random_access_iterator	&operator--(void){
				--_ptr;
				return *this;
			}

			random_access_iterator	operator--(int){
				random_access_iterator	tmp = *this;
				--_ptr;
				return tmp;
			}

			random_access_iterator	operator+(const difference_type &n) const{
				return random_access_iterator(_ptr + n);
			}

			difference_type	operator+(const random_access_iterator &rhs) const{
				return (_ptr + rhs._ptr);
			}

			random_access_iterator	operator-(const difference_type &n) const{
				return random_access_iterator(_ptr - n);
			}

			difference_type	operator-(const random_access_iterator &rhs) const{
				return (_ptr - rhs._ptr);
			}

			random_access_iterator	&operator+=(const difference_type &n) const
			{
				_ptr += n;
				return *this;
			}

			random_access_iterator	&operator-=(const difference_type &n) const
			{
				_ptr -= n;
				return *this;
			}
			
			// relational operators
			bool	operator<(const random_access_iterator &rhs) const{
				return (_ptr < rhs._ptr);
			}

			bool	operator>(const random_access_iterator &rhs) const{
				return (_ptr > rhs._ptr);
			}

			bool	operator<=(const random_access_iterator &rhs) const{
				return (_ptr <= rhs._ptr);
			}

			bool	operator>=(const random_access_iterator &rhs) const{
				return (_ptr >= rhs._ptr);
			}


			// offset dereference operator
			value_type	&operator[](size_t n) const{
				return *(_ptr + n);
			}
		
		private:
			pointer	_ptr;
	};
}

#endif