// Includes
#include <stdio.h>
#include <string.h>
#include "domains.h"

// Main function 
int main(void) {
    
  // Read user input
  #define LEN 4
  char user_input[LEN];
  printf("Enter a domain including the . (e.g. .uk): ");
  fgets(user_input, LEN, stdin);
    
	
  // Enter your code under here
  // Use strcmp(user_input, country_codes[0].domain) to compare the text in user_input to the text in country_codes[0].domain.
#define ARRSIZE(arr) (sizeof(arr)/ sizeof(arr[0]))
  const size_t arrlen = ARRSIZE(country_codes); 
  for (size_t i = 0; i < arrlen; i++) {
    if (0 == strncmp(user_input, country_codes[i].domain, LEN)) {
      fprintf(stdout, "This is the domain for: %s\n", country_codes[i].country);
      goto exit;
    }
  }
  fprintf(stdout, "Domain not found.\n");
  return 1;

exit:
 
  // Do not edit below here
  return 0;
}
