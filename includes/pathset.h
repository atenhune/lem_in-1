/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:52:57 by atenhune          #+#    #+#             */
/*   Updated: 2022/09/30 18:57:27 by atenhune         ###   ########.fr       */
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
	int		**child;
	int		**to;
	int		**entries;
	int		*seen;
	int		*first;
	int		*parent;
	int		*used;
	int		*weight;
	int		*from;
	int		len;
	int		count; //jhjghh
	int		turns; //lhkkhk
	int		cur;
	int		flag;
	int		index; // seen index
	int		seen_len;
	// int		*cur_path;
	// int		*temp;
	// int		state; // 
} t_pathset;

void	zero_pathset(t_lem *d, t_pathset *set);
void	init_pathset(t_lem *d, t_pathset *set);
void	del_set(t_lem *d, t_pathset *set);
#endif