/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:36:28 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/17 20:10:21 by sbartoul         ###   ########.fr       */
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
