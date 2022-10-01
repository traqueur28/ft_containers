/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:44:57 by jgourlin          #+#    #+#             */
/*   Updated: 2022/10/01 10:34:39 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft
{
	template<typename T>
	struct node
	{
		T			*_v;
		node		*_l;
		node		*_r;
		node		*_p;
		int			_color; // 0 = black
	};
}

#endif