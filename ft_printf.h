/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseminat <tseminat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 02:15:25 by tseminat          #+#    #+#             */
/*   Updated: 2020/01/30 18:41:33 by tseminat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct 	s_inf
{
	char		*str;
	int			index;
	int			prec;

}				t_inf;

int flag_string(va_list va, t_inf inf);
int flag_char(va_list va, t_inf inf);

#endif