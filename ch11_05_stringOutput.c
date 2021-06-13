#include <stdio.h>
#define TEST "A string from #define."

int main() {

    /*
        puts(): add \n at the end
    */

    char str[60] = "String array initialized";
    const char* ptr = "A pointer initialized";

    puts("String without \\n");
    puts("END");
    puts(TEST);
    puts(TEST + 5);
        
    puts(&str[3]);  // 문자열의 시작 포인터를 바꿔 준다. 
                    // puts() 함수의 인자는 
                    // 출력할 문자열(string)이 저장된 메모리의 주소이다. 
    //puts(str[3]); //Error

    puts(ptr + 3);
        // 문자열의 시작 포인터가 바뀐 것처럼 
        // 몇 칸 더 가서 시작하는 것처럼 나오고 있다. 
       

    return 0;
}

