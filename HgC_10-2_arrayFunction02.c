#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

//$ �迭�� ���� �Է��ϴ� �Լ�
// 
// �迭�� ���� �Է��ϴ� �Լ��� �迭�� ���� ����ϴ� �Լ��� ���� ����� �����ϴ�. 
// 
// �ٸ� �Է� �Լ��� �����͸� ������ �迭�� ��ġ�� �ʿ��ϹǷ�, 
// �Լ� �ȿ��� �����͸� ���� ����Ѵ�. 
// 
// ������ ���� �Ǽ� �迭�� ���� �Է��ϴ� �Լ��� �ִ��� ã�� �Լ��� ���� ����. 

void input_arr(double* ptr_a, int size);
double find_max(double* ptr_a, int size);
double find_max2(double* ptr_a, int size);
void print_arr(double* ptr_a, int size);

int main() {

	double arr[5];
	double max, max2;

	int size = sizeof(arr) / sizeof(arr[0]);	// �迭 ����� ���� ���

	input_arr(arr, size);						// �迭�� �� �Է�
	max = find_max(arr, size);					// �迭�� �ִ� ��ȯ
	max2 = find_max2(arr, size);

	printf("\n");
	printf("�迭�� �ִ�: %.1lf\n", max);
	printf("�迭�� �ִ�: %.1lf\n", max2);
	printf("\n");

	print_arr(arr, size);

	return 0;
}

void input_arr(double* ptr_a, int size) {	// double �����͸� �Ű� ������ ����

	printf("%d���� �Ǽ� �� �Է�: ", size);

	for (int i = 0; i < size; ++i) {		// size�� ���� ���� �ݺ� Ƚ�� ����
		scanf_s("%lf", ptr_a + i);			// &ptr_a[i]�� ����, 
	}                                       // �Է��� �迭 ����� �ּҸ� ����
}

double find_max(double* ptr_a, int size) {

	double max;

	max = ptr_a[0];		// ù ��° �迭 ����� ���� �ִ����� ����

	for (int i = 1; i < size; ++i) {
		if (max < ptr_a[i]) {
			max = ptr_a[i];
		}
	}
	return max;
}

double find_max2(double* ptr_a, int size) {

	double max;

	max = *ptr_a;		// ù ��° �迭 ����� ���� �ִ����� ����

	for (int i = 1; i < size; ++i) {
		if (max < *(ptr_a + i)) {
			max = *(ptr_a + i);
		}
	}
	return max;
}

void print_arr(double* ptr_a, int size) {

	for (int i = 0; i < size; ++i) {
		printf("arr[%d] = %.1f\n", i, *(ptr_a + i));	// ptr_a[i] 
	}
}

// ù ��° �迭 ����� ���� ptr_a[0]���� �ص� �ǰ�, *ptr_a�� �ص� �ȴ�.  
// 
// �� ������ double �� �迭�� ���� �Է��ϴ� �Լ��� 
// �Է��� �� �߿��� �ִ��� ã�� ��ȯ�ϴ� �Լ��� �����.
// 
// �̹� ���� �� �迭�� ���� ����ϴ� �Լ��� ũ�� �ٸ��� �ʴ�. 
// 
// scanf_s("%lf", ptr_a + i);	
// <= ptr_a�� i�� ���Ͽ� �� �迭 ����� �ּҸ� ���ϰ�, 
//    �� ���� �״�� scanf() �Լ��� ����ϴ� Ư¡�� �ִ�. 
// 
// scanf() �Լ��� �Է��� ���� ������ �迭�� ��ġ�� �˾ƾ� �ϹǷ�, 
// �μ��� ���� ptr_a�� ���� �״�� ����Ѵ�. 
// 
// *(ptr_a + i)�� ���� �������� �迭 ��Ҹ� ���ϰ�, 
// �ٽ� &(*(ptr_a + i))�� ���� �ּ� ������ ����� ���� ������, 
// ���ʿ��� ������ �ݺ����� �ʴ� ���� ����. 
// 
// �ٸ�, &ptr_a[i]�� ���� ���ȣ�� ����� �迭 ��� ǥ������ ����ص� ������ �ʴ�. 
// 
// ���� ���� ����(*)�� �ּ� ����(&)
//                     ptr_a + 2	�� ��° �迭 ��� �ּ�
//     *(ptr_a + 2) �Ǵ� ptr_a[2]	�� ��° �迭 ���
// &(*(ptr_a + 2)) �Ǵ� &ptr_a[2]	�� ��° �迭 ��� �ּ� 
//
// �迭�� ���� ����ϴ� �Լ��� print_arr()���� ������ �ô�. 