#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 내가 이것 저것 실험해 봄. 

int main() {
  
    char* histhings1[1] = { "g" };
    printf("sizeof histhings1[1]: \t\t%zd\n", sizeof(histhings1));
    // 4
    char* histhings2[1][1] = { "g" };
    printf("sizeof histhings2[1][1]: \t%zd\n", sizeof(histhings2));
    // 4
    char* histhings3[1][1][1] = { "g" };
    printf("sizeof histhings3[1][1][1]: \t%zd\n", sizeof(histhings3));
    // 4
    char* histhings4[2] = { "g" };
    printf("sizeof histhings4[2]: \t\t%zd\n", sizeof(histhings4));
    // 8
    char* histhings5[1][2] = { "g" };
    printf("sizeof histhings2[1][2]: \t%zd\n", sizeof(histhings5));
    // 8
    putchar('\n');

    char herthings1[1] = { "g" };
    printf("sizeof herthings1[1]: \t\t%zd\n", sizeof(herthings1));
    // 1
    char herthings2[1][1] = { "g" };
    printf("sizeof herthings2[1]: \t\t%zd\n", sizeof(herthings2));
    // 1
    char herthings3[2] = { "g" };
    printf("sizeof herthings3[2]: \t\t%zd\n", sizeof(herthings3));
    // 2
    char herthings4[2][1] = { "g" };
    printf("sizeof herthings4[2][1]: \t%zd\n", sizeof(herthings4));
    // 2
    char herthings5[2][2] = { "g" };
    printf("sizeof herthings5[2][2]: \t%zd\n", sizeof(herthings5));
    // 4
    putchar('\n');
    putchar('\n');
    putchar('\n');

    // test
    char arr[] = "Hello, World.";
    char* str = "Hello, World";
    printf("%s\n", arr);
    printf("%s\n", str);
    printf("%c\n", *arr);   // H
    printf("%c\n", arr[1]); // e
    printf("%c\n", *str);   // H
    printf("%c\n", str[1]); // e
    printf("\n");
    
    return 0;
}