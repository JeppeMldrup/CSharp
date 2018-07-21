#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int array[100], temp = 1, i, j;
	srand(time(NULL));

	for(i = 0; i < 100; ++i)
	{
		array[i] = rand()%100;
	}

	while(temp != 0)
	{
		temp = 0;
		for(i = 0; i < 99; ++i)
		{
			if(array[i] > array[i+1])
			{
			temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
			continue;
			}
 		}
 	}

	for(i = 0; i < 100; ++i)
	{
		printf("%d\n", array[i]);
	}

	printf("Press ENTER key to Continue... ");
	getchar();

	return 0;
}

/* pseudocode
array = random
while array is not sorted
	for i -> 99
		if array[i] > array[i+1])
		swap array[i] and array[i+1]
*/
