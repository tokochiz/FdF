/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:05:22 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/03/27 17:32:40 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/libft.h"
# include "../includes/get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERR_ARGS "Invalid number of arguments\n"
# define ERR_PIPE "pipe "
# define ERR_EXECVE "execve "
# define ERR_MALLOC "malloc "
# define ERR_CMD "Error : Command not found\n"
# define ERR_DIR "Error : No such file of directory\n"
# define ERR_FILE "Error : invalid file\n"

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	int			shift_x;
	int			shift_y;
	int			p;

}				t_point;

typedef struct s_map
{
	int			width;
	int			height;
	int			**height_map;
	int			**color_map;
}				t_map;

typedef struct s_camera
{
	double		angle_x;
	double		angle_y;
	int			depth;
	int			zoom;
}				t_camera;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			color;
	t_point		point;
	t_map		map;
	t_camera	camera;
}				t_data;

// check file
int				check_file_exists(char *filename);
int				check_file_extension(char *filename);
int				check_map_empty(char *filename);
int				check_map_consistent_width(char *filename);
void			check_file(char *filename);

// gnl remove newline
char			*gnl_remove_newline(int fd);

// error
void			put_error_and_exit(const char *msg);
void			put_invalid_file(const char *msg);

// get_width _height
void			free_line(char **line);
char			**split_str_by_spaces(char *str);
int				get_width(char *line);
int				get_height(char *filename);

int				handle_invalid_file(char *filename);
int				hex_str_to_int(char *hex);
void			fill_map(int *depth, int *color, char *line);
void			parse_file(char *filename, t_data *data);

#endif