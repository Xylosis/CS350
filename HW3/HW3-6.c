/* Print a float in binary: ftob.c */
#include <stdio.h>
#include <stdlib.h>

#define LEN 32
#define EXP_32 8		/* ending index of s for exponent */
#define MAN_32 9		/* starting index of s for significand */

float strToDecimal(char s[LEN]) {
   unsigned int uInt = 0;
   unsigned int mask;

    printf("binary value = ");
    for(int i = 0; i < LEN-1; i++) {
        printf("%c", s[i]);
        if(i == 0 || i == EXP_32)
            printf(" ");
    }
    printf(" --> ");
    for (int i = 0; i < (LEN); i++) {
        if (s[i] == ' ')
            continue;
        if(s[i] == '1') {
            uInt = (uInt | 1 << (31 - i));
        }
    }
    
    float f = *((float *) &uInt);
    return f;
}

int main(int argc, char **argv) {
  int n=LEN;
  char s[LEN] = "001111110100000000000000000000";

  printf("float value = %f\n", strToDecimal(s));

  printf("float value = %f\n", strToDecimal("00111110000000000000000000000000"));

  return 0;
}