#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Լ��� ���� ���� �з�
// 
// ���ݱ��� ������ ���� ���� �з��� ���ؼ� �����ߴ�. 
// �Լ��� ���� ������ ���ؼ� ���� ���ڴ�. 

/*
	Storage Classes and Functions
	- Functions external (by default) or static
	- A function declaration is assumed to be extern
*/

// external�� static�� ��� �����ϴ�. 
// �Լ��� ó���� ���α׷��� �Բ� loading�� �ȴ�. 
// �޸𸮿� ��� �ִ�. 
// function pointer�� �� �ּҸ� ��� �� ���� �ִ�. 
// 
// �⺻������ function declaration�� extern�̶�� �����ǰ� �ִ�. 
// ��� �Լ��� ������ extern�̴�. 
// �Ʒ� �Լ��� ���� ������ ���� ������ ���� extern�� �پ� �ִ�. 
// extern void fun();
// extern void fun_second(); 
// ������, �Լ��� ���ϱ� ������ extern�� ������ �� �ִ�.  
// 

int g_int = 123;	// defining declaration
//TODO: try static

// main() �Լ����� ����ϱ� ���� �Լ��� prototype�� ������ �ش�. 
void fun();			// �ٸ� �Լ��� ���� �����̴�. 
void fun_second();	// �ٸ� ���Ͽ� �ִ� �Լ��� ���� �����̴�. 

int main() {
	fun();
	fun_second();

	return 0;
}

void fun() {
	extern int g_int;	// optional

	g_int += 1;
	printf("g_int in fun() %d %p\n", g_int, &g_int);
}

// second.c ���Ͽ� �ִ� �Լ� void fun_second(void) �տ� static�� �ٿ� �ָ�
// ��� �ɱ�?
// unresolved external symbol _fun_second_referenced in function _main
//	<= main() �Լ����� fun_second() �Լ��� ã�µ� ����. 
// fatal error LNK1120 ��ŷ ������ ���. 
// second.c���� �Լ��� ������ �� static�� �ٿ��� scope�� ���� ������,
// second.c ���� �ȿ����� ����� �� �ְ� �� ���� �����̴�. 
// 
// ��ŷ�� �� ��, ã�� ���� ���� ���̴�. 
// static Ű���尡 �Լ������� ���������� ���������� �����ϰ� ���ȴ�. 
// 
// �Լ��� ����ó�� ������ �� �ʿ䰡 ������?
// ��� �Լ��� ��𿡼��� �� ���� ������ ������?
// static���� ���� ������ �� ���� �ʿ��ұ�?
// 
// �츮�� ������ ���� ���� ����̶�� �������� ���� ���� ����. 
// � ����� �ϴ� �Լ����� ��� ����, 
// �ٸ� ����� �ϴ� �Լ����� �� �ٸ� ���Ͽ� ��� ���´�. 
//	<= ���Ϻ��� ������ �� �δ� ���̴�. 
// 
// ���� second.c ���Ͽ����� ���Ǵ� �Լ� tool()�� �ִٰ� �����ϸ�, 
// �� �� ��� �ۿ����� tool() �Լ��� ���Ǵ� ���� ���� ������ �ʹٸ�, 
// �Լ� �տ� static�� ���� ���� �ִ�. 
// 
// �̷��� ��⺰�� �Լ��� ������ ���� ��, static �Լ��� ���� �� �ִ�. 
// static�� pototype �տ� �ٿ��� �ǰ�, �Լ� ���Ǻ� �տ� �ٿ��� �ȴ�. 
// <= linking�� ���� �ʰ� ���� ������ ȿ���� �ִ�. 
// 
// �Լ��� ���� ���� �з��� ���ؼ� ���� �ô�. 