/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:59:16 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/03 18:25:08 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

template <class T, class U>
bool    equal(T first1, T last1, U first2)
{
    for (; first1 != last1; ++first1, ++first2)
        if (!(*first1 == *first2))
            return (false);
        return (true);
}


template <class T, class U, class V>
bool    equal(T first1, T last1, U first2, V pred)
{
    for (; first1 != last1; ++first1, ++first2)
        if (!p(*first1, *first2))
            return (false);
    return (true);
}

#endif