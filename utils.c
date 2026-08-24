/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:09:25 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/20 18:32:59 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_sign(const char *nptr, int *i, int *negative)
{
	*negative = 1;
	*i = 0;
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || (nptr[*i] == 32))
		(*i)++;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			(*negative) = -1;
		(*i)++;
	}
	if (*negative > 0)
		return (1);
	return (*negative);
}

float	ft_atof(const char *nptr)
{
	int		i;
	int		negative;
	double	result;
	double	decimal;

	result = 0.0;
	decimal = 0.1;
	negative = parse_sign(nptr, &i, &negative);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '.')
	{
		i++;
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			result = result + (nptr[i] - '0') * decimal;
			decimal = decimal / 10;
			i++;
		}
	}
	return ((float)result * negative);
}