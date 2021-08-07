#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1차원 배열처럼 사용되는 동적 할당

int main() {

	/*
		1D array
	*/
	
	int n = 3;
	int* ptr = (int*)malloc(sizeof(int) * n);
	if (!ptr) exit(1);

	ptr[0] = 123;
	*(ptr + 1) = 456;
	*(ptr + 2) = 789;

	free(ptr);
	ptr = NULL;

	return 0;
}

// int n = 3; <= 런 타임에서 바뀌게 짤 수 있다. 
// int* ptr = (int*)malloc(sizeof(int) * n);
// n 과 int 크기를 곱하는 표현식으로 얼마나 메모리를 받아올지를 결정할 수 있다.
// 그 메모리를 동적 할당으로 받아오고, 
// 그 받은 메모리의 첫 번째 주소를 포인터 변수 ptr에 저장을 한다. 
// 
// 배열의 이름은 포인터와 거의 비슷하게 사용할 수 있다. 
// 완전히 동일하지는 않다. 
// 
// 동적 할당을 받은 메모리의 첫 주소에 대한 포인터 ptr은, 
// 배열처럼 사용할 수 있지만 배열과는 다르다. 
// 
// 배열은 automatic duration 자동 지속 기간을 갖기 때문에, 
// 블록을 나가면 메모리가 자동으로 해제된다. <= 빼 버린다. 
// 
// 동적 할당으로 받은 메모리는 힙에 들어 있으므로, 
// 수동으로 free(ptr); 해제를 해 줘야 한다. 
// 
// 동적 할당으로 받아오면, (x64로 빌드하면 특히)
// 사용할 수 있는 메모리가 훨씬 크다.
// 어마어마하게 큰 데이터를 다룰 때는, 동적 할당 메모리를 일반적인 배열보다
// 많이 사용하게 된다. 게다가 사이즈를 원하는 대로 바꿀 수도 있다. 
// 
// 그러므로 배열과 유사하게 사용할 수 있다. 
// 배열의 인덱싱도 사용할 수 있고, 포인터 연산으로 값을 저장할 수 있다. 
// ptr[0] = 123;
// *(ptr + 1) = 456;	<= +1이란 int가 4bytes이므로 4bytes씩 더한다.
// *(ptr + 2) = 789; 
// 
// 이렇게 1차원 array처럼 사용할 수 있다. 
// 
// int* ptr = (int*)malloc(sizeof(int) * n);
// 위와 같은 포인터 연산을 할 수 있도록 하기 위하여, 
// malloc() 함수가 우리에게 던져 주는 void pointer, generic pointer를
// 원하는 형인 int type으로 형 변환 casting을 해서 ptr에 넣어 주고 있다.
// <= 이렇게 형 변환을 했기 때문에, 위에서 포인터 연산을 할 수 있다. 
// 
// 2차원 배열을 사용하는 게 조금 문제가 될 수 있다. <= 어려울 수 있다. 