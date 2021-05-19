#include <stdio.h>

int fibonacci_recursion(int n);
void fibonacci_loop(int n);

int main() {
    int num = 13;

    for (int i = 1; i < num; ++i) {
        printf("%d ", fibonacci_recursion(i));
    }
        
    printf("\n");

    fibonacci_loop(num);

    return 0;
}

int fibonacci_recursion(int n) {
    
    if (n > 2)
        return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
    else
        return 1;
}

void fibonacci_loop(int n) {

    int t_1 = 1, t_2 = 1, t_3, i;

    printf("%d %d", t_1, t_2);

    for (i = 3; i < n; ++i) {

        t_3 = t_1 + t_2;

        printf(" %d", t_3);

        t_1 = t_2;
        t_2 = t_3;
    }
}
