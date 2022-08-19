/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:43:47 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/19 18:07:32 by jgourlin         ###   ########.fr       */
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


 #include "../class/Iterator/reverse_iterator.hpp"
//  #include "../class/vector.hpp"

int main ()
{
		std::cout << std::endl << "VECTOR" << std::endl;

		{
			std::vector<int> alpha(5);
			for (int i = 0; i < 5; i++)
				alpha[i] = i;

			try
			{
				alpha.at(4);
				/* code */
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		{
			std::vector<int> alpha(15, 8);
			std::vector<int> beta(2, 8);

			alpha.reserve(20);
			beta = alpha;

			std::cout << "capacity: "<< alpha.capacity() << " size: " << alpha.size() << std::endl;
			std::cout << "capacity: "<< beta.capacity() << " size: " << beta.size() << std::endl;


			for (std::vector<int>::iterator it=alpha.begin(); it<alpha.end(); it++)
    			std::cout << ' ' << *it;
			std::cout << std::endl;

			for (std::vector<int>::iterator it=beta.begin(); it<beta.end(); it++)
    			std::cout << ' ' << *it;
			std::cout << std::endl;



		}

				std::cout << std::endl << "fin" << std::endl;
	

	return (0);
}