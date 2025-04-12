/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:39:54 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/26 18:23:53 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

int	exit_window(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_window(g->mlx, g->win);
	free_map(g->map);
	free(g->mlx);
	close (g->fd);
	exit(0);
}

void	free_enemies(t_enemy *enemies)
{
	t_enemy	*current;
	t_enemy	*next;

	current = enemies;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
