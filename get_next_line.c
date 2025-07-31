/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:35:20 by ycinarog          #+#    #+#             */
/*   Updated: 2025/07/31 14:46:41 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char *copy_free(char *stash, char *copy)
{
	char *temp;

	temp = ft_strjoin(stash, copy);
	free(stash);
	return (temp);
}

char *dostum(int fd, char *stash)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	if (!stash)
	{
		stash = ft_strdup("");
		return (stash);
	}
	return(NULL);
}

char *tostum(char *stash, char	*line)
{
	if (stash && stash[0] != '\0')
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
		return (line);
	}
	free(stash);
	stash = NULL;
	return (NULL);
}

char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	static char *stash = NULL; // kullanımı kontrol et.
	char	*line;
	char	*remainder;
	ssize_t	bytes_read;
	bytes_read = read(fd, buffer, BUFFER_SIZE);

	stash = dostum(fd, stash);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		stash = copy_free(stash, buffer);

		if (ft_strchr(stash) > -1)
		{
			remainder = ft_substr(stash, ft_strchr(stash) + 1, ft_strlen(stash) - ft_strchr(stash)); //kalan
			line = ft_substr(stash, 0, ft_strchr(stash) + 1); //döndürülmesi gereken kısım
			stash = copy_free(stash, remainder);
			return (line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return tostum(stash, line);
}
*/

char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	static char *stash = NULL; // kullanımı kontrol et.
	char	*temp;
	char	*line;
	char	*remainder;
	ssize_t	bytes_read;
	bytes_read = read(fd, buffer, BUFFER_SIZE);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	if (!stash)
	stash = ft_strdup("");

	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;

		if (ft_strchr(stash) > -1) // stash 6
		{
			remainder = ft_substr(stash, ft_strchr(stash) + 1, ft_strlen(stash) - ft_strchr(stash)); //kalan
			line = ft_substr(stash, 0, ft_strchr(stash) + 1); //döndürülmesi gereken kısım
			free(stash); //stashi sıfırla
			stash = remainder; // newlinedan sonrasını stashe geri ver
			return (line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (stash && stash[0] != '\0')
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
		return (line);
	}
	free(stash);
	stash = NULL;
	return (NULL);
}



/* stash 12345X789() size:10 -> stash 678



char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	char *stash = ft_strdup(""); // kullanımı kontrol et.
	char *new_stash = ft_strdup("");
	ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	stash = ft_strjoin(stash, buffer); 
	
	while (bytes_read > 0) //newline yoksa ve okunacak varsa bura
	{
		if (ft_strchr(stash) > -1) //newline bulunuyorsa yapıyorum bu zaten sonlandırıcı
		{
			//printf("%s",ft_substr(stash, 0, ft_strchr(stash)));
			new_stash = ft_substr(stash, (ft_strchr(stash) + 1), (ft_strlen(stash) - ft_strchr(stash)));
			free(stash);
			stash = ft_strdup(new_stash);
			free(new_stash);
			
			return (stash);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	
	return (stash);
}

*/