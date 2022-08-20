/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:30:44 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/20 19:07:32 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PROTO_HPP
# define PROTO_HPP

# define RED__ "\033[31m"
# define GREEN "\033[32m"
# define YELLO "\033[33m"
# define BLUE_ "\033[34m"
# define PURPL "\033[35m"
# define CYAN_ "\033[36m"
# define GREY_ "\033[37m"
# define DEFAU "\033[0m"

# if STD
	# define PRE std
	# define CHECK "std"
# else
	# define PRE ft
	# define CHECK "ft"
# endif

// FT
# include "../vector.hpp"

// STL
# include <vector>


// OTHER
# include <iostream>

// vector_main.cpp

	bool	vector_main();

# endif