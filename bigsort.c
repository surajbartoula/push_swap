/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/30 07:51:24 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	anticlock(int index, int size)
{
	if (index <= (size - index))
		return (1);
	return (0);
}

void	anticlockwise(t_stack **a, t_stack **b, int index)
{
	ft_ra(a, index - 1);
	ft_pb(a, b, 1);
}

void	clockwise(t_stack **a, t_stack **b, int index, int size)
{
	ft_rra(a, (size - index) + 1);
	ft_pb(a, b, 1);
}

void	rotatestack(t_stack **a, t_stack **b, int index, int size)
{
	if (anticlock(index, size))
		anticlockwise(a, b, index);
	else
		clockwise(a, b, index, size);
}

int	indexposition(t_stack **a, int i)
{
	t_stack	*current;
	int		index;

	index = 1;
	while (current && current->p_index != i)
	{
		current = current->next;
		index++;
	}
	return (index);
}

void	ft_rotate_push(t_stack **a, t_stack **b, int len)
{
	int		i;
	int		findex;
	int		sindex;
	int		size;
	t_stack	*current;

	i = 1;
	while (i < len - 2)
	{
		current = *a;
		size = ft_lstsize(current);
		findex = indexposition(a, i);
		sindex = indexposition(a, i + 1);
		rotatestack(a, b, findex, size);
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
