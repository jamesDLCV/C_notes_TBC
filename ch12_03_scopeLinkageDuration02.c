#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �ĺ����� ������ scope ����,
// �޸� ������ �����ϰ� �ִ� ��ü�� �޸𸮿����� duration ���� �Ⱓ���� ����.

/*
	Variable scopes (visibility ������ ���ü�)
	- �������� 4������ �ִ�.
	  block, function, function prototype, file.
*/

// block, function, function prototype�� ���ؼ� ���캸��.

void f1(int hello, double world);	// to the end of the prototype declaration
									// void f1(int, double);�� �ص� �ȴ�. 
		// function prototype������ type�� �߿����� name�� �߿������� �ʴ�. 
		// ������ hello�� world�� ���ִ� ���� ����, ������ �����ϴ�. 
		// ���� function prototype���� hello�� world�� ū �ǹ̰� ����. 
		// function prototype��, 
		// ��� �Լ��� �ִ��� �˷��ִ� ���ʿ� ���� ������ �Ѵ�. 
		// ������ �����ִ� ���� ����. 
		// �̰��� function prototype scope�̴�. 
// void vla_param(int n, int m, double ar[n][m]);	// gcc only
//(����) VLA�� ���̸� ��������� �ϱ� ������ ������Ÿ�Կ��� �ĺ��ڸ� ������ �� ����. 

double func_block(double d) {
	double p = 0.0;

	int i;
	for (i = 0; i < 10; ++i) {
	//for (int i = 0; i < 10; ++i) // c99 ���Ŀ��� �̷��� ��뵵 �����ϴ�.
		double q = d * i;
		p *= q;

		if (i == 5)
			goto hello;
	}

// goto���� ������ �����Ƿ� �׳� ���� �Ѵ�. 
hello:
	printf("Hello, World");

	return p;
}


void func1() {
	

}

void func2() {
	

}

int main() {
	
	func_block(1.0);

	return 0;
}

void f1(int hello, double world) {

}
