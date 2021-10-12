#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// qsort()

// qsort() 함수 포인터 연습 문제
//
// float 오름차순으로 바꾸어 보아라.
// 
//TODO: try increasing/decreasing order
int compare(const void* first, const void* second) {
	if (*(float*)first < *(float*)second)
		return 1;
	else if (*(float*)first > *(float*)second)
		return -1;
	else
		return 0;
}

int main() {
	float arr[] = { 8.1f, 2.4f, 5.6f, 3.2f, 6.5f, 11.0f };
	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; ++i)
		printf("%f ", arr[i]);


	return 0;
}
// 실행을 하면, 
// 11.000000 8.100000 6.500000 5.600000 3.200000 2.400000
// 내림차순으로 정렬이 돼서 출력된다. 
// 
// 이를 통해서 qsort() 함수를 어떻게 사용하는지는 이해를 했을 것이다. 
// 
// 다음 연습 문제를 풀어 보아라.