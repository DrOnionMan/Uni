#include <stdio.h>

#define OUTTEXT  "{\n\t\"name\": \"Michael Kidd\",\n\t\"email\": \"michael.kidd@student.manchester.ac.uk\",\n\t\"number1\": %0.2lf,\n\t\"number2\": %0.3e\n}"
#define BUFFMAXLEN 1024

int main(int argc, char *argv[]){
    
	
	// Enter your code under here to read the filename from the command line
	if (2 > argc) {
    fprintf(stderr, "Error. Expected 1 filename.\n");
    return 1;
  }
	
	
	// Read number from file - do not edit
	double num;
	FILE *fptr;
	fptr = fopen(argv[1], "r");
  if (!fptr) {
    fprintf(stderr, "Error. Cannot open requested file.");
    return 1;
  }
	fscanf(fptr, "%lf", &num);
	fclose(fptr);
	

	// Enter your code from Lab D to print JSON output (with name, email, number1, number2) goes under here
  char buffer[BUFFMAXLEN];
	sprintf(buffer, OUTTEXT, num, num);
  fprintf(stdout,"%s", buffer);
	

	// Do not edit below here
	return 0;
}
