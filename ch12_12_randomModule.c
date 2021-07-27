#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// srand(), 랜덤 넘버를 생성할 때 사용하는 함수가 포함됨.
#include <time.h>	// time()

// C언어에서 난수를 생성하는 방법에 대해서 살펴 보고, 
// 직접 난수 생성기를 만들고, 
// 그 난수 생성기 코드를 모듈로 정리하는 방법에 대해서 예제로 풀어 보겠다. 

int main() {

	/*
		rand()
		- 0 to RAND_MAX (typically INT_MAX)
		- defined in stdlib.h
	*/

	for (int i = 0; i < 10; ++i) {
		printf("%d\n", rand());		
	}
	
	return 0;
}

// C언어에서 난수를 생성할 때, 임의의 숫자를 생성할 때는, rand() 함수를 사용한다.
// 0 to RAND_MAX 
// 0 이상 RAND_MAX로 매크로 정의돼 있는 심볼릭 상수까지의 숫자 중 난수를 생성한다.
// 진짜 random한 숫자는 아니고, 사람이 봤을 때 random하게 보이는 숫자다. 
// 
// RAND_MAX는 typically INT_MAX, 전형적으로 INT_MAX와 같은 값이다. 
// 열 개를 출력해 보면, 다음과 같다. 
// 
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
// 임의의 숫자인 것 같지만, 여러 번 실행시켜도 같은 값이 출력된다. 
// 컴퓨터는 진정한 난수를 만드는 능력은 없다. 기계이기 때문이다. 
// 
// 보완하는 방식으로 random seed를 사용한다. 
// 
