/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:07:37 by altikka           #+#    #+#             */
/*   Updated: 2022/09/15 17:28:17 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* PLAN
 * 0: some options like -q etc
 * i: init data
 * ii: parse data
 * iii: solve
 * iv: print
 */

int	main(int argc, char **argv)
{
	t_lem	d;

	//0: -q etc
	(void ) argc;
	(void ) argv;
	if (init_data(&d) < 0)
		return (panic(NULL, "Error: Initializing data failed."));
	//if (parse_data(&d) < 0)
	//	return (panic(NULL, "Error: Parsing data failed."));
	//* iii: solve
	//* iv: print
	return (0);
}
