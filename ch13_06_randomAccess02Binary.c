#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Binary random access
// 
// ���̳ʸ� ���Ͽ��� random access�� ��� �ϴ��� ���ڴ�. 

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

// FILE* fp = fopen("binary", "wb"); ���̳ʸ� ������ �ϳ� �������. 
// ���̳ʸ� ������ ���� �� for������ double 100���� ������ ���Ҵ�. 
// 
// ������ ���ڸ���, ���� ��ġ�� ��� ����,
// cur = ftell(fp);
// printf("Before reading %ld\n", cur);
//	<= ���) Before reading 0, <= ���� ��ġ�� 0�̴�. 
// 
// fread(&d, sizeof(double), 1, fp);
//	fread(), (double�� ������ ���� �����̴ϱ�) double�� �д´�.
// 
// fread()�� ���� �� ���� ��ġ�� ��� ����, 
// cur = ftell(fp);
// printf("After reading %ld\n", cur);
//	<= ���) After reading 8, <= double�� 8bytes�̹Ƿ� 8�� �̵��� �Ѵ�. 
//  ���������� ���� �ϳ��� �����ϱ� 1byte�� �̵��� �� ���̴�. 
// 
// fseek(fp, 32L, SEEK_SET);	// 32 = 4 * 8
// fread(&d, sizeof(double), 1, fp);
// printf("%f\n", d);
//  <= 32L�� double(8) �� ����ŭ �̵��� �ؼ� fread()�� �ϴ� ���°� �ȴ�. 
//     ���) 4.440000, (0, 1.11, 2.22, 3.33, 4.44) 
// 
// ������ ���� ���� ����� ���ؼ� fseek(), ftell() �Լ� �� ������ ���ַ� ���� �ô�.