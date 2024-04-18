/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexsorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:08:36 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/18 16:46:26 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (arr[i] <= pivot && i <= high - 1)
			i++;
		while (arr[j] > pivot && j >= low + 1)
			j--;
		if (i < j)
			ft_swap(&arr[i], &arr[j]);
	}
	ft_swap(&arr[low], &arr[j]);
	return (j);
}

void	ft_quicksort(int *arr, int low, int high)
{
	int	partindex;

	if (low < high)
	{
		partindex = partition(arr, low, high);
	}
}

void	fill_a_index(t_stack **a, int *sortedarray)
{
	int	i;
	int	len;

	i = 0;
	len = sizeof(sortedarray) / sizeof(sortedarray[0]);
	while (i < len)
	{
		while ((*a)->next)
		{
			if (sortedarray[i] == (*a)->num)
			{
				(*a)->position_index = i;
				(*a)->position_index++;
				break ;
			}
			*a = (*a)->next;
		}
		i++;
	}
}

void	fill_postion_index(t_stack **a)
{
	int		*sortedarray;
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *a;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	sortedarray = malloc(sizeof(int) * i);
	if (!sortedarray)
		return ;
	i = 0;
	while ((*a)->next)
	{
		*a = (*a)->next;
		sortedarray[i] = (*a)->num;
		i++;
	}
	ft_quicksort(sortedarray, 0, i);
	fill_a_index(&a, sortedarray);
	free(sortedarray);
}
