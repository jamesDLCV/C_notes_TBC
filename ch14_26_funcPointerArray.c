#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// 함수 포인터의 배열을 사용하는 연습 문제를 풀어 보자.
//
// 아래에서 보여주는 코드를 사용해서
//

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);	//TODO: add a new menu

int main() {
	char options[] = { 'u', 'l' };	//TODO: add a new menu
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower };	//TODO: add a new menu

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");
	
	return 0;
}

// 위의 것만 보고 나머지는 스스로 구현을 해 봐라. 
// 지금까지 이런 형태를 구현해 봤기 때문에 스스로 구현할 수 있을 것이다. 
// 
// 실행 결과는 다음과 같다. 
// Enter a string
// >> Hello World
// Choose an option:
// u) to upper
// l) to lower
// u	<= u를 입력하면,
// HELLO WORLD	<= 대문자로 출력된다. 
// 
// 특이한 점은, 
// typedef void (*FUNC_TYPE)(char*);
// FUNC_TYPE operations[] = { ToUpper, ToLower };	//TODO: add a new menu
// <= 함수 포인터의 배열이 들어 있다. 
//    이것을 잘 활용해서 문제를 풀어 보아라. 