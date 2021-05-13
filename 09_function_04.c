#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH   40                  // 기호적 상수                   
#define NAME    "James Hwang"
#define ADDRESS "Seoul, Korean"

void print_multiple_chars(char c, int n_stars);

int main() {
    int n_blanks = 0;

    print_multiple_chars('*', WIDTH);
    printf("\n");
    n_blanks = (WIDTH - strlen(NAME)) / 2;
    print_multiple_chars(' ', n_blanks);
    printf("%s\n", NAME);

    n_blanks = (WIDTH - strlen(ADDRESS)) / 2;
    print_multiple_chars(' ', n_blanks);
    printf("%s\n", ADDRESS);
    print_multiple_chars('*', WIDTH);
    printf("\n");

    return 0;
}

void print_multiple_chars(char c, int n_stars) {
    //printf("********************\n");

    for (int i = 0; i < n_stars; ++i)
        printf("%c", c);    // putchar(c);    
}