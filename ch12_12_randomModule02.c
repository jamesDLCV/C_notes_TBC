#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// srand(), 랜덤 넘버를 생성할 때 사용하는 함수가 포함됨.
#include <time.h>	// time()

// random seed 사용

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

// random seed에서 seed는 씨앗이라는 뜻이다. 
// 씨앗으로부터 random number들이 나온다. 
// 시작점이다. 이 정도로 생각하면 될 것이다. 
// 
// seed(1)로 했을 때, 결괏값은 다음과 같다. 여러 번 실행시켜도 같은 값이 나온다. 
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
// seed(2)로 했을 때, 결괏값은 다음과 같다. 여러 번 실행시켜도 같은 값이 나온다. 
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
// seed 값을 바꿔 봤자 같은 값이 계속 출력되므로, 
// seed에 들어갈 값으로 time() 함수를 넣는 방법이 사용된다. 
// 
//

