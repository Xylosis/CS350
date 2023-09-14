/*
    Instead of overflowing the way normal two’s-complement addition does, saturating addition returns TMax when there would be positive overflow, and TMin
    when there would be negative overflow. Saturating arithmetic is commonly used in programs that perform digital signal processing.

    . Assumptions
    -Integers are represented in two’s-complement form.
    -Right shifts of signed data are performed arithmetically.
    -Data type int is w bits long. For some of the problems, you will be given a
    specific value for w, but otherwise your code should work as long as w is a
    multiple of 8. You can use the expression sizeof(int)<<3 to compute w.
    . Forbidden
    -Conditionals (if or ?:), loops, switch statements, function calls, and macro
    invocations.
    -Division, modulus, and multiplication.
    -Relative comparison operators (<, >, <=, and >=).
    . Allowed operations
    -All bit-level and logic operations.
    -Left and right shifts, but only with shift amounts between 0 and w − 1.
    -Addition and subtraction.
    -Equality (==) and inequality (!=) tests. (Some of the problems do not allow
    these.)
    -Integer constants INT_MIN and INT_MAX.
    -Casting between data types int and unsigned, either explicitly or implicitly


*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*Addition that saturates to Tmin or Tmax*/
int saturating_add(int x, int y){

}


int main() {


    return 0;
}