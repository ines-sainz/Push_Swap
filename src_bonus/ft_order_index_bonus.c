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

#include "ft_push_swap_bonus.h"

/**
 * @brief Checks if a list is ordered in ascending order.
 *
 * This function verifies if the list `list->first_node_a` is sorted in
 * ascending order by comparing the content of each node with the next one.
 * It also returns early if `first_node_b` is not NULL.
 *
 * @param list Pointer to the t_list structure containing the nodes.
 * 
 * @return int Returns 0 if the list is sorted and `first_node_b` is NULL.
 *             Returns 1 otherwise (if unsorted or `first_node_b` is not NULL).
 */
int	ft_ordered_list(t_list *list)
{
	if (list->first_node_b != NULL)
		return (1);
	list->iterator = list->first_node_a;
	while (list->iterator->next != NULL)
	{
		if (list->iterator->content > list->iterator->next->content)
			return (1);
		list->iterator = list->iterator->next;
	}
	return (0);
}
