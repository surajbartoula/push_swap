/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argumentstolst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:00:29 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/19 14:52:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	returnlsta(int argc, char *argv[], t_stack **a)
{
	int		numb;
	int		i;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		exit(0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = -1;
		while (argv[++i] != 0)
		{
			numb = ft_atoi(argv[i]);
			ft_lstadd_back(a, ft_lstnew(numb));
		}
		ft_free(argv);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			numb = ft_atoi(argv[i]);
			ft_lstadd_back(a, ft_lstnew(numb));
		}
	}
}
