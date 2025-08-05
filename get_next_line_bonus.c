/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:35:20 by ycinarog          #+#    #+#             */
/*   Updated: 2025/08/04 16:41:59 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*copy_free(char *stash, char *remainder)
{
	free(stash);
	return (remainder);
}

char	*last(char *stash)
{
	if (!stash || !*stash)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
		return (ft_strdup(stash));
	return (ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1));
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*remainder;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash[fd], '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(stash[fd]), stash[fd] = NULL, NULL);
		buffer[bytes] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	line = last(stash[fd]);
	if (ft_strchr(stash[fd], '\n'))
		remainder = ft_substr(stash[fd], ft_strchr(stash[fd], '\n') - stash[fd] + 1,
				ft_strlen(stash[fd]) - (ft_strchr(stash[fd], '\n') - stash[fd] + 1));
	else
		remainder = NULL;
	stash[fd] = copy_free(stash[fd], remainder);
	return (line);
}
