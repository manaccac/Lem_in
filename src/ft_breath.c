#include "../includes/lem_in.h"

void 	ft_breath(t_mapping *map){
	int nb_start_finish;

	nb_start_finish = 0;
	int i;

	i = 0;

	while (map->room_start.room_nbPipes > i)
	{
		printf("index = %d name = %s\n", map->room_start.room_index[i], map->room_start.room_pipes[i]);
		i++;
	}
	
	// X variable en fonction du nbpipes de start ensuite il faut parcourire la map
	while (nb_start_finish < map->room_start.room_nbPipes)
	{
		// on part de chaqu'un des start
		//qu'on avance en meme temps

		nb_start_finish++;
	}
}