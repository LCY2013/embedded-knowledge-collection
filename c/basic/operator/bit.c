#include "bit-head.h"

int main(int argc, char *argv[])
{
    printf("negate: \n");
    bitNegate();
    printf("and: \n");
    bitAnd();
    printf("moveLeft: \n");
    bitMoveLeft();
    printf("or: \n");
    bitOr();
    printf("bitAndNegateMove:\n");
    bitAndNegateMove();
    printf("bitRightMove:\n");
    bitRightMove();
    return 0;
}
