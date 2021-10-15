#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// 함수 포인터의 배열을 사용하는 연습 문제를 풀어 보자.
//
// 아래에서 보여주는 코드를 사용해서

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);	//TODO: add a new menu

int main() {
	char options[] = { 'u', 'l', 't'};	//TODO: add a new menu
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose };	//TODO: add a new menu

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");

	while (true) {
		printf("Choose an option:\n");
		printf("u) to upper\n");
		printf("l) to lower\n");
		printf("t) to transpose\n");	//TODO: add a new menu

		char c;
		while (scanf("%c%*[^\n]%*c", &c) != 1)
			printf("Please try again.\n");

		bool found = false;

		/*switch (c) {
		case 'u':
			ToUpper(input);
			found = true;
			break;
		case 'l':
			ToLower(input);
			found = true;
			break;
		} <= 이렇게 해 주는 게 직관적이기는 하지만, 아래 for문이 보다 유연하다.
		*/ 

		for (int i = 0; i < n; ++i)
			if (options[i] == c) {
				(*(operations[i]))(input);
				 // <= 함수에 대한 포인터로 직접 수행하기 때문에, 
				 //    Transpose가 추가돼도 수정할 필요가 없다. 
				found = true;
				break;
			}

		if (found)
			break;
		else
			printf("Wrong input, try again\n");
	}

	printf("%s\n", input);

	return 0;
}

void update_string(char* str, int(*pf)(int)) {
	while (*str) {
		*str = (*pf)(*str);
		str++;
	}
}

void ToUpper(char* str) {
	update_string(str, toupper);
}

void ToLower(char* str) {
	update_string(str, tolower);
}

void Transpose(char* str) {
	while (*str) {
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

//
// 함수 포인터의 배열을 어떻게 사용하는지에 대한 연습 문제를 풀어 봤다. 