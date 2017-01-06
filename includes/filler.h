/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 10:53:50 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/05 18:22:27 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

typedef	struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef	struct	s_grid
{
    char        player;
    char        **map;
    char        **piece;
	t_vector	mpos;
	t_vector	ppos;
	t_vector	s_map;
	t_vector	s_piece;
    t_vector    save;
}				t_grid;

int				main(void);
void			free_tab2d(char **tab);
char			**get_map(char *line, t_grid *data);
char			**get_piece(char *line, t_grid *data);
void			solve(t_grid *data);
int             browse_piece(t_grid *data, t_vector *place, int count);

#endif
