#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// C 언어에는 문자열 사용을 도와주는 다양한 함수가 있다. 

int main() {

    /*
        strcpy() and strncpy()
            문자열을 포인터만 복사하는 것이 아니라,
            내용물을 한 글자 한 글자 다 돌면서 복사를 해 준다.
            strncpy()는 몇 글자인지 제한을 둘 수 있다.
    */

    char dest[100] = "";    // make sure memory is enough
    char source[] = "Start programming!";
                      // Start programmiong!
    strcpy(dest, source);
    strncpy(dest, source, 5);       // '\0' is NOT added 
        // 주의할 점!
        // Start만 복사가 되고, null character 부분은 복사가 되지 않는다.
        // source에 있는 문자열 중 딱 5글자만 복사하라고 하면, 
        // 정말 곧이곧대로 5개만 복사한다. '\0'도 복사를 안 한다. 
        // '\0' 이 복사가 안 되면, 문제가 생길 것이다.         
        // 
    puts(dest);     // Start programming! 이 전부 출력이 되고 있다. 
                    // 5개만 출력이 돼야 하는데, 어찌된 일인가?
                    // '\0'을 복사하지 않기 때문이다. 
    
    // 문자열 함수들은, 맨뒤에 \n(new line)이나 \0(null character)를 
    // 자동으로 넣어주는 경우가 있는데, 
    // strcpy() 같은 경우는 메모리 자체를 복사하는 용도로도 종종 사용되므로, 
    // '\0'를 붙여주는 것과 같은 군더더기 처리를 안 해 준다. 
    // 
    // 이런 것으로 인한 오류가 있으므로 주의를 해야 한다. 
    // 메모리 자체를 복사하는 용도로는 
    // 네트워킹할 때 간단하게 사용하는 경우가 가끔 있다. 
    // 대부분의 경우에는 램 카피가 있다. 
    // 메모리를 복사해 주는 함수가 있다.     

    return 0;
}
