#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(void) {

    // Get user input
    #define N 256
    char buffer[N+1], *filename = buffer, *end = buffer;
    char ch;
    int i = 0; // counter for how many characters read
    printf("Enter a file name: ");
    while ((ch = getchar()) != '\n') { // get one character at a time
        filename[i++] = ch;
        // Enter your code under here
        end++;
        
    }
    
    for (; i < N+1; i++) { // fill the rest of the array with null characters
        filename[i] = '\0';
    }

    // Enter your code under here
    for (; *end != '.' && end > filename; end--);
    if (end == filename) {
      printf("Error!");
    }
    else {
      printf("%s", end);
    }


    return EXIT_SUCCESS;
}
