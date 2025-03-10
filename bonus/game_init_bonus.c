/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:07:48 by orhaddao          #+#    #+#             */
/*   Updated: 2024/11/18 11:55:21 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init_null(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->door_tex = NULL;
	data->ceiling_tex = NULL;
	data->floor = NULL;
	data->ceiling = NULL;
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->floor_parse = NULL;
	data->ceiling_parse = NULL;
	data->map = NULL;
	data->map_checker = NULL;
	data->new_map = NULL;
	data->door = NULL;
	data->img_2d.img = NULL;
	data->img_3d.img = NULL;
}

void	game_texture_init(t_texture *text, int count)
{
	int	idx;

	idx = count - 1;
	while (idx >= 0)
	{
		text[idx].img = NULL;
		text[idx].data = NULL;
		text[idx].width = 0;
		text[idx].height = 0;
		text[idx].size_line = 0;
		text[idx].endian = 0;
		if (idx == count - 1)
			text[idx].bpp = -13;
		else
			text[idx].bpp = 0;
		idx--;
	}
}

void	game_init(t_data *data)
{
	data->img_3d.width = WINDOW_WIDTH;
	data->img_3d.height = WINDOW_HEIGHT;
	data->pr_info.project_y = WINDOW_HEIGHT / 2;
	data->p.r = 2;
	data->key.key_a = 0;
	data->key.key_s = 0;
	data->key.key_d = 0;
	data->key.key_w = 0;
	data->key.key_j = 0;
	data->key.key_sp = 0;
	data->key.key_q = 0;
	data->key.key_left = 0;
	data->key.key_right = 0;
	data->width = 0;
	game_init_null(data);
	game_texture_init(data->textures, 6 + 1);
	game_texture_init(data->first, 43 + 1);
	game_texture_init(data->second, 101 + 1);
	game_texture_init(data->third, 14 + 1);
	game_texture_init(data->fourth, 31 + 1);
	game_texture_init(data->loading_bar, 5 + 1);
}

void	draw_mini_map_helper(t_data *data, int *xy, int start_x, int start_y)
{
	double	distance;
	int		color;

	distance = pow(xy[0] - (MINI_WIDTH / 2), 2) + pow(xy[1] - (MINI_HEIGHT / 2),
			2);
	if (distance <= pow((MINI_HEIGHT / 2), 2))
	{
		if (distance >= pow((MINI_HEIGHT / 2) - 2, 2))
			color = COLOR_WHITE;
		else
			color = get_pixel_color(data, start_x + xy[0], start_y + xy[1]);
		set_pixel_color(&data->img_3d, xy[0], xy[1], color);
	}
}
