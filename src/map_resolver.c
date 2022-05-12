#include "../includes/lem_in.h"

void ft_resolve(t_mapping *map){
	// dprintf(1, "DANS FT RESOLVE\n");

	int i;
	int j;
	int tmp_path_index;
	int tmp_nb_moves;
	j = 0;
	i = 0; 

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
		// printf("[best nb_moves	= %d]\n", tmp_nb_moves);
		map->ants[i].path_index = tmp_path_index;
		map->ants[i].nb_wait	= map->path[tmp_path_index].path_nb_wait++;
		map->path[tmp_path_index].nb_moves++;
		//IMPORTANT A LIRE CA 
		// les chemin on augemente leurs mb mouve a chaque fourmis qui prend ce chemin au moins il prend le plus rapide
		// mettre une sorte de waiting time au fourmi en gros si une fourmis a 2 de waiting time elle va attendre le tour 2 avent de prendre sont chemin
		i++;
	}

	// d'abord choisir le chemin que toute les fourmis vont prendre avec un while

	// ensuite avec un while faire les tours avec les print ...
	int ants_end = 0;
	int tour = 0;
	i = 0;

	while (ants_end < map->nb_ants)
	{
		i = 0;
		while (i != map->nb_ants)
		{
			if (map->ants[i].nb_wait < tour && map->ants[i].end != true){
				// printf("name = %s\n", map->room[map->path[map->ants[i].path_index].index_road[map->ants[i].room_move]].name);
				// printf("L%s-%s ", map->path[map->ants[i].path_index].index_road);// dans le while
				if (map->ants[i].room_move != map->path[map->ants[i].path_index].taille_chemin){
					if (map->ants[i].room_move + 1 == map->path[map->ants[i].path_index].taille_chemin)
						printf("L%s-%s ", map->room[map->path[map->ants[i].path_index].index_road[map->ants[i].room_move - 1]].name,
								map->room_end.name);
					else
						printf("L%s-%s ", map->room[map->path[map->ants[i].path_index].index_road[map->ants[i].room_move]].name,
								map->room[map->path[map->ants[i].path_index].index_road[map->ants[i].room_move + 1]].name);
				}
				map->ants[i].room_move++;
				if (map->ants[i].room_move == map->path[map->ants[i].path_index].taille_chemin){
					ants_end++;
					map->ants[i].end = true;
				}
			}
			i++;
		}
		printf("\n"); // a la fin du tour
		tour++;
	}
	


	// printf("L%s-%s ");// dans le while
	// printf("\n"); // a la fin du tour

	i = 0;
	while (i < map->nb_ants)
	{
		// printf("[best path for ants	= %d]\n", map->ants[i].path_index);
		i++;
	}
	

	map->ants = map->ants;
}