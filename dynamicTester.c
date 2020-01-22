#include <stdio.h>
#include "colorUtils.h"

int main (void) {
	int choice;
	
	printf("Which code would you like to test?\n");
	printf("1 - RGB to CMYK\n");
	printf("2 - CMYK to RGB\n");
	printf("Enter Choice: ");
	scanf("%d", &choice);
	
	if(choice == 1) {
		int red, green, blue;
		double cyan, magenta, yellow, k;
		
		printf("\nEnter Red Value (0-255): ");
		scanf("%d", &red);
		printf("\nEnter Green Value (0-255): ");
		scanf("%d", &green);
		printf("\nEnter Blue Value (0-255): ");
		scanf("%d", &blue);
		
		if(rgbToCMYK(red, green, blue, &cyan, &magenta, &yellow, &k) == 0) {
			printf("\nCyan = %.2f, Magenta = %.2f, Yellow = %.2f, K = %.2f\n\n", cyan, magenta, yellow, k);
		}
	} 
	else if (choice == 2) {
		int red, green, blue;
		double cyan, magenta, yellow, k;
		
		printf("\nEnter Cyan Value (0-1): ");
		scanf("%lf", &cyan);
		printf("\nEnter Magenta Value (0-1): ");
		scanf("%lf", &magenta);
		printf("\nEnter Yellow Value (0-1): ");
		scanf("%lf", &yellow);
		printf("\nEnter K Value (0-1): ");
		scanf("%lf", &k);
		
		if(cmykToRGB(cyan, magenta, yellow, k, &red, &green, &blue) == 0) {
			printf("Red = %d, Green = %d, Blue = %d", red, green, blue);
		}
	} 
	else {
		printf("\nSorry, invalid input\n\n");
	}
	
	return 0;
}