// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function 
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);

#include <stddef.h>
#include <stdbool.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	int j = 0;
	size_t byte = 0;
	bool same = false;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				same = true;
				byte++;
				break;
			}
			j++;
		}
		if (same == false)
			break;
		same = false;
		i++;
	}
	return (byte);
}

//------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	printf("%ld\n", ft_strspn(av[1], av[2]));
	printf("%ld", strspn(av[1], av[2]));
}