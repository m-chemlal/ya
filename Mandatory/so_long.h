/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:56:29 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/28 17:14:54 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

typedef struct data_game
{
	int				fd;
	size_t			num_line;
	char			*str;
	char			**map;
	size_t			count_pe;
	size_t			count_c;
	void			*mlx;
	void			*win;
	size_t			ww;
	size_t			wh;
	int				iw;
	int				ih;
	void			*textures[5];
	size_t			row;
	size_t			col;
	unsigned int	move;
	size_t			player_x;
	size_t			player_y;
}					t_game;

int		check_map(char *pat_str, t_game *g);
char	**ft_split(char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	get_map_dimensions(t_game *g);
int		check_ff(t_game g);
void	load_img(t_game *g);
void	render_map(t_game *g);
int		handle_keypress(int keycode, t_game *g);
void	display_move_count(t_game *g);
int		exit_window(t_game *g);
void	free_map(char **map);

#endif
