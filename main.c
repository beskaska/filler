/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 21:51:00 by aimelda           #+#    #+#             */
/*   Updated: 2020/04/27 11:53:35 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	print(t_cell *answer)
{
	ft_putnbr(answer->i);
	ft_putchar(' ');
	ft_putnbr(answer->j);
	ft_putchar('\n');
}

static int	get_player(void)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "$$$ exec p", 10))
		{
			if (line[10] == '1')
			{
				free(line);
				return (1);
			}
			else if (line[10] == '2')
			{
				free(line);
				return (2);
			}
		}
		free(line);
	}
	return (0);
}

int			main(void)
{
	t_map	*map;
	t_token	*token;
	int		my_number;

	if (!(my_number = get_player()))
		return (1);
	while (1)
	{
		if (!(map = get_map()))
			return (1);
		if (!(token = get_token()))
		{
			free_all(map, token);
			return (1);
		}
		if (!define_points(map, token, my_number))
			return (1);
		put_piece(map, token, 10000000);
		print(map->answer);
		free_all(map, token);
	}
}
