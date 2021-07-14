#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 식별자인 변수는 scope 영역,
// 메모리 공간을 차지하고 있는 객체는 메모리에서의 duration 지속 기간으로 본다.

/*
	Variable scopes (visibility 변수의 가시성)
	- 영역에는 4가지가 있다. 
	  block, function, function prototype, file.
*/

// 여기에서는 file scope에 대해서 살펴보자.

int g_i = 123;		// global variable, file scope를 갖는다. 
int g_j;			// global variable, 초기화를 안 했다. 

void func1() {
	g_i++;			// usese g_i
}

void func2() {
	g_i += 2;		// uses g_i

	// local = 456;	// Error, main() 함수의 영역에서만 선언되었다. 
					// func2()에서는 볼 수가 없다. 
}

int main() {
	int local = 1234;

	func1();
	func2();

	printf("%d\n", g_i);	// uses g_i
	printf("%d\n", g_j);	// Not initialized? Warning도 안 뜬다. 
							// BSS segment에서 한꺼번에 0으로 초기화한다. 
	printf("%d\n", local);
	
	//126
	//0			<= 컴퓨터가 0으로 초기화를 해줬다는 것을 알 수 있다. 
	//1234

	return 0;
}

//int g_i = 123;		// global variable, file scope를 갖는다. 
//int g_j;
// 위의 것들이 왜 전역변수 global variable이라고 불리는지는 
// linkage하고 같이 봐야 한다. 
