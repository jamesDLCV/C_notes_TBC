#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���� ������ ���� ����
// static variabes with internal linkage
// �� ���ǿ��� ���� �� static variables with external linkage�� 
// ���� ���� linkage �ϳ��� �ٸ���. 
// ������, ���� ������ ���� ������ ���ο����� ����� �� �ִ�. 
// �� ���� ���� �ȿ����� �� �� �ְ�, ����� �� �ִ�. 
// ��� �Լ� �ۿ��� static Ű���带 ����Ѵ�.
//  
// ������Ʈ ���� ������ �� �� �������.

/*
	Static variable with internal linkage
	- File scope, external linkage, static storage duration
	- Internal storage class
*/

static int g_int = 123;	// defining declaration

void fun();
void fun_second();
void fun_third();

int main() {
	fun();
	fun_second();
	fun_third();

	return 0;
}

void fun() {
	extern int g_int;	// optional
	g_int += 1;
	printf("g_int in fun() \t\t%d %p\n", g_int, &g_int);
}

// �� ���Ͽ����� 
// int g_int = 123;		// defining declaration
// ���� g_int�� ���Ǹ� �ߴ�. 
// 
// �ٸ� ���Ͽ����� 
// extern int g_int;	// referencing declaration
// ������ ���Ǹ� �Ѵ�. 
// �̷��� �� �� �� linking�� �ϴ� ��������, 
// linker�� �ٸ� ������ �����ϵż� ������� obj ���Ͽ��� g_int�� ã�Ƽ�, 
// ������ ���� �ش�. 
// 
// void fun_second(void) �Լ����� main() �Լ��� ���� �޸𸮸� �����ϰ� �ȴ�. 
// ���� ����, ���� obj�� ����ϰ� �ȴ�. 
// �׷��Ƿ� main() �Լ��� &g_int�� fun_second(void) �Լ��� &g_int��,
// fun_third(void) �Լ��� &g_int�� ��� ���� �ּڰ��� ���´�.  
// 
// g_int�� ������ ��, 
// main() �Լ������� defining declaration�̰�, 
// �ٸ� �Լ������� referencing declaration�̴�. 
// 
// �ϳ��� ��¥�� �������� �̷� �� ��� �����ϱ� �̰��� linking ���� �޶�� ���̴�.
// extern Ű���带 �Ἥ �ٱ��� �̷� �� �����ϱ� linking�� ���� �޶�. 
// main() �Լ��� �ִ� ���� second.c�� third.c�� �ִ� ��ó�� ����� �� �ְ� �� �޶�.
// 
// g_int�� defining declartion �ʱ�ȭ�� �� �������� �ؾ� �Ѵ�. 
// main() �Լ����� �ʱ�ȭ�� �ߴٸ� �ٸ� ���Ͽ����� extern���� ������ �� ���� �ִ�. 
// ������ ���� �̸����� �ʱ�ȭ�� �ٽ� �� ���� ����. 
// ���� second.c ���Ͽ��� �ʱ�ȭ�� �ߴٸ� 
// �ٸ� ���Ͽ����� ���� ���������� �ʱ�ȭ�� �� �� ����. 
// <= �� ������ ����̴�.
// 
// ������, �⺻������ main() �Լ� ���� int g_int = 123;�� ����
// ������ ���� ������ ����ϴ� ���� �������� �ʴ´�. 
// �ʹ� ���������� �����̴�. 
// �Ȱ��� ������ ���⼭ ����ϰ� ���⼭ �ٲ�� �ϸ� debugging�� �ϰų�, 
// ���α׷� ����, ������ �������� �ʴ�. 
// 
// � ��쿡�� g_int�� file scope������ ����� �� �ֵ��� �����ϴ� ��쵵 �ִ�. 
// ��� �ϸ� �ٸ� ���Ͽ����� ������� ���ϰ� ���� ������?
// static int g_int = 123; �� ���� 
// �տ��ٰ� static Ű���带 �Ἥ ���� ������ �ȴ�. 
// 
// static�̶�� Ű������ �ǹ̴�, g_int ������ �� scope �ȿ� �����ǵ��� ������ �ش�.
// �ռ� block scope�� �ִ� ���� �տ��� static�� �ٿ���, 
// �޸𸮿� ��� ������ ���·� �����ϰ� ������, 
// block scope �ȿ����� �۵��ϴ�(����ϴ�) ��쿡 ���ؼ� ���� �ô�. 
// 
// file scope�� ���� ���� �տ� static�� ���̸�, 
// linkage�� ����� �� ���� ����. ������ ���� �� ���� ����. 
// �ٸ� ���Ͽ��� extern Ű���带 ����ϴ��� �� ������ ã�� �� ���� �ȴ�. 
// �������ؼ� linking�� �õ��ϸ�, error LNK2001: ~ �� ���� ��ŷ ������ ���. 
// 
// main() �Լ��� g_int�� static�� �ٿ� �ָ� (static int g_int = 123;), 
// second.c ������ int g_int�� �ٸ� �ּҰ��� ���� ���ο� ������ �ȴ�. 
// third.c ���Ͽ� �ִ� extern int g_int;�� second.c ������ g_int�� 
// linking�� �ȴ�. 
// 
//g_int in fun()          124 00BEA000
//g_int in fun_second()   1 00BEA584
//g_int in fun_third()    2 00BEA584
// 
// �� �ᱣ���� ����, fun_second()�� fun_third()�� g_int ������ �ּڰ��� ����. 
// 
// ���� second.c�� g_int�� 
// static int g_int; �� ���� static���� ���� ������, 
// third.c������ extern int g_int;�� referencing declaration�� �� �� ����. 
// �������ϸ� fatal error LNK1120: ~ ���� ��ŷ error�� ���. 
// 
// �ʱ�ȭ ���� �� �־ 0���� �ʱ�ȭ�� ������, �ʱ�ȭ ���� �־� �ִ� ���� �����Ѵ�.
// <= �ʱ�ȭ�� �� �ִ� ���� �����Ѵ�. 
// 
// ���� ������ ���ο����� ���� �ô�. 
//