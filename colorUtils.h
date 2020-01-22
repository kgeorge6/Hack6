/*
	Color Utilities Source Code
	Kyle George
	1-21-2020
*/

#include <stdio.h>

double max(double var1, double var2, double var3) {
	double maximum = var1;
	if (var2 > maximum) {
		maximum = var2;
	}
	
	if (var3 > maximum) {
		maximum = var3;
	}
	
	return maximum;
}

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
	if (r > 255) {
		printf("Red value cannot be greater than 255.");
		return 2;
	} else if (r < 0) {
		printf("Red value cannot be less than 0.");
		return -2;
	}
	
	if (g > 255) {
		printf("Green value cannot be greater than 255.");
		return 3;
	} else if (g < 0) {
		printf("Green value cannot be less than 0.");
		return -3;
	}
	
	if (b > 255) {
		printf("Blue value cannot be greater than 255.");
		return 4;
	} else if (b < 0) {
		printf("Blue value cannot be less than 0.");
		return -4;
	}
	
	double rPrime = (double) r / 255;
	double gPrime = (double) g / 255;
	double bPrime = (double) b / 255;
	
	*k = 1 - max(rPrime, gPrime, bPrime);
	
	if (*k == 1) {
		printf("ERROR DIVIDE BY 0\n");
		return -1;
	}
	
	*c = (1 - rPrime - *k)/(1 - *k);
	*m = (1 - gPrime - *k)/(1 - *k);
	*y = (1 - bPrime - *k)/(1 - *k);
	
	return 0;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
	if(c > 1) {
		printf("Cyan value cannot be greater than 1.");
		return 1;
	} else if (c < 0) {
		printf("Cyan value cannot be less than 0.");
		return -1;
	}
	
	if (m > 1) {
		printf("Magenta value cannot be greater than 1.");
		return 2;
	} else if (m < 0) {
		printf("Magenta value cannot be less than 0.");
		return -2;
	}
	
	if (y > 1) {
		printf("Yellow value cannot be greater than 1.");
		return 3;
	} else if (y < 0) {
		printf("Yellow value cannot be less than 0.");
		return -3;
	}
	
	if (k > 1) {
		printf("K value cannot be greater than 1.");
		return 4;
	} else if (k < 0) {
		printf("K value cannot be less than 0.");
		return -4;
	}
	
	*r = 255 * (1 - c) * (1 - k);
	*g = 255 * (1 - m) * (1 - k);
	*b = 255 * (1 - y) * (1 - k);
	
	return 0;
}


/*
	Test Cases
	
	rgbToCMYK
	I: (R = 100, G = 50, B = 75) 
	EO: (C = 0, M = 0.5, Y = .25, K = 0.61)
	O: (C = 0, M = 0.5, Y = 0.25, K = 0.61)
	
	I: (R = 20, G = 100, B = 66)
	EO: (C = 0.8, M = 0, Y = .34, K = 0.61)
	O: (C = 0, M = 0.5, Y = 0.34, K = 0.61)
	
	I: (R = 0, G = 0, B = 0)
	EO: (ERROR DIVIDE BY ZERO)
	O: (ERROR DIVIDE BY ZERO)
	
	cmykToRGB
	I: (C = .97, M = .23, Y = .11, k = .77)
	EO: (R = 1.76, G = 45.16, B = 52.20)
	O:
	
	I: (C = 1.3, M = .28, Y = .66, k = .98)
	EO: (Value Cannot Excede 
	O: 
	
	I: (C = .44, M = .68, Y = .29, k = .23)
	EO: 
	O: 
*/