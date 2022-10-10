/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & atenhune <@student.hive.fi>       +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:52:57 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/10 11:23:36 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

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
	int		count;
	int		turns;
	int		cur;
	int		flag;
	int		index;
	int		seen_len;
}			t_pathset;

int		init_pathset(t_lem *d, t_pathset *set);
int		panic_pathset(t_lem *d, t_pathset *set, const char *msg);
void	free_pathset(t_lem *d, t_pathset *set);

#endif
