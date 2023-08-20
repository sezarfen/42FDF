#include "fdf.h"

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	free_split(char **split)
{
	int	i;

	i = split_len(split) - 1;
	while (i >= 0)
	{
		free(split[i]);
		split[i] = NULL;
		i--;
	}
	free(split);
	split = NULL;
}

int max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}