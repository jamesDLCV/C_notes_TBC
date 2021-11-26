#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ 표준 입력 함수의 버퍼 공유 문제
// scanf(), getchar() 함수 같은 표준 입력 함수는 입력 버퍼를 공유한다. 
// 따라서 같은 버퍼를 공유하는 gets()나 fgets() 함수에서 
// 개행 문자를 입력의 종료 조건으로 사용하면, 문제를 일으킬 수 있다. 
//
// 앞서 입력한 함수가 버퍼에 개행 문자를 남겨 놓는 경우,
// 이어서 호출되는 함수가 버퍼에서 개행 문자만 가져오고 입력을 끝내는 문제가 생긴다.


int main() {

	// 손코딩 12-6. 개행 문자로 인행 gets() 함수가 입력을 못 하는 경우
	{
		int age;					// 나이를 저장할 변수
		char name[20];				// 이름을 저장할 배열

		printf("나이 입력: ");
		scanf("%d", &age);			// scanf() 함수로 나이 입력

		printf("이름 입력: ");
		gets(name);					// gets() 함수로 이름 입력
		printf("나이: %d, 이름: %s\n", age, name);
	}
	puts("");
	// 실행하면, 이름 입력 자체를 할 수 없게 된다. 
	// scanf("%d", &age);에서 키보드로 입력한 나이는 문자열로 버퍼에 저장되었다가
	// scanf() 함수가 숫자로 변환하여 변수 age에 저장한다. 
	// 
	// 이때 버퍼에 남아 있는 개행 문자가 gets(name);	 함수의 입력으로 쓰인다. 
	// 
	//    키보드 입력				 버퍼
	//             17 ----> | 1 | 7 | \n|
	// Enter를 누룰 때        <------>  |
	//    개행 문자까지           |      |
	//    버퍼에 저장           scanf   gets
	//                          |       |  
	//     age 변수 17 <---------        -------> | \0|   |   |  name 배열
	//  문자열 "17"을 정수 17로 
	//  변환하여 2진수로 저장 
	//
	// 결국 gets() 함수는 버퍼에서 개행 문자를 가져와서 입력을 끝내므로, 
	// 키보드로 이름을 입력하는 과정이 생략되며, name 배열의 첫 번째 요소에는 
	// 널 문자가 저장되어 이름으로는 아무것도 출력되지 않는다. 
	// 
	// 이 문제는 입력 함수들이 버퍼를 공유해서 생기므로, 
	// 필요한 경우 버퍼의 내용을 지워야 한다.
	// 
	// 버퍼에 남아 있는 개행 문자를 지우는 방법은 간단하다. 
	// 개행 문자를 읽어 들이는 문자 입력 함수를 호출하면 된다. 
	// 
	// getchar();	 // 버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 버림
	// 
	// scanf("%*c"); // 버퍼에서 하나의 문자를 읽어서 버림, 변수는 필요 없음
	// 
	// fgets(stdin); // 버퍼에서 하나의 문자를 읽어서 반환, 반환 문자는 버림
	// 
	// 위 예제에 fgets(stdin);을 넣어서 다시 컴파일 후 실행해 보아라. 
	// 이번에는 이름을 입력 받아서 제대로 출력할 수 있을 것이다. 
	{
		int age;					
		char name[20];				

		printf("나이 입력: ");
		scanf("%d", &age);			

		//fgets(stdin);             // <= error 뜬다.
		//getchar();				// '\n' 개행 문자 버리기
		scanf("%*c");				// '\n' 개행 문자 버리기
		 
		printf("이름 입력: ");
		gets(name);					
		printf("나이: %d, 이름: %s\n", age, name);
	}
	
	return 0;
}