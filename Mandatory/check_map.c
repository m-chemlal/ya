/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:54:36 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/23 18:53:57 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_borders(t_game *g, size_t i)
{
	size_t	j;

	j = 0;
	while (g->map[i][j])
	{
		if (g->map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	check_rect(t_game *g)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (i < g->num_line)
	{
		if (i != g->num_line - 1)
		{
			if (ft_strlen(g->map[i]) != ft_strlen(g->map[i + 1]))
				return (0);
		}
		if ((i == 0 || i == g->num_line - 1) && !check_borders(g, i))
			return (0);
		if (g->map[i][0] != '1'
			|| g->map[i][ft_strlen(g->map[i]) - 1] != '1')
			return (0);
		i++;
	}
	len = ft_strlen(g->str);
	if (g->str[len - 1] == '\n')
		return (0);
	return (1);
}

static int	check_wall_elements(t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	g->count_pe = 0;
	g->count_c = 0;
	while (i < g->num_line)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (!ft_strchr("01PEC", g->map[i][j]))
				return (0);
			if (g->map[i][j] == 'P' || g->map[i][j] == 'E')
				g->count_pe++;
			if (g->map[i][j] == 'C')
				g->count_c++;
			j++;
		}
		i++;
	}
	if (g->count_pe != 2 || g->count_c < 1)
		return (0);
	return (1);
}

static int	result_check(t_game *g, char *line)
{
	char	*temp;

	while (1)
	{
		line = get_next_line(g->fd);
		if (!line)
			break ;
		temp = g->str;
		g->str = ft_strjoin(g->str, line);
		free(temp);
		if (!g->str || line[0] == '\n')
			return (free(line), free (g->str), close (g->fd), 0);
		free(line);
		g->num_line++;
	}
	g->map = ft_split(g->str, '\n');
	if (!g->map)
		return (free_map(g->map), free(g->str), close(g->fd), 0);
	if (check_rect(g) == 0 || check_wall_elements(g) == 0)
		return (free_map(g->map), free(g->str), close(g->fd), 0);
	if (check_ff(*g) == 0)
		return (free_map(g->map), free(g->str), close(g->fd), 0);
	return (1);
}

int	check_map(char *pat_str, t_game *g)
{
	char	*line;

	g->fd = open(pat_str, O_RDONLY);
	if (g->fd == -1)
		return (0);
	g->num_line = 0;
	g->str = NULL;
	line = NULL;
	if (result_check(g, line) == 0)
		return (0);
	return (1);
}
