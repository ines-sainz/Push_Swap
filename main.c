/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:47:25 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/27 12:29:22 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_free(t_list *list)
{
	if (list->first_node_a != NULL)
		ft_lstclear(list);
}

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

void	inicialize_structure(t_list *list)
{
	list->first_node_a = NULL;
	list->first_node_b = NULL;
	list->n_numbers = 0;
}

int	main(int argc, char **argv)
{
	t_list	list;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	inicialize_structure(&list);
	if (ft_parse_and_stack(argc, argv, &list) == 1)
	{
		ft_error();
		ft_free(&list);
		return (1);
	}
	if (ft_push_swap(&list) == 1)
	{
		ft_error();
		ft_free(&list);
		return (1);
	}
	ft_free(&list);
	return (0);
}
