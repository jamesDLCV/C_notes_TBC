#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {
        
    char small_array[5];
    puts("Enter long strings: (1)");
    printf("%p\n", small_array);    
    printf("%p\n", fgets(small_array, 5, stdin));
        // Return value of fgets()
        // control + z 를 입력해 보자. 
        // fgets()의 반환값이 null이 될 수 있다. 
    fputs(small_array, stdout);
    printf("\n");


    /* Repeating short reading */
    char small_arr2[5];
    puts("Enter long strings: (2)");
    while (fgets(small_arr2, 5, stdin) != NULL && small_arr2[0] != '\n')  
        puts(small_arr2);  // What if we use fputs()
    printf("\n");

    char small_arr3[5];
    puts("Enter long strings: (3)");
    while (fgets(small_arr3, 5, stdin) != NULL && small_arr3[0] != '\n')
        fputs(small_arr3, stdout);  
            // 5개 제한이지만 마치 한 번에 다 읽어들이는 것처럼 출력한다. 
    
    return 0;
}

