#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		// strlen()

//$ fgets() 함수를 사용한 문자열 입력
// scanf(), gets()는 입력되는 문자열의 크기가 배열 크기를 넘어설 위험성이 있다.
// 이렇게 문자열의 크기가 배열보다 커지면 할당되지 않은 메모리 공간을 침범하여,
// 실행 중인 프로그램에 에러가 발생할 수 있다. 
// 
// 안전하게 문자열을 입력하려면, 배열 크기를 확인하는 fgets() 함수를 사용하는 것이 좋다.
// fgets() 함수는 최대 배열의 크기까지만 문자열을 입력한다. 

int main() {

	{
		// 손코딩 12-5. fgets() 함수의 문자열 입력 방법
		char str[80];

		printf("공백이 포함된 문자열 입력: ");
		fgets(str, sizeof(str), stdin);				// 문자열 입력

		// 나중에 입력할 공간
		printf("입력된 문자열은 %s입니다.\n", str);	// 문자열 출력
	}
	
	// fgets() 함수는 인수를 3개 사용하는데 각각 다음과 같다. 
	// 
	//      1.배열명           3. 표준 입력  
	// fgets(str, sizeof(str), stdin);
	//            2. 배열의 크기 확인
	//
	// fgets() 함수는 문자열을 저장할 배열명 외에 
	// 배열의 크기와 표준 입력 버퍼를 뜻하는 stdin을 함께 사용한다. 
	// 
	// 첫 번째 인수는 1. 배열명이다. 
	// 두 번째 인수는 2. 배열의 크기를 알려 준다. 배열의 크기를 넘는 문자열을 입력해도
	//                 배열의 크기만큼만 저장된다. 
	//                 입력한 문자열의 끝에는 항상 널 문자를 붙이므로, 
	//                 최대로 '배열의 크기 - 1개'의 문자만을 저장한다. 
	//    예) 배열의 크기가 5바이트라면, str 배열에는 appl까지만 저장된다. 
	//        str 배열  | a | p | p | l | \0|
	// 세 번째 인수는 3. stdin으로 데이터를 입력할 때, 키보드와 연결된 
	//                 표준 입력 버퍼 stdin을 사용하라는 뜻이다.  
	// 
	// scanf()와 gets() 함수는 기본적으로 표준 입력을 사용하지만, 
	// fgets() 함수는 입력 버퍼를 선택할 수 있는 함수이므로, 
	// 키보드로 입력할 때는 항상 stdin을 넣어야 한다. 
	// 
	// fgets() 함수가 문자열을 입력하는 방식은 gets() 함수와 거의 같으나, 
	// 개행 문자의 처리 방식이 다르다. 
	// 
	//$ 버퍼에 있는 개행 문자도 배열에 저장하고 널 문자를 붙여 문자열을 완성한다.
	// 
	//   키보드 입력								 버퍼
	//        apple jam  ----> | a | p | p | l | e |   | j | a | m | \n|
	//   Enter를 누를 때,        <-------------------------------------->
	//   개행 문자까지                           | 개행 문자까지 배열에 저장하고
	//   버퍼에 저장                             | 마지막에 널 문자를 붙인다.
	//                                          |
	//                str 배열  | a | p | p | l | e |   | j | a | m | \n| \0|
	// 
	// 실행 결과를 보면, 배열에 입력된 개행 문자 때문에 
	// apple jam이 출력되고 바로 줄이 바뀐 걸 알 수 있다. 
	puts("");
	//
	//$ 개행 문자 제거 과정
	// 개행 문자는 어떻게 제거할 수 있을까?
	// 입력된 개행 문자가 불필요하다면, 다음 공식에 따라 제거한다. 
	//   
	//                   str[strlen(str) - 1] = '\0'
	//        널 문자 이전까지 문자 수 10개 
	//   9는 배열에서 개행 문자가 저장된 곳의 위치 
	//                       개행 문자를 널 문자로 바꿈
	// 
	// strlen() 함수는 배열명을 인수로 받아 널 문자 이전까지의 문자 수를 세어 반환한다. 
	// 사용할 때, string.h 헤더 파일을 include하며 자세한 구현 방식은 다음에 다룬다.
	// 
	{
		// 손코딩 12-5. fgets() 함수의 문자열 입력 방법, 개행 문자 제거
		char str[80];

		printf("공백이 포함된 문자열 입력: ");
		fgets(str, sizeof(str), stdin);				// 문자열 입력

		// #include <string.h>
		str[strlen(str) - 1] = '\0';
		printf("입력된 문자열은 %s입니다.\n", str);	// 문자열 출력
	}
	// 위와 같이 str[strlen(str) - 1] = '\0';를 해 주면, 
	// 개행 문자를 널 문자로 바꿔 주면, 개행 문자를 제거할 수 있다. 	

	return 0;
}