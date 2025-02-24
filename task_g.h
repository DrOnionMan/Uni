#include <math.h>
#include <assert.h>
void find_max_less_than_10(const double a[], const int n, double *max) {
    
    // Your code below here
  // sorted array so easy to find value
  if (10.0 <= a[0] ) {

    *max = INFINITY;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (10.0 <= a[i]) {
      *max = a[i-1];
      return;
    }
  }  

    
}
