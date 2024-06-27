/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:54:10 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/01 11:24:44 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <unistd.h>

int	ft_sab(t_stack *first_node, char c)
{
	int	temp_num;

	if (first_node == NULL || first_node->next == NULL)
		return (1);
	temp_num = first_node->content;
	first_node->content = first_node->next->content;
	first_node->next->content = temp_num;
	if (c == 'a' || c == 'b')
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	return (0);
}

int	ft_ss(t_list *list)
{
	if ((ft_sab(list->first_node_a, 'x') == 1)
		&& (ft_sab(list->first_node_b, 'x') == 1))
		return (1);
	write(1, "ss", 2);
	write(1, "\n", 1);
	return (0);
}

int	ft_pab(t_stack **to_move, t_stack **to_put, char c)
{
	t_stack	*temp;

	if (*to_move == NULL)
		return (1);
	if (*to_put == NULL)
	{
		temp = *to_move;
		*to_move = (*to_move)->next;
		*to_put = temp;
		temp->next = NULL;
	}
	else
	{
		temp = *to_move;
		*to_move = (*to_move)->next;
		temp->next = *to_put;
		*to_put = temp;
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}

int	ft_rab(t_list *list, t_stack **first_node, char c)
{
	t_stack	*temp;

	if (*first_node == NULL || (*first_node)->next == NULL)
		return (1);
	temp = *first_node;
	*first_node = (*first_node)->next;
	list->iterator = *first_node;
	while (list->iterator->next != NULL)
		list->iterator = list->iterator->next;
	list->iterator->next = temp;
	temp->next = NULL;
	if (c == 'a' || c == 'b')
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	return (0);
}

int	ft_rr(t_list *list)
{
	if ((ft_rab(list, &list->first_node_a, 'x') == 1)
		&& (ft_rab(list, &list->first_node_b, 'x') == 1))
		return (1);
	write(1, "rr", 2);
	write(1, "\n", 1);
	return (0);
}
