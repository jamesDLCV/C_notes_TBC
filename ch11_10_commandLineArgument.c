#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 명령줄 인수에 대해서 살펴 본다. 
// 지금까지는 main() 함수의 parameter가 없었다. 
// 빈칸으로 두거나 void를 넣어 줬다. 
// 아래는 매개변수가 두 개가 생겼다. 
// 첫 번째 매개변수는 정수형이고, 두 번째 매개변수는 
// char 포인터 배열이다. <= 문자열의 배열이다.  
// argv[]로 들어오는 문자열이 몇 개인지가, argc에 담겨서 들어오게 된다. 
// 

int main(int argc, char* argv[]) {
    int count;
    printf("The command line has %d arguments:\n", argc);

    // argc만큼 돌면서 
    // argv[]를 출력하고 있다. 
    for (count = 0; count < argc; count++)
        printf("Arg %d : %s\n", count, argv[count]);
    printf("\n");

    return 0;
}

// main() 함수를 호출할 때, 매개변수 자리에
// 어떤 argument들이 들어와야 되는데, 그걸 누가 넣어 줄까?
// 운영체제가 넣어 준다. 
// 운영체제가 main() 함수의 매개변수가 없는 것들도 잘 실행을 시켜 줬다.
// 갑자기 위와 같은 것이 생겼는데 잘 실행을 시켜 줄까?
// 뭘 넣어 줄까? 궁금하게 생각할 것이다. 
// 프로그래머 혹은 사용자가 이 프로그램을 실행시킬 때, 
// arguments들을 넣어 줄 수가 있다. 
// 강의 아주 앞 부분에서, 우리가 실행 파일을 컨맨드 라인에서 
// 직접 실행하는 것을 공부했다. 
// exe 파일을 찾아서 컨맨드 라인에서 컨맨드 프롬프트에서 직접 실행을 시켜야
// 하기 때문에, 일단 빌드부터 해야 한다. 
// 위 코드를 빌드하면, 어디 어디에 exe 파일이 생겼다는 메시지가 뜬다. 
// tools > Visual Studio Command Prompt  <= 이걸 사용하는 게 제일 편하다.
// 2019에 위가 없다. 
// tools > Commnad Line > Developer Command Prompt
// 실행 파일의 위치를 찾아서 직접 실행시키려고 하는 것이다. 
// E:\temp_03_C++\TBC______\Debug\ch11_01_strings03.exe
// ch11_01_strings03.exe <= 여기에서는 이 파일을 찾아야 한다. 
// 
// 이 실행 파일이 생기는 규칙이 있다. 
// ch11_10_commandLineArgument, 이 프로젝트를 우클릭한 후 
// properties를 클릭한다. 
// 그리고 Configuration Properties > General을 클릭한다. 
// 
// Output Directory에 출력이 되는 것이다. $(SolutionDir)$(Configuration)\
// Solution 디렉토리 밑의 Configuration 밑에 저장이 되는 것이다. 
// $로 경로명을 구분해 주고 있다. 
// $(SolutionDir)은 뭐뭐.sln 파일이 있는 그 위치다. 
// 그 밑의 Configuration은 디버그냐 릴리즈냐, x64의 디버크냐, x64의 릴리즈냐
// 등등 이런 것을 의미한다. 
// 
// Intermediate Directory는 빌드할 때 중간에 사용되는 파일들이 
// 저장되는 위치다. 
// Target 네임이 실행 파일의 이름인데, 실행 파일의 이름이 프로젝트 이름과
// 동일하다. 
// 명령줄 인수와는 상관이 없지만, 위 사항도 알아 두면 좋다. 
// 
// Configuration Type이 Application (.exe)이다. 
// 그래서 .exe 파일이 생기고 있다. 
// 프로젝트 창에서 ch11_10_commandLineArgument.c 파일을 선택한 후, 
// 코딩 창 ch11_10_commandLineArgument.c을 우클릭한 후, 
// Open Containing Folder를 클릭한 후,
// .sln이 있는 상위 폴더로 가서, Debug 폴더로 가면, 
// ch11_10_commandLineArgument.exe 파일을 찾을 수 있다. 
//
// command prompt에서 실행시키는 가장 쉬운 방법은,
// ch11_10_commandLineArgument.exe를 그냥 drag & drop 한 후 엔터를 친다.
// 
// The command line has 1 arguments:
// Arg 0 : E:\temp_03_C++\TBC______\Debug\ch11_10_commandLineArgument.exe
// 이렇게 뜬다. 
// 
// setting해 놓은 그대로 뜬다. "Arg 0 ~ "
// (7:40~)
// string으로 Argv의 0, 문자열이 나온다. 
// 그 문자열이 뭐냐? 실행 파일의 이름이다. 
// 실행 파일의 경로하고, 실행 파일의 이름이 들어온다. 
// count가 0일 때, string으로..
// 
// 배열이니까 여러 개가 들어올 수도 있지 않을까? 
// 위화살표를 누르면 방금 전에 실행한 명령을 다시 불러올 수 있다. 
// 불러온 후 그 뒤에 hello world 1234 3.14 와 같이 넣고 엔터를 쳐 보자. 
// E:\temp_03_C++\TBC______>E:\temp_03_C++\TBC______\Debug\ch11_10_commandLineArgument.exe hello world 1234 3.14
// 
// 결과는 아래와 같다. // 
//The command line has 5 arguments:
//Arg 0 : E : \temp_03_C++\TBC______\Debug\ch11_10_commandLineArgument.exe
//Arg 1 : hello
//Arg 2 : world
//Arg 3 : 1234
//Arg 4 : 3.14
// 
// 리눅스 뒤에는 .exe가 붙지 않는다. 
// 실행시킬 때 이 뒤에 붙여주는 arguments들을  
// int main(int argc, char* argv[])로 받아 주는 것이다. 
// 
// 운영체제가 우리가 작성한 프로그램을 실행시킬 때, arguments를 보내주는 것이다.
// 원리 자체는 간단하다. 사용하는 용법도 간단하다.
// int main(int argc, char* argv[]) <= 이 규칙은 지켜야 한다. 
// main() 함수를 만들 때, 매개변수가 없거나, 두 개가 있거나 하는 방식으로
// 프로그래밍을 하도록, C 언어가 운영체제와 약속을 하고 있는 것이다. 
// 아무 것도 없다면, command arguments가 뭐가 들어오든 관심 없다는 뜻이다.
// 
// 어떻게 사용하는지, 운영체제가 넣어 준다는 개념, 그것들을 사용할 때, 
// 문자열로 받아서 사용할 때, 어떻게 쓸 수 있는지는 이해가 갔을 것이다. 
// 
// 그런데, 이런 게 어디에 쓸모가 있는 것인가?
// 다음 강의에서 명령줄 인수를 
// 좀 더 쓸모 있게 사용하는 방법들에 대해서 살펴 볼 것이다. 
// 


