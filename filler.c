/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:33:52 by aimelda           #+#    #+#             */
/*   Updated: 2020/03/15 23:43:02 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	t_map	*map;
	t_token	*token;

	if (!(map = get_map()) || !(token = get_token()))
		return (0);
	//return (placing_a_piece(get_map, get_token));
}
