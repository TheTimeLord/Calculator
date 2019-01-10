/*
 * Author: Brian Andrus
 * pemdas.c
 *	- given an equation, perfom the order of operations on it
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "pemdas.h"

double pemdas(char token[MAX_LEN][MAX_LEN], double num[MAX_LEN]) {
	char operation;
	int i,k;
        double a,b;
        double temp, result;
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
                        // Check the current operation, it cannot be the first or last charater
			if(token[k][0] == operation && k>0 && k<MAX_LEN) {
                            a = num[k-1];
                            b = num[k+1];
                            switch(i) {
                                // Exponent
                                case 1:
                                    temp = pow(a, b);
                                    num[k-1] = temp;
                                    num[k+1] = temp;
                                    break;

                                // Multiply
                                case 2:
                                    temp = a*b;
                                    num[k-1] = temp;
                                    num[k+1] = temp;
                                    break;

                                // Divide
                                case 3:
                                    temp = a/b;
                                    num[k-1] = temp;
                                    num[k+1] = temp;
                                    break;

                                // Add
                                case 4:
                                    temp = a+b;
                                    num[k-1] = temp;
                                    num[k+1] = temp;
                                    break;

                                // Subtract
                                case 5:
                                    temp = a-b;
                                    num[k-1] = temp;
                                    num[k+1] = temp;
                                    break;
                            }
                            result = temp;
                        }
			k++;
	        }
	}
        printf("result: %lf\n", result);
	return 0.0;
}
