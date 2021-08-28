#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ��Ÿ ����� �Լ���
// ungetc(), setvbuf(), fflush()

int main() {

	FILE* fp;
	int ch;

	/* ungetc() */
	fp = fopen("input.txt", "r");

	ch = fgetc(fp);
	fputc(ch, stdout);

	printf("\n");

	ungetc(ch, fp);		// try another characters

	ch = fgetc(fp);
	fputc(ch, stdout);  // <= "

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= I

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= ����

	ch = fgetc(fp);
	fputc(ch, stdout);	// <= c

	fclose(fp);

	/* setvbuf() */

	return 0;
}

// ungetc()
//	�� ���ڸ� ���� �� ���ۿ��ٰ� �� �Լ��� �ٽ� ���� �־� ������. 
//  ���� �Ųٷ� �ϴ� �Լ��̴�. 
// 
// input.txt ������ ����� ������ �Է��Ѵ�. 
/*
"I choose a lazy person to do a hard job.
Because a lazy person will find an easy way to do it."

Bill Gates
*/
// ù ���ڸ� ������ "�� ���� ���̴�. 
// 
// ch = fgetc(fp);      <= �� ���ڸ� �о� �´�. 
// fputc(ch, stdout);   <= ����Ѵ�. �Ǿ��� ������ "�� ��µȴ�. 

// ungetc(ch, fp);		// try another characters
//						<= �о� ���� ���ڸ� �ٽ� ���ۿ� �ִ´�. 
// ch = fgetc(fp);      <= �ٽ� ���ڸ� �о� ���̸�,
// fputc(ch, stdout);	<= �ٽ� �Ǿ��� ������ "�� ��µȴ�. 
// 
// ch = fgetc(fp);      <= ���ڸ� �о� ���̸�,
// fputc(ch, stdout);   <= ������ " ������ ���� I�� ��µȴ�. 
// 
// fclose(fp);
//
// ungetc() �Լ��� �ǹ����� �ʿ��� ���� �ִ�. 