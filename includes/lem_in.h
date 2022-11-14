#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct		s_room
{
	int posX;
	int posY;

	int index;

	int room_nbPipes;

	char *name;	
	char **room_pipes;
	int *room_index;

	int heat_point;

	bool deadlock;
	
	bool hold;
	bool take;
}					t_room;


typedef struct		s_path
{
	bool done;
	int		nb_moves;

	int		taille_chemin;

	char	**road;
	int		*index_road;

	int		path_nb_wait;
}					t_path;

typedef struct		s_end
{
	int posX;
	int posY;
	
	int index;

	int room_nbPipes;
	int heat_point;

	char *name;	
	char **room_pipes;
	int *room_index;
	
	bool hold;
}					t_end;

typedef struct		s_start
{
	int posX;
	int posY;

	int index;
	
	int room_nbPipes;
	int heat_point;

	char *name;	
	char **room_pipes;
	int *room_index;
	
	bool hold;
}					t_start;

typedef struct s_ants
{
	bool 	end;

	int		path_index;

	int		nb_wait;

	char 	*in_room;
	int		room_move;

}					t_ants;


typedef struct		s_mapping
{
	int nb_ants;
	int nbRoom;
	int nbPipe;

	int Ants_finish;

	char *start; 
	char *end;

	char *roomName[100];


	char *map[10000];
	char *pipes[100000];

	t_room		*room;
	t_end		room_end;
	t_start		room_start;
	t_path		*path;
	t_ants		*ants;

}					t_mapping;

void 			ft_resolve(t_mapping *map);
void 			ft_breath(t_mapping *map);

#endif