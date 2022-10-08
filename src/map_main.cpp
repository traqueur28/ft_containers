/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:22:50 by jgourlin          #+#    #+#             */
/*   Updated: 2022/10/08 05:41:07 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../class/Utility/proto.hpp"

void	map_main()
{
	title("MAP", RED__, 0);
	{

	}

	title("Constructor", CYAN_, 1);
	{
		PRE::map<int,int>	alpha;

		for (int i = 0; i < 8; i++)
			alpha.insert(PRE::pair<int, int>(i, -i));
		for (PRE::map<int,int>::iterator it = alpha.begin(); it != alpha.end(); it++)
			std::cout << "alpha first = " << it->first << " second = " << it->second << std::endl;
		
		std::cout << "Beta is copy of Alpha" << std::endl;
		PRE::map<int,int>	beta(alpha);
		for (PRE::map<int,int>::iterator it = beta.begin(); it != beta.end(); it++)
			std::cout << "beta first = " << it->first << " second = " << it->second << std::endl;

		std::cout << "Charlie range alpha's begin alpha's end" << std::endl;
		PRE::map<int,int>	charlie(alpha.begin(), alpha.end());
		for (PRE::map<int,int>::iterator it = charlie.begin(); it != charlie.end(); it++)
			std::cout << "charlie first = " << it->first << " second = " << it->second << std::endl;
		
		std::cout << "delta = charlie" << std::endl;
		PRE::map<int,int>	delta = charlie;
		for (PRE::map<int,int>::iterator it = delta.begin(); it != delta.end(); it++)
			std::cout << "delta first = " << it->first << " second = " << it->second << std::endl;

	}

	title("Element access", CYAN_, 1);
	{
		PRE::map<char, int>	a;

		a['a'] = 2;
		a['b'] = 1;
		a['c'] = 0;
		a['d'] = 4;
		
		std::cout << "a.at('a') = " << a.at('a') << std::endl;
		std::cout << "a.at('b') = " << a.at('b') << std::endl;
		std::cout << "a.at('c') = " << a.at('c') << std::endl;
		std::cout << "a.at('d') = " << a.at('d') << std::endl;

		std::cout << "action: a.at('a') = 42" << std::endl;
		a.at('a') = 42;
		std::cout << "a.at('a') = " << a.at('a') << std::endl;

		std::cout << "action: a[0] = -1" << std::endl;
		std::cout << "action: a[1] = -123" << std::endl;
		std::cout << "action: a[2] = -42" << std::endl;
		std::cout << "action: a[3] = 84 " << std::endl;
		a[0] = -1;
		a[1] = -123;
		a[2] = -42;
		a[3] = 84;

		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "a[1] = " << a[1] << std::endl;
		std::cout << "a[2] = " << a[2]<< std::endl;
		std::cout << "a[3] = " << a[3] << std::endl;

	}
	title("Bound", CYAN_, 1);
	{
		PRE::map<int, int> mp;

		for (int i = 0; i < 9; i++)
		{
			mp.insert(PRE::pair<int, int>(i * 3, i*2));
			std::cout << i * 3 << " " << mp[i * 3] << std::endl;
		}

		std::cout << "lower_bound(6) = " << mp.lower_bound(6)->first << std::endl;
		std::cout << "upper_bound(6) = " << mp.upper_bound(6)->first << std::endl;

		std::cout << "lower_bound(5) = " << mp.lower_bound(5)->first << std::endl;
		std::cout << "upper_bound(5) = " << mp.upper_bound(5)->first << std::endl;

		PRE::pair<PRE::map<int, int>::iterator, PRE::map<int, int>::iterator> itpair;
		itpair = mp.equal_range(6);

		std::cout << "equal_range(6) first->first = " << itpair.first->first  << " second->first = " << itpair.second->first << std::endl;
	}
	title("Insert and Delete", CYAN_, 1);
	{
		PRE::map<int, std::string> alpha;



		std::cout << "alpha.insert(1,\"lol\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(1, "lol"));

		std::cout << "alpha.insert(2,\"la\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(2, "la"));

		std::cout << "alpha.insert(3,\"truc\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(3, "truc"));

		std::cout << "alpha.insert(4,\"thing\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(4, "thing"));

		std::cout << "alpha.insert(4,\"thing\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(4, "thing"));

		std::cout << "alpha.erase(2)" << std::endl;
		alpha.erase(2);

		PRE::map<int, std::string> beta;
		beta[-1] = "beta-1";
		beta[-42] = "beta-42";
		beta[-3] = "beta-3";
		beta[-666] = "beta-666";

		std::cout << "alpha.insert(beta.begin(), beta.end())" << std::endl;
		alpha.insert(beta.begin(), beta.end());

		PRE::map<int, std::string>::iterator it = alpha.begin();
		for(;it!= alpha.end(); it++)
			std::cout << "first = " << it->first << " second = " << it->second << std::endl;
		std::cout << "alpha.empty() = " << alpha.empty() << std::endl;
		alpha.clear();
		std::cout << "alpha.clear()" << std::endl << "alpha.empty() = " << alpha.empty() << std::endl;
		for(it = alpha.begin();it!= alpha.end(); it++)
			std::cout << "first = " << it->first << " second = " << it->second << std::endl;

	}
}