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

	int heat_point;
	
	bool hold;
}					t_room;

typedef struct		s_end
{
	int posX;
	int posY;
	
	int room_nbPipes; // a initialliser a 0
	int heat_point;

	char *name;	// a mettre en dinamique
	char *room_pipes[1000];
	
	bool hold;
}					t_end;

typedef struct		s_start
{
	int posX;
	int posY;

	int room_nbPipes; // a initialliser a 0
	int heat_point;

	char *name;	// a mettre en dinamique
	char *room_pipes[1000];
	
	bool hold;
}					t_start;


typedef struct		s_mapping
{
	int ants;
	int nbRoom;
	int nbPipe;

	char *start; // a mettre en dinamique
	char *end;// a mettre en dinamique

	char *roomName[10000];// a mettre en dinamique


	char *map[10000];// a mettre en dinamique
	char *pipes[100000];// a mettre en dinamique

	char *resolve[100];// a mettre en dinamique

	t_room		*room; //room[300];// a mettre en dinamique
	t_end		room_end;
	t_start		room_start;
}					t_mapping;

void 			ft_resolve(t_mapping *map);

#endif