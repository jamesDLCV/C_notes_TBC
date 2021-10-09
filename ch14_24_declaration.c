#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Declaration
// 복잡한 선언을 해석하는 요령
// 
// C언어에서 종종 만나게 되는 복잡해 보이는 선언을 어떻게 해석해야 되는지 
// 요령을 살펴 보겠다. 
//
// 앞 강의 typedef에서 복잡해 보이는 선언에 대해서 언급을 했다. 

int temp(int a) {
	return 0;
}

int (*g(int a))(int) {
	return temp;
}
 
int main() {
	/*
		*	indicates a pointer
		()	indicates a function
		[]	indicates an array
	*/

	/* Deciphering Complex Declarations (KNK 18.4)
	   - Always read declarations from the inside out.
	   - When there's a choice, always favor [] and () over *(asterisk).	
	*/

	int* ap[10];	// Identifier ap is an array of pointers

	typedef int* pint;
	pint ap2[10];

	float* fp(float);	// fp is a function that returns a pointer

	typedef float* pfloat;
	pfloat fp2(float);

	void (*pf)(int);
	/*
		void (*pf)(int);
		      1           1. pointer to
			       2      2. function with int argument
	    3                 3. returning void
	*/

	int* (*x[10])(void);
	/*
		int* (*x[10])(void);
		         1				1. array of
		      2                 2. pointers to
			          3         3. functions with no arguments
		4						4. returning pointer to int
	*/

	/* A function can't return an array */

	//int f(int)[];	// Wrong

	/* But it can return a pointer to an array */

	int(*f(int))[];

	/* A function can't return a function */

	// int g(int)(int);		// Wrong

	/* But it can return a pointer to a function */

	int (*g(int))(int);

	/* An array of functions aren't possbile */

	//int a[10](int);		// Wrong

	/* But an array of function pointers are possible */

	int (*x2[10])(int);

	/* Using typedef to simplify declarations */

	typedef int FCN(int);
	typedef FCN* FCN_PTR;
	typedef FCN_PTR FCN_PTR_ARRAY[10];
	FCN_PTR_ARRAY x3;

	/* More examples */

	int board[6][4];	// an array of arrays of int
	int** ptr;

	int* risks[10];		// A 10-element array of pointers to int
	int(*rusk)[10];		// A pointer to an array of 10 ints

	int* off[3][4];		// A 4x3 array of pointers to int
	int(*uff)[3][4];	// a pointer to a 3x4 array of ints
	int(*uof[3])[4];	// a 3-element array of pointers 
	                    // to 4-element arrays of int

	char* fump(int);	// function returning pointer to char
	char (*frump)(int);	// pointer to a function that returns type char
	char (*flump[3])(int);	// array of 3 pointers to functions 
	                        // that return type char

	typedef int arr5[5];
	typedef arr5* p_arr5;
	typedef p_arr5 arrp10[10];

	arr5 togs;
	p_arr5 p2;
	arrp10 arp;

	return 0;
}

//
	/*
	int (*g(int a))(int) {
		return temp;
	}
	*/
