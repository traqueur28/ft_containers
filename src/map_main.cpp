/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:22:50 by jgourlin          #+#    #+#             */
/*   Updated: 2022/09/30 04:27:12 by jgourlin         ###   ########.fr       */
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
		PRE::map<int, int>::const_iterator it2 = alpha.end();
		while (it1 != it2)
		{
			std::cout << it1->first << " => " << it1->second << '\n';
			it1++;
		}
	}

	{
		PRE::map<int, int>	bravo; //map vide
		PRE::map<int, int>::iterator it1 = bravo.begin();

		std::cout << "begin() empty =" << it1->first << std::endl;
	}
}