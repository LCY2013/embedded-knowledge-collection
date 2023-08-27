#include "bit-head.h"

void bitNegate() {
    unsigned char x = 0x17, y;

    y = ~x;

    printf("%#x\n", y);
}

void bitAnd() {
    unsigned char x = 0126, y = 0xac, z;

    z = x & y;

    printf("%#x\n", z);
}

void bitMoveLeft() {
    unsigned char x = 0xe4, y = 1;

    printf("x=%#x,y=%#x\n", x, y);

    y = x << 1;
    printf("x=%#x,y=%#x\n", x, y);

    y = x << 2;
    printf("x=%#x,y=%#x\n", x, y);

    y = x << 3;
    printf("x=%#x,y=%#x\n", x, y);

}

void bitOr() {
    unsigned char x = 0x4, y = 2;

    x = x | (1 << (y-1));

    printf("x=%#x,y=%#x\n", x, y);
}

void bitAndNegateMove() {
    unsigned char x = 0x14, y = 3;

    x = x & (~(1 << (y - 1)));

    printf("x=%#x, y=%#x\n", x, y);
}

void bitRightMove() {
    int a = 65, b = 0;

    printf("%#x %d\n", a, a);

//        b = a / 16;
    b = a >> 4;
    printf("%#x %d\n", b, b);

    //b = a % 16;
    b = a & 0xf;
    printf("%#x %d\n", b, b);
}
