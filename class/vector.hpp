/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:00:47 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/19 18:12:26 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

// https://cplusplus.com/reference/vector/vector/?kw=vector
// https://en.cppreference.com/w/cpp/container/vector

// https://cplusplus.com/reference/memory/allocator/

# include "Iterator/reverse_iterator.hpp"
# include "Iterator/random_access_iterator.hpp"

# include "Algorithm/equal.hpp"
# include "Algorithm/lexicographical_compare.hpp"

# include "Type_traits/enable_if.hpp"
# include "Type_traits/is_integral.hpp"

# include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef	T			value_type;
			typedef	Allocator	allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef ft::random_access_iterator<T>			iterator;
			typedef ft::random_access_iterator<const T>	const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t		size_type;

			// Constructor https://cplusplus.com/reference/vector/vector/vector/

			//Default
			explicit vector (const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {}	

			//FIll
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _ptr(NULL), _capacity(n), _size(n)
			{
				_ptr = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_ptr + i, val);
			}

			//Range
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _ptr(NULL), _size(0), _capacity(0)
			{
				size_type	n = last - first;
				
				reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_ptr + 1, *(first + i));
				_size = n;
			}

			//Copy
			vector (const vector& x): _alloc(x._alloc), _ptr(NULL), _size(x._size), _capacity(x.capacity)
			{
				_ptr = _alloc.allocate(x.capacity());
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_ptr + i, x._ptr[i]);
			}

			// Destructor https://cplusplus.com/reference/vector/vector/~vector/

			~vector()
			{
				_alloc.deallocate(_ptr, _size);
			}

			// Operator= https://cplusplus.com/reference/vector/vector/operator=/
			vector	&operator= (const vector &x)
			{
				clear();
				if (_capacity < x._size)
					reserve(x._size);
				_size = x._size;
				for (size_t i = 0; i < x._size; i++)
					_alloc.construct(_ptr + i, x._ptr[i]);
				return (*this);
			}


			// Iterators:
			
			iterator begin(){
				return (iterator(_ptr));
			}
			const_iterator begin() const{
				return (iterator(_ptr));
			}

			iterator end(){
				return (iterator(_ptr + _size));
			}
			const_iterator end() const{
				return (iterator(_ptr + _size));
			}

			reverse_iterator rbegin(){
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend(){
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const{
				return (const_reverse_iterator(begin()));
			}

			// Capacity:

			size_type size() const{
				return (_size);
			}
			
			size_type max_size() const{
				return (_alloc.max_size());
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_ptr + i);
				}
				else if (n > _size)
				{
					reserve(n);
					for (size_type i = _size; i < n; i++)
						_alloc.construct(_ptr + i, val);
				}
				_size = n;
			}

			size_type capacity() const {
				return (_capacity);
			}

			bool empty() const{
				return (!_size);
			}

			void reserve (size_type n)
			{
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > _capacity)
				{
					pointer tmp = _alloc.allocate(n);
					for (size_t i = 0; i < _size; i++)
					{
						_alloc.construct(tmp + i, _ptr[i]);
						_alloc.destroy(_ptr + i);
					}
					_alloc.desallocate(_ptr, _capacity);
					_ptr = tmp;
					_capacity = n;
				}
			}

			// Element access:

			reference operator[] (size_type n){
				return (_ptr[n]);
			}
			const_reference operator[] (size_type n) const{
				return (_ptr[n]);
			}

			reference at (size_type n)
			{
				if (n >= _size)
				{
					throw std::out_of_range(
						std::string("vector::at error n >= size");
					)
				}
				return (_ptr[n]);
			}
			const_reference at (size_type n) const
			{
				if (n >= _size)
				{
					throw std::out_of_range(
						std::string("vector::at error n >= size");
					)
				}
				return (_ptr[n]);
			}

			reference front(){
				return (_ptr[0]);
			}
			const_reference front() const{
				return (_ptr[n]);
			}

			reference back(){
				return (_ptr[_size - 1]);
			}
			const_reference back() const{
				return (_ptr[_size -1]);
			}

			value_type* data(){
				return (_ptr);
			}

			const value_type* data() const{
				return (_ptr);
			}

			// Modifiers:

			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last) // range
			{
				size_type n = last - first;

				reserve(n);
				for (size_type i = 0; i < n; i++)
				{
					_alloc.destroy(_ptr + i);
					_alloc.contruct(_ptr + i, *(first + i));
				}
				_size = n;
			}

			void assign (size_type n, const value_type& val) // fill
			{
				reserve(n);
				for (size_type i = 0; i < n; i++)
				{
					_alloc.destroy(_ptr + i);
					_alloc.contruct(_ptr + i, val);
				}
				_size = n;

			}

			void push_back (const value_type& val)
			{
				if (_size + 1 > _capacity)
					_Augment_capacity(_size + 1);
				_alloc.construct(_ptr + _size, val);
				_size++;
			}

			void pop_back()
			{
				_alloc.destroy(_ptr + _size);
				_size--;
			}


			iterator insert (iterator position, const value_type& val) // single element
			{
				size_type	n = position - begin();

				if (_size + 1 > _capacity)
					_Augment_capacity(_size + 1);
				_Replace_right(n, 1);
				_alloc.construct(_ptr + pos, val);
				_size++;
				return (_ptr);
			}

    		void insert (iterator position, size_type n, const value_type& val) // fill
			{
				size_type	pos = position - begin();

				if (_size + n > _capacity)
					_Augment_capacity(_size + n);
				_Replace_right(pos, n);
				while (n--)
					_alloc.construct(_ptr + pos++, val);
				_size -= n;
				return (_ptr);
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last) // range
			{
				size_type	pos = position - begin();
				size_type	n = last - first;

				if (_size + n > _capacity)
					_Augment_capacity(_size + n);
				_Replace_right(pos, n);
				while (n--)
				{
					_alloc.construct(_ptr + pos++, *first);
					first++;
				}
				_size -= n;
				return (_ptr);
			}

			iterator erase (iterator position){
				size_type	n = position - begin();

				_alloc.destroy(_ptr + n);
				_Replace_left(n, 1);
				_size--;
				return (_ptr + n);
			}
			iterator erase (iterator first, iterator last){
				size_type	deb = first - begin();
				size_type	end = last - begin();
				size_type	n = last - first;

				while (*first != *last){
					_alloc.destroy(&(*first));
					first++;
				}
				_Replace_left(deb, end - deb);
				_size -= n;
				return (_ptr + n);
			}

			void swap (vector& x)
			{
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_ptr, x._ptr);
				std::swap(_alloc, x._alloc);
			}

			void clear(){
				if (_ptr)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_ptr + i);
				}
				_size = 0;
			}

			// Allocator:
			allocator_type get_allocator() const{
				return (_alloc);
			}





			private:
				allocator_type	_alloc;
				pointer			_ptr;
				size_type		_size;
				size_type		_capacity;

				void	_Augment_capacity(size_type n)
				{
					if (!_capacity)
						_capacity = 1;
					while (_capacity < n)
						_capacity *= 2;
					reserve(_capacity);
				}

				void	_Replace_right(size_type deb, size_type n)
				{
					size_type	i = _size - 1;

					while (i >= pos && i)
					{
						_alloc.construct(_ptr + i + n, _ptr[i]);
						_alloc.destroy(_ptr + i);
						i--;
					}
				}

				void	_Replace_left(size_type deb, size_type n)
				{
					while (deb < _size && pos + n < _capacity; pos++)
					{
						_alloc.contruct(_ptr + deb, _ptr[deb + n]);
						_alloc.destroy(_ptr + pos + n);
					}
				}
	};

	// Non-member function overloads

		//relational operators

		template <class T, class Alloc>
			bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
			{
				if (lhs.size() != rhs.size())
					return (false);
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

		template <class T, class Alloc>
			bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
				return !(lhs == rhs);
			}

		template <class T, class Alloc>
			bool operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

		template <class T, class Alloc>
			bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
				return !(rhs < lhs);
			}

		template <class T, class Alloc>
			bool operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
				return (rhs < lhs);
			}

		template <class T, class Alloc>
			bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){
				return !(lhs < rhs);
			}

		// Swap

		template <class T, class Alloc>
			void swap(vector<T, Alloc> &x, vector<T, Alloc> &y){
				x.swap(y);
			}
}

#endif