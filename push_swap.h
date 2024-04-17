/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:09:41 by sbartoul          #+#    #+#             */
/*   Updated: 2024/04/17 20:04:44 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "ft_printf/ft_printf.h"

typedef struct push_swap
{
	struct 	push_swap *next;
	struct 	push_swap *prev;
	int		num;
	int		position_index;
}	t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new_lst);
t_stack	*ft_lstnew(int *num);
int	ft_atoi(const char *str);
void	returnlsta(int argc, char *argv[], t_stack **a);

#endif