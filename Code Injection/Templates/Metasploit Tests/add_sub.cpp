//Test file to fingerprint
#include <stdio.h>

int add_funct(int a_funct, int b_funct)
{
	return a_funct + b_funct;
}

int sub_funct(int a_funct, int b_funct)
{
	return a_funct - b_funct;
}

void some_print()
{
	printf("We are in the print function.\n");
	printf("Here is another line.\n");
}

int main()
{
	int apple = 1;
	int bananas = 10;
	int cat = bananas + 2;

	char really_long[] = "This string is really long in order to emphasize what sort of information we should be looking for in the data section of our program. This is just some more padding.";
	for(int i = 0; i < 10; i++)
	{
		bananas = add_funct(apple,bananas);
		cat = sub_funct(bananas,apple);
	}

	some_print();

	char another_one[] = "Smaller string to better understand where we are";

	return 0;
}