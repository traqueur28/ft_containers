/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:00:26 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/22 00:38:12 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

// https://cplusplus.com/reference/stack/stack/
// https://en.cppreference.com/w/cpp/container/stack

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef				Container					container_type;
			typedef	typename	Container::value_type		value_type;
			typedef	typename	Container::size_type		size_type;
			typedef	typename	Container::reference		reference;
			typedef	typename	Container::const_reference	const_reference;


		//Member functions

			// constructor
			// Default
			explicit stack(const Container &cont = Container()) : c(cont)
			{}

			// Copy
			stack(const stack &other) : c(other.c)
			{}

			// destructor
			virtual ~stack(){}
 
			// operator=
			stack &operator=(const stack &other)
			{
				c = other.c;
				return (*this);
			}

	//	Element access

		// top
		value_type &top(){
			return (c.back());
		}
		const value_type &top() const{
			return (c.back());
		}

 

	// Capacity
		// empty
		bool empty() const {
			return (c.empty());
		}
		// size
		size_type size() const {
			return (c.size());
		}


	// Modifiers
		// push
		void push(const value_type &value){
			c.push_back(value);
		}

		// pop
		void pop(){
			c.pop_back();
		}

		// Member Objects
		protected:
			container_type	c;
			
		// Non-member functions
		//operator==
		friend bool operator==(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
			return (lhs.c == rhs.c);
		}

		//operator!=
		friend bool operator!=(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
			return (lhs.c != rhs.c);
		}

		//operator<
		friend bool operator< (const stack<T,Container> &lhs, const stack<T,Container> &rhs){
			return (lhs.c <  rhs.c);
		}

		//operator<=
		friend bool operator<=(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
			return (lhs.c <= rhs.c);
		}

		//operator>
		friend bool operator> (const stack<T,Container> &lhs, const stack<T,Container> &rhs){
			return (lhs.c >  rhs.c);
		}

		//operator>=
		friend bool operator>=(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
			return (lhs.c >= rhs.c);
		}
	};
}

#endif