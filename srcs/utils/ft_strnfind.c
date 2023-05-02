/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:48:05 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/04/18 12:48:40 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strnfind(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!n || !s1 || !s2)
		return (-1);
	while (s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else if (j && s1[i])
			j = 0;
		if (j == n)
			return (1);
		i++;
	}
	return (0);
}
