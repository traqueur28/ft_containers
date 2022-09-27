/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:18:00 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/24 07:03:58 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

// https://cplusplus.com/reference/utility/pair/?kw=pair
// https://en.cppreference.com/w/cpp/utility/pair

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		public:
			// Members types
			typedef T1	first_type;
			typedef	T2	second_type;

			// Members variables
			first_type	first;
			second_type	second;

			// Conctructor

			//	Default
			pair() :first(), second(){}

			// Copy
			template< class U1, class U2 >
			pair(const pair<U1, U2> &p) : first(p.first), second(p.second){}
			
			//pair(const pair &p) = default {}

			// Initialization
			pair(const T1 &x, const T2 &y) : first(x), second(y){}

			// Operator=
			pair &operator=(const pair &pr)
			{
				if (this != &pr)
				{
					first = pr.first;
					second = pr.second;
				}
				return (*this);
			}

			// Destructor
			~pair(){}
	};
	// Non-member functions

	template <class T1, class T2>
	pair<T1,T2>	make_pair (T1 x, T2 y){
		return pair<T1, T2>(x, y);
	}

	template <class T1, class T2>
  	bool operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
  	bool operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs){
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
  	bool operator< (const pair<T1,T2> &lhs, const pair<T1,T2> &rhs){
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
  	bool operator<=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs){
		return (!(rhs < lhs));
	}

	template <class T1, class T2>
  	bool operator> (const pair<T1,T2> &lhs, const pair<T1,T2> &rhs){
		return (rhs < lhs);
	}

	template <class T1, class T2>
  	bool operator>=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs){
		return (!(rhs < lhs));
	}
}

#endif