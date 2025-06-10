/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:03:40 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/13 15:11:43 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_list
{
	t_stack	*first_node_a;
	t_stack	*first_node_b;
	t_stack	*iterator;
	int		n_numbers;
}	t_list;

int		ft_error(void);
int		ft_parse_and_stack(int argc, char **argv, t_list *list);
int		ft_create_stack(int number, t_list *list);
void	ft_lstclear(t_list *list);
int		ft_push_swap(t_list *list);
int		ft_sab(t_stack *first_node, char c);
int		ft_ss(t_list *list);
int		ft_pab(t_stack **to_move, t_stack **to_put, char c);
int		ft_rab(t_list *list, t_stack **first_node, char c);
int		ft_rr(t_list *list);
int		ft_rrab(t_list *list, t_stack **first_node, char c);
int		ft_rrr(t_list *list);
int		ft_ordered_list(t_list *list);

#endif
