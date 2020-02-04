/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseminat <tseminat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:14:39 by tseminat          #+#    #+#             */
/*   Updated: 2020/01/30 18:58:23 by tseminat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int format_string(va_list va, t_inf inf)
{
	int len;
	char *str;

	len = 0;
	str = va_arg(va, char *);
	printf("va = %s\n", str);
	if (!inf.prec)
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	while (len < inf.prec)
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int format_char(va_list va, t_inf inf)
{
	int c;

	c = va_arg(va, int);
	write(1, &c, 1);
	return (1);
}

char *fun2()
{
	return ("test2");
}

char *fun3()
{
	return ("test3");
}
