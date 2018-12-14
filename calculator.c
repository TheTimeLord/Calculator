/*
 * Author: Brian Andrus
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

void intro() {
	printf("Input the type of calculation being done:\n");
	printf("[b] Basic Arithmetic: \"+,-,/,*\"\n");
	printf("[e] Exit:\n");
	return;
}

int main(int argc, char *argv[]) {
	intro();

	return 0;
}
