/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:01:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/09 16:57:19 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hex_str_to_int(char *hex)
{
	int	len;
	int	base;
	int	decimal;

	len = ft_strlen(hex) - 1;
	base = 1;
	decimal = 0;
	while (len >= 0)
	{
		if (hex[len] >= '0' && hex[len] <= '9')
			decimal += (hex[len] - '0') * base;
		if (hex[len] >= 'A' && hex[len] <= 'F')
			decimal += (hex[len] - 'A' + 10) * base;
		if (hex[len] >= 'a' && hex[len] <= 'f')
			decimal += (hex[len] - 'a' + 10) * base;
		base *= 16;
		len--;
	}
	return (decimal);
}

void	free_split_parts(char **split_parts)
{
	int	i;

	i = 0;
	while (split_parts[i])
	{
		free(split_parts[i]);
		i++;
	}
	free(split_parts);
}

char	**split_str_by_spaces(char *str)
{
	char	**split_parts;

	split_parts = ft_split(str, ' ');
	if (split_parts == NULL)
		put_error_and_exit(ERR_MALLOC);
	return (split_parts);
}

void	fill_map(int height, char *line, t_data *data)
{
	char	**split_parts;
	char	*comma_p;
	char	*depth_str;
	int		j;

	split_parts = split_str_by_spaces(line);
	j = 0;
	while (split_parts[j] != '\0')
	{
		comma_p = ft_strchr(split_parts[j], ',');
		if (comma_p != NULL)
		{
			depth_str = ft_substr(split_parts[j], 0, comma_p - split_parts[j]);
			data->map.height_map[height][j] = ft_atoi(depth_str);
			free(depth_str);
			data->map.color_map[height][j] = hex_str_to_int(comma_p + 1);
		}
		else
		{
			data->map.height_map[height][j] = ft_atoi(split_parts[j]);
			data->map.color_map[height][j] = DEFAULT_COLOR;
		}
		j++;
	}
	free_split_parts(split_parts);
}
