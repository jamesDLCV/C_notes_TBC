#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ gets() �Լ��� ����� ���ڿ� �Է�
// scanf() �Լ��� �߰��� ������ ���Ե� ���ڿ��� �� ���� �Է��� �� ����. 
// ������ ������ �־�� �� ���� �ִ�.
// 
// �׷� ���� gets() �Լ��� ����Ѵ�. 
// �߰��� �����̳� �� ���ڸ� �����Ͽ� ���ڿ� �� ���� �Է��Ѵ�. 

// gets() �Լ� ����
// char* gets(char* str);

int main() {

	{
		// ���ڵ� 12-4. gets() �Լ��� �� ���� ���ڿ� �Է�
		char str[80];

		printf("������ ���Ե� ���ڿ� �Է�: ");
		gets(str);									// apple jam �Է�
			
		printf("�Է��� ���ڿ��� %s�Դϴ�.", str);		// apple jam ���
	}
	puts("");

	// gets() �Լ��� Ű����� Enter�� ���� ������ �Է��� �� ���� char �迭�� �����Ѵ�.
	// ���۸� ����ϹǷ�, Ű����� �Է��� �����ʹ� �ϴ� ���ۿ� ����� �Ŀ� 
	// gets() �Լ��� ���� �´�.
	// 
	// �߰��� �ִ� �����̳� �� ���ڵ� ��� �������Ƿ�, �� ������ �� ���� ������ �� �ִ�.
	//
	// �̶� ���� �ִ� ���� ���ڸ� ó���ϴ� ����� �ָ��ؾ� �Ѵ�.  !!!

	//$ �߿� 1. ���ۿ��� ���� ���ڸ� ����������, �迭���� �� ���ڷ� �ٲ� �����Ѵ�.
	//
	//   Ű���� �Է�                              ����
	//        apple jam  ----> | a | p | p | l | e |   | j | a | m | \n|
	//   Enter�� ���� ��,        <-------------------------------------->
	//    ���� ���ڱ���                          | ��� �迭�� ����������,
	//    ���ۿ� ����                            | ���� ���� ��� �� ���ڸ� ���δ�.
	//                                          |
	//                str �迭  | a | p | p | l | e |   | j | a | m | \0|   
	//
	// �ᱹ gets() �Լ��� scanf() �Լ��� ����������, 
	// �Է��� ���ڿ��� ������ �������� �迭�� �����Ѵ�.
	// 
	// ����, �迭�� ũ�⺸�� ū ���ڿ��� �Է��ϸ�, 
	// �迭�� �Ҵ�� �޸� ������ ��� �����ϹǷ� �����ؾ� �Ѵ�. 
	// 
	//$ �߿� 2. gets �Լ��� Enter�� ������ �Է��� ������.
	// scanf() �Լ��� ���ڿ��� �Է��� �� ���ڸ� �Է��ϱ� ���� 
	// Space Bar, Tab, Enter�� �Է��ص� ��� �Է��� ��ٸ���.   
	// 
	// �̵� Ű�� ���� ��, �ԷµǴ� ���� ����, �� ����, ���� ���ڴ� 
	// ���ڿ��� �����ϴ� �뵵�� ���� ���� �����ͷ� �Է������� �ʱ� �����̴�. 
	// 
	// �׷��� gets() �Լ��� ���ڿ��� �Ϻη� �Է��ϹǷ�, 
	// ���ڿ� �Է� ���� �ٷ� Enter�� ������ �Է��� ������. 
	// 
	// �̶� �迭�� ù ��° ��ҿ��� ���� ���� ��� �� ���ڸ� �����Ѵ�. 
	// 
	//                            ����
	//     Ű���� �Է� ----> | \n |    |    |
	//						  |
	//                        | ���� ���ڸ� �������� ���
	//                        | �� ���ڸ� ���δ�. 
	//                        |
	//             str �迭 | \0 |    |    |

	return 0;
}