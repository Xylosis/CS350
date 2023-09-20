/* Print a float in binary: ftob.c */
#include <stdio.h>
#include <stdlib.h>

#define LEN 32
#define EXP_32 8		/* ending index of s for exponent */
#define MAN_32 9		/* starting index of s for significand */

float strToDecimal(char s[LEN]) {
   unsigned int uInt = 0;
   unsigned int mask;

    for (int i = 0; i < (LEN); i++) {
        if(s[i] == ' ')
            continue;
        if(s[i] == '1') {
            uInt = (uInt | 1 << (31 - i));
        }
    }


    int flag = 0;
    mask = 1 << 31;
    for(int i = 0; i < LEN; i++) {
        flag = 0;
        printf("%u", (uInt & mask)!=0?1:0);
        mask = mask >> 1;
    }
    printf("\n");
    printf("uInt = %u\n", uInt);
    float f = *((float *) &uInt);
    printf("%f\n", ((float *)&uInt));
    printf("%f", f);
    return f;
}


int main(int argc, char **argv) {
  int n=LEN;
  char s[LEN];

  printf("binary value = ");
  for (int i = 0; i < (n); i++) {
    s[i] = argv[1][i];
    printf("%c", s[i]);
    if(i == EXP_32 || i == 1)
        printf(" ");
  }
  printf("\n");
  float f = strToDecimal(s);

  printf("float = %f\n", f);

  return 0;
}

