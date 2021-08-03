#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 메모리 누수 leak와 free()의 중요성
// 비주얼 스튜디어 진단 도구 사용법
// 
// 앞 강의에서 메모리 동적 할당을 사용할 때, 
// 일단 할당 받은 메모리를 다 사용했다면,
// 반드시 반납을 하는 것이 중요하다고 했다. 
// 
// free() 함수를 사용해서 운영체제에게 메모리를 반납해서  
// 내가 지금 작성한 프로그램이 다시 그 메모리를 사용하거나, 
// 운영체제가 관리하는 다른 프로그램이 그 메모리를 사용하게 한다.
// 
// 반납을 하지 않았을 때 생기는 문제를 메모리 누수 memory leak이라고 한다.
// 메모리가 새는 것은 나중에 문제가 생길 수 있으므로, 
// 정말 중요하게 진단을 하야 한다. 
// 
// 다음 코드에서 살펴 조자.
// Heap을 크게 사용하려면, x64를 사용해야 한다. 
// 실무에서는 x64를 많이 사용하게 될 것이다. 
// 
// 메모리 누수를 강제로 만들려고 하므로 메모리 공간이 커야 한다. 

int main() {

	printf("Dummy Output\n");

	{
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int)); 

		if (!ptr)	// if(ptr == NULL) 
		{
			printf("Malloc() failed"); 
			exit(EXIT_FAILURE);
		}
			
		for (int i = 0; i < n; ++i)
			ptr[i] = i + 1;

		free(ptr);
		ptr = NULL;
	}
	 // What happens?

	printf("Dummy Output\n");

	return 0;
}

// 포인터가 초기화가 제대로 됐는지 확인하는 방법은?
// malloc이 제대로 메모리 주소를 줬는지 안 줬는지 체크할 때는?
// if (!ptr)	// if (ptr == NULL) 
// 위처럼 !ptr로 할 수도 있고 ptr == NULL로 할 수도 있다. 동일하다.
// if (ptr == NULL) <= 이게 더 직관적이지 않을까? 
// 
//int n = 100000000;
//int* ptr = (int*)malloc(n * sizeof(int));
// 
// 4억 bytes의 메모리 공간을 달라. <= 381 mega
// 큰 문제가 될 메모리 량은 아니다. 
// 
// 실행을 시키면 아무 문제가 없다. 
// 
// 디버깅을 해 보자. 
// 아무데나 찍고 디버깅을 실행한다. 
// 
// Diagnostic Tools를 본다. 
// 메모리를 얼마나 많이 사용하는지,
// CPU를 얼마나 많이 사용하는지 알 수 있다. 
// 
// Diagnostic Tools의 Memory Usage에서 Heap Profiling을 클릭하여,
// 활성화시킨다. 
// 
// Take Snapshot을 눌러서 현재 상태를 찍어 놓는다.
// F10을 눌러서 다음으로 간 후 다시 Take Snapshot을 누른다.
// 
// int* ptr = (int*)malloc(n * sizeof(int)); 을 실행시킨 후,
// Take Snapshot을 해 보면, Heap Size(Diff)에 변동이 생긴다. 
// <= 390메가 정도가 생겼다. 
// 
// Heap memory에 메모리가 잡힌 것이다. 
// 프로그램이 운영체제로부터 390메가 정도를 받아온 것이다. 
// 
// ptr이라는 식별자 identifier는 블록 안에서만 살아 있다. 
// 포인터 변수 ptr 자체는 automatic duration을 가지고 있다. 
// 그러므로 위 블록 밖으로 나가면 ptr은 사라져 버린다.
// 
// 변수 ptr이 사라지더라도 Heap의 메모리를 사라지지 않을까?
// 블록 밖으로 나가서 다시 take snapshot을 해 보면,
// Heap 사이즈의 변화가 전혀 없다. <= free(ptr);을 안 해 줬을 때
// 
// malloc() 함수로 받아온 동적 할당 메모리(힙에 있는 메모리)의
// 포인터 변수 ptr은 block scope를 벗어나면서 사라졌지만, 
// 동적 할당으로 받아온 메모리 자체는 메모리 공간에 살아 있다. 
// <= 그래서 프로그램 전체에서 사용하는 메모리에 가득차 있다. 
// 하지만, ptr 변수를 잃어 버렸기 때문에, 
// 블록 밖에서 이 메모리에 접근해서 무슨 작업을 할 방법이 없다. 
// 
// free(ptr);의 주석 처리를 해제하고 디버깅을 해 보자.
//	<= 마우스 우클릭 run to cursor를 누르고 다음으로 넘어간다. 
// 
// free(ptr);을 해 준 후 heap memory를 take snapshot을 해 보면,
// heap에 있던 메모리가 반납된 것을 볼 수 있다. 
// 깔끔하게 돌려 줬다. 
// 
// 동적 할당 메모리의 특징을 이용하는 방법도 있다. 
// 블록을 벗어나도 free(ptr);을 하지 않으면 메모리에 그대로 남아 있다. 
// 이것을 이용하려면, 다음과 같이 할 수 있다. 
// <= 권장하지는 않는다. 블록을 벗어나면 메모리에서 사라지는 것이 깔끔하다.
// 사라져야 실수를 할 여지가 줄어든다.  
// 