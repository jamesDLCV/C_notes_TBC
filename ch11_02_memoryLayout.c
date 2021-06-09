#include <stdio.h>

//c 언어의 문자열을 초기화하는 두 가지 방법이 차이가 있고, 
//문법적으로 주의해야 할 부분이 있다. 
//메모리 레이아웃이 어떻게 사용되는지 들여다 보는 시간을 갖겠다. 
//레이아웃: 설계도, 전체 구조.
//
//작성한 프로그램이 컴퓨터에서 실행이 될 때, 
//메모리를 어떻게 용도별로 나누어서 사용하는지 구조를 보여주는 것이다. 

// 이번 강의의 목표는 다음 두 가지의 차이를 이해하는 것이다. 
//char arr[] = "Hello, World."; <= 배열이다.
// 배열은 자체로 메모리를 가지고 있다. 따라서 arr[]은 메모리를 가지고 있고, 
// "Hello, World."라는 문자열의 내용물이 이 배열로 복사해서 들어가면서 초기화가 된다. 
// 
//char* str = "Hello, World";
// str은 문자 포인터이므로, "Hello, World."라는 문자열의 첫 번째 주소를 
// 가리키고만 있는 상황이다. 
// 
// str[0] = 'M';    // ERROR!!! <= run time error 발생.
// 원소를 바꾸려고 하면 런타임 에러가 발생한다. 
// 왜 원소를 바꿀 수 없는지에 대한 근본적인 이유를 
// 메모리 레이아웃과 관련지어 살펴보자. 
// 
// 노트 필기 참조: 스택, 힙
// 

void test_function();

int main() {    

    /* Array vs. Pointer */
    // 배열과 포인터의 차이만 이해하면 된다. 
    // 추가로 메모리 배치가 이렇게 되는구나를 이해하면 더 좋다. 
     
    // 포인터가 받는 문자열의 주소를 잘 봐라.
    const char* pt2 = "I am a string!.";        // the same as pt3
    const char* pt3 = "I am a string!.";        // the same as pt2
    const char* pt4 = "I am a string!!!!!!.";   // <- different;

    // 배열의 경우에는, 문자열이 똑같더라도 주소가 다르다. 
    // 배열 자체가 메모리를 확보하고 있고 거기에 복사해서 넣는 방식이다. 
    const char ar1[] = "I am a string!.";
    const char ar2[] = "I am a string!.";
    const char ar3[] = "I am a string!!.";      // <- all different

    // read only data, 주소가 낮은 방향이다. 
    printf("rodata low \t%llu %llu %llu %llu\n", (unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4, (unsigned long long)"I am a string!.");
    // 140701707513816 140701707513816 140701707513840 140701707513816
    // the same        the same        different       the same
        // 문자열을 주소처럼 사용하고 있다. 주소는 pt2와 pt3와 똑같다. 
        // 또 (unsigned long long)"I am a string!."의 값도 똑같다. 
        // 왜 이런 일이 일어날까?
        // 컴파일러 입장에서 똑같은 문자열의 주소를 세 번 잡을까?
        // 한 번만 잡을까? ==> 한 번만 잡는다. 
        // 한 곳에 저장해 놓고 여러 번 사용하자. 
        // 프로그램의 크기를 줄이는 것도 컴파일러의 중요한 임무 중 하나이다. 
        // 
        // 만약 pt2[0] = "H"; 이렇게 바꿔 버린다면, 어이없게도 
        // pt3[0]도 같이 바뀌어 버리는 문제가 발생한다. <= 허용이 안 된다. 
        // 그러므로 const로 미리 막아 버렸다. 
    printf("\n");

    // Stack은 높은 방향이다. (여기에서는 중간 정도? 교수가 중간이라고 함)  
    printf("Stack high \t%llu %llu %llu\n", (unsigned long long)ar1, (unsigned long long)ar2, (unsigned long long)ar3); // check address numbers!
    printf("\n");
        // 배열의 경우에는 문자열이 같더라도 주소가 모두 다르다.  

    // read only data와 stack 데이터의 주소가 자릿수가 다르다. 
    // windows os와 linux os의 주소 자릿수 경향성이 다르다.

    ///* Memory address check */

    ///* Local variables */

    // &pt2는 pt2라는 주솟값을 저장하는 변수에 대한 주소이다. 
    // 포인터 변수는 주소의 값을 저장하는 변수이다.
    // 포인터 변수도 변수이니까 당연히 주소가 있다. 
    // &pt2 자체는 stack에 저장이 된다.    
    printf("\nMemory address check\n");
    printf("Stack high \t%llu %llu %llu\n", (unsigned long long)&pt2, (unsigned long long)&pt3, (unsigned long long)&pt4);
    printf("\n");
    // 위 주소는 각각 32씩 증가한다.
    // &pt2, &pt3, %pt4의 값은 서로 다르다. 
    // 262023410488 262023410520 262023410552

    int i;
    printf("&i\n");
    printf("Stack high \t%llu\n", (unsigned long long) & i);
    printf("\n");

    /* Local variable in a function */
    test_function();
    printf("\n");

    /* Dynamic allocation */
    // 뒤에 다시 나온다. 
    // 메모리 주소가 대략 어디쯤 있는지 확인만 하라고 넣어 놨다. 
    // #include <stdlib.h> // malloc
    char* p5 = (char*)malloc(sizeof(char) * 100);
    printf("Heap middle p5\t%llu\n", (unsigned long long)p5);

    char* p6 = (char*)malloc(sizeof(char) * 100);
    printf("Heap middle p6\t%llu\n", (unsigned long long)p6);
    printf("\n");
    // stack은 '6444747*****' 등으로 주소가 비슷 비슷하다. 
    // 메모리가 전체 구조가 있고, 그것을 용도에 따라 나눠서
    // 레이아웃에 맞춰서 사용한다는 것을 확인할 수 있다. 
    // Heap 부분은 주소가 또 다르다. (21:00)   



    return 0;
}

void test_function() {

    printf("&j\n");
    int j;  // 지역 변수이므로 지역 변수 stack 쪽에 나올 것이다. 
    printf("Stack high \t%llu\n", (unsigned long long) & j);

}
