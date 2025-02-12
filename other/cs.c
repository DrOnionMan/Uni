#include <stdio.h>
#include <stdint.h>
#include <complex.h>
#include <math.h>


#define J I

#define WORDLEN 8


#define GETBIT(ind, word) ((word >> (8 - 1 - ind)) & 1)
#define SETBIT(state, index, word) ()



int main(void) {
  /*
  float complex y = 1 + 1/(3*J) + 1/(8*J) + 1/(13*J);
  fprintf(stdout, "Mag: %f,Phase: %f", cabs(y), carg(y));
  */
  uint8_t reg = 0b01100011;
  for (int i = 0; i < 16; i++) {
    fprintf(stdout, "%d\n", reg);
    uint8_t fb = (GETBIT(0, reg) & GETBIT(2, reg)) ^ GETBIT(5, reg);
  }


  return 0;
}
