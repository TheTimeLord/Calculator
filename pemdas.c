/*
 * Author: Brian Andrus
 * pemdas.c
 *	- given an equation, perfom the order of operations on it
 */

#include "calculator.h"
#include "pemdas.h"

double pemdas(char token[MAX_LEN][MAX_LEN], double num[MAX_LEN]) {
	char operation;
	int i,k,j=0;
	// for each operation in PEMDAS
	for(i=0; i<6; i++) {
		switch(i) {
			case 0:
				operation = '(';
				break;
			case 1:
				operation = '^';
				break;
			case 2:
				operation = '*';
				break;
			case 3:
				operation = '/';
				break;
			case 4:
				operation = '+';
				break;
			case 5:
				operation = '-';
				break;
		}
		
		k=0;
		// search the token array for the current operations and their position
		while( token[k][0] != '\0' && token[k][0] != '\n' && k<MAX_LEN ) {
			// TODO: Use a Queue to do the operations
			if(token[k][0] == operation) {
                            printf("%c ", operation);
                            j++;
                        }
			k++;
	        }
	}

	printf("\n%d operations\n", j);
	return 0.0;
}
