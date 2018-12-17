/*
 * Author: Brian Andrus
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

void intro() {
	printf("\n");
	printf("Input the type of calculation being done:\n");
	printf("[b] Basic equation:\n");
	printf("[e] Exit:\n\n");
	printf("> ");
	return;
}

void break_equation(char *eq, char **token) {
	return;
}

int main(int argc, char *argv[]) {
	char equation[MAX_LEN];
	char tokens[MAX_LEN][MAX_LEN];

	// initialize token array to '\0'
	for(int i=0; i<MAX_LEN; i++)
		tokens[i][0] = '\0';

	printf("Input String:\n");
	fgets(equation, MAX_LEN, stdin);

	// i = equation index
	// j = row index
	// k = col index
	int i=0, k=0, j=0;
	while( i<MAX_LEN ) {
		// if character is NaN
		if( equation[i] < 0x30 || equation[i] > 0x39 )
		{
			// if the first char is NaN, put it in the first index and move on
			if( i==0 ) {
				tokens[j][k] = equation[i];
			}
			else {
				// if the previous char was a #, terminate the string and move on
				if( k!=0 ) {
					tokens[j][k] = '\0';
					j++;
				}
				k = 0;
				tokens[j][k] = equation[i];
			}
			j++;
		}
		else {
			tokens[j][k] = equation[i];
			k++;
		}
		if(equation[i] == '\0') {
			tokens[j][k] = '\0';
			break;
		}
		i++;
	}
	
	i=0;
	while( tokens[i][0] != '\0' && tokens[i][0] != '\n' && i<MAX_LEN ) {
		printf("%d: %s\n", i, tokens[i]);
		i++;
	}

	return 0;
}
