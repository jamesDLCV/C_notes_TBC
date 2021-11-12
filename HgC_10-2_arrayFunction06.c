#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���� ���� ����
// ���� 1. �ζ� ��ȣ ���� ���α׷�
// 
// 1 ~ 45 �߿� 6���� ���� �ٸ� ���� �迭�� �Է��ϰ� ����Ѵ�. 
// �Է��� ���� �̹� ����� ���� ������ ���� �޽����� ����ϰ� �ٽ� �Է��Ѵ�. 

// �ش�

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

	int num;
	int i, j;
	int dup;

	printf("1 ~ 45 ���� ���ڸ� �Է��ϼ���: \n");
	for (i = 0; i < 6; ++i) {
		printf("%d ��° ��ȣ�� �Է��ϼ���: ", i + 1);
		scanf("%d", &num);

		if (num < 1 || num > 46) {
			printf("1 ~ 45������ ���ڸ� �Է��ϼ���.\n");
			--i;
			continue;
		}

		dup = 0;
		for (j = 0; j < i; ++j) {
			if (num == lotto_nums[j]) {
				dup = 1;
				break;
			}
		}

		if (!dup) {
			lotto_nums[i] = num;
		}

		else {
			printf("���� ��ȣ�� �ֽ��ϴ�!\n");
			--i;
		}
	}
}

void print_nums(int* lotto_nums) {

	int temp;
	printf("\n�ζ� ��ȣ: ");
	//for (int i = 0; i < 5; ++i) {
	//	temp = i;

	//	for (int j = i + 1; j < 6; ++j) {
	//		if (lotto_nums[temp] > lotto_nums[j]) {
	//			temp = j;
	//		}
	//	}
	//	int temp_arr = lotto_nums[i];
	//	lotto_nums[i] = lotto_nums[temp];
	//	lotto_nums[temp] = temp_arr;
	//}

	for (int i = 0; i < 6; ++i) {
		printf("%d ", lotto_nums[i]);
	}
}