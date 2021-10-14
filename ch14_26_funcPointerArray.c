#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// �Լ� �������� �迭�� ����ϴ� ���� ������ Ǯ�� ����.
//
// �Ʒ����� �����ִ� �ڵ带 ����ؼ�
//

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);	//TODO: add a new menu

int main() {
	char options[] = { 'u', 'l' };	//TODO: add a new menu
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower };	//TODO: add a new menu

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");
	
	return 0;
}

// ���� �͸� ���� �������� ������ ������ �� ����. 
// ���ݱ��� �̷� ���¸� ������ �ñ� ������ ������ ������ �� ���� ���̴�. 
// 
// ���� ����� ������ ����. 
// Enter a string
// >> Hello World
// Choose an option:
// u) to upper
// l) to lower
// u	<= u�� �Է��ϸ�,
// HELLO WORLD	<= �빮�ڷ� ��µȴ�. 
// 
// Ư���� ����, 
// typedef void (*FUNC_TYPE)(char*);
// FUNC_TYPE operations[] = { ToUpper, ToLower };	//TODO: add a new menu
// <= �Լ� �������� �迭�� ��� �ִ�. 
//    �̰��� �� Ȱ���ؼ� ������ Ǯ�� ���ƶ�. 