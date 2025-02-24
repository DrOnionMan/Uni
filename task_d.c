#include <stdio.h>

#define OUTTEXT  "{\n\t\"name\": \"Michael Kidd\",\n\t\"email\": \"michael.kidd@student.manchester.ac.uk\",\n\t\"number1\": \"%0.2lf\",\n\t\"number2\": \"%e\"\n}"
#define BUFFMAXLEN 1024


int main(void){
    
	// Read number from file - do not edit
	double num;
	FILE *fptr;
	fptr = fopen("number.txt", "r");
	if(fptr == NULL) { // display error if can't open file
    printf("Error. Not able to open the file.");
		return 1;
  }
	fscanf(fptr, "%lf", &num);
	fclose(fptr);
	

	// Your code below here
	char buffer[BUFFMAXLEN];
	sprintf_s(buffer, BUFFMAXLEN, OUTTEXT, num, num);
  fprintf(stdout, buffer);
	
	// Do not edit below here
	return 0;
}
