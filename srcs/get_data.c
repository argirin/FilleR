/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argirin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:59:05 by argirin           #+#    #+#             */
/*   Updated: 2017/01/06 18:02:38 by argirin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** On recupere les dimensions de la map ainsi que toute la map
*/
char	**get_map(char *line, t_grid *data)
{
	int			i;
	char		**map;
	char		**str_map;

	i = 0;
	str_map = ft_strsplit(line, ' ');
	data->s_map.y = ft_atoi(str_map[1]);
	data->s_map.x = ft_atoi(str_map[2]);
	if (!(map = (char**)malloc(sizeof(char*) * data->s_map.y)))
		return (NULL);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < data->s_map.y)
	{
		get_next_line(0, &line);
		map[i] = ft_strdup(&line[4]);
		i++;
		ft_strdel(&line);
	}
	free_tab2d(str_map);
	return (map);
}

/*
** On recupere les dimensions de la piece ansi que toute la piece
*/
char	**get_piece(char *line, t_grid *data)
{
	int			i;
	char		**piece;
	char		**str_piece;

	i = 0;
	str_piece = ft_strsplit(line, ' ');
	data->s_piece.y = ft_atoi(str_piece[1]);
	data->s_piece.x = ft_atoi(str_piece[2]);
	if (!(piece = (char**)malloc(sizeof(char*) * data->s_piece.y)))
		return (NULL);
	while (i < data->s_piece.y)
	{
		get_next_line(0, &line);
		piece[i] = ft_strdup(line);
		i++;
		ft_strdel(&line);
	}
	free_tab2d(str_piece);
	return (piece);
}

/*
** On compte le nombre d'asterix dans la piece et on recupere
** l'origine de la forme dans la piece
*/

/*
int		get_forme(t_grid *data)
{

	data->count = -1;
	data->ppos.y = -1;
	while (++data->ppos.y < data->s_piece.y)
	{
		data->ppos.x = -1;
		while (++data->ppos.x < data->s_piece.x)
		{
			if (data->piece[data->ppos.y][data->ppos.x] == '*')
			{
				if (++data->count == 1)
				{
					data->origin.x = data->ppos.x;
					data->origin.y = data->ppos.y;
				}
				data->origin.x = (data->origin.x < data->ppos.x) ?
				data->origin.x : data->ppos.x;
			}
		}
	}
	return (data->count);
}
*/

/*
** On stock dans un t_vector* les coordonnees de chaque adterix
*/

/*
void	stock_asterix(t_grid *data)
{
	int 		i;
	t_vector	pos;

	if (!(data->stock_f = (t_vector*)ft_memalloc(sizeof(t_vector) * data->count)))
		return (NULL);
	i = 0;
	pos.y = data->origin.y - 1;
	pos.x = data->origin.x - 1;
	while (i < data->count)
	{
		while (++pos.y < data->s_piece.y)
		{
			while (++pos.x < data->s_piece.x)
			{
				if (data->piece[pos.y][pos.x] == '*')
				{
					stock_f[i.y][i.x] = data->piece[pos.y][pos.x];
					i++;
				}
			}
		}
	}
}*/
