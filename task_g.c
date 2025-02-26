#include <stdio.h>
#include <stdlib.h>
#include "task_g.h"
#include <string.h>
#include <stdint.h>
#include <assert.h>


static char* readFile(const char* fname, size_t* const restrict size) {
  // read whole file
  FILE* pfile = NULL;
  pfile = fopen(fname, "rb");
  if (!pfile) {
    //fprintf(stderr, "Error!\n");
    return NULL;
  }
  fseek(pfile, 0L, SEEK_END);
  const size_t fsize = ftell(pfile);
  rewind(pfile);
  char* buffer = (char*) malloc(sizeof(char) * fsize);
  if (!buffer) {
    //fprintf(stderr, "Error!\n");
    return buffer;
  }
  const size_t bytesread = fread(buffer, sizeof(char), fsize, pfile);

  if (bytesread != fsize) {
    //fprintf(stderr, "Error!\n");
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
  double* const arr = (double*)calloc(20, sizeof(double));
  do {
    if ('\n' == nums[eind] || '\0' == nums[eind]) {
      if (20 < darrind) {
        return NULL;
      }
      const size_t bsize = eind - sind;
      char* temp = (char*)alloca(sizeof(char) * (bsize));
      strncpy(temp, nums + sind, bsize);
      temp[bsize] = '\0';
      sind = eind + 1;
      eind++;
      while(69) {
        if (' ' != *temp)break;
        else temp++;
      }
      double num = atof(temp);
      arr[darrind] = num;
      darrind++;
    }else {
      eind++;
    }
  } while(eind <= size);
  return arr;
}
/* OLD
static inline __fastcall swap(double* const restrict n1, double* const restrict n2) {
  *(uint64_t*)n1 ^= *(uint64_t*)n2;
  *(uint64_t*)n2 ^= *(uint64_t*)n1;
  *(uint64_t*)n1 ^= *(uint64_t*)n2;
}
*/


static void Qsort(double* const restrict a, const size_t len) {
  if (len <= 1) 
    return;
  const double pivot = a[len/2];
  double b[len], c[len];
  size_t i, j = 0, k = 0;
  for (i=0; i < len; i++) {
    //ignore pivot value
    if (i == len/2) 
      continue;
    // fill sub arrs
    if ( a[i] <= pivot) 
      b[j++] = a[i];
    else            
      c[k++] = a[i];
  }
  //sort sub arrs after pivot split recursively
  Qsort(b,j);
  Qsort(c,k);
  for (i=0; i<j; i++) 
    a[i] = b[i];
  a[j] = pivot;
  for (i= 0; i<k; i++) 
    a[j+1+i] = c[i];
}

int main(void) {
  // Your code below here
  size_t size = 0;
  char* const fcontents = readFile("numbers.txt", &size);
  assert(NULL != fcontents);
  double* const arr = makeDoubleArray(fcontents, size);
  assert(NULL != arr);
  Qsort(arr, 20);
  
  /*
  for (int i = 0; i < 20; i++) {
    printf("%lf\n", arr[i]);
  }
  */
  //sort(arr, 19);
  

  double max;
  find_max_less_than_10(arr, 20, &max);
  
  if (INFINITY == max) {
    fprintf(stdout, "Error!");
    return 1;
  } else {
    fprintf(stdout, "%0.2lf", max);
  }
  
  free(fcontents);
  free(arr);
  return 0;
}
