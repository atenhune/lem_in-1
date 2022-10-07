/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:14:15 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/07 17:56:37 by altikka          ###   ########.fr       */
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
	t_flag	flag;
	int		done;
}			t_printer;

int		init_printer(t_bfs *bf, t_printer *p, t_flag flag);
int		panic_printer(t_printer *p, const char *msg);
void	free_printer(t_printer *p);
void	sort_paths(t_bfs *bf);
void	place_ants_in_line(t_lem *d, t_bfs *bf, t_printer *p);
int		place_ants_on_paths(t_lem *d, t_bfs *bf, t_printer *p);
void	print_options(t_lem *d, t_bfs *bf, t_printer *p, t_vec *farm);
int		print_send_all(t_lem *d, t_vec *farm, t_flag flag);

#endif
