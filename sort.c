/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:46:33 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/25 22:59:05 by sbartoul         ###   ########.fr       */
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
		ft_rra(a, 1);
		ft_sa(a, 1);
		ft_printf("rra\nsa\n");
	}
	else if (middle->p_index < first->p_index && middle->p_index < last->p_index
		&& first->p_index < last->p_index)
	{
		ft_sa(a, 1);
		ft_printf("sa\n");
	}
	else if (middle->p_index > first->p_index && middle->p_index > last->p_index
		&& first->p_index > last->p_index)
	{
		ft_rra(a, 1);
		ft_printf("rra\n");
	}
	else if (middle->p_index < first->p_index && middle->p_index < last->p_index
		&& first->p_index > last->p_index)
	{
		ft_ra(a, 1);
		ft_printf("ra\n");
	}
	else if (middle->p_index < first->p_index
		&& middle->p_index > last->p_index)
	{
		ft_rra(a, 1);
		ft_printf("rra\n");
	}
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;
	int		size;

	b = NULL;
	size = ft_lstsize(*a);
	if (size == 2)
		ft_sa(a, 1);
	else if (size == 3)
		ft_tiny_sort(a);
	else
		ft_bigsort(a, &b);
}
