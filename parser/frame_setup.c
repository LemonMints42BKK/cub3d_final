/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:38:38 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/25 11:37:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	translate_rgb(char *str, t_color *color)
{
	char	**rgb;
	int		i;

	i = 0;
	(void)color;
	rgb = ft_split(str, ',');
	if (!rgb)
		return ;
	while (rgb[i])
	{
		if (i == 0)
			color->r = ft_atoi(rgb[i]);
		else if (i == 1)
			color->g = ft_atoi(rgb[i]);
		else if (i == 2)
			color->b = ft_atoi(rgb[i]);
		free(rgb[i]);
		i++;
	}
	free(rgb);
}

unsigned int	hexcode(t_frame *secen, char *key)
{
	t_list	*ptr;
	t_color	color;
	char	*str;

	ptr = secen->map->iden->next;
	while (ptr)
	{
		if (ft_strncmp(ptr->key, key, 1) == 0)
			break ;
		ptr = ptr->next;
	}
	str = ptr->content;
	translate_rgb(str, &color);
	return (color3f(color.r, color.g, color.b));
}

int	set_scene(t_frame *scene)
{
	scene->w = WINDOW_WIDTH;
	scene->h = WINDOW_HEIGHT;
	scene->ceiling_color = hexcode(scene, "C");
	scene->floor_color = hexcode(scene, "F");
	if (mapsize(scene->map, scene->p))
		return (4);
	return (EXIT_SUCCESS);
}

int	color3f(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
