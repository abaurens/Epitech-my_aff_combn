void my_putchar(char c)
{
	write(1, &c, 1);
}

int	get_num_len(int nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int gfd(int nb, int n)
{
	int	i;

	i = get_num_len(nb);
	if (i < n)
		return (0);
	while (nb / 10 > 0)
		nb /= 10;
	return (nb);
}

int	spec_put_nbr(int nb, int n)
{
	long nbr;
	int	i;

	nbr = nb;
	i = get_num_len(nb);
	while (n > 1 && i < n)
	{
		my_putchar('0');
		i++;
	}
	if (nbr / 10 > 0)
		spec_put_nbr(nbr / 10, -1);
	my_putchar(nbr % 10 + '0');
	return (nb);
}

void		my_real_aff_comb_n(int n, int nn, int nb)
{
	int i;

	i = nb % 10 + 1;
	while (i <= 9)
	{
		if (n - 1 > 0)
			my_real_aff_comb_n(n - 1, nn, (nb == -1 ? 0 : nb) * 10 + i);
		else
		{
			if (nn > 1)
				spec_put_nbr(nb, nn - 1);
			my_putchar(i + '0');
			 if (nn != 1 && gfd(nb, nn - 1) != (10 - nn) || (nn == 1 && i != 9))
			 {
				my_putchar(',');
				my_putchar(' ');
			 }
		}
		i++;
	}
	return (0);
}
int			my_aff_combn(int n)
{
	if (n <= 0 || n > 10)
		return (-1);
	my_real_aff_comb_n(n, n, -1);
	return (0);
}

int	main()
{
	if (my_aff_combn(2) == -1)
		return (1);
	my_putchar('\n');
	return (0);
}
