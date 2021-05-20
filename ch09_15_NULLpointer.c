#include <stdio.h>

int main() {

    int a_1;
    printf("%p\n", &a_1);
    printf("%d\n", a_1);

    /* 
    004FFA20        <= 주소를 갖게 된다. 
    - 858993460     <= 초기화를 안 해 줘서 이런 쓰레기 값을 갖게 된다. 
    */

    /*
    int *ptr;                   <= 초기화가 안 됐다. 
    printf("%p\n", ptr);        <= 쓰레기 주솟값인가?    
    printf("%d\n", *ptr);       <= 찾아갈 주소가 쓰레기 주소이다. 
    */
    // 위를 해석해 보면, 찾아가 봤더니 사용하도록 할당 받은 공간이 아니다.
    // 컴파일러가 강제 종료시킨다. 
    // 동적할당, 자료구조 때 이런 오류를 많이 만나게 된다. 
    // run-time error는 주소를 잘못 넣어 줬을 때 발생한다. 

    // run-time error 방지 방법 중 하나 소개

    int *safer_ptr;
    int a = 123;
    //safer_ptr = &a;   // <= 이건 확실한 경우이다. 
    // 하지만 확실한 경우보다 아래와 같은 경우가 더 많다. 

    // 어떠한 조건에 따라서 이 포인터에 변수가 대입이 될 수도 아닐 수도 있다.
    // 대입이 될지 안 될지는 run-time에 결정되는 경우가 있다. 
    if (a % 2 == 0) {
        safer_ptr = &a;
    }

    // 다음의 예로 확인하자. 
    int b;
    scanf_s("%d\n", &b);

    if (b % 2 == 0)
        safer_ptr = &a;

    // 입력이 1, 3, 5와 같은 숫자로 들어오면, 
    // 포인터는 초기화되지 않은 상태로 남게 된다. 
    // 이를 어떻게 해결하는가?
    // 대부분의 c 프로그래머들은 포인터를 선언함과 동시에 NULL 값을 넣는다.

    // NULL 포인트 초기화!
    int* safer_ptr2 = NULL;     // 예전에는 0을 대입하기도 했다. 
                                // c++에서는 nullptr을 넣는다. 
    int c;
    scanf_s("%d", &c);

    if (c % 2 == 0)
        safer_ptr2 = &c;

    // 위에서 c에 1이 입력되더라고 포인터에는 NULL 값이 입력돼 있을 것이다.

    if (safer_ptr2 != NULL)
        printf("%p\n", safer_ptr2);

    if (safer_ptr2 != NULL)
        printf("%d\n", *safer_ptr2);

    return 0;
}