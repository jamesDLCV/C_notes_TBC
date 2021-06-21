#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// C 언어에는 문자열 사용을 도와주는 다양한 함수가 있다. 

void fit_str(char*, unsigned int);

int main() {

    /*
        strlen(): return length of the string
                  문자열의 길이를 알려주는 함수
    */

    // TODO: use dubugger

    char msg[] = "Just,"" do it!";
    puts(msg);
    printf("Length %d\n", strlen(msg));
    fit_str(msg, 4);
    puts(msg);
    printf("Length %d\n", strlen(msg));
    
    return 0;
}

void fit_str(char* str, unsigned int size) {

    if (strlen(str) > size)
        str[size] = '\0';    

}

// 문자열을 사용할 때는, 메모리 공간이 잘 잡혀 있는지, 사용할 수 있는 
// 공간이 있는지, 계속 확인을 하는 것이 중요하다. 