#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int comp(const void* a, const void* b) {
  return *(double*)a > *(double*)b;
}



int main(void) {


    #define N 201
    #define M 3
    double data[N][M];

    #define MAXCHAR 100
    char buffer[MAXCHAR];
    int row = 0;
    int column = 0;
    char *ptr;

    char fn[] = "data.csv";
    FILE *fptr;
    fptr = fopen(fn, "r");
    while (fgets(buffer, MAXCHAR, fptr)) {
        column = 0;
        row++;
        if (row == 1) {
            continue;
        }
        char* value = strtok(buffer, ", ");
        while (value) {  
            data[row-2][column] = strtod(value,&ptr);
            value = strtok(NULL, ", ");
            column++;
        }
    }
    fclose(fptr);
    fptr = NULL;
    for (int i = 0; i < N; i++) {
      qsort(data[i], 3, sizeof(double), comp);
      printf("%.2lf,", data[i][1]);
    }
    




    return EXIT_SUCCESS;
}
