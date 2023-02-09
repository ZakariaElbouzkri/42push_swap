/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:08:27 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/02/09 23:30:24 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	free_args(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	free_alocated(char **res, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(res[i++]);
	}
	free(res);
	res = NULL;
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	trigger;

	trigger = -1;
	i = 0;
	while (*s)
	{
		if (*s != c && trigger < 0)
		{
			i++;
			trigger = 1;
		}
		else if (*s == c && trigger > 0)
			trigger = -1;
		s++;
	}
	return (i);
}

static int	args_len(char **arr)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (arr[i])
	{
		len += count_words(arr[i], ' ');
		i++;
	}
	return (len);
}

char	**split_args(char **arr)
{
	char	**spl;
	char	**res;
	int		i;
	int		j;
	int		z;

	i = 0;
	z = 0;
	res = malloc(sizeof(char *) * (args_len(arr) + 1));
	if (!res)
		return (NULL);
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], ""))
			return (free_alocated(res, i), NULL);
		spl = ft_split(arr[i], ' ');
		if (!spl)
			return (NULL);
		j = 0;
		while (spl[j])
			res[z++] = ft_strdup(spl[j++]);
		i++;
		free_args(spl);
	}
	return (res[z] = NULL, res);
}
