/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:30:44 by jgourlin          #+#    #+#             */
/*   Updated: 2022/10/03 19:57:22 by jgourlin         ###   ########.fr       */
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
# include "../stack.hpp"
# include "../map.hpp"

// STL
# include <vector>
# include <stack>
# include <map>
# include <set>


// OTHER
# include <iostream>

// vector_main.cpp

	void	vector_main();
	void	title(std::string str, std::string color, size_t n);
// stack_main.cpp
	void	stack_main();

// map_main.cpp
	void	map_main();

# endif