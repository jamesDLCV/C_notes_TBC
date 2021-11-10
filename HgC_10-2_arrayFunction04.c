#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 확인 문제 2. 
// 각 달의 일수를 저장하는 배열이다. month[0]은 1월이며, 첨자가 순차적으로 증가할 때,
// 월도 함께 증가한다. month 배열의 값을 한 줄에 5개씩 출력하는 함수를 만들어 봐라.

void print_month(int* mon_ptr, int size);

int main() {

	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int size = sizeof(month) / sizeof(month[0]);

	print_month(month, size);

	return 0;
}

void print_month(int* mon_ptr, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%5d", mon_ptr[i]);
		if ((i + 1) % 5 == 0) {	// 출력 개수가 5의 배수이면 줄 바꿈
			printf("\n");
		}
	}
}