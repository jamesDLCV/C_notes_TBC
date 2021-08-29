#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 기타 입출력 함수들
// ungetc(), setvbuf(), fflush()
// 
// ungetc()

int main() {

	FILE* fp;
	int ch;

	/* ungetc() */
	fp = fopen("input.txt", "r");

	ch = fgetc(fp);
	fputc(ch, stdout);

	printf("\n");

	ungetc((int)'A', fp);		// try another characters

	ch = fgetc(fp);
	fputc(ch, stdout);  // <= "가 A로 대체됨. A 출력

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= I
		
	ch = fgetc(fp);
	fputc(ch, stdout);	// <= 공백

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= c

	printf("\n");

	ungetc((int)'B', fp);	// 윗 줄에서 읽어 들인 c에다가 B를 넣는다.

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= B

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= h

	fclose(fp);

	/* setvbuf() */

	return 0;
}

// ungetc() 함수가 실무에서 필요할 수도 있다. 
// 
//  input.txt 파일에는 다음의 내용이 담겨 있다. 
/*
"I choose a lazy person to do a hard job.
Because a lazy person will find an easy way to do it."

Bill Gates
*/
// 
// ungetc((int)'A', fp);
//  윗 라인에서 ch = fgetc(fp);으로 " 한 글자를 읽었다. 
//  "를 이 버퍼에서 꺼낸다. 이 자리에다가 A를 넣는다. 
// 
// ungetc()
//  un이 붙으면 반대의 기능을 해 주는 것이다. 
// 
// setvbuf() 함수를 살펴 보자.