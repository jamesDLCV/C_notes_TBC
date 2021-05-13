#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

#define WIDTH   40                  // 기호적 상수                 
#define NAME    "James Hwang"
#define ADDRESS "Seoul, Korean"

void print_multiple_chars(char c, int n_stars, bool endl);
void print_centered_str(char str[]);

int main() {    
    print_multiple_chars('*', WIDTH, true);
    //printf("\n");   // <= 깔끔하지가 않다. 위 true로 대체함. 

    print_centered_str(NAME);
    print_centered_str(ADDRESS);        // 코드가 훨씬 깔끔해졌다. 
    print_centered_str("I love you.");  // 간단하게 출력 문구를 추가할 수 있다. 

    /*n_blanks = (WIDTH - strlen(ADDRESS)) / 2;
    print_multiple_chars(' ', n_blanks);
    printf("%s\n", ADDRESS);*/

    print_multiple_chars('*', WIDTH, false);

    return 0;
}

void print_multiple_chars(char c, int n_stars, bool print_newline) {
    //printf("********************\n");

    for (int i = 0; i < n_stars; ++i)
        printf("%c", c);    // putchar(c);    

    if (print_newline)   
        printf("\n");
}

void print_centered_str(char str[]) {
    int n_blanks = 0;
    n_blanks = (WIDTH - strlen(str)) / 2;
    print_multiple_chars(' ', n_blanks, false);
    printf("%s\n", str);
}
 
// 함수를 쓰면 좋을 때는???
// 1. 기능을 확장해야 할 때
// 2. 같은 기능이 여러 번 반복해서 나타날 때
// 이 두 가지 경우에는 함수를 사용해서 코드를 정리하는 것이 좋다. 
// 함수 이름만 잘 지어놓으면, 다른 사람도 쉽게 의미를 이해할 수 있다.

