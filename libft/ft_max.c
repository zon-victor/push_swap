int		ft_max(int *array, int len)
{
	int		i;
	int		max;

	i = 0;
	max = array[i];
	while (i < len)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}
