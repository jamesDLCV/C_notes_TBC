#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

// �ؽ�Ʈ ���� ��� ��Ʈ���� �پ��� ����� �Լ���
// fprintf(), fscanf(), fgets(), fputs()
// 
// �ܼ� ����¿� ����ߴ� �Լ��� ������ �Լ��� ���� ����¿����� ����ϴµ�,
// �̵� �Լ��� ���ؼ� ���� ����. 

#define MAX 31

int main() {
	FILE* fp;
	char words[MAX] = { '\0', };

	const char* filename = "record";	// "record.txt"�� �ϸ� �� ���ϴ�. 

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

	while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
	{
		fprintf(fp, "%s\n", words);
	}
		
	//while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
	//	fputs(words, fp);
	
	rewind(fp);	/* go back to beginning of file */

	while (fscanf(fp, "%s", words) == 1)
		fprintf(stdout, "%s\n", words);

	//while (fgets(words, MAX, fp) != NULL)	// EOF check
	//	fputs(words, stdout);

	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	return 0;
}

// FILE* fp; <= FILE ������
// 
// char words[MAX] = { '\0', }; ������ �迭�� �Է� �޴´�. 
// ������ �Է��� �޴� ���� ������ �Ѵ�. 
//
// const char* filename = "record.txt"; ���� �̸��� �̷��� �ߴ�. 
// const char* filename = "record";     <= �̷��� Ȯ���� .txt�� ���� �ȴ�. 
// 
// Ȯ���ڰ� txt�� �ƴϴ��� ���� ���Ϸ� ������ �ϸ�, ���� ����ó�� ���� �� �ִ�. 
// 
// ������ ���� �κ��� ���� �� ������ �����Ѵ�. if ((~) == NULL)
// fprintf(stderr, ~ ) <= fprintf() �Լ��� ����ߴµ�, stderr���ٰ� ����ϰ� �ִ�.
// stdout�̸� �ܼ� �Է��̰�, stderr�� ����� �ص� ����� ȿ���� ����. 
// 
// c stdout�� stderr�� �����ؼ� �޾� ���� ������, 
// redirection�� �� ��, stderr�� ���� redirection�� �� �ִµ�, 
// ������ ���� �ü�� ���ǿ��� ���� �� �� ��Ȯ�� �� ����. 
// 
// fprintf()���� ���콺�� hover over�� ����, 
// int _cdecl fprintf(FILE *const _Stream, const char *const _Format, ...); 
// �̶�� ���. ������ ��ü�� underscore Stream�̴�. 
// stream�� stdout�� stderr�� �����ؼ� ����� �� �ִ� ������ ������ �ֶ�. 
// 
// while () �Լ��� �ϳ��� fprintf()�� �� �ְ�, �ϳ��� fputs()�� �� �ִ�. 
// �� �� �Լ��� ���̸� �˰� �ִٸ� �̴� ���� ���ذ� �ȴ�. 
// 
// while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.')�� ����,
// stdin���� �޾� ���̰� �ִ�. <= �׳� scanf()�� ���� �����ϰ� �۵��Ѵ�. 
// words��� �迭�� �Է� ���� ���ڸ� �޾� ���δ�. 
// '== 1'�� �ǹ̴� �Է� ���� ���� '�ϳ��̸�'�̶�� �ǹ��̴�. 
// "%30s" <= string �ϳ��� �Է� �޵��� �� �ִ�. 
// <== �ᱹ '�Է��� ����� ���Դٸ�'�̶�� �ǹ��̴�. 
// �Է��� ���ٸ� true�� �ƴϹǷ�, while() �� ������ ���� ���̴�. 
//  
// words[0] != '.' <= �Է� ���� strings �� ù ���ڰ� '.' ��ħǥ�̸�, �Է��� �����ڴ�.
// 
// fprintf(fp, "%s\n", words); <= ���� ������ fp���ٰ� print�� �ϰ� �ִ�. 
// ������ "%s\n" �̷��� �Ѵ�. (format specifier)
// words ���ڿ��� fp���ٰ� ����Ѵ�. 
// 
// printf(), scanf() ������ ���� ����ϴ�. 
// 
// rewind(fp);	/* go back to beginning of file */
// <= ������ ó������ ���ư���. 
//    ������ ��� ����� �ϴٰ� rewind()�� ������, �ٽ� ó������ ���ư��� ����Ѵ�.
//
// �� ���� �Ʒ� while()���� ����ȴ�. 
//  
// while (fscanf(fp, "%s", words) == 1)
//     fpinrtf(stdout, "%s\n", words);
// 
// fscanf() �Լ��� ���� ���Ϸκ��� �� �ܾ �о� �鿩�� words��� �迭�� ������ �Ѵ�. 
// fscanf() �Լ��� ��ȯ���� ���������� �Է��� �޾��� ��, 
//	("%s" <= �Է� ���� �������� �����̴�)
// �ϳ��̸� true�ϱ� 1�̴�. <= ���������� �Է��� �޾Ҵٴ� �ǹ��̴�. 
// EOF�� ������ ���� EOF�� ������ �Ѵ�. 
// ������ fscanf() == 1�� fscanf() != EOF�� �ص� ���� ����� �Ѵ�. 
// 
// fpinrtf(stdout, ~ ) <= stdout�� �� �ָ�, printf()�� ����������. 
// 
// �� ��������, ������ �ݾ� �ش�. 
// if (fclose(fp) != 0)
//     fprintf(stderr, "Error closing file\n");
// <= �� �� ������ ������ �� �� �����ϱ� ���� �޽����� ����ϰ� �Ѵ�. 
// 
// ������ ��Ű��, 
// Can't open "record" file. �̶�� ����� �ȴ�. 
// <= ������ ����ٴ� ����� �ϰ� ������. 
// 
// "r+" mode�� reading�� writing�� �� �Ǵµ�, ������ ������, ������ ���Ѵ�.
// 
// "w+" mode������ reading�� writing�� �� �Ǵµ�, ������ ������ �����, 
//		������ ������ ������ ���� ������ �ٽ� ����. 
// 
// if ((fp = fopen(filename, "r+")) == NULL)
// �� �� if���� "r+"�� "w+" mode�� �ٲ� ����. 
// 
// ������ �ϸ�, �Է� Ŀ���� �߰�, �ܼ� �Է��� �ϸ�, 
// �Է��� ������ ȭ�鿡 ����� �ǰ�, 'record'��� ���Ϸ� ������ �ȴ�. 
// ������ 'record'�� Ȯ���ڸ� ������� �ʾ����Ƿ� Ȯ���� ���� record ���Ϸ� ����ȴ�.
// record ������ �޸������ε� �� �� �ְ�, visual studio�ε� �� �� �ִ�. 
// �� record�� Ȯ���ڸ� .txt�� �� �ָ� ���� �� �� �ִ�. 
// 
// const char* filename = "record";	��
// const char* filename = "record.txt"; �� �� �ָ� Ȯ���ڰ� txt�� ����ȴ�. 
// 
// �ٽ� ������ �ϰ�, �ܼ� �Է��� �ϸ�, 
// ������ �ִ� ���뿡 over-writing�� �Ѵ�. �� ������ ������ �������. 
// 
// "w+" mode�� "a+"�� �ٲٰ� ������ �� ����. 
// �̹����� �� �� "w+" mode���� �Է��ߴ� ���뿡 ���ٿ��� ȭ�鿡 ����� �ǰ�, 
// ���Ͽ��� ������ �ȴ�. 
// 
// ���� "a+" mode�� "r+" mode�� �ٲ� ����. 
// ������ ���� ���¿��� "r+"�� �ϸ� ������ �����. 
// ������ ������ �ִ� �����̴�. 
// ������ �ϸ� ��� �Ǵ°�?
// <==== ���� ����. ���� ���µ� ��ü�� ���� ���� �� �ƴ϶�
//		 �� �κк��� ���� �� �����Ƿ�, ������ �Է��ߴ� ������ ���� �Է��� ���뺸�� 
//       ���ٸ�, �� �̹� �κ��� ������ �״�� ����� �ȴ�. 
// 
// r+, w+, a+ �� ���� ����� ���̿� ���ؼ� ���� �ô�. 