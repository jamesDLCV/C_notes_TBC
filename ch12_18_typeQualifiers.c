#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// memcpy
#include "ch12_18_header.h"	// constants 불러오기

// Type Qualifiers 자료형 한정자
// const, volatile, restrict
// 
// Qualify라는 뜻은 자격을 부여한다는 의미이다. 
// 자료 한정자라고 보통 번역들을 한다. 

//const double gravity = 9.8;
//const double PI = 3.141592;

int main() {
	/*
		Qualified types
		const, volatile, restrict, _Atomic
	*/

	/*
		const
	*/

	// C99 ideompotent, 타입 한정자를 여러 개 써도 된다. 
	const const const int n = 6;	// <= const int n = 6;과 동일하다.

	typedef const int zip;	// 프로그래머가 zip으로 정의한 것이다.
	const zip q = 8;		// const const int zip

	// const int i;			// NOT initialized!
	// i = 12;				// Error
	// printf("%d\n", i);	// Error

	const int j = 123;  // <= const로 막은 변수는 선언 때 반드시 초기화를 해 줘야 한다.
	const int arr[] = { 1, 2, 3 };

	float f1 = 3.14f, f2 = 1.2f;

	const float* pf1 = &f1;
	//*pf1 = 5.0f;	// Error
	pf1 = &f2;		// Allowed

	float* const pf2 = &f1;

	*pf2 = 6.0f;	// Allowed
	//pf2 = &f2;	// Error

	const float* const pf3 = &f1;
	//*pf3 = 7.0f;	// Error
	//pf3 = &pf2;	// Error

	/*
		Global constants
	*/

	double area_circle = PI * 2.0f * 2.0f; 


	/*
		volatile
		- Do not optimize
		- (ex: hardward clock)
	*/

	volatile int vi = 1;		// volatile location
	volatile int* pvi = &vi;	// pionts to a volatile location

	int i1 = vi;

	// ...

	int i2 = vi;

	/*
		restrict (_restrict in VS)
		- sole initial means of accessing a data object
		- compiler can't check this restriction
	*/

	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* par = ar;

	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar)	exit(1);

	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8;

	restar[0] += 3;
	restar[0] += 5;
	// restar[0] += 8;	// Equalivalent

	free(restar);

	return 0;
}

// typedef const int zip;	// 프로그래머가 zip으로 정의한 것이다.
// const zip q = 8;	<= 결국 const const int zip와 같은 의미가 된다. 
// const const int zip이 컴파일 안 되는 문제를 방지하기 위해서, 
// 한정자를 중복해서 써도 되도록 C99에서 추가가 되었다. 
// 
// const int i;	<= const는 값을 바꿀 수 없기 때문에 
//				   선언할 때 반드시 초기화를 해 줘야 한다.
// 초기화를 안 해 주면, 결국은 사용할 수 없게 된다. 
// 
// const int i;			// NOT initialized!
// i = 12;				// Error, 값을 바꿀 수도 없다. 
// printf("%d\n", i);	// Error, 값을 사용할 수도 없다. 
// 
// 포인터의 const는 문법이 조금 복잡할 수가 있다. 
// 
// float f1 = 3.14f, f2 = 1.2f;
// const float* pf1 = &f1;
// <= pf1 포인터 변수 자체는 다른 값을 가질 수 있다.
//  
// *pf1 = 5.0f;		// Error, <= indirection을 한 다음에는 값을 바꿀 수 없다.
// pf1 = &f2;		// Allowed
// <= 다른 변수의 포인터로 값을 바꿀 수가 있다. 
// 
// 그럼 반대의 경우는?
// float* const pf2 = &f1;	<= 이렇게 const를 붙여 주면, 
// *pf2 = 6.0f;	// Allowed	<= indirection을 한 후에는 값을 바꿀 수 있으나,
// pf2 = &f2;	// Error	<= 포인터 변수 자체는 다른 값을 가질 수 없다. 
// 
// indirection으로도 값을 바꿀 수 없고, 포인터 변수 자체의 값도 못 바꾸게 하려면?
// const float* const pf3 = &f1;	<= 이렇게 const를 두 개 붙이면 된다.
// *pf3 = 7.0f;	// Error
// pf3 = &pf2;	// Error/  
// 
// global const는?
// 첫 번째로 생각할 수 있는 것은, 다음과 같이 전역 변수로 만든 후,
// 다근 file에서 사용할 때는 extern 키워드를 사용한다. 
// const double gravity = 9.8;
// const double PI = 3.141592;
// 
// 하지만, 이렇게 하면 다른 프로그램을 만들 때 번거로워진다. 
// 이걸 또 찾아야 하기 때문이다. 
// 
// 재활용할 수 있는 좋은 방법은, 
// 위와 같은 global const를 c file에 넣지 말고, header file에 넣는 것이다. 
// 
// static const double gravity = 9.8;
// static const double PI = 3.141592;
// <= 헤더 파일에 이 constants를 넣어 놓고, 
// #include "ch12_18_header.h" 이렇게 include해서 쓰면 된다. 
// gravity를 이용해서 이동하게 한다든지, PI를 사용해서 원의 크기를 계산할 때 사용한다. 
// 
// volatile 을 살펴 보자.
// 사전적 의미는 휘발성이다, 날라갈 수 있다. 불안정한 의미를 생각하면 된다. 
// 
// volatile int vi = 1;		// volatile location
// volatile int* pvi = &vi;	// pionts to a volatile location
// int i1 = vi;
// 
// ...						<= 별 다른 작업을 안 했으나, vi의 값이 바뀔 수 있다.
// 
// 어떤 변수 vi를 선언한 후, 이 변수의 값을 이 프로그램이 아닌 다른 프로그램에서
// 바꿀 수 있다. 
// 컴파일러가 모르는 상황에서 이 값이 바뀔 수가 있다고 표기를 해 주는 것이다. 
// 
// 다른 모듈에서 혹은 운영체제에서 변수 vi의 포인터를 가져다가, 
// 예를 들어 시간을 넣어 준다면, 시간이 흘러감에 따라 값이 계속 변하게 된다. 
// 
// vi가 컴파일러가 알 수 없는 이유에 의해서 값이 바뀔 수 있다는 의미이다. 
// 그러므로 결과적으로 컴파일러한테 네가 최적화를 하지 말라는 의미가 된다. 
// 건드리지 마라. 
// 
// int i1 = vi;

