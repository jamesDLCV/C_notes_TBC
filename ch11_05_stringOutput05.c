#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TEST "A string from #define."

/*
    puts() which doesn't add a new line at the end
    Use pointer increment operator and putchar()
*/

void custom_put(const char* str);    // Only two lines, 줄바꿈 없이 두 라인
int  custom_put2(const char* str);   // Add \n, return # of characters
                                     // 줄바꿈 추가, 출력한 단어의 개수 반환

int main() {

    /*
        Custom function
    */

    custom_put("Just ");
    custom_put("Do it!");

    printf("%d\n", custom_put2("12345"));    

    return 0;
}

void custom_put(const char* str) {

    while (*str != '\0')    // while (*str)
        putchar(*str++);
}

int  custom_put2(const char* str) {
    int count = 0;

    while (*str)    // while (*str  != '\0')
    {
        putchar(*str++);
        count++;
    }
    putchar('\n');
    
    return count;
}

// 문자열을 출력하는 다양한 방법들을 살펴 보았다. 