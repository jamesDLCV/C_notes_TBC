#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Ȯ�� ���� 2. 
// �� ���� �ϼ��� �����ϴ� �迭�̴�. month[0]�� 1���̸�, ÷�ڰ� ���������� ������ ��,
// ���� �Բ� �����Ѵ�. month �迭�� ���� �� �ٿ� 5���� ����ϴ� �Լ��� ����� ����.

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
		if ((i + 1) % 5 == 0) {	// ��� ������ 5�� ����̸� �� �ٲ�
			printf("\n");
		}
	}
}