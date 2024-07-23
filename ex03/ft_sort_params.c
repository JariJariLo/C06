/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crjarill <crjarill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:34:56 by crjarill          #+#    #+#             */
/*   Updated: 2024/07/23 23:39:58 by crjarill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Optimized implementation of Bubble sort
#include <stdbool.h>
#include <stdio.h>

void	ft_swap(char **a, char **b);
int		ft_strcmp(char *s1, char *s2);
void	ft_sort_int_tab(char **argv, int size);

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else if (s1[i] > s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	ft_sort_int_tab(char **argv, int size)
{
	int	swapped;
	int	i;
	int	j;

	i = 0;
	swapped = 1;
	while (i < size - 1 && swapped)
	{
		j = 1;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				ft_swap(&argv[j], &argv[j + 1]);
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}
/*

argv[0][i] = H O L A
argv[1][i] = M U N D O
*/

// Driver program to test above functions
int	main(int argc, char **argv)
{
	int i;
	if (argc == 1)
	{
		return (0);
	}

	// llamada al sort

	// mostrar todo el array que esta ordenado
	ft_sort_int_tab(argv, argc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}

	return (0);
}