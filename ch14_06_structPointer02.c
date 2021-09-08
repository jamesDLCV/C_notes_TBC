#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct my_data {
	int a;
	char c;
	float arr[2];
};

int main_example() {
	struct my_data d1 = { 1234, 'A', };

	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	printf("%f %f\n", d1.arr[0], d1.arr[1]);
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);

	struct my_data d2 = d1;

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	printf("%f %f\n", d2.arr[0], d2.arr[1]);
	printf("%lld %lld\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

	return 0;
}

// �� �߻����� ����ü my_data�� �ִ�. 
//  float arr[2] <= float�� �迭 arr[2]�� ������ �ִ�. 
//  ���� ���������� �̰��� �����ͷ� �ٲ㼭 ���� �Ҵ��� ���� ���̴�. 
// 
// ������ ���� �ʱ�ȭ�� �� �� ���� ������,
// struct my_data d1 = { 1234, 'A', {1.1f, 2.2f} };
// 
// �Ʒ��� ���� 
// struct my_data d1 = { 1234, 'A', };
// <= float arr[2]�� ���� �ʱ�ȭ�� �Ʒ��� ���� ���� ��� �� �� ���� �ִ�. 
// 
// d1.arr[0] = 1.1f;
// d1.arr[1] = 2.2f;
//
// �״��� d1.a, d1.c, �׸��� (long long)d1.arr �ּҸ� ����� ����.  
	/*
	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	printf("%f %f\n", d1.arr[0], d1.arr[1]);
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);
	*/
// �׸��� ������ ���� �ּҵ� ����� ����. 
// 
// struct my_data d2 = d1;
// <= ���� �����ڷ� ����ü�� �����Ѵ�. 
//    ����ü�� �����ϸ� ���������� ���縦 �� �ش�. ���� ���ϴ�.
//    d2�� d1�� ������ �ش�.
//    d1�� ������ �ִ� ������ d2�� ���縦 �ϴ� ���̴�. 
//    
// ���� ���� �����ڰ� ���ǰ� �� �� �ִٸ�, 
// struct my_data d2;
// d2.a = d1.a;
// d2.c = d1.c;
// d2.arr[0] = d1.arr[0];
// d2.arr[1] = d1.arr[1];
// <= �̷��� ������ ����� ������ ��� �Ѵ�. 
//  
// ����� �� ����, 
// printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
// printf("%f %f\n", d2.arr[0], d2.arr[1]);
// printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);
// 
// d1.arr, d2.arr 
// <= array�� �̸��� �ּ�ó��(������ó��) ����� �� �ִ�.
//  
// d1�� d2�� �ּҴ� ���� �ٸ���.
// ������ �� �شٰ� �ؼ� �ּҰ� ���������� ���� �ƴϴ�.
// �޸𸮿� ����� �ִ� ���鸸 ���簡 �ȴ�. 
// d1�� d2�� �ٸ� �޸𸮸� ������ �ִ�. 
// 
// printf("%f %f\n", d1.arr[0], d1.arr[1]); ��
// printf("%f %f\n", d2.arr[0], d2.arr[1]); �� ���� 
// <= ������ ���� ��µȴ�. 
//    �迭�� ������ �ִ� ���� ���縦 �� ��� �����̴�. 
// 
// ������ ����, 
// 1234 A 1036424771696
// 1.100000 2.200000
// 1036424771696 1036424771700	<= 4 ����Ʈ ���̰� ����. float�� 4 ����Ʈ�̹Ƿ�.
//
// 1234 A 1036424771744
// 1.100000 2.200000
// 1036424771744 1036424771748	<= 4 ����Ʈ ���̰� ����. �迭�̴�. 
// 
// ���� ���� ������ �����Ϸ��� ����ϸ�,
// struct my_data d2 = d1; �� �� �� ���� �ִ�. 
// <= �������� ����� �ϳ� �ϳ� ������ ������ ��� �ߴ�. 
// 
// ���� �ٸ� ������ ���� ����.