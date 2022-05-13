#include "../includes/lem_in.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void ft_heat_map(t_mapping *map){

	int i;
	int j;

	int nb_done;
	char **done_name; // a voir comment faire pour ne pas a avoir a mettre comme ca
	int *done_index;

	i = 0;
	nb_done = 0;
	int tmp;
	tmp = 0;
	done_name = malloc(1000000000);// a changer
	
	done_index = malloc(sizeof(int *) + map->nbRoom * 4);

	while(i != map->room_end.room_nbPipes){
		// printf("pipe de la room end %s = %s\n", map->room_end.name, map->room_end.room_pipes[i]);
		if (ft_strcmp(map->room_end.room_pipes[i], map->room_start.name) == 0){
			map->room_start.heat_point++;
			done_name[nb_done] = map->room[j].name;
			done_index[nb_done] = j;
			nb_done++;
		}
		else {
			j = 0;
			while (j < map->nbRoom){
				if (ft_strcmp(map->room_end.room_pipes[i],map->room[j].name) == 0){
					map->room[j].heat_point++;
					done_name[nb_done] = map->room[j].name;
					done_index[nb_done] = map->room[j].index;
					nb_done++;
					break ;
				}
				j++;
			}
		}

		
		i++;
	}
	i = 0;

	//test
	int y;
	int start_find = 0;
	while(nb_done + start_find < map->nbRoom + 1 && done_name[i]){
		// faire un truc en mode du debut de index done a la fin et quand on done on en met un a la fin
		if (ft_strcmp(done_name[i], map->room_start.name) == 0 || ft_strcmp(done_name[i], map->room_end.name) == 0){
			;
		}
		else {
			j = 0;
			// printf("i %d\n", i);
			while (j < map->room[done_index[i]].room_nbPipes)
			{
				// printf("i %d\n", );
				// printf("name = %s nbpipe = %d\n", map->room[done_index[i]].name ,map->room[done_index[i]].room_nbPipes);
				// dprintf(1, "%d ===== %s\n", map->room[done_index[i]].room_nbPipes, map->room[done_index[i]].name);
				// dprintf(1, "index	%d\n", done_index[i]);
				// dprintf(1, "index	%s\n", map->room[0].name);
				y = 0;
				while (y < map->nbRoom){
					if (ft_strcmp(map->room[done_index[i]].room_pipes[j], map->room_start.name) == 0){
						if (map->room_start.heat_point != 0 && map->room_start.heat_point > map->room[done_index[i]].heat_point + 1)
							map->room_start.heat_point = map->room[done_index[i]].heat_point + 1;
						else if (map->room_start.heat_point == 0) {
							map->room_start.heat_point = map->room[done_index[i]].heat_point + 1;
							start_find++;
						}
					}
					if (ft_strcmp(map->room[done_index[i]].room_pipes[j], map->room[y].name) == 0){
						if (map->room[y].heat_point != 0 && map->room[y].heat_point > map->room[done_index[i]].heat_point + 1)
							map->room[y].heat_point = map->room[done_index[i]].heat_point + 1;
						if (map->room[y].heat_point == 0) { // a mettre un if le nouveau heat point et plus bas alors on remplace juste le heat point
							if (map->room[y].room_nbPipes == 1)
								map->room[y].deadlock = true;
							if (map->room[done_index[i]].heat_point + 1 + map->nb_ants > map->room_start.heat_point) // si la room et trop eloignee
							map->room[y].heat_point = map->room[done_index[i]].heat_point + 1;
							done_name[nb_done] = map->room[y].name;
							done_index[nb_done] = map->room[y].index;
							nb_done++;
							break ;
						}
					}
					y++;
				}
				j++;
			}
		}
		i++;
	}

	free(done_name);
	free(done_index);
}

