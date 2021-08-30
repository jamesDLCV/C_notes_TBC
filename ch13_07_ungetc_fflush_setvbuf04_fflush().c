#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 기타 입출력 함수들
// ungetc(), fflush(), setvbuf()
// 
// fflush()

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
	printf("\n\n\n");

	/* fflush() */

	// Writing a large amount of data

	fflush(fp);

	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%c", buffer[i]);
	printf("\n");

	fclose(fp);

	return 0;
}

// flush 화장실에서 변기의 물을 내린다. 
// 버퍼에 쌓여 있는 데이터를 쫙 내려 보내라. 
// 
// fflush(fp); 이런 식으로 사용한다. 
// 대용량의 데이터가 필요한데 실험으로 재현하기가 곤란해서 용법만 적어 놓았다.
// 
// OS와 C가 대용량 데이터를 처리하는 과정에서 버퍼에 있는 데이터를
// 파일이나 디스플레이나 스트림으로 완벽하게 출력을 못 한 경우가 발생할 수 있다. 
// 그럴 때 반드시 버퍼에 있는 데이터를 다 출력해라, 다 내보내라는 의미이다.  
// 
// 출력 명령을 내렸는데 왜 출력이 안 될까?
// 버퍼에 미처 출력하지 못한 데이터가 남아 있는데, 강제로 프로그램이 종료됐을 때. 
// 이럴 때 fflush()를 사용하면 도움이 될 수 있다. 
// 
// 우리가 만날 모든 문제가 fflush()로 해결될 거라고는 못 하겠지만, 
// 시도해 볼 만한 옵션 중 하나이다. 
// 
// ungetc(), fflush(), setvbuf() 세 함수에 대해서 살펴 봤다. 