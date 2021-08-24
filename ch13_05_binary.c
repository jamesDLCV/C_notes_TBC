#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Binary, 바이너리 파일 입출력
// 텍스트 파일과 달리 바이너리 파일은, 바이너리 데이터를 그대로 파일로 옮긴다. 

int main() {

	/*
		fopen() mode string for binary IO
		- "rb", "wb", "ab"
		- "ab+", "a+b"
		- "wb+", "w+b"
		- "ab+', "a+b"

		C11 'x' mode fails if the file exists, instead of overwriting it.
		- "wx", "wbx", "w+x", "w+bx"
	*/

	// Writing example
	{
		FILE* fp = fopen("binary_file", "wb");

		double d = 1.0 / 3.0;
		int n = 123;
		int* parr = (int*)malloc(sizeof(int) * n);
		if (!parr) exit(1);

		for (int n = 0; n < 123; ++n)
			*(parr + n) = n * 2;

		fwrite(&d, sizeof(d), 1, fp);
		fwrite(&n, sizeof(n), 1, fp);
		fwrite(parr, sizeof(int), n, fp);

		fclose(fp);
		free(parr);

		// Total size is 8 * 1 + 4 * 1 + 123 * 4 = 504 bytes
	}

	// Reading exmaple, feof(), ferror()
	{
		FILE* fp = fopen("binary_file", "rb");
		double d;
		int n = 0;

		fread(&d, sizeof(d), 1, fp);
		fread(&n, sizeof(n), 1, fp);

		int* parr = (int*)malloc(sizeof(int) * n);
		if (!parr) exit(1);

		fread(parr, sizeof(int), n, fp);

		printf("feof = %d\n", feof(fp));

		printf("%f\n", d);
		printf("%d\n", n);

		for (int i = 0; i < n; ++i)
			printf("%d ", *(parr + i));
		printf("\n");

		printf("feof = %d\n", feof(fp));

		fread(&n, sizeof(n), 1, fp);	      // read one more toward EOF

		printf("feof = %d\n", feof(fp));	  // returns non-zero at EOF
		printf("ferror = %d\n", ferror(fp));  // returns 0: ok

		fwrite(&n, sizeof(n), 1, fp);		  // try writing to make an error

		printf("ferror = %d\n", ferror(fp));  // 0 is ok, non-zero otherwise.

		fclose(fp);
		free(parr);
	}

	return 0;
}

// 바이너리에서 가장 먼저 봐야 할 것은, fopen()의 mode string에
// "rb", "wb", "ab"와 같이 b가 붙는다.
// r, w, a, + 옵션의 의미는 텍스트 파일의 mode string하고 동일하다.
// <= 뒤에 b만 붙여 주면 된다. 
// 
// "ab+", "a+b" 
// <= +는 맨뒤에 붙일 수도 있고, a 뒤에 붙일 수도 있다. 
// 구체적인 기능은 앞선 강의에서 소개한 것과 동일하다. 
//
// C11에서 'x' mode가 추가되었다. 
// "wx", "wbx", "w+x", "w+bx"와 같이 x가 붙은 mode가 추가된 것이다. 
// <= x를 붙여 주면, 파일이 이미 존재한다면, overwriting을 하지 않고, 
//    그냥 fails 실패를 하게 된다. 
//    overwriting을 하지 못하게 하는 옵션이다. 
// 
// FILE* fp = fopen("binary_file", "wb");
//	fopen()을 할 때 "wb", b가 들어간 mode string을 하고 있다 .
//  파일 이름은 "binary_file"이다. 
// 
// 우리가 알고 있는 대부분의 파일은 바이너리 파일이다. 
// doc, docx, hwp 파일 또한 모두 바이너리 파일이다. <= txt 파일로 읽을 수 없다. 
// 
// 공부를 할 때는 디버깅이 편하므로 txt 파일로 많이 하지만, 
// 실무에서는 바이너리 파일을 대부분 사용한다. 
// 
// 바이너리 입출력은 그렇게 어렵지는 않다. 
// 
// FILE* fp = fopen("binary_file", "wb");
//  바이너리 상태로 write하기 위해서 파일을 하나 열었다. 
// 
// double d = 1.0 / 3.0;
//  파일 d를 하나 저장했다. 
// d를 저장하려면, 
//  fwrite(&d, sizeof(d), 1, fp); <= fwrite()을 한 후 &d로 d의 주소를 넘겨 준다.
//  그다음 sizeof(d)를 넘겨 준다. 사이즈가 몇 개 짜리(여기에서는 1)가 
//  저장이 될지 넣어 준다. 그냥 메모리에 있는 데이터를, 그대로 &d가 시작점이고, 
//  &d에서부터 쫙 저장한다는 의미이다. 파일 포인터 fp는 뒤에 있다. 
// 
// 배열도 저장할 수 있다. 
// 배열을 저장할 때는, 파일을 저장하고 읽을 때 읽는 쪽에서 
// 몇 개인지 정확하게 알지 못한다면, 
// int n = 123; 이렇게 개수까지 같이 저장하는 것이 보통이다. 
// 
// int* parr = (int*)malloc(sizeof(int) * n);
//  n개만큼 메모리 공간을 확보한다. 
// 
// for (int n = 0; n < 123; ++n)
//     * (parr + n) = n * 2;
//  이렇게 데이터는 초기화했다. 
// 
// fwrite(&n, sizeof(n), 1, fp);
//  개수도 저장을 해 준다. 
// 
// fwrite(parr, sizeof(int), n, fp);
//  동적 배열을 그대로 wrting한다. 사이즈가 n이 붙었다. 
//  int가 n개가 있다. 4 (int) * n 개이다. (123 * 4 = 492)
//  parr는 자체가 포인터이므로 &가 안 붙었다. 
// 
// fclose(fp);
// free(parr);
//  사용이 끝나면, fclose()로 닫아 주고, free()로 메모리를 해제까지 해 준다. 
// 
// 파일 사이즈를 체크해 보자. 
// Total size is 8 * 1 + 4 * 1 + 123 * 4 = 504 bytes
//  double이 하나니까 8 * 1, int n도 한 개니까 4 * 1,   
//  동적 할당은 4(int) * 123 이니까 총 504 bytes이다. 
// <= 저장된 binary binary_file을 열고 속성을 눌러 보면, 
//    504 bytes인 걸 확인할 수 있다.
// 
// 다음 Reading example 코드를 보자.
// 
// 텍트트 파일을 열면 바로 읽을 수 있지만, 바이너리 파일은 열어도 읽을 수가 없다. 
// 파일을 읽는 쪽에서 이 바이너리 파일이 어떤 형식으로 만들어져 있는지, 
// 그러니까 double로 돼 있는지, char이 저장돼 있는지 등등을  
// 알고 있어야 해독을 할 수 있다. 
//  (물론 해킹을 하 듯이 전부 분석을 하는 경우도 있지만)
// 대부분의 경우에는 파일을 만든 쪽과 읽어 들이는 쪽이 이 파일이 어떻게 구성이 돼 있는지
// 잘 알고 있어야지만 해독을 하기 수월하다. 
// 
// 위에서 파일을 만들 때, double 한 개, int n 한 개, 
// 그리고 그 int n의 개수만큼의 int가 들어 있다는 걸 이미 알고 있다. 
// 
// fread(&d, sizeof(d), 1, fp);
// fread(&n, sizeof(n), 1, fp);
//  <= double d와 int n을 &d와 &n으로 읽어 들인다. 
// 
// n을 읽어 들인 후, 
// int* parr = (int*)malloc(sizeof(int) * n);
// if (!parr) exit(1);
// 동적 할당으로 메모리를 받는다. 
// 
// 동적 할당의 중요한 용법 중의 하나이다. 
// 만약 웹서비스를 만든다고 하면, 새로 가입하는 가입자 수는 매일 달라진다.
// 매일 매일 백업할 때마다 파일에 저장되는 사람의 수, 데이터의 수도 달라질 것이다. 
// 읽어 들일 때도 개수가 다르니까 매번 다른 개수로 읽어 들여야 한다. 
// <= 이럴 때 동적 할당을 사용한다. 
// 
// 읽어 들인 n의 개수에 맞춰서 
// int* parr = (int*)malloc(sizeof(int) * n); 
//  이렇게 메모리를 초기화하고, 
// 여기에다가, 
// fread(parr, sizeof(int), n, fp);
//  이렇게 쭉 받아 들이는 것이다. parr에 n개만큼의 int를 한 번에 쭉 일어 들이고 있다. 
// 
// 이때 이 데이터가 아주 크다면, 안 쪽에서 버퍼링이 작동하게 된다. 
// 버퍼가 몇 기가 정도로 크지는 않기 때문에, 
// 버퍼가 한 번 꽉 차고, 또 다시 읽어오는 것을 반복하면서 읽어 오고 있을 것이다. 
// 
// printf("feof = %d\n", feof(fp));
//  feof() 함수는 EOF를 만났는지를 물어 본다. 
// <= 지금 깔끔하게 저장된 개수만큼 메모리 할당이 됐으므로 eof을 만나지 못한 상황이다. 
// 
// 그래서, 
// printf("feof = %d\n", feof(fp));
//  eof을 만나지 못한 상태이다. 
// 
// 그 상태에서, 
// fread(&n, sizeof(n), 1, fp);	// read one more toward EOF
//  4bytes을 한 번 더 읽어 온다. 그러면 eof을 만날 수 있게 된다. 
// 
// 그 다음,
// printf("feof = %d\n", feof(fp));
//  feof() 함수를 호출하면, 0이 아닌 값을 반환하게 된다. 
// 
// printf("ferror = %d\n", ferror(fp));	
//  ferror()라는 함수는 파일 스트림이 데이터를 쭉쭉 읽어 가는데, 
//  이 때 무슨 문제가 있느냐 없느냐에 대한 것이다. 
// 
// 이제 이미 eof까지 온 상태에서, 강제로
// fwrite(&n, sizeof(n), 1, fp);			// try writing to make an error
//  여기에다가 writing을 하려고 한다.  
// 그러나, 위 
// FILE* fp = fopen("binary_file", "rb"); 에서 보면, 
//  이 파일은 "rb" 즉 read mode이다. 
//  <= write를 할 수가 없는 상태이다. 
//  
// 사실 eof과 상관 없이 read mode로 돼 있는 파일에다가 write를 하려고 하면, 
// 당연히 안 된다. 그러므로 에러가 발생한다. 
// printf("ferror = %d\n", ferror(fp));
//	<= error를 출력한다. ferror() 함수가 0이 아닌 값을 반환한다. 
// 
// 실행을 해 보면 다음과 같은 결괏값을 얻는다. 
// 
//feof = 0	
//	<= 처음 파일을 연 직후에는 feof가 0이다. 0은 EOF를 만나지 않았다는 뜻이다.
//0.333333
//123
//0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84 86 88 90 92 94 96 98 100 102 104 106 108 110 112 114 116 118 120 122 124 126 128 130 132 134 136 138 140 142 144 146 148 150 152 154 156 158 160 162 164 166 168 170 172 174 176 178 180 182 184 186 188 190 192 194 196 198 200 202 204 206 208 210 212 214 216 218 220 222 224 226 228 230 232 234 236 238 240 242 244
//feof = 0	<= EOF를 만나지 않았다. 
//             데이터를 저장된 만큼 정확하게 읽어 들였기 때문에, EOF를 만나지 않았다.
//feof = 1
//			<= 거기에서 한 번 더 나아가면, EOF가 1을 반환하게 된다. 
//             non-zero 값을 리턴하게 된다. 
//ferror = 0	<= ferror도 여기까지는 괜찮다가
//ferror = 1    <= read only 파일에다가 writing을 하려고 하니까,  
//                 문제가 있다고 0이 아닌 값을 반환해 주고 있다. 
// 
// 여기까지 바이너리 파일의 입출력 방법, 
// feof() 함수, ferror() 함수 사용법까지 살펴 봤다.  
// 실무에서는 바이너리 파일을 훨씬 더 많이 사용한다. 
// 문법 측면에서는 그렇게 어려운 면이 없다. 
// 
// 실무에서는 이 파일이 어떤 형식으로 작성되는가, 
// 어떤 데이터를 담고 있는가, 순서가 어떻게 되는가, 
// int, char, double 이런 형식을 지키면서, 잘 코딩하는 것이 실무에서는
// 익숙해질 필요가 있는 부분이다. 
// 
// 많은 양의 데이터를 한 번에 쭉 읽어 들이는 것이 가장 많이 사용하는 형태이다. 
// 동적 할당으로 동적 배열을 사용하는 것까지 소개했다. 