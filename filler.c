/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 21:50:48 by aimelda           #+#    #+#             */
/*   Updated: 2020/04/27 11:58:13 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check(t_map *map, t_cell *point, int i, int j)
{
	int	flag;

	flag = 0;
	while (point)
	{
		if (map->content[i + point->i][j + point->j] != '.')
		{
			if (flag)
				return (0);
			else
				flag = 1;
		}
		point = point->next;
	}
	return (1);
}

static int	calc(t_map *map, t_cell *dot, int i, int j)
{
	int		sum;
	int		min;
	int		d;
	t_cell	*tmp;

	sum = 0;
	while (dot)
	{
		if (map->content[i + dot->i][j + dot->j] == '.')
		{
			min = 1000000;
			tmp = map->opp_points;
			while (tmp)
			{
				d = ft_abs(tmp->i - i - dot->i) + ft_abs(tmp->j - j - dot->j);
				if (d < min)
					min = d;
				tmp = tmp->next;
			}
			sum += min;
		}
		dot = dot->next;
	}
	return (sum);
}

void		put_piece(t_map *map, t_token *token, int min)
{
	t_cell	*my;
	t_cell	*dot;
	int		tmp;

	my = map->my_points;
	while (my)
	{
		dot = token->points;
		while (dot)
		{
			if (my->i >= dot->i && my->j >= dot->j
			&& map->lines - my->i >= token->lines - dot->i
			&& map->columns - my->j >= token->columns - dot->j
			&& check(map, token->points, my->i - dot->i, my->j - dot->j)
			&& (tmp = calc(map, token->points, my->i - dot->i, my->j - dot->j)))
				if (tmp < min)
				{
					min = tmp;
					map->answer->i = my->i - dot->i;
					map->answer->j = my->j - dot->j;
				}
			dot = dot->next;
		}
		my = my->next;
	}
}