void ft_setPipe(t_mapping *map){
	int i;
	int j;
	int y;

	int test = 0;
	int j_tmp = 0;

	char **tmp;

	y = 0;
	i = 0;
	while(i != map->nbPipe){
		tmp = ft_split(map->pipes[i], '-');

		j = 0;
			while(map->roomName[y] && j != 2){
				if (ft_strcmp(map->room_start.name, tmp[j]) == 0) {
					if (j == 1){
						map->room_start.room_pipes[map->room_start.room_nbPipes] = tmp[0];
						j_tmp = 0;
					}
					else {
						map->room_start.room_pipes[map->room_start.room_nbPipes] = tmp[1];
						j_tmp = 1;
					}
					while (test < map->nbRoom){
						if (ft_strcmp(tmp[j_tmp], map->room_end.name) == 0){
							map->room_start.room_index[map->room_start.room_nbPipes] = map->room_end.index;
							break;
						}
						if (ft_strcmp(tmp[j_tmp], map->room[test].name) == 0){
							map->room_start.room_index[map->room_start.room_nbPipes] = map->room[test].index;
							break;
						}
						test++;
					}
					test = 0;
					j++;
					map->room_start.room_nbPipes++;
					y = -1;
				}
				else if (ft_strcmp(map->room_end.name, tmp[j]) == 0) {
					if (j == 1){
						map->room_end.room_pipes[map->room_end.room_nbPipes] = tmp[0];
						j_tmp = 0;
					}
					else{
						map->room_end.room_pipes[map->room_end.room_nbPipes] = tmp[1];
						j_tmp = 1;
					}
					while (test < map->nbRoom){
						if (ft_strcmp(tmp[j_tmp], map->room_start.name) == 0){
							map->room_end.room_index[map->room_end.room_nbPipes] = map->room_start.index;
							break;
						}
						if (ft_strcmp(tmp[j_tmp], map->room[test].name) == 0){
							map->room_end.room_index[map->room_end.room_nbPipes] = map->room[test].index;
							break;
						}
						test++;
					}
					test = 0;
					j++;
					map->room_end.room_nbPipes++;
					y = -1;
				}
				else if (ft_strcmp(map->room[y].name, tmp[j]) == 0){
					if (j == 1){
						map->room[y].room_pipes[map->room[y].room_nbPipes] = tmp[0];
						j_tmp = 0;
					}
					else{
						map->room[y].room_pipes[map->room[y].room_nbPipes] = tmp[1];
						j_tmp = 1;
					}
					while (test < map->nbRoom){
						if (ft_strcmp(tmp[j_tmp], map->room_start.name) == 0){
							map->room[y].room_index[map->room[y].room_nbPipes] = map->room_start.index;
							break;
						}
						if (ft_strcmp(tmp[j_tmp], map->room_end.name) == 0){
							map->room[y].room_index[map->room[y].room_nbPipes] = map->room_end.index;
							break;
						}
						if (ft_strcmp(tmp[j_tmp], map->room[test].name) == 0){
							map->room[y].room_index[map->room[y].room_nbPipes] = map->room[test].index;
							break;
						}
						test++;
					}
					test = 0;
					j++;
					map->room[y].room_nbPipes++;
					y = -1;
				}
				y++;
			}
		i++;
		free(tmp);
	}
}

int ft_verif_pipes(char *pipes, t_mapping map){
	char **tmp;
	tmp = ft_split(pipes, '-');

	int i;
	int j;
	int y;
	y = 0;
	j = 0;
	i = 0;

	if (ft_strcmp(tmp[0], tmp[1]) == 0)
		return -1;

	while (i != 2 && j != 2){
		while (y != map.nbRoom + 2)
		{
			if (ft_strcmp(tmp[j], map.roomName[y]) == 0)
			{
				j++;
				break;
			}
			y++;
		}
		y = 0;
		i++;
	}
	if (j != 2)
		return -1;
	return 1;
}

void ft_name_room(t_mapping *map){
	char **tmp;
	tmp = ft_split(map->start, ' ');
	map->roomName[0] = tmp[0];
	free(tmp);
	tmp = ft_split(map->end, ' ');
	map->roomName[1] = tmp[0];
	free(tmp);

	int i;
	
	i = 0;
	int j = 2;
	while(i != map->nbRoom){
		tmp = ft_split(map->map[i], ' ');
		map->roomName[j] = tmp[0];
		free(tmp);
		i++;
		j++;
	}
}

char *ft_name(char *room){
	char *tmp;
	int i = 0;
	int j = 0;

	while(room[i] != ' ' && room[i]){
		i++;
	}
	tmp = malloc(i);
	i = 0;

	while(room[i] != ' ' && room[i]){
		tmp[j] = room[i];
		j++;
		i++;
	}
	tmp[j] = '\n';
	return tmp;
}

