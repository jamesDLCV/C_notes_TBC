#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ 좀 더 알아보기. 직접 구현해 보는 gets() 함수
// gets() 함수와 똑같이 작동하는 함수를 만들면 다음과 같다.

void my_gets(char* ptr_s);

int main() {

	int i = 0;					// 배열 요소 첨자 변수
	char str[20];				// 문자열을 저장할 배열
	char ch;					// 입력한 문자를 받아 둘 임시 변수

	do {
		ch = getchar();			// 일단 문자 하나 입력
		str[i] = ch;			// 배열에 저장
		i++;					// 첨자 증가
	} while (ch != '\n');		// 입력한 문자가 개행이면 종료

	str[--i] = '\0';			// 개행 문자가 입력된 위치에 널 문자 저장
	printf("%s", str);
	puts("");

	// 함수로 만들어서 할 수도 있다. 
	my_gets(str);
	printf("%s", str);

	return 0;
}

// 또는 다음처럼 아예 함수를 만들어서 프로그램을 작성할 때 호출하는 방법도 있다. 
void my_gets(char* ptr_s) {				// ps는 첫 번째 배열 요소를 가리킨다.
	char ch;

	while ((ch = getchar()) != '\n') {  // 입력한 문자가 개행 문자가 아닌 동안 반복
		*ptr_s = ch;					// 배열에 저장하고,
		ptr_s++;						// 다음 배열 요소로 이동
	}
	*ptr_s = '\0';						// 마지막에 널 문자로 마무리한다.
}

//$ 핵심 포인트
// 문자열은 첫 번째 문자가 저장된 메모리의 주소로 바뀐다. 
// scanf() 함수는 중간에 공백이 포함된 문자열을 입력할 수 없다.
// gets() 함수는 한 줄의 데이터를 char 배열에 저장한다.
// fgets() 함수는 배열의 크기를 검사하는 기능을 가진 문자열 입력 함수이다.

//$ 문자열을 저장하는 배열과 포인터의 차이
//
// 초기화	char *pc = "mango";			char str[80] = "mango";
// 대입      pc = "banana";				strcpy(str, "banana");
// 크기		sizeof(pc) --> 4바이트		sizeof(str) --> 80바이트
// 수정      pc[0] = 't'; ( X )			str[0] = 't'; ( O )
// 입력      scanf("%s", pc); ( X )		scanf("%s", str); ( O )