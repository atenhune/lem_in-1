/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:14:15 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/03 19:56:24 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

typedef struct s_printer
{
	t_vec	result;
	int		*ant_line;
	int		**ants_on_paths;
	int		done;
}			t_printer;

void	free_printer(t_printer *p);
int		panic_printer(t_printer *p, const char *msg);

#endif