#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 문자열을 숫자로 바꿔주는 함수가 들어있다. 

int main(int argc, char* argv[]) {

    /*
        string to long, unsigned long, double
        strtol(), strtoul(), strtod()
        long으로, 언사인드 롱, double로 바꿔준다.

        strtod() converts base 10 only, 10진수만 변환 가능, atoi() 함수와 비슷하다.
    */

    char str1[] = "1024Hello";  // "-1024Hello" 이렇게 음수도 가능하다.
    char* end;
    long l = strtol(str1, &end, 10);    // &가 붙었다. <= 이중 포인터이다. 
    printf("%s %ld %s %d\n", str1, l, end, (int)*end);
    // 1024Hello 1024 Hello 72
    // end가 포인터이므로 string처럼 출력이 된다. 
    // str1의 문자열을 한 글자 한 글자 변환하다가 변환할 수 없는 문자를 만나면 
    // 그 문자(H)에 대한 포인터를 char* end;에 넣어준다. 
    // H는 십진수로 변환할 방법이 없으므로 넣어주고 끝낸다. 
    // (int)*end <= 아스키 코드 십진수 출력, H이므로 72가 나온다.
    //    
    printf("\n");

    long ul = strtoul(str1, &end, 10);  
        // unsigned long type이지만, long으로 해도 출력이 된다. 
        // 예외적인 것으로 생각하고, 의도적으로는 사용하지 말아라.
    printf("%s %ld %s %d\n", str1, ul, end, (int)*end);
    // 십진수일 때는 간단하다.
    printf("\n");

    // 16진수일 때는 문자 중 일부가 16진수로 변환이 된다. 
    char str2[] = "10FFHello";  // 10FF까지가 숫자다. 
    l = strtol(str2, &end, 16);
    printf("%s %ld %s %d\n", str1, l, end, (int)*end);
    //1024Hello 4351 Hello 72

    return 0;
}