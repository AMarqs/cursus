// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0100  0001
//      ||
//      \/
//  1000  0010

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 7;
	unsigned char res = 0;
	while (i >= 0)
	{
		if ((octet & (1 << i)))
			res = res | (1 << (7 - i));
		i--;
	}
	return (res);
}

//------------------------------------------------------

#include <stdio.h>

int main(int ac, char **av)
{
	printf("%d", (int)reverse_bits(av[1][0]));
}