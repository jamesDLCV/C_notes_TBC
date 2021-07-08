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
        /* Example 1*/

        int times = atoi(argv[1]);  // 숫자를 문자로 입력을 받고, 그것을 다시 정수로 바꾼다. 
        // atof(), atol()

        // 3번째에 들어온 문자열을 times만큼 반복해서 출력하는 예제이다. 
        for (int i = 0; i < times; i++)
            puts(argv[2]);
    }
    // 그냥 실행시키면, 실행 파일이 argument line이 없이 (명령줄 인수가 없이) 실행이 된다. 
    // argc가 하나는 꼭 들어온다. 실행 파일의 이름은 있어야만 하니까. 
    // 하나만 가지고 들어오므로 if문에 걸려서 Wrong Usage of ~ 부분이 출력이 된다. 
    // 
    // command line에서 말고 visual studio에서도 실행을 할 수 있다. 
    // 프로젝트 이름(ch11_11_stringIntoNumber)을 grab한 후 우클릭한다.
    // properties > Configuration Properties > Debugging > Command Arguments 
    // (입력) 3 hellob > (enter) 
    // ctrl + F5 실행.
    // hello
    // hello
    // hello
    // 위 반복문의 실행 결과로 hello가 3번 반복이 된다. 
    // 

    /* Example 2 */

    //printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));



    return 0;
}