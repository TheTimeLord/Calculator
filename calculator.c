/*
 * Author: Brian Andrus
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 15

void intro() {
	printf("\n");
	printf("Input the type of calculation being done:\n");
	printf("[b] Basic equation:\n");
	printf("[e] Exit:\n\n");
	printf("> ");
	return;
}

int main(int argc, char *argv[]) {
	char equation[MAX_LEN];
	char tokens[MAX_LEN][MAX_LEN];

	printf("Input String:\n");
	fgets(equation, MAX_LEN, stdin);

	int i=0, k=0, j=0;
	while( /*equation[i] != '\0' &&*/ i<MAX_LEN ) {
		if( equation[i] < 0x30 || equation[i] > 0x39 )
		{
			tokens[j][k] = '\0';
			j++;
			k = 0;
			tokens[j][k] = equation[i];
			j++;
		}
		else {
			tokens[j][k] = equation[i];
			k++;
		}
		if(equation[i] == '\0') {
			tokens[j][k] = "\0";
			break;
		}
		i++;
	}
	
	i=0;
	while( tokens[i] != "\0" && i<MAX_LEN ) {
		printf("%d: %s\n", i, tokens[i]);
		i++;
	}

	return 0;
}
