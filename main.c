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

/**
 * @brief Frees all nodes in the list if list A is not empty.
 * 
 * Calls ft_lstclear() to clear the linked list `first_node_a` if it's not
 * already NULL. Ensures that allocated memory is released.
 * 
 * @param list Pointer to the list structure to free.
 */
void	ft_free(t_list *list)
{
	if (list->first_node_a != NULL)
		ft_lstclear(list);
}

/**
 * @brief Prints an error message to stderr.
 * 
 * Outputs "Error\n" to file descriptor 2 and returns 1.
 * 
 * @return Always returns 1 to indicate error.
 */
int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

/**
 * @brief Initializes all fields of the list structure to default values.
 * 
 * Sets both list heads to NULL and resets the element counter to 0.
 * 
 * @param list Pointer to the list structure to initialize.
 */
void	inicialize_structure(t_list *list)
{
	list->first_node_a = NULL;
	list->first_node_b = NULL;
	list->n_numbers = 0;
}

/**
 * @brief Entry point of the program. Parses args and executes push_swap.
 * 
 * Initializes the list structure, parses input arguments, and if valid,
 * performs the push_swap algorithm. Handles errors and cleanup.
 * 
 * @param argc Argument count from the command line.
 * @param argv Argument vector from the command line.
 * 
 * @return 0 on success, 1 on error or invalid input.
 */
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
