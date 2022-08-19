/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:55:32 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/17 15:06:14 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

// https://en.cppreference.com/w/cpp/types/is_integral
// https://cplusplus.com/reference/type_traits/is_integral/

namespace ft
{
template <class T>
struct is_integral{
	static const bool value = false;
};

template<>
struct is_integral<bool>{
	static const bool value = true;
};

template<>
struct is_integral<char>{
	static const bool value = true;
};

template<>
struct is_integral<wchar_t>{
	static const bool value = true;
};

template<>
struct is_integral<signed char>{
	static const bool value = true;
};

template<>
struct is_integral<short int>{
	static const bool value = true;
};

template<>
struct is_integral<int>{
	static const bool value = true;
};

template<>
struct is_integral<long int>{
	static const bool value = true;
};

template<>
struct is_integral<long long int>{
	static const bool value = true;
};

template<>
struct is_integral<unsigned char>{
	static const bool value = true;
};

template<>
struct is_integral<unsigned short int>{
	static const bool value = true;
};

template<>
struct is_integral<unsigned int>{
	static const bool value = true;
};

template<>
struct is_integral<unsigned long int>{
	static const bool value = true;
};

template<>
struct is_integral<unsigned long long int>{
	static const bool value = true;
};
}


#endif