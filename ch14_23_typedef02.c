#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	"One good way to synthesize declarations is
	in small steps with typedef, ..."
	- K&R book Chapter 5.12
*/
// <= ������ ������ ���ظ� �� ��, typedef�� �߰� �ɰ��� �����ϸ� ���� ���ϴ�. 
//	  �����ε� ���� ���̴� ����̴�.
// 
// ������ ������ ��� �����ϴ����� ���ؼ��� �̾����� ���ǿ��� �� �� �����Ѵ�. 
// 
// ���⿡���� typedef�� ������ �����ϰ� ����� �ش�. ���ϴ� ������ �����ϸ� �ȴ�. 

/* Complicated Function Declartions */

char char3[3] = { 'A','B', 'C' };

char(*complicated_function1())[3]{ // Function Returns Pointer to Char[3]
	return &char3;	// Returns a pointer to char[3]
}
// <= � �Լ��� �ϳ� �ִ�. �Լ� ����ΰ� �� �����ϴ�. 
//    �� �Լ��� ����� Char[3], char �� ��¥�� array�� ���� �����͸� �����ϴ� �Լ��̴�.
//    �̷� ���� ��� �о� �������� ���� ���ǿ��� ���� �� ���̴�. 
// �̹� ���ǿ����� char(*complicated_function1())[3] �̷� �Լ��� 
// typedef�� ����ؼ� ��� ���ϰ� ����� �� �ִ����� ���ؼ� ���� ����. 
// <= &char3�� char �� ��¥�� array�̴�. 
//    return &char3;�� char �� ��¥�� array�� ��ȯ�ϰ� �ִ�. 
//    char3�� �����͸� ��ȯ�� �ִ� �Լ��̴�. 
// 
// char(*complicated_function1())[3] �� �Լ��� ���� ������ ������ �����Ѵٰ� �ϸ�,
// <= char(*(*fptr1)())[3] = complicated_function1; �̷��� �ؾ� �Ѵ�. 
//    �� �����ϴ�. 
//	  char(*(*fptr1)())[3]�� ��� ����ϴ����� ���ؼ��� ���� ���ǿ��� �ٷ��. 
// 
// �׷��� typedef�� ����ϸ�, 
typedef char(*FRPTC3())[3];	// Function Returns Pointer To Char[3]
typedef char(*(*PTFRPTC3)())[3];

char(*(*fptr1)())[3] = complicated_function1;

FRPTC3* fptr2 = complicated_function1;
// <= �̷���
PTFRPTC3 fptr3 = complicated_function1;
// <= �Ǵ� �̷��� �����ϰ� ����� �� �ִ�. 

// char(*(*fptr1)())[3] = complicated_function1;����
// FRPTC3* fptr2 = complicated_function1; Ȥ��
// PTFRPTC3 fptr3 = complicated_function1;�� �ξ� �����ϴ�. 
//
// typedef�� ����ϸ� ����. ��ü���� ����� ���� ���¿��� ���� ����. 
// 
// ���⿡�� �� �������� �� �ִ�. 
// char(*complicated_function1())[3] �� �Լ� ��ü�� �ϴ� �����
// �� ��¥�� char Ÿ�� array�� �����͸� ������ �ִ� �Լ��̴�. 
// �׷��� 

/* Use typedef to make declarations simpler */

typedef char c3[3];
// <= char�� �� ��¥�� �迭�� c3��� �̸��� �ڷ������� ������ �ִ� ���̴�. 
//    [3]�� �� �ڿ� �پ� �ֳ�? ����� �׷��� �� �ְ� ���� ���ǿ��� �ڼ��� �ٷ��. 
// <= c3��� �ڷ����� char �� ���̴�. �� ���� ��ó�� �پ� �ִ�. 
// 
// �׷��� ���� �ִ� 
// char(*complicated_function1())[3] �� �Լ��� 
// �Ʒ��� ���� �پ���.  

c3* complicated_function2() {
	return &char3;	// Return a pointer to char[3]
}
// <= �̷��� ����ϸ� �ſ� �������̴�. 
//    �Լ� �̸� �ְ�, �Ű������� ���� ����.
//    ��ȯ �ڷ����� c3�� �������̴�. 
// �ξ� �����ϱ� ��������. 
// ������ ����� ���� �ξ� ���ϴ�. 

int main() {
	char(*ret_val)[3] = fptr1();

	printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);

	c3* my_c3 = fptr2();
	// <= char(*ret_val)[3] = fptr1();�� ������ ����� ������, 
	// ���� �ſ� �������̴�. 
	// c3��� � �ڷ����� �������̴�. 
	// c3�� ã�Ƽ� ���� �ö� ����, typedef char c3[3];
	// char �� ���� array�� ���� �� �� �ִ�. 
	// �̷��� �о� ���̸� �����ϱ� �ξ� ����. 
	// 
	printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]);
	//<= printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);��
	//	 �����ϰ� �۵��Ѵ�. 

	return 0;
}

// ������ �� ����, 
// A B C
// A B C
// <= �����ϰ� ��µǴ� ���� Ȯ���� �� �ִ�. 
// 
// typedef�� ���� ���� ����� ���� �ô�. 