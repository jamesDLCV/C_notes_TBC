#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 기타 입출력 함수들
// ungetc(), setvbuf(), fflush()
// 
// setvbuf()

int main() {

	FILE* fp;
	int ch;

	/* setvbuf() */
	fp = fopen("input.txt", "r");

	char buffer[32] = { '\0', };

	setvbuf(fp, buffer, _IOFBF, sizeof(buffer));	// _IOLBF, _IOFBF, _IONBF 

	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%hhd", buffer[i]);
	printf("\n");

	ch = fgetc(fp);		// Read just only a single character!
	
	// dump buffer
	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%c", buffer[i]);
	printf("\n");

	fclose(fp);

	/* fflush() */

	return 0;
}

//  input.txt 파일에는 다음의 내용이 담겨 있다. 
/*
"I choose a lazy person to do a hard job.
Because a lazy person will find an easy way to do it."

Bill Gates
*/
// 
// setvbuf() 함수를 살펴 보자.
//	버퍼의 설정을 바꿔 줄 수 있다. 다양한 기능이 있다. 여기서는 기본적인 것만 소개한다.
//
// char buffer[32] = { '\0', }; <= 배열을 하나 만들었다.
//                                 이것을 버퍼로 사용하라고 할 수 있다. 
// setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); 
//	<= 위에서 만든 배열을 버퍼로 사용하라. 
// 
// 글자를 읽어 들이기 전에 버퍼에 있는 내용을 dump해 보면, 
// <= 00000000000000000000000000000000
//	  0으로 초기화된 32개의 배열이 출력된다. 버퍼가 비어 있다. 
// 
// ch = fgetc(fp);	<= 한 글자만 읽었다. 
// 
// 그다음, 버퍼에 있는 내용을 dump를 해 본다. 
// for (int i = 0; i < sizeof(buffer); ++i)
//  	printf("%c", buffer[i]);
// <= 버퍼에 있는 내용을 다 출력을 해 보면, 
//    한 글자만 읽어 왔음에도 불구하고 버퍼는 꽉 찼다. 
// 출력) "I choose a lazy person to do a
//      <= 맨마지막은 공백
//    세어 보면 32 글자이다. 
// 
// 버퍼는 이 프로그램이 이 파일의 내용을 계속 읽을 것이라고 예상이 되면, 
// 미리 버퍼에 그 파일을 넣어 놓고, 버퍼에서 가지고 온다. 
// 파일을 버퍼에서 가지고 오면 훨씬 빠르다. 
//
// 파일에서 버퍼로 옮기는 것은 시간이 걸리니까 
// 한 번에 여러 글자씩 버퍼로 읽어 들이려고 하는 것이다. 
// 일단 버퍼에 올라온 다음에는 fgetc()를 이용해서 버퍼로부터 한 글자를 가지고 오거나,
// 여러 글자를 가지고 오는 것은 비교적 빠르기 때문에, 
// 버퍼를 미리 채워 나가고 있는 것이다. 
// 
// 버퍼가 비어 있다가, 한 글자만 읽으면, 버퍼를 먼저 채우고 (채울 수 있는 만큼 채우고),
// ch = fgetc(fp);로 거기에서 한 글자를 가지고 온 것이다. 
// 그래서 버퍼가 자신을 채울 수 있는 만큼 꽉 채우고 있는 것이다. 
// 
// 관심이 있는 경우는, 
// 아주 엄청나게 많은 데이터를 파일로 저장하는 것일 것이다.  
// 읽어 들이는 것도 중요하고 저장하는 것도 중요하다.
// 그럴 때, 
// setvbuf(fp, buffer, _IOFBF, sizeof(buffer));	// _IOLBF, _IOFBF, _IONBF 
//  <= _IOLBF, _IOFBF, _IONBF 이런 옵션을 사용할 수 있다. 
//     _IOLBF 라인을 하나씩 꺼내서 버퍼에 저장. L <= Line
//     _IOFBF 통째로 저장. F <= Full
//     _IONBF N은 No이다. 
//  이것을 예제로 보여 주려면 엄청나게 큰 데이터를 사용해서 끊고 조작하는 과정을
// 보여 줘야 하는데 그것이 쉽지가 않다. 기초에서는 그리 중요하지 않아서 생략한다.
// 
// 버퍼를 사용하지 않는 경우 _IONBF만 살펴 보자. 
// 위 setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); 에서 
// _IOFBF를 _IONBF으로 바꾸면, 
// 버퍼를 읽어 들이지 않는다. <= 버퍼를 dump해 보면 아무 것도 출력이 되지 않는다.
// 
// 위에서는 reading만 살펴 봤다. 나중에 실무에서 writing도 해 보기 바란다. 
// 
// fflush()를 살펴 보자.