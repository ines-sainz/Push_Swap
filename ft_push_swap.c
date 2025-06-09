/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:53:58 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/27 12:36:15 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/**
 * @brief Sorts the stack in the list using the push_swap algorithm.
 *
 * Determines if sorting is necessary and chooses between a small or full sort
 * based on the number of elements. Uses indexing to prepare for sorting.
 *
 * @param list Pointer to the list structure containing the stack.
 * @return 0 on success, 1 on error.
 */
int	ft_push_swap(t_list *list)
{
	if (!list->first_node_a)
		return (0);
	if (ft_ordered_list(list) == 0 || list->n_numbers == 1)
		return (0);
	if (ft_write_index(list) == 1)
		return (1);
	if (list->n_numbers <= 5)
		ft_small_ordenate(list);
	else
		ft_sort(list);
	return (0);
}
