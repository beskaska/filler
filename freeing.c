/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:11:23 by aimelda           #+#    #+#             */
/*   Updated: 2020/04/27 11:58:48 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	free_point(t_cell *point)
{
	t_cell	*tmp;

	while (point)
	{
		tmp = point;
		point = point->next;
		free(tmp);
	}
}

void		free_content(char **content, int lines, int offset)
{
	while (lines--)
		free(content[lines] - offset);
	free(content);
}

void		free_all(t_map *map, t_token *token)
{
	free_content(map->content, map->lines, 4);
	free_point(map->my_points);
	free_point(map->opp_points);
	free_point(map->answer);
	free(map);
	if (token)
	{
		free_content(token->content, token->lines, 0);
		free_point(token->points);
		free(token);
	}
}
