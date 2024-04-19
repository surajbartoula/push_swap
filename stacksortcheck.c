/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksortcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:19:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/19 20:09:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(int *arr)
{
	int	len;
	int	i;

	len = sizeof(arr) / sizeof(arr[0]);
	i = -1;
	while (++i < (len - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}
