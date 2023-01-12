/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:28:50 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/09/17 00:03:48 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "limits.h"

static int	ft_isvalid(char caracter)
{
	if (caracter == '\f')
		return (1);
	if (caracter == '\t')
		return (1);
	if (caracter == '\n')
		return (1);
	if (caracter == '\v')
		return (1);
	if (caracter == '\r')
		return (1);
	if (caracter == ' ')
		return (1);
	return (0);
}

int	ft_atoi_ex(const char *str, int *value)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	while (ft_isvalid(str[i]))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (str[i])
	{	
		if (ft_isdigit((int)*(str + i)) == 0)
			return (0);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	*value = res * neg;
	if ((res * neg) > INT_MAX || (res * neg) < INT_MIN)
		return (0);
	return (1);
}
