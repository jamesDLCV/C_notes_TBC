#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH   20
#define NAME    "James Hwang"
#define ADDRESS "Seoul, Korean"

void print_bar();

int main() {

    print_bar();

    printf("    James Hwang\n");
    printf("    Seoul, Korean\n");

    print_bar();

    return 0;
}

void print_bar() {
    printf("********************\n");
}