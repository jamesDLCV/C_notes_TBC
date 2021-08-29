#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ��Ÿ ����� �Լ���
// ungetc(), setvbuf(), fflush()
// 
// ungetc()

int main() {

	FILE* fp;
	int ch;

	/* ungetc() */
	fp = fopen("input.txt", "r");

	ch = fgetc(fp);
	fputc(ch, stdout);

	printf("\n");

	ungetc((int)'A', fp);		// try another characters

	ch = fgetc(fp);
	fputc(ch, stdout);  // <= "�� A�� ��ü��. A ���

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= I
		
	ch = fgetc(fp);
	fputc(ch, stdout);	// <= ����

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= c

	printf("\n");

	ungetc((int)'B', fp);	// �� �ٿ��� �о� ���� c���ٰ� B�� �ִ´�.

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= B

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= h

	fclose(fp);

	/* setvbuf() */

	return 0;
}

// ungetc() �Լ��� �ǹ����� �ʿ��� ���� �ִ�. 
// 
//  input.txt ���Ͽ��� ������ ������ ��� �ִ�. 
/*
"I choose a lazy person to do a hard job.
Because a lazy person will find an easy way to do it."

Bill Gates
*/
// 
// ungetc((int)'A', fp);
//  �� ���ο��� ch = fgetc(fp);���� " �� ���ڸ� �о���. 
//  "�� �� ���ۿ��� ������. �� �ڸ����ٰ� A�� �ִ´�. 
// 
// ungetc()
//  un�� ������ �ݴ��� ����� �� �ִ� ���̴�. 
// 
// setvbuf() �Լ��� ���� ����.