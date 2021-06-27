#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// C 언어에는 문자열 사용을 도와주는 다양한 함수가 있다. 

int main() {

    /*
        strcpy() and strncpy()
            문자열을 포인터만 복사하는 것이 아니라,
            내용물을 한 글자 한 글자 다 돌면서 복사를 해 준다.
            strncpy()는 몇 글자인지 제한을 둘 수 있다. 
    */

    char dest[100] = "";    // make sure memory is enough
    char source[] = "Start programming!";
    //dest = source;              // Error
            // 포인터에다가 포인터를 집어 넣는 것이 될 것이다?
            // 안 된다. 안 되는 이유는 배열에서 설명함.  
    //dest = "Start someting";    // Error

    strcpy(dest, source);           
        // char *__cdecl strcpy(char *_Destination, const char *_Source)
        // Source를 Destination에 갖다가 복사를 하는 것이다. 
        // Source와 Destination 두 용어는 앞으로 많이 만나게 될 것이다. 
        //
        // source "Start programming!"을 한 글자 한 글자 돌면서
        // null character를 만날 때까지 돌면서, 
        // destination에다가 복사를 할 것이다. 
        //  
    puts(dest);                     // Start programmiong!
    strncpy(dest, source, 5);       // '\0' is NOT added 
        // 주의할 점!
        // Start만 복사가 되고, null character 부분은 복사가 되지 않는다.
        // source에 있는 문자열 중 딱 5글자만 복사하라고 하면, 
        // 정말 곧이곧대로 5개만 복사한다. '\0'도 복사를 안 한다. 
        // '\0' 이 복사가 안 되므로, 문제가 생길 것이다.         
        // 
    puts(dest);                     // Start
    strcpy(dest, source + 6);       
        // 포인터 연산을 이용해서, 시작하는 위치를 바꿔서 넣을 수 있다. 
        // 
    puts(dest);                     // programming!    
    strcpy(dest, source);           
    puts(dest);                     // Start programmiong!    
    strcpy(dest + 8, "coding!");
    puts(dest);                     // Start prcoding!
                    // dest에는 Start programmiong! 이 들어가 있다.    
                    // Start pr <= dest + 8
                    // dest안에 있는 문자열 중 딱 8개만 넣어라.

    return 0;
}
