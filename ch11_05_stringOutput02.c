#include <stdio.h>
#define TEST "A string from #define."

int main() {

    /*
        stinrg without \0
    */

    char str[] = { 'H', 'I', '!' }; // No \0 at the end.
        // 맨뒤에 null character가 없다. 
        // null character가 없게 하기 위하여 강제로 이렇게 초기화했다. 
        // "" 겹따옴표를 사용해서 초기화를 하면 
        // 맨마지막에 '\0'가 자동으로 추가가 된다. 
        // string이라기보다는 배열로 각각의 문자를 집어 넣어서 초기화했다.
        // 
    puts(str);  // VS warns you!
                // Warning!
        // NULL character를 만나면, 출력을 종료해야 하는데, 
        // Null character가 없으므로, 계속 출력을 하고 있는 것이다. 
        // 메모리에 우연히 존재하는 널 캘릭터를 만날 때까지 계속 출력을 한다. 
        // 예상하지 못한 이상한 문자들이 출력된다. 

    return 0;
}

