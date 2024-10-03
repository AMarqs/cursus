// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);

int		isvalid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (base);
	return (-1);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	while (*str <= 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (isvalid(*str, str_base) != -1)
		result = result * str_base + isvalid(*str, str_base);
	return (result * sign);
}

//--------------------------------

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
		
    }
    return (0);
}