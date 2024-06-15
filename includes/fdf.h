/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:05:22 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/06/15 15:44:52 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/libft.h"
# include "../includes/get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERR_ARGS "Invalid number of arguments\n"
# define ERR_PIPE "Error pipe "
# define ERR_EXECVE "Error execve "
# define ERR_MALLOC "Error malloc "
# define ERR_OPEN "Error open "
# define ERR_CMD " command not found\n"
# define ERR_DIR " No such file of directory\n"
# define ERR_FILE "Error invalid file \n"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define DEFAULT_COLOR 0x7cfc00
# define TEXT_COLOR 0xeaeaea
# define HORIZONTAL 0
# define VERTICAL 1
# define ESC_KEY 53
# define DESTROY_NOTIFY 17
# define ANGLE_30 0.523599

typedef struct s_point
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;
	double	z;
	int		color;
	int		center_x;
	int		center_y;
	int		p;
}			t_point;

typedef struct s_map
{
	int		width;
	int		height;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	int		**height_map;
	int		**color_map;
}			t_map;

typedef struct s_view
{
	double	angle_x;
	double	angle_y;
	int		depth;
	double	scale;
	double	offset_x;
	double	offset_y;
}			t_view;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

typedef struct s_data
{
	t_mlx	mlx;
	t_point	point;
	t_map	map;
	t_view	view;
}			t_data;

// check file
int			check_file_exists(char *filename);
int			check_file_extension(char *filename);
int			check_map_empty(char *filename);
int			check_line_width(char *line, int *width, int *first_line_width);
int			check_map_consistent_width(char *filename);
void		check_file(char *filename);

// put_error
void		put_error_and_exit(const char *msg);
void		put_invalid_file(const char *msg);

// get_next_line_utils.c
void		free_2d_memory(int **array, int height);
char		*gnl_remove_trailing_chars(int fd);
void		reset_gnl(char *filename);

// get_width & height
int			get_width_from_line(char *line);
int			get_width(char *filename);
int			get_height(char *filename);

// fill_map
char		**split_str_by_spaces(char *str);
int			handle_invalid_file(char *filename);
int			hex_str_to_int(char *hex);
void		fill_map(int i, char *line, t_data *data);

// parse_file
void		handle_read_error(t_data *data, int row, const char *error_message);
void		allocate_map_memory(t_data *data);
void		allocate_row_memory(t_data *data, int row);
void		read_map_from_file(char *filename, t_data *data);
void		parse_file(char *filename, t_data *data);

// draw
void		calc_isometric(double *x, double *y, int z, t_data *data);
void		ajust_point(t_data *data);
void		calc_line_steps(t_data *data);
void		set_points(t_data *data, int x, int y, int direction);
void		draw(t_data *data);

// key_handler
int			close_window(void *param);
int			press(int key, t_data *data);

// set_scale
double		calc_scale(t_data *data);
void		update_min_max(double iso_x, double iso_y, t_data *data);
void		find_min_max_iso(t_data *data);
void		set_scale(t_data *data);

// put_img
void		display_info(t_data *data);
void		init_image(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif