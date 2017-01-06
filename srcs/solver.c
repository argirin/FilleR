/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:19:10 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/06 17:55:18 by argirin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		place_piece(t_grid *data, int y_ret, int x_ret)
{
	int			super;
	int			count;
	t_vector	place;
	
	super = 0;
	count = 0;
	//if (!(y_ret < 0 || x_ret < 0 || y_ret < data->s_map.y || x_ret > data->s_map.x))
	//	return (0);
	while (browse_piece(data, &place, ++count))
	{
		if ( y_ret + place.y >= 0 && x_ret + place.x >= 0 &&
		   y_ret + place.y < data->s_map.y &&
		   x_ret + place.x < data->s_map.x)
		{
			if (data->map[y_ret + place.y][x_ret + place.x] != '.')
				super++;
		}
		else
		{
			data->save.y = 0;
			data->save.x = 0;
			return (0);
		}
		if (super > 1)
			return (0);
	}
	data->save.y = y_ret;
	data->save.x = x_ret;
	return (1);
}

int		browse_piece(t_grid *data, t_vector *place, int count)
{
	int			index;

	index = 0;
	data->ppos.y = -1;
	while (++data->ppos.y < data->s_piece.y)
	{
		data->ppos.x = -1;
		while (++data->ppos.x < data->s_piece.x)
		{
			if (data->piece[data->ppos.y][data->ppos.x] == '*')
			{
				index++;
				if (index == count)
				{
					place->y = data->ppos.y;
					place->x = data->ppos.x;
					return (1);
				}
			}
		}
	}
	return (0);
}

int		check_placement(t_grid *data)
{
	int			count;
	t_vector	place;

	count = 0;
	place.y = 0;
	place.x = 0;
	browse_piece(data, &place, ++count);
	while (!(place_piece(data, data->save.y - place.y, data->save.x - place.x)))
		if (!(browse_piece(data, &place, ++count)))
			return (0);
	return (1);
}

void	solve(t_grid *data)
{
	data->mpos.y = -1;
	while (++data->mpos.y < data->s_map.y)
	{
		data->mpos.x = -1;
		while (++data->mpos.x < data->s_map.x)
		{
			if (data->map[data->mpos.y][data->mpos.x] == data->player ||
			   data->map[data->mpos.y][data->mpos.x] == data->player + 32)
			{
				data->save.y = data->mpos.y;
				data->save.x = data->mpos.x;
				if (check_placement(data))
					return ;
			}
		}
	}
	//free_tab2d(data->piece);
	//free_tab2d(data->map);
}
