#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 동적 할당을 위해서 malloc() 함수를 사용했다. 
// 이번에는 malloc() 함수보다 
// 좀 더 기능이 많은 calloc(), reallock() 함수에 대해서 살펴 본다.

int main() {

	int n = 10;
	int* ptr = NULL;

	// ptr = (int*)malloc(sizeof(int) * n);
	ptr = (int*)calloc(n, sizeof(int));	// contiguous allocation
	if (!ptr)
		exit(1);

	for (int i = 0; i < n; ++i) {
		printf("%d ", ptr[i]);
	}
	printf("\n");

	/*
		realloc() KNK p. 422
		- doesn't initialize the bytes added
		- returns NULL if can't enlarge the memory block
		- If first argument is NULL, it behaves like malloc()
		- If second argument is 0, it frees the memory block.
	*/

	for (int i = 0; i < n; ++i) {
		ptr[i] = i + 1;
	}

	n = 20;

	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int));
	//ptr = (int*)realloc(ptr, n * sizeof(int));

	printf("%p %p\n", ptr, ptr2);

	printf("%d\n", ptr[0]);
	printf("\n");

	if (!ptr2)
		exit(1);
	else
		ptr = NULL;

	for (int i = 0; i < n; ++i)
		printf("%d ", ptr2[i]);		// copies data
	printf("\n");

	free(ptr2);

	return 0;
}

