// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int num) 
{
	if(num == -2147483648)
		return("-2147483648\0");
	int len = 0;
	if (num <= 0)
		len++;
	int n = num;
	while (n) 
	{
		n /= 10;
		len++;
	}
	char *result = malloc(sizeof(char) * (len + 1));
	if (result == NULL) 
		return NULL;
	result[len] = '\0';
	if (num == 0)
		result[0] = '0';

	else if (num < 0) 
	{
		result[0] = '-';
		num = -num;
	}
	while (num) 
	{
		len--;
		result[len] = num % 10 + '0';
		num /= 10;
	}
	return result;
}