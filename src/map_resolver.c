#include "../includes/lem_in.h"

void ft_resolve(t_mapping *map){
	// dprintf(1, "DANS FT RESOLVE\n");

	int i;
	int j;
	int tmp_path_index;
	j = 0;
	i = 0; 
	while(i < map->nb_ants){
		j = 0;
		tmp_path_index = 2147483647;
		while(j != map->room_start.room_nbPipes){
			if (tmp_path_index > map->path[j].nb_moves)
				tmp_path_index = map->path[j].nb_moves; // a changer par un tmp nb moves...
			j++;
		}
		map->ants[i].path_index;
		//IMPORTANT A LIRE CA 
		// les chemin on augemente leurs mb mouve a chaque fourmis qui prend ce chemin au moins il prend le plus rapide
		// mettre une sorte de waiting time au fourmi en gros si une fourmis a 2 de waiting time elle va attendre le tour 2 avent de prendre sont chemin
		i++;
	}

	// d'abord choisir le chemin que toute les fourmis vont prendre avec un while

	// ensuite avec un while faire les tours avec les print ...


	// printf("L%s-%s ");// dans le while
	// printf("\n"); // a la fin du tour

	map->ants = map->ants;
}