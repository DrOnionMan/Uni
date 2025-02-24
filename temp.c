#include <stdio.h>





int main() {
  fprintf(stdout, "%d, %d, %d, %d\n", sizeof(int), sizeof(long), sizeof(long int), sizeof(long long));
  return 0;
}
