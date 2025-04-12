/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:09:06 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/27 14:55:52 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_direction(t_game *g, t_enemy *current)
{
	if (current->direction == 1)
	{
		if (g->map[current->enemy_x + 1][current->enemy_y] == '0'
			|| g->map[current->enemy_x + 1][current->enemy_y] == 'P')
		{
			g->map[current->enemy_x][current->enemy_y] = '0';
			g->map[current->enemy_x + 1][current->enemy_y] = 'N';
			current->enemy_x++;
		}
		else
			current->direction = 0;
	}
	else
	{
		if (g->map[current->enemy_x - 1][current->enemy_y] == '0'
			|| g->map[current->enemy_x - 1][current->enemy_y] == 'P')
		{
			g->map[current->enemy_x][current->enemy_y] = '0';
			g->map[current->enemy_x - 1][current->enemy_y] = 'N';
			current->enemy_x--;
		}
		else
			current->direction = 1;
	}
}

void	move_horizontal(t_game *g, t_enemy *current)
{
	if (current->horizontal_direction == 1)
	{
		if (g->map[current->enemy_x][current->enemy_y + 1] == '0'
			|| g->map[current->enemy_x][current->enemy_y + 1] == 'P')
		{
			g->map[current->enemy_x][current->enemy_y] = '0';
			g->map[current->enemy_x][current->enemy_y + 1] = 'N';
			current->enemy_y++;
		}
		else
			current->horizontal_direction = 0;
	}
	else if (current->horizontal_direction == 0)
	{
		if (g->map[current->enemy_x][current->enemy_y - 1] == '0'
			|| g->map[current->enemy_x][current->enemy_y - 1] == 'P')
		{
			g->map[current->enemy_x][current->enemy_y] = '0';
			g->map[current->enemy_x][current->enemy_y - 1] = 'N';
			current->enemy_y--;
		}
		else
			current->horizontal_direction = 1;
	}
}
