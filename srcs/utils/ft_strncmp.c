/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:25:18 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/04/19 16:19:51 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') && i < n - 1)
		i++;
	if (n == 0)
		return (0);
	if (s1[i] && !s2[i])
	{
		if (s1[i] == '\n')
			return (0);
		return ((unsigned char) s1[i + 1] - (unsigned char) s2[i]);
	}
	if (!s1[i] && s2[i])
		return ((unsigned char) s1[i] - (unsigned char) s2[i + 1]);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
