#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 12-1. ���ڿ��� ������
// ���ڿ��� �����Ϳ� ���谡 ��� �߸� ����ϸ� ������ ã�� �����. 
// ���� ���ڿ��� �ڽ� �ְ� �ٷ����, ���ڿ��� ���� ����� ��Ȯ�� �����ؾ� �Ѵ�. 
// 
// ���ڿ��� ��ü�� ������ ����, �����ͷ� ���ڿ��� �ٷ�� ����� ���� ����.

int main() {

	// printf("%s", "apple");�� apple�� ��µȴ�.
	// 
	// "apple"�� �� ���� 'a', 'p' ���� ���� �迭�̶�� ������ ����. 
	// �̰��� �迭�̶�� �翬�� �迭���� ����� ���̰�, 
	// �����δ� �迭�� ���� ��ġ�� ������ ����ϰ� �� ���̴�. 
	// 
	// �迭�� �ƴ� ���ڿ��� ���� ����ϴ� ��쵵 ���������̴�. 
	// ������ �������� ���ڿ��� ù ��° ������ �ּҷ� �а��ϰ�,
	// �� ���Ĵ� �迭�� ����ϴ� �Ͱ� ���� ������ ��ģ��.
	// 
	// <= ���ڿ��� �迭�� ������ ������, ù ��° ������ �ּҷ� ���δ�.

	printf("%s,\t%p\n", "apple", "apple");	// apple,  00007FF718E19C24

	//              "apple"�� 'a'�� ����� �ּڰ� 
	//                         |
	// "apple"�� �迭�̶�� ---> | a | p | p | l | e | \0 |
	//                         �迭�� �ּ�����, 
	//                         ù ��° ������ �ּ�

	printf("\t%p %p\n", "apple", &"apple");	// 00007FF718E19C24 00007FF718E19C24
	puts("");

	//$ ���ڿ� ��� ���� ���
	// ���ڿ��� ũ��� �������� �ʴ�. 
	// ����, �����Ϸ��� ���ڿ� ����� ��Ư�� ������� ó���Ѵ�. 
	// ������ �������� ���ڿ��� char �迭 ���·� ���� �����ϰ�, 
	// ���ڿ� ����� �ִ� ������ �迭�� ��ġ ���� ����Ѵ�. 
	// 
	// ���� ��� ���ڿ� "apple"�� ���� 'a'�� ����� �޸��� �ּڰ����� �ٲ��. 
	{
		// ���ڵ� 12-1. ���ڿ� ����� �ּҶ� ����
		printf("apple�� ����� ���� �ּڰ�: %p\n", "apple");	  // 00007FF718E19C24
		printf("     �� ��° ������ �ּڰ�: %p\n", "apple" + 1); // 00007FF718E19C25
		printf("             ù ��° ����: %c\n", *"apple");    // a, ���� ���� ����
		printf("             �� ��° ����: %c\n", *("apple" + 1));// p, ������ �����
		printf("�迭�� ǥ���� �� ��° ����: %c\n", "apple"[2]);   // p, �迭 ǥ���� 
	}


	return 0;
}

// printf("%p\n", "apple"); �� ���ڿ��� ����� ���� ��ġ ���� ����Ѵ�. 
// ���ڿ� "apple"�� �迭 ���·� ���� ����ǰ�, printf() �Լ��� �μ��� 
// �� ù ��° ���� 'a'�� �ּҰ� ���ȴ�. 
// 
// printf() �Լ����� %p�� ����ϸ�, �� ���� 16������ Ȯ���� �� �ִ�. 
// p�� �ַ� �����͸� ����� ��, ����ϴ� ��ȯ �����̸�, 
// ������ ���� 16���� �빮�ڷ� ����Ѵ�. 
// 
// printf("�ּڰ�: %p\n", "apple");
//                        ------
//                  ���ڿ��� ���� �迭�� ����
//                                       
//         ���ڿ��� ����� ���� ��ġ �� --> 24  25  26  27  28  29
//                                      | a | p | p | l | e | \0 |   
//  ù ��° ������ �ּ� ����  _____________
//                        |
// printf("�ּڰ�: %p\n", 24);
// 
// �ᱹ ���ڿ��� ������ �������� char ������ �ּҷ� �ٲ�Ƿ�, 
// ���� ������ ������ ������ �� �ִ�.
// 
// printf("%p\n", "apple" + 1);
// �̷��� ������ ���ϸ�, ���� ������ �ּҸ� ���� �� �ְ�, 
// 
// printf("%c\n", *"apple");
// �̷��� ���� ���� ������ �����ϸ�, ù ��° ���ڰ� �ȴ�. 
// 
// printf("%c\n", "apple"[2]); 
// �̷��� �迭��ó�� ����ϴ� �͵� �����ϴ�. 
// 
// ��, �����ؾ� �� ���� �ִ�. 
//$ ����!
// �ּҷ� �����ؼ� ���ڿ��� �ٲ㼭�� �� �ȴ�. 
// *"apple' = 't'; �� ���� ù ��° ���ڰ� ����� ������ 
// �ٸ� ���ڸ� �����Ͽ� �� ���� �ٲٷ��� �õ��� �����ϴ�. 
// 
// ���� ��ü�� ������ �����Ƿ� ���������� �����ϵ�����, 
// ������ ��, �ü���� ���ؼ� ���� ����� ���ɼ��� �ִ�. 
// 
// �ü���� ���ڿ� ����� �б� ���� �޸� ������ �����Ѵ�. 
// ���� �� ���� �ٲٴ� ������ ������ �����Ѵ�. 
// <= �ü���� ���� �ٸ� �� ������, ȣȯ���� �����Ѵٸ� �õ����� ����.
// 
// ���ڿ��� �ּҷ� �ٲٸ�, ������ ������ ���ؼ� 
// ���ڿ��� ���� ��ġ���� ���� ���� ���� ����� �� �ִ�. 
// 
// �� ��� ���ڿ��� ���� �˾ƾ� �ϹǷ�, ���ڿ��� ���� ǥ���ϱ� ���ؼ� 
// �� ���� null character�� ����Ѵ�. 
// <= �����Ϸ��� ���ڿ� ����� ������ ��, �������� �׻� �� ���ڸ� �ٿ� �ش�.