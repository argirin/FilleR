/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 13:22:13 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/06 16:41:35 by argirin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		put_piece(t_grid *data)
{
	ft_putnbr(data->save.y);
	ft_putchar(' ');
	ft_putnbr(data->save.x);
	ft_putchar('\n');
}

int				main(void)
{
	char	*line;
	t_grid	data;

	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "$$$ exec p", 10) == 0)
			data.player = (line[10] == '1') ? 'O' : 'X';
		else if (ft_strncmp(line, "Plateau", 7) == 0)
			data.map = get_map(line, &data);
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			data.piece = get_piece(line, &data);
			solve(&data);
			put_piece(&data);
		}
	}
	return (0);
}
