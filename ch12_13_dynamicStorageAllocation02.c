#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// malloc(), free()

int main() {
	float x;
	char str[] = "Dancing with a Star";

	int arr[100];

	/*
		malloc() returns a void type pointer.
		void* : generic pointer

		free() deallocates the memory
		
	*/

	double* ptr = NULL;

	ptr = (double*)malloc(30 * sizeof(double));

	if (ptr == NULL) {
		puts("Memory allocation failed.");

	/*
		exit(EXIT_FAILURE) is simillar to return 1 IN main().
		exit(EXIT_SUCCESS) is simillar to return 0 In main().
	*/

		exit(EXIT_FAILURE);
	}

	printf("Before free %p\n", ptr);

	free(ptr);	// no action occurs when ptr is NULL

	printf("After free %p\n", ptr);

	ptr = NULL;	// optional

	/* Dynamically Allocated Array */

	return 0;
}

// main() 함수의 다음의 것들은 statck에 저장이 된다.
// float x;
// char str[] = "Dancing with a Star";
//
// int arr[100];
// 
// 이에 대해서는 메모리 구조에서 설명했다. 
// 이런 statck에 저장되는 것들과 malloc은 다르다. 
// 
// 메모리를 할당해 달라. <= memory allocation, malloc() 함수를 사용.
// malloc() 함수의 parameter는 마우스를 갖다 대 보면, 
// size_t_Size라고 뜬다. 
// size_t는 typedef unsigned int이다. 
// typedef는 다른 이름을 만들어 주는 것이다로 정리. 
// 몇 bytes 메모리를 요청할지 사이즈만 적어 주면 된다. 
// 
// ptr = (double*)malloc(30 * sizeof(double));
// 
// double 30 개를 저장할 수 있는 메모리 공간이 필요하다. 
// 나중에는 수억 개의 저장을 할 수 있는 메모리 공간이 필요할 것이다. 
// 단, 컴퓨터에 이 정도의 메모리가 있어야 한다. 
// 
// 위의 숫자 30에는 큰 숫자 or 런 타임에 결정이 되는 변수도 들어갈 수 있다. 
// 몇 bytes 메모리가 사용될지 적어 주는 것이다. 
// 30 * 8 (double) = 240 bytes를 요청하는 것이다. 
// 
// 운영체제가 가지고 있는 메모리 중에서,   
// 운영체제 입장에서는 여러 개의 프로그램이 작동하고 있다. 
// 다른 프로그램이 쓰고 있는 메모리까지 포함해서, 
// 남아 있는 메모리 중에서, 
// Heap 공간에다가 240 bytes의 메모리를 배정해 달라고 요청하는 것이다. 
// 
// 이 메모리를 쓰라는 의미로, 
// 운영체제가 할당해 주는 240 bytes의 메모리 공간의
// 첫 번째 주소를 return해 준다. 
//	위 malloc() 함수 위에 마우스를 갖다 대면, 
//	void*_cdecl malloc(size_t_Size)가 뜬다. <= 첫 번째 주소
// 포인터를 알려 준다. 포인터를 받을 수 있다. 
// 
// malloc() returns a void type pointer.
//	malloc() 함수가 리턴해 주는 게 void type의 포인터이다. 
//	void type이란 어떤 타입을 받는 것이 아니라 그냥 순수한 주소라는 의미이다.
//	운영체제 입장에서는 어디에 쓸지에 대해서는 관심이 없다. 
//	어떤 타입의 배열로 사용할지에 대해서는 관심이 없는 것이다. 
//  240 bytes를 달라고 했으니 240 bytes를 줄 뿐이다. 
// 
// 그래서 쓰는 쪽에서 casting 형 변환을 해 준다. 
// ptr = (double*)malloc(30 * sizeof(double));
//	이 예제에서는 double 타입의 배열처럼 사용하려고 하므로, 
//  double 타입의 포인터로 casting을 해 주고 있다. 
// 
// void* : generic pointer
//	void* 보이드 포인터는 generic pointer라고도 부른다. 
//	특별한 자료형을 갖는 것이 아니고 순수한 주소 자체이기 때문에
//	generic이라는 용어를 사용한다. (generic 일반 명칭인)
//	void* 보이드 포인터는 포인터 연산을 사용할 수 없다.
//  자료형의 크기를 모르기 때문이다. 
// 
// ptr = (double*)malloc(30 * sizeof(double));
// 캐스팅을 해서 특정한 자료형의 배열인 것처럼 사용할 수 있다. 
// 
// 배열이란 같은 자요형의 데이터 여러 개가 메모리에 나열돼 있는 형태이다. 
// 연속적으로 나열돼 있는 메모리 공간을 malloc() 함수를 통해서 가지고 왔다. 
// 결국은 배열처럼 사용하게 되는 게 대부분이다. 
// 
// malloc() 함수는, 만약 할당할 수 있는 메모리가 없다면, 
// NULL pointer를 리턴한다. ptr에 NULL 포인터가 들어온다. 
// 
// if (ptr == NULL) {
//	puts("Memory allocation failed.");
// }
// NULL pointer일 경우, 
// C 프로그래머들은, 위처럼 put() 함수로 에러 메시지를 보낸다. 
// 
// 대부분의 경우 메모리 할당이 안 된다는 것은,
// 아주 심각해서 더 이상 프로그램을 진행할 수가 없는 경우이다. 
// exit(EXIT_FAILURE);
// <= 이렇게 exit() 함수를 사용해서 강제로 종료하는 것이 일반적이다. 
// 
// 웹 서버를 만든다거나 그 어떤 경우에도 계속 돌아가야 하는 프로그램을 만들 때는,
// 오류 처리를 활용해서 <= 메모리가 할당이 안 됐다. 어떻게 해야 하느냐, 
// 대안을 찾자 등등으로 처리를 한다. 
//	<= 이런 오류 처리 문법을 사용할 수 있다. 
// 이런 오류 처리 기술은 다른 언어를 공부할 때 배우면 된다. 
// 
// C언어의 경우에는 메모리 할당이 안 됐다면, 
// exit() 함수로 나가는 경우가 많다. 
// 메모리 할당이 안 된다는 것은 아주 심각해서 더 이상 
// 프로그램을 진행할 수 없는 경우이므로 exit()로 강제 종료하는 것이 보통이다.
// 꼭 강제 종료해야 하는 것은 아니다. 
// 기다린다거나 사이즈를 줄여서 다시 요청한다거나 등등 여러 가시 시도를 할 수 있다.
// 
// exit() 함수로 나가는 경우는 실제 프로그램에서보다는 
// 디버깅할 때 많이 사용한다. 
// 
// exit(EXIT_FAILURE); 의 EXIT_FAILURE 매크로는 1로 돼 있다. 
// 이것은 main() 안에서 return 1; 이라고 하는 것과 동일하다. 
// return 0; 이외의 다른 숫자로 끝나는 것은, 
// OS에 뭔가 문제가 있다는 것을 말하는 것이다. 
// <= 뭔가 문제가 생겼다. 그런데 끝났다라고 말하는 것이다. 
// 
// return 0; 와 return 1;은 main() 함수에서만 쓸 수 있다. 
// 반면, 
// exit() 함수를 쓰면, 어떤 함수에서도 강제로 프로그램을 종료할 수 있다. 
// 디버깅할 때, 여기까지만 해 보고 끝내겠다고 할 때는 exit() 함수를 쓴다.
// 
// malloc() 함수로 메모리 할당이 안 되는 경우를, 
// 공부할 때는 보기 힘들다. 
// 할당 메모릴 크기가 어마어마하게 커야 하는데 보통 학습할 때는
// 그렇게 큰 메모리를 할당하지 않는다. 
// 
// malloc() 함수가 메모리 할당을 못 해서, 
// NULL 포인터를 리턴하는 경우는, 여러 가지가 있다. 
// 메모리 고장(확률 적음), 
// 너무 큰 공간의 메모리를 요청해서 할당할 수 없는 경우, 
// 요즘은 메모리 사이즈가 크므로 그리 큰 문제가 되지는 않는다.
// 이보다는 이것 저것 많은 프로그램을 띄워 놨을 때, 
// 운영체제가 연속된 공간을 줄 수 없을 경우가 발생한다. 
// 메모리 전체로 봤을 때는 여유 공간이 있는데, 
// 그 여유 공간에 프로그래머가 요청한 만큼의 분량이 일렬로 나열돼 있지 않고, 
// 여기 저기 파편화 돼 있을 때는 할당을 못 해 줄 수도 있다. 
// <= 가상 주소 공간을 사용해서 보완이 되기는 한다. 
// 
// malloc() 함수가 문제를 일으키는 경우가 공부할 때는 거의 없지만,
// 연구를 하거나 실무에서는 문제가 생길 수 있다. 
// 
// ptr = (double*)malloc(30 * sizeof(double));
// 포인터 ptr은 block scope에 들어 있고,
// automatic duration을 갖는다. 
// 블록 밖으로 나가면 포인터 자체는 사라진다. 
//	포인터 변수는 블록 밖으로 나가면 잃어 버릴 수가 있다. 
// automatic duration 때문에 블록 밖으로 나가면 사라진다. 
// <= 힙에는 분명히 메모리가 살아 있는데, 
// 메모리에 접근할 포인터 주소는 잃어 버렸기 때문에,
// 그 메모리에 접근해서 값을 가져올 수도 없고, 
// 그 메모리에 값을 저장할 수도 없는 어이 없는 경우가 발생한다.
// 
// C언어 프로그래밍 할 때, C언어로 자료 구조를 공부할 때, 
// 이 부분에 대해서 어려움을 겪을 수 있다. 
// 
// 동적 할당 받은 메모리하고 포인터 ptr를 동일시하면 안 된다. 
// ptr은 주소를 적어 놓은 쪽지일 뿐이다. 
// 쪽지를 잃어 버려도 메모리는 존재한다. 
// 
// 초보 때 많이 실수하는 것이, 
// 메모리 주소, 포인터를 잃어 버리고, 
// 동적 할당만 계속 하는 것이다. 계속 반복하다 보면 Heap이 꽉 차 버린다.
// <= 문제가 발생한다. 이건 이후 자료 구조를 공부할 때 정리하기를 바란다.
// 
// 그 다음 포인터를 다 사용했을 때는, 반납을 해 줘야 한다.
// free(ptr);	// no action occurs when ptr is NULL
//	<= 중요한 요소이다. 
// 1. OS에게 반납을 해 줘서 다른 용도로 사용할 수 있게 해 줘야 한다. 
// 2. malloc() 함수, 동적 할당으로 계속 받아오기만 하면 
//	  Heap이 꽉 차서 더 이상 할당할 수 있는 메모리가 없는 경우가 발생한다. 
// <== 다 쓴 메모리를 꼬박꼬박 반납을 해 줘야 한다. 
// 
// 만약 ptr이 NULL이라면 free(ptr);을 할 때 아무 일도 일어나지 않는다.
// free(ptr);	// no action occurs when ptr is NULL
// 
// 위 프로그램을 실행해 보면, 결과는 다음과 같다.
// Before free 00D1CE60
// After free 00D1CE60
// 
// free() 함수를 실행한 후에도 메모리 주소, 포인터가 그대로 유지가 된다. 
// free()를 해 줘도 포인터는 별도의 변수이므로, 주소를 계속 가지고 있다. 
// 그러므로, free()를 해 준 후에도,
// ptr = NULL;	// optional
// 이과 같이 동적 할당 메모리에 대한 포인터 변수 ptr은, 
// NULL 값으로 바꿔 주는 것이 여러 가지로 안전하고 편하다. 
// optional이라고 했지만 꼬박꼬박 적어 주는 것이 좋다. 
// free(ptr);을 해 준 후 프로그램이 종료해서 
// 더 이상 ptr 포인터가 사용될 일이 절대 없다면, 
// NULL 값으로 바꿔 줄 필요까지는 없겠다. 
// 그 외의 경우는 ptr = NULL; 포인터에 NULL을 넣어 줘서,
// 이 메모리는 어떠한 동적 할당 메모리도 가리키고 있지 않다는 걸 
// 명확하게 표현해 놓는 것이 좋다. 
// 
// 동적 할당 메모리는 배열처럼 사용할 수 있다. 
// 