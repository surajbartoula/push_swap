/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/01 07:49:15 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	anticlockwise(t_stack **a, t_stack **b, int index)
{
	t_stack	*currenta;
	t_stack	*currentb;

	currentb = *b;
	ft_ra(a, index - 1);
	currenta = *a;
	if (currenta->num < currentb->num)
	{
		ft_pb(a, b, 1);
		ft_sb(b, 1);
	}
	else
		ft_pb(a, b, 1);
}

void	clockwise(t_stack **a, t_stack **b, int index, int size)
{
	t_stack	*currenta;
	t_stack	*currentb;

	currentb = *b;
	ft_rra(a, (size - index) + 1);
	currenta = *a;
	if (currenta->num < currentb->num)
	{
		ft_pb(a, b, 1);
		ft_sb(b, 1);
	}
	else
		ft_pb(a, b, 1);
}

int	ipos(t_stack **a, int i)
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

void	ft_rotate_push(t_stack **a, t_stack **b, int len, int i)
{
	int		high;
	int		mid;
	int		low;
	t_stack	*cur;

	while (i < len - 2)
	{
		cur = *a;
		high = highvalue(ipos(a, i), ipos(a, i + 1), ipos(a, i + 2));
		mid = midvalue(ipos(a, i), ipos(a, i + 1), ipos(a, i + 2));
		low = lowvalue(ipos(a, i), ipos(a, i + 1), ipos(a, i + 2));
		if (anticlock(low, mid, high, ft_lstsize(cur)))
		{
			anticlockwise(a, b, low);
			anticlockwise(a, b, mid - low);
			anticlockwise(a, b, high - mid);
		}
		else
		{
			clockwise(a, b, ft_lstsize(cur) + 1 - high, ft_lstsize(cur));
			clockwise(a, b, high - mid, ft_lstsize(cur));
			clockwise(a, b, mid - low, ft_lstsize(cur));
		}
		i++;
	}
}

void	ft_bigsort(t_stack **a, t_stack **b)
{
	int	len;
	int	size;
	int	i;

	i = 1;
	len = ft_lstsize(*a);
	if (len >= 6 && ((len - 3) % 3 == 0))
		ft_rotate_push(a, b, len, i);
	else if (len >= 6 && (((len - 3) % 3 == 1) || ((len - 3) % 3 == 1)))
	{
		ft_rotate_push(a, b, len, i);
		size = ft_lstsize(*a);
		ft_rp_till6(a, b, size);
	}
	else
		ft_rp_till6(a, b, len);
	if (len == 3)
		ft_tiny_sort(a);
	ft_pa(a, b, len - 3);
}
