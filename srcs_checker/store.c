/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:52:11 by vmoreau           #+#    #+#             */
/*   Updated: 2021/04/13 17:31:17 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	check_douplicate(long *val_tab, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (val_tab[j] == val_tab[i])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_limits(long *val_tab, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && val_tab[i] <= INT_MAX && val_tab[i] >= INT_MIN)
		i++;
	if (i < len)
		return (-1);
	else
		return (check_douplicate(val_tab, len));
}

static int	is_num(char *av)
{
	size_t i;

	i = 0;
	if (av[i] == '-')
		i++;
	while (ft_isdigit(av[i]))
		i++;
	if (i < ft_strlen(av) || av[0] == '\0')
		return (-1);
	else
		return (0);

}

static int	check_args(char **av)
{
	size_t len;
	long *val_tab;
	size_t i;

	len = 0;
	while (av[len])
		len++;
	val_tab = (long *)malloc(sizeof(long) * (len));
	i = 0;
	while (av[i] && !is_num(av[i]))
	{
		val_tab[i] = atol(av[i]);
		i++;
	}
	if (i < len)
		return (-1);
	else
		return (check_limits(val_tab, len));
}

int			store_val(t_list **a, char **av)
{
	size_t i;
	int *num;

	if (check_args(av))
		return (-1);
	i = 0;
	while (av[i])
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(av[i]);
		ft_lstadd_back(a, ft_lstnew(num));
		i++;
	}
	return (0);
}
