#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 기타 입출력 함수들
// ungetc(), setvbuf(), fflush()

int main() {

	FILE* fp;
	int ch;

	/* ungetc() */
	fp = fopen("input.txt", "r");

	ch = fgetc(fp);
	fputc(ch, stdout);

	printf("\n");

	ungetc(ch, fp);		// try another characters

	ch = fgetc(fp);
	fputc(ch, stdout);  // <= "

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= I

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= 공백

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= c

	fclose(fp);

	/* setvbuf() */

	return 0;
}

// ungetc()
//	한 글자를 읽은 후 버퍼에다가 그 함수를 다시 집어 넣어 버린다. 
//  일을 거꾸로 하는 함수이다. 
// 
// input.txt 파일을 만들고 내용을 입력한다. 
/*
"I choose a lazy person to do a hard job.
Because a lazy person will find an easy way to do it."

Bill Gates
*/
// 첫 글자를 읽으면 "가 나올 것이다. 
// 
// ch = fgetc(fp);      <= 한 글자를 읽어 온다. 
// fputc(ch, stdout);   <= 출력한다. 맨앞의 글자인 "가 출력된다. 

// ungetc(ch, fp);		// try another characters
//						<= 읽어 들인 글자를 다시 버퍼에 넣는다. 
// ch = fgetc(fp);      <= 다시 글자를 읽어 들이면,
// fputc(ch, stdout);	<= 다시 맨앞의 글자인 "가 출력된다. 
// 
// ch = fgetc(fp);      <= 글자를 읽어 들이면,
// fputc(ch, stdout);   <= 이제는 " 다음의 문자 I가 출력된다. 
// 
// fclose(fp);
//
// ungetc() 함수가 실무에서 필요할 수도 있다. 