#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* scanf() */
    char str1[6], str2[6];
    int count = scanf("%5s %5s", str1, str2);     // 5개를 받아올 수 있다.
    printf("%s|%s \n", str1, str2);    
    printf("\n");

    //int count2 = scanf("%6s %6s", str1, str2);  // RUN_TIME error 뜬다.
                                                  // 6개는 안 된다.  
    //printf("%s|%s \n", str1, str2);
        
    int count3 = scanf_s("%5s %5s", str1, 6, str2, 6);
        // 최근에 나왔다. <= scanf_s
        // scanf_s의 인자는 (string pointer, size) 형태로 들어간다. 
    printf("%s|%s \n", str1, str2);
    printf("\n"); 

    return 0;
}

