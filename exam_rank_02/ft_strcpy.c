// Assignment name  : ft_strcpy
// Expected files   : ft_strcpy.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcpy (man strcpy).

// Your function must be declared as follows:
// char    *ft_strcpy(char *s1, char *s2);

#include <unistd.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

//--------------------------------------------------------------------------------

#include <stdio.h>

int main()
{
	char *src = "hola";
	char *dest;
	ft_strcpy(dest, src);
	int i = 0;
	printf("%s", dest);
	// while (dest[i] != '\0')
	// 	write(1, &dest[i++], 1);
	return (0);
}