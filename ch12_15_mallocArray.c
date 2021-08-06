#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 동적 할당 메모리를 배열처럼 사용하기
//
// 동적 할당 메모리를 실제로 사용하는 예를 살펴 보자.
// 문법 위주로 살펴 본다.

int main() {

	/*
		One variable
	*/

	int* ptr = NULL;

	ptr = (int*)malloc(sizeof(int) * 1);
	if (!ptr) exit(1);

	*ptr = 1024 * 3;
	printf("%d\n", *ptr);

	free(ptr);
	ptr = NULL; 

	return 0;
}

// 이 예제는 동적 할당 메모리를 하나의 변수처럼 사용하고 있다. 
// 마치 어떤 변수에 대한 포인터를 알고 있다 정도로 생각할 수 있다. 
// 
// int* ptr = NULL; 포인터를 NULL로 초기화한다. 
// 
// ptr = (int*)malloc(sizeof(int) * 1); 동적 할당으로 받아 온다.
//										int 하나 치 메모리만 받아 온다.
// if (!ptr) exit(1); 메모리 할당이 안 됐을 때는 exit(1)로 나간다. 
//					  이런 일은 거의 일어나지 않을 것이다. 
// *ptr = 1024 * 3;	 indirection으로 값을 바꿔 주고 있다. 
// 
// free(ptr);		다 사용을 하면, free()로 메모리를 반납한다.
// ptr = NULL;		<= 이렇게 해 두면 깔끔하다. 
// 
// 변수 하나처럼, 변수 하나에 대한 포인터처럼 사용할 수 있다. 
// 하지만 변수 하나를 다루기 위해서 굳이 동적 할당까지 사용하는 일은 거의 없다.
// <= 변수처럼 사용할 수는 있지만 거의 사용하지는 않는다. 
//  
// 다음에서 일 차원 배열로 사용되는 예를 살펴 본다.