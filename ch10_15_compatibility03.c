#include <stdio.h>

int main() {

    {
        const int** pp2;
        int* p1;
        const int n = 13;
        pp2 = &p1;          // const?
                            // pp2 이중 포인터에 p1의 주소를 집어 넣었다.

        *pp2 = &n;          // sets p1 to point at n
                            // pp2에 indirection을 하면, &p1이다. 
                            // p1에다가 const인 n을 집어 넣는다. 
                            // p1은 const가 안 붙었는데 const를 대입한다?
                            // 빌드에 문제가 없다. 

        *p1 = 10;           // change n
                            // const의 값을 바꾸고 있는데, 
                            // 컴파일러가 아무 말도 안 하고 있다. 
        // 위와 같은 것은 하지 않는 것이 좋다. 
        // 컴파일러가 허용을 하든 말든 쓰지 않는 것이 좋다. 
        // 위와 같은 경우를 C 문법에서는 undefined라고 한다.
        // C의 철학 때문에 위와 같은 것을 엄격하게 제재하고 있지는 않다. 
    }

    /* C const and C++ const */
    {
        const int y;
        const int* p2 = &y;

        int* p1;
        p1 = p2;    // Waring or Error in cpp. 
                    // C++에서는 명확하게 막고 있다. 
                    // C 컴파일에서 허용을 하더라도 이렇게 논리적으로 
                    // 해서는 안 되는 일인 경우에는 사용하지 않는 걸 권장!
    }

    // 위와 같은 오묘한 방법은 문법적으로 허용되더라도 사용하지 않는 것이 좋다.
    // C++에서는 더 엄격하게 Error로 막아서 제재를 한다. 

    return 0;
}