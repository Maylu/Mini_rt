/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:04:56 by gcamara           #+#    #+#             */
/*   Updated: 2025/12/13 15:16:46 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*fill_line(char **stash)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	line = NULL;
	temp = NULL;
	if (!stash || !(*stash) || !(**stash))
		return (NULL);
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if (ft_strchr (*stash, '\n'))
	{
		line = ft_substr(*stash, 0, i + 1);
		temp = ft_substr(*stash, i + 1, ft_strlen(*stash) - (i + 1));
	}
	else
		line = ft_substr(*stash, 0, i);
	free(*stash);
	*stash = temp;
	return (line);
}

char	*set_line(char *buff, char *stash)
{
	char	*tmp;

	if (stash == NULL)
		tmp = ft_substr(buff, 0, ft_strlen(buff));
	else
		tmp = ft_strjoin(stash, buff);
	free(stash);
	return (tmp);
}

char	*line_check(char **stash, char **buff, char **line)
{
	*line = fill_line(stash);
	if (*line == NULL)
		return (free(*stash), *stash = NULL, free(*buff), NULL);
	if (*stash && !(*stash)[0])
	{
		free(*stash);
		*stash = NULL;
	}
	return (free(*buff), *line);
}

char	*get_next_line(int fd)
{
	int			b_count;
	static char	*stash;
	char		*buff;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (free(stash), stash = NULL, NULL);
	b_count = 1;
	while (1)
	{
		if (b_count == 0 || (stash && ft_strchr(stash, '\n')))
			return (line_check(&stash, &buff, &line));
		b_count = read(fd, buff, BUFFER_SIZE);
		if (b_count < 0)
			return (free(stash), stash = NULL, free(buff), NULL);
		buff[b_count] = '\0';
		stash = set_line(buff, stash);
		if (stash == NULL)
			return (free(stash), stash = NULL, free(buff), NULL);
	}
}
/*
int main(){
	char    *line;
	int     fd;
	int	i;
    
	fd = open("text.txt", O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%d: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
}*/
