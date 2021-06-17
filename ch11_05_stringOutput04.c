#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TEST "A string from #define."

int main() {

    /* 
        printf()    
    */

    char str[] = "Just do it, do it!";
    printf("%s\n", str);    // \n added
    puts(str);
    puts(str);  // 줄바꿈을 알아서 해 준다. 
    puts("");

    char input[100] = "";
    int ret = scanf("%10s", input); // Input: "Just do it, do it!\n"
                                    // (Note %10s) 열 글자 제한을 걸었다.
    printf("%s\n", input);          // Output: "Just"
        // scanf()는 빈칸을 만나면 더 이상 읽어들이지 않는다.
        // scanf()가 입력 받는 것은 사실은 단어 하나이다. 
        // scanf()의 장점은 여러 가지 자료형이 섞여 있을 때,
        // 입력을 받기가 편하다. 
        // 한 단어, 정수 한 개 등등 
        // 문자열을 입력받고 그 문자열을 숫자로 변환시킬 수도 있다. 

    ret = scanf("%10s", input);     // Reads remaning buffer
        // 읽기 않고 buffer에 남아 있던 것들을 읽어 들인다. 
        
    printf("%s\n", input);          // Output: "do"
        // 버퍼에 남아 있는 것들을 읽어 들이다가 또 빈칸을 만나면, 
        // 읽기를 중단한다.    

    return 0;
}

