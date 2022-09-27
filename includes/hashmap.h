//header

#ifndef HASHMAP_H

# define HASHMAP_H

# include "libft.h"

# define TABLE_SIZE 10000

typedef struct s_hash
{
	char	*room;
	int		index;
}		t_hash;


unsigned long	hash(char *name);
int				hash_insert(char *room, int index, t_hash *hash_table);
int				hash_lookup(char *room, t_hash *hash_table);
int				hash_get(char *room, t_hash *hash_table);

#endif
