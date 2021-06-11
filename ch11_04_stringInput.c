#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* Creating Space */

    //char* name = "";    // Error at RUN-TIME
                          // 이렇게 하면 안 된다. 왜인지는 앞에서 설명했다.
                          // 포인터로 문자열을 정의하면, 값을 바꿀 수가 없다 
    //*char name[128];
    char name[128];
    int result = scanf("%s", name); // name 앞에 &가 안 붙은 이유는,
                                    // 배열 이름 name이 포인터와 비슷하게 
                                    // 작동하기 때문이다. 
                                    // 인수로 들어가는 게 포인터여야 한다.

    /*
        scanf() vs gets()
        scanf() reads one word, 한 단어만 읽는다.
        gets() reads one line and removes \n and add \0
                    한 줄을 통째로 다 읽는다. 줄바꿈 문자 제거. \0 추가
    */

    char words[STRLEN] = "";    // Warning without initialization
                                // 초기화를 안 해 주면, warning이 뜨므로
                                // "" 해 줬다.     
        // parameter로 받아 들이는 자료형이 char * str (char의 포인터)이다.
        // 문자열로 사용할 수 있는 배열이다. 
        // 주솟값만 넣어라 혹은 포인터만 넣으라는 말이 아니라,
        // 배열을 대표하는 주솟값을 넣어라는 의도로 만들어진 함수다. 

    printf("gets(words): ");
    gets(words);        // gets receives pointer. 입력 받는다.
                        // No idea when string ends.
                        // 포인터를 argument (인수)로 넣어 줘야 한다.
                        // 배열의 이름도 포인터이기 때문에, 
                        // 배열이 가지고 있는 메모리의 첫 주소를 넣어 준다.
        // gets() 함수로서는, 포인터 하나만 argument로 받아 가지고는 
        // 자기가 사용할 수 있는 메모리의 크기가 얼마나 되는지 알 수가 없다.
        // 메모리 공간이 어디에서 시작하는지만 알고, 
        // 어디에서 끝나는지는 모르는 형태가 된다. 
        // 이것은 포인터 하나만을 argument로 받는 함수들이 
        // 공통적으로 겪는 일이다. 
        //   
    printf("gets_s(words, sizeof(words)): ");
    gets_s(words, sizeof(words));   // C11에서 gets()의 단점을 보완했다. 
        // 포인터와 사이즈를 둘 다 arguments로 요구하는 함수를 추가했다.
        // 이 함수를 사용하는 것을 권장한다. 
        // 하지만 C11이 지원되지 않는 C99에서는 사용할 수 없다. 

    int result2 = scanf("%s", words);

    printf("START\n");
    printf("%s", words);    // there is no '\n' at the end
                            // 자동 줄바꿈은 안 해 준다.
    putchar('\n');
    printf("puts() adds '\\n' at the end.\n");
    puts(words);            // puts() adds \n at the end. 
                            // 출력한다. 
                            // 자동 줄바꿈도 해 준다. 
                            // gets_s()와 puts()는 쌍으로 이뤄진 함수이다.
    puts("END.");

    // TODO: try char words[5];
    // STRLEN 81로 배열의 사이즈를 크게 잡아 줬다. 
    // 만약 STRLEN이 5인데, 입력된 문자열이 사이즈 5를 넘어가면 어떻게 될까?
    // RUN-TIME ERROR가 발생한다. 
    // gets_s() 함수를 사용해도 마찬가지로 RUN-TIME ERROR가 뜨게 된다. 

    /* fgets() and fputs() */
    char words2[STRLEN] = "";
    fgets(words2, STRLEN, stdin);    // does NOT remove \n.
        // stdin 자리에 파일에 대한 포인터를 넣어 줄 수 있다.
        // 원래는 파일을 입력 받을 때 사용하는 함수이다. 
        // stdin을 적어 주면, 콘솔 입력도 받을 수 있다. 
        // 파일 입력은 뒤에서 다시 다룬다. 
        // 
        // fgets() 함수를 사용하면, 런타임 에러를 방지할 수 있다. 
        // fgets() 함수는 읽어들이는 데이터가 언제 끝날지 모른다고 상정하므로
        // 사이즈보다 큰 크기의 값이 들어와도 문제가 생기지 않는다. 
        // gets() 함수보다 안정적으로 사용할 수 있다. 
        // 
        // fgets() 함수는 '\n' 줄바꿈 기호를 제거해 주지 않는다. 
        // 파일 입출력 할 때는 줄바꿈을 제거해 주지 않는 게 좋다. 
        // 입력 받으려는 파일 내용을 곧이곧대로 읽어들여 주므로 좋은 것이다. 
        // 
        // stdin은 stdio.h 해더 파일에 정의돼 있다. 
        // stdin을 넣어 주면, 원래 파일 입력에 사용되는 함수를 
        // 콘솔 string 입력에도 사용할 수 있게 해 준다. 
        // 
        // 하지만 콘솔 창에서 입력을 받을 때에는 마지막의 '\n' 줄바꿈을
        // 제거해 주지 않으므로 약간 번거로운 일이 될 수도 있다. 
        // 
        // 디버거를 찍은 후, fgets(words, ....)의 words에 마우스를 갖다대면,
        // '\n'이 그대로 남아 있는 걸 볼 수 있다. 
        // 
        // '\n'을 찾아서 제거하고 싶을 때는 어떻게 하는가?

    // TODO: replace '\n' with '\0'
    // 아래와 같이 하면, 줄바꿈 기호를 제거해 줄 수 있다. 직접 짜 봐라. 
    int i = 0;
    while (words[i] != '\n' && words[i] != '\0')
        i++;
    if (words[i] == '\n')   // '\0'이면 '\0'으로 놔 둔다. 
        words[i] = '\0';
    printf("\n");

    // fputs()
    // 콘솔 창으로 출력을 한다. 
    fputs(words, stdout);           // does NOT add \n
        // 파일을 출력할 때는 군더더기 없이 필요한 내용만 저장된 파일을 
        // 출력하는 것이므로, 맨 뒤에 줄바꿈 기호 '\n' 같은 것을 
        // 출력하지 않는다. 
        // puts()는 화면에 출력할 때 프로그래머의 편의를 위해 '\n'을
        // 자동으로 추가해 줬다. 
        // fgets()와 fputs는 파일을 읽어오고 출력할 때 사용하는 함수이지만,
        // stdin과 stdout을 통해서 콘솔 입출력에도 사용할 수 있다. 
        // 즉, 표준 입출력에도 사용할 수 있다. 
        // 표준 입출력에 대해서는 뒤에서 다시 다룬다. 
        //
    fputs("END", stdout);
    printf("\n");

    /* Small array */
    // 입력 받으려고 하는 메모리 공간이 작은 경우
    // 입력 받은 데이터를 저장할 공간이 작은 경우
    // 
    char small_array[5];
    puts("Enter long strings:");

    fgets(small_array, 5, stdin);   // FILE *_Stream
                                    // 4 글자만 입력 받는다. 
                                    // 마지막에는 \0이다. 
                                    // '\0' 포함 총 5 글자를 입력 받는다.
                                    // 런타임 에러가 발생하지 않는다. 
        // fgets에 마우스를 갖다 대면, 
        // char pointer를 인자로 받고 있다. 
        // end of file을 만났다. 파일 입력을 받을 경우에는 end of file을
        // 만날 경우가 대부분일 것이다. 끝이 있는 파일로부터 입력을 받게 되므로.
        // 모든 파일에는 끝이 있다. 
        // UEF(?)를 만날 경우에는 null-character를 return하게 된다. 
        // 
    putchar('\n');
    fputs(small_array, stdout);     // no '\n', 줄바꿈 안 된다.  
    printf("\n%p\n", small_array);
    printf("\n"); 

    return 0;
}

// 문자열을 입력 받을 때 주의해야 할 점은, 
// 일단 입력받을 공간을 확보한 후에 그 공간에 입력을 받아야 한다. 
