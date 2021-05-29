#include <stdio.h>

int main() {
    /* Pointer Compatibility */

    int n = 5;
    double x;
    x = n;      // no error, promotion 형 변환, 정수를 더블에 넣는다.
        
    int* p1 = &n;
    double* pd = &x;
    //pd = p1;  // Warning, incompatible type, 정말 권장하지 않는다.
                // visual studio에서 warning만 띄워주고 있다. 
                // 이런 것은 피해야 한다. 

    pd = (double*)p1;   // 이렇게 casting하면 할 수 있다. 
                        // 정말 포인터 끼리 casting을 해야 하는 상황이라면,
                        // 주석을 달아야 한다. 
    
    // c++에는 다이나믹 캐스팅, 스태틱 캐스팅 같은 것들이 있다. 
    // 객체지향 프로그래밍에서 가끔 형 변환을 해야 할 경우가 있다. 
    // 클래스간 형 변환을 할 때 허용이 되는 문법이 있다. 
    // 이럴 때 포인터간 형 변환이 허용되는 경우가 있다. 
    // 하지만 이 경우에도 그렇게 좋지는 않다. 
    // 좋지는 않지만 가끔 하는 경우가 있다. 

    // 복잡한 포인터 연산을 모른다고 해서 프로그래밍하는 데 큰 문제 없다.

    int* pt;
    int(*pa)[3];   // 포인터인데, 세 개짜리 원소를 가진 배열을 가질 수 있는
                   // 포인터이다. 

    // 사이즈가 다른 배열 두 개
    int ar1[2][3] = { 3, };
    int ar2[3][2] = { 7, };

    int** p2;       // a pointer to a pointer

    pt = &ar1[0][0];    // pointer-to-int
                        // pt가 포인터이다. 
                        // 2차원 배열의 한 원소의 주소를 담을 수 있다. 
                        // 포인터 pt를 이용해서 
                        // 배열 ar1의 원소 6개를 모두 출력할 수 있다. 

    // 1차원 배열로 다차원 배열의 원소들에 전부 접근할 수 있다. 
    // 메모리 구조가 그렇게 돼 있기 때문이다. 
    // 메모리에 어차피 일렬로 쭉 나열돼 있는 데이터이기 때문이다. 
    // 다만 포인터만으로는 원소가 몇 개인지 알 수가 없다. 
    for (int i = 0; i < 6; ++i)
        printf("%d ", pt[i]);
    printf("\n");

    for (int i = 0; i < 6; ++i)
        printf("%d ", *(pt + i));


    pt = ar1[0];        // pointer-to-int;
                        // ar1[0]이 포인터이므로,
                        // ar1[0]와 &ar1[0][0]은 같다. 
    //pt = ar1;         // Warning (Error)
                        // ar1은 2차원 배열이기 때문에, 
                        // 그냥은 포인터에 담을 수가 없다. 
    pa = ar1;           // pointer-to-int[3]
                        // pa는 원소가 3개짜리인 배열에 대한 포인터이다. 
                        // ar1은 원소가 3개짜리인 배열의 배열이다. 
                        // 그러므로 원소가 3개짜리인 포인터에 담을 수가 있다.

    pa = ar2;           // Warning or error
                        // ar2를 담으려고 하면 Warning이 뜬다.
                        // ar2는 원소가 두 개이기 때문이다. 
                        // int *(pa)[2]; 로 선언해 주면 된다. 

    p2 = &pt;           // pointer-to-int *
                        // p2는 이중포인터다. pt의 주소를 담을 수 있다. 

    *p2 = ar2[0];       // pointer-to-int
                        // 이렇게도 담을 수 있다. 

    //p2 = ar2;         // Warning or error
    // Notes
    // - p2: pointer to pointer to int
    // int에 대한 포인터에 대한 포인터이다. 이중포인터이므로. 
    // - ar2: a pointer to array-of-tow-ints
    // 두 개의 int를 가진 배열에 대한 포인터이다. 

    /* Pointer and const */

    int x = 20;
    const int y = 23;
    int* p1 = &x;
    const int* p2 = &y;
    const int** pp2 = &p1;

    //p1 = p2;      // Warning or Error
    
    //*p2 = 123;    // Error
    p2 = p1;

    int x2 = 30;
    int* p3 = &x2;
    *pp2 = p3;
    pp2 = &p1;

    return 0;
}