// Data Structures Updation Operation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

void main() {
	int LA[] = { 1,3,5,7,8 };
	int k = 3, n = 5, item = 10;
	int i, j;

	printf("The original array elements are :\n");

	for (i = 0; i<n; i++) {
		printf("LA[%d] = %d \n", i, LA[i]);
	}

	LA[k - 1] = item;

	printf("The array elements after updation :\n");

	for (i = 0; i<n; i++) {
		printf("LA[%d] = %d \n", i, LA[i]);
	}
}