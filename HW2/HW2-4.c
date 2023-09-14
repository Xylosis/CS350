#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

char *castingSignedUnsigned(int num1, unsigned int num2){
    if( num1 == num2 ){
        return "==";
    } else if ( num1 > num2 ) {
        return ">";
    } 
    return "<";
}

char *castingUnsignedSigned(unsigned int num1, int num2){
    if( num1 == num2 ){
        return "==";
    } else if ( num1 > num2 ) {
        return ">";
    } 
    return "<";
}

int main(){
    printf("-------------------------------------------------------------------\n Constant 1\tConstant 2\t\tRelation\tEvaluation\n-------------------------------------------------------------------\n");
    
    printf(" %d\t\t%uU\t\t\t%s\t\t%s\n", 0, 0U, castingSignedUnsigned(0, 0U), "unsigned");
    printf(" %d\t\t%d\t\t\t%s\t\t%s\n", -1, 0, (-1 > 0 ? ">" : "<"), "signed");
    printf(" %d\t\t%uU\t\t\t%s\t\t%s\n", -1, 0U, castingSignedUnsigned(-1, 0U), "unsigned"); 
    /*Returns -1 > 0U because -1 becomes casted to unsigned, so instead of comparing -1 & 0, its actually comparing 65535 (Unsigned Max, since -1 == UNSIGNED MAX == FFFF ) */
    printf(" %d\t%d\t\t%s\t\t%s\n", INT_MAX, INT_MIN, ( INT_MAX > INT_MIN ? ">" : "<"), "signed");
    printf(" %uU\t%d\t\t%s\t\t%s\n", INT_MAX, INT_MIN, castingUnsignedSigned(INT_MAX, INT_MIN), "unsigned");
    printf(" %d\t\t%d\t\t\t%s\t\t%s\n", -1, -2, (-1 > -2 ? ">" : "<"), "signed");
    printf("(unsigned)%d\t%d\t\t\t%s\t\t%s\n", -1, -2, castingUnsignedSigned(-1, -2), "unsigned");
    printf(" %d\t%uU\t\t%s\t\t%s\n", INT_MAX, INT_MIN, castingSignedUnsigned(INT_MAX, INT_MIN), "unsigned");
    printf(" %d\t(int)%uU\t%s\t\t%s\n", INT_MAX, INT_MIN, (INT_MAX > (int)((unsigned) INT_MAX + 1U) ? ">" : "<"), "signed");

    return 0;
}