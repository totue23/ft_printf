
#include "ft_printf.h"

int main(void)
{
	char *s = "Salut";
	char c = 't';
	int d = -14;

 //-->  flags test

	//champs
	printf("|%7s|\n", s);
	printf("|%-7s|\n", s);

	//Precision
	printf("|%.2s|\n", s);

	// Zero
	printf("|%0d|\n", d);



}
