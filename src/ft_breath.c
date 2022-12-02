#include "../includes/lem_in.h"

int	ft_strcmp2(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void ft_reset_path(t_mapping *map){
	int i = 0;
	int j = 0;
	while(i < map->room_start.room_nbPipes){
		j = 1;
		while (j < map->path[i].nb_moves)
		{
			map->path[i].index_road[j] = '\0';
			map->path[i].road[j] = "\0";
			j++;
		}
		map->path[i].done = false;
		map->path[i].taille_chemin = 0;
		map->path[i].nb_moves = 0;
		map->path[i].path_nb_wait = 0;
		i++;
	}
}

void ft_reset_map(t_mapping *map){
	int i = 0;

	while (i < map->nbRoom){
		map->room[i].take = false;
		i++;
	}
}

void 	ft_breath(t_mapping *map){
	// int nb_start_finish;

	// nb_start_finish = 0;
	int i;
	int j;
	i = 0;

	map->path = malloc(sizeof(t_path) * map->room_start.room_nbPipes + 1000);

	while (map->room_start.room_nbPipes > i)
	{
		map->path[i].road = malloc(sizeof(map->path->road) * map->nbPipe);
		map->path[i].index_road = malloc(sizeof(map->path->index_road) * map->nbPipe);
		map->path[i].road[0] = map->room_start.room_pipes[i];
		map->path[i].index_road[0] = map->room_start.room_index[i];
		map->path[i].nb_moves = 0;
		map->path[i].path_nb_wait = 0;
		if (ft_strcmp2(map->room[map->path[i].index_road[0]].name, map->room_end.name) != 0)
			map->path[i].done = false;
		else
			map->path[i].done = true;
		i++;
	}

	i = 0;
	int y;
	int min_heat;
	int index_min_heat;
	int nb_done = 0;
	int nb_while = 0;
	bool breath = false;
	i = 0;
	while (nb_done < map->room_end.room_nbPipes && nb_done < map->room_start.room_nbPipes)
	{
		j = 0;
			while (map->room_start.room_nbPipes > j){
				y = 0;
				min_heat = 2147483647;
				index_min_heat = 2147483647;
				if (map->path[j].index_road[i] == 2147483647)
					;
				else
					while (map->path[j].done != true && map->room[map->path[j].index_road[i]].room_nbPipes > y)
					{
						if (ft_strcmp2(map->room[map->path[j].index_road[i]].room_pipes[y], map->room_start.name) == 0)
							;
						else if (ft_strcmp2(map->room[map->path[j].index_road[i]].room_pipes[y], map->room_end.name) == 0){
							map->path[j].done = true;
							map->room[j].hold = true;
							map->room[j].take = true;
							map->path[j].index_road[i + 1] = index_min_heat;
							map->path[j].nb_moves++;
							nb_done++;
							min_heat = 0;
							index_min_heat = 0;
						}
						else{
							if (map->room[map->room[map->path[j].index_road[i]].room_index[y]].take == true && map->nbRoom < 200)
								;
							else if (map->room[map->room[map->path[j].index_road[i]].room_index[y]].hold == true && map->room[map->path[j].index_road[i]].room_nbPipes != 2)
								;
							else if (min_heat > map->room[map->room[map->path[j].index_road[i]].room_index[y]].heat_point){
								min_heat = map->room[map->room[map->path[j].index_road[i]].room_index[y]].heat_point;
								index_min_heat = map->room[map->room[map->path[j].index_road[i]].room_index[y]].index;
							}
						}
						y++;
					}
				if (min_heat == 2147483647 && map->path[j].done != true && nb_while > map->nbRoom && map->nbRoom < 200 && breath == false){
					nb_while = 0;
					breath = true;
					ft_reset_path(map);
					ft_reset_map(map);
					nb_done = 0;
					i = -1;
					j = 0;
					y = 0;
					break;
				}
				else if (map->path[j].done != true) {
					if (index_min_heat != 2147483647){
						map->path[j].index_road[i + 1] = index_min_heat;
						map->room[index_min_heat].hold = true;
						map->room[index_min_heat].take = true;
						map->path[j].nb_moves++;
					}
				}
				j++;
			}
		if (i > map->nbRoom)
			break;
		nb_while++;
		i++; 
	}

	i = 0;
	while (map->room_start.room_nbPipes > i)
	{
		map->path[i].taille_chemin = map->path[i].nb_moves;
		// printf("done = %d taille chemin = %d\n", map->path[i].done, map->path[i].nb_moves);
		i++;
	}
}