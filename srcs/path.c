/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:54:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/04/19 16:20:14 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	while (env[j])
	{
		i = 0;
		while (env[j] && env[j][i])
		{
			if (!i && env[j][i] == 'P' && env[j][i + 1] == 'A' && \
			env[j][i + 2] == 'T' && env[j][i + 3] == 'H')
			{
				res = &env[j][i + 5];
				return (res);
			}
			i++;
		}
		j++;
	}
	return (NULL);
}

char	*get_acess(char *big_path, char **cmd)
{
	char	*res;
	char	**matrix;
	char	*temp;
	int		i;

	i = 0;
	if (access(cmd[0], X_OK) == 0)
		return (ft_strdup(cmd[0]));
	matrix = ft_split(big_path, ':');
	res = ft_str_add("/", cmd[0]);
	while (matrix[i])
	{
		temp = ft_str_add(matrix[i], res);
		if (access(temp, X_OK) == 0)
		{
			free(res);
			res = temp;
			break ;
		}
		free (temp);
		i++;
	}
	ft_free_matrix(&matrix);
	return (res);
}
