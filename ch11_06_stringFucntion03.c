#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// C 언어에는 문자열 사용을 도와주는 다양한 함수가 있다. 

int main() {

    /*
        strncat(): string concatenation
                                뒤에다가 붙이는 것이다.
    */

    char str1[100] = "First string";    // 공간이 충분해야 한다. 
                                        // 그래야 뒤에다가 붙여 줄 수 있다.
    char str2[] = "Second string";  

    strncat(str1, str2, 2); // Append 2 characters
                            // 100개가 모두 초기화가 된 것이 아니라서,
                            // 녹색 밑줄이 뜬다. 
    puts(str1);             // First string,  Second stringSe
                            // 뒤에 눈에는 안 보이는 
                            // null character도 추가가 돼 있을 것이다. 


    return 0;
}
