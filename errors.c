/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:36:28 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/19 15:16:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_printf("Error: %s\n", str);
	exit(0);
}

void	ft_free(char **argv)
{
	char	*str;

	if (!argv)
		return ;
	while (*argv)
	{
		str = *argv;
		argv++;
		free(str);
	}
	*argv = NULL;
	free(argv);
}

int	duplicate(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->num == temp->num)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}
