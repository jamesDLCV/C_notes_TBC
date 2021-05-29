#include <stdio.h>

int main() {    

    /* Pointer and const */

    int x = 20;
    const int y = 23;
    int* p1 = &x;
    const int* p2 = &y;
    const int** pp2 = &p1;

    //p1 = p2;      // Warning or Error
                    // Warning이 뜨지만 넣을 수는 있다. 
                    // 권장하지 않는다. 

    //*p2 = 123;    // Error, const를 왼쪽에 붙여줬으므로
                    // indirection을 하면서 값을 못 바꾼다. <== 숙지!!!!

    p2 = p1;        // const int* const p2 = &y;과 같이 const를 붙여주면, 
                    // p2 = p1은 안 된다. <== 숙지!!!

    int x2 = 30;
    int* p3 = &x2;
    *pp2 = p3;      // 이중 포인터에 넣을 수가 있다.
                    // indirection을 해도 뭔가 바꿀 수가 있다. 
                    // const int* const* pp2 = &p1; <= 이렇게 하면,
                    // *pp2 = p3;는 안 된다. 

    pp2 = &p1;      // pp2에 p1의 주소를 넣을 수도 있다. 
                    // const int** const pp2 = &p1; <= 이렇게 하면,
                    // pp2 = &p1;은 안 된다. 

    // const를 포인터와 함께 사용할 때는 주의를 해야 한다. 




    return 0;
}