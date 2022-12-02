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
	char **done_name;
	int *done_index;

	i = 0;
	nb_done = 0;
	// int tmp;
	// tmp = 0;
	done_name = malloc(1000000000);
	
	done_index = malloc(sizeof(int *) + map->nbRoom * 4);

	while(i != map->room_end.room_nbPipes){
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

	int y;
	int start_find = 0;
	while(nb_done + start_find < map->nbRoom + 1 && done_name[i]){
		if (ft_strcmp(done_name[i], map->room_start.name) == 0 || ft_strcmp(done_name[i], map->room_end.name) == 0){
			;
		}
		else {
			j = 0;
			while (j < map->room[done_index[i]].room_nbPipes)
			{
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

	if (ft_strcmp(tmp[0], tmp[1]) == 0){
		return -1;
	}

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
	map.map = malloc(sizeof(char **) * (ft_strlen(buf)));
	map.room = malloc(sizeof(t_room) * (ft_strlen(buf)));
	map.pipes = malloc(sizeof(char **) * (ft_strlen(buf)));

	while (map_cut[i])
	{
		if (part == 1 && (map_cut[i][0] >= '0' && map_cut[i][0] <= '9'))
		{
			int u = 0;
			while (map_cut[i][u] && (map_cut[i][u] >= '0' && map_cut[i][u] <= '9')){
				u++;
			}
			if (map_cut[i][u] && map_cut[i][u] != '#'){
				printf("ERROR No Ants\n");
				free(map_cut);
				free(buf);
				free(map.map);
				free(map.pipes);
				return (-1);
			}
			else
			{
				map.nb_ants = ft_atoi(map_cut[i]);
				part++;
			}
			
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
				printf("%s\n", map_cut[i]);
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
				printf("%s\n", map_cut[i]);
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
				else if (map.start && map.end){
					map.nbRoom = other_room_nb;
					printf("room name\n");
					map.roomName = malloc(sizeof(char *) * 1000);
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
	if (!map.start || !map.end){
		free(buf);
		free(map_cut);
		free(map.room);
		free(map.map);
		free(map.pipes);
		printf("ERROR no start or end\n");
		return (-1);
	}
	map.nbPipe = nb_pipes;
	i = 0;
	while (i < map.nbRoom)
	{
		map.room[i].room_pipes = malloc((sizeof nb_pipes) * nb_pipes);
		map.room[i].room_index = malloc((sizeof nb_pipes) * (map.room[i].room_nbPipes + nb_pipes));
		i++;
	}
	map.room_start.room_pipes = malloc((sizeof nb_pipes) * nb_pipes);
	map.room_start.room_index = malloc((sizeof nb_pipes) * (map.room[i].room_nbPipes + nb_pipes));
	map.room_end.room_pipes = malloc((sizeof nb_pipes) * nb_pipes);
	map.room_end.room_index = malloc((sizeof nb_pipes) * (map.room[i].room_nbPipes + nb_pipes));
	
	ft_setPipe(&map);
	ft_heat_map(&map);
	ft_breath(&map);

	i = 0;
	int nb_done = 0;
	while (map.room_start.room_nbPipes > i){
		if (map.path[i].done == true)
			nb_done++;
		i++;
	}
	if (nb_done > 0)
		ft_resolve(&map);
	else {
		printf("ERROR no path found\n");
	}
	i = 0;
	while (i < map.nbRoom)
	{
		free(map.room[i].room_pipes);
		free(map.room[i].room_index);
		i++;
	}
	free(map.roomName);
	free(map.room_start.room_pipes);
	free(map.room_start.room_index);
	free(map.room_end.room_pipes);
	free(map.room_end.room_index);
	free(buf);
	free(tmp);
	free(map.map);
	free(map.pipes);
	free(map_cut);
	free(map.path);
	free(map.room);
	return 0;
}