#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>  // toupper(), ispunct(), ...

#define NUM_LIMIT 1024

// ctype.h에 다양한 문자 함수들이 들어 있다. 
// ctype.h에 들어 있는 문자 함수를 
// 문자열에서 어떻게 사용하는지 간단하게 살펴 보자. 
// 문자열에 있는 모든 문자에 대해서 적용을 하는 것이다. 

void ToUpper(char*);
int PunctCount(const char*);

int main() {
    char line[NUM_LIMIT];
    char* new_line = NULL;
    fgets(line, NUM_LIMIT, stdin);
    new_line = strchr(line, '\n');  // find first newline

    // '\n'을 '\0'으로 바꾼다. 
    if (new_line)
        *new_line = '\0';

    ToUpper(line);  // 주어진 문자열을 한 글자씩 돌면서 대문자로 바꿔 준다.
    puts(line);
    printf("%d\n", PunctCount(line));   // 문자열에 기호가 몇 개인지 센다.

    return 0;
}

// 문자열을 받기 위해 문자의 포인터를 받고 있다. 
// char 타입에 대한 포인터가 parameter로 사용된다면, 
// 대부분은 문자에 대한 포인터라기보다, 문자열을 받기 위해서 사용하고 있다.
// 아래에서는 개수가 몇 개인지는 받고 있지 않다. 

void ToUpper(char* str) {
    while (*str) {
        *str = toupper(*str);
            // 최근에는 toupper() 함수 안에 아래의 기능이 포함돼 있다. 
        /*if (islower(*str))
            *str = toupper(*str);*/
        str++;
    }
}

int PunctCount(const char* str) {
    int ct = 0;
    while (*str) {
        if (ispunct(*str))
            ct++;
        str++;
    }
    return ct;
}