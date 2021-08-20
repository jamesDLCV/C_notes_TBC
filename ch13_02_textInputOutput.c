#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 텍스트 파일 입출력 예제
// 
// 간단한 텍스트 입출력 파일을 만들어 보자. 
// 
// 앞에서 텍스트 파일 읽기를 공부했다. 
// 이 프로그램을 확장해서 읽기도 하고 쓸 수도 있는 프로그램을 작성해 보자. 
// 그러니까 텍스트 파일을 복사해 주는 프로그램을 만들어 보는 것이다.
// 
// 읽기만 할 수 있는 프로그램을 확장하여 출력도 할 수 있게 해 보자. 

int main(int argc, char* argv[]) {
	int ch;
	FILE* fr;	// TODO: file pointer to write

	/*
	typedef struct _iobuf
	{
		char*	_ptr;
		int _cnt;
		char*	_base;
		int _flag;
		int _file;
		int _charbuf;
		int _bufsiz;
		char*	_tmpfname;
	} File;	
	*/

	//const char* out filename = "output.txt";	//TODO: Use this

	unsigned long count = 0;

	if (argc != 2) 
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL)	// Open a text file for reading
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/*
		fopen mode strings for text files
		- r: reading
		- w: creating-and-writing or over-writing
		- a: appending or creating-and-writing
		- r+: both reading and writing
		- w+: reading and writing, over-writing or creating
		- a+: reading and writing, appending or creating
	*/

	//TODO: open file to write with "w" mode string

	while ((ch = fgetc(fr)) != EOF)	// getc(fr)
	{
		// putc(ch, stdout);	// same as putchar(ch);
		fputc(ch, stdout);

		// TODO: use fputs() to write a file stream!

		count++;
	}

	fclose(fr);
	// TODO:


	return 0;
}

