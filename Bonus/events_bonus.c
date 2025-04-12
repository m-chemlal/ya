/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:07:55 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/26 18:23:10 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_player(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->player_x = i;
				g->player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	move_player(t_game *g, int new_x, int new_y)
{
	if (g->map[new_x][new_y] == '0')
	{
		g->map[g->player_x][g->player_y] = '0';
		g->map[new_x][new_y] = 'P';
		g->move++;
	}
	if (g->map[new_x][new_y] == 'C')
	{
		g->move++;
		g->map[g->player_x][g->player_y] = '0';
		g->map[new_x][new_y] = 'P';
		g->count_c--;
	}
	if (g->map[new_x][new_y] == 'E' && g->count_c == 0)
	{
		write (1, "You won!\n", 10);
		exit_window(g);
	}
	if (g->map[new_x][new_y] == 'E' && g->count_c != 0)
		return ;
	if (g->map[new_x][new_y] == '1')
		return ;
	render_map(g);
}

static void	action_player(int key, t_game *g)
{
	find_player(g);
	if (key == W_KEY)
		move_player(g, g->player_x - 1, g->player_y);
	if (key == S_KEY)
		move_player(g, g->player_x + 1, g->player_y);
	if (key == A_KEY)
	{
		g->player_anim = 1;
		move_player(g, g->player_x, g->player_y - 1);
	}
	if (key == D_KEY)
	{
		g->player_anim = 2;
		move_player(g, g->player_x, g->player_y + 1);
	}
}

int	handle_keypress(int key, t_game *g)
{
	if (key == ESC_KEY)
		exit_window(g);
	if (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY)
		action_player(key, g);
	return (0);
}
