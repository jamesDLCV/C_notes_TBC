#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>		// time()
#include "my_rand.h"	// 재활용할 수 있도록 이렇게 한다. 
						// my_srand() 함수가 header에 들어 있다. 

// 연습 문제
// 직접 rand() 함수와 똑같은 기능을 하는 프로그램을 짜 보라. 
// 모듈 형태로 쪼개 서 해 봐라. 
// 

int main() {

	my_srand((unsigned int)time(0));

	for (int i = 0; i < 10; ++i) {
		printf("%d\n", my_rand() % 6 + 1);
	}	

	return 0;
}

// my_rand() % 6	 <= 값은 0, 1, 2, 3, 4, 5 (0 ~ 5)
// my_rand() % 6 + 1 <= 값은 1, 2, 3, 4, 5, 6 (1 ~ 6)
//
// 실행을 하면, time() 함수로부터 값을 받아들이기 때문에, 
// 값은 매번 바뀌게 된다. 
// 
// 지금까지 random numbers를 생성하는 코드에 대해서 살펴 봤다. 
// random numbers를 생성할 때 컴퓨터는 알고리즘을 사용한다. 
// 사람이 사용하는 random numbers하고는 좀 차이가 있다. 
// 
// 어떤 기능을 묶어서, 사용이 가능한 모듈 형태로 만들 수 있다 .
// 헤더 파일과 c 파일을 이용해서, 정리를 해 나갈 수 있다. 
//
