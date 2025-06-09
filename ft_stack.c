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

#include "ft_push_swap.h"

/**
 * @brief Frees all nodes in the stack and resets the list.
 *
 * Iterates over all nodes in list->first_node_a, freeing each one.
 *
 * @param list Pointer to the list structure containing the stack.
 */
void	ft_lstclear(t_list *list)
{
	t_stack	*temp;

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

/**
 * @brief Adds a new node to the end of the stack if it's not a duplicate.
 *
 * If the list is empty, sets the node as the first. Prevents duplicate
 * contents.
 *
 * @param list Pointer to the list structure.
 * @param temp Pointer to the new node to add.
 * @return 0 on success, 1 if a duplicate value is found.
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
 * @brief Creates a new stack node with the given content.
 *
 * Allocates and initializes a new t_stack node.
 *
 * @param content Integer value to store in the node.
 * @return Pointer to the new node, or NULL on allocation failure.
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
 * @brief Creates and adds a number to the stack, checking for duplicates.
 *
 * Wraps ft_lstnew() and ft_lstadd_back(). On error, clears the list and
 * frees memory.
 *
 * @param number The number to add to the stack.
 * @param list Pointer to the list structure.
 * @return 0 on success, 1 on error or duplicate.
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
