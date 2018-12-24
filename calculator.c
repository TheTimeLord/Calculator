/*
 * Author: Brian Andrus
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pemdas.h"

#define MAX_LEN 50

/*************************************************************
 * intro()
 * 	- displays basic information to guide the user
 *************************************************************/

void intro() {
	printf("\n");
	printf("Input the type of calculation being done:\n");
	printf("[b] Basic equation:\n");
	printf("[e] Exit:\n\n");
	printf("> ");
	return;
}

/*************************************************************
 * break_equation()
 * Input: String eq, String tokens[]
 * 	- breaks apart eq into tokens of 2 catagories: numbers
 * 	  and non-numbers. tokens are then stored in tokens[]
 *	  in order in which they appear in eq.
 *************************************************************/

void break_equation(char *eq, char tokens[MAX_LEN][MAX_LEN]) {
	// i = equation index
	// j = row index
	// k = col index
	int i=0, k=0, j=0;
	while( i<MAX_LEN ) {
		// if character is NaN
		if( eq[i] < 0x30 || eq[i] > 0x39 )
		{
			// if the first char is NaN, put it in the first index and move on
			if( i==0 ) {
				tokens[j][k] = eq[i];
			}
			else {
				// if the previous char was a #, terminate the string and move on
				if( k!=0 ) {
					tokens[j][k] = '\0';
					j++;
				}
				k = 0;
				tokens[j][k] = eq[i];
			}
			j++;
		}
		else {
			tokens[j][k] = eq[i];
			k++;
		}
		if(eq[i] == '\0') {
			tokens[j][k] = '\0';
			break;
		}
		i++;
	}
	return;
}

void print_eq(char token[MAX_LEN][MAX_LEN]) {
	int i=0;
	while( token[i][0] != '\0' && token[i][0] != '\n' && i<MAX_LEN ) {
		printf("%d: %s\n", i, token[i]);
		i++;	
	}
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

	break_equation(equation, tokens);
	print_eq(tokens);

	int i=0;

	// PEMDAS TESTING
	pemdas();

	return 0;
}
