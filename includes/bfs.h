/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:51:41 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/05 14:47:01 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

typedef struct s_bfs
{
	int			**flow;
	int			*fl_dir;
	t_pathset	*best;
}				t_bfs;

void	debug_bfs(t_lem *d, t_bfs *bf, t_pathset *set);

int		init_bfs(t_lem *d, t_bfs *bfs);
int		bfs(t_lem *d, t_bfs *bf);
void	set_seen_from_start(t_lem *d, t_bfs *bf, t_pathset *set);
int		is_next(t_bfs *bf, t_pathset *set);
int		stepped_on_a_path(t_bfs *bf, t_pathset *set);
void	update_seen(t_lem *d, t_bfs *bf, t_pathset *set);
void	reverse_flow(t_lem *d, t_bfs *bf, t_pathset *set);
void	place_flow(t_bfs *bf, int cur, int next);
int		is_child(int *list, int prev);
void	set_flow(t_lem *d, t_bfs *bf, t_pathset *set);
void	path_collector(t_lem *d, t_bfs *bf, t_pathset *set);
void	set_fl_dir(t_lem *d, t_bfs *bf, t_pathset *set);

int		turn_amount(t_lem *d, t_pathset *set);
void	place_ant(t_pathset *set);
int		last_ant(t_pathset *set);

// bfs retry

void	double_check_paths(t_lem *d, t_bfs *bf);

#endif
