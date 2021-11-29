#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 지금까지 문자열의 구현 방법과 입출력 함수에 대해 공부했다. 
// 문자열은 문자들을 메모리에 연속으로 저장하고, 
// 첫 번째 문자의 주소로 처리한다. 
// 따라서, 문자열 입출력 함수의 기능을 정확히 익혀야 포인터 문제를 겪지 않는다.
// 
// 문제를 풀면서 입출력 함수의 기능을 익히고 차이점을 살펴 보자.

int main() {

	// 1. p335
	{
		char* ptr_s = "applepie";
		ptr_s += 5;
		printf("%s", ptr_s);		// pie
	}
	puts("\n");

	// 2.
	{
		char str[20] = "apple";
		char* ptr_a = str;
		char* ptr_b = "pineapple";

		printf("%s\n", "apple");		// apple
		printf("%c\n", str[0]);			// a. printf("%s\n", str[0]);는 안 됨.
		printf("%s\n", ptr_a);			// apple
		printf("%s\n", ptr_b + 4);		// apple
	}
	puts("\n");

	// 3.
	{
		char ani[20];
		char why[80];

		printf("좋아하는 동물: ");
		scanf("%s", ani);
				
		scanf("%*c");			// getchar();

		printf("좋아하는 이유: ");
		fgets(why, sizeof(why), stdin);

		printf("%s is %s", ani, why);
	}

	return 0;
}

// printf("%s\n", str[0]);는 아무것도 출력이 안 된다. 
// printf("%c\n", str[0]);로 해야 출력이 된다. 한 글자 출력!