/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:51:49 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/04/18 16:26:41 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_str_add(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*res;

	i = 0;
	if (!s2)
		return (NULL);
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
	res = (char *)malloc(s1_len + s2_len + 1);
	if (!res)
		return (NULL);
	while (i < s1_len || i < s2_len)
	{
		if (i < s1_len)
			res[i] = s1[i];
		if (i < s2_len)
			res[s1_len + i] = s2[i];
		i++;
	}
	res[s1_len + s2_len] = 0;
	return (res);
}
