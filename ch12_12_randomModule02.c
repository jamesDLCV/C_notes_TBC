#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// srand(), ���� �ѹ��� ������ �� ����ϴ� �Լ��� ���Ե�.
#include <time.h>	// time()

// random seed ���

int main() {

	/*
		rand()
		- 0 to RAND_MAX (typically INT_MAX)
		- defined in stdlib.h
	*/

	srand(2);	// random seed
	//srand((unsigned int)time(0));

	for (int i = 0; i < 10; ++i) {
		printf("%d\n", rand());
		//printf("%d\n", rand() % 6 + 1);
	}

	//unsigned int next = 1;

	return 0;
}

// random seed���� seed�� �����̶�� ���̴�. 
// �������κ��� random number���� ���´�. 
// �������̴�. �� ������ �����ϸ� �� ���̴�. 
// 
// seed(1)�� ���� ��, �ᱣ���� ������ ����. ���� �� ������ѵ� ���� ���� ���´�. 
//41
//18467
//6334
//26500
//19169
//15724
//11478
//29358
//26962
//24464
// 
// seed(2)�� ���� ��, �ᱣ���� ������ ����. ���� �� ������ѵ� ���� ���� ���´�. 
//45
//29216
//24198
//17795
//29484
//19650
//14590
//26431
//10705
//18316
//
// seed ���� �ٲ� ���� ���� ���� ��� ��µǹǷ�, 
// seed�� �� ������ time() �Լ��� �ִ� ����� ���ȴ�. 
// 
//

