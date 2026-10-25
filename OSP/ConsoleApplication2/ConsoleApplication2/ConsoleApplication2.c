// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

float train[][2] = {
		{0,3},
		{1,2},
		{2,4},
		{3,6},
		{4,8},
};

int count = (sizeof(train)/sizeof(train[0]));

float cost(float random_num) {
	float result = 0;

	for (int i = 0; i < count; i++) {
		float x = train[i][0];
		float y = x * random_num;
		float d = y - train[i][1];

		result += d * d;
	}

	result /= count;
	return result;
}

int main(void)
{
	float random_num = (float)(rand()%10000)/1000;
	//printf("Predicted: %f, Real: %f", random_num * train[3][0], train[3][1]);

	//printf("First error: %f", cost(random_num));
	float delta = 0.001;

	for (int i = 0; i < 2000; i++) {
		float dcost = (cost(random_num + delta) - cost(random_num)) / delta;
		float rate = 0.001;
		random_num -= rate * dcost;
		printf("Error: %f\n", cost(random_num));
	}

	float n = 0;
	printf("\nEnter number: ");
	scanf_s("%f", &n);

	printf("Predict: %f", random_num * n);

	return 0;
}
