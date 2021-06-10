#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//앞에서 다차원 배열을 사용했듯이 
//문자열의 배열도 만들 수가 있다. 
//문자열의 배열을 정의하는 방법
//문자열의 배열이 메모리에 어떻게 배치가 되어 있는지 
//디버거를 사용해서 메모리 구조를 들여다 보겠다. 

int main() {
    /* Arrays of Character Strings */

    // 문자열의 배열을 선언하는 방법은 두 가지가 있다. 
    // 1. char type의 포인터가 5개 있는 배열을 선언할 수 있다. 
    const char* mythings[5] = {
        "Dancing in the rain",
        "Couting apples",
        "Watching movies with freiends",
        "Writing sad letters",
        "Studying the C language",
    };

    // 2. 40개짜리 5개 배열, 2차원 배열을 선언할 수 있다.  
    char yourthings[5][40] = {
        "Studying the C++ language",
        "Eating",
        "Watching Netflix",
        "Walking around till dark",
        "Deleting spam emails"
    };

    const char* temp1 = "Dancing in the rain";
    const char* temp2 = "Studying the C++ language";

    printf("%s %s %s %u %u %u\n", mythings[0], *mythings, temp1, (unsigned)mythings[0], (unsigned)temp1, (unsigned)*mythings );
        // 이 두 주소는 동일하다. 
        // 포인터로 포인팅만 하고 있기 때문에, 
        // 컴파일러가 TEXT segment에 이것과 저것이 같으니까 같은 곳에 두자고 한 것이다.

    printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2);
        // 하지만 이 두 주소는 다르다.
        // temp2는 스택에 배열로서 메모리를 가지고 있다. 
        // 그러므로 별도의 메모리에 값들이 복사해서 들어간다.

    printf("%u %u\n", (unsigned)yourthings, (unsigned)&yourthings[0][0]);
        // yourthings[0] == &yourthings[0][0] == yourthings 주소 동일
    printf("\n");
    
    printf("%-30s %-30s\n", "My Things:", "Your Things:");
    for (int i = 0; i < 5; ++i)
        printf("%-30s %-30s\n", mythings[i], yourthings[i]);
    

    printf("\nsizeof mythings: \t%zd \nsizeof yourthings: \t%zd\n", sizeof(mythings), sizeof(yourthings));  
        // 20 (5 * 4bytes), 200 (5 * 40)
    printf("\n");    

    // 메모리에 어떻게 배치가 되는지 디버거로 들여다 보자. 
    // 완전히 붙어 있지는 않지만 덕지 덕지 붙어 있다. 
    // -30도 보인다. => 프로그램의 일부가 들어와 있다. 프로그램이 저장된 공간이다. 
    // 실행 파일에 저장되어 있던 프로그램이 실제로 실행되기 위해서는 
    // 먼저 메모리로 복사되어야 한다. 
    // yourthings[5][40]
    // 40칸이므로 yourthings의 메모리를 보면 초기화되지 않은 공간에 '.....'가 들어 있다. 
    // "Studying the C++ language"가 40칸(25 + 1(널캐) + 14),
    // "Eating"가 40칸, 등 총 5행이 40칸씩이다.
    // 
    // 26 글자(널 포함)이므로 14 글자는 '.'을 넣어 준다. => 15개의 '.'이다. 
    // 
    // "Dancing in the rain"은 메모리에 한 카피만 존재한다. 한 본만 존재하는 것이다. 
    // 그러므로 mythings[0]의 주소와 temp1의 주소가 같게 나오는 것이다. 
    //  
    // "Studying the C++ language"은 메모리에 두 카피가 존재한다.
    //
    // 문자열을 정의할 때, 포인터로 정의하는 것과 배열로 정의하는 것 두 가지가
    // 어떻게 차이가 나는지 또 한 번 중요한 측면을 살펴봤다. 
    // 
    // 문자열을 포인터로 정의하면 문자열을 한 군데만 두고 같이 사용하므로,
    // 메모리를 아낀다는 측면이 있다. 대신에 값을 바꿀 수가 없다. 
    // OS가 바꿀 수 없게 막아 버린다. 
    // 
    // 문자열을 포인터로 정의할 때와 배열로 정의할 때, 
    // 어떻게 차이가 나는지,
    // 메모리 구조도 살펴 봤고, 메모리 레이아웃의 성질에 대해서도 설명했다. 
    // 
    
    for (int i = 0; i < 100; ++i)
        printf("%c", mythings[0][i]);   // mythings[0]은 첫 주소.
    printf("\n");
    printf("\n");

    for (int i = 0; i < 200; ++i)
        printf("%d", (int)yourthings[0][i]);
    printf("\n");
    printf("\n");

    for (int i = 0; i < 200; ++i)
        printf("%c", yourthings[0][i]);
    printf("\n");
    printf("\n");

    // Not a good idea to take advantage of this property
    // 
    // 포인터와 배열이 메모리 구조에 어떻게 접근하는지 이해하고 있다면, 
    // 메모리에 있는 것들을 그냥 쭉 출력하고 있다는 것을 간단히 이해할 수 있다.
    // 종종 위와 같은 것을 사용할 수 있으나, 실무에서는 권장하지는 않는다. 
    // 효율성을 위해서 이런 것들을 체크해서 거르지 않는다.
    // 프로그래머를 믿으므로 알아서 이런 코딩은 하지 않을 것이라 생각한다.
    // 
    // 문자열의 배열의 사용법에 대해서 살펴 봤다. 
    // 앞에서 다룬 다차원 배열과 많이 유사하다.
    // 바로 앞 강의에서 메모리 레이아웃과 연관지어서
    // 문자열이 어디에 저장되는지까지 연관지어서 생각하면 좋겠다. 
    // 

    return 0;
}