#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// C 언어에는 문자열 사용을 도와주는 다양한 함수가 있다. 

int main() {

    /*
        strcat() and strncat(): string concatenation
                                뒤에다가 붙이는 것이다. 
    */

    char str1[100] = "First string";    // 공간이 충분해야 한다. 
                                        // 그래야 뒤에다가 붙여 줄 수 있다.
    char str2[] = "Second string";

    strcat(str1, ",  ");    // 한 번 덧붙여 주고,
    strcat(str1, str2);     // 그 다음 또 덧붙여 준다. 

    puts(str1);             // First string,  Second string
                     
    return 0;
}
