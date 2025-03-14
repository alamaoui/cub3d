/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_parsing_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:55:52 by alamaoui          #+#    #+#             */
/*   Updated: 2024/11/14 15:17:45 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rgb_check(char **array, t_data *data)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	if (i != 3)
		error(data);
}

void	mini_check(char *color_str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (color_str[i])
	{
		if (ft_is_num(color_str[i]) && color_str[i + 1] == ' ')
		{
			j = i + 1;
			while (color_str[j])
			{
				if (color_str[j] == ',')
					break ;
				else if (ft_is_num(color_str[j]))
					error(data);
				j++;
			}
			i = j;
		}
		i++;
	}
}

void	validate_color_format(char *color_str, t_data *data)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	if (!color_str)
		error(data);
	while (color_str[i])
	{
		if (!ft_is_num(color_str[i]) && color_str[i] != ','
			&& color_str[i] != ' ' && color_str[i] != '\n')
			error(data);
		if (color_str[i] == ',')
			commas++;
		i++;
	}
	if (commas != 2)
		error(data);
	mini_check(color_str, data);
}

char	*validate_color(char *str, t_data *data)
{
	char	*path;
	char	*tmp;

	tmp = str;
	if (!str)
		error(data);
	if (ft_strncmp(str, "F ", 2) && ft_strncmp(str, "C ", 2))
		error(data);
	if (str[1] != ' ')
		error(data);
	str += 2;
	if (!(*str))
		error(data);
	path = ft_strdup(&(tmp[2]));
	free(tmp);
	return (path);
}

void	get_color(t_data *game)
{
	int	r;
	int	g;
	int	b;

	game->floor = validate_color(game->floor, game);
	validate_color_format(game->floor, game);
	game->floor_parse = ft_split(game->floor, ',');
	rgb_check(game->floor_parse, game);
	r = ft_atoi(game->floor_parse[0], game);
	g = ft_atoi(game->floor_parse[1], game);
	b = ft_atoi(game->floor_parse[2], game);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error(game);
	game->floor_color = (r << 16 | g << 8 | b);
	game->ceiling = validate_color(game->ceiling, game);
	validate_color_format(game->ceiling, game);
	game->ceiling_parse = ft_split(game->ceiling, ',');
	rgb_check(game->ceiling_parse, game);
	r = ft_atoi(game->ceiling_parse[0], game);
	g = ft_atoi(game->ceiling_parse[1], game);
	b = ft_atoi(game->ceiling_parse[2], game);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error(game);
	game->ceiling_color = (r << 16 | g << 8 | b);
}
