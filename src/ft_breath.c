#include "../includes/lem_in.h"

int	ft_strcmp2(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}


int ft_best_room(t_mapping *map, int room_index, int nb_to_move, int path_index){
	printf("donnée ==== \n");

	printf("room_index = %d\n", room_index);
	printf("test room_index name = %s\n", map->room[map->path[path_index].index_road[room_index]].name);
	printf("nb_to_move = %d\n", nb_to_move);
	printf("path_index = %d\n", path_index);
	printf("fin de donnée\n");
	int i;
	int j;

	i = 0;

	// while(i != map->nbRoom){
	// 	printf("name room dans hold or not %s = %d\n", map->room[i].name, map->room[i].hold);
	// 	i++;
	// }

	i = 0;
	int min_heat;
	int index_min_heat;
	printf("%d\n",nb_to_move);
	while (i < nb_to_move){
		printf("nbpipe = %d\n", map->room[room_index].room_nbPipes);
		j = 0;
		min_heat = 2147483647;
		index_min_heat = 2147483647;
		while(map->path[path_index].done != true && map->room[map->path[path_index].index_road[room_index]].room_nbPipes > j){ //map->path[j].done != true && mais on a pas le bon j
		// (map->path[j].done != true && map->room[map->path[j].index_road[i]].room_nbPipes > y)
				if (ft_strcmp2(map->room[map->path[path_index].index_road[room_index]].room_pipes[j], map->room_start.name) == 0)
					;// printf("H_start	=	%d\n", map->room_start.heat_point);
				else if (ft_strcmp2(map->room[map->path[path_index].index_road[room_index]].room_pipes[j], map->room_end.name) == 0){
					printf(" test = %s \n", map->room[map->path[path_index].index_road[room_index]].name);
					printf("here donne ?\n");
					map->path[path_index].done = true;
					map->room[path_index].hold = true;
					map->path[path_index].index_road[room_index + 1] = index_min_heat;
					map->path[path_index].nb_moves++;
					min_heat = 0;
					index_min_heat = 0;
				}

			// if (ft_strcmp2(map->room[room_index].room_pipes[j], map->room_start.name) == 0)
			// 	;
			// else if (ft_strcmp2(map->room[room_index].room_pipes[j], map->room_end.name) == 0){
			// 	// map->path[j].done = true;
			// 	// map->room[j].hold = true;
			// 	// map->path[j].index_road[i + 1] = index_min_heat;
			// 	// map->path[j].nb_moves++;
			// 	// nb_done++;
			// 	// min_heat = 0;
			// 	// index_min_heat = 0;
			// }


		//j = path_index
		//i = room_index
		//y = j

			else{
				// printf("H_room	=	%d\n", map->room[map->room[map->path[j].index_road[i]].room_index[y]].heat_point);
				if (map->room[map->room[map->path[path_index].index_road[room_index]].room_index[j]].hold != true &&
					min_heat > map->room[map->room[map->path[path_index].index_road[room_index]].room_index[j]].heat_point)//verifie si le heat et pas plus grand que celui ou on est
				{
					printf("ROOM FIND confirmed!!!\n");
					printf("test room_index name = %d\n", map->room[map->room[map->path[path_index].index_road[room_index]].room_index[j]].hold);
					min_heat = map->room[map->room[map->path[path_index].index_road[room_index]].room_index[j]].heat_point;
					index_min_heat = map->room[map->room[map->path[path_index].index_road[room_index]].room_index[j]].index;
				}
			}
			j++;


			// else{
			// 	printf("ROOM FIND?\n");
			// 	if (map->room[map->room[room_index].room_index[j]].hold != true && min_heat > map->room[map->room[room_index].room_index[j]].heat_point)//verifie si le heat et pas plus grand que celui ou on est
			// 	{
			// 		printf("ROOM FIND confirmed!!!\n");
			// 		min_heat = map->room[map->room[room_index].room_index[j]].heat_point;
			// 		index_min_heat = map->room[map->room[room_index].room_index[j]].index;
			// 	}
			// }
			// j++;
		}
		if (map->path[path_index].done != true) {
			if (index_min_heat != 2147483647){
				map->path[path_index].index_road[room_index + 1] = index_min_heat;
				map->room[index_min_heat].hold = true;
				map->path[path_index].nb_moves++;
				break;
			}
		}
		// peut etre quil faut faire room_index = le nouvelle index
		room_index++;
		i++;
	}
	printf("done = %d\n",map->path[path_index].done);
	printf("END DE LA RECHERCHE\n");
	if (map->path[path_index].done == true)
		return (1);
	return (0);

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
		// map->room[map->room_start.room_index[i]].hold = true;
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
	int backtrack;
	int min_heat;
	int index_min_heat;
	int nb_done = 0;
	int find_pipe;
	bool find = false;
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
					map->room[j].hold = true;
					map->path[j].index_road[i + 1] = index_min_heat;
					map->path[j].nb_moves++;
					nb_done++;
					min_heat = 0;
					index_min_heat = 0;
				}
				else{
					// printf("H_room	=	%d\n", map->room[map->room[map->path[j].index_road[i]].room_index[y]].heat_point);
					if (map->room[map->room[map->path[j].index_road[i]].room_index[y]].hold != true &&
						min_heat > map->room[map->room[map->path[j].index_road[i]].room_index[y]].heat_point)//verifie si le heat et pas plus grand que celui ou on est
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

				// on va essayer de faire du backtracking
				backtrack = i;
				find = false;
				while(backtrack >= 0 && find != true){
					// printf("nb pipes = %d\n", map->room[map->path[j].index_road[backtrack]].room_nbPipes);
					if (map->room[map->path[j].index_road[backtrack]].room_nbPipes > 2){
						find_pipe = 0;
						while (find_pipe < map->room[map->path[j].index_road[backtrack]].room_nbPipes && find != true){
							if (map->room[map->room[map->path[j].index_road[backtrack]].room_index[find_pipe]].hold != true)//verifie si le heat et pas plus grand que celui ou on est
							{
								if (map->room[map->room[map->path[j].index_road[backtrack]].room_index[find_pipe]].heat_point <= map->room[map->path[j].index_road[backtrack]].heat_point){
									printf("heat = %d\n", map->room[map->room[map->path[j].index_road[backtrack]].room_index[find_pipe]].index);
									// while (backtrack < i)
									// {
										if (ft_best_room(map, backtrack, i - backtrack, j) == 1)
											nb_done++;
										// la fonction doit avoir la map l'index de la room et le nombre de room qu'elle doit pour resincroniser tout
									// 	backtrack++;
									// }
									find = true;
									// il faudrait remonter le backtrack jusqu'au i et laisser faire comment avent
								}
								// min_heat = map->room[map->room[map->path[j].index_road[backtrack]].room_index[find_pipe]].heat_point;
								// index_min_heat = map->room[map->room[map->path[j].index_road[backtrack]].room_index[find_pipe]].index;
							}
							find_pipe++;
						}
					}
					backtrack--;
				}

				//
				dprintf(1, "hello 1 nbd0ne = %d\n", backtrack);
				if (backtrack == -1){
					nb_done++;
				}
				// nb_done++;
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