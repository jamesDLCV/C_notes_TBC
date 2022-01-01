#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ 직접 만드는 strcpy() 함수

char* my_strcat(char* ptr_d, char* ptr_s);

int main() {

	char str[80] = "straw";

	printf("바꾸기 전 문자열: %s\n", str);	// 바꾸기 전 문자열: straw

	my_strcat(str, "berry");

	printf("바꾼 후 문자열: %s\n", str);		// 바꾼 후 문자열: strawberry
	printf("다른 문자열 대입: %s\n", my_strcat(str, "kiwi"));
									// 다른 문자열 대입:  strawberrykiwi
	return 0;
}

char* my_strcat(char* ptr_d, char* ptr_s) {

	char* ptr_o = ptr_d;

	while (*ptr_d != '\0') {
		ptr_d++;
	}

	while (*ptr_s != '\0') {
		*ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
	}

	return ptr_o;
}
//
//                100 101 102 103 104 105  ...
//       105      | s | t | r | a | w | /0|   |   |   |   | 복사 받을 str 배열
//                                      |   |   |   |   |
//  포인터 ptr_d-------------------------|   |   |   |   |
//                                      |   |   |   |   |  대입
//                                    200 201 202 203 204 205
//                            200     | b | e | r | r | y | \0| 복사할 문자열 상수
//                                      |   |   |   |   |
//                        포인터 ptr_s-------------------