#include <stdio.h>
#include <math.h>

int main(void){
  double height = 0;
	double volume = 0;
	printf("Enter height: ");
	scanf("%lf", &height);
	
	// Your code below here
  const double radius = 2.2;	
  //volume = M_PI * radius * radius * height;	
  
  volume = M_PI * pow( abs(radius) , 2.0) * height;
	
	// Do not edit below here
	printf("Volume: %.2f", volume);
	return 0;
}
