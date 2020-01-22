#include <stdio.h>
#include "colorUtils.h"

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