// calloc()은 contiguous allocation의 약자이다. 
// 
// ptr = (int*)calloc(n, sizeof(int));
// size가 int 짜리, 즉 4bytes 짜리가 n개 있다. 
// 연속돼 있는 메모리 공간을 받으라는 의미인 것 같다. 
// 문법적으로는 아래의 
// ptr = (int*)malloc(sizeof(int) * n)
// 과 별 차이가 없다.
// calloc(n, sizeof(int))도 내부적으로는 곱해서 처리할 것이다. 
// 
// calloc()과 malloc()의 문법적인 1차적인 차이는, 
// calloc() 위에 마우스를 갖다 대면, 
// size_t_Count, size_t_Size 두 개의 parameter를 갖는다.
// <= 각각의 크기가 얼마고, 그것이 총 몇 개냐.
// <= 4bytes 짜리 n개이다. 결국은 malloc()과 똑같아진다. 
// 
// calloc()과 malloc()의 중요한 차이가 있다. 
// malloc()은 메모리를 할당만 해 주고 초기화를 해 주지는 않는다. 
// 프로그래머 입장에서는 초기화를 안 해 주는 게 효율적일 수 있다. <= 연산을 줄인다.
// 어차피 다른 값으로 초기화해 줄 테니까 굳이 자동으로 초기화를 안 해 주는 게 나을 수 있다.
// 하지만 경우에 따라서는 0으로 초기화된 메모리를 받는 게 더 좋을 때도 있다. 
// calloc() 함수는 0으로 자동으로 초기화를 해 준다. 
// 
// malloc() 함수는 메모리를 할당 받아온 직후에 바로 출력을 하면 쓰레기 값이 출력됐다. 
// 
// realloc() 함수를 보자. 
// 일단 동적 할당으로 메모리를 한 번 받은 후, 
// 사이즈가 늘었거나, 줄어들었거나, 
// 즉 내가 필요로 하는 메모리의 사이즈가 늘어났거나, 
// 메모리가 이 정도까지는 필요 없고 덜 필요할 경우에, 
// 다시 할당을 받고 싶을 때 사용하는 함수이다. 
// 
// realloc()을 안 쓴다면, 예를 들어 100개 치의 메모리를 동적 할당 받았는데, 
// 200개가 필요하다고 하면, 다시 200개의 동적 할당 메모리를 받은 후 이전에 있던 
// 100개의 데이터를 복사를 하고, 100명 치의 메모리는 반납을 해야 한다. 
// <= realloc() 함수를 사용하면 이러한 과정을 한 번에 처리한다. 
// 
// 문법적으로 알아 둬야 할 사항이 있다. 
// realloc()으로 기존의 메모리 공간보다 더 큰 공간을 요구하면,
// 원래 있던 data를 그대로 복사해 준다. <= 편리하다. 
// 하지만 새로 추가된 메모리에 대해서는 0으로 초기화를 해 주지 않는다. 
// 그냥 준다. 추가된 부분을 출력하면 쓰레기 값이 나온다. 
// 
// 새로운 값을 할당해 줄 수 없는 경우에는 NULL 값을 리턴해서 못 했다고 알려 준다.
// 
// argument를 두 개 갖는다. 
// realloc()에 마우스를 갖다 대면,   
// void *_cdecl realloc(void*_Bock, size_t_Size)이 뜬다.
// 앞의 void*_Bock 포인터는 
// 이미 동적 할당으로 받아서 가지고 있는 메모리에 대한 포인터이다. <= 메모리 블록이다. 
// 메모리 블록에 대한 포인터를 넣으라는 의미로, void*_Bock라고 써 있다. 
// 새로 할당 받고 싶은 메로리 사이즈를 오른쪽 argument로 넣어 준다. 
// 
// malloc()으로 받았어도 realloc()으로 다시 받을 수 있다. 
// n = 20;	<= n을 바꿨다.
// int* ptr2 = NULL;
// ptr2 = (int*)realloc(ptr, n * sizeof(int));
// 위에서 calloc()으로 받은 포인터 ptr을 argument로 넣어 준다. 
// n * sizeof(int) <= 새로 늘어난 메로리 공간에 대해서 다시 재할당을 요청한다. 
// 만약 ptr이 NULL 포인터라면, malloc()처럼 작동한다. 
// <= 새로운 메모리를 던져 준다. 
// 
// 만약 second argument, 그러니까 할당을 요청하는 메모리의 사이즈가 0이라면,
// 메모리 블록을 free해 준다. 
// 
// 위에서와 같이 realloc()은 기능이 좀 더 많은 함수이다. 
// 
// ptr2 = (int*)realloc(ptr, n * sizeof(int)); <= 위는 예제라서 이렇게 했지만,
// ptr = (int*)realloc(ptr, n * sizeof(int));  <= 실무에서는 이렇게 기존의
// 포인터 ptr을 ptr에 넣어서 마치 포인터가 가리키고 있는 메모리가 늘어난 것처럼
// 사용할 수도 있다. 
//  
// printf("%p %p\n", ptr, ptr2); 
// 주소를 찍어 보면 ptr과 ptr2는 같을 수도 있다. 
// 하지만 보통은 다르게 나올 것이다. 
// ptr에 할당된 메모리 뒷쪽에 여유 공간이 많으면, 
// 포인터는 바뀌지 않고 그 뒷쪽을 더 쓰라고 줄 수도 있다. 
// 즉 새롭게 할당을 요청하면 그 뒷쪽을 쓰라고 할 수 있으므로 같은 포인터일 수 있지만, 
// 이건 운영체제가 결정할 문제이다.  
// 
// if (!ptr2)
//     exit(1);
// else
//     ptr = NULL; <= 포인터가 ptr2로 바뀌므로 
//                    원래 포인터는 NULL 값을 넣어서 사용할 수 없도록 막아 준다. 
// 
// ptr = (int*)realloc(ptr, n * sizeof(int)); <= 이렇게 사용한다면,
// 위처럼 ptr = NULL;을 해 주면 안 된다. 
// 
// realloc()은 data를 복사까지 해 준다. 
// 하지만 위에서 언급한 대로 새로 추가된 메모리의 초기화는 해 주지 않는다. 
// 
// free(ptr2);	<= free()를 해 주고 끝난다. 
// 
// 실행을 해 보면, 
// 0 0 0 0 0 0 0 0 0 0
// 00000282DAC65300 00000282DAC65300 <= ptr과 ptr2가 같은 주소이나 다를 때가 많다.
// 1

// 1 2 3 4 5 6 7 8 9 10 - 842150451 - 842150451 - 842150451 - 842150451 - 842150451 - 842150451 - 842150451 - 842150451 - 842150451 - 842150451
// <= realloc()에 의해 포인터가 바뀌었다. 
// <= 앞 부분은 기존의 data를 복사해서 넣어 줬으나 뒷 부분은 쓰레기 값이 출력됐다. 
// 
// 지금까지 malloc() 함수보다 기능이 많은 calloc()과 realloc() 함수에 대해서 살펴 봤다.