/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:11:44 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/17 13:37:11 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		num;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		ft_printf("Please provide the right extension ./push_swap arguments\n");
		return (0);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (argv[i] != 0)
		{
			num = ft_atoi(argv[i]);
			ft_lstadd_back(&a, ft_lstnew(num));
			i++;
		}
	}
}
