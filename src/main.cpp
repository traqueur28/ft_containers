/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:43:47 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/23 20:24:13 by jgourlin         ###   ########.fr       */
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


# include "../class/Iterator/reverse_iterator.hpp"
# include "../class/vector.hpp"
# include "../class/Utility/proto.hpp"

int main ()
{
		std::cout << RED__ << CHECK <<  DEFAU << std::endl;

		vector_main();
		
		stack_main();

		map_main();


	return (0);
}