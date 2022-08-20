/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:43:47 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/20 16:26:14 by jgourlin         ###   ########.fr       */
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


		std::cout << std::endl << "VECTOR" << std::endl;
		if (vector_main())
			std::cout << std::endl << "VECTOR true" << std::endl;
		else
			std::cout << std::endl << "VECTOR false" << std::endl;


		std::cout << std::endl << "END VECTOR" << std::endl;
		// {
		// 	ft::vector<int> bravo;
		// }

		// {
		// 	ft::vector<int> alpha(5);
		// 	for (int i = 0; i < 5; i++)
		// 		alpha[i] = i;

		// 	try
		// 	{
		// 		alpha.at(4);
		// 		/* code */
		// 	}
		// 	catch(const std::exception& e)
		// 	{
		// 		std::cerr << e.what() << '\n';
		// 	}
		// }
		// {
		// 	ft::vector<int> alpha(4, 42);
		// 	for (ft::vector<int>::iterator it=alpha.begin(); it<alpha.end(); it++)
    	// 		std::cout << ' ' << *it;
		// 	std::cout << std::endl;
		// }
		// {
		// 	ft::vector<int> alpha(4, 42);
		// 	ft::vector<int> beta(alpha.begin(), alpha.end());

		// 	alpha.reserve(20);
		// 	beta = alpha;

		// 	std::cout << "capacity: "<< alpha.capacity() << " size: " << alpha.size() << std::endl;
		// 	std::cout << "capacity: "<< beta.capacity() << " size: " << beta.size() << std::endl;


		// 	for (ft::vector<int>::iterator it=alpha.begin(); it<alpha.end(); it++)
    	// 		std::cout << ' ' << *it;
		// 	std::cout << std::endl;

		// 	for (ft::vector<int>::iterator it=beta.begin(); it<beta.end(); it++)
    	// 		std::cout << ' ' << *it;
		// 	std::cout << std::endl;



		// }

		// 		std::cout << std::endl << "fin" << std::endl;
	

	return (0);
}