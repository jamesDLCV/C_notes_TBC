#include <stdio.h>

void test_function();

int main() {

    const char* pt2 = "I am a string!.";        // the same as pt3
    const char* pt3 = "I am a string!.";        // the same as pt2
    const char* pt4 = "I am a string!!!!!!.";   // <- different;

    const char ar1[] = "I am a string!.";
    const char ar2[] = "I am a string!.";
    const char ar3[] = "I am a string!!.";      // <- different

  
    /* Array Vs. Pointer (continued) */

    // ar1++;   // Error
                // ar1은 포인터가 아니라 배열의 이름이다. 
    pt2++;      // Ok
                // 증가 연산자 때문에 한 칸 앞으로 가는 바람에 
                // 한 글자가 날아갔다. 
    printf("pt2++\n");
    puts(pt2);  // Check the first character
        // 증가 연산자 때문에 한 칸 이동하는 바람에 한 글자가 날아갔다.
        // am a string!.
    putchar('\n');


    /* Array and Pointer Differences */

    char heart[] = "I love Kelly!";         // 배열로 정의하였다.
    const char* head = "I love Kelly!";     // 포인터로 정의하였다.

    printf("heart[i]\n");
    for (int i = 0; i < 8; i++) 
        putchar(heart[i]);      // Note: putchar()
                                // parameter가 int이다. 
                                // putchar()은 argument로 int를
                                // 하나 받아들이게 돼 있다. 
                // 아스키 코드를 넣으면, 문자를 확인해서 출력해 준다. 
        // 출력) I love
    putchar('\n');

    // 포인터를 배열인 것처럼 사용
    printf("\nhead[i]\n");
    for (int i = 0; i < 8; ++i)
        putchar(head[i]);       // Note: putchar()
    putchar('\n');


    // pointer addition
    // 
    // 배열을 포인터 연산인 것처럼 사용할 수도 있다. 
    printf("\n*(heart + i) <= pointer addition\n");
    for (int i = 0; i < 8; ++i)
        putchar(*(heart + i));
    putchar('\n');

    // 포인터 연산 
    printf("\n*(head + i)\n");
    for (int i = 0; i < 8; ++i)
        putchar(*(head + i));
    putchar('\n');
    putchar('\n');

    // 전체 문자열 출력 
    while (*(head) != '\0')     // 널캐릭터를 만날 때까지 계속 출력
        putchar(*(head++));
    putchar('\n');

    head = heart;       // pointer인 head에다가 배열의 이름인 heart를
                        // 대입할 수 있다. 
                        // 배열의 이름은 포인터와 호환이 되도록 
                        // 컴파일러가 허용을 해 주고 있다. 
                        
    // heart = head;    // Error
                        // 배열의 이름에 포인터를 대입할 수는 없다. 

    // Cannot chage heart. Can change the elements of heart
    heart[7] = 'H';     // Note: character
                        // 원소를 바꿀 수 있다. 
    putchar(*(heart + 7));  // putchar(heart[7]); 
    putchar('\n');

    *(heart + 7) = 'K'; // 'H'로 바꿨다가 다시 'K'로 바꿨다. 

    putchar(*(heart + 7));
    putchar('\n');
    
    // 배열을 통해서는 원소를 바꿀 수 있으나, 
    // 포인터를 통해서는 원소를 바꿀 수 없다. 
    // head[7] = 'C';   <= Error!
    // 
    // 포인터는 자기가 가지고 있는 메모리 공간, 그러니까 스택에 있는 메모리를
    // 가리키는 것이 아니고, TEXT segment에 있는 메모리를 가리키는 건데,
    // TEXT segment에 올라가는 데이터는 프로그램에 담겨 있는 것이기 때문에,
    // 우리가 변경할 수 없도록 운영체제가 막아 버린다. 
    // 

    char* word = "Goggle";  // 대표 포인터를 이용해서 정의하는 경우에는
                            // 앞에 const를 붙여서 막아 두는 것을 권장한다.
    //word[2] = 'k';        // Run-time error!
                            // exited with code -1073741819.
    puts(word);

    // Note: const char * word = "Goggle"; is recommended
    // TEXT segment에 있으므로 변경할 수가 없으므로 const로 아예 막아 둔다.

    const char* str1 = "When all the lights are low, ...";
    const char* copy;

    copy = str1;        // 포인터를 복사하고 있다. 
                        // 즉 주소를 복사하는 것이다. 
        // 내용물을 통째로 다른 메모리 공간으로 옮겨서 복사하는 게 아니라, 
        // 그냥 TEXT segment에 있는 주소만 옮겨 가고 있다. 

    printf("%s %p %p\n", str1, str1, &str1);
    printf("%s %p %p\n", copy, copy, &copy);

    // str1과 copy는 동일한 값이 출력된다. 
    // 하지만 &str1은 스택에 저장되므로 주소가 다르다. 동떨어져 있는 주소다.
    // "When all thelights are low, ..." 이 문자열은 TEXT segment에 있다.
    // str1과 copy는 모두 TEXT segment에 저장돼 있는 
    // 문자열을 가리키고 있다. 

    // Note: strcpy(), strncpy()
    // 문자열을 한 글자씩 읽어서 복사한 것처럼 사용하려면 strcpy() 함수 사용.

    return 0;
}

// 스트링, 문자열을 사용할 때, 
// 문자열이 배열로 사용되는 것과, 포인터로 사용되는 두 가지가 
// 다르다는 것을 이해하라. 
// 문법적으로 이렇게 다르다는 것에 추가로, 
// 내부적으로 메모리 구조가 이렇게 사용되기 때문에, 
// 실행할 때 메모리가 이렇게 사용되기 때문에, 
// 결과적으로 이렇게 작동이 될 수밖에 없구나라고 이해하면 더 좋다. 