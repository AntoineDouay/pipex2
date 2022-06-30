/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:48:49 by adouay            #+#    #+#             */
/*   Updated: 2022/06/30 18:53:51 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(t_pipex *pipex, char **av)
{
	int	fd;
	char	*line;

	fd = open ("here_doc_tmp.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		return ; // ERROR
	line = NULL;
	while (1)
	{
		write (0, "here_doc>", 9);
		line = get_next_line(0);
		if (line == NULL)
			return ; // ERROR
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
			break ;
		write(fd, &line, ft_strlen(line));
		free (line);
	}
	free (line);
	close(fd);
	pipex->infile_fd = open("here_doc_tmp.txt", O_RDONLY);
}