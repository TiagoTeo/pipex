/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:26:25 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/05/02 12:07:42 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct s_list
{
	char			**cmd;
	int				fd[2];
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	char	**env;
	char	*path_og;
	t_list	*cmds;
}			t_data;

//main
t_data			*data(void);
void			free_cmds(t_list *cmds);

//here_doc
void			ft_here_doc(int *ac, char ***av);

//error
int				ft_error(char *str, int flag);

//path
char			*get_acess(char *big_path, char **cmd);
char			*get_path(char **env);

//utils
char			**ft_split(char const *str, char c);
size_t			ft_strlen(const char *str);
char			*ft_str_add(char *s1, char *s2);
void			ft_free_matrix(char ***m);
char			*ft_strdup(const char *src);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnfind(char *s1, char *s2, int n);

//lst
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(char **content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);

#endif