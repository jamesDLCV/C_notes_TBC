#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

#define WIDTH   40                               
#define NAME    "James Hwang"
#define ADDRESS "Seoul, Korean"

// 함수의 프로토타입에서는 매개변수의 type만 선언해 줘도 된다. 
// 변수명은 생략해도 문제가 없지만, 모두 써 주는 게 좋다. 
void print_multiple_chars(char, int, bool);
void print_centered_str(char);

int main() {
    print_multiple_chars('*', WIDTH, true);    

    print_centered_str(NAME);
    print_centered_str(ADDRESS);        
    print_centered_str("I love you.");  

    print_multiple_chars('*', WIDTH, false);

    return 0;
}

void print_multiple_chars(char c, int n_stars, bool print_newline) {
    //printf("********************\n");

    for (int i = 0; i < n_stars; ++i)
        printf("%c", c);        

    if (print_newline)
        printf("\n");
}

void print_centered_str(char str[]) {
    int n_blanks = 0;
    n_blanks = (WIDTH - strlen(str)) / 2;
    print_multiple_chars(' ', n_blanks, false);
    printf("%s\n", str);
}

