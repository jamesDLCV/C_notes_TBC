#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �ĺ����� ������ scope ����,
// �޸� ������ �����ϰ� �ִ� ��ü�� �޸𸮿����� duration ���� �Ⱓ���� ����.

/*
	Variable scopes (visibility ������ ���ü�)
	- �������� 4������ �ִ�. 
	  block, function, function prototype, file.
*/

// ���⿡���� file scope�� ���ؼ� ���캸��.

int g_i = 123;		// global variable, file scope�� ���´�. 
int g_j;			// global variable, �ʱ�ȭ�� �� �ߴ�. 

void func1() {
	g_i++;			// usese g_i
}

void func2() {
	g_i += 2;		// uses g_i

	// local = 456;	// Error, main() �Լ��� ���������� ����Ǿ���. 
					// func2()������ �� ���� ����. 
}

int main() {
	int local = 1234;

	func1();
	func2();

	printf("%d\n", g_i);	// uses g_i
	printf("%d\n", g_j);	// Not initialized? Warning�� �� ���. 
							// BSS segment���� �Ѳ����� 0���� �ʱ�ȭ�Ѵ�. 
	printf("%d\n", local);
	
	//126
	//0			<= ��ǻ�Ͱ� 0���� �ʱ�ȭ�� ����ٴ� ���� �� �� �ִ�. 
	//1234

	return 0;
}

//int g_i = 123;		// global variable, file scope�� ���´�. 
//int g_j;
// ���� �͵��� �� �������� global variable�̶�� �Ҹ������� 
// linkage�ϰ� ���� ���� �Ѵ�. 
