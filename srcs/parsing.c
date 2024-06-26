/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:52:58 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/06 15:35:49 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit(int fd, char *s, char *all)
{
	write (2, "invalid map\n", 12);
	close (fd);
	free(s);
	free(all);
	exit(1);
}

int	check_elem(char **strs, char *s)
{
	if (ft_count(strs, 'P') != 1)
		error_crash(strs, s, "error player\n", 0);
	else if (ft_count(strs, 'E') != 1)
		error_crash(strs, s, "error exit\n", 0);
	else if (ft_count(strs, 'C') < 1)
		error_crash(strs, s, "error collictibl\n", 0);
	return (0);
}

int	ft_check(char *s)
{
	size_t	len;

	len = ft_strlen (s) - 1;
	if (s[0] != '1')
		return (0);
	else if (s[len] == '\n' && s[len - 1] != '1')
		return (0);
	else if (s[len] != '\n' && s[len] != '1')
		return (0);
	else if (!(ft_strspn(s, "01PCE\n") == len + 1))
		return (0);
	return (1);
}

char	*read_check(char *name)
{
	int		fd;
	char	*s;
	char	*all;

	all = NULL;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		(ft_putendl_fd("Error opening the file", 2), exit(1));
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		if (!ft_check(s))
			ft_exit(fd, s, all);
		all = ft_strjoin(all, s);
		if (!all)
			ft_exit(fd, s, all);
		free(s);
	}
	if (!all || all[ft_strlen(all) - 1] == '\n')
		ft_exit(fd, s, all);
	close(fd);
	return (all);
}
