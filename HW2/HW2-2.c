#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("-------------------------------------------------------------------------------\n\t\t\tWord Size w\n\t----------------------------------------------------------------\n");
    printf(" Value\t%d\t%d\t%d\t\t%d\n", CHAR_BIT, CHAR_BIT*2, CHAR_BIT*4, CHAR_BIT*8);
    printf("-------------------------------------------------------------------------------\n");
    printf(" %s\t%#X\t%#X\t%#X\t%#lX\n", "UMax", UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX);
    printf(" \t%d\t%d\t%u\t%lu\n\n", UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX);
    printf(" %s\t%#hhX\t%#hX\t%#X\t%#lX\n", "TMin", CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
    printf(" \t%d\t%d\t%d\t%ld\n\n", CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
    printf(" %s\t%#X\t%#X\t%#X\t%#lX\n", "TMax", CHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX);
    printf(" \t%d\t%d\t%d\t%ld\n\n", CHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX);
    printf(" %d\t%#hhX\t%#hX\t%#X\t%#lX\n\n", CHAR_MIN + CHAR_MAX, SHRT_MIN + SHRT_MAX, INT_MIN + INT_MAX, (LONG_MIN + LONG_MAX));
    printf(" %d\t0X", 0);
    for(int i = 0; i < (int) (CHAR_BIT / 4); i++){
        printf("0");
    }
    printf("\t0X");
    for(int i = 0; i < (int) ((CHAR_BIT * 2) / 4); i++){
        printf("0");
    }
    printf("\t0X");
    for(int i = 0; i < (int) ((CHAR_BIT * 4) / 4); i++){
        printf("0");
    }
    printf("\t0X");
    for(int i = 0; i < (int) ((CHAR_BIT * 8) / 4); i++){
        printf("0");
    }
    printf("\n-------------------------------------------------------------------------------\n");
    return 0;
}
