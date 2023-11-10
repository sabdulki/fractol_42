/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:59:37 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/10 16:42:21 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

size_t	check_d(const char *str)
{
	size_t	i;
	size_t	dot_count;
	size_t	minus_count;

	i = 0;
	dot_count = 0;
	minus_count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	if ((minus_count > 0 && str[0] != '-' ) || \
		(dot_count > 0 && (str[i - 1] == '.' || str[0] == '.')) || \
		(dot_count > 1 || minus_count > 1) || \
		(minus_count && str[1] == '0' && str[2] != '.') || \
		(str[0] == '0' && str[1] != '.'))
		return (0);
	return (1);
}

size_t	is_d(const char *str)
{
	size_t	i;
	size_t	check;

	check = check_d(str);
	if (check == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '.')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	if (n == 0)
		return (0);
	while (i < n || (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (n != i)
		return (0);
	return (1);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	decimal_scale;
	int		minus;

	integer_part = 0;
	fractional_part = 0;
	minus = +1;
	decimal_scale = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			minus *= -1;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		decimal_scale /= 10;
		fractional_part = fractional_part + (*s++ - 48) * decimal_scale;
	}
	return ((integer_part + fractional_part) * minus);
}
