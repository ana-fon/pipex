/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:33:33 by mefische          #+#    #+#             */
/*   Updated: 2026/01/14 13:20:20 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	if (!s)
		return (0);
	while (s[l])
	{
		l++;
	}
	return (l);
}

/*int	main()
{
	printf("%zu", ft_strlen("Hello"));
}*/