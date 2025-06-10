/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:39:16 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/07 10:45:36 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/**
 * @brief Writes the rotate-reverse operation to standard output.
 *
 * Prints "rra" or "rrb" followed by a newline based on the given character.
 *
 * @param c Character representing the target stack ('a' or 'b').
 */
void	ft_write(char c)
{
	if (c == 'a' || c == 'b')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

/**
 * @brief Performs a reverse rotate on the given stack.
 *
 * Moves the last element to the front of the stack and writes the
 * operation name if 'a' or 'b' is passed.
 *
 * @param list Pointer to the list structure containing iterators.
 * @param first_node Pointer to the stack to operate on.
 * @param c Character indicating which stack is rotated ('a' or 'b').
 * @return 0 on success, 1 if the stack has fewer than 2 elements.
 */
int	ft_rrab(t_list *list, t_stack **first_node, char c)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (*first_node == NULL || (*first_node)->next == NULL)
		return (1);
	list->iterator = *first_node;
	while (list->iterator->next != NULL)
	{
		list->iterator = list->iterator->next;
		i++;
	}
	list->iterator = *first_node;
	while (list->iterator->next != NULL)
	{
		if (i == 1)
			temp = list->iterator;
		list->iterator = list->iterator->next;
		i--;
	}
	temp->next = NULL;
	list->iterator->next = *first_node;
	*first_node = list->iterator;
	ft_write(c);
	return (0);
}

/**
 * @brief Performs a reverse rotate on both stack A and B simultaneously.
 *
 * Applies reverse rotate to both stacks without printing rra/rrb individually.
 *
 * @param list Pointer to the list structure containing both stacks.
 * @return 0 on success, 1 if both stacks can't be rotated.
 */
int	ft_rrr(t_list *list)
{
	if (ft_rrab(list, &list->first_node_a, 'x') == 1
		&& ft_rrab(list, &list->first_node_b, 'x') == 1)
		return (1);
	write(1, "rrr", 3);
	write(1, "\n", 1);
	return (0);
}
