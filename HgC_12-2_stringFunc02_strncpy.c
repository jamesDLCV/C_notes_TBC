#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//$ ���ϴ� ������ ���ڸ��� �����ϴ� strncpy() �Լ�
// strncpy() �Լ��� ���ڿ��� ������ ��, ������ ���� ������ �� �ִ�. 
// 
// ���� ���, ���ڿ� "apple-pie"�� �տ��� 5���� ���ڸ� char �迭 str�� �����Ϸ���,
// ������ ���� ����Ѵ�. 
// 
// strncpy(str, "apple-pie", 5);
//          |        |       |      
//      ���� ����   ������   ������    
//      �迭��      ���ڿ�   ���� �� 

int main() {

	{
		// ���ڵ� 12-9. strncpy() �Լ��� ����� ���ڿ� ����
		char str[20] = "mango tree";	// �迭 �ʱ�ȭ

		strncpy(str, "apple-pie", 5);   // "apple-pie"���� �ټ� ���ڸ� ����

		printf("%s\n", str);			// ���� ���� ���ڿ� ���
										// apple tree
	}
	puts("");
	{
		char str[20] = "mango tree";	
		strncpy(str, "apple-pie", 5);  

		str[5] = '\0';

		printf("%s\n", str);			// apple
	}
	
	return 0; 
}

// ���� ������� Ȯ���� �� �ֵ��� strncpy() �Լ���, 
// ������ ���ڿ����� ������ ������ŭ ���ڸ� �����ϰ� �� ���ڴ� �������� �ʴ´�.
// 
// ����, str �迭���� mango�� apple�� �ٲ�Ƿ�, 
// �ᱹ str �迭�� ����� ���ڿ��� "apple tree"�� �ȴ�. 
// 
// strncpy(str, "apple-pie", 6); <= ������ ���� ���� 6���� �ٲٸ�, 
// ����� apple-tree�� �ȴ�. 
// 
// ���� str �迭�� ���ڿ� "apple"�θ� ���̵��� �Ϸ���, 
// apple�� ������ �Ŀ� �� ���ڸ� ������ �����ؾ� �Ѵ�. 
// 
// str �迭  | a | p | p | l | e |   | t | r | e | e | \0|
//                                 |
//                     ���⿡ �� ���ڸ� ä�� �ִ´�. 
// <= str[5] = '\0';