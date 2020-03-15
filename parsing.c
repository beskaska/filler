/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:52:58 by aimelda           #+#    #+#             */
/*   Updated: 2020/03/15 23:42:52 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	get_player(t_map *map)
{
	char	*line;

	map->my_sign = 0;
	if (get_next_line(1, &line) > 0)
	{
		/* Expected line instance: "$$$ exec p1 : [players/abanlin.filler]"*/
		if (ft_strlen(line) > 10)
		{
			if (line[10] == '1')
			{
				map->my_sign = 'O';
				map->opponent = 'X';
			}
			else
			{
				map->my_sign = 'X';
				map->opponent = 'O';
			}
		}
	}
	else
		return (0);
	free(line);
	return (map->my_sign);
}

static int	get_dimensions(int *lines, int *columns, int offset)
{
	char	*line;

	*lines = 0;
	*columns = 0;
	if (get_next_line(1, &line) > 0)
	{
		/* Expected line instance: "Plateau 7 12:"*/
		if (ft_strlen(line) > offset)
		{
			*lines = ft_atoi(line + offset);
			while (ft_isdigit(*(line + offset)))
				++offset;
			*columns = ft_atoi(line + offset);
		}
	}
	else
		return (0);
	free(line);
	if (*lines && *columns)
		return (1);
	return (0);
}

static char	**get_content(int lines, int columns, int offset)
{
	char	**res;
	char	*line;
	int		i;

	if (res = (char**)malloc(sizeof(char*) * lines))
	{
		i = 0;
		while (i < lines)
		{
			if (get_next_line(1, &line) > 0)
			{
				if (ft_strlen(line) == columns + offset)
				{
					res[i++] = line + offset;
					continue;
				}
				else
					free(line);
			}
			free(res);
			return (NULL);
		}
	}
	return (res);
}

t_map		*get_map(void)
{
	t_map	*map;
	char	*line;

	if (map = (t_map*)malloc(sizeof(t_map)))
	{
		if (!get_player(map) || !get_dimensions(&map->lines, &map->columns, 8)
		|| get_next_line(1, &line) <= 0)
		{
			free(map);
			return (NULL);
		}
		if (!(map->content = get_content(map->lines, map->columns, 4)))
			return (NULL);
	}
	return (map);
}

t_token		*get_token(void)
{
	t_token	*token;

	if (token = (t_token*)malloc(sizeof(t_token)))
	{
		if (!get_dimensions(&token->lines, &token->columns, 6))
		{
			free(token);
			return (NULL);
		}
		if (!(token->content = get_content(token->lines, token->columns, 0)))
			return (NULL);
	}
	return (token);
}
