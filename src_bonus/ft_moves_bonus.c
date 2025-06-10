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

#include "ft_push_swap_bonus.h"

/**
 * @brief Swaps the first two elements of a stack.
 *
 * @param first_node Pointer to the head of the stack.
 * @param c Stack identifier (unused).
 * @return 0 on success, 1 if the stack is empty or has one element.
 */
int	ft_sab(t_stack *first_node, char c)
{
	int	temp_num;

	(void)c;
	if (first_node == NULL || first_node->next == NULL)
		return (1);
	temp_num = first_node->content;
	first_node->content = first_node->next->content;
	first_node->next->content = temp_num;
	return (0);
}

/**
 * @brief Swaps the first two elements of both stacks A and B.
 *
 * @param list Pointer to the list containing both stacks.
 * @return 0 on success, 1 if both stacks have fewer than two elements.
 */
int	ft_ss(t_list *list)
{
	if ((ft_sab(list->first_node_a, 'x') == 1)
		&& (ft_sab(list->first_node_b, 'x') == 1))
		return (1);
	return (0);
}

/**
 * @brief Pushes the top element from one stack to another.
 *
 * @param to_move Pointer to the source stack.
 * @param to_put Pointer to the destination stack.
 * @param c Stack identifier (unused).
 * @return 0 on success, 1 if the source stack is empty.
 */
int	ft_pab(t_stack **to_move, t_stack **to_put, char c)
{
	t_stack	*temp;

	(void)c;
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
	return (0);
}

/**
 * @brief Rotates a stack upwards (first element becomes last).
 *
 * @param list Pointer to the list containing the stack.
 * @param first_node Pointer to the head of the stack to rotate.
 * @param c Stack identifier (unused).
 * @return 0 on success, 1 if the stack is empty or has one element.
 */
int	ft_rab(t_list *list, t_stack **first_node, char c)
{
	t_stack	*temp;

	(void)c;
	if (*first_node == NULL || (*first_node)->next == NULL)
		return (1);
	temp = *first_node;
	*first_node = (*first_node)->next;
	list->iterator = *first_node;
	while (list->iterator->next != NULL)
		list->iterator = list->iterator->next;
	list->iterator->next = temp;
	temp->next = NULL;
	return (0);
}

/**
 * @brief Rotates both stacks A and B upwards.
 *
 * @param list Pointer to the list containing both stacks.
 * @return 0 on success, 1 if both stacks cannot be rotated.
 */
int	ft_rr(t_list *list)
{
	if ((ft_rab(list, &list->first_node_a, 'x') == 1)
		&& (ft_rab(list, &list->first_node_b, 'x') == 1))
		return (1);
	return (0);
}
