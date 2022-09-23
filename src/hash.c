//header

#include "lem_in"


int	hash_lookup(char *room, t_hash *hash_table)
{
	int	value;
	int	try;
	int	i;

	value = hash(room);
	try = (i + value) % TABLE_SIZE;
	i = 0;
	while (i < TABLE_SIZE && hash_table[try].room != NULL)
	{
		if (!ft_strncmp(room, hash_table[try].room, ft_strlen(room) + 1))
			return (0);
		i++;
		try = (i + value) % TABLE_SIZE;
	}
	return (1);
}

int	hash_table_insert(char *room, t_hash *hash_table)
{
	int	value;
	int	try;
	int	i;

	value = hash(room);
	try = (i + value) % TABLE_SIZE;
	i = 0;
	while (i < TABLE_SIZE)
    {
		if (hash_table[try].room == NULL)
		{
			hash_table[try].room = room;
			return (1);
		}
		i++;
		try = (i + value) % TABLE_SIZE;
	}
	return (0);
}

unsigned long	hash(char *name)
{
	unsigned long	hash_value;
	int				len;
	int				i;

	hash_value = 0;
	len = ft_strlen(name);
	i = 0;
	while (i < len)
	{
		hash_value += name[i] * (i + 1);
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
		i++;
	}
	return (hash_value);
}
