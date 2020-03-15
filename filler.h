/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:39:07 by aimelda           #+#    #+#             */
/*   Updated: 2020/03/15 23:37:07 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct	s_map
{
	char	**content;
	int		lines;
	int		columns;
	char	my_sign;
	char	opponent;
}				t_map;

typedef struct	s_token
{
	char	**content;
	int		lines;
	int		columns;
}				t_token;

t_map		*get_map(void);
t_token		*get_token(void);
