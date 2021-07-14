#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 식별자인 변수는 scope 영역,
// 메모리 공간을 차지하고 있는 객체는 메모리에서의 duration 지속 기간으로 본다.

/*
	Variable scopes (visibility 변수의 가시성)
	- 영역에는 4가지가 있다.
	  block, function, function prototype, file.
*/

// block, function, function prototype에 대해서 살펴보자.

void f1(int hello, double world);	// to the end of the prototype declaration
									// void f1(int, double);로 해도 된다. 
		// function prototype에서는 type이 중요하지 name이 중요하지는 않다. 
		// 하지만 hello와 world를 써주는 것이 유지, 관리에 용이하다. 
		// 따라서 function prototype에서 hello와 world는 큰 의미가 없다. 
		// function prototype은, 
		// 어떠한 함수가 있는지 알려주는 차례와 같은 역할을 한다. 
		// 관리를 잘해주는 것이 좋다. 
		// 이것이 function prototype scope이다. 
// void vla_param(int n, int m, double ar[n][m]);	// gcc only
//(예외) VLA는 길이를 지정해줘야 하기 때문에 프로토타입에서 식별자를 생략할 수 없다. 

double func_block(double d) {
	double p = 0.0;

	int i;
	for (i = 0; i < 10; ++i) {
	//for (int i = 0; i < 10; ++i) // c99 이후에는 이렇게 사용도 가능하다.
		double q = d * i;
		p *= q;

		if (i == 5)
			goto hello;
	}

// goto문은 사용되지 않으므로 그냥 참고만 한다. 
hello:
	printf("Hello, World");

	return p;
}


void func1() {
	

}

void func2() {
	

}

int main() {
	
	func_block(1.0);

	return 0;
}

void f1(int hello, double world) {

}
