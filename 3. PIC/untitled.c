// Performs addition, subtraction, multiplication or division depending the input from user

// ./lib.so

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

void *getHandle(char *);
int exitIfError();

int main() {

	char operator;
	double firstDouble,secondDouble;
	int firstInt, secondInt;
	long int firstLongInt;
	void *handle;
	double (* basicOperation)(double, double);
	void (* baseOperation)(long int, int);
	int (* modulusOperation)(int, int);
	double (* percentOperation)(double);

	printf("Enter an operator (+, -, *, /, (m)odulus, (p)ercent, (b)ase): ");
	scanf("%c", &operator);

	if ( operator == 'm') {
		printf("Enter two operands: ");
		scanf("%d %d",&firstInt, &secondInt);	
	} else if ( operator == 'p') {
		printf("Enter an operand: ");
		scanf("%lf", &firstDouble);
	} else if ( operator == 'b') {
		printf("Enter an integer and the base to convert it to (2 to 16): ");
		scanf("%li %i",&firstLongInt, &secondInt);
	} else if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
		printf("Enter two operands: ");
		scanf("%lf %lf",&firstDouble, &secondDouble);
	}

	handle = getHandle("./lib.so");


	switch(operator)
	{
		case '+':
		*(void **) (&basicOperation) = dlsym(handle, "sum");
		exitIfError();
		printf("%.2f %c %.2f = %.2f\n",firstDouble, operator, secondDouble, (*basicOperation)(firstDouble, secondDouble));
		break;

		case '-':
		*(void **) (&basicOperation) = dlsym(handle, "subtract");
		exitIfError();
		printf("%.2f %c %.2f = %.2f\n",firstDouble, operator, secondDouble, (*basicOperation)(firstDouble, secondDouble));
		break;

		case '*':
		*(void **) (&basicOperation) = dlsym(handle, "multiply");
		exitIfError();
		printf("%.2f %c %.2f = %.2f\n",firstDouble, operator, secondDouble, (*basicOperation)(firstDouble, secondDouble));
		break;

		case '/':
		*(void **) (&basicOperation) = dlsym(handle, "divide");
		exitIfError();
		printf("%.2f %c %.2f = %.2f\n",firstDouble, operator, secondDouble, (*basicOperation)(firstDouble, secondDouble));
		break;

		case 'm':
		*(void **) (&modulusOperation) = dlsym(handle, "getModulus");
		exitIfError();
		printf("%d %% %d = %d\n",firstInt, operator, secondInt, (*modulusOperation)(firstInt, secondInt));
		break;

		case 'p':
		*(void **) (&percentOperation) = dlsym(handle, "getPercent");
		exitIfError();
		printf("%.2f in percentage = %.2f\n",firstDouble, operator, (*percentOperation)(firstDouble));
		break;
		
		case 'b':
		*(void **) (&baseOperation) = dlsym(handle, "getBase");
		exitIfError();
		(*baseOperation)(firstLongInt, secondInt);
		break;
		
		default:
		printf("Error! operator is not correct");
	}

	dlclose(handle);
	return 0;
}

/** 
/	Searches a shared object library 
/	for a handle and returns it 
/
*/

void * getHandle(char* lib) {
	void *handle = dlopen(lib, RTLD_LAZY);

	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	dlerror();

	return handle;
}

int exitIfError() {
	char *error;
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}
	return 0;
}
