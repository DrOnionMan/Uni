#include <stdio.h>
#include <string.h>


#define INDEX_BOUND(val, bottom, top) (bottom <= val && val < top)


int is_vowel(char* letter) {
  switch (*letter) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u': return 1;
    default: break;
  }
  return 0;
}

int main(void){
  int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	
	
	// Your code below here
  char my_email[] = "michael.kidd@student.manchester.ac.uk";
	const unsigned int len = strlen(my_email);
  if (!INDEX_BOUND(n, 0, len)) {
    fprintf(stdout, "Error");
    return 1;
  }
  
  if (is_vowel(my_email + n)) {
    printf("Vowel"); // place as needed in the code. You can use more than once.
  }
  else {
    printf("Not vowel"); // place as needed in the code. You can use more than once.
  }
	
	// Do not edit below here
	return 0;
}