// 위 int main(int argc, char* argv[])는 명령 줄 인수로 
// 파일 이름을 읽어 들이고 있다. 
// 
// int ch; 버퍼로부터 한 글자씩 읽어 들일 수 있도록 변수를 선언했다. 
// 
// FILE* fr; File에 대한 포인터라고 생각할 수도 있지만, 
// 엄밀히 말하면, File을 처리할 때, 필요한 데이터의 묶음에 대한 포인터이다.  
// 데이터의 묶음을 structure 구조체라고 한다. 
// 
// 파일을 처리할 때 필요한 여러 가지 데이터의 묶음을 
// File이라는 자료형이 있는 것처럼 사용할 수 있게 해 주는 것이다. 
// 
// FILE* fr; 그 FILE에 대한 포인터를 선언했다. 
//			 파일 자체에 대한 포인터라고 생각할 필요는 없다.
// 하지만 프로그래밍을 하다 보면 FILE 자체의 포인터인 것처럼 느끼면서 프로그래밍하게 된다. 
// 왜냐하면 나머지는 C언어와 운영체제가 알아서 해 주기 때문이다. 
// 마치 이 fr 포인터가 파일 자체에 대한 포인터인 것처럼 fr에다가 쓰고, 
// fr로부터 읽어 들이고, 여타 작업을 하는 것처럼 느끼게 돼 있다. 
// 
// FILE* fr; File이라는 자료형에 대한 포인터를 선언했다. 
// 
// unsigned long count = 0; 는 몇 글자인지 카운팅하려고 선언한 변수이다. 
// 
// if (argc != 2) 
// {
//  	printf("Usage: %s filename\n", argv[0]);
//  	exit(EXIT_FAILURE);
// }
// <= 명령줄 인수로부터 파일 이름을 받아들이고 있다. 
//    명령줄 인수가 비어 있으면, "Usage: %s filename\n" 이렇게 이름을 입력하라고
//    경고 내지는 사용법을 알려 주고 있다. 
//    이런 식으로 명령 줄 인수의 사용법을 알려 주는 것이 C 프로그래밍에서는 
//    일반적인 방식이다. 
// 
// 	if ((fr = fopen(argv[1], "r")) == NULL)	// Open a text file for reading
//  {
//  	printf("Can't open %s\n", argv[1]);
//  	exit(EXIT_FAILURE);
//  }
// <= argv[1] 은 파일 이름의 입력이 제대로 들어왔다면, 
//    (문자열로 입력을 받아 들였다면) 
//    파일을 열어라. 
// 그러면 이 fopen() 함수는 파일 포인터를 리턴해 준다. (리턴해서 fr에 대입한다)
// 파일 자체에 대한 포인터를 받아 오는 것처럼 얘기를 하지만, 
// 엄밀하게 말하면, 파일을 처리할 때 필요한 데이터의 묶음에 대한 포인터를 받아 오는 것이다.
// 
// 파일을 처리하려면, (파일에 어떠한 데이터를 저장하려면)
// 운영체제가 하드디스크에게 명령을 내린다. (이러한 데이터를 저장하라)
// 그러면 하드디스크에 내장돼 있는 소프트웨어가 작동을 해서 
// 하드웨어에 있는 여러 가지 부속품을 이용해서 데이터를 저장하기도 하고, 
// 읽어 오기도 하는 일련의 과정이 일어난다. 
// 
// fopen(argv[1], "r")은 argv[1]에 저장돼 있는 이름을 갖는 파일에다가 
// "r" write 하겠다라는 것을 fopen()이라는 간단한 함수로 시작할 수 있다. 
// 
// if ((fr = fopen(argv[1], "r")) == NULL)	
// <= fopen() 함수가 리턴해 주고, 그 리턴한 포인터가 fr에 저장된다. 
//    포인터 fr이 NULL이면 (파일을 열지 못했다는 의미이다),
//    (stream을 열지 못했다는 뜻이다)
//    할 수 있는 게 없다. exit(EXIT_FAILURE);으로 끝낸다. 
// 
//    fopen 우클릭 > Go To Definition을 찍어서 가 보면, 
//    <= _In_ FILE* _Stream, 결국은 스트림이다. 
//       스트림이라는 용어 하나로 입출력 스트림, 파일 스트림 이렇게 일원화돼 있다.
//       한 가지의 데이터 통로가 있는 것처럼 처리를 할 수 있도록 
//       C언어가 제공해 준다. 
// 
//    printf("Can't open %s\n", argv[1]);로 열지 못했다는 것을 사용자에게 알려 준다.
// 
//    이렇게 NULL이 반환되는 경우는 많지 않지만 다음의 경우가 있다.  
//    - 하드 디스크가 꽉 차 버렸다. (기타 하드웨어와 관련된 경우)
//    - 읽기 전용으로 만들어진 파일에 강제로 쓰려고 한다. 
//    - etc...
// 
// fopen mode strings for text files		
//	"r" 이 문자를 fopen의 mode string이라고 부른다. 문자열이다. 
//		한 글자가 아니라 문자열이다. 
//  위에서 여섯 가지를 적어 놨지만, 몇 가지 더 있다. 
//  (바이너리 모드의 것이 더 있으나 이는 다른 강의에서 다룬다)
// 
// fr = fopen(argv[1], "r")의 "r" 자리에 r을 넣으면 reading이다. 
// W은 writing을 해야 하는데 이런 이름을 가진 파일이 없다면 먼저 파일을 만들고 쓴다. 
//     파일이 이미 있다면, 그 파일에 덮어 쓴다. 
//     <= 그 파일이 없었던 것처럼 지워 버리고 다시 쓴다. 
//        기존의 내용이 모두 사라져 버리므로, 좀 위험할 수도 있다. 
// 
// a는 뒤에다가 덧붙인다. 파일이 이미 존재할 경우에는 이미 있는 내용 뒤에 추가가 된다. 
//     파일이 없다면, 파일을 새로 만들고 writing한다. 
// 
// 동일한 이름의 파일이 존재한다면, w 모드는 덮어 쓰고, r 모드는 추가해 준다.
// 
// r+는 reading과 writing이 둘 다 된다. 파일을 읽기도 하고 쓰기도 한다.
// w+는 reading과 writing이 둘 다 된다. 덮어 쓰거나 파일이 없을 경우 새로 만든다.
// a+도 reading과 writing이 둘 다 된다. 추가시키거나 파일이 없을 경우 새로 만든다.
// 
// r mode와 w mode를 실습해 본다. 
// 
// while ((ch = fgetc(fr)) != EOF)	// getc(fr)
// {
//		// putc(ch, stdout);	// same as putchar(ch);
//		fputc(ch, stdout);

//		// TODO: use fputs() to write a file stream!

//		count++;
// }
// <= 텍스트 파일 스트림으로부터 데이터를 읽어 오는 과정이다. 
//    한 글자씩 읽어 오고 있다. 
//    ch는 int로 선언돼 있다. fgets(fr) 함수가 리턴해 주는 값이 int이기 때문이다.
// fgets()에 마우스를 올려 놔 보면, parameter가 FILE*_Stream으로 돼 있다.
// 파일 스트림이라는 의미이다. 
// 이 FILE이라는 구조체는, 
// 파일 스트림을 사용할 때 필요한 데이터를 갖고 있는 데이터의 묶음이다. 
// 
// fr을 보면, 맨 위에서 선언을 해 줬고, (fr = fopen(argv[1], "r")로 열었다.
// (ch = fgetc(fr)) != EOF 로 데이터를 한 글자씩 받아 오고 있다. 
// 
// fgetc() 함수와 getc() 함수는 거의 동일한데 fgetc() 함수를 더 많이 사용한다.
// 
// while ((ch = fgetc(fr)) != EOF) 
// <= EOF(파일의 끝)이 아닐 때까지 while문으로 계속 읽어 들이고 있다. 
//    (End Of File)
// 
// putc(ch, stdout); 에서 stderr을 넣으면 에러 스트림으로 출력이 된다. 