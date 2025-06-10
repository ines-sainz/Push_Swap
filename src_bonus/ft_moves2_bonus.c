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

#include "ft_push_swap_bonus.h"

/**
 * @brief Performs a reverse rotate operation on a given stack.
 *
 * Moves the last element of the stack to the top (reverse rotate).
 *
 * @param list Pointer to the list containing the stack.
 * @param first_node Pointer to the head of the stack to rotate.
 * @param c Stack identifier ('a' or 'b'), unused here.
 * @return 0 on success, 1 if the stack is empty or has only one element.
 */
int	ft_rrab(t_list *list, t_stack **first_node, char c)
{
	t_stack	*temp;
	int		i;

	i = 0;
	(void)c;
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
	return (0);
}

/**
 * @brief Performs reverse rotate on both stacks simultaneously.
 *
 * Calls ft_rrab on both stack A and stack B.
 *
 * @param list Pointer to the list containing both stacks.
 * @return 0 on success, 1 if both operations failed.
 */
int	ft_rrr(t_list *list)
{
	if (ft_rrab(list, &list->first_node_a, 'x') == 1
		&& ft_rrab(list, &list->first_node_b, 'x') == 1)
		return (1);
	return (0);
}
