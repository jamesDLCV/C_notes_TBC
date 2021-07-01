#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// C 언어에는 문자열 사용을 도와주는 다양한 함수가 있다. 

int main() {

    /*
        there are more functions...
    */

    printf("%s\n", strchr("Hello, World", 'W'));
        // World
        // 'W'로 시작되는 위치를 찾아서 포인터를 리턴해 준다.
        // 그리고 그것을 다시 string으로 출력을 하면, 
        // 마치 'W'로 시작하는 데서부터 출력을 하는 것처럼 보인다.         

    printf("%s\n", strpbrk("Hello, World", "ABCDE"));
        // (null)
        // "ABCDE" 중에 시작되는 하나를 찾는다.
        // 그러나 해당되는 글자가 없다. 
        // 그래서, (null)이 출력된다. 
        //
    printf("%s\n", strpbrk("Hello, World", "abcde"));
        // ello, World
        // "abcde" 중에서 소문자 e가 가장 먼저 찾아지는 문자이므로, 
        // H가 빠진 ello, World가 출력이 되고 있다. 

    printf("%s\n", strrchr("Hello, World, Hello, World", 'l'));
        // ld 
        // last occurrence
        // 'l'이 나타나는 가장 마지막 포인터를 리턴해 준다. 
        // 그러므로 ld 만 출력이 된다. 

    printf("%s\n", strstr("Hello, World", "wor"));
        //(null)
        // 문자열끼리 비교를 해 준다. 
        // "wor"이 없으므로 안 결린다. 

    printf("%s\n", strstr("Hello, World", "Wor"));
        // World
        // "Wor"을 찾을 수가 있으므로, World의 W 포인터가 리턴이 되고,
        // 스트링이 W에서부터 출력이 돼서, World가 출력이 되고 있다.        

    //World
    //(null)
    //ello, World
    //ld
    //(null)
    //World

    return 0;
}
