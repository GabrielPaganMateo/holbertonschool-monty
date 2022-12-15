/*
 *
 */
int check_arg(char *argument)
{
	int i = 0, j = 0;

	while (argument[i] != '\0')
	{
		if (argument[i] >= 48 && argument[i] <= 57 && argument[i] != '-')
		{
			j = i + 1;
			while (argument[j] != '\0')
			{
				if (argument[j] < 48 || argument[j] > 57)
				{
					return (1);
				}
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}
