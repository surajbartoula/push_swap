/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:18:36 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/16 20:02:25 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	fill_lst_a(char **argv, t_stack *a)
{
	int		i;
	int		num;

	i = 0;
	while (argv[i] != 0)
	{
		num = ft_atoi(argv[i]);
		if (i == 0)
			a = ft_lstnew(num);
		else
			ft_lstadd_back(&a, ft_lstnew(argv[i]));
		i++;
	}
}