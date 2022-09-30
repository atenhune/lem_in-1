/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:52:57 by atenhune          #+#    #+#             */
/*   Updated: 2022/09/30 14:26:15 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

// typedef struct s_lem
// {
// 	int		ants;
// 	t_vec	rooms;
// 	int		**links;
// 	int		room_count; // <------ antti muuttaa!
// 	int		start;
// 	int		end;
// }			t_lem;

typedef struct s_pathset
{
	int		**paths;
	int		**entries;
	int		*cur_path;
	int		**child;
	int		**to;
	int		*seen;
	int		*first;
	int		*temp;
	int		*parent;
	int		*used;
	int		*weight;
	int		*from;
	int		len;
	int		count;
	int		turns;
	int		cur;
	int		flag;
	int		index;
	int		seen_len;
	int		state; // 
} t_pathset;

void	zero_pathset(t_lem *d, t_pathset *set);
void	init_pathset(t_lem *d, t_pathset *set);
void	del_set(t_lem *d, t_pathset *set);
#endif