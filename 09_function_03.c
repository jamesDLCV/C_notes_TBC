#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH   20                  // 기호적 상수                   
#define NAME    "James Hwang"
#define ADDRESS "Seoul, Korean"

void print_bar(int n_stars);

int main() {

    print_bar(WIDTH);

    //printf("    James Hwang\n");
    printf("    %s\n", NAME);

    //printf("    Seoul, Korean\n");
    printf("    %s\n", ADDRESS);

    print_bar(WIDTH);

    return 0;
}

void print_bar(int n_stars) {
    //printf("********************\n");

    for (int i = 0; i < n_stars; ++i) 
        putchar('*');    
    putchar('\n');
}