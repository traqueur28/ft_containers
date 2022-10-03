/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:22:50 by jgourlin          #+#    #+#             */
/*   Updated: 2022/10/03 19:59:36 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../class/Utility/proto.hpp"

void	map_main()
{
	title("MAP", RED__, 0);
	{
		PRE::map<int, int>	alpha;
		std::cout << "test end vide "<< std::endl;
		PRE::map<int, int>::const_iterator qwe = alpha.end();
		alpha.insert(PRE::pair<int, int>(1, -1));
		std::cout << "test end 1 elem "<< std::endl;
		PRE::map<int, int>::const_iterator asd = alpha.end();

		static_cast<void>(qwe);
		static_cast<void>(asd);
		for (int i = 9; i >= 0; i--)
				alpha.insert(PRE::pair<int, int>(i, -i));

		PRE::map<int, int>::iterator it1 = alpha.begin();
		PRE::map<int, int>::iterator it2 = alpha.end();
		while (it1 != it2)
		{
			std::cout << "UwU" << std::endl;
			std::cout << it1->first << " => " << it1->second << '\n';
			it1++;
		}
	}

	{
std::cout << "MAP PHASE 2" << std::endl;
		// PRE::map<int, int>	bravo; //map vide
		// PRE::map<int, int>::iterator it1 = bravo.begin();
		// PRE::map<int, int>::iterator it2 = bravo.end();

		// std::cout << "begin = " << &it1 << std::endl;
		// std::cout << "end   = " << &it2 << std::endl;

		// std::cout << "begin() empty = " << it1->first << " - " << it1->second << std::endl;
		// bravo.insert(PRE::pair<int, int>(42, 666));
		// bravo.insert(PRE::pair<int, int>(41, 66));
		// bravo.insert(PRE::pair<int, int>(43, 66));

		// it1 = bravo.begin();
		// it2 = bravo.end();

		// std::cout << "begin = " << &it1 << std::endl;
		// std::cout << "end   = " << &it2 << std::endl;
		// while (it1 != it2)
		// {
		// 	std::cout << "b begin = " << &it1 << " " << it1->first << std::endl;
		// 	std::cout << "b end   = " << &it2 << " " << it2->first << std::endl;
		// 	++it1;
		// }


		// std::cout << "begin() meme non vide = " << it1->first << " - " << it1->second << std::endl;
		// PRE::map<int, int>::iterator UWU = bravo.begin();
		// std::cout << "begin() empty = " << UWU->first << " - " << UWU->second << std::endl;
	}

	{
		std::cout << "MAP PHASE 3" << std::endl;
		PRE::map<int, int>	bravo;
		for (int i = 9; i >= 0; i--)
				bravo.insert(PRE::pair<int, int>(i, -i));
		PRE::map<int, int>::iterator it(bravo.begin());
		++it;
		std::cout << "it = "<< it->first<< std::endl;
		it++;
		std::cout << "it = "<< it->first<< std::endl;
		it++;
		std::cout << "it = "<< it->first<< std::endl;
		++it;
		std::cout << "it = "<< it->first<< std::endl;
		++it;
		std::cout << "it = "<< it->first<< std::endl;
		++it;
		std::cout << "it = "<< it->first<< std::endl;
		++it;
		std::cout << "it = "<< it->first<< std::endl;
		++it;
		while (it != bravo.end())
		{
			std::cout << "it = "<< it->first<< std::endl;
			it++;
		}
		
		std::cout << "it = "<< &it<< std::endl;

		
		std::cout << "pre end"<< std::endl;
		PRE::map<int, int>::iterator ite(bravo.end());
		std::cout << "sub end"<< std::endl;
		std::cout << "pre --ite= "<< &ite<< std::endl;
		--ite;
		std::cout << "pre ite--= "<< &ite<< std::endl;
		ite--;
		std::cout << "ite = "<< &ite<< std::endl;

	}

	std::cout << std::endl << "MAP PHASE 4" << std::endl;
	{


	}
	std::cout << std::endl << "MAP PHASE 5" << std::endl;
	{
		PRE::map<char, int>	a;

		a['a'] = 2;
		a['b'] = 1;
		a['c'] = 0;
		a['d'] = 4;

		PRE::map<char, int>::const_iterator it = a.begin();
		PRE::map<char, int>::const_iterator it2;

		while (it != a.end())
		{
			std::cout << "--" << std::endl;
			it2 = a.begin();
			while (it2 != a.end())
			{
				std::cout << "++" << std::endl;
				std::cout << it->first << " " << it2->first << std::endl;
				it2++;
			}
			it++;

		}

	}
	std::cout << std::endl << "MAP PHASE 5" << std::endl;
	{
		PRE::map<int, int> mp;

		PRE::map<int, int>::iterator it = mp.begin();
		PRE::map<int, int>::iterator ite = mp.end();
		while (it != ite)
		{
			std::cout << it->first << std::endl;
			it++;
		}
		mp[42] = 28;
		it = mp.begin();
		while (it != ite)
		{
			std::cout << it->first << std::endl;
			it++;
		}
		mp.clear();
		it = mp.begin();
		while (it != ite)
		{
			std::cout << it->first << std::endl;
			it++;
		}
	}
	std::cout << std::endl << "MAP PHASE 6" << std::endl;
	{
		PRE::map<int, int> mp;

		for (int i = 0; i < 9; i++)
		{
			mp.insert(PRE::pair<int, int>(i * 3, i*2));
			std::cout << i * 3 << " " << mp[i * 3] << std::endl;
		}

		std::cout << "LOWER" << std::endl;	
		std::cout << "lower_bound(6) = " << mp.lower_bound(6)->first << std::endl;
		std::cout << "UPPER" << std::endl;
		std::cout << "upper_bound(6) = " << mp.upper_bound(6)->first << std::endl;

		std::cout << "LOWER" << std::endl;	
		std::cout << "lower_bound(5) = " << mp.lower_bound(5)->first << std::endl;
		std::cout << "UPPER" << std::endl;
		std::cout << "upper_bound(5) = " << mp.upper_bound(5)->first << std::endl;
		std::cout << "end" << std::endl;


	}
	std::cout << std::endl << "MAP DOUBLON 6" << std::endl;
	{
		PRE::map<int, int> mp;
		for (int i = 0; i < 9; i++)
		{
			mp.insert(PRE::pair<int, int>(i * 3, i*2));
			std::cout << i * 3 << " " << mp[i * 3] << std::endl;
		}
		for (int i = 0; i < 9; i++)
		{
			mp.insert(PRE::pair<int, int>(i * 3, 67));
			std::cout << i * 3 << " " << mp[i * 3] << std::endl;
		}
	}
	{


	}

}