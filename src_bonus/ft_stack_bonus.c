/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:59:34 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/13 16:28:40 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	ft_lstclear(t_list *list)
{
	t_stack	*temp;

	if (list->first_node_a != NULL)
	{
		list->iterator = list->first_node_a;
		while (list->iterator != NULL)
		{
			temp = list->iterator;
			list->iterator = list->iterator->next;
			free(temp);
		}
		temp = NULL;
		list->first_node_a = NULL;
	}
	if (list->first_node_b != NULL)
	{
		list->iterator = list->first_node_b;
		while (list->iterator != NULL)
		{
			temp = list->iterator;
			list->iterator = list->iterator->next;
			free(temp);
		}
		temp = NULL;
	}
}

int	ft_lstadd_back(t_list *list, t_stack *temp)
{
	if (list->first_node_a == NULL)
	{
		list->first_node_a = temp;
		return (0);
	}
	list->iterator = list->first_node_a;
	while (list->iterator->next != NULL)
	{
		if (list->iterator->content == temp->content)
			return (1);
		list->iterator = list->iterator->next;
	}
	if (list->iterator->content == temp->content)
		return (1);
	list->iterator->next = temp;
	return (0);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*element;

	element = (t_stack *)malloc(sizeof(t_stack));
	if (!element)
		return (0);
	element->content = content;
	element->next = NULL;
	return (element);
}

int	ft_create_stack(int number, t_list *list)
{
	t_stack	*temp;

	temp = ft_lstnew(number);
	if (!temp)
	{
		ft_lstclear(list);
		return (1);
	}
	if (ft_lstadd_back(list, temp) == 1)
	{
		ft_lstclear(list);
		return (free(temp), 1);
	}
	list->n_numbers++;
	return (0);
}
