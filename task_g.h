#include <math.h>
#include <assert.h>
void find_max_less_than_10(const double a[], const int n, double *max) {
  // Your code below here
  // sorted array so easy to find val
  int l = 0;
  int r = n - 1;
  int res = -1; // Index of the largest number less than 'val'
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
}
