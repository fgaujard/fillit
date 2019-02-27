static int		count_block(char *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetri[i] != '\0')
	{
		if ((tetri[i] != '.') || (tetri[i] != '#'))
			return (0);
		if (tetri[i] == '.')
			i++;
		else if (tetri[i] == '#')
		{
			j++;
			i++;
		}
	}
	if (j > 4)
		j = 0;
	return (j);
}

static int		verif_forms(char *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetri[i] != '\0')
	{
		while (tetri[i] == '.')
			i++;
		if (tetri[i] == '#')
		{
			if (tetri[i+1] == '#')
				j++;
			if (tetri[i+5] == '#')
				j++;
			if (tetri[i+
		}
	}
}
