#include <stdio.h>
#define GLOBAL 5
int main() {
	printf("L3 App Prog-Unix\n %d",GLOBAL);
	typedef struct {
		int x;
	} test;
	test a = {1};
	printf("Hello : %d", a.x);
}

