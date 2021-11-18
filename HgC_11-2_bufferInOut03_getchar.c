#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* $ getchar 함수를 사용한 문자열 입력
 getchar() 함수도 버퍼를 사용하는 문자 입력 함수이다. 
 getchar() 함수를 반복 사용하면 한 줄의 문자열을 char 배열에 입력할 수 있다. 

 예제로 문자열 입력 과정을 살펴 보자. */

// 손코딩 11-6. getchar 함수를 사용한 문자열 입력
void my_gets(char* str, int size);

int main() {

	char str[7];						// 문자열을 저장할 배열

	my_gets(str, sizeof(str));			// 한 줄의 문자열을 입력하는 함수
	printf("입력한 문자열: %s\n", str);	// 입력한 문자열 출력

	return 0;
}

void my_gets(char* str, int size) {		// str은 char 배열, size는 배열의 크기
	int ch;								// getchar 함수의 반환값을 저장할 변수
	int i = 0;							// str 배열의 첨자

	ch = getchar();						// 첫 번째 문자 입력

	while ((ch != '\n') && (i < size - 1)) {	// 배열의 크기만큼 입력
		str[i] = ch;					// 입력한 문자를 배열에 저장
		++i;							// 첨자 증가
		ch = getchar();					// 새로운 문자 입력
	}

	str[i] = '\0';						// 입력된 문자열의 끝에 널 문자를 저장

}
// 실행 결과1:
// a boy
// 입력한 문자열: a boy

// 실행 결과2:
// Be happy!
// 입력한 문자열: Be hap

/* 이 예제는 getchar() 함수를 사용하여 
 키보드로 입력한 한 줄의 문자열을 char 배열로 저장한다. 
 단, 배열의 크기를 넘는 문자열을 입력한 경우도 배열의 크기만큼만 입력하도록 작성하여
 할당되지 않은 메모리를 침범하지 않도록 작성한다. 

 또한 크기가 다른 배열에도 사용할 수 있도록 함수로 만든다. 

 다음 행이 함수를 호출하는 부분이며, 문자열을 저장할 배열명과 배열의 크기를 인수로 준다.

	my_gets(str, sizeof(str));

 함수 안에서는 다음 행에서 최초로 문자를 입력하는데 
 이때 키보드로 한 줄의 데이터를 모두 입력하여 버퍼에 저장해 둔다. 

	ch = getchar();

 이후 getchar() 함수를 반복 사용하여 
 버퍼로부터 문자를 하나씩 가져와 배열에 차례로 저장한다. */