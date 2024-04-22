/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:46:33 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/22 06:10:23 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tiny_sort(t_stack **a)
{
	t_stack	*first;
	t_stack	*middle;
	t_stack	*last;

	first = *a;
	middle = (*a)->next;
	last = (*a)->next->next;
	if (middle->p_index > first->p_index && middle->p_index > last->p_index
		&& first->p_index < last->p_index)
	{
		ft_rra(&a, 1);
		ft_sa(&a, 1);
	}
	else if (middle->p_index < first->p_index && middle->p_index < last->p_index
		&& first->p_index < last->p_index)
		ft_sa(&a, 1);
	else if (middle->p_index > first->p_index && middle->p_index > last->p_index
		&& first->p_index > last->p_index)
		ft_rra(&a, 1);
	else if (middle->p_index < first->p_index && middle->p_index < last->p_index
		&& first->p_index > last->p_index)
		ft_ra(&a, 1);
	else if (middle->p_index < first->p_index
		&& middle->p_index > last->p_index)
		ft_rra(&a, 1);
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(a) == 2)
		ft_sa(&a, 1);
	else if (ft_lstsize(a) == 3)
		ft_tiny_sort(&a);
	else
		ft_bigsort(&a);
}
