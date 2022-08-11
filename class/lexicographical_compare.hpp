/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:27:41 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/11 02:37:07 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE
# define LEXICOGRAPHICAL_COMPARE

//	https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
//	https://www.cplusplus.com/reference/algorithm/lexicographical_compare/

namespace ft
{
	template <class T, class U>
	bool	lexicographical_compare (T first1, T last1, U first2, U last2)
	{
    	for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 )
		{
        	if (*first1 < *first2)
				return true;
        	if (*first2 < *first1)
				return false;
    	}
    	return (first1 == last1) && (first2 != last2);
	}

	template <class T, class U, class Compare>
	bool	lexicographical_compare (T first1, T last1, U first2, U last2, Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
        	if (comp(*first1, *first2))
				return true;
        	if (comp(*first2, *first1))
				return false;
    	}
   		return (first1 == last1) && (first2 != last2);
	}
}

#endif