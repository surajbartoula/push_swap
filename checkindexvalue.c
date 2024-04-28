/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkindexvalue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:57:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/28 10:10:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index_position(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current)
	{
		ft_printf("%d ", current->p_index);
		current = current->next;
	}
	ft_printf("\n");
}
