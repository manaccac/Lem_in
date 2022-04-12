#include "../includes/lem_in.h"

// void ft_best_room(t_mapping map, char *room, int room_index){
// 	printf("hello\n");

// }

int	ft_strcmp2(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}


void 	ft_breath(t_mapping *map){
	int nb_start_finish;

	nb_start_finish = 0;
	int i;
	int j;

	i = 0;

	map->path = malloc(sizeof(t_path) * map->room_start.room_nbPipes + 1);

	while (map->room_start.room_nbPipes > i)
	{
		printf("index = %d name = %s\n", map->room_start.room_index[i], map->room_start.room_pipes[i]);
		map->path[i].road[0] = map->room_start.room_pipes[i];
		map->path[i].index_road[0] = map->room_start.room_index[i];
		if (ft_strcmp2(map->room[map->path[i].index_road[0]].name, map->room_end.name) != 0)
			map->path[i].done = false;
		else
			map->path[i].done = true;
		i++;
	}
	
	// X variable en fonction du nbpipes de start ensuite il faut parcourire la map
	i = 0;
	int y;
	int min_heat;
	int index_min_heat;
	int nb_done = 0;
	while (nb_done < map->room_start.room_nbPipes)
	{
		j = 0;
		while (map->room_start.room_nbPipes > j){
			y = 0;
			min_heat = 2147483647;
			index_min_heat = 2147483647;
			// printf("name	=	%s\n", map->room[map->path[j].index_road[i]].name);
			while (map->path[j].done != true && map->room[map->path[j].index_road[i]].room_nbPipes > y) // tant qu'il y a des pipe je cherhce le moins chaud
			{
				if (ft_strcmp2(map->room[map->path[j].index_road[i]].room_pipes[y], map->room_start.name) == 0)
					;// printf("H_start	=	%d\n", map->room_start.heat_point);
				else if (ft_strcmp2(map->room[map->path[j].index_road[i]].room_pipes[y], map->room_end.name) == 0){
					map->path[j].done = true;
					map->path[j].index_road[i + 1] = index_min_heat;
					map->path[j].nb_moves++;
					nb_done++;
					min_heat = 0;
					index_min_heat = 0;
				}
				else{
					// printf("H_room	=	%d\n", map->room[map->room[map->path[j].index_road[i]].room_index[y]].heat_point);
					if (map->room[map->room[map->path[j].index_road[i]].room_index[y]].hold != true &&
						min_heat > map->room[map->room[map->path[j].index_road[i]].room_index[y]].heat_point)
					{
						min_heat = map->room[map->room[map->path[j].index_road[i]].room_index[y]].heat_point;
						index_min_heat = map->room[map->room[map->path[j].index_road[i]].room_index[y]].index;
					}
				}
				y++;
			}
			if (min_heat == 2147483647 && map->path[j].done != true){
				// si il na pas trouver un chemin c a dire qu'il a surment etait bloquer par des hold alors on avancer
				// peut etre opti en metant donne a se qui sont bloquer
				dprintf(1, "hello\n");
				nb_done++;
			}
			if (map->path[j].done != true) {
				if (index_min_heat != 2147483647){
					map->path[j].index_road[i + 1] = index_min_heat;
					map->room[index_min_heat].hold = true;
					map->path[j].nb_moves++;
				}
			}
			// map->path[j];
			// faire un appel a fonction qui callregarde les room possible et qui choisi celle qui a le heat point le moins elever et qui n'est pas occuper
			// printf("name  =	%s\n", map->path[j].road[0]);
			// printf("index =	%d\n", map->path[j].index_road[0]);
			j++;
		}
		i++;
		// on part de chaqu'un des start
		//qu'on avance en meme temps

	}

	// affichage 
	i = 0;
	while (map->room_start.room_nbPipes > i)
	{
		printf("done = %d taille chemin = %d\n", map->path[i].done, map->path[i].nb_moves);
		i++;
	}
	
}