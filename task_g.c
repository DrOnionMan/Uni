#include <stdio.h>
#include <stdlib.h>
#include "task_g.h"
#include <string.h>
#include <stdint.h>
#include <assert.h>


#define SIZECHECK(t1, t2) (sizeof(t1) == sizeof(t2))






static char* readFile(const char* fname, size_t* const restrict size) {
  // read whole file
  FILE* pfile;
  pfile = fopen(fname, "rb");
  if (!pfile) {
    fprintf(stderr, "Error!\n");
    return NULL;
  }
  fseek(pfile, 0L, SEEK_END);
  size_t fsize = ftell(pfile);
  rewind(pfile);
  char* buffer = (char*) malloc(sizeof(char) * fsize);
  if (!buffer) {
    fprintf(stderr, "Error!\n");
    return buffer;
  }
  size_t bytesread = fread(buffer, sizeof(char), fsize, pfile);

  if (bytesread != fsize) {
    fprintf(stderr, "Error!\n");
    return NULL;
  }

  buffer[bytesread] = '\0';
  *size = fsize;
  fclose(pfile);
  return buffer;
}



static double* makeDoubleArray(const char* const restrict nums, size_t size) {
  size_t sind = 0;
  size_t eind = 0;
  size_t darrind = 0;
  double* arr = (double*)calloc(20, sizeof(double));
  do {
    if ('\n' == nums[eind]) {
      if (20 <= darrind) {
        fprintf(stderr, "Error!\n");
        return NULL;
      }
      size_t bsize = eind - sind;
      char* temp = (char*) alloca(sizeof(char) * (bsize));
      strncpy(temp, nums + sind, bsize);
      temp[bsize] = '\0';
      sind = eind + 1;
      eind++;
      while(69) {
        if (*temp != ' ')break;
        else temp++;
      }
      double num = atof(temp);
      arr[darrind] = num;
      darrind++;
    } else {
      eind++;
    }

  } while(eind < size);

  return arr;
}

static inline void swap(double* restrict n1, double* restrict n2) {
  //magic
  *(uint64_t*)n1 ^= *(uint64_t*)n2;
  *(uint64_t*)n2 ^= *(uint64_t*)n1;
  *(uint64_t*)n1 ^= *(uint64_t*)n2;
}


static void sort(double* const restrict nums, size_t len) {
  // Would do quicksort but its O(1) anyway so why bother
  for (size_t i = 0; i < len - 1; i++) {
    for (size_t j = 0; j < len - 1 - i; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums + j, nums + j + 1);
      }
    }
  }  
}





int main(void) {

    // Your code below here
  size_t size = 0;
  char* fcontents = readFile("numbers.txt", &size);
  double* arr = makeDoubleArray(fcontents, size);

  sort(arr, 20);

  double max;
  find_max_less_than_10(arr, 20, &max);
  
  if (INFINITY == max) {
    printf("Error!\n");
    return 1;
  }
  
  printf("%0.2lf.", max);
  return 0;
}
