/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:56:23 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/28 18:04:11 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_map( char *pat_str, t_game *g)
{
	if (ft_strncmp(pat_str + ft_strlen(pat_str) - 4, ".ber", 4) != 0)
	{
		perror("Error\nExtention (.ber). Sorry");
		return (0);
	}
	if (check_map(pat_str, g) == 0)
	{
		perror("Error\nYour map not valid !!!. Sorry");
		return (0);
	}
	else
		return (1);
}

static int	is_graphic_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		return (0);
	get_map_dimensions(g);
	if (g->ww > 2550 || g->wh > 1400)
	{
		perror("Error\nInvalid map dimensions !!!. Sorry");
		return (0);
	}
	g->win = mlx_new_window(g->mlx, g->ww, g->wh, "so_long");
	if (!g->win)
		return (free(g->mlx), 0);
	load_img(g);
	render_map(g);
	g->move = 0;
	mlx_hook(g->win, 2, 0, handle_keypress, g);
	mlx_hook(g->win, 17, 0, exit_window, g);
	mlx_loop(g->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*pat_str;
	t_game	game;

	if (argc != 2)
	{
		perror("Error\nYour path not valid !!!. Sorry");
		return (0);
	}
	pat_str = argv[1];
	if (is_valid_map(pat_str, &game) == 0)
		return (0);
	if (is_graphic_mlx(&game) == 0)
		return (free_map(game.map), close(game.fd), 0);
	return (0);
}
