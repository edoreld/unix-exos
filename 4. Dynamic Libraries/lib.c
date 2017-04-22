#include <stdio.h>
#include <stdlib.h>

double sum(double a, double b) {
	return a + b;
}

double subtract(double a, double b) {
	return a - b;
}

double multiply(double a, double b) {
	return a * b;
}

double divide(double a, double b) {
	if (b == 0) {
		printf("ERROR: Division by zero\n");
		exit(-1);
	}
	return a / b;
}

void getBase(long int number_to_convert, int base) {
	
	char base_digits[16] =
	{'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	int converted_number[64];
	int next_digit, index=0;

	while (number_to_convert != 0)
	{
		converted_number[index] = number_to_convert % base;
		number_to_convert = number_to_convert / base;
		++index;
	}

	--index;

	for(  ; index>=0; index--) 
	{
		printf("%c", base_digits[converted_number[index]]);
	}
	printf("\n");   
}

int getModulus(int a, int b) {
	return a % b;
}

double getPercent(double a) {
	return a / 100;
}