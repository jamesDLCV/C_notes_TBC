#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char* argv[]) {

    /*
        Numbers to strings
        Use sprintf() instead of itoa(), ftoa()     // cf) atoi(), atof()
        하지만 itoa()와 ftoa()는 표준이 아니라서 실무에서 사용을 권장하지 않는다.
    */

    char temp[100];
    puts(_itoa(10, temp, 16));  // 표준에서 이름이 바뀌었다. _itoa()처럼 underscore를 붙여야 한다.
                                // 실무에서 사용을 권장하지 않는다.

    // 실무에서는 sprintf()를 많이 사용한다. 
    // 숫자를 문자로 바꿀 때는 sprintf()를 사용하는 것이 좋다. 
    sprintf(temp, "%x", 10);    // printf()의 결과를 temp에 저장하라.
    puts(temp);

    //a
    //a     

    return 0;
}