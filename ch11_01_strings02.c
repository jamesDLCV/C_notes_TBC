#include <stdio.h>

#define MESSAGE "A symbolic string constant"
#define MAXLENGTH 81

int main() {

    // 문자열을 선언하는 방법 세 가지
    // 1. 문자열 자체를 선언한다.
    // 2. 배열로 만든다. 
    // 3. 문자열에 대한 포인터로 선언한다.                        

    char greeting[50] = "Hello, and"" How are" " you" " today!";

    //char greeting[50] = "Hello, and How are you today!";
    // 위처럼 큰따옴표 사이의 간격이 있어도 된다. 동일하다. 
    // 문자열을 배열에 넣어서 초기화할 수 있다. 

    puts(greeting); // warning이 나오는 이유는 words에서와 동일하다. 

    printf("\" to be, or not to be\" Hamlet said.\n");

    printf("%s, %p, %c\n", "We", "are", *"excellent programmers");        
        // "are"의 주소는 뭘까?
        // 첫 글자가 저장된 주소이다. 
        // 문자열 앞에 indirection operator *를 붙이면 어떻게 될까?
        // "excellent programmers"의 주소는 이 문자열이 저장된 공간의 
        // 첫 번째 주소이다. 
        // 첫 번째 공간의 주소에 대해서 indirection을 하면 뭐가 되는가?
        // 'e'가 된다. 

    return 0;
}

// (예습) 
// 읽기 전용 메모리에 저장된 데이터의 값을 바꾸려고 시도하면
// 운영체제가 중단시킨다. 
// 배열은 읽기/쓰기가 모두 가능한 메모리를 사용한다. 
// 문자열 리터럴은 프로그램의 일부이기 때문에
// 읽기 전용 메모리에 저장되어 있다. 