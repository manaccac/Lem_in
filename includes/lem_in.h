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

	int index; // pour savoir ou il se trouve dans la map

	int room_nbPipes; // a initialliser a 0

	char *name;	// a mettre en dinamique
	char *room_pipes[1000];
	int room_index[1000];

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

	char	*road[1000];
	int		index_road[1000];

	int		path_nb_wait;
}					t_path;

typedef struct		s_end
{
	int posX;
	int posY;
	
	int index; // pour savoir ou il se trouve dans la map

	int room_nbPipes; // a initialliser a 0
	int heat_point;

	char *name;	// a mettre en dinamique
	char *room_pipes[1000];
	int room_index[1000];
	
	bool hold;
}					t_end;

typedef struct		s_start
{
	int posX;
	int posY;

	int index; // pour savoir ou il se trouve dans la map
	
	int room_nbPipes; // a initialliser a 0
	int heat_point;

	char *name;	// a mettre en dinamique
	char *room_pipes[1000];
	int room_index[1000];
	
	bool hold;
}					t_start;

typedef struct s_ants
{
	bool 	end;

	int		path_index;//Chemin choisi

	int		nb_wait;

	char 	*in_room;
	int		room_move; // pour le move savoir ou on en est et on l'augmente de 1 a chaque avancement

}					t_ants;


typedef struct		s_mapping
{
	int nb_ants;
	int nbRoom;
	int nbPipe;

	int Ants_finish;

	char *start; // a mettre en dinamique
	char *end;// a mettre en dinamique

	char *roomName[10000];// a mettre en dinamique


	char *map[10000];// a mettre en dinamique
	char *pipes[100000];// a mettre en dinamique

	// char *resolve[100];// a mettre en dinamique

	t_room		*room; //room[300];// a mettre en dinamique
	t_end		room_end;
	t_start		room_start;
	t_path		*path;// a mettre en dinamique
	t_ants		*ants;

}					t_mapping;

void 			ft_resolve(t_mapping *map);
void 			ft_breath(t_mapping *map);

#endif