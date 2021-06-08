#include <stdio.h>

#define MESSAGE "A symbolic string constant"
#define MAXLENGTH 81

int main() {      

    const char m1[15] = "Love you!";

    for (int i = 0; i < 15; ++i)
        printf("%d ", (int)m1[i]);  // Note the null characters
    printf("\n");

    // 76 111 118 101 32 121 111 117 33 0 0 0 0 0 0
    // 아스키 코드를 출력해 보면, 
    // 초기화되지 않은 남는 공간은 null character로 초기화되었다. 

    const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0' };  
        // 문자의 배열을 초기화하는 것이다.
        // 이런 식으로 초기화할 때는, 
        // null character를 수동으로 잡아 줘야 한다.
        // const char m1[15] = "Love you!";에서는 
        // 컴파일러가 알아서 맨뒤에 null character를 잡아 준다. 
        // 하지만, '\0'를 생략하더라도 컴파일러가 잡아 주기도 한다. 

    for (int i = 0; i < 15; ++i)
        printf("%d ", (int)m2[i]);  // Note the null characters
    printf("\n");

    // 76 111 118 101 32 121 111 117 33 0 0 0 0 0 0
    // 똑같이 작동한다. 

    // 아래처럼, 일반적인 배열 초기화처럼 원소의 사이즈를 안 쓸 수도 있다. 
    // 컴파일러가 알아서 잘 센다. 
    const char m3[] = "Love you, too!";


    int n = 8;
    char cookies[1] = { 'A', };
        // 배열의 길이는 unsigned int를 넣어 줘야 한다. 
        // 1은 문제가 없다. 

    char cakes[2 + 5] = { 'A' };
        // 2 + 5는 7이므로 문제가 없다. 

    char pies[2 * sizeof(long double) + 1] = { 'A', };
    // sizeof를 사용해도 괜찮다. 종종 사용하는 일이 있다. 
    // 이렇게 조금 더 복잡해 보이는 형태로 해도 되지만, 
    // 복잡하게 하다가 '실수'가 들어가면 안 된다. 
    // pies는 결국 배열이다. 

    //char crumbs[n];   // VLA
                        // VAL를 지원해 주는 컴파일에서는 이런 식으로 
                        // 할 수도 있다. 
                        // visual studio에서는 지원하지 않는다.  

    // 배열 공부할 때 봤던 부분이다. 
    char truth[10] = "Truths is ";
    if (truth == &truth[0]) puts("true!");
        // 배열의 이름은 첫 번째 원소의 주소다. 
    if (*truth == 'T') puts("true!");
        // truth 배열의 첫 번째 주소를 indirection하면?
    if (*(truth + 1) == truth[1]) puts("true!");
        // 'r'
    if (truth[1] == 'r') puts("true!");
        // 'r'

    return 0;
}

//일종의 몸 풀기로 문자열을 어떻게 초기화하는지 설명했다. 
//문자열의 성질이 배열로서의 성질도 있고, 
//포인터로서의 성질도 같이 있는데, 
//여기에 대해서는 앞에서 배열과 포인터에 대해서 많이 설명했다. 
//이어지는 강의에서 프로그램이 메모리에 어떻게 실리는가
//어떻게 배치가 되는가와 관련지어서 추가적으로 설명하겠다. 