#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>	// SetConsoleOutputCP()

// 텍스트 인코딩과 코드 페이지, Encoding, Code Page
// 
// C 프로그램으로 텍스트 입출력을 할 때 알아야 하는 것을 기본적인 것을 위주로 살펴 본다.
// 두 가지 개념 모두 실무에서 필요하다. 

int main() {
	const UINT default_cp = GetConsoleOutputCP();
	printf("%u\n", default_cp);

	int ch;
	FILE* fr, * fw;

	const char* in_filename = "원본.txt";	
	const char* out_filename = "사본.txt";

	unsigned long count = 0;

	if ((fr = fopen(in_filename, "r")) == NULL)	// Open a text file for reading
	{
		printf("Can't open %s\n", in_filename);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL) // Open a text file for reading
	{
		printf("Can't open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}

	SetConsoleOutputCP(CP_UTF8);	// UTF-8 mode

	while ((ch = fgetc(fr)) != EOF)	
	{		
		fputc(ch, stdout);		// same as putchar(ch);
		fputc(ch, fw);
		count++;
	}

	fclose(fr);
	fclose(fw);

	SetConsoleOutputCP(default_cp);	// ISO 2022 Korean

	printf("FILE %s has %lu characters\n", in_filename, count);
	printf("Copied to %s\n", out_filename);

	printf("한글 출력 확인");

	return 0;
}

// const char* in_filename = "원본.txt";
// const char* out_filename = "사본.txt";
// <= 이렇게 파일 이름을 한글로 사용하고 있다. 
// 그 외는 앞 강좌의 예제와 거의 동일하다. 
// 명령 줄 인수를 사용하지 않도록 코드를 약간 변형시켰다. 
// 
// 탭에서 파일 이름에 hover over한 후 우클릭 > (click) Open Containing Folder,
// 이 폴더에 "원본.txt" 파일을 생성한다. 내용은 아무 것이나 괜찮지만 '한글 + 영어'로 한다.
// 이 txt 파일의 우하단 부분을 보면, Windows(CRLF)라고 적혀 있다. 
// <= 운영체제마다 각라인의 끝을 나타내는 기호가 다르다.
//    윈도우즈에서는 \r과 \n 두 가지를 사용한다. 
//	  CR은 carriage return, 컴퓨터 복귀, 
//			(타자기를 칠 때 다음 라인으로 넘어가기 위해 쭉 미는 행위). 
//    LF는 line feed, 
//		라인 피드(모니터 커서의 위치나 프린터 인쇄 위치를 한 줄 아래로 내리는 일)
//    라인의 끝을 나타내는 기호로 CRLF를 사용한다는 뜻이다. 
// 
// txt 파일의 우하단을 보면, UTF-8이라고 적혀 있다. 
// <= 이것이 Encoding 방식이다. 
// 
// "원본.txt" 파일 안에는 한글과 영어를 같이 써 준다. 
// 실행을 하면, 영어는 제대로 출력이 되나, 한글은 모두 깨져 있다. 
// 
// 왜 그럴까?
// 텍스트 파일도 결국은 binary로 저장이 된다. 
// 하드 디스크라는 장비 자체가 데이터를 저장할 때, 이진수로 저장한다. 
// 이진수로 저장돼 있는 것을 텍스트 파일로 읽어 들이도록 
// 어떠한 규칙을 정해 놨다. 
// 이진수를 어떠한 숫자로 바꾸고, 그 숫자가 어떠한 문자에 대응된다라는 식으로, 
// 인간이 이해할 수 있는 문자로 decoding하게 된다. 
// encoding과 decoding을 하면서 저장하고 출력을 하는데, 
// 이때 (화면에 표현할 때) decoding하는 표를 잘못 사용한 것이다. 
// 
// 실행을 한 후 다시 (click) Open Containing Folder를 해 보면,
// "사본.txt"가 저장이 돼 있다.
// 이 사본을 열어 보면, 제대로 저장이 돼 있다. 
// 콘솔 출력을 할 때는 문제가 생겼는데, 
// 파일(사본txt)로 저장할 때는 제대로 저장이 된 것이다. 
// 
// 왜 그럴까?
// 원본에서 이진수를 사용하기 때문에, 이진수처럼 읽어 들였다.
// 화면에 출력할 때 깨진 것은 그 읽어 들인 숫자들이 어떠한 문자에 대응이 되는지, 
// 대응되는 표를 잘못 사용해서 글자가 깨지는 것이다. 
// 하지만 저장을 할 때는 그 데이터를 그대로 저장하고, 
// 저장한 데이터를 정해져 있는 제대로 된 encoding으로 여니까, 제대로 보이는 것이다.
// 
// 실험을 하나 해 보자.
// "원본.txt"를 열고 다른 이름 저장하기를 누른 후 인코딩을 'ANSI'로 한 후, 
// 이름을 "원본_ANSI.txt"로 저장한다. 
// 
// const char* in_filename = "원본_ANSI.txt";	
// <= 읽어 들일 파일 이름을 "원본_ANSI.txt"로 바꾼다. 
// const char* out_filename = "사본_ANSI.txt"
// <= 사본도 _ANSI를 붙여 준다.
// 
// 출력을 하면, 화면에 한글이 제대로 나온다. 
// 이 콘솔 창이 decoding되는 방식이 ANSI로 encoding된 것과 동일하기 때문에, 
// 제대로 출력이 되는 것이다. 
// 
// 텍스트 파일 입장에서는, 
// "원본.txt" 파일과 "원본_ANSI.txt" 파일은, encoding 방식이 다르다. 
// 
// encoding 방식이 다른데 텍스트 파일을 열면 왜 똑같은가? 
// 그것은 메모장 프로그램이 해 주는 것이다. 결국은 파일에 저장될 때는 binary이다. 
// 
// 실무에서 데이터 양이 많거나 빠르게 읽고 써야 할 때는 binary 위주로 사용하게 된다. 
// 
// encoding 방식을 ANSI로 바꾸니까 C에서 사용하는 decoding 방식과 잘 맞아서,
// 한글이 제대로 출력이 되었다. 
// 
// "사본_ANSI.txt"는 ANSI로 저장이 되었다. 운영체제가 처리를 해 줬다. 
// 
// 이 프로그램이 데이터를 해독하는 표가 잘못 선택돼서 이상한 글자가 출력이 되었다.
// <= decoding 방식이 안 맞는 것이다. 
// <= 이를 맞춰 주는 방법으로 첫 번째는 위와 같이 텍스트 파일을 저장할 때, 
//	  encoding 방식을 바꿔 주는 것이다. (ANSI로 바꿔 줬다)
// <= 이를 프로그램에서 맞춰 줄 수도 있다. 
// 
// ANSI를 사용하지 않고 프로그램에서 맞춰 주는 방식을 살펴 보자.
// #include <windows.h>	// SetConsoleOutputCP() 
// <= include를 해 줘야 한다. 이는 윈도우즈에서만 가능하다.
// SetConsoleOutputCP()에서 CP는 code page의 약자이다. 
// 이 페이지에서는 이 code를 사용한다는 개념이다. 
// 화면에 이러한 데이터를 뿌려 줘야 하는데 이 숫자가 어떠한 데이터에 대응이 되는지
// 그 표를 결정해 주는 것이다 .
//  
// const UINT default_cp = GetConsoleOutputCP(); 를 사용하면, 
// 현재 사용하고 있는 CP가 뭔지 알 수가 있다. 
// printf("%u\n", default_cp); 로 출력해서 볼 수 있다. 
// 
// 밑으로 쭉 내려가서, 
// SetConsoleOutputCP(CP_UTF8);	// UTF-8 mode
// <= 이렇게 UTF-8으로 바꿔 준다. 
//    콘솔 창에 문자를 출력할 때 사용하는 코드 페이지를 
//    텍스트 파일이 encoding돼 있는 UTF-8을 사용하겠다.  
//    즉 파일이 encoding된 방식과 콘솔 창에 뿌려 주는 방식, 
//    이 두가지를 똑같이 맞춰 주겠다는 의미가 된다. 
// 
// SetConsoleOutputCP(CP_UTF8);	을 해 준 후 실행을 시키면,
// 콘솔 창 맨 위에 949가 출력된다. 이는 default_cp이다. 번호가 949이다. 
// 한글과 영어가 모두 제대로 출력이 되는데, 
// 아랫 부분의 'Copied to 纻.txt'에서와 같이 프로그램 안에 있는 한글이 깨져서 나온다.
// printf("한글 출력 확인"); 이 부분도 깨져서 제대로 출력이 되지 않는다. 
// 
// CP_UTF8 <= UTF8으로 인코딩돼 있는 텍스트 데이터를 화면에 출력할 때는  
//            UTF8 CP (code page)를 사용한다. <= 148 라인에 대한 설명임.
// 이를 실행한 후,  
// SetConsoleOutputCP(default_cp);	// ISO 2022 Korean
// <= 이것을 실행하면 모든 한글이 정상적으로 출력이 된다. 
// <= 프로그램 자체에서 사용하는 기본 모드로 돌아가서, (default_cp에 저장을 해 놨다)
//	  (default_cp를 다시 사용해서 돌아가서)
//    출력을 하면, 프로그램 안에 있는 한글도 정상적으로 출력이 된다. 
//  
// 여기까지 텍스트 파일의 encoding 개념에 대해서 
// 노트 패드 위주로 살펴 봤고,
// 한글이 깨지는 현상을 해결하기 위해서, 
// 코드 페이지 (CP)를 이용해서, 
// 텍스트 문서가 인코딩된 방식과 화면에 출력하는 방식 
// 이 두 가지를 맞춰 주는 방법에 대해서 간단하게 살펴 봤다. 
//
// GetConsoleOutputCP function
//  Retrieves the output code page used by the console associated with the calling process.A console uses its output code page to translate the character values written by the various output functions into the images displayed in the console window.