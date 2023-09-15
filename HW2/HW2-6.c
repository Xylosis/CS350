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

    int sum = x + y;
    /*Figure out how far to shift to get MSB, and then store them in variables by masking by 1.*/
    int shift = (sizeof(int) << 3) - 1;;
    /*Get MSB of x, y, and sum, since these are the signifiers for overflow and underflow.*/
    int x_MSB = x >> shift & 1;
    int y_MSB = y >> shift & 1;
    int sum_MSB = sum >> shift & 1;

    /*
    If MSB for x & y are 1, then we know we have two negative values, so adding them together will result in another negative value. So when we check the
    sum's MSB, if it's 1, then everything is good, meaning its still negative. If it's zero, that means underflow occured and the sum was smaller than the
    supported value. Likewise with overflow, if the MSB for x & y are 0, and then the MSB for the sum is 1, then this means we added to positive numbers together,
    and got a negative number, which could only happen from overflow occuring.

    We can't use an if statement, but we can use conditional operators. && has a precedence of left to right, so if we use booleans paired with &&, then we can
    essentialy make an if check without the if statement.
    */

    int underflow_occured = x_MSB && y_MSB && !sum_MSB;
    int overflow_occured = !x_MSB && !y_MSB && sum_MSB;

    /*Choose what value to give to sum for return.*/
    (underflow_occured && (sum = INT_MIN)) || (overflow_occured && (sum = INT_MAX));

    return sum;
}


int main() {

    int a = 14, b = 28, c = -12398, x = (INT_MIN) + 1, y = INT_MAX - 1;

    printf("\t\t Normal Addition\n-----------------------------------------------\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d + %d = %ld\n", c, x, (long) (c + x));
    printf("%d + %d = %ld\n", b, y, (long) (b + y));

    printf("\n\t\tSaturating Addition\n-----------------------------------------------\n");
    printf("%d + %d = %d\n", a, b, saturating_add(a, b));
    printf("%d + %d = %d\n", c, x, saturating_add(c, x));
    printf("%d + %d = %d\n", b, y, saturating_add(b, y));

    return 0;
}