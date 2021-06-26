#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// C 언어에는 문자열 사용을 도와주는 다양한 함수가 있다. 

int main() {

    /*
        strcmp() and strncmp: compare strings (not characters) 
    */

    // true, false의 개념이 아니다. 

    printf("%d\n", strcmp("A", "A"));                   // 0
    printf("%d\n", strcmp("A", "B"));                   // -1
        // 앞의 것의 아스키 코드가 빠르면 -1이 뜬다.                      
    printf("%d\n", strcmp("B", "A"));                   // 1
        // 앞의 것이 아스크 코드가 뒤에 있으면 1이 뜬다. 
    printf("%d\n", strcmp("Hello", "Hello"));           // 0
    printf("%d\n", strcmp("Banana", "Bananas"));        // -1
        // null character와 s가 비교된다. 널 캐릭터가 더 작으므로 -1
    printf("%d\n", strcmp("Bananas", "Banana"));        // 1
    printf("%d\n", strncmp("Bananas", "Banana", 6));    // 0 
        // 글자 수를 제한할 수 있다. 6 글자만 비교한다. 

    return 0; 
}
