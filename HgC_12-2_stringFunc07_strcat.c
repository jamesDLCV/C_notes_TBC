#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ ���� ����� strcpy() �Լ�

char* my_strcat(char* ptr_d, char* ptr_s);

int main() {

	char str[80] = "straw";

	printf("�ٲٱ� �� ���ڿ�: %s\n", str);	// �ٲٱ� �� ���ڿ�: straw

	my_strcat(str, "berry");

	printf("�ٲ� �� ���ڿ�: %s\n", str);		// �ٲ� �� ���ڿ�: strawberry
	printf("�ٸ� ���ڿ� ����: %s\n", my_strcat(str, "kiwi"));
									// �ٸ� ���ڿ� ����:  strawberrykiwi
	return 0;
}

char* my_strcat(char* ptr_d, char* ptr_s) {

	char* ptr_o = ptr_d;

	while (*ptr_d != '\0') {
		ptr_d++;
	}

	while (*ptr_s != '\0') {
		*ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
	}

	return ptr_o;
}
//
//                100 101 102 103 104 105  ...
//       105      | s | t | r | a | w | /0|   |   |   |   | ���� ���� str �迭
//                                      |   |   |   |   |
//  ������ ptr_d-------------------------|   |   |   |   |
//                                      |   |   |   |   |  ����
//                                    200 201 202 203 204 205
//                            200     | b | e | r | r | y | \0| ������ ���ڿ� ���
//                                      |   |   |   |   |
//                        ������ ptr_s-------------------