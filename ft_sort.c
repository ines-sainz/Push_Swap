/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:08:24 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/13 14:58:33 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_count_rb(t_list *list, int index)
{
	int	i;

	i = 0;
	list->iterator = list->first_node_b;
	while (list->iterator && list->iterator->index != index)
	{
		list->iterator = list->iterator->next;
		i++;
	}
	return (i);
}

int	ft_k_sort2(t_list *list)
{
	int	num_rb;
	int	num_rrb;
	int	num_numbers;

	num_numbers = list->n_numbers;
	while (num_numbers - 1 >= 0)
	{
		num_rb = ft_count_rb(list, num_numbers - 1);
		num_rrb = (num_numbers + 3) - num_rb;
		if (num_rb <= num_rrb)
		{
			while (list->first_node_b->index != num_numbers - 1)
				ft_rab(list, &list->first_node_b, 'b');
			ft_pab(&list->first_node_b, &list->first_node_a, 'a');
			num_numbers--;
		}
		else
		{
			while (list->first_node_b->index != num_numbers - 1)
				ft_rrab(list, &list->first_node_b, 'b');
			ft_pab(&list->first_node_b, &list->first_node_a, 'a');
			num_numbers--;
		}
	}
	return (0);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

int	ft_k_sort1(t_list *list)
{
	int	k;
	int	i;
	int	sqrt;

	sqrt = ft_sqrt(list->n_numbers);
	k = sqrt * 14 / 10;
	i = 0;
	while (list->first_node_a)
	{
		if (list->first_node_a->index <= i)
		{
			ft_pab(&list->first_node_a, &list->first_node_b, 'b');
			ft_rab(list, &list->first_node_b, 'b');
			i++;
		}
		else if (list->first_node_a->index <= i + k)
		{
			ft_pab(&list->first_node_a, &list->first_node_b, 'b');
			i++;
		}
		else
			ft_rab(list, &list->first_node_a, 'a');
	}
	return (0);
}

int	ft_sort(t_list *list)
{
	ft_k_sort1(list);
	ft_k_sort2(list);
	return (0);
}
