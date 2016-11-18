/* This program solves quadratic or cubic equations with three roots */

#include <stdio.h>
#include <stdlib.h>

void quadratic(int b, int c);

int cubic(int a, int b, int c, int d);

int main()
{
	int choice, a, b, c, d;

	printf("Hello master! Please enter '1' for \"Trinomial solver\", "
		   "or '2' for \"Third degree equation solver\": \n");

	scanf("%d", &choice);

	while (choice != 1 && choice != 2)	// check valid input
	{
		printf("No, this was not an option my lord, please choose again wisely:\n");
		scanf("%d", &choice);
	}

	if (choice == 1)	// Go to quadratic solver
	{
		printf("You choose to solve a trinomial. Please enter the 'b' and 'c' coefficients:\n");
		scanf("%d%d", &b, &c);
		quadratic(b, c);
	}

	if (choice == 2)	// Go to cubic solver
	{
		printf("You choose to solve a \"Third degree equation\". "
			"Please enter the coefficients - 'a', 'b', 'c' and 'd'\n");
		scanf("%d%d%d%d", &a, &b, &c, &d);
		return cubic(a, b, c, d);
	}

	return 0;
}


void quadratic(int b, int c)
{
	int x, x1, x2, root_count = 0;
	
	for (x = -1000; x <= 1000 && root_count < 2; ++x)
		if (x*x+b*x+c == 0)	// Iterate numbers until a solution is found
		{
			if (root_count > 0)	// If we find another root, we store
				x2 = x1;		// the first one in x2
							
			x1 = x;
			++root_count;
		}

	switch(root_count)
	{
		case 2:
			printf("Trinomial is solved! The roots are: (%d) and (%d)\n", x2, x1);
			return;
		case 1:
			printf("Trinomial is solved! There is only one root: (%d)\n", x1);
			return;
		case 0:
			printf("No solutions were found!\n");
			return;
	}
}


int cubic(int a, int b, int c, int d)
{
	int x, x1, x2, x3, root_count = 0;

	for (x = -1000; x <= 1000 && root_count < 3; ++x)
		if (x*x*x*a + x*x*b + x*c + d == 0)	// Iterate numbers until solution is found
		{
			if (root_count > 1)	// Store x2 in x3 after
				x3 = x2;		// third root is found
							
			if (root_count > 0)	// Store x1 in x2 after second
				x2 = x1;		// and third roots are found

			x1 = x;			
			++root_count;
		}

	if (root_count == 3)
	{
		printf("Equation solved! The roots are: (%d),(%d) and (%d)\n", x3, x2, x1);
		return 0;
	}
	else
	{
		printf("No solutions were found!\n");
		return 1;
	}


}