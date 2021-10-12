#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// qsort()

// qsort() �Լ� ������ ���� ����
//
// float ������������ �ٲپ� ���ƶ�.
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
// ������ �ϸ�, 
// 11.000000 8.100000 6.500000 5.600000 3.200000 2.400000
// ������������ ������ �ż� ��µȴ�. 
// 
// �̸� ���ؼ� qsort() �Լ��� ��� ����ϴ����� ���ظ� ���� ���̴�. 
// 
// ���� ���� ������ Ǯ�� ���ƶ�.