/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexsorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:08:36 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/25 07:59:24 by sbartoul         ###   ########.fr       */
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
		ft_quicksort(arr, low, partindex - 1);
		ft_quicksort(arr, partindex + 1, high);
	}
}

void	fill_a_index(t_stack **a, int *sortedarray, int len)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *a;
	while (i < len && current != NULL)
	{
		while ((*a)->next)
		{
			if (sortedarray[i] == (*a)->num)
			{
				(*a)->p_index = i;
				(*a)->next;
				break ;
			}
			*a = (*a)->next;
		}
		i++;
	}
}

int	*getarray(t_stack **a)
{
	t_stack	*temp;
	int		*sortedarray;
	int		i;

	temp = *a;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	sortedarray = malloc(sizeof(int) * i);
	if (!sortedarray)
		return (0);
	i = 0;
	while ((*a)->next)
	{
		*a = (*a)->next;
		sortedarray[i] = (*a)->num;
		i++;
	}
	return (sortedarray);
}

void	fill_postion_index(t_stack **a)
{
	int		*sortedarray;
	int		i;
	int		len;

	i = 0;
	sortedarray = getarray(a);
	len = sizeof(sortedarray) / sizeof(sortedarray[0]);
	if (stack_sorted(sortedarray))
	{
		ft_free_stack(a);
		free(sortedarray);
		exit(0);
	}
	else
		ft_quicksort(sortedarray, 0, i);
	fill_a_index(a, sortedarray, len);
	free(sortedarray);
}
