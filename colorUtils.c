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
		printf("Red value cannot be greater than 255. Set to 255.");
		r = 255;
	} else if (r < 0) {
		printf("Red value cannot be less than 0. Set to 0.");
		r = 0;
	}
	
	if (g > 255) {
		printf("Green value cannot be greater than 255. Set to 255.");
		g = 255;
	} else if (g < 0) {
		printf("Green value cannot be less than 0. Set to 0.");
		g = 0;
	}
	
	if (b > 255) {
		printf("Blue value cannot be greater than 255. Set to 255.");
		b = 255;
	} else if (b < 0) {
		printf("Blue value cannot be less than 0. Set to 0.");
		b = 0;
	}
	
	double rPrime = (double) r / 255;
	double gPrime = (double) g / 255;
	double bPrime = (double) b / 255;
	
	*k = 1 - max(rPrime, gPrime, bPrime);
	
	if (*k == 1) {
		printf("ERROR DIVIDE BY 0\n");
		return -1;
	}
	
	printf("%.2f\n%.2f\n%.2f\n", (1 - rPrime - *k)/(1 - *k), (1 - gPrime - *k)/(1 - *k), (1 - bPrime - *k)/(1 - *k));
	*c = (1 - rPrime - *k)/(1 - *k);
	*m = (1 - gPrime - *k)/(1 - *k);
	*y = (1 - bPrime - *k)/(1 - *k);
	
	return 0;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
	if(c > 1) {
		printf("Cyan value cannot be greater than 1. Set to 1.");
		c = 1;
	} else if (c < 0) {
		printf("Cyan value cannot be less than 0. Set to 0.");
		c = 0;
	}
	
	if (m > 1) {
		printf("Magenta value cannot be greater than 1. Set to 1.");
		m = 1;
	} else if (m < 0) {
		printf("Magenta value cannot be less than 0. Set to 0.");
		m = 0;
	}
	
	if (y > 1) {
		printf("Yellow value cannot be greater than 1. Set to 1.");
		y = 1;
	} else if (y < 0) {
		printf("Yellow value cannot be less than 0. Set to 0.");
		y = 0;
	}
	
	if (k > 1) {
		printf("K value cannot be greater than 1. Set to 1.");
		k = 1;
	} else if (k < 0) {
		printf("K value cannot be less than 0. Set to 0.");
		k = 0;
	}
	
	*r = 255 * (1 - c) * (1 - k);
	*g = 255 * (1 - m) * (1 - k);
	*b = 255 * (1 - y) * (1 - k);
	
	return 0;
}

int main (void) {
	int r = 100;
	int g = 50;
	int b = 75;
	double c, m, y, k;
	rgbToCMYK(r, g, b, &c, &m, &y, &k);
	
	printf("%d, %d, %d, %.2f, %.2f, %.2f, %.2f\n\n", r, g, b, c, m, y, k);
	
	r = 20;
	g = 100;
	b = 66;
	
	rgbToCMYK(r, g, b, &c, &m, &y, &k);
	printf("%d, %d, %d, %.2f, %.2f, %.2f, %.2f\n\n", r, g, b, c, m, y, k);
	
	r = 0;
	g = 0;
	b = 0;
	
	rgbToCMYK(r, g, b, &c, &m, &y, &k);	
}


/*
	Test Cases
	
	rgbToCMYK
	I: (R = 100, G = 50, B = 75) 
	EO: (C = 0, M = 0.5, Y = .25, K = 0.61)
	O: (C = 0, M = 0.5, Y = 0.25, K = 0.61)
	
	I: (R = 20, G = 100, B = 66)
	EO: (C = 0.8, M = 0, Y = .34, K = 0.61)
	O: (C = 0, M = 0.5, Y = 0.25, K = 0.61)
	
	I: (R = 0, G = 0, B = 0)
	EO: (ERROR DIVIDE BY ZERO)
	O: (ERROR DIVIDE BY ZERO)
*/