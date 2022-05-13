#include "../includes/lem_in.h"

void ft_resolve(t_mapping *map){
	int i;
	int j;
	int tmp_path_index;
	int tmp_nb_moves;
	j = 0;
	i = 0; 
	
	map->ants = malloc(sizeof(t_ants) * map->nb_ants);

	while (i < map->nb_ants)
	{
		map->ants[i].room_move = 0;
		map->ants[i].end = false;
		i++;
	}
	

	i = 0;
	while(i < map->nb_ants){
		j = 0;
		tmp_path_index = 2147483647;
		tmp_nb_moves = 2147483647;
		while(j != map->room_start.room_nbPipes){
			if (tmp_nb_moves > map->path[j].nb_moves && map->path[j].done == true){
				tmp_nb_moves = map->path[j].nb_moves;
				tmp_path_index = j;
			}
			j++;
		}
		map->ants[i].path_index = tmp_path_index;
		map->ants[i].nb_wait	= map->path[tmp_path_index].path_nb_wait++;
		map->path[tmp_path_index].nb_moves++;
		i++;
	}

	int ants_end = 0;
	int tour = 0;
	i = 0;

	while (ants_end < map->nb_ants)
	{
		i = 0;
		while (i != map->nb_ants)
		{
			if (map->ants[i].nb_wait < tour && map->ants[i].end != true){
				if (map->ants[i].room_move != map->path[map->ants[i].path_index].taille_chemin){
					if (map->ants[i].room_move + 1 == map->path[map->ants[i].path_index].taille_chemin)
						printf("L%d-%s ", i, map->room_end.name);
					else
						printf("L%d-%s ", i,
								map->room[map->path[map->ants[i].path_index].index_road[map->ants[i].room_move]].name);
				}
				map->ants[i].room_move++;
				if (map->ants[i].room_move == map->path[map->ants[i].path_index].taille_chemin){
					ants_end++;
					map->ants[i].end = true;
				}
			}
			i++;
		}
		printf("\n");
		tour++;
	}
}