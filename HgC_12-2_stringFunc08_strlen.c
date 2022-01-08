#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ 직접 만드는 strlen() 함수
//$ 직접 만드는 strcmp() 함수

int my_strlen(char* ptr_s);
int my_strcmp(char* ptr_a, char* ptr_b);

int main() {

	// my_strlen()
	char str[80] = "straw";
	char str2[80] = "pineapple";

	int cnt = my_strlen(str);
	int cnt2 = my_strlen(str2);

	printf("%s의 개수는 %d입니다.\n", str, cnt);
	printf("%s의 개수는 %d입니다.\n", str2, cnt2);	
	puts("");

	// my_strcmp()
	char str3[80] = "pear";
	char str4[80] = "peach";

	printf("사전에 나중에 나오는 과일 이름: ");

	if (my_strcmp(str3, str4) > 0)	// str3이 str4보다 크면
		printf("%s\n", str3);
	else							// str3이 str$보다 크지 않으면,
		printf("%s\n", str4);

	return 0;
}

int my_strlen(char* ptr_s) {    // ptr_s는 배열명을 저장하고 
									// 첫 번째 배열 요소를 가리킴.
	int cnt = 0;				// 문자를 세기 위한 변수
	while (*ptr_s != '\0') {	// ptr_s가 가리키는 문자가 널 문자가 아니면, 
		cnt++;
		ptr_s++;
	}
	
	return cnt;					// 전체 문자 수 변환
}

int my_strcmp(char* ptr_a, char* ptr_b) {

	while ((*ptr_a == *ptr_b) && (*ptr_a != '\0')) { // 두 문자가 같으나
		ptr_a++;										// 널 문자가 아닌 경우
		ptr_b++;
	}

	// 반복문 이후 이 시점에서는 두 문자가 다르거나 둘 다 널 문자임
	if (*ptr_a > *ptr_b) return 1;
	else if (*ptr_a < *ptr_b) return -1;
	else return 0;
}

//$ 핵심 포인트
//
// strcpy() 문자열을 복사 받는 곳은 배열이어야 한다. 
// strcat() 문자열을 최초로 붙일 때는 초기화를 해야 한다. 
// 배열에 저장된 실제 문자열의 길이를 알고 싶을 때 strlen() 함수를 쓴다. 
// strcmp() 문자열의 사전 등록 순서를 확인할 수 있다. 
//
// strcpy(str1, str2);	문자열 str2를 str1에 복사						!대입
// strlen(str);			문자열 str의 길이(문자 수)를 구해서 반환		!길이 계산
// strcat(str1, str2);	문자열 str2를 str1 문자열 뒤에 이어서 붙임		!붙이기
// strcmp(str1, str2);	문자열 str1이 str2보다 크면 1 반환		    !비교
//                             str1이 str2보다 작으면 -1 반환
//                             str1과 str2가 같은 문자열이면 0 반환