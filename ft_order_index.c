/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:24:46 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/02 12:31:21 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/**
 * @brief Checks if the stack in the list is not ordered in ascending order.
 *
 * Iterates over the stack and compares adjacent elements to detect disorder.
 *
 * @param list Pointer to the list structure.
 * @return 1 if the stack is not ordered, 0 if it is ordered.
 */
int	ft_ordered_list(t_list *list)
{
	list->iterator = list->first_node_a;
	while (list->iterator->next != NULL)
	{
		if (list->iterator->content > list->iterator->next->content)
			return (1);
		list->iterator = list->iterator->next;
	}
	return (0);
}

/**
 * @brief Assigns an index to each node based on its relative value.
 *
 * Each node gets an index representing how many other nodes have a smaller
 * value.
 *
 * @param list Pointer to the list structure.
 * @return Always returns 0.
 */
int	ft_write_index(t_list *list)
{
	int		down;
	t_stack	*temp;

	list->iterator = list->first_node_a;
	while (list->iterator != NULL)
	{
		temp = list->first_node_a;
		down = 0;
		while (temp != NULL)
		{
			if (list->iterator->content > temp->content)
				down++;
			temp = temp->next;
		}
		list->iterator->index = down;
		list->iterator = list->iterator->next;
	}
	return (0);
}
