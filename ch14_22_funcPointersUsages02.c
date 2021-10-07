#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>	// toupper(), tolower()

// Function Pointers, �Լ� �������� ��� ���
//
// �Լ� �����Ͱ� ���α׷����� �󸶳� �����ϰ� ������� ���� ���ڴ�.

void ToUpper(char* str) {
	while (*str) {
		*str = toupper(*str);	// ctype.h�� ��� �ִ� �Լ� toupper()
		str++;
	}
}

void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);	// ctype.h�� ��� �ִ� �Լ� lower()
		str++;
	}
}

// ���� ������ Ȱ���ؼ� �� ToUpper() �Լ��� ToLower() �Լ��� ��ģ��. 
void UpdateString(char* str, int(*pf)(int)) {
	while (*str) {
		*str = (*pf)(*str);
		str++;
	}
}

int main() {

	char str[] = "Hello, World!";

	void (*pf)(char*);

	pf = ToUpper;	// Name of a function is a pointer
	// pf = &ToUpper;		// Acceptable
	// pf = ToUpper(str);	//Not acceptable in C

	printf("String literal %lld\n", (long long)("Hello, World!"));
	printf("Function pointer %lld\n", (long long)ToUpper);
	printf("Variable %lld\n", (long long)str);

	(*pf)(str);
	//pf(str);	//K&R X, ANSI OK

	printf("ToUpper %s\n", str);

	pf = ToLower;

	//(*pf)(str);
	pf(str);

	printf("ToLower %s\n", str);
	printf("\n");

	/*
		passing function pointers to functions
	*/

	UpdateString(str, toupper);

	printf("ToUpper %s\n", str);

	UpdateString(str, tolower);

	printf("ToLower %s\n", str);

	//Note: __cdecl is function calling convention

	return 0;
}

//
// ���� ������ Ȱ���ؼ� ��ģ��. 
	/*
	void UpdateString(char* str, int(*pf)(int)) {
	 <= char* str�� ���� parameters�̴�. 
	    int(*pf)(int) parameter�� �ϳ� �߰��Ǿ���. 
		<= UpdateString()�� ���� �Լ� ��ü�� parameter�� �ް� �ִ�. 
		   �����͸� ���ؼ� ����� ������ �Լ� ��ü�� parameter�� �ް� �ְ�, 
		   �� *pf�� ���ؼ� ������ �����Ų�ٴ� �ǹ��̴�. <= *str = (*pf)(*str);
     
	 <= �ٸ� ���� toupper(), tolower() �Լ��� �ٸ���.
	 
		while (*str) {
			*str = (*pf)(*str);
			 <= �����ų �Լ��� parameter int(*pf)(int)�� �޾ƿͼ�
			    �� ���� �Լ��� ��ģ��. 
			str++;
		}
	}
	*/
//
// 
	/*
		//	passing function pointers to functions	

	UpdateString(str, toupper);
	 <= UpdateString()�̶�� �Լ��� ȣ���ϴµ�, 
	    argument�� ���ڿ� string str�Ӹ� �ƴ϶�, 
		�Լ��� �ּ� toupper�� �μ��� �־ UpdateString() �Լ��� ȣ���Ѵ�. 
		toupper�� �ְ� ������ ��Ű��, ����� ����. 

	printf("ToUpper %s\n", str);

	UpdateString(str, tolower);
	 <= tolower �Լ��� �ּҸ� �μ��� �ְ� �����Ų �� ����� ����. 

	printf("ToLower %s\n", str);

	//Note: __cdecl is function calling convention
	*/
// <= ������ ���� UpdateString() �Լ��� ���ؼ� �빮�ڿ� �ҹ��ڰ� ����� ����� �ȴ�. 
// 
// ��ġ �Լ����� �����ؼ� ����ϴ� ������ ����. 
// �Լ� ������ �� �߿��� ��� �� �ϳ��̴�. 
// 
// Note: __cdecl is function calling convention
// �Լ� �����͸� ������ �� __cdecl �� �κ��� ���ø� �ϰ� �Լ� �����͸� ������ �Դ�. 
// <= �̰��� �Լ� ȣ�� �Ծ��̶�� �Ѵ�. 
// ���߿� �������� API�� ������ ��, �ڼ��ϰ� �����ϰ� �� ���̴�. 
// __cdecl�� ��� �����Ϸ��� ���������� ������ �ǵ��� ó���� �� �ش�. 
// 
// void UpdateString(char* str, int(*pf)(int)) �Լ��� 
// �μ��� int(*pf)(int), int (*pf)(int) �� ���� ��� �Ǵµ�, 
// 
// int (__cdecl *pf)(int) ó�� __cdecl�� �־� �൵ �Ȱ��� �۵��Ѵ�. 
// �⺻ ���������� __cdecl���� ������� �ʾƵ� �ȴ�. 
// 
// �Լ� �������� �⺻���� ��� ����� ���ؼ� ���� �ô�. 