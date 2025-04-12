/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:31:12 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/28 09:47:34 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "get_next_line_bonus.h"
# include <fcntl.h>
# include <stdio.h>

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

typedef struct data_enemy
{
	size_t				enemy_x;
	size_t				enemy_y;
	int					direction;
	int					horizontal_direction;
	struct data_enemy	*next;
}						t_enemy;

typedef struct data_game
{
	int		fd;
	size_t	num_line;
	char	*str;
	char	**map;
	size_t	count_pe;
	size_t	count_c;
	size_t	count_n;
	void	*mlx;
	void	*win;
	size_t	ww;
	size_t	wh;
	int		iw;
	int		ih;
	void	*textures[9];
	size_t	row;
	size_t	col;
	int		move;
	size_t	player_x;
	size_t	player_y;
	int		player_anim;
	size_t	count_exit;
	t_enemy	*enemies;
}			t_game;

int		check_map(char *pat_str, t_game *g);
char	**ft_split(char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	get_map_dimensions(t_game *g);
int		check_ff(t_game g);
void	load_img(t_game *g);
void	render_map(t_game *g);
int		handle_keypress(int keycode, t_game *g);
void	find_player(t_game *g);
int		exit_window(t_game *g);
void	free_map(char **map);
int		check_enemy(t_game *g);
void	move_enemy(t_game *g);
void	move_direction(t_game *g, t_enemy *current);
void	move_horizontal(t_game *g, t_enemy *current);
int		loop_game(t_game *g);
void	display_move_count(t_game *g);
void	free_enemies(t_enemy *enemies);

#endif
