#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// C 언어에는 문자열 사용을 도와주는 다양한 함수가 있다. 

int main() {

    /*
        sprintf()
            
    */

    char str[100] = "";
    int i = 123;
    double d = 3.14;
    sprintf(str, "%05d.png %f", i, d);
        // printf()와 거의 비슷하지만, 
        // 첫 parameter가, 문자열을 담을 수 있는 배열이다. 
        // printf()를 이 문자열에 해 준다.    
        // 출력은 안 된다. 
        // 출력을 위해서 아래 puts() 함수를 사용했다. 

    puts(str);          // 00123.png 3.140000
    // 연속되는 파일을 출력할 때, 파일 이름을 프로그램에서 자동으로 
    // 생성해 줘야 하는 경우가 있다. 천 개, 만 개, 십만 개 출력한다. 
    // 이때 파일 이름을 문자로 만들어서 파일 이름으로 쓸 수가 있다. 
    // eg) capture00000.png, capture00001.png, ...    
    
    return 0;
}
