#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//$ 원하는 개수의 문자만을 복사하는 strncpy() 함수
// strncpy() 함수는 문자열을 복사할 때, 문자의 수를 지정할 수 있다. 
// 
// 예를 들어, 문자열 "apple-pie"의 앞에서 5개의 문자만 char 배열 str에 복사하려면,
// 다음과 같이 사용한다. 
// 
// strncpy(str, "apple-pie", 5);
//          |        |       |      
//      복사 받을   복사할   복사할    
//      배열명      문자열   문자 수 

int main() {

	{
		// 손코딩 12-9. strncpy() 함수를 사용할 문자열 복사
		char str[20] = "mango tree";	// 배열 초기화

		strncpy(str, "apple-pie", 5);   // "apple-pie"에서 다섯 문자만 복사

		printf("%s\n", str);			// 복사 받은 문자열 출력
										// apple tree
	}
	puts("");
	{
		char str[20] = "mango tree";	
		strncpy(str, "apple-pie", 5);  

		str[5] = '\0';

		printf("%s\n", str);			// apple
	}
	
	return 0; 
}

// 실행 결과에서 확인할 수 있듯이 strncpy() 함수는, 
// 복사할 문자열에서 지정한 개수만큼 문자를 복사하고 널 문자는 저장하지 않는다.
// 
// 따라서, str 배열에서 mango만 apple로 바뀌므로, 
// 결국 str 배열에 저장된 문자열은 "apple tree"가 된다. 
// 
// strncpy(str, "apple-pie", 6); <= 복사할 문자 수를 6으로 바꾸면, 
// 출력은 apple-tree가 된다. 
// 
// 만약 str 배열이 문자열 "apple"로만 쓰이도록 하려면, 
// apple을 복사한 후에 널 문자를 별도로 저장해야 한다. 
// 
// str 배열  | a | p | p | l | e |   | t | r | e | e | \0|
//                                 |
//                     여기에 널 문자를 채워 넣는다. 
// <= str[5] = '\0';