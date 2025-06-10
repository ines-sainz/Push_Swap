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

#include "ft_push_swap_bonus.h"

/**
 * @brief Checks if the input string is a valid move command.
 *
 * Validates the command in `buffer` against known push_swap operations.
 *
 * @param buffer The input string to validate (e.g., "sa\n", "rrr\n").
 * @return int Returns 0 if valid move, 1 if invalid.
 */
int	check_if_move(char *buffer)
{
	int	len;

	len = ft_strlen(buffer);
	if ((ft_strncmp(buffer, "sa\n", len) == 0 && len == 3)
		|| (ft_strncmp(buffer, "sb\n", len) == 0 && len == 3))
		return (0);
	if (ft_strncmp(buffer, "ss\n", len) == 0 && len == 3)
		return (0);
	if (ft_strncmp(buffer, "pa\n", len) == 0 && len == 3)
		return (0);
	if (ft_strncmp(buffer, "pb\n", len) == 0 && len == 3)
		return (0);
	if (ft_strncmp(buffer, "ra\n", len) == 0 && len == 3)
		return (0);
	if (ft_strncmp(buffer, "rb\n", len) == 0 && len == 3)
		return (0);
	if (ft_strncmp(buffer, "rr\n", len) == 0 && len == 3)
		return (0);
	if (ft_strncmp(buffer, "rra\n", len) == 0 && len == 4)
		return (0);
	if (ft_strncmp(buffer, "rrb\n", len) == 0 && len == 4)
		return (0);
	if (ft_strncmp(buffer, "rrr\n", len) == 0 && len == 4)
		return (0);
	return (1);
}

/**
 * @brief Executes a stack operation based on the command in buffer.
 *
 * Maps the input move string to the corresponding stack manipulation
 * function (e.g., swap, push, rotate, reverse rotate).
 *
 * @param buffer The command string (e.g., "pb\n", "rr\n").
 * @param list The list structure holding both stacks.
 */
void	make_move(char *buffer, t_list *list)
{
	int	len;

	len = ft_strlen(buffer);
	if (ft_strncmp(buffer, "sa\n", len) == 0 && len == 3)
		ft_sab(list->first_node_a, 'a');
	else if (ft_strncmp(buffer, "sb\n", len) == 0 && len == 3)
		ft_sab(list->first_node_b, 'b');
	else if (ft_strncmp(buffer, "ss\n", len) == 0 && len == 3)
		ft_ss(list);
	else if (ft_strncmp(buffer, "pa\n", len) == 0 && len == 3)
		ft_pab(&list->first_node_b, &list->first_node_a, 'a');
	else if (ft_strncmp(buffer, "pb\n", len) == 0 && len == 3)
		ft_pab(&list->first_node_a, &list->first_node_b, 'b');
	else if (ft_strncmp(buffer, "ra\n", len) == 0 && len == 3)
		ft_rab(list, &list->first_node_a, 'a');
	else if (ft_strncmp(buffer, "rb\n", len) == 0 && len == 3)
		ft_rab(list, &list->first_node_b, 'b');
	else if (ft_strncmp(buffer, "rr\n", len) == 0 && len == 3)
		ft_rr(list);
	else if (ft_strncmp(buffer, "rra\n", len) == 0 && len == 4)
		ft_rrab(list, &list->first_node_a, 'a');
	else if (ft_strncmp(buffer, "rrb\n", len) == 0 && len == 4)
		ft_rrab(list, &list->first_node_b, 'b');
	else if (ft_strncmp(buffer, "rrr\n", len) == 0 && len == 4)
		ft_rrr(list);
}

/**
 * @brief Main function to execute moves for the push_swap checker.
 *
 * Reads commands from standard input and applies them to the stack.
 * Verifies input validity and checks final list order.
 *
 * @param list The list structure holding the two stacks.
 * @return int 0 if list is sorted and valid, 1 on error, 2 if unsorted.
 */
int	ft_push_swap(t_list *list)
{
	int		n_bytes;
	char	buffer[1024];

	if (!list->first_node_a)
		return (1);
	while (1)
	{
		n_bytes = read(1, buffer, 1024);
		if (n_bytes < 0)
			return (1);
		if (n_bytes == 0)
			break ;
		buffer[n_bytes] = '\0';
		if (check_if_move(buffer) == 1)
			return (1);
		else
		{
			make_move(buffer, list);
		}
	}
	if (ft_ordered_list(list) == 0)
		return (0);
	return (2);
}
