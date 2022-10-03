/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:55:18 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/03 15:03:57 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static void	sort_paths(t_lem *d, t_bfs *bf)
// {
// 	size_t	i;

// 	i = 0;
	
// }

int	solve(t_lem *d, t_bfs *bf)
{
	int	ret;

	init_bfs(d, bf);
	ret = 1;
	while (ret == 1)
	{
		ret = bfs(d, bf);
		if (ret < 0)
			return (panic(NULL, "Error: Memory issue in bfs."));
	}
	if (!bf->best)
		return (panic(NULL, "Error: No solution."));
	
	return (1);
}
