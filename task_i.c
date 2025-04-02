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
    // allocate row buffers 
    double row1[N];
    double row2[N];
    double row3[N];
    for (int i = 0; i < N; i++) {
      // copy data into rows 
      row1[i] = data[i][0];
      row2[i] = data[i][1];
      row3[i] = data[i][2];
    }
    // sort them in acending order with stdlib qsort
    // because i cba writing my own again lmao
    qsort(row1, 201, sizeof(double), comp);
    qsort(row2, 201, sizeof(double), comp);
    qsort(row3, 201, sizeof(double), comp);
    
    // print median value
    // will be (n-1)/2 therefore is (201-1)/2 = 100
    printf("%.2lf, %.2lf, %.2lf", row1[100], row2[100], row3[100]);



    return EXIT_SUCCESS;
}
