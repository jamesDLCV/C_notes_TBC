#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// srand(), 랜덤 넘버를 생성할 때 사용하는 함수가 포함됨.
#include <time.h>	// time()

// random seed로 time() 함수 사용

int main() {

	/*
		rand()
		- 0 to RAND_MAX (typically INT_MAX)
		- defined in stdlib.h
	*/
	
	srand((unsigned int)time(0));
	
	for (int i = 0; i < 10; ++i) {	
		printf("%d\n", rand());
		//printf("%d\n", rand() % 6 + 1);
	}
	printf("\n\n");

	// 다음은 내부적으로 사용하는 알고리즘 중의 한 가지이다. 
	unsigned int next = 1;

	for (int i = 0; i < 10; ++i) {
		next = next * 1103515245 + 1234;
		next = (unsigned int)(next / 65536) % 32768;
		printf("%d\n", (int)next);
	}

	printf("\n\n");

	// seed 값을 time() 함수로 바꾸었다. 
	unsigned int next2 = (unsigned int)time(0);

	for (int i = 0; i < 10; ++i) {
		next2 = next2 * 1103515245 + 1234;
		next2 = (unsigned int)(next2 / 65536) % 32768;
		printf("%d\n", (int)next2);
	}

	return 0;
}

// srand((unsigned int)time(0)); 에서 time() 함수를 호출했을 때, 
// 리턴하는 값은 시간에 따라 다르다. 
// 그래서 seed 값이 변하는,
// 우리가 예측하기 힘든 값으로 seed 값이 자동으로 바뀌어서 
// 설정이 되는 효과가 나타난다. 
// 
//32435
//16393
//4150
//30356
//17529
//1724
//28491
//19979
//13624
//20311
// 
// 실행될 때마다 다른 값이 생성된다. 
// rand() 함수가 만들어내는 값이 새로운 값으로 출력된다. 
// 
/*
unsigned int next = 1;		<= seed 값이 설정이 된다. 

for (int i = 0; i < 10; ++i) {
	next = next * 1103515245 + 1234; <= 곱하고 더하는 데 규칙이 있다. 
								   <= 유사 난수, pseudo random number라고 한다.
								   <= overflow를 이용한다. 
	next = (unsigned int)(next / 65536) % 32768;
								   <= 자릿수를 맞춰 주기 위해서 사용한다. 
								   <= 음수가 나오면 안 된다. 
								   <= int type으로 숫자를 맞춰 주기 위해서 
								   <= 이런 코드를 사용한다. 
	// C언어에서 위 코드와 동일한 알고리즘을 사용한다고는 말하지 못하겠다. 
	// 컴파일러를 만든 사람들이 rand() 함수를 어떻게 만들었는지 알기가 어렵다.
	//
	// C언어 말고 다른 언어들에는 보다 정밀하게 난수를 만들어 주는 함수가 
	// 라이브러리에 들어 있다.
	// 
	// C언어로 게임을 만들 때 난수는 위 코드로 충분하다. 
	// 통계학적으로 정밀한 난수를 만들어야 할 때는 
	// 다른 라이브러리를 가져다 쓸 수 있다.
	// 
	// 유사 난수의 경우 겉으로는 난수 같지만, 
	// 위 코드에서와 같이 규칙이 있다는 것을 알 수 있다. 
	printf("%d\n", (int)next);
	// 여러 번 실행시켜도 똑같은 숫자가 나온다. 
}
*/

// seed 값을 time() 함수로 바꾸면 실행시킬 때마다 다른 숫자가 생성된다. 
// 