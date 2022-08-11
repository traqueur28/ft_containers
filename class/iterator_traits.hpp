/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 02:42:33 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/11 03:06:31 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

//	https://en.cppreference.com/w/cpp/iterator/iterator_traits
//	https://www.cplusplus.com/reference/iterator/iterator_traits/

namespace ft
{
	//generic definition
	template <class Iterator>
	class iterator_traits
	{
		typedef typename	Iterator::difference_type difference_type;
		typedef typename	Iterator::value_type value_type;
		typedef typename	Iterator::pointer pointer;
		typedef typename	Iterator::reference reference;
		typedef typename	Iterator::iterator_category iterator_category;
	};

	//T* specialization
	template <class T>
	class iterator_traits<T*>
	{
		typedef	std::ptrdiff_t difference_type;
		typedef	T value_type;
		typedef	T* pointer;
		typedef	T& reference;
		typedef	random_access_iterator_tag iterator_category;
	};

	//const T* specialization
	template <class T>	
	class iterator_traits<const T*>;
	{
		typedef	std::ptrdiff_t difference_type;
		typedef	T value_type;
		typedef	const T* pointer;
		typedef	const T& reference;
		typedef	random_access_iterator_tag iterator_category;
	};
}
#endif