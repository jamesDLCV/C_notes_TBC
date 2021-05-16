#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int int_min(int, int); 

int main() {

    int i1, i2;

    while (1) {
        printf("Input two integers: (q / quit) ");

        if ((scanf("%d %d", &i1, &i2)) != 2) break;

        int lesser = int_min(i1, i2);
        // int lesser = min;
        printf("The lesser of %d and %d is %d\n", i1, i2, lesser);
    }

    return 0;
}

int int_min(int m, int n) {

    /*if (m > n) m = n;
   
    return m;*/

    // return (m < n) ? m : n;

    if (m < n)  return m;
    else        return n;

    printf("Who am I?");
    exit(1);    // 이런 식으로 남길 수는 있다. 의도적인 것이다. 
}
