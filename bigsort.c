/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:58:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/22 07:09:34 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bigsort(t_stack **a)
{
	int	i;
	int	len;
	int	index;

	i = 0;
	index = 0;
	len = ft_lstsize(&a);
	while (i < len)
	{
		if (i == len - 3)
			ft_tiny_sort(&a);
		while ((*a)->p_index != i)
		{
			(*a) = (*a)->next;
			index++;
		}
	}
}
