#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265359  //define is always written with #define first then a name for it and then the constant value it has
//max define still needed

int main()
{
	printf("\n This Programm is to fill an array with random numbers and then Output the 4highest value. "); // user understanding

	// variables
	int numbercount = 0, numbercount2;
	int temp2 = 0;

	// input1
	printf("\n Amount of Numbers: ");
	scanf("%d", &numbercount);

	int array[numbercount];
	srand((unsigned)time(NULL));

	float *p1 =(float* )malloc(numbercount * sizeof(float)); //dont think i really would need the (float* )

	for (int i = 0; numbercount > i; i++)
	{
		p1[i] = (rand() % 100)* PI;
		printf("\n%d.= %.6f ", i + 1, p1[i]);
	}
	
	
		// input2
		printf("\n\n   Do you want to enter more numbers? \n   1= Yes \n   2= No\n   :");
		scanf("%d", &temp2);

		while (temp2 == 1) {
		
			printf("\n   Amount of Numbers: ");
			scanf("%d", &numbercount2);

			p1 = realloc(p1, numbercount2 * sizeof(float)); // numbercount is the space that gets added

			for (int i = numbercount; numbercount + numbercount2 > i; i++) {
				p1[i] = (rand() % 100)* PI; // p1[i] stands for which position in the array should be used for it
				printf("\n%d.= %.6f ", numbercount2 + i - 1, p1[i]);
			}

			printf("\n\n   Do you want to enter more numbers? \n   1= Yes \n   2= No\n   :");
			scanf("%d", &temp2);
			numbercount=numbercount+numbercount2;
		}
	
	free(p1);
	return 0;
}