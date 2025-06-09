/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_ordenate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:20:36 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/11 11:06:52 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/**
 * @brief Sorts a stack of five numbers using the push_swap algorithm.
 *
 * Moves the two smallest elements to stack B, sorts the remaining three in
 * stack A, then reorders and pushes elements from B back to A.
 *
 * @param list Pointer to the list structure containing the stacks.
 */
void	ft_five_numbers(t_list *list)
{
	int	i;

	i = 0;
	while (list->first_node_a && i < 2)
	{
		if (list->first_node_a->index == 0 || list->first_node_a->index == 1)
		{
			ft_pab(&list->first_node_a, &list->first_node_b, 'b');
			i++;
		}
		else
			ft_rab(list, &list->first_node_a, 'a');
	}
	ft_three_numbers(list);
	if (list->first_node_b->content < list->first_node_b->next->content)
		ft_sab(list->first_node_b, 'b');
	while (list->first_node_b)
		ft_pab(&list->first_node_b, &list->first_node_a, 'a');
}

/**
 * @brief Sorts a stack of four numbers using the push_swap algorithm.
 *
 * Pushes the smallest three elements to stack B, then reinserts them into
 * stack A in correct order.
 *
 * @param list Pointer to the list structure containing the stacks.
 */
void	ft_four_numbers(t_list *list)
{
	int	i;

	i = 0;
	while (list->first_node_a && i < 3)
	{
		if (list->first_node_a->index == i)
		{
			ft_pab(&list->first_node_a, &list->first_node_b, 'b');
			i++;
		}
		else
			ft_rab(list, &list->first_node_a, 'a');
	}
	while (list->first_node_b)
		ft_pab(&list->first_node_b, &list->first_node_a, 'a');
}

/**
 * @brief Sorts a stack of three numbers in-place.
 *
 * Uses conditional logic to determine and apply minimal operations
 * (swap, rotate, reverse) to sort three elements in stack A.
 *
 * @param list Pointer to the list structure containing the stack.
 */
void	ft_three_numbers(t_list *list)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = list->first_node_a->content;
	num2 = list->first_node_a->next->content;
	num3 = list->first_node_a->next->next->content;
	if (num2 > num1 && num2 > num3 && num1 < num3)
	{
		ft_pab(&list->first_node_a, &list->first_node_b, 'b');
		ft_sab(list->first_node_a, 'a');
		ft_pab(&list->first_node_b, &list->first_node_a, 'a');
	}
	else if (num2 < num1 && num2 < num3 && num1 < num3)
		ft_sab(list->first_node_a, 'a');
	else if (num2 < num1 && num2 > num3 && num1 > num3)
	{
		ft_sab(list->first_node_a, 'a');
		ft_rab(list, &list->first_node_a, 'a');
		ft_rab(list, &list->first_node_a, 'a');
	}
	else if (num2 > num1 && num2 > num3 && num1 > num3)
		ft_rrab(list, &list->first_node_a, 'a');
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		ft_rab(list, &list->first_node_a, 'a');
}

/**
 * @brief Sorts stacks of 2 to 5 elements with optimized logic.
 *
 * Delegates to specialized functions based on number of elements.
 *
 * @param list Pointer to the list structure containing the stack.
 * @return 0 on success, 1 on error.
 */
int	ft_small_ordenate(t_list *list)
{
	if (list->n_numbers == 2)
		return (ft_sab(list->first_node_a, 'a'));
	if (list->n_numbers == 3)
	{
		ft_three_numbers(list);
		return (0);
	}
	if (list->n_numbers == 4)
	{
		ft_four_numbers(list);
		return (0);
	}
	if (list->n_numbers == 5)
	{
		ft_five_numbers(list);
		return (0);
	}
	return (0);
}
