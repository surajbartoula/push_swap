/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/03 18:37:37 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	anticlockwise(t_stack **a, t_stack **b, int index)
{
	t_stack	*cura;
	t_stack	*curb;

	curb = *b;
	if (index > 0)
		ft_ra(a, index);
	cura = *a;
	if (curb && cura->num < curb->num && (ft_lstsize(*b) == 1))
	{
		ft_pb(a, b, 1);
		ft_sb(b, 1);
	}
	else if (curb && ft_lstsize(*b) > 1 && cura->num < curb->num
		&& cura->num > curb->next->num)
	{
		ft_pb(a, b, 1);
		ft_sb(b, 1);
	}
	else if (curb && ft_lstsize(*b) > 1 && cura->num < curb->num
		&& cura->num < curb->next->num)
	{
		ft_pb(a, b, 1);
		ft_sb(b, 1);
		ft_pa(a, b, 1);
		ft_sb(b, 1);
		ft_pb(a, b, 1);
	}
	else
		ft_pb(a, b, 1);
}

void	clockwise(t_stack **a, t_stack **b, int index)
{
	t_stack	*cura;
	t_stack	*curb;

	curb = *b;
	ft_rra(a, index);
	cura = *a;
	if (curb && cura->num < curb->num && (ft_lstsize(*b) == 1))
	{
		ft_pb(a, b, 1);
		ft_sb(b, 1);
	}
	else if (curb && ft_lstsize(*b) > 1 && cura->num < curb->num
		&& cura->num > curb->next->num)
	{
		ft_pb(a, b, 1);
		ft_sb(b, 1);
	}
	else if (curb && ft_lstsize(*b) > 1 && cura->num < curb->num
		&& cura->num < curb->next->num)
	{
		ft_pb(a, b, 1);
		ft_sb(b, 1);
		ft_pa(a, b, 1);
		ft_sb(b, 1);
		ft_pb(a, b, 1);
	}
	else
		ft_pb(a, b, 1);
}

int	ipos(t_stack **a, int i)
{
	t_stack	*current;
	int		index;

	index = 1;
	current = *a;
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

	while (i < len - 3)
	{
		cur = *a;
		high = highvalue(ipos(a, i), ipos(a, i + 1), ipos(a, i + 2));
		mid = midvalue(ipos(a, i), ipos(a, i + 1), ipos(a, i + 2));
		low = lowvalue(ipos(a, i), ipos(a, i + 1), ipos(a, i + 2));
		if (anticlock(low, mid, high, ft_lstsize(cur)) == 1)
		{
			anticlockwise(a, b, low - 1);
			anticlockwise(a, b, mid - low - 1);
			anticlockwise(a, b, high - mid - 1);
		}
		else
		{
			clockwise(a, b, ft_lstsize(cur) + 1 - high);
			clockwise(a, b, high - mid);
			clockwise(a, b, mid - low);
		}
		i += 3;
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
	else if (len >= 6 && (((len - 3) % 3 == 1) || ((len - 3) % 3 == 2)))
	{
		ft_rotate_push(a, b, len, i);
		size = ft_lstsize(*a);
		ft_rp_till6(a, b, size);
	}
	else
		ft_rp_till6(a, b, len);
	if (ft_lstsize(*a) == 3)
		ft_tiny_sort(a);
	ft_pa(a, b, len - 3);
}
