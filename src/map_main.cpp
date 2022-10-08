/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:22:50 by jgourlin          #+#    #+#             */
/*   Updated: 2022/10/08 18:25:19 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../class/Utility/proto.hpp"

void	map_capacity_int_int(PRE::map<int, int> &mp)
{
	std::cout << "   size: " <<mp.size();
	std::cout << std::endl;
	std::cout << "   Max_size: " <<mp.max_size();
  	std::cout << std::endl;		
	std::cout << "   Is empty ? " << mp.empty() << std::endl;
}

void	map_capacity_char_int(PRE::map<char, int> &mp)
{
	std::cout << "   size: " <<mp.size();
	std::cout << std::endl;
	std::cout << "   Max_size: " <<mp.max_size();
  	std::cout << std::endl;		
	std::cout << "   Is empty ? " << mp.empty() << std::endl;
}

void	map_capacity_int_string(PRE::map<int, std::string> &mp)
{
	std::cout << "   size: " <<mp.size();
	std::cout << std::endl;
	std::cout << "   Max_size: " <<mp.max_size();
  	std::cout << std::endl;		
	std::cout << "   Is empty ? " << mp.empty() << std::endl << std::endl;
}

void	map_main()
{
	title("MAP", RED__, 0);

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

		map_capacity_int_int(alpha);
		map_capacity_int_int(beta);
		map_capacity_int_int(charlie);
		map_capacity_int_int(delta);
	}

	title("Element access", CYAN_, 1);
	{
		PRE::map<char, int>	a;

		a['a'] = 2;
		a['b'] = 1;
		a['c'] = 0;
		a['d'] = 4;

		map_capacity_char_int(a);
		
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

		map_capacity_char_int(a);


		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "a[1] = " << a[1] << std::endl;
		std::cout << "a[2] = " << a[2]<< std::endl;
		std::cout << "a[3] = " << a[3] << std::endl;
		std::cout << "a['a'] = " << a['a'] << std::endl;
		std::cout << "a['b'] = " << a['b'] << std::endl;
		std::cout << "a['c'] = " << a['c']<< std::endl;
		std::cout << "a['d'] = " << a['d'] << std::endl;

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


		map_capacity_int_string(alpha);
		std::cout << "alpha.insert(1,\"lol\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(1, "lol"));

		map_capacity_int_string(alpha);
		std::cout << "alpha.insert(2,\"la\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(2, "la"));

		map_capacity_int_string(alpha);
		std::cout << "alpha.insert(3,\"truc\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(3, "truc"));

		map_capacity_int_string(alpha);
		std::cout << "alpha.insert(4,\"thing\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(4, "thing"));

		map_capacity_int_string(alpha);
		std::cout << "alpha.insert(4,\"strange\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(4, "strange"));

		map_capacity_int_string(alpha);
		std::cout << "alpha.erase(2)" << std::endl;
		alpha.erase(2);

		map_capacity_int_string(alpha);
		std::cout << "alpha.erase(2)" << std::endl;
		alpha.erase(2);

		map_capacity_int_string(alpha);
		std::cout << "alpha.insert(666,\"evil\")" << std::endl;
		alpha.insert(PRE::pair<int, std::string>(666, "evil"));

		map_capacity_int_string(alpha);
		std::cout << "alpha.erase(++alpha.begin(), --alpha.end())" << std::endl;
		alpha.erase(++alpha.begin(), --alpha.end());

		map_capacity_int_string(alpha);
		PRE::map<int, std::string> beta;
		beta[-1] = "beta-1";
		beta[-42] = "beta-42";
		beta[-3] = "beta-3";
		beta[-666] = "beta-666";

		std::cout << "alpha.insert(beta.begin(), beta.end())" << std::endl;
		alpha.insert(beta.begin(), beta.end());
		map_capacity_int_string(alpha);
		
		PRE::map<int, std::string>::iterator it = alpha.begin();
		for(;it!= alpha.end(); it++)
			std::cout << "first = " << it->first << " second = " << it->second << std::endl;
		std::cout << "alpha.empty() = " << alpha.empty() << std::endl;
		alpha.clear();
		std::cout << "alpha.clear()" << std::endl << "alpha.empty() = " << alpha.empty() << std::endl;
		for(it = alpha.begin();it!= alpha.end(); it++)
			std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	}
	title("Iterator and swap", CYAN_, 1);
	{
		PRE::map<int,int>	alpha;
		PRE::map<int,int>	beta;

		for (int i = 0;i < 9; i++)
			alpha[i] = -i;
		for (int i = 42;i < 60; i++)
			beta[i] = -i;

		PRE::map<int,int>::const_reverse_iterator crit = alpha.rbegin();
		PRE::map<int,int>::const_reverse_iterator crite = alpha.rend();
		for (;crit != crite; crit++)
			std::cout << "ralpha "<< crit->first << "-" << crit->second << std::endl;

		PRE::map<int,int>::reverse_iterator rit = beta.rbegin();
		PRE::map<int,int>::reverse_iterator rite = beta.rend();
		for (;rit != rite; rit++)
			std::cout << "rbeta " <<rit->first << "-" << rit->second << std::endl;

		map_capacity_int_int(beta);
		map_capacity_int_int(alpha);
		alpha.swap(beta);
		map_capacity_int_int(beta);
		map_capacity_int_int(alpha);
		PRE::map<int,int>::iterator it = beta.begin();
		PRE::map<int,int>::iterator ite = beta.end();
		for (;it != ite; ++it)
			std::cout << "beta "<< it->first << "-" << ite->second << std::endl;
		
		for (PRE::map<int,int>::const_iterator cit = alpha.begin(); cit != alpha.end(); ++cit)
			std::cout << "alpha "<< cit->first << "-" << cit->second << std::endl;
	}
	title("count find", CYAN_, 1);
	{
		PRE::map<int,int>	alpha;
		for (int i = 0;i < 9; i++)
			alpha[i] = -i;
		map_capacity_int_int(alpha);
		for (PRE::map<int,int>::iterator it = alpha.begin(); it != alpha.end(); it++)
			std::cout << "alpha "<< it->first << "-" << it->second << std::endl;
		std::cout << "count(5)= "<< alpha.count(5) << std::endl;
		std::cout << "count(15)= "<< alpha.count(15) << std::endl;

		std::cout << "find(8)= "<< alpha.find(8)->first << std::endl;
		std::cout << "find(15)= ";
		PRE::map<int,int>::iterator res = alpha.find(15);
		if (res == alpha.end())
			std::cout << "end" << std::endl;
		else
			std::cout << "first: " << res->first << "second: " << res->second << std::endl;	
	}
	title("Non-member function", CYAN_, 1);
	{
		PRE::map<int,int>	small;
		PRE::map<int,int>	medium;
		PRE::map<int,int>	medium_bis;

		for (int i = 0;i < 9; i++)
			small[i] = -i;

		for (int i = 0;i < 9; i++)
		{
			medium[i + 42] = -i;
			medium_bis[i + 42] = -i;
		}

		std::cout << "small <  medium = " << (small < medium) << std::endl;
		std::cout << "small <= medium = " << (small <= medium) << std::endl;
		std::cout << "small >  medium = " << (small > medium) << std::endl;
		std::cout << "small >= medium = " << (small >= medium) << std::endl;
		std::cout << "small == medium = " << (small == medium) << std::endl;
		std::cout << "small != medium = " << (small != medium) << std::endl;

		std::cout << "medium_bis <  medium = " << (medium_bis < medium) << std::endl;
		std::cout << "medium_bis <= medium = " << (medium_bis <= medium) << std::endl;
		std::cout << "medium_bis >  medium = " << (medium_bis > medium) << std::endl;
		std::cout << "medium_bis >= medium = " << (medium_bis >= medium) << std::endl;
		std::cout << "medium_bis == medium = " << (medium_bis == medium) << std::endl;
		std::cout << "medium_bis != medium = " << (medium_bis != medium) << std::endl;
	
		std::cout << "swap(small, medium)" << std::endl;
		swap(small, medium);
		std::cout << "small <  medium = " << (small < medium) << std::endl;
		std::cout << "small <= medium = " << (small <= medium) << std::endl;
		std::cout << "small >  medium = " << (small > medium) << std::endl;
		std::cout << "small >= medium = " << (small >= medium) << std::endl;
		std::cout << "small == medium = " << (small == medium) << std::endl;
		std::cout << "small != medium = " << (small != medium) << std::endl;

		std::cout << "medium_bis <  small = " << (medium_bis < small) << std::endl;
		std::cout << "medium_bis <= small = " << (medium_bis <= small) << std::endl;
		std::cout << "medium_bis >  small = " << (medium_bis > small) << std::endl;
		std::cout << "medium_bis >= small = " << (medium_bis >= small) << std::endl;
		std::cout << "medium_bis == small = " << (medium_bis == small) << std::endl;
		std::cout << "medium_bis != small = " << (medium_bis != small) << std::endl;

	}

}