int ft_verif_room(char *room){
	int i = 0;

	if (room[0] == 'L' || room[0] == '#')
		return -1;
	i++;
	while (room[i] != ' ' && room[i])
		i++;
	if (room[i] == '\n')
		return -4;
	i++;
	if (room[i] >= '0' && room[i] <= '9')
		while (room[i] >= '0' && room[i] <= '9')
			i++;
	else
		return -2;
	
	if (room[i] == ' ')
		i++;
	if (room[i] >= '0' && room[i] <= '9')
		while (room[i] >= '0' && room[i] <= '9')
			i++;
	else
		return -3;
	
	return 1;
}

int main()
{
	char *buf;
	buf = malloc(1000000);
	read(0, buf, 1000000);

	char **map_cut;
	map_cut = ft_split(buf, '\n');

	int i = 0;
	int part = 1;
	int other_room_nb = 0;
	int nb_pipes = 0;


	t_mapping map;
	char **tmp;
	map.room = malloc(sizeof(t_room) * 100000 + 1);

	while (map_cut[i])
	{
		if (part == 1 && (map_cut[i][0] >= '0' && map_cut[i][0] <= '9'))
		{
			map.nb_ants = ft_atoi(map_cut[i]);
			part++;
		}
		else if (part == 2) {
			while((map_cut[i] && map_cut[i][0] == '#'))
			{
				if (ft_strncmp(map_cut[i], "##start", 7) == 0)
					break;
				else if (ft_strncmp(map_cut[i], "##end", 5) == 0)
					break;
				i++;
			}
			if (ft_strncmp(map_cut[i], "##start", 7) == 0){
				i++;
				while(map_cut[i] && map_cut[i][0] == '#')
					i++;
				if (!map_cut[i])
					break;
				if (ft_verif_room(map_cut[i]) == 1){ 
					map.start = map_cut[i];
					tmp = ft_split(map_cut[i], ' ');
					map.room_start.room_nbPipes = 0;
					map.room_start.name = tmp[0];
					map.room_start.heat_point = 0;
					map.room_start.posX = ft_atoi(tmp[1]);
					map.room_start.posY = ft_atoi(tmp[2]);
					map.room_start.index = other_room_nb;
					free(tmp);
				}
			}
			else if (ft_strncmp(map_cut[i], "##end", 5) == 0){
				i++;
				while(map_cut[i] && map_cut[i][0] == '#')
					i++;
				if (!map_cut[i])
					break;
				if (ft_verif_room(map_cut[i]) == 1){
					map.end = map_cut[i];
					tmp = ft_split(map_cut[i], ' ');
					map.room_end.room_nbPipes = 0;
					map.room_end.heat_point = 0;
					map.room_end.name = tmp[0];
					map.room_end.posX = ft_atoi(tmp[1]);
					map.room_end.posY = ft_atoi(tmp[2]);
					map.room_end.index = other_room_nb;
					free(tmp);
					}
			}
			else
			{
				if (!map_cut[i])
					break;
				if (ft_verif_room(map_cut[i]) == 1){
					map.map[other_room_nb] = map_cut[i];
					tmp = ft_split(map_cut[i], ' ');
					map.room[other_room_nb].room_nbPipes = 0;
					map.room[other_room_nb].heat_point = 0;
					map.room[other_room_nb].name = tmp[0];
					map.room[other_room_nb].posX = ft_atoi(tmp[1]);
					map.room[other_room_nb].posY = ft_atoi(tmp[2]);
					map.room[other_room_nb].index = other_room_nb;
					map.room[other_room_nb].hold = false;
					free(tmp);
					other_room_nb++;
					}
				else{
					map.nbRoom = other_room_nb;
					ft_name_room(&map);
					part++;
				}
			}
		}
		if (part == 3){
			while(map_cut[i] && map_cut[i][0] == '#')
				i++;
			if (!map_cut[i])
				break;
			if(ft_verif_pipes(map_cut[i], map) == 1){
				map.pipes[nb_pipes] = map_cut[i];
				nb_pipes++;
			}
		}
		printf("%s\n", map_cut[i]);
		i++;
	}
	map.nbPipe = nb_pipes;
	ft_setPipe(&map);

	ft_heat_map(&map);
	ft_breath(&map);


	ft_resolve(&map);

	free(buf);
	return 0;
}