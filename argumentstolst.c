/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argumentstolst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:00:29 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/26 05:55:32 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	returnlsta(int argc, char *argv[], t_stack **a)
{
	int		numb;
	int		i;
	char	**string;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		exit(0);
	else if (argc == 2)
	{
		string = ft_split(argv[1], 32);
		i = -1;
		while (string[++i])
		{
			numb = ft_atoi(argv[i]);
			ft_lstadd_back(a, ft_lstnew(numb));
		}
		ft_printf("%d\n", ft_lstsize(*a));
		ft_free(string);
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
