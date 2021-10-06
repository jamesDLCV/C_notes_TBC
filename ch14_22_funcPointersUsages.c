#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>	// toupper(), tolower()

// Function Pointers, �Լ� �������� ��� ���
//
// �Լ� �����Ͱ� ���α׷����� �󸶳� �����ϰ� ������� ���� ���ڴ�.

// toupper() �Լ��� ����ؼ� ���ڿ��� ��� �ִ� ��� ���ڸ� �빮�ڷ� �ٲ� �ش�.
void ToUpper(char* str) {		
	while (*str) {
		*str = toupper(*str);	// ctype.h�� ��� �ִ� �Լ� toupper()
		str++;
	}
}

// �� ���ھ� �ٲ� �ִ� tolower() �Լ��� �̿��ؼ� ���ڿ� ��ü�� �ҹ��ڷ� �ٲ� �ش�.
void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);	// ctype.h�� ��� �ִ� �Լ� lower()
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

	/*
		passing function pointers to functions
	*/

	return 0;
}

// �� void ToUpper(char* str) �Լ��� 
// void ToLower(char* str) �Լ��� Ư¡��,
// �Է��� ���ڿ��̴�. ������ �����ͷ� �� �ִ� ���ڿ��̴�. 
// ���ڿ��� �Է� �������� char* str�� ���� �� ����. 
// �׸��� ��ȯ�� Ÿ���� void�̴�. ��ȯ���� ����. 
// �� �Լ��� parameter�� return type�� �����ϴ�. 
// 
// ��, ������ �Լ� �����͸� ���ؼ� 
// void ToUpper(char* str)�� ����� ���� �ְ�, 
// void ToLower(char* str)�� ����� ���� �ִ�. 
// 
// 
	/*
	char str[] = "Hello, World!"; <= ��ҹ��ڰ� ���� �ִ� ���ڿ�

	void (*pf)(char*); <= �Լ� �����͸� �����ߴ�. 
	 <= �Լ� �������� �̸�(�ĺ���, identifier)�� pf�̰�,
	    �Լ� �������̹Ƿ� �տ� asterisk *�� �ٿ� ����. 
		parameter�� ���� ���� char*�� �־� ���. 
		��ȯ�� ���� void�� �־� ���. 	    

	pf = ToUpper;	// Name of a function is a pointer
	 <= ToUpper()��� �Լ��� �̹� �����ϰ� ������ ����. 
	    ������ pf�� ToUpper() �Լ��� ����Ű���� ������ �� �� �� �ִ�. 
     <= ������ �� �� �� �� ���� ������ �ִٰ� �� ���ǿ��� ����ߴ�. 
	    �ϳ��� pf = ToUpper;�̰� �� �ٸ� �ϳ��� pf = &ToUpper;�̴�. 	 
	 <= pf = &ToUpper;		// Acceptable
		�Լ� �̸�(�ĺ���) �տ� addressof operator�� �ٿ��� ����� ���� �ִ�.
		�� ToUpper�κ��� �ּҸ� ���� �ͼ� �� �ּڰ��� �����Ϳ� ������ �� �ִ�. 
	 <= ���� �۵� ���� ���鿡�� ���� ����, 
		�Լ��� �̸� ��ü�� �� �Լ��� ����� �ִ� �޸��� �ּ��̴�. 
		��ġ �迭�� �̸��� ù ��° ������ �ּ�ó�� ���Ǵ� �Ͱ� ����ϴ�.
		�Լ��� �̸� ��ü�� �ּ��̱� ������ �׳� �ּҸ� ������ �� �ִ�. pf = ToUpper; 

	// pf = ToUpper(str);	//Not acceptable in C
	 <= ������ ToUpper(str) �̰��� �Լ��� �����Ų ���̴�. 
	    ��ȣ �ȿ� parameter�� ��� �ִ�. 
	    �� pf = ToUpper;�� pf = &ToUpper;�� ��ȣ�� ����. 

		pf = ToUpper(str);�� �ǹ̴� ToUpper(str) �Լ��� ������Ѽ� 
		�� ��ȭ���� pf�� ���Խ�Ű�ڴٴ� ���̴�. 
		���ʿ� �ִ� pf�� �Լ� �������̰�, ToUpper(str)�� ��ȯ���� ���� �Լ��̹Ƿ�
		Ÿ�Ե� �� �°�, ToUpper(str)�� �Լ��� �����Ų�ٴ� �ǹ��̹Ƿ� 
		pf = ToUpper(str);�� ������ ������ �ʴ´�. 
     <= pf = ToUpper;�� ���� �ν��ڸ� �־� �־��, 
	    �Լ� �����Ϳ� �Լ��� �ּҸ� �����ؼ� �־� �� ���� �ִ�. 

    // �ּҸ� ����� ����. 
	printf("String literal %lld\n", (long long)("Hello, World!"));
	 <= String literal 140701715045752
	printf("Function pointer %lld\n", (long long)ToUpper);
	 <= Function pointer 140701715010471
	
	<= "Hello, World!"�� ToUpper�� TEXT Segment�� ����� �ִ�.

	printf("Variable %lld\n", (long long)str);
	 <= Variable 56036948168
	    str ��ü�� �迭�� �̸��̱� ������ �ּ��̴�. 

	<= str�� stack�� ������ �ȴ�. �׷��� �ּҰ� TEXT Segment�ʹ� �ָ� ������ �ִ�.

	�Լ� �����͸� ������ �� �� �̷��� �����Ѱ�?
	void (*pf)(char*);
	�׳� ��� function�� �� ����ų �� �ִ� �Լ� �����͸� ����� ���� ������?

	�Լ� �����Ϳ� �⺻������ � parameter�� ��������, 
	��ȯ���� Ÿ���� ������ �̸� ������ �� ��� �ϴ� ������,
	�� �Լ� �����͸� ���ؼ� ������ ��Ű���� parameter�� ���� ������, 
	��ȯ���� �������� �˾ƾ� �ϱ� �����̴�. 

	(*pf)(str);
	 <= str�� parameter�� �־��ָ� ToUpper(str)�� �Ȱ��� ȿ���� �� �� �ִ�. 
	    �ֳ��ϸ� pf��� �����Ͱ� ToUpper�� ����Ű�� �ֱ� �����̴�. 

	pf = ToUpper;�� pf = &ToUpper;�� ��� ����� �ȴٰ� �տ��� ����ߴ�.
	�Լ� �����͸� ���ؼ� �Լ��� �����ų ����, �� �� ���� ������ ��� ����� �ȴ�. 
	pf(str);	//K&R X, ANSI OK
	 <= ���
	
	ù ��° ������, pf�� �������̴�. �Լ� �����͵� �������̴�. 
	�׷��Ƿ� indirection *�� �� ������ *pf(str) �̷��� ������ ���Ѿ� �Ѵٴ� �����̴�.

	�� ��° ������, ������ �Լ� �̸� ��ü�� �ּ��̴�. 
	�׷��Ƿ� pf(str) �̷��� �ٷ� ������ ���ѵ� �ȴٴ� �����̴�. 
	K&R ǥ�ؿ����� pf(str)�� ������� �ʾ�����, ANSI������ ����Ѵ�. 

	���� ���� ���� �����Ϸ��� ����� ���� ���� ���̱� ������ 
	pf(str)�� ���Ǵ� ������ �����ϸ� �ȴ�. 

	printf("ToUpper %s\n", str);

	pf = ToLower;
	*/
