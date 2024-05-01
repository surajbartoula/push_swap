/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highmidlow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:42:58 by sbartoul          #+#    #+#             */
/*   Updated: 2024/05/01 06:47:10 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	anticlock(int low, int mid, int high, int size)
{
	if (((low - 1) + (mid - low) + (high - mid)) <= ((size + 1 - high)
			+ (high - mid) + (mid - low)))
		return (1);
	return (0);
}

int	lowvalue(int first, int second, int third)
{
	int	low;

	low = first;
	if (low > second)
		low = second;
	if (low > third)
		low = third;
	return (low);
}

int	midvalue(int a, int b, int c)
{
	if ((a < b && b < c) || (c < b && b < a))
		return (b);
	else if ((b < a && a < c) || (c < a && a < b))
		return (a);
	else
		return (c);
}

int	highvalue(int first, int second, int third)
{
	int	high;

	high = first;
	if (high < second)
		high = second;
	if (high < third)
		high = third;
	return (high);
}
