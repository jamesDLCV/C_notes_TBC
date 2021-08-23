#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

// 텍스트 파일 모드 스트링과 다양한 입출력 함수들
// fprintf(), fscanf(), fgets(), fputs()
// 
// 콘솔 입출력에 사용했던 함수와 유사한 함수를 파일 입출력에서도 사용하는데,
// 이들 함수에 대해서 살펴 보자. 

#define MAX 31

int main() {
	FILE* fp;
	char words[MAX] = { '\0', };

	const char* filename = "record";	// "record.txt"로 하면 더 편하다. 

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

// FILE* fp; <= FILE 포인터
// 
// char words[MAX] = { '\0', }; 문자의 배열을 입력 받는다. 
// 일종의 입력을 받는 버퍼 역할을 한다. 
//
// const char* filename = "record.txt"; 파일 이름은 이렇게 했다. 
// const char* filename = "record";     <= 이렇게 확장자 .txt는 빼도 된다. 
// 
// 확장자가 txt가 아니더라도 문자 파일로 저장을 하면, 문자 파일처럼 읽을 수 있다. 
// 
// 파일을 여는 부분은 이제 알 것으로 생각한다. if ((~) == NULL)
// fprintf(stderr, ~ ) <= fprintf() 함수를 사용했는데, stderr에다가 출력하고 있다.
// stdout이면 콘솔 입력이고, stderr에 출력을 해도 비슷한 효과가 난다. 
// 
// c stdout과 stderr을 구분해서 받아 보고 싶으면, 
// redirection을 할 때, stderr을 따로 redirection할 수 있는데, 
// 리눅스 같은 운영체제 강의에서 배우는 게 더 정확할 것 같다. 
// 
// fprintf()위에 마우스를 hover over해 보면, 
// int _cdecl fprintf(FILE *const _Stream, const char *const _Format, ...); 
// 이라고 뜬다. 변수명 자체는 underscore Stream이다. 
// stream을 stdout과 stderr로 구분해서 사용할 수 있다 정도로 정리해 둬라. 
// 
// while () 함수가 하나는 fprintf()로 돼 있고, 하나는 fputs()로 돼 있다. 
// 이 두 함수의 차이를 알고 있다면 이는 쉽게 이해가 된다. 
// 
// while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.')을 보면,
// stdin으로 받아 들이고 있다. <= 그냥 scanf()와 거의 동일하게 작동한다. 
// words라는 배열에 입력 받은 문자를 받아 들인다. 
// '== 1'의 의미는 입력 받은 것이 '하나이면'이라는 의미이다. 
// "%30s" <= string 하나를 입력 받도록 돼 있다. 
// <== 결국 '입력이 제대로 들어왔다면'이라는 의미이다. 
// 입력이 없다면 true가 아니므로, while() 문 밖으로 나갈 것이다. 
//  
// words[0] != '.' <= 입력 받은 strings 중 첫 글자가 '.' 마침표이면, 입력을 끝내겠다.
// 
// fprintf(fp, "%s\n", words); <= 파일 포인터 fp에다가 print를 하고 있다. 
// 포멧은 "%s\n" 이렇게 한다. (format specifier)
// words 문자열을 fp에다가 출력한다. 
// 
// printf(), scanf() 문법과 거의 비슷하다. 
// 
// rewind(fp);	/* go back to beginning of file */
// <= 파일의 처음으로 돌아가라. 
//    뭔가를 계속 출력을 하다가 rewind()를 만나면, 다시 처음으로 돌아가서 출력한다.
//
// 그 다음 아래 while()문이 실행된다. 
//  
// while (fscanf(fp, "%s", words) == 1)
//     fpinrtf(stdout, "%s\n", words);
// 
// fscanf() 함수로 인해 파일로부터 한 단어씩 읽어 들여서 words라는 배열에 저장을 한다. 
// fscanf() 함수의 반환값이 정상적으로 입력을 받았을 때, 
//	("%s" <= 입력 받은 아이템의 개수이다)
// 하나이면 true니까 1이다. <= 정상적으로 입력을 받았다는 의미이다. 
// EOF을 만났을 때는 EOF를 리턴을 한다. 
// 위에서 fscanf() == 1은 fscanf() != EOF로 해도 같은 기능을 한다. 
// 
// fpinrtf(stdout, ~ ) <= stdout을 해 주면, printf()와 동일해진다. 
// 
// 다 끝났으면, 파일을 닫아 준다. 
// if (fclose(fp) != 0)
//     fprintf(stderr, "Error closing file\n");
// <= 잘 안 닫히면 문제가 될 수 있으니까 에러 메시지를 출력하게 한다. 
// 
// 실행을 시키면, 
// Can't open "record" file. 이라는 출력이 된다. 
// <= 문제가 생겼다는 출력을 하고 끝났다. 
// 
// "r+" mode는 reading과 writing이 다 되는데, 파일이 없으면, 열지를 못한다.
// 
// "w+" mode에서는 reading과 writing이 다 되는데, 파일이 없으면 만들고, 
//		기존의 파일이 있으면 지워 버리고 다시 쓴다. 
// 
// if ((fp = fopen(filename, "r+")) == NULL)
// 위 이 if문의 "r+"를 "w+" mode로 바꿔 보자. 
// 
// 실행을 하면, 입력 커서가 뜨고, 콘솔 입력을 하면, 
// 입력한 내용이 화면에 출력이 되고, 'record'라는 파일로 저장이 된다. 
// 위에서 'record'의 확장자를 명시하지 않았으므로 확장자 없는 record 파일로 저장된다.
// record 파일은 메모장으로도 볼 수 있고, visual studio로도 볼 수 있다. 
// 또 record의 확장자를 .txt로 해 주면 쉽게 볼 수 있다. 
// 
// const char* filename = "record";	를
// const char* filename = "record.txt"; 로 해 주면 확장자가 txt로 저장된다. 
// 
// 다시 실행을 하고, 콘솔 입력을 하면, 
// 이전에 있던 내용에 over-writing을 한다. 즉 이전의 내용은 사라진다. 
// 
// "w+" mode를 "a+"로 바꾸고 실행을 해 보자. 
// 이번에는 좀 전 "w+" mode에서 입력했던 내용에 덧붙여서 화면에 출력이 되고, 
// 파일에도 저장이 된다. 
// 
// 이제 "a+" mode를 "r+" mode로 바꿔 보자. 
// 파일이 없는 상태에서 "r+"를 하면 에러가 생겼다. 
// 이제는 파일이 있는 상태이다. 
// 실행을 하면 어떻게 되는가?
// <==== 덮어 쓴다. 덮어 쓰는데 전체를 덮어 쓰는 게 아니라
//		 앞 부분부터 덮어 써 나가므로, 이전에 입력했던 내용이 새로 입력한 내용보다 
//       많다면, 그 이번 부분의 내용은 그대로 출력이 된다. 
// 
// r+, w+, a+ 세 가지 모드의 차이에 대해서 살펴 봤다. 