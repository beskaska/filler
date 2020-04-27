/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:39:07 by aimelda           #+#    #+#             */
/*   Updated: 2020/04/27 12:01:34 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct	s_cell
{
	int				i;
	int				j;
	struct s_cell	*next;
}				t_cell;

typedef struct	s_map
{
	char	**content;
	int		lines;
	int		columns;
	t_cell	*my_points;
	t_cell	*opp_points;
	t_cell	*answer;
}				t_map;

typedef struct	s_token
{
	char	**content;
	int		lines;
	int		columns;
	t_cell	*points;
}				t_token;

t_map			*get_map(void);
t_token			*get_token(void);
int				define_points(t_map *map, t_token *token, int my_number);
void			free_all(t_map *map, t_token *token);
void			free_content(char **content, int lines, int offset);
void			put_piece(t_map *map, t_token *token, int min);

#endif
