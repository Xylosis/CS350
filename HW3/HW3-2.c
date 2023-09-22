#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    int k, x = 2;
    if(argc > 1) 
        k = atoi(argv[1]);
    if(k == 17)
        x = (x << 4) + x;
    else if (k == -7) 
        x = x - (x << 3);
    else if (k == 60)
        x = (x << 6) - (x << 2);
    else if (k==-112)
        x = ( x << 4 ) - (x << 7);

    printf("%d\n", x);
    return 0;
}