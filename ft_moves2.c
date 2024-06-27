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
#include <unistd.h>

void	ft_write(char c)
{
	if (c == 'a' || c == 'b')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

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

int	ft_rrr(t_list *list)
{
	if (ft_rrab(list, &list->first_node_a, 'x') == 1
		&& ft_rrab(list, &list->first_node_b, 'x') == 1)
		return (1);
	write(1, "rrr", 3);
	write(1, "\n", 1);
	return (0);
}
