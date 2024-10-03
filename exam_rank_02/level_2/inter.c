// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <unistd.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	char aux[28];
	int num = 0;
	bool same;
	same = false;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					aux[num] = argv[1][i];
					num++;
				}
				j++;
			}
			i++;
		}
		write(1, &aux[0], 1);
		i = 1;
		while (aux[i])
		{
			j = i - 1;
			while (j >= 0)
			{
				if (aux[j] == aux[i])
					same = true;
				j--;
			}
			if (!same)
				write(1, &aux[i], 1);
			same = false;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}