#include "str-head.h"

void StrOne() {
    char arr1[] = {'a', 'b', 'c'};
    char arr2[] = {'d', 'e', 'f'};

    printf("arr1:%s %p %p\n", arr1, arr1, &arr1[2]);
    printf("arr2:%s %p\n", arr2, arr2);
    //printf("err:%d\n", *(arr2+3));
    printf("====\n");

#if 1
    int i, n;
    n = sizeof(arr1) / sizeof(char);
    for (i = 0; i < n; i++)
        putchar(arr1[i]);
    putchar('\n');

    n = sizeof(arr2) / sizeof(char);
    for (i = 0; i < n; i++)
        putchar(arr2[i]);
    putchar('\n');
#endif
}

void StrTwo() {
    char fruit[][20] = {"banana", "apple", "strawmerry", "watermelen"};
    int i, j, n, m;

    n = sizeof(fruit) / sizeof(fruit[0]);
    m = sizeof(fruit[0]) / sizeof(char);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            putchar(fruit[i][j]);
        putchar('\n');
    }

}

void StrThree() {
    char fruit[][20] = {"banana", "apple", "strawmerry", "watermelen"};
    int i, n;

    n = sizeof(fruit) / sizeof(fruit[0]);

    for (i = 0; i < n; i++)
        printf("%s\n", fruit[i]);
}

void StrFour() {
    char arr[] = "welcome";
    int i, n;

    n = sizeof(arr) / sizeof(char);
    for (i = n - 1; i >= 0; i--)
        putchar(arr[i]);
    putchar('\n');
}

#define N 20

void StrFive() {
    char arr[N] = {0};
    int i, n;

    printf("Please input a string:");
    //gets(arr);
    scanf("%s", arr);

    n = strlen(arr);
    for (i = n - 1; i >= 0; i--)
        putchar(arr[i]);
    putchar('\n');
}

void StrSix() {
    char arr[N] = {0};
    int i, j, n, ch;

    printf("Please input a string:");
    //gets(arr);
    scanf("%s", arr);

    n = strlen(arr);
    i = 0;
    j = n - 1;
    while (i < j) {
        ch = arr[i];
        arr[i] = arr[j];
        arr[j] = ch;
        i++;
        j--;
    }

    puts(arr);
}

void IsAlpha() {
    int ch ;

    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            if (isupper(ch))
                printf("upper:%c\n", ch);
            if (islower(ch))
                printf("lower:%c\n", ch);
        }
        if (isdigit(ch))
            printf("digit:%d %c\n", ch - '0', ch);
        putchar(ch);
    }
}

void Strstr() {
    char s[] = "how are you";
    char subs[] = "are";

    printf("%s\n", strstr(s, subs));
    printf("%ld\n", strstr(s, subs) - s);
}

#define M 100
void StrcatOne() {
    char dest[M] = "www.makeru";
    char src[] = ".com.cn";

    strcat(dest, src);

    puts(src);
    puts(dest);
}

void StrcatTwo() {
    char dest[M] = {'a', 'b', 'c'};
    //char dest[M] = {'a', 'b', '\0'};
    char src[] = ".com.cn";

    strcat(dest, src);

    printf("dest:%p src:%p\n", dest, src);
    puts(src);
    puts(dest);
}

void StrcatThree() {
    char src[] = "makeru";
    char dest[M] = ".com.cn";

    strncat(dest, src, 4);

    puts(src);
    puts(dest);
}

void StrChr() {
    char s1[] = "abas$f$sf";
    int ch;

    ch = '$';

    printf("%p %p \n", s1, strchr(s1, ch));
    printf("%p %p \n", s1, strrchr(s1, ch));

    printf("%ld \n", strchr(s1, ch) - s1);
    printf("%ld \n", strrchr(s1, ch) - s1);
}

void Strcmp() {
    char s1[] = "ab";
    char s2[] = "abc";

    printf("%d\n", strcmp(s1, s2));
}

void StrcmpOne() {
    char s1[] = "QUIT";
    char s2[] = "quit";

    printf("%d\n", strncmp(s1, s2, 4));
    printf("%d\n", strcasecmp(s1, s2));
}

void StrcpyOne() {
    char src[] = "makeru";
    char dest[N];
    int i, n;

    //strcpy(dest, src);
    i = 0;
    n = strlen(src);
    printf("n=%d\n", n);
    while (i < n) {
        dest[i] = src[i];
        i++;
    }

    puts(src);
    puts(dest);
}

void StrcpyTwo() {
    char src[] = "makeru";
    char dest[M] = ".com.cn";

    strncpy(dest, src, 4);

    puts(src);
    puts(dest);
}

void StrlenOne() {
    //char s1[10] = {'A', '0', 'B', '\0', 'C'};
    char s1[] = "makeru";

    printf("%ld\n", strlen(s1));
    printf("%ld\n", sizeof(s1)/sizeof(char));
}

void StrlenTwo() {
    char s1[] = "\tab\nc\vd\\e";
    char s2[]= "\x69\141";

    printf("%ld\n", strlen(s1));
    printf("%ld\n", sizeof(s1)/sizeof(char));

    printf("\n%ld\n", strlen(s2));
    printf("%ld\n", sizeof(s2)/sizeof(char));
    puts(s2);
}

void Toupper() {
    int ch;

    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = tolower(ch);
            }
            else {
                ch = toupper(ch);
            }
            printf("%c\n", ch);
        }
    }
}