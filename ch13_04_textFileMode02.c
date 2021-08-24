#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

// fgets()�� fputs()�� ���ؼ� ���� ����,
// fscanf() vs. fgets()�� ���̿� ���ؼ� ���� ����. 

#define MAX 31

int main() {
	FILE* fp;
	char words[MAX] = { '\0', };

	const char* filename = "record.txt";	// "record"�� �� ���� �ִ�. 

	/*
		fopen() mode strings for text files
		- r: reading
		- w: creating-and-writing or over-writing
		- a: appending or creating-and-writing
		- r+: both reading and wrting
		- w+: reading and writing, over-writing or creating
		- a+: reading and writing, appending or creating
	*/

	if ((fp = fopen(filename, "a+")) == NULL)	// Try r+, w+, a+
	{
		fprintf(stderr, "Can't open \"%s\" file.\n", filename);
		exit(EXIT_FAILURE);
	}

	/*while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
	{
		fprintf(fp, "%s\n", words);
	}*/

	while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
		fputs(words, fp);

	rewind(fp);	/* go back to beginning of file */

	/*while (fscanf(fp, "%s", words) != EOF)
		fprintf(stdout, "%s\n", words);*/

	while (fgets(words, MAX, fp) != NULL)	// EOF check
		fputs(words, stdout);

	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	return 0;
}

// fscanf()�� �Է��� 'hello world hi'��� ���� �ٿ� �ܾ �Է��ص�, 
// �ᱹ�� ���� ���� �ܾ�ó�� �Է��� �Ѵ�. 
// hello world hi 
// bye . <= �̷��� �Է��� �ϸ�, 
// �Ʒ��� ���� ���� �ܾ�� ����� �ȴ�. 
// hello
// world
// hi
// bye
// <= �ٹٲ��� �϶�� ��ħǥ '.'�� ��ó�� �Էµŵ� ���� ���� �ޱ� ������ ���� ������.
// 
// �� ������ �Է��� �������� ��� �ұ�?
// fgets()�� ����ϸ� �ȴ�. 
// 
// fgets()�� fputs()���� ������ ���� �� ������ �ִ�. 
// 1. fgets()�� fputs() �� �� stream�� ���� ������ (FILE�� ���� ������)��
//    �ڿ� �ٴ´�. <= (fgets(words, MAX, stdin) stdin�� �ڿ� �پ� �ִ�. 
//		cf) fscanf(stdin, "%30s", words)�� FILE�� ���� �����Ͱ� �տ� �پ� �ִ�.
//    fgets(words, MAX, stdin) <= ��� �������� �����ϴ� words�� �迭�� ������, 
//		�ִ� �� �� MAX, stdin�� �ڿ� ���δ�.
// 
//    fputs(words, fp) <= ������ ������ fp�� ���� �ִ�. 
//		fputs()�� fputs(words, stdout);������ ���� stdout�� �ڿ� �ٴ´�. 
//    �̷��� ������ �ٸ���. �����ؾ� �Ѵ�. 
// 
// 2. EOF üũ�� NULL�� �Ѵ�. 
//    (fgets(words, MAX, stdin) != NULL) <= �̷��� �Ѵ�. 
//		cf) (fscanf(fp, "%s", words) != EOF) <= fscanf()�� �̷��� EOF�� ���Ѵ�.
//          (fscanf(fp, "%s", words) == 1)   <= �Ǵ� �Է� �޴� �������� �ϳ��̹Ƿ� 
//											1�� ���ص� �ȴ�. �� ���� ����� �ִ�.	
//    �ֳ��ϸ�, fgets()�� ���������� �Է��� �޾��� ����, 
//    �迭�� ù �ּ�, �����͸� �����ϴ� �Լ��̱� ������ EOF�� ������ NULL�� �����Ѵ�.
// 
// ������ �� ��, ���� �Է��� �ϸ�, ���� ������ �Է��� �ް� ����� �Ѵ�. 
// ���� hava a good day. <= �̷��� '.'�� ���� ���ο� �Է��ϸ� ���ᰡ �� �ȴ�. 
// '.'�� ������ �޸��ؼ� ù ��° �Է����� �־�� ���ᰡ �ȴ�. 
// 
// "w+" mode�� �ϸ� ������ ������ ��� ���� ������ �ٽ� �Է��Ѵ�. 
// "a+" mode�� �ϸ� ���� ���뿡 �߰��� �ȴ�. 
// "r+" mode�� ������ ���� ���¿����� ������ ������, 
//      ������ ������ �ִٸ� ���� ����. 
//      <= ���� ���µ� �տ������� ���� ����. 
//         ������ ������ �� ��ٸ� �� �� �κп� ���ؼ��� ������ ������ �����ȴ�. 
// 
// �� ���� ��� ���̿� ���ؼ� �� ������ �ֶ�. 
// 
// "a+" mode�� ���� �� �����ϱ� ���ϹǷ�, "a+"�� �Ѵ�. 
// 
// fscanf() vs. fgets()�� ���̿� ���ؼ� ���� ����. 
//
// fscanf()�� fprintf()�� ���������, fscanf()�� fputs()�� ����ص� �ȴ�. 
// �� fgets()�� fprintf()�� ����ص� �ȴ�. <= ��� �ᵵ �ȴ�. 
// 
// fscanf()�� �Է��� 'hello world hi'��� ���� �ٿ� �ܾ �Է��ص�, 
// �ᱹ�� ���� ���� �ܾ�ó�� �Է��� �Ѵ�. 
// ���Ḧ �ǹ��ϴ� '.'�� �Էµ� ���ο� ���ο��� ���� �ʾƵ� �ȴ�. 
// ���� �Ŀ� '.'�� ������ ���ᰡ �ȴ�. 
// 
// fscanf()�� fgets()�� ���������� � ���̰� �ִ��� ���� ����. 
// ���� ������ ���̴� �տ��� �����ߴ�. 
// 
// fgets()�� �Է¿�����, 
// abcd efgh 4567 . <= �̷��� �Է��� �ϸ� ���ᰡ ���� �ʴ´�. 
// ����� ������ �ٲ㼭 ù ���ڷ� '.' ��ħǥ�� �Է��ؾ� �ȴ�. 
// <= fscaf()�� ���� ���ο����� ���� �Է� �� '.'�� �Է��ϸ� ���ᰡ �ƴ�. 
// 
// r+, w+, a+ �� ���� mode string�� ��� ���� �ٸ��� ���� �ð�, 
// ���� ���� �ؽ�Ʈ ���� ����¿� ���ؼ� ���� �ô�. 