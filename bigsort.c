/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/28 12:06:10 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_push(t_stack **a, t_stack **b, int len)
{
	int		i;
	int		index;
	t_stack	*current;

	i = 0;
	while (i < len - 2)
	{
		index = 1;
		current = *a;
		while (current && current->p_index != i)
		{
			current = current->next;
			index++;
		}
		if (index < (len - index))
		{
			ft_ra(a, index - 1);
			ft_pb(a, b, 1);
			len--;
		}
		else
		{
			ft_rra(a, len - index);
			ft_pb(a, b, 1);
			len--;
		}
		i++;
	}
}

void	ft_bigsort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_lstsize(*a);
	ft_rotate_push(a, b, len);
	if (ft_lstsize(*a) == 3)
		ft_tiny_sort(a);
	ft_pa(a, b, len - 3);
}
