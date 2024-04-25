/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/25 07:47:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_push(t_stack **a, t_stack **b, int len)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i <= len - 3)
	{
		while ((*a)->p_index != i)
		{
			(*a) = (*a)->next;
			index++;
		}
		if (index < (len - index))
		{
			ft_ra(a, index);
			ft_pb(a, b, 1);
		}
		else
		{
			ft_rra(a, index -1);
			ft_pb(a, b, 1);
		}
	}
}

void	ft_bigsort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_lstsize(*a);
	ft_rotate_push(a, b, len);
	ft_tiny_sort(a);
	ft_pa(a, b, len - 3);
}
