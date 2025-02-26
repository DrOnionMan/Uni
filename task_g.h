#ifndef TASK_G_H
#define TASK_G_H
#include <math.h>
#include <assert.h>

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


void find_max_less_than_10(const double a[], const int n, double *max) {
  // Your code below here
  // sorted array so easy to find val
  Qsort((double* const)a, 20);
  int l = 0;
  int r = n - 1;
  int res = -1; 
  const double val = 10.0;
  while (l <= r) {
    const int mid = l + (r - l) / 2;

    if (a[mid] < val) {
      res = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }    
  }
  
  *max = res == -1 ? INFINITY : a[res];
  printf("Error!");
}


#endif
