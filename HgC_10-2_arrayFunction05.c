#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���� ���� ����
// ���� 1. �ζ� ��ȣ ���� ���α׷�
// 
// 1 ~ 45 �߿� 6���� ���� �ٸ� ���� �迭�� �Է��ϰ� ����Ѵ�. 
// �Է��� ���� �̹� ����� ���� ������ ���� �޽����� ����ϰ� �ٽ� �Է��Ѵ�. 

// ���� § �ڵ�. �ش信���� input_nums()�� ���� �ٸ��� �ۼ���.

void input_nums(int* lotto_nums);	// �迭�� �ζ� ��ȣ�� �Է��ϴ� �Լ�
void print_nums(int* lotto_nums);	// �迭�� ����� ���� ����ϴ� �Լ�

int main() {

	int lotto_nums[6];				// �ζ� ��ȣ�� ������ �迭

	input_nums(lotto_nums);			// �Է� �Լ� ȣ��
	print_nums(lotto_nums);			// ��� �Լ� ȣ��
	puts("");

	return 0;
}

void input_nums(int* lotto_nums) {

	printf("1 ~ 45 ���� ���ڸ� �Է��ϼ���: \n");
	for (int i = 0; i < 6; ++i) {
		printf("%d ��° ��ȣ�� �Է��ϼ���: ", i + 1);

		scanf("%d", lotto_nums + i);

		if (*(lotto_nums + i) < 1 || *(lotto_nums + i) > 46) {
			printf("1 ~ 45������ ���ڸ� �Է��ϼ���.\n");
			--i;
			continue;
		}

		int temp = lotto_nums[i];
		for (int j = 0; j < i; ++j) {
			if (temp == lotto_nums[j]) {
				printf("������ ���ڰ� �̹� �ֽ��ϴ�. �ٽ� �Է��ϼ���.\n");
				--i;
				break;
			}
		}
	}
}

void print_nums(int* lotto_nums) {

	int temp;
	printf("\n�ζ� ��ȣ: ");
	for (int i = 0; i < 5; ++i) {
		temp = i;

		for (int j = i + 1; j < 6; ++j) {
			if (lotto_nums[temp] > lotto_nums[j]) {
				temp = j;
			}
		}
		int temp_arr = lotto_nums[i];
		lotto_nums[i] = lotto_nums[temp];
		lotto_nums[temp] = temp_arr;
	}

	for (int i = 0; i < 6; ++i) {
		printf("%d ", lotto_nums[i]);
	}
}