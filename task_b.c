#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
  double height = 0;
	double volume = 0;
	printf("Enter height: ");
	scanf("%lf", &height);
	


	// Your code below here
  const double radius = 2.2;	
  //volume = M_PI * radius * radius * height;	
  //calc volume using pow func from math.h and fabs to assert height is > 0
  volume = M_PI * pow( radius , 2.0) * fabs(height);
	
	// Do not edit below here
	printf("Volume: %.2f", volume);
	return 0;
}
