#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH   40                  // 기호적 상수                   
#define NAME    "James Hwang"
#define ADDRESS "Seoul, Korean"

void print_multiple_chars(char c, int n_stars);
void print_centered_str(char str[]);

int main() {
    int n_blanks = 0;

    print_multiple_chars('*', WIDTH);
    printf("\n");

    print_centered_str(NAME);
    print_centered_str(ADDRESS);        // 코드가 훨씬 깔끔해졌다. 
    print_centered_str("I love you.");  // 간단하게 출력 문구를 추가할 수 있다. 

    /*n_blanks = (WIDTH - strlen(ADDRESS)) / 2;
    print_multiple_chars(' ', n_blanks);
    printf("%s\n", ADDRESS);*/

    print_multiple_chars('*', WIDTH);    

    return 0;
}

void print_multiple_chars(char c, int n_stars) {
    //printf("********************\n");

    for (int i = 0; i < n_stars; ++i)
        printf("%c", c);    // putchar(c);    
}

void print_centered_str(char str[]) {
    int n_blanks = 0;
    n_blanks = (WIDTH - strlen(str)) / 2;
    print_multiple_chars(' ', n_blanks);
    printf("%s\n", str);
}

// main() 함수 안은 깔끔해졌다. 
// 처음에 짠 몇 줄 안 되는 코드에 비해 함수도 두 개가 됐고, 
// 훨씬 복잡한 구조로 바꾸어 버렸다.
// 보다 나은 프로그래머가 되려면 다음을 고려해야 한다.  
// 어떤 코드든지 일반적으로 작동하도록 짠다. 
// 장기적으로 유지 보수가 쉽도록 짠다. 
// 추구 문구를 넣기도 쉽다. 
// print_centered_str() 함수를 다른 곳에서도 재사용할 수 있다. 
// 코드 개선, 활용에 이런 함수 활용이 아주 중요하다. 
// 25:37
