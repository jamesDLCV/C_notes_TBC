#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 문자열을 숫자로 바꿔주는 함수가 들어있다. 

int main(int argc, char* argv[]) {

    /*
        string to integer, double, long
        atoi(), atof(), atol()
        정수로, 더블로, long으로 바꿔준다.
    */

    if (argc < 3)
        printf("Wrong Usage of %s\n", argv[0]); // 0번 파일에 들어오는 것은 실행 파일 자체의 이름.
    else {
        /* Example 2 */

        // arguments로 들어오는 두 개를 정수로 바꿔서 더한다.
        printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
    }    
       
    // arguments로 10과 21을 넣어준다.
    // Sum = 31
    //  
    // .exe 파일을 직접 실행시킬 일이 있을까? 
    // c나 c++로 만든 실행 파일을 다른 스크립트 언어로 실행시킬 때가 있다. 
    // 또 반복해서 실행시킬 경우도 있다. 
    // 이럴 때는 명령줄 인수가 유용하게 사용된다. 
    // python은 원래 다른 언어로 만들어진 실행 파일을 실행시킬 때, 
    // 빠르게 스크립팅하는 용도로 개발된 것이다. 
    // 
    // 프로그래머 생활을 하게 되면 명령줄 인수를 많이 사용하게 된다. 

    return 0;
}