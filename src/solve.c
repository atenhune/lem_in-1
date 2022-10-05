/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:55:18 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/05 19:31:57 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	solve(t_lem *d, t_bfs *bf)
{
	int	ret;

	if (d->start_to_end == true)
		return (1);
	if (init_bfs(d, bf) < 0)
		return (panic(NULL, "Error: Failed to initialize bfs."));
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