// ...			<= 어떠한 작업. 

// int i2 = vi;
// 
// 이러한 경우 컴파일러 입장에서는 최적화를 하기 위해서, 
// 두 번째 vi를 메모리에서 읽어다가 i2에 대입을 해 주는 것이 원칙인데, 
// 컴파일러는 중간에 어떠한 작업이 없다면, 첫 번째 vi의 값이 안 바뀔 것으로 예상하고, 
// vi를 임시 저장 공간에 저장해서 코드를 좀 빠르게 만들어 주려고 최적화할 수 있다. 
// <= cach를 한다. caching. 임시 저장 공간에 잠깐 저장해서 속도를 빠르게 하는 것.
// 
// 그런데 컴파일러가 모르는 상황에서 운영체제가 vi의 값을 강제로 바꿔 버릴 때, 
// caching을 하면 문제가 생긴다.  
// 그러므로 caching을 못 하게, 최적화를 못 하게 막아 버려라! <= volatile
// 결과적으로 최적화를 못 하게 된다. 
// 
// 하드웨어를 다룬다거나 로봇을 만든다거나 기판에서 코딩을 한다거나 imbeded 코딩을 
// 한다면, volatile type을 많이 사용하게 된다. 
// 
// restrict를 살펴 보자.
// 의미는 data object에 접근하는 게 이거 하나뿐이다라는 의미이다. 
// 
// int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
// int* par = ar;
// 이처럼 어떤 array가 있다면 이 array에 대한 포인터를 설정해 줄 수 있다. 
// 
// 그러면,
// 	ar[0] += 3;		<= 이 array를 통해서 값을 바꾸는 것과
// par[0] += 5;		<= 포인터를 통해서 값을 바꾸는 것이 사실은 동일하다. 
// <= 위 둘은 par[0] += 8;와 같다. 
// 컴파일러 입장에서는 이 두 연산을 par[0] += 8;로 최적화를 하고 싶을 수 있다. 
// 
// 포인터 par(ar에 대한 포인터)가 어차피 ar[10]의 첫 번째 주소를 가리키고 있기 때문에,
// ar[0]과 par[0]은 같지만, 
// 컴파일러 입장에서는 이 둘은 다른 이름이다. 
// 그러므로 par[0] += 8;과 같이 최적화를 해 줄 수 없다. 
// 
// int* __restrict restar = (int*)malloc(10 * sizeof(int));
// if (!restar)	exit(1);
// 
// restar[0] += 3;
// restar[0] += 5;
// restar[0] += 8;	// Equalivalent
// 
// 하지만, 이처럼 동적 할당받은 메모리를 __restrict 해 주면, 
// 동적 할당으로 받아온 (int*)malloc(10 * sizeof(int)) 메모리를, 
// 다른 포인터나 뭔가 다른 수단을 이용해서 접근하지 않고, 
// restar를 통해서만 접근하겠다는 의미가 된다. 
// 
// restar[0] += 3;
// restar[0] += 5;
// <= 이 둘은 컴파일러 입장에서는, restar[0] += 8; 이렇게 최적화를 해 줄 수도 있다.
// <= 동적 할당된 메모리에 접근하는 수단은 restar에 접근하는 것 이외에는 없기 때문이다. 
// __restrict restar으로 최적화를 도와줄 수 있다. 
// 
// compiler can't check this restriction
// 주의할 점은, 컴파일러 입장에서는 정말 이 restrict가 지켜지고 있는지 
// 동적 할당받은 메모리에 대해서 포인터가 restar 밖에 없는지, 
// 진짜 restar 밖에 없는지는 체크를 할 수가 없다. 
// 
// 프로그래머가 __restrict 키워드를 보고, 
// 다른 포인터를 통해서는 이것에 접근을 하지 말자고 지켜야만 하는 단점이 있다. 
// restrict는 컴파일러를 도와 주는 것이다. 
// visual studio에서 사용할 때는 키워드 앞에 underscore 두 개를 붙여 줘야 한다. 
// 
// 지금까지 자료형 한정자 const, volatile, restrict에 대해서 살펴 봤다.
// 