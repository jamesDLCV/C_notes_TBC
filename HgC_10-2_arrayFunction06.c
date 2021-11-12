#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 도전 실전 예제
// 도전 1. 로또 번호 생성 프로그램
// 
// 1 ~ 45 중에 6개의 서로 다른 수를 배열에 입력하고 출력한다. 
// 입력한 수가 이미 저장된 수와 같으면 에러 메시지를 출력하고 다시 입력한다. 

// 해답

void input_nums(int* lotto_nums);	// 배열에 로또 번호를 입력하는 함수
void print_nums(int* lotto_nums);	// 배열에 저장된 값을 출력하는 함수

int main() {

	int lotto_nums[6];				// 로또 번호를 저장할 배열

	input_nums(lotto_nums);			// 입력 함수 호출
	print_nums(lotto_nums);			// 출력 함수 호출
	puts("");

	return 0;
}

void input_nums(int* lotto_nums) {

	int num;
	int i, j;
	int dup;

	printf("1 ~ 45 중의 숫자를 입력하세요: \n");
	for (i = 0; i < 6; ++i) {
		printf("%d 번째 번호를 입력하세요: ", i + 1);
		scanf("%d", &num);

		if (num < 1 || num > 46) {
			printf("1 ~ 45까지의 숫자를 입력하세요.\n");
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
			printf("같은 번호가 있습니다!\n");
			--i;
		}
	}
}

void print_nums(int* lotto_nums) {

	int temp;
	printf("\n로또 변호: ");
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