/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:39:04 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/10 11:06:58 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# define TABLE_SIZE 13000

typedef struct s_hash
{
	char	*room;
	int		index;
}			t_hash;

unsigned long	hash(char *name);
int				hash_insert(char *room, int index, t_hash *hash_table);
int				hash_lookup(char *room, t_hash *hash_table);
int				hash_get(char *room, t_hash *hash_table);

#endif
