/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:38:44 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/04/19 16:17:36 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	change_av(int ac, char ***av)
{
	char	**res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	res = malloc(sizeof(char *) * (ac + 1));
	if (!res)
		return ;
	res[ac] = NULL;
	while (av[0][j + i])
	{
		if (j == 2)
			i++;
		res[j] = ft_strdup(av[0][j + i]);
		j++;
	}
	*av = res;
}

void	ft_here_doc_2(int *ac, char ***av, int *fd, char **temp)
{
	(data())->fd_out = open(av[0][*ac - 1], O_CREAT | \
	O_WRONLY | O_APPEND, 0644);
	if (data()->fd_out == -1)
		ft_error(av[0][*ac - 1], 2);
	*fd = open("here_doc", O_CREAT | O_TRUNC | O_RDWR, 0644);
	*temp = NULL;
}

void	ft_here_doc(int *ac, char ***av)
{
	char	buff[2];
	char	*temp;
	char	*temp2;
	int		fd;

	ft_here_doc_2(ac, av, &fd, &temp);
	while (!buff[0] || ft_strncmp(temp, av[0][2], \
	((int)ft_strlen(av[0][2]) + 1)))
	{
		buff[0] = 0;
		write(fd, temp, ft_strlen(temp));
		free(temp);
		temp = NULL;
		while (buff[0] != '\n')
		{
			read(STDIN_FILENO, buff, 1);
			temp2 = temp;
			temp = ft_str_add(temp, buff);
			free(temp2);
		}
	}
	close(fd);
	free(temp);
	*ac -= 1;
	change_av(*ac, av);
}
