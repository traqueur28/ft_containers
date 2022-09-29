/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:22:50 by jgourlin          #+#    #+#             */
/*   Updated: 2022/09/29 11:12:40 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../class/Utility/proto.hpp"

void	map_main()
{
	title("MAP", RED__, 0);
	{
		std::map<int, int>	alpha;

		alpha.insert(std::pair<int, int>(1, -1));
		for (int i = 9; i >= 0; i--)
				alpha.insert(std::pair<int, int>(i, -i));

		std::map<int, int>::iterator it1 = alpha.begin();
		std::map<int, int>::iterator it2 = alpha.end();
		while (it1 != it2)
		{
			std::cout << it1->first << " => " << it1->second << '\n';
			it1++;
		}
	}

	{
		std::map<int, int>	bravo;
		std::map<int, int>::iterator it1 = bravo.begin();

		std::cout << "begin() empty =" << it1->first << std::endl;
	}
}