//
// �� �ڵ��� ������ ������� ���� ���� ������ ����. 
// pf = ToUpper; <= ToUpper �Լ��� �ּڰ��� �Լ� �����Ϳ� �����ؼ� ������ ���ٰ� 
// (*pf)(str);	 <= ���⿡�� ������ ��Ű��,                
// printf("ToUpper %s\n", str); <= �״��� str�� ��� ���ߴ��� ����� �� ����.
// 
// pf = ToLower; <= �Լ� ������ pf���ٰ� ToLower �Լ��� �ּڰ��� ������ ����,  
// pf(str);      <= �� �����͸� ���ؼ� ������ ��Ų��. 
// printf("ToLower %s\n", str);
// 
// pf = ToUpper;
// (*pf)(str)	 <= pf�� ����Ű�� �ִ� ���� ToUpper �Լ��̹Ƿ�, 
//                  ��ġ ToUpper �Լ��� �����Ų ��ó�� ������ �ȴ�. 
// pf = ToLower; <= pf�� ToLower �Լ��� ����Ű�� �ֱ� ������, 
// pf(str);      <= ��ġ ToLower �Լ��� �����Ų ��ó�� ������ �ȴ�. 
// 
// ������ ��Ű��,
// ToUpper HELLO, WORLD!
// ToLower hello, world!
// �� ��µȴ�. 
// 
// void ToUpper(char* str) 
// void ToLower(char* str) 
// <= �� �� �Լ��� �ٵ� ���� ������ ���� ����ϴ�. 
//    ���̴� toupper() �Լ��� ����ϴ���, tolower() �Լ��� ����ϴ����̴�. 
//    �׷��� �� �� �Լ��� ���ļ� �ϳ��� �Լ�ó�� � Ʋ�� ���� �� ������?
// 
// ����Ǵ� ������ ��� �ϳ��� �Լ��� �����, 
// �ٲ��� �ϴ� �κи� �ٲ� ���� �� �ְ� ����� �ָ�, 
// �ڵ��ϴ� �з��� �پ� ���, 
// ����, ������ �� �� ����� ���� ���, 
// �Ǽ��� �� Ȯ���� �پ���. 
// 
// �Լ� ������, ���Ŀ� ������ ���� ���� ���� �����(��ü������ ������)�� 
// �����ϰ� �� Ȱ���Ѵٸ� ���α׷��� �ξ� ���������� ��������. 
// 
// �� �� �Լ��� ��� ��ĥ��? 
// �Լ� �����͸� ���ؼ� ��ģ��. 