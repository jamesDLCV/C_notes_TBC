#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 다음은 메모리 누수를 돌려 보겠다. 

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
 
// 위처럼 엄청 욕심 많은 동적 할당 메모리를 요구하는 경우에는???
// free(ptr);을 안 해 주고 계속 할당만 받으면 어떻게 되는가???
// 디버거를 찍어서 Heap profiling의 task snapshot을 해 보면,
// Heap Size(Diff)가 계속 급격하게 증가하는 것을 볼 수 있다. 
// 컴퓨터가 가지고 있는 메모리의 한계를 넘어서까지 증가하게 되면,
// 문제가 발생한다. 
//  
// 실무에서 메모리 누수가 있는 프로그램을 런칭했다면, 
// 큰 일이 발생하는 것이다. 
// 
// 최근 실무에서 사용하는 언어는 이런 일이 가급적 발생하지 않도록
// 여러 가지 장치를 제공하고 있다. 
// 
// 이런 문제가 존재한다는 것과 왜 생기는지는 알고 있는 것이 좋다. 
// 실무에서 이런 사고가 발생하는 것을 방지해야 한다. 
// 
// fee(ptr); 해 주고 디버거의 break point 없이 실행을 시켜 보자.
// 이번에는 take snapshot를 해 봐도 
// Heap Size가 급격하게 증가하지 않는다. 
// 
// 할당 받고 반납하고 다시 돌아가서 할당 받고 반납하고를 반복하기 때문에, 
// 힙 메모리의 크기가 증가하지 않는다. <= 메모리가 새지 않는다. 
// 
// 필요한 메모리는 써야 하지만, 불필요한 메모리가 아주 작은 사이즈라도
// 쌓이고 쌓이면 문제가 발생한다. 
// 
// 메모리 누수를 관리하는 것은 좋은 프로그래머가 되기 위해서 반드시 
// 알아 둬야 하는 내용이다. 
// 
// x86으로 free(ptr);를 하지 말고 위 프로그램을 실행하면, 
// 오류가 발생한다. 
// 
// Dummy Output
// 1 2
// 1 2
// 1 2
// 1 2
// Malloc() failed
// 
// x86일 때는 컴퓨터 최대 메모리를 전부 Heap으로 사용할 수 있는 건 아니다. 
// 컴파일러가 컴파일할 때 사용할 수 있는 메모리의 한도가 조금 낮다. 
// 그래서 최근에서 x64를 사용하는 것이 일반적이다. 
// 
// 메모리 누수는 매우 위험한 것이다. 
//