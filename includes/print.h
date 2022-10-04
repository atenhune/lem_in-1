/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:14:15 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/04 18:25:15 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

typedef struct s_printer
{
	t_vec	result;
	int		*ant_line;
	int		**ants_on_paths;
	int		path_count;
	int		done;
}			t_printer;

void	free_printer(t_printer *p);
int		panic_printer(t_printer *p, const char *msg);

#endif
