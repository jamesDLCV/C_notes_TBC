#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���ݱ��� ���ڿ��� ���� ����� ����� �Լ��� ���� �����ߴ�. 
// ���ڿ��� ���ڵ��� �޸𸮿� �������� �����ϰ�, 
// ù ��° ������ �ּҷ� ó���Ѵ�. 
// ����, ���ڿ� ����� �Լ��� ����� ��Ȯ�� ������ ������ ������ ���� �ʴ´�.
// 
// ������ Ǯ�鼭 ����� �Լ��� ����� ������ �������� ���� ����.

int main() {

	// 1. p335
	{
		char* ptr_s = "applepie";
		ptr_s += 5;
		printf("%s", ptr_s);		// pie
	}
	puts("\n");

	// 2.
	{
		char str[20] = "apple";
		char* ptr_a = str;
		char* ptr_b = "pineapple";

		printf("%s\n", "apple");		// apple
		printf("%c\n", str[0]);			// a. printf("%s\n", str[0]);�� �� ��.
		printf("%s\n", ptr_a);			// apple
		printf("%s\n", ptr_b + 4);		// apple
	}
	puts("\n");

	// 3.
	{
		char ani[20];
		char why[80];

		printf("�����ϴ� ����: ");
		scanf("%s", ani);
				
		scanf("%*c");			// getchar();

		printf("�����ϴ� ����: ");
		fgets(why, sizeof(why), stdin);

		printf("%s is %s", ani, why);
	}

	return 0;
}

// printf("%s\n", str[0]);�� �ƹ��͵� ����� �� �ȴ�. 
// printf("%c\n", str[0]);�� �ؾ� ����� �ȴ�. �� ���� ���!