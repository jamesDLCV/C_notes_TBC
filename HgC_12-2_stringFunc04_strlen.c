#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//$ 문자열 길이를 계산하는 strlen() 함수
// 문자열을 저장하는 char 배열은 다양한 길이의 문자열을 저장할 수 있도록 
// 충분히 크게 선언해서 사용해야 한다. 
//
// 따라서 배열에 저장된 문자열의 길이는 배열의 크기와 다를 수 있다. 
// 만약 배열에 저장된 문자열의 실제 길이를 알고 싶으면 strlen() 함수를 사용한다. 
//
// strlen(str);
//        크기를 확인할 배열명

int main() {

	// 손코딩 12-11. 두 문자열 중 길이가 긴 단어 출력
	char str1[80], str2[80];
	char* res_ptr;

	printf("2개의 과일 이름 입력: ");
	scanf("%s%s", str1, str2);

	if (strlen(str1) > strlen(str2))
		res_ptr = str1;
	else
		res_ptr = str2;

	printf("이름이 긴 과일은: %s\n", res_ptr);
	puts("");

	// strlen() 함수는 배열에 저장된 문자열에서 널 문자가 나올 때까지 문자 수를 세어 반환한다. 
	// 따라서, 배열의 크기와는 상관 없이 실제 저장된 문자열의 길이를 확인할 수 있다. 
	// 
	// 문자열의 길이를 반환하므로, 
	// if (strlen(str1) > strlen(str2)) 처럼 
	// 반환값을 바로 비교하거나 수식의 일부로 사용할 수 있다.
	// 
	//$ sizeof 연산자와 strlen() 함수의 차이
	// sizeof 연산자는 배열에 저장된 문자열 길이와는 상관 없이 배열 전체 크기를 계산한다. 
	{
		char str[80] = "apple";
		printf("%d\n", sizeof(str));	// 80
		printf("%d\n", strlen(str));	// 5
	}

	return 0;
}

