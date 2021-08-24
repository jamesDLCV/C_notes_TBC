#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

// fgets()와 fputs()에 대해서 살펴 보고,
// fscanf() vs. fgets()의 차이에 대해서 살펴 보자. 

#define MAX 31

int main() {
	FILE* fp;
	char words[MAX] = { '\0', };

	const char* filename = "record.txt";	// "record"로 할 수도 있다. 

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

// fscanf()는 입력을 'hello world hi'라고 같은 줄에 단어를 입력해도, 
// 결국은 여러 개의 단어처럼 입력을 한다. 
// hello world hi 
// bye . <= 이렇게 입력을 하면, 
// 아래와 같이 개별 단어로 출력이 된다. 
// hello
// world
// hi
// bye
// <= 줄바꿈을 하라는 마침표 '.'가 위처럼 입력돼도 끊고 새로 받기 때문에 나가 버린다.
// 
// 줄 단위로 입력을 받으려면 어떻게 할까?
// fgets()를 사용하면 된다. 
// 
// fgets()와 fputs()에서 주의할 사항 두 가지가 있다. 
// 1. fgets()와 fputs() 둘 다 stream에 대한 포인터 (FILE에 대한 포인터)가
//    뒤에 붙는다. <= (fgets(words, MAX, stdin) stdin이 뒤에 붙어 있다. 
//		cf) fscanf(stdin, "%30s", words)는 FILE에 대한 포인터가 앞에 붙어 있다.
//    fgets(words, MAX, stdin) <= 어디에 담을지를 결정하는 words는 배열의 포인터, 
//		최대 몇 개 MAX, stdin이 뒤에 놓인다.
// 
//    fputs(words, fp) <= 파일의 포인터 fp가 여기 있다. 
//		fputs()도 fputs(words, stdout);에서와 같이 stdout이 뒤에 붙는다. 
//    이렇게 순서가 다른다. 주의해야 한다. 
// 
// 2. EOF 체크를 NULL로 한다. 
//    (fgets(words, MAX, stdin) != NULL) <= 이렇게 한다. 
//		cf) (fscanf(fp, "%s", words) != EOF) <= fscanf()은 이렇게 EOF와 비교한다.
//          (fscanf(fp, "%s", words) == 1)   <= 또는 입력 받는 아이템이 하나이므로 
//											1과 비교해도 된다. 두 가지 방법이 있다.	
//    왜냐하면, fgets()는 성공적으로 입력을 받았을 때는, 
//    배열의 첫 주소, 포인터를 리턴하는 함수이기 때문에 EOF를 만나면 NULL을 린턴한다.
// 
// 실행을 한 후, 문자 입력을 하면, 라인 단위를 입력을 받고 출력을 한다. 
// 단지 hava a good day. <= 이렇게 '.'을 같은 라인에 입력하면 종료가 안 된다. 
// '.'을 라인을 달리해서 첫 번째 입력으로 넣어야 종료가 된다. 
// 
// "w+" mode로 하면 이전의 내용은 모두 지워 버리고 다시 입력한다. 
// "a+" mode로 하면 이전 내용에 추가가 된다. 
// "r+" mode는 파일이 없는 상태에서는 에러가 뜨지만, 
//      이전의 파일이 있다면 덮어 쓴다. 
//      <= 덮어 쓰는데 앞에서부터 덮어 쓴다. 
//         기존의 파일이 더 길다면 더 긴 부분에 대해서는 기존의 내용이 유지된다. 
// 
// 세 가지 모두 차이에 대해서 잘 정리해 둬라. 
// 
// "a+" mode로 했을 때 설명하기 편하므로, "a+"로 한다. 
// 
// fscanf() vs. fgets()의 차이에 대해서 살펴 보자. 
//
// fscanf()와 fprintf()를 사용했으나, fscanf()와 fputs()를 사용해도 된다. 
// 또 fgets()와 fprintf()를 사용해도 된다. <= 섞어서 써도 된다. 
// 
// fscanf()는 입력을 'hello world hi'라고 같은 줄에 단어를 입력해도, 
// 결국은 여러 개의 단어처럼 입력을 한다. 
// 종료를 의미하는 '.'의 입력도 새로운 라인에서 하지 않아도 된다. 
// 공백 후에 '.'를 넣으면 종료가 된다. 
// 
// fscanf()와 fgets()가 문법적으로 어떤 차이가 있는지 살펴 보자. 
// 종료 조건의 차이는 앞에서 설명했다. 
// 
// fgets()의 입력에서는, 
// abcd efgh 4567 . <= 이렇게 입력을 하면 종료가 도지 않는다. 
// 종료는 라인을 바꿔서 첫 글자로 '.' 마침표를 입력해야 된다. 
// <= fscaf()은 같은 라인에서도 공백 입력 후 '.'를 입력하면 종료가 됐다. 
// 
// r+, w+, a+ 세 가지 mode string이 어떻게 서로 다른지 살펴 봤고, 
// 여러 가지 텍스트 파일 입출력에 대해서 살펴 봤다. 