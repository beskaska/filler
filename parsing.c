/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:52:58 by aimelda           #+#    #+#             */
/*   Updated: 2020/03/14 22:26:23 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	get_player_number(void)
{
	char	*line;
	char	c;

	c = 0;
	if (get_next_line(1, &line) > 0)
	{
		/* Expected line instance: "$$$ exec p1 : [players/abanlin.filler]"*/
		if (ft_strlen(line) > 10)
			if (line[10] == '1')
				c = 'O';
			else
				c = 'X';
	}
	else
		return (c);
	free(line);
	return (c);
}

static int	get_numbers_of_lines_and_columns(int *lines, int *columns)
{
	char	*line;
	int		offset;

	*lines = 0;
	*columns = 0;
	if (get_next_line(1, &line) > 0)
	{
		/* Expected line instance: "Plateau 7 12:"*/
		offset = 8;
		if (ft_strlen(line) > offset)
			*lines = ft_atoi(line + 8);
		while (ft_isdigit(*(line + offset)))
			++offset;
		*columns = ft_atoi(line + offset);
	}
	else
		return (0);
	free(line);
	if (*lines && *columns)
		return (1);
	return (0);
}

char	**get_map()
{
	char	*line;
	char	c;
	int		lines;
	int		columns;

	if (c = get_player_number)
		if (get_numbers_of_lines_and_columns(lines, columns))
			if (get_next_line(1, &line) > 0)
			{
				free(line);
				
			}
}