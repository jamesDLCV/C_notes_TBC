#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ 문자열을 출력하는 puts, fputs 함수
// 화면에 문자열만 출력할 때는, 전용 출력 함수인 puts(), fputs()를 사용한다. 
//
// puts() 함수 원형
// int puts(const char* str)	            // 문자열을 출력하고 자동 줄 바꿈
// int fputs(const char* str, FILE* stream)	// 문자열을 출력하고 줄 바꾸지 않음
// 
// puts()와 fputs() 함수 모두 정상 출력된 경우, 
// 0을 반환하고 출력에 실패하면, -1 (EOF)를 반환한다. 

int main() {

	// 손코드 12-7. 문자열을 출력하는 puts()와 fputs() 함수
	{
		char str[80] = "apple juice";	// 배열에 문자열 초기화
		char* ptr_s = "banana";			// 포인터에 문자열 연결

		puts(str);						// apple juice 출력하고 줄 바꿈
		fputs(ptr_s, stdout);			// banana만 출력
		puts("milk");					// banana에 이어 milk 출력
	}
	// 실행 결과
	// apple juice
	// bananamilk
	// 
	// puts()와 fputs() 함수는 문자열의 시작 위치부터 널 문자가 나올 때까지, 
	// 모든 문자를 출력한다. 
	// 
	// 따라서, puts(str);와 같은 char 배열명이나, 
	// fputs(ptr_s, stdout);와 같은 문자열 상수를 연결하고 있는 포인터를, 
	// 인수로 줄 수도 있다. 
	// puts("milk"); 이렇게 문자열 상수를 직접 사용하는 것도 가능하다.
	// 
	// 어떤 경우이든 문자열에서 첫 번재 문자의 주소가 되므로, 
	// 결국 문자열이 출력된다. 
	// 
	//              100 101 102  ...
	//   배열명 str  | a | p | p | l | e |   | j | u | i | c | e | \0|
	// 
	//                                    200 201 202  ...
	// 포인터 ptr_s  |      200      | --> | b | a | n | a | n | a | \0| 
	// 
	//              300 301 302  ...  
	//   문자열 상수  | m | i | l | k | \0|
	// 
	// puts()는 fputs()와 달리 문자열을 출력한 후에 자동으로 줄을 바꿔 주므로, 
	// 편리하지만 줄을 바꾸고 싶지 않을 때는 적당하지 않다. 
	// 
	// 위 예제를 보면, apple juice는 puts()로 출력해서, 출력 후 자동으로 줄이 바뀌었다.   
	// banana는 fputs()로 출력해서, banana가 출력된 후에 milk가 바로 이어서 출력이 됐다.
	// <= bananamilk, 
	//    fputs()로 출력하면 \n 줄 바꿈은 되지 않는다.

	return 0;
}