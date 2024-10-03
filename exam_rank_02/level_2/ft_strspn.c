// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function 
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	int j = 0;
	size_t byte = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				byte++;
			j++;
		}
		i++;
	}
	return (byte);
}