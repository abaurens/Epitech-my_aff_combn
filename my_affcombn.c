/*
** my_print_combn.c for combn in /home/bauren_a/Work/Piscine/CPool_Day03
**
** Made by Arthur
** Login <bauren_a@epitech.net>
**
** Started on Wed Oct  5 11:59:44 2016 Arthur
** Last update Wed Oct  5 22:37:25 2016 Arthur
*/

int	get_num_len(int nb)
{
  int	i;

  i = 0;
  while (nb > 0)
    {
      nb /= 10;
      i++;
    }
  return (i);
}

int	gfd(int nb, int n)
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
  long	nbr;
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

void	my_real_aff_combn(int n, int nn, int nb)
{
  int	i;

  i = nb % 10 + 1;
  while (i <= 9)
    {
      if (n - 1 > 0)
	my_real_aff_combn(n - 1, nn, (nb == -1 ? 0 : nb) * 10 + i);
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
}

int	my_print_combn(int n)
{
  if (n <= 0 || n > 10)
    return (-1);
  my_real_aff_combn(n, n, -1);
  return (0);
}
