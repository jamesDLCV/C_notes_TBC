#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

// 우리가 쓰고 싶은 기능을 갖고 있는 
// 문자열 입력 함수를 직접 만들어서 쓸 수도 있다. 
// C++ 나 다른 언어에서는 기본 라이브러리에서 여러 가지를 제공하고 있다. 
// C에서는 만들어 보는 게 의미가 있다. 

char* custom_string_input(char* st, int n);

int main() {

    /* An example of custom input function */
    // 입력 받는 함수를 자기가 만들어서 쓸 수도 있다. 
    char word[11];
    puts(custom_string_input(word, 11));

    return 0;
}

char* custom_string_input(char* st, int n) {

    char* ret_ptr;
    int i = 0;

    ret_ptr = fgets(st, n, stdin);

    if (ret_ptr) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] == '\0';
        else
            while (getchar() != '\n')   // clear buffer
                continue;
                // 버퍼에 남아 있는 경우가 있는데, 쓸데없이 읽는 걸 막는다.
                // 버저를 지워 준다. 
    }

    return ret_ptr;

}
