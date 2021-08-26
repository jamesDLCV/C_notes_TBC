#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���� ���� ���� Random Access
// 
// ������ ������ ��ġ�� ���� �����ؼ� �����͸� �о� �� �� �ִ� 
// ������ ���� ���ٿ� ���ؼ� ���� ���ڴ�. 
//
// text.txt���� ABCDEFGHIJKLMNOPQRSTUVWXYZ �� �Էµ� �ִ�. 

/*
	ABCDEF ...
	Current position 0 and read -> A
	Cureent position 1 and read -> B
	...
*/

int main() {
	int ch;
	long cur;

	FILE* fp = fopen("test.txt", "r");

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	/* SEEK_SET */
	printf("\n*** SEEK_SET ***\n");

	fseek(fp, 2L, SEEK_SET);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* SEEK_CUR */
	printf("\n*** SEEK_CUR ***\n");

	fseek(fp, -2L, SEEK_CUR);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* SEEK_END */
	printf("\n*** SEEK_END ***\n");

	fseek(fp, 0L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -1L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -2L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* fsetpos(), fgetpos() */
	printf("\n*** fsetpos() ***\n");

	fpos_t pt;
	pt = 10;
	fsetpos(fp, &pt);		// returns 0 ok
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	printf("\n*** fsetpos() ***\n");

	fgetpos(fp, &pt);		// returns 0 ok
	printf("%lld\n", pt);	//NOTE: not meant to be read directly

	return 0;
}

// test.txt���� A���� Z������ �빮�ڷ� �Էµ� �ִ�. <= text.txt ������ ����� �д�.
// ó���� �� test.txt ������ ����, 
// 0��° ��ġ�� �ְ�, �� ���ڸ� ������ 1byte ������ �̵��Ѵ�. 
// <= ������ �������κ��� 1byte��ŭ ������ �ְ� �ȴ�. 
// 
// ������ �������κ��� 2byte��ŭ ������ �ִٸ� ����ΰ�?
// AB����C, <= �����̴�. ���⿡�� �� ���ڸ� �д´ٸ�, C�� �а�, 
// C�� �о��� ������ �� ĭ �̵��Ѵ�. 
// <= �� ������ �˸� �� �ڵ带 ������ �� �ִ�. 
// 
// FILE* fp = fopen("test.txt", "r"); <= ������ ����
// cur = ftell(fp);
//	ftell()�̶�� �Լ��� ȣ���ϸ�, ������ ��ġ�� �˷� �ش�. 
//  ���� ��𿡼� ���� �غ� �� �ִ��� �˷� �ش�. 
//  ���� ��Ű�� ftell() = 0 �̷��� 0�� ��µȴ�. 
//  <= ���������κ��� 0byte��ŭ ������ �ִ�. �� �������� �ִٶ�� �ǹ̰� �ȴ�. 
// 
// �״���,
// fseek(fp, 2L, SEEK_SET); 
//  fseek() �Լ��� ����ϸ�, �̵��� �� �� �ִ�. 
//  SEEK_SET flag�� �� ��° �μ��� �ְ�, ���� ������ fp�� ù ��° �μ��� �ְ�, 
//  �� ���� �μ��� long�� �ְ� �ִµ� bytes�̴�. 
//  <= ������(SEEK_SET)���κ��� 2bytes ������ ������ �̵��Ѵ�. 2bytes(?)
//     �׸��� ���� �غ� �Ѵٴ� �ǹ��̴�. 
// 
// �׸���, ������?
// cur = ftell(fp);
// printf("ftell() = %ld\n", cur);
//  ���) ftell() = 2  <= 2�� ����Ѵ�. 
//
// ch = fgetc(fp);				<= �о� ���δ�. 
// printf("%d %c\n", ch, ch);   
//		<= c�� ����ϰ�, 
//      <= �о��� ������ �� byte�� �� �̵��ؼ� 
//         ���������κ��� 3bytes ������ ������ ���� �غ� �Ѵ�.
// 
// cur = ftell(fp);					<= �׸��� �ٽ� �� �� �о� ���̰�
// printf("ftell() = %ld\n", cur);  <= ����� �ϸ�, 3�� ���´�. 
//		<= �� ���� �����鼭 �� byte �� �̵��� �� ���̴�.  
// 
// fseek(fp, -2L, SEEK_CUR);		<= SEEK_CUR�� ������, 
//                                     ���� ��ġ���� -2L ���ڸ�ŭ �̵��Ѵ�. 
//									   3���� -2��ŭ �Ųٷ� ����.  
// cur = ftell(fp);                 <= �о� ���̸�, 
// printf("ftell() = %ld\n", cur);  <= 1�� ��µȴ�. 
// 
// ch = fgetc(fp);                  <= 1���� �ٽ� �о� ���̸�,  
// printf("%d %c\n", ch, ch);       <= B�� ���´�.
// 
// SEEK_END�� �ִ�. 
// 
// fseek(fp, 0L, SEEK_END);			<= ���������� ã�´�. 
//                                  <= ������ �̵��� �� �� 0��ŭ �̵��� �ϰ�,
// ch = fgetc(fp);                  <= �о� ���̸�, 
// printf("%d %c\n", ch, ch);       <= -1�� ��µȴ�. EOF�� ���´�. 
// 
// fseek(fp, -1L, SEEK_END);		<= EOF���� -1��ŭ �̵��ϰ�,
// ch = fgetc(fp);					<= �о� ���̸�, 
// printf("%d %c\n", ch, ch);       <= 90 Z�� ��µȴ�. 
//
// fseek(fp, -2L, SEEK_END);        <= EOF���� -2��ŭ �̵��ϰ�,
// ch = fgetc(fp);				    <= �о� ���̸�,
// printf("%d %c\n", ch, ch);		<= 89 Y�� ��µȴ�. 
//
// ��������� �� ��° �μ��� long�� ��µ�, 
// ������ ���ϰ� Ŭ ��쿡�� long ��ſ� fpos_t Ÿ���� ����� �� �ִ�. 
// 
// fpos_t pt;		<= visual studio������ fpos_t�� Ÿ���� long long���� �� ����.
// pt = 10;
//  ����� ���� �Ͱ� ���� �ٸ���. 
// fsetpos(fp, &pt);		// returns 0 ok
//  <= fseek()�� ����ϳ� �����͸� �־� �ְ� �ִ�.  
// 
// ch = fgetc(fp);            <= �о� ���̰� 
// printf("%d %c\n", ch, ch); <= K�� ���, ��ġ�� 10
// 
// fgetpos(fp, &pt);		// returns 0 ok
//                            <= ���� ��ġ�� ����. 
//                            <= �� 10���� K�� �о����Ƿ� �� ĭ �� �� 11�� �ȴ�. 
//  <= ftell()�� ����ϳ� �� ��° �μ��� �����͸� �־� �ְ� �ִ�. 
// printf("%lld\n", pt);	//NOTE: not meant to be read directly
//                            <= 11�� ���
//  <= fpos_t�� lld�� �ް� ������, fpos_t�� ���� ���� �����ڴ� �������� �ʴ´�.
//     �ǵ����̶�� �Ѵ�. ���� ū ����, ���ڵ��� ������ ���� �����Ƿ�,
//     format specifier�� ������ ���� �ʾҴٰ� �Ѵ�. 
//     ���⿡���� ����� ���� �ֱ� ���� lld�� �ϰ� ������ ����� �ߴ�. 
// 
// �������� ���̳ʸ� ���Ͽ��� random access�� ��� �ϴ��� ���ڴ�. 