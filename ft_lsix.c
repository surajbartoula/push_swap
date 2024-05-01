/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 07:19:38 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/01 07:27:24 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	anticlockwises(t_stack **a, t_stack **b, int index)
{
	ft_ra(a, index - 1);
	ft_pb(a, b, 1);
}

void	clockwises(t_stack **a, t_stack **b, int index, int size)
{
	ft_rra(a, (size - index) + 1);
	ft_pb(a, b, 1);
}

void	ft_rp_till6(t_stack **a, t_stack **b, int len)
{
	int		i;
	int		index;
	int		size;
	t_stack	*current;

	i = 1;
	while (i < len - 2)
	{
		index = 1;
		current = *a;
		size = ft_lstsize(current);
		while (current && current->p_index != i)
		{
			current = current->next;
			index++;
		}
		if (index <= (size - index))
			anticlockwises(a, b, index);
		else
			clockwises(a, b, index, size);
		i++;
	}
}
