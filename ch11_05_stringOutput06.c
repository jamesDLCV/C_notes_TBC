#include <stdio.h>

int main() {

    int nData = 0x41;

    printf("%d\n", nData);
    printf("%X\n", nData);

    printf("%c\n", nData);
    printf("%c\n", nData + 1);
    printf("%c\n", 'A' + 2);
    printf("%c\n", 'A' + 3);

    printf("%s %d\n", "Hello", 10);
    printf("\n");

    char* pszData = "Test string!";

    printf("%s\n", pszData);
    printf("%p\n", pszData);
    printf("%p\n", &pszData);

    return 0;
}