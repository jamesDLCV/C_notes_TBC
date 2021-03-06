#include <stdio.h>
#define COLS 4

// 복합 리터럴과 배열 Compound Literals

int sum_1d(int arr[], int n);
int sum_2d(int arr[][COLS], int rows);

int main() {

    int a = 1;
    3;          // Literals are constants that aren't symbolic
    3.14f;
    int b[2] = { 3, 4 };
        // 배열이라는 것은 잠시 뒤로 해 두고, 
        // 구조만 보면, 3이라는 숫자와 4라는 숫자가 묶여 있다. 
        // 이를 복합 리터럴이라고 부를 수 있다. 
        // 3, 4라는 데이터 즉, 나열된 리터럴을 복사해서 
        // b[2] 여기 메모리 공간에 복사해서 넣어라. 이렇게 초기화해라.
        // 같은 자료형 여러 개을 묶는 것 외에도 
        // 다른 자료형끼리도 묶을 수가 있다. 구조체 배운 후 다시 다룬다.
        // 구조체와 관련된 복합 리터럴을 뒤에 다시 공부한다. 
    // 여기에서는 같은 자료형 여러 개를 묶어 복합 리터럴을 만들고, 
    // 사용하는 방법에 대해서 다룬다. 

    (int[2]) { 3, 4 };      // compound literal
        // 위와 똑같은데 배열의 이름이 없다. 
        // 기호적이지 않은 상수다. 
        // 배열을 컴파운드 리터럴로 표현하면 이렇게 된다. 
        // (int[2]) 이런 것은 앞서 설명했다. 
        // 
    // int c[2] = (int[2]){ 3, 4 };  // Error
        // 배열도 복합 리터럴 형태로 초기화할 수 있지 않을까?
        // 문법적으로 허용해 주지 않는다. 
        // 복합 리터럴로 배열을 초기화하는 것은 컴파일 에러가 생긴다. 
    
    // 그러면 이 복합 리터럴을 어디에 쓸 수 있을까?

    int arr1[2] = { 1, 2 };
    int arr2[2][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8} };

    printf("%d\n", sum_1d(arr1, 2));
    printf("%d\n", sum_2d(arr2, 2));
    printf("\n");

    // 아래는 재미있는 경우이다. 
    // 
    printf("%d\n", sum_1d((int[2]) { 1, 2 }, 2));
        // compound literals를 함수에 보내 줄 수 있다.
        // 즉, (int[2] { 1, 2 }를 함수에 보낼 수 있다. 
    printf("%d\n", sum_2d((int[2][COLS]) { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } }, 2));
        // 이것도 마찬가지다. 위의 arr2[2][COLS]와 똑같은 것을
        // 함수에 보낼 수 있다. 
        // 이름이 있는 배열로 먼저 선언을 하고, 
        // 이를 함수의 인자로 넣는 것이 아니라
        // 배열을 리터럴처럼 바로 인자로 넣어 줄 수가 있다. 
        // 직접 입력을 하는 하드 코딩의 경우 매우 유용하다. 
        // 변수를 선언하는 구간이 없이 바로 함수에 넣어 줄 수 있어서,
        // 간결한 맛이 있다. 
        // 물론 이런 하드 코딩이 항상 좋은 것은 아니다. 
    printf("\n");

    int* ptr1;
    int(*ptr2)[COLS];

    ptr1 = (int[2]){ 1, 2 };
        // array를 선언하고 포인터 ptr1에다가 그 array의 주소를 넣어 주는 
        // 것이 아니라 이렇게 복합 리터럴을 바로 포인터에 넣어 줄 수가 있다. 

    ptr2 = (int[2][COLS]){ {1, 2, 3, 4}, {5, 6, 7, 8} };
        // 이것도 복합 리터럴을 바로 포인터에 넣어 주었다. 

    // 포인터를 함수의 argument로 넣어 줄 수도 있다. 
    printf("%d\n", sum_1d(ptr1, 2));
    printf("%d\n", sum_2d(ptr2, 2));
    printf("\n");

    // 실행을 하면 위 세 가지 경우가 모두 동일하게 작동을 한다. 

    return 0;
}

int sum_1d(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; ++i)
        total += arr[i];
    return total;
}

int sum_2d(int arr[][COLS], int rows) {
    int total = 0;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < COLS; c++)
            total += arr[r][c];
    return total;
}

// 여러 가지 데이터를 묶어서, 리터럴처럼 사용하는 것이 
// 기본적인 복합 리터럴의 의미이다. 
// 여기에서는 같은 자료형을 여러 개 묶어서,  
// 배열의 리터럴처럼 사용하는 경우를 소개했다. 
// 서로 다른 자료형들이 묶여서 사용되는 보다 복합적인 복합 리터럴은
// 자료형을 공부하고 나서 다시 설명한다. 
// 
// 위처럼 이름이 없는 무엇인가를 사용하는 것이 최근 다양한 프로그램의 문법으로 
// 등장하고 있다. 
// 예를 들어 람다 함수 같은 것이 최근 빈번하게 나타난다. 
// 이름이 없는 함수도 만들 수가 있다. 
// 
// 이름이 없는 자료의 묶음, 
// 이름이 없는 자료의 복합체와 같은 응용된 개념들도 알아 두기를 바란다. 