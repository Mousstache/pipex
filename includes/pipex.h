/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:48:29 by motroian          #+#    #+#             */
/*   Updated: 2023/03/30 14:52:08 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_data
{
	char	**path;
	char	**env;
	char	**cmd;
	int		nbcmd;
	int		outfile;
	int		infile;
	int		prev_pipe;
	int		here_doc;
	int		*pid;
	int		fd[2];
}	t_data;

void	free_all(char **tab);
char	*ft_gnl(int fd, int boolean);
void	error_free_exit(t_data *data);
void	ft_printtab(char **tab);
char	**path_finder(char **env);
void	dup_close(int fd, int fd2);
int		here_doc(t_data *data, char *delim);
void	message(t_data *data);
void	waiting(t_data *data);
void	ft_close(t_data *data);
void	last_cmd(t_data *data, char **av);

#endif