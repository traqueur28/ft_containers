/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:43:47 by jgourlin          #+#    #+#             */
/*   Updated: 2022/10/08 18:30:03 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iterator>
# include <stack>
# include <vector>
# include <utility> 
# include <map>
# include <string>
# include <compare>

# include <time.h>
#include <math.h> 

# include "../class/Utility/proto.hpp"

int main ()
{
	clock_t deb;
	clock_t end;

	 	 std::cout << RED__ << CHECK <<  DEFAU << std::endl;

	deb = clock();
		vector_main();
	end = clock() - deb;
	std::cout << "vector timer: "<< end << std::endl;
	

	deb = clock();
		stack_main();
	end = clock() - deb;
	std::cout << "stack timer: "<< end << std::endl;

	deb = clock();
		map_main();
	end = clock() - deb;
	std::cout << "map timer: "<< end << std::endl;

	return (0);
}