// <= 이런 함수를 보면, 직관적으로 느낌이 오지를 않는다. 
//    실무에서는 이런 문법을 잘 사용하지 않는다. 
//    이보다는 typedef를 이용해서 이해하기 쉬운 형태로 바꿔서 코딩하는 것이 일반적이다.
//	  하지만 기본적인 원리는 알아 두는 것이 좋다. 
// 
// 선언을 할 때 복잡하게 느끼는 것이 다음의 세 가지의 조합이다.
// *	indicates a pointer
//  <= 첫 번째는 포인터이다. 포인터를 만들어 주는 기호 * asterisk
// ()	indicates a function
//  <= 두 번째는 괄호이다. 두 가지 의미가 있다. 
//     하나는 수학 계산을 할 때 우선 순위를 표현하기 위해서 묶어 주는 것이고, 
//     또 하나는 함수의 매개변수가 들어가는 공간으로서의 괄호이다.   
// []	indicates an array
//  <= bracket, 대괄호. 배열을 의미한다. 
// 
// Deciphering Complex Declarations (KNK 18.4)
//  <= KNK 18.4장에 보면 두 가지 원칙과 여러 가지 예제가 소개돼 있다.  
// -Always read declarations from the inside out.
//  <= 첫 번째 원칙은 안쪽에서부터 바깥쪽으로 읽어라. 
// - When there's a choice, always favor [] and () over *(asterisk).	
//  <= 두 번째 원칙은 포인터 * asterisk보다 []와 ()가 우선 순위가 높다. 
// 
// 이 두 가지를 이용해서 해석을 한다. 
// 
// int* ap[10];	// Identifier ap is an array of pointers
//  <= 해석을 할 때, 이름(식별자, identifier)를 먼저 찾는다.
//	   이름은 ap이다. 오른쪽에는 *가 있고 왼쪽에는 []이 있다. 
//     []이 *보다 우선 순위가 높다. 
//     그러므로 ap는 배열이다. <= ap[]
//     무슨 배열이냐? <= int에 대한 포인터(int*)의 배열이다. 
//	   그러므로 int* ap[10]은 int pointer 10개짜리 배열이다. 
//  <= 이렇게 보면 조금 복잡할 수 있는데, typedef를 사용하면 이해하기 훨씬 쉽다.   	
// 
// typedef int* pint;
//  <= 이렇게 재정의를 한다.      
// 
// pint ap2[10];
//  <= 그러면 pint가 뭔지는 몰라도 pint 자료형의 10개짜리 배열이라고 이해할 수 있다. 
//     pint가 뭔지 위를 보니까 int에 대한 포인터(int*)라는 것을 알 수 있다. 
//     그러므로 int에 대한 포인터 10개짜리 배열이라는 것을 이해할 수 있다. 
//  <= 이런 식으로 생각하면 훨씬 쉬워진다. 
// 
// 아래에서도 똑같이 적용할 수 있다. 
// float* fp(float);	// fp is a function that returns a pointer
//  <= fp(float)은 함수이다. 
//     fp라는 이름(식별자, 인식자)를 찾는다.
//     왼쪽에는 *가 있고 오른쪽에는 ()가 있다. ()가 *보다 우선 순위가 높다. 
//     매개변수로 float 하나가 들어오는 함수 fp이다. 
//     그 함수의 반환값이 float이다.       
// 
// 이것도 아래처럼 typedef로 바꿔 놓고 보면 훨씬 이해하기가 쉽다. 
// typedef float* pfloat;
// pfloat fp2(float);
// 
// void (*pf)(int);
//  <= 이름을 찾는다. 이름은 pf이다. 
//     이름 앞에 *이 붙어 있고 *pf는 괄호로 감싸져 있다. 
//     (*pf)는 포인터이다. 무엇인가에 대한 포인터인가?
//     오른쪽에 괄호 int, (int)가 있다. 
//     즉 정수형 하나를 매개변수로 갖는 함수라는 뜻이다. 
//     그리고 반환값은 void이다. 
//  <= 매개변수는 정수형(int)이고 반환 자료형은 void인 함수에 대한 포인터 (*pf)이다. 
//     
// 아래 것은 조금 더 복잡해 보인다. 
// int* (*x[10])(void);
//  <= 먼저 이름을 찾는다. 이름은 x이다. 
//     왼쪽 []이 오른쪽 *보다 우선 순위가 높으므로, 
//     x는 일단 x[] array이다. 
//     무엇의 array인가? <= 포인터에 대한 array이다. 
//     그러면 이 포인터가 무엇에 대한 포인터인지 알아야 한다. 
//      <= 해석을 할 때는 안에서부터 밖으로 나오면서 해석을 하라. 
//     (*x[10])의 밖으로 나와 보면, 오른쪽에는 *가 있고 왼쪽에는 (void)가 있다. 
//     괄호가 *에 비해 우선 순위가 높다. 
//     괄호 (void)는 매개변수가 없는 함수이다. 
//     반환값은 int의 포인터이다. 
// 
//  <= 결과적으로 x라는 것은, int에 대한 포인터를 반환해 주는 
//     매개변수가 없는 함수에 대한 포인터의 배열이 된다. 
//     
// 함수에 대한 포인터의 배열은 이후 예제를 통해 다시 살펴 본다. 
// 
// 안 되는 것들도 있다. 복잡도가 많이 줄어들게 된다. 
// 
// 함수가 배열을 반환할 수 없다. 기본적으로 안 된다. 
// int f(int)[];	// Wrong <= 이렇게 배열을 반환할 수는 없다. 
// 
// 하지만 배열에 대한 포인터를 반환할 수는 있다. 
// 
// int(*f(int))[]; <= 이런 형태는 가능하다. 앞 강의인 typedef에서 언급했다. 
// 
// 함수가 함수를 리턴할 수는 없다. C언어에서는 안 된다. 
// 함수가 함수를 반환한다는 개념 자체는 C++나 다른 언어에서는 가능한 개념이다. 
// 하지만 내부적으로 구현할 때는 어차피 function pointer로 구현하게 돼 있다. 
// <= C언어에서 안 되는 것이지 다른 언어에서도 안 되는 것은 아니다. 
// 
// int g(int)(int);		// Wrong
//  <= 함수가 함수를 반환하는 것은 막혀 있으므로 이렇게는 사용할 수 없다. 
// 
// 하지만, 함수의 포인터는 리턴할 수 있다. 
// 
// int (*g(int))(int);
// <= 함수에 포인터가 붙어 있다. 
//    해석하는 방법은 앞에서 살펴 본 것과 동일하다. 
// 
// 함수의 배열은 안 된다. 
// 
// int a[10](int);		// Wrong
// <= 함수의 배열이므로 막혀 있다. 
//
// 하지만 함수의 포인터의 배열은 가능하다. 
// 
// int* (*x2[10])(void);
// <= int (*g(int))(int);와 대칭되게 바꿔 보면, 
//    int (*x2[10])(int);이 된다. 
//    <= x2가 배열인데, 포인터의 배열이다. 그럼 무엇에 대한 포인터이냐?
//       매개변수로 int 타입이 하나 들어오고, int 타입 하나를 반환해 주는 
//       함수의 포인터에 대한 배열이 10개이다.  
//
// 다음은 이전 강의 typedef에서 설명한 것과 유사한 내용이다. 
//
// /* Using typedef to simplify declarations */
//
// typedef int FCN(int);
//  <= 함수를 선언한다. 매개변수는 int이고 반환 타입도 int이다. 
// 
// typedef FCN* FCN_PTR;
//  <= 함수에 대한 포인터를 해 준다.  
// 
// typedef FCN_PTR FCN_PTR_ARRAY[10];
//  <= 다음에 그 함수 FCN_PTR에 대한 포인터가 10개 있다. 
// FCN_PTR_ARRAY x3;
//  <= 다음에 FCN_PTR으로 x3를 선언했다. 
//  <= x2와 x3는 타입이 똑같다.
//     둘 다 int가 들어오고 int를 반환하는 함수에 대한 포인터 10개를 
//     배열로 저장할 수 있는 자료형이 된다.  
// 
// 이런 식으로 typedef로 이해하기 쉽게 선언을 할 수 있다. 
//
// 이 외에도 여러 가지 예제들이 있다. 
// /* More examples */
// 이 예제들은 위의 설명을 이해했다면 이해할 수 있으므로 직접 해석해 보기 바란다. 
// 
// 복잡한 선언을 해석하는 방법에 대해서 살펴 봤다. 
// 실무에서는 이렇게 복잡한 선언을 가지고 머리 싸매고 고민할 일은 많지 않을 것이다. 
// typedef를 이용해서 이해하기 쉬운 형태로 정리하는 것이 훨씬 더 좋은 방법이다. 
// 다만 원리는 한 번쯤 봐 두면 도움이 될 것이다. 