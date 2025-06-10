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

/**
 * @brief Frees all nodes in both stacks of the given list.
 *
 * Iterates through stack A and B, freeing each node and resetting pointers.
 *
 * @param list The list structure containing both stacks.
 */
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

/**
 * @brief Adds a new node to the end of stack A if not duplicated.
 *
 * If the list is empty, sets the new node as the first. Prevents duplicates.
 *
 * @param list The list structure containing stack A.
 * @param temp The node to add.
 * @return int Returns 0 on success, 1 if duplicate found.
 */
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

/**
 * @brief Allocates and initializes a new stack node.
 *
 * Sets the node's content and initializes next to NULL.
 *
 * @param content The integer value to store in the node.
 * @return t_stack* Pointer to the new node, or NULL on allocation failure.
 */
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

/**
 * @brief Creates and adds a new number node to stack A.
 *
 * Allocates a new node and adds it to stack A, clearing list on failure.
 *
 * @param number The number to add to the stack.
 * @param list The list to add the number to.
 * @return int 0 on success, 1 on failure.
 */
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
