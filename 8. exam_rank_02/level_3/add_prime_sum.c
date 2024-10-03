// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	num = 0;

	while (*s)
		num = num * 10 + *s++ - '0';
	return (num);
}

int	is_prime(int num)
{
	int	i = 2;
	if (num <= 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char num = (n % 10) + '0';
	write(1, &num, 1);
}

int main(int argc, char **argv)
{
	if (argc != 2 || ft_atoi(argv[1]) < 0)
		write(1, "0", 1);
	if (argc == 2)
	{
		int	nbr = ft_atoi(argv[1]);
		int	sum = 0;
		while (nbr > 0)
		{
			if (is_prime(nbr))
				sum += nbr;
			nbr--;
		}
		ft_putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}