// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// void sort_int_tab(int *tab, unsigned int size);

// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.

// Doubles must be preserved.

// Input is always coherent.

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j = 0;
	int	aux;
	while (i < size)
	{
		j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                aux = tab[i];
		        tab[i] = tab[j];
		        tab[j] = aux;
            }
            j++;
        }
        i++;
	}
}