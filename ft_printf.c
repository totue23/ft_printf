/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseminat <tseminat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 02:11:00 by tseminat          #+#    #+#             */
/*   Updated: 2020/01/30 19:13:14 by tseminat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int check_format(va_list va, t_inf inf,  char c)
{
	char *format = "cs";
	int (*func[])(va_list va, t_inf inf) = {&format_char, &format_string};
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == c)
			return ((*func[i])(va, inf));
		i++;
	}
	return (0);
}

int check_flag(va_list va, t_inf inf, char c)
{
	char *flags = "-0.*";
	int (*func[])(va_list va, t_inf inf) = {&format_char, &format_string};
	int i;
	char *str;

	str = inf.str;
	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return ((*func[i])(va, inf));
		i++;
	}
	return (0);
}

int	ft_parse(va_list va, t_inf inf)
{
	char *str;
	int i;
	int len;

	str = inf.str;
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			inf.index = i;
			len += check_flag(va, inf, str[i]);
			len += check_format(va, inf, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	t_inf		inf;
	va_list 	va;
	int total_len;
	
	va_start(va, format);
	inf.str = ft_strdup(format);
	inf.index = 0;
	inf.prec = 0;
	total_len = ft_parse(va, inf);
	va_end(va);
	return (total_len);
}

int main(int ac, char **av)
{
	//printf("%d\n", ft_printf("test \n|%c|\n|%s", 'a', "fonctionne"));

	int i = 42;
	unsigned int  ui = 21;

	printf("%0d\n", i);
	printf("%0i\n", i);
	printf("%03u\n", ui);
	printf("%p\n", &i);

}
