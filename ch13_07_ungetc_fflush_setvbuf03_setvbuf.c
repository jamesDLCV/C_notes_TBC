#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ��Ÿ ����� �Լ���
// ungetc(), setvbuf(), fflush()
// 
// setvbuf()

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
	printf("\n");

	fclose(fp);

	/* fflush() */

	return 0;
}

//  input.txt ���Ͽ��� ������ ������ ��� �ִ�. 
/*
"I choose a lazy person to do a hard job.
Because a lazy person will find an easy way to do it."

Bill Gates
*/
// 
// setvbuf() �Լ��� ���� ����.
//	������ ������ �ٲ� �� �� �ִ�. �پ��� ����� �ִ�. ���⼭�� �⺻���� �͸� �Ұ��Ѵ�.
//
// char buffer[32] = { '\0', }; <= �迭�� �ϳ� �������.
//                                 �̰��� ���۷� ����϶�� �� �� �ִ�. 
// setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); 
//	<= ������ ���� �迭�� ���۷� ����϶�. 
// 
// ���ڸ� �о� ���̱� ���� ���ۿ� �ִ� ������ dump�� ����, 
// <= 00000000000000000000000000000000
//	  0���� �ʱ�ȭ�� 32���� �迭�� ��µȴ�. ���۰� ��� �ִ�. 
// 
// ch = fgetc(fp);	<= �� ���ڸ� �о���. 
// 
// �״���, ���ۿ� �ִ� ������ dump�� �� ����. 
// for (int i = 0; i < sizeof(buffer); ++i)
//  	printf("%c", buffer[i]);
// <= ���ۿ� �ִ� ������ �� ����� �� ����, 
//    �� ���ڸ� �о� �������� �ұ��ϰ� ���۴� �� á��. 
// ���) "I choose a lazy person to do a
//      <= �Ǹ������� ����
//    ���� ���� 32 �����̴�. 
// 
// ���۴� �� ���α׷��� �� ������ ������ ��� ���� ���̶�� ������ �Ǹ�, 
// �̸� ���ۿ� �� ������ �־� ����, ���ۿ��� ������ �´�. 
// ������ ���ۿ��� ������ ���� �ξ� ������. 
//
// ���Ͽ��� ���۷� �ű�� ���� �ð��� �ɸ��ϱ� 
// �� ���� ���� ���ھ� ���۷� �о� ���̷��� �ϴ� ���̴�. 
// �ϴ� ���ۿ� �ö�� �������� fgetc()�� �̿��ؼ� ���۷κ��� �� ���ڸ� ������ ���ų�,
// ���� ���ڸ� ������ ���� ���� ���� ������ ������, 
// ���۸� �̸� ä�� ������ �ִ� ���̴�. 
// 
// ���۰� ��� �ִٰ�, �� ���ڸ� ������, ���۸� ���� ä��� (ä�� �� �ִ� ��ŭ ä���),
// ch = fgetc(fp);�� �ű⿡�� �� ���ڸ� ������ �� ���̴�. 
// �׷��� ���۰� �ڽ��� ä�� �� �ִ� ��ŭ �� ä��� �ִ� ���̴�. 
// 
// ������ �ִ� ����, 
// ���� ��û���� ���� �����͸� ���Ϸ� �����ϴ� ���� ���̴�.  
// �о� ���̴� �͵� �߿��ϰ� �����ϴ� �͵� �߿��ϴ�.
// �׷� ��, 
// setvbuf(fp, buffer, _IOFBF, sizeof(buffer));	// _IOLBF, _IOFBF, _IONBF 
//  <= _IOLBF, _IOFBF, _IONBF �̷� �ɼ��� ����� �� �ִ�. 
//     _IOLBF ������ �ϳ��� ������ ���ۿ� ����. L <= Line
//     _IOFBF ��°�� ����. F <= Full
//     _IONBF N�� No�̴�. 
//  �̰��� ������ ���� �ַ��� ��û���� ū �����͸� ����ؼ� ���� �����ϴ� ������
// ���� ��� �ϴµ� �װ��� ������ �ʴ�. ���ʿ����� �׸� �߿����� �ʾƼ� �����Ѵ�.
// 
// ���۸� ������� �ʴ� ��� _IONBF�� ���� ����. 
// �� setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); ���� 
// _IOFBF�� _IONBF���� �ٲٸ�, 
// ���۸� �о� ������ �ʴ´�. <= ���۸� dump�� ���� �ƹ� �͵� ����� ���� �ʴ´�.
// 
// �������� reading�� ���� �ô�. ���߿� �ǹ����� writing�� �� ���� �ٶ���. 
// 
// fflush()�� ���� ����.