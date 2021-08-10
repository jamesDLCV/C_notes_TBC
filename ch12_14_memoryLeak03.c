#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ������ �޸� ������ ���� ���ڴ�. 

int main() {

	printf("Dummy Output\n");

	for (int k = 0; k < 1000000; ++k) 
	{
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));

		if (!ptr)	// if(ptr == NULL)
		{
			printf("Malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i) 
		{
			ptr[i] = i + 1;
		}

		printf("%d %d\n", ptr[0], ptr[1]);

		//free(ptr);
		//ptr = NULL;
	}
	// What happens?
		
	printf("Dummy Output\n");

	return 0;
}
 
// ��ó�� ��û ��� ���� ���� �Ҵ� �޸𸮸� �䱸�ϴ� ��쿡��???
// free(ptr);�� �� �� �ְ� ��� �Ҵ縸 ������ ��� �Ǵ°�???
// ����Ÿ� �� Heap profiling�� task snapshot�� �� ����,
// Heap Size(Diff)�� ��� �ް��ϰ� �����ϴ� ���� �� �� �ִ�. 
// ��ǻ�Ͱ� ������ �ִ� �޸��� �Ѱ踦 �Ѿ���� �����ϰ� �Ǹ�,
// ������ �߻��Ѵ�. 
//  
// �ǹ����� �޸� ������ �ִ� ���α׷��� ��Ī�ߴٸ�, 
// ū ���� �߻��ϴ� ���̴�. 
// 
// �ֱ� �ǹ����� ����ϴ� ���� �̷� ���� ������ �߻����� �ʵ���
// ���� ���� ��ġ�� �����ϰ� �ִ�. 
// 
// �̷� ������ �����Ѵٴ� �Ͱ� �� ��������� �˰� �ִ� ���� ����. 
// �ǹ����� �̷� ����� �߻��ϴ� ���� �����ؾ� �Ѵ�. 
// 
// fee(ptr); �� �ְ� ������� break point ���� ������ ���� ����.
// �̹����� take snapshot�� �� ���� 
// Heap Size�� �ް��ϰ� �������� �ʴ´�. 
// 
// �Ҵ� �ް� �ݳ��ϰ� �ٽ� ���ư��� �Ҵ� �ް� �ݳ��ϰ��� �ݺ��ϱ� ������, 
// �� �޸��� ũ�Ⱑ �������� �ʴ´�. <= �޸𸮰� ���� �ʴ´�. 
// 
// �ʿ��� �޸𸮴� ��� ������, ���ʿ��� �޸𸮰� ���� ���� �������
// ���̰� ���̸� ������ �߻��Ѵ�. 
// 
// �޸� ������ �����ϴ� ���� ���� ���α׷��Ӱ� �Ǳ� ���ؼ� �ݵ�� 
// �˾� �־� �ϴ� �����̴�. 
// 
// x86���� free(ptr);�� ���� ���� �� ���α׷��� �����ϸ�, 
// ������ �߻��Ѵ�. 
// 
// Dummy Output
// 1 2
// 1 2
// 1 2
// 1 2
// Malloc() failed
// 
// x86�� ���� ��ǻ�� �ִ� �޸𸮸� ���� Heap���� ����� �� �ִ� �� �ƴϴ�. 
// �����Ϸ��� �������� �� ����� �� �ִ� �޸��� �ѵ��� ���� ����. 
// �׷��� �ֱٿ��� x64�� ����ϴ� ���� �Ϲ����̴�. 
// 
// �޸� ������ �ſ� ������ ���̴�. 
//