#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수의 저장 공간 분류
// 
// 지금까지 변수의 저장 공간 분류에 대해서 공부했다. 
// 함수의 저장 공간에 대해서 살펴 보겠다. 

/*
	Storage Classes and Functions
	- Functions external (by default) or static
	- A function declaration is assumed to be extern
*/

// external과 static이 모두 가능하다. 
// 함수는 처음에 프로그램과 함께 loading이 된다. 
// 메모리에 계속 있다. 
// function pointer로 그 주소를 찍어 볼 수도 있다. 
// 
// 기본적으로 function declaration은 extern이라고 가정되고 있다. 
// 모든 함수의 선언은 extern이다. 
// 아래 함수의 전방 선언은 원래 다음과 같이 extern이 붙어 있다. 
// extern void fun();
// extern void fun_second(); 
// 하지만, 함수는 뻔하기 때문에 extern을 생략할 수 있다.  
// 

int g_int = 123;	// defining declaration
//TODO: try static

// main() 함수에서 사용하기 위해 함수의 prototype만 선언해 준다. 
void fun();			// 다른 함수의 전방 선언이다. 
void fun_second();	// 다른 파일에 있는 함수의 전방 선언이다. 

int main() {
	fun();
	fun_second();

	return 0;
}

void fun() {
	extern int g_int;	// optional

	g_int += 1;
	printf("g_int in fun() %d %p\n", g_int, &g_int);
}

// second.c 파일에 있는 함수 void fun_second(void) 앞에 static을 붙여 주면
// 어떻게 될까?
// unresolved external symbol _fun_second_referenced in function _main
//	<= main() 함수에서 fun_second() 함수를 찾는데 없다. 
// fatal error LNK1120 링킹 에러가 뜬다. 
// second.c에서 함수를 정의할 때 static을 붙여서 scope를 막아 버려서,
// second.c 파일 안에서만 사용할 수 있게 해 놨기 때문이다. 
// 
// 링킹을 할 때, 찾을 수가 없는 것이다. 
// static 키워드가 함수에서도 변수에서와 마찬가지로 동일하게 사용된다. 
// 
// 함수를 변수처럼 제한해 둘 필요가 있을까?
// 모든 함수를 어디에서나 다 쓰면 편하지 않을까?
// static으로 막아 버리는 게 과연 필요할까?
// 
// 우리가 파일을 나눌 때는 모듈이라는 개념으로 나눌 때가 많다. 
// 어떤 기능을 하는 함수들을 모아 놓고, 
// 다른 기능을 하는 함수들을 또 다른 파일에 모아 놓는다. 
//	<= 파일별로 정리를 해 두는 것이다. 
// 
// 만약 second.c 파일에서만 사용되는 함수 tool()이 있다고 가정하면, 
// 즉 이 모듈 밖에서는 tool() 함수가 사용되는 것을 막아 버리고 싶다면, 
// 함수 앞에 static을 붙일 수가 있다. 
// 
// 이렇게 모듈별로 함수를 정리해 나갈 때, static 함수가 사용될 수 있다. 
// static은 pototype 앞에 붙여도 되고, 함수 정의부 앞에 붙여도 된다. 
// <= linking이 되지 않게 막아 버리는 효과가 있다. 
// 
// 함수의 저장 공간 분류에 대해서 살펴 봤다. 