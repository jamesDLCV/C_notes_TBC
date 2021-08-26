#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Binary random access
// 
// 바이너리 파일에서 random access를 어떻게 하는지 보겠다. 

int main() {

	// make a test binary file
	{
		FILE* fp = fopen("binary", "wb");
		for (int i = 0; i < 100; ++i)
		{
			double d = i * 1.11;
			fwrite(&d, sizeof(double), 1, fp);
		}
		fclose(fp);
	}

	// read

	FILE* fp = fopen("binary", "rb");
	long cur;
	double d;

	cur = ftell(fp);
	printf("Before reading %ld\n", cur);

	fread(&d, sizeof(double), 1, fp);

	cur = ftell(fp);
	printf("After reading %ld\n", cur);

	printf("%f\n", d);

	fread(&d, sizeof(double), 1, fp);
	printf("%f\n", d);

	cur = ftell(fp);
	printf("After reading %ld\n", cur);

	fseek(fp, 32L, SEEK_SET);	// 32 = 4 * 8
	fread(&d, sizeof(double), 1, fp);
	printf("%f\n", d);

	fclose(fp);

	return 0;
}

// FILE* fp = fopen("binary", "wb"); 바이너리 파일을 하나 만들었다. 
// 바이너리 파일을 만든 후 for문으로 double 100개를 저장해 놓았다. 
// 
// 파일을 열자마자, 현재 위치를 찍어 보면,
// cur = ftell(fp);
// printf("Before reading %ld\n", cur);
//	<= 출력) Before reading 0, <= 현재 위치는 0이다. 
// 
// fread(&d, sizeof(double), 1, fp);
//	fread(), (double을 저장해 놓은 파일이니까) double을 읽는다.
// 
// fread()로 읽은 후 현재 위치를 찍어 보면, 
// cur = ftell(fp);
// printf("After reading %ld\n", cur);
//	<= 출력) After reading 8, <= double이 8bytes이므로 8씩 이동을 한다. 
//  이전에서는 문자 하나씩 읽으니까 1byte씩 이동을 한 것이다. 
// 
// fseek(fp, 32L, SEEK_SET);	// 32 = 4 * 8
// fread(&d, sizeof(double), 1, fp);
// printf("%f\n", d);
//  <= 32L은 double(8) 네 개만큼 이동을 해서 fread()를 하는 형태가 된다. 
//     출력) 4.440000, (0, 1.11, 2.22, 3.33, 4.44) 
// 
// 파일의 임의 접근 방법에 대해서 fseek(), ftell() 함수 두 가지를 위주로 살펴 봤다.