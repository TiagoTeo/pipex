/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:26:03 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/04/19 17:25:53 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	exec_cmd(t_list *cmds, int in, int out)
{
	char	*path;

	path = get_acess(data()->path_og, cmds->cmd);
	if (!path)
		ft_error(cmds->cmd[0], 0);
	if (fork() == 0)
	{
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		close(in);
		close(out);
		if (execve(path, cmds->cmd, data()->env) == -1)
			ft_error(cmds->cmd[0], 1);
	}
	close(in);
	close(out);
	free(path);
	if (cmds->next)
		exec_cmd(cmds->next, cmds->fd[0], cmds->next->fd[1]);
}

t_list	*get_cmds(int ac, char **av)
{
	t_list	*res;
	t_list	*temp;
	int		i;

	i = 0;
	res = NULL;
	while (++i < ac -1)
	{
		temp = ft_lstnew(ft_split(av[i], 32));
		if (i == 1)
			temp->fd[0] = data()->fd_in;
		else if (i == ac -2)
			temp->fd[1] = data()->fd_out;
		else
			pipe(temp->fd);
		ft_lstadd_back(&res, temp);
	}
	return (res);
}

void	free_cmds(t_list *cmds)
{
	t_list	*temp;

	while (cmds)
	{
		temp = cmds->next;
		if (cmds->cmd)
			ft_free_matrix(&cmds->cmd);
		free(cmds);
		cmds = temp;
	}
}

int	main(int ac, char **av, char **env)
{
	static int		i;

	if (ac >= 5)
	{
		if (!ft_strncmp(av[1], "here_doc", 8))
			ft_here_doc(&ac, &av);
		else
			(data())->fd_out = open(av[ac - 1], O_CREAT | \
			O_TRUNC | O_WRONLY, 0644);
		(data())->fd_in = open(av[1], O_RDONLY | O_CREAT, 0644);
		(data())->env = env;
		(data())->path_og = get_path(data()->env);
		if (data()->fd_in == -1)
			ft_error(av[1], 2);
		if (data()->fd_out == -1)
			ft_error(av[ac - 1], 2);
		(data())->cmds = get_cmds(ac, av);
		exec_cmd(data()->cmds->next, data()->cmds->fd[0], \
		data()->cmds->next->fd[1]);
		while (++i < ac - 2)
			wait(NULL);
		free_cmds(data()->cmds);
		if (!ft_strncmp(av[1], "here_doc", 8))
			ft_free_matrix(&av);
	}
}
