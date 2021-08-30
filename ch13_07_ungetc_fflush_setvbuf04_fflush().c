#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ��Ÿ ����� �Լ���
// ungetc(), fflush(), setvbuf()
// 
// fflush()

int main() {

	FILE* fp;
	int ch;

	/* setvbuf() */
	fp = fopen("input.txt", "r");

	char buffer[32] = { '\0', };

	setvbuf(fp, buffer, _IOFBF, sizeof(buffer));	// _IOLBF, _IOFBF, _IONBF 

	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%hhd", buffer[i]);
	printf("\n");

	ch = fgetc(fp);		// Read just only a single character!

	// dump buffer
	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%c", buffer[i]);
	printf("\n\n\n");

	/* fflush() */

	// Writing a large amount of data

	fflush(fp);

	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%c", buffer[i]);
	printf("\n");

	fclose(fp);

	return 0;
}

// flush ȭ��ǿ��� ������ ���� ������. 
// ���ۿ� �׿� �ִ� �����͸� �� ���� ������. 
// 
// fflush(fp); �̷� ������ ����Ѵ�. 
// ��뷮�� �����Ͱ� �ʿ��ѵ� �������� �����ϱⰡ ����ؼ� ����� ���� ���Ҵ�.
// 
// OS�� C�� ��뷮 �����͸� ó���ϴ� �������� ���ۿ� �ִ� �����͸�
// �����̳� ���÷��̳� ��Ʈ������ �Ϻ��ϰ� ����� �� �� ��찡 �߻��� �� �ִ�. 
// �׷� �� �ݵ�� ���ۿ� �ִ� �����͸� �� ����ض�, �� ��������� �ǹ��̴�.  
// 
// ��� ����� ���ȴµ� �� ����� �� �ɱ�?
// ���ۿ� ��ó ������� ���� �����Ͱ� ���� �ִµ�, ������ ���α׷��� ������� ��. 
// �̷� �� fflush()�� ����ϸ� ������ �� �� �ִ�. 
// 
// �츮�� ���� ��� ������ fflush()�� �ذ�� �Ŷ��� �� �ϰ�����, 
// �õ��� �� ���� �ɼ� �� �ϳ��̴�. 
// 
// ungetc(), fflush(), setvbuf() �� �Լ��� ���ؼ� ���� �ô�. 