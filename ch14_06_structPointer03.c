#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//

struct my_data {
	int a;
	char c;
	float* arr;		// �������̴�
};

int main() {

	struct my_data d1 = { 1234, 'A', NULL };

	d1.arr = (float*)malloc(sizeof(float) * 2);	// ���� �Ҵ����� �޸𸮸� �޴´�.
	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	printf("%f %f\n", d1.arr[0], d1.arr[1]);
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);

	struct my_data d2 = d1;

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	printf("%f %f\n", d2.arr[0], d2.arr[1]);
	printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

	return 0;
}

// float* arr; arr�� �����ͷ� ������ �ְ�, 
// ���� �Ҵ����� �޸𸮸� �޴� �� �ܿ��� ��� ���� ������ �����ϴ�.
// 
// ���� �Ҵ����� �ް� �迭ó�� ����ϰ� �ִ�. 
// 
// array�� �̸��� �ּ�ó��(������ó��) ����� �� �ִ�.
// d1.arr <= printf() �ϸ� �ּڰ��� ��µȴ�. 
// 
// d1.arr[0], d1.arr[1]��
// d2.arr[0], d2.arr[1]�� ������ ���� ���´�. 
// 
// ���⿡���� �ּڰ��� ��� �����ϴ�. 
// <= ���� �Ҵ����� �޾ƿ� �޸��� �ּڰ��� �����ϰ� �ִ�. 
//    struct my_data d2 = d1;���� float* arr�� �ִ� �ּڰ��� �����Ѵ�.
// 
// struct my_data d2 = d1;
// <= ��������� d1�� d2�� �޸𸮸� �����ϰ� �ִ�. 
//    d1.arr�� d2.arr�� ������ �ִ� �ּڰ��� �����ϴ�. 
//    ���� ������ �ִ� �޸𸮸� ����Ű�� �ִ�. 
// 
// �� ������ ���� ��� �� ����� �� �ֶ�.
// �� ������ � �� �����ϵ��� ������ �� �� �ִ� ���� �Ǽ��� ������ �� �� �ִ�.
// 
// ����ü�� �����Ϳ� �����ؼ� �����ؾ� �� ���� �� ������ ���� �ô�. 