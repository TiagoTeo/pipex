/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:25:21 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/04/19 16:17:25 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char *str, int flag)
{
	if (!flag)
		write(STDERR_FILENO, "permission denied:\n", 19);
	else if (flag == 1)
	{
		write(STDERR_FILENO, "command not found: ", 20);
		write(STDERR_FILENO, str, ft_strlen(str));
		write(STDERR_FILENO, "\n", 1);
	}
	else
		perror(str);
	free_cmds(data()->cmds);
	exit(1);
}
