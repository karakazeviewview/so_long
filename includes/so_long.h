#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "./ft_printf.h"
# include "./get_next_line.h"

# define MAP_OK 1
# define WRONG_MAP_SHAPE 2
# define INVALID_MAP_FORMATTING 3
# define MALLOC_FAIL 4
# define NO_MAP 5
# define WRONG_CEP 6
# define NO_WALLS 7
# define NO_VALID_PATH 8

# define PORTAL_LEFT 'A'
# define PORTAL_RIGHT 'B'
# define PORTAL_FRONT 'D'

# define PRE 1
# define POST 2

# define WIDTH 48
# define HEIGHT 48

typedef struct s_image{
	void	*coin_front;
	void	*coin_left;
	void	*coin_right;
	void	*coin_side;
	void	*empty;
	void	*wall;
	void	*exit;
	void	*p_front;
	void	*p_left;
	void	*p_right;
	void	*portal_front;
	void	*portal_left;
	void	*portal_right;
	void	*i_left;
	void	*i_right;
	void	*ii;
	void	*iii;
	void	*iv;
	void	*v;
	void	*vi;
	void	*vii;
	void	*viii;
}	t_image;

typedef struct s_game{
	char	**map;
	char	**map_dup;
	bool	game_ended;
	bool	player_moved;
	size_t	num_of_collectibles;
	size_t	num_of_players;
	size_t	num_of_exits;
	size_t	map_width;
	size_t	map_height;
	size_t	player_x;
	size_t	player_y;
	size_t	exit_x;
	size_t	exit_y;
	size_t	total_steps;
	bool	reachable_exit;
	size_t	reachable_collectibles;
	int		map_error;
	void	*win_id;
	void	*mlx_id;
	t_image	*i;
}	t_game;

typedef struct s_parse{
	bool	map_ended;
	size_t	col_offset;
	char	*map_start_ptr;
	char	*map_end_ptr;
}	t_parse;

typedef struct s_line{
	char	*current_ln;
	size_t	pre;
	size_t	mid;
	size_t	post;
}	t_line;

void	check_args(int argc, char **argv);
void	get_map(char *map_file, t_game *g);

void	skip_before_map(char *joined_line, t_parse *p, t_game *g);
void	extract_map(t_parse *p, t_game *g);
void	split_extracted_line(char *extracted, t_game *g);
void	skip_after_map(t_parse *p, t_game *g);
void	info_to_g(char chr, size_t i, t_game *g);

void	check_num_of_cep(t_game *g);
void	check_if_rectangle(t_game *g);
void	check_basic_requirements(t_game *g);
void	check_for_walls(t_game *g);
void	check_if_playable(t_game *g);

void	print_err_and_exit(char *err_message);
void	free_map(char **map);
void	print_map_error(t_game *g);

void	start_game(t_game *g);
int		put_full_map(t_game *g);
void	images_to_window(t_game *g, size_t y, size_t x);
void	more_images_to_window(t_game *g, size_t y, size_t x);
void	put_steps_on_screen(t_game *g);

void	make_images(t_game *g);
void	make_more_images(t_game *g);
void	images_to_window(t_game *g, size_t y, size_t x);
void	more_images_to_window(t_game *g, size_t y, size_t x);

int		animation(t_game *g);

int		process_pressed_key(int keycode, t_game *g);
void	step_to_portal(char player, int y, int x, t_game *g);
char	set_non_player(t_game *g);
void	move_player(int y, int x, t_game *g);
char	get_player(char player, t_game *g);

int		close_game(t_game *g, int exit_status);

#endif