#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//$ ���ڿ��� ���̴� strcat(), strncat() �Լ�
// 
// strcpy() �Լ��� �ʱ�ȭ�� ���ڿ��� ����� ���ο� ���ڿ��� �ٲ� �� ����Ѵ�. 
// �ݸ鿡 �迭�� �ִ� ���ڿ� �ڿ� �̾� ���� ����, 
// strcat() �Ǵ� strncat() �Լ��� ����Ѵ�. 
// 
// ������ ���ϱ� ������ ���� �����̴�. 
// 
// strcat() �Լ��� ���ڿ��� �̾� ���̸�, 
// strncat() �Լ��� ������ ������ ������ŭ ���δ�. 

int main() {

	// ���ڵ� 12-10. strcat(), strncat() �Լ��� ����� ���ڿ� ���̱�
	char str[80] = "straw";			// ���ڿ� �ʱ�ȭ

	strcat(str, "berry");			// str �迭�� ���ڿ� ���̱�
	printf("%s\n", str);			// strawberry

	strncat(str, "piece", 3);		// str �迭�� 3���� ���� ���̱�
	printf("%s\n", str);			// strawberrypie

	return 0;
}

// strcat(str, "berry");�� str �迭�� �ִ� ���ڿ� �ڿ�, 
// �� ��° �μ��� �־����� ���ڿ��� �̾� ���δ�. 
// 
// ���� ����� ���� �ٿ� ���� �迭���� �� ������ ��ġ�� ã��, 
// �� ��ġ���� �ٿ� ���� ���ڿ��� �����Ѵ�. 
// 
// �ٿ� �ֱⰡ ���� �Ŀ��� �� ���ڸ� �����Ͽ� �������Ѵ�. 
//
//$ strcat() �Լ� ��� �� ���� ����
// 
// ���� 1. strcat() �Լ��� �޸𸮸� ħ���� �� �ִ�. 
//        strcat() �Լ��� ���ڿ��� �����̴� ���̹Ƿ�, 
//        �ٿ� �ֱⰡ �Ǵ� �迭�� ũ�Ⱑ ����� Ŀ�� �Ѵ�.  
// 
//        strcat() �Լ��� �ٿ� ���� ������ �ּҸ� ������Ű�Ƿ�, ������ ������ ���
//        �Ҵ����� ���� �ٸ� �޸� ������ ħ���� �� �ִ�. 
// 
//	      �� ������ �������� �� �߰����� ���ϰ�, 
//        ���α׷��� �ϼ��� �� ������ �� �߻��ϹǷ� �����ؾ� �Ѵ�.
// 
// ���� 2. strcat() �Լ��� ����� ���� �迭�� �ʱ�ȭ�ؾ� �Ѵ�. 
//        strcat() �Լ��� �ٿ� �ֱ� ���� ���� �� ������ ��ġ�� ã���Ƿ�, 
//        �ݵ�� �ʱ�ȭ�� �ؾ� �Ѵ�. 
// 
//        �迭�� �ʱ�ȭ���� ������, ������ ���� �߰����� �ٿ� ���� ���ɼ��� ũ��. 
// 
//        char str[80] = "straw";ó�� Ư���� ���ڿ��� �ʱ�ȭ�ϰų�, 
//        �ּ��� ù ��° ���ڰ� �� ���ڰ� �ǵ��� �ʱ�ȭ�Ѵ�. 
// 
//$ ������ ���� �ʱ�ȭ�� ��� �����ϴ�. 
//     ���������� �� ���ڸ� �ʱ�ȭ           �� ������ �ƽ�Ű �ڵ� ������ �ʱ�ȭ
//       char str[80] = { '\0' };              char str[80] = { 0 };
// 
//     ū����ǥ �ȿ� �ƹ��͵� �����Ƿ�        ù ��° �迭 ��Ҹ� ������ �ʱ�ȭ
//     �� ���ڸ� �ʱ�ȭ
//       char str[80] = "";					   str[0] = '\0';
// 
// strncat(str, "piece", 3); �Լ��� �ٿ� ���� ���� ���� ������ �� �ִ�. 
// 
// strncat() �Լ��� strncpy() �Լ��� �޸� �ٿ� ���� �Ŀ���
// �� ���ڸ� �����Ͽ� ���ڿ��� �ϼ��Ѵ�. 
// 
//   | s | t | r | a | w | b | e | r | r | y | p | i | e | \0|  str �迭
//                                             |   |   |   |
//                              strncat �Լ�----------------
//                                                         �������� 
//                                                         �� ���ڸ� ����