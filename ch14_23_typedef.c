#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>	// time()

// typedef
// 자료형에 별명을 붙여 주는 typedef의 여러 가지 용법을 살펴 본다.

int main() {

	/*
		typedef specifier
		- Give symbolic names (or aliases) to types
		- Does not create new types.
	*/

	typedef unsigned char BYTE;	// Note the scope of BYTE

	BYTE x, y[10] = { 0, }, * z = &x;

	{
		typedef unsigned char byte;	// You can use lowercases as well.

		/* Portable data types */

		size_t s = sizeof(byte);//unsigned int (x86), unsigned long long (x64)
		// unsigned int s = sizeof(byte);			// x86
		// unsigned long long s = sizeof(byte);		// x64
	}
	 //byte b;	// typedef definition has a scope

	/*
		This function returns the time since 00:00:00 UTC, January 1, 1970 (Unix timestamp)
	*/

	time_t t = time(NULL);

	printf("%lld\n", t);

	/*
		typedef vs #define
	*/

	typedef char* STRING;

	STRING name = "John Wick", sign = "World";

	/*
	- typedef interpretation is performed by the compiler, not the preprocessor
	- More flexible than #define

	#define STRING char*

	STRING name, sign;
	char* name, sign; // Note the type of sign
	*/

	typedef struct complex {
		float real;
		float imag;
	} COMPLEX;	// typedef struct complex COMPLEX

	typedef struct { double width; double height; } rect;	// No tag
	rect r1 = { 1.1, 2.2 };
	rect r2 = r1;

	printf("%f %f\n", r2.width, r2.height);

	return 0;
}

// typedef의 기본적인 용법은 자료형에 또 다른 이름(별명)을 붙여 주는 것이다. 
// 이름을 바꿔 주고, 다른 이름으로 부르는 것뿐이지, 
// 새로운 자료형을 만들어 주는 것은 아니다. 
// 
// 기본 자료형(int, float, double, char) 외에 기존에 없던 자료형이 
// 마법처럼 새롭게 나타나는 것은 아닌다. 
// 단지 이름을 바꿔서 부를 수 있다는 것이다. 
// 
// typedef unsigned char BYTE;	// Note the scope of BYTE
//  <= 이름을 바꿔 부르고 싶은 자료형 unsigned char을 적어 주고, 
//     바꿔서 부르고 싶은 이름 BYTE를 뒤에 적어 준다. 
//     이름이 하나 더 생긴 것일 뿐이다. 
//     unsigned char를 못 쓰게 된 것은 아니다. 
//     unsigned char도 쓸 수 있고 새로운 이름 BYTE도 쓸 수 있다. 
//     두 가지 다 쓸 수 있다.  
// 
// BYTE x, y[10] = { 0, }, * z = &x;
//  <= 변수를 선언할 수도 있고, 배열을 선언할 수도 있고, 
//     * z = &x 포인터로 선언해서 사용할 수도 있다. 
//  <= BYTE 위에 마우스를 갖다 대면 타입은 unsigned char이라고 뜬다. 
//     이름이 바뀌었을 뿐이지 unsigned char이 다른 자료형으로 작동하는 것은 아니다. 
//     이름을 바꿔 두면 타이핑하는 양이 줄어들 수 있다. 
// 
// 반복해서 긴 자료형의 이름을 사용해야 할 때는, typedef로 짧게 줄여서 쓰는 경우가 있고,
// 또 unsigned char 자체를 문자로 사용하기보다는, 
// BYTE라는 정보의 양을 측정하는 단위로서, 즉 1바이트짜리 자료를 저장할 때 쓰는
// 기본 자료형으로서만 생각하고 싶을 때가 있다. 
// 나중에 네트워킹을 공부할 때, 윈도우즈 API 같은 응용 분야를 공부할 때,  
// 많이 만나게 된다. 
// 
	/*
	{
		typedef unsigned char byte;	// You can use lowercases as well.
		 <= byte를 소문자로 사용해도 된다. 

		//// Portable data types 
		 <= typedef의 중요한 용법 중 하나가 Portable data types이다. 
		    이식성이 높은 데이터 타입이라는 의미이다. 

		예를 들면, 
		size_t s = sizeof(byte);//unsigned int (x86), unsigned long long (x64)
		 <= sizeof(byte)는 x86에서는 unsigned int이지만, 
		    x64에서는 unsigned long long이다. 
		그러면, 
		// unsigned int s = sizeof(byte);			// x86
		   <= x86에서는 이렇게 코딩하고, 
		// unsigned long long s = sizeof(byte);		// x64
		   <= x64에서는 이렇게 코딩해야 하느냐고 생각할 수 있다.  
		x86에서 쓸 때와 x64 쓸 때 다르게 코딩해 줘야 할까?

		이런 번거로움을 없애기 위해서, size_t라는 자료형이 있는 것처럼 
		typedef로 이름을 지어 준다. 

		x64에서 size_t에 마우스를 갖다 대면, 
		typedef unsigned long long size_t라고 뜬다. 

		x86으로 바꾸고 size_t에 마우스를 갖다 대면, 
		typedef unsigned int size_t라고 바뀐다. 

		컴파일하는 환경에 따라서 다른 자료형으로 사용할 수 있다.  

		size_t를 우클릭하고 Go to Defition으로 가서 어떻게 돼 있는지 확인해 보자. 

		// Definitions of common types
		#ifdef _WIN64	<= 전처리기이다.
		                <= 64비트라면 _WIN64 이 조건에 걸려서 여기가 활성화돼 있다.
			typedef unsigned __int64 size_t;
			  <= __int64는 8바이트짜리 정수라는 뜻이다. 
			typedef __int64          ptrdiff_t;
			typedef __int64          intptr_t;
		#else			<= 64비트에서는 비활성화돼 있다. 
			typedef unsigned int     size_t;
			typedef int              ptrdiff_t;
			typedef int              intptr_t;
		#endif
		 <= 전처리기에 대해서는 다른 강좌에서 다룬다. 

		typedef를 이용해서, 
		이식성(portable data type)이 높은 프로그래밍을 할 수 있다.

	}
	//byte b;	// typedef definition has a scope
	*/
// 
// 또 한 가지 문법적 측면을 살펴 보면, 
// typedef도 scope를 가진다. 
//
	/*
	{
		typedef unsigned char byte;
	}

	byte b;	<= 사용할 수 없다. 
	*/
// <= { } 안에 선언된 byte는 { } scope를 벗어나면 사용할 수 없다. 
// 
// portable data type의 다른 예를 살펴 보자. 
	/*
	time_t t = time(NULL);
	 <= 컴퓨터가 지금 몇 시인지를 알려 주는 time() 함수가 있다. 
	    이 함수는 1970년 1월 1일 00:00:00시부터 지금까지 몇 초가 지났는지 
		알려 주는 함수이다. 
		옛날 컴파일러는 32비트로 컴파일을 했고, 요즘은 64비트로 컴파일한다. 
	 
		time_t을 우클릭한 후 Go To Definition으로 가 보면, 

		#ifndef _CRT_NO_TIME_T
		#ifdef _USE_32BIT_TIME_T
			typedef __time32_t time_t;
		#else
			typedef __time64_t time_t;
		#endif
		<= 이렇게 64비트면 64비트 __time64_t를 사용하게 정의돼 있다. 
		   __time64_t를 우클릭하고 Go To Definition으로 한 번 더 가 보면,

		   typedef long                          __time32_t;
		   typedef __int64                       __time64_t;
		   <= 이렇게 typedef를 이용해서 64비트로 사용할 수 있도록 정의돼 있다. 

	이런 식으로 typedef를 이용해서 이식성이 높은 코드를 사용할 수 있도록 도움을 받는다.

	나중에 C++에서는 조금 더 많이 사용하게 된다. 

	printf("%lld\n", t);
	*/
// 
// 그럼 typedef를 사용하는 것과 #define을 사용하는 것은 무슨 차이가 있을까?
// 이름만 교체가 되는 것이고 새로운 기능이 추가되는 것이 아니므로
// 매크로 #define을 이용해서 바꿔 주는 것과 무슨 차이가 있을까?
// 기본적으로는 typedef를 사용하는 것을 권장한다. 
// 둘의 차이를 살펴 보자. 
	/*
		typedef vs #define
	*/
// 
// typedef char* STRING;
//  <= 문자열을 다룰 때 char* (char pointer)를 많이 사용한다. 
//     마치 STRING이라는 자료형이 있는 것처럼 사용한다. // 
// 
// STRING name = "John Wick", sign = "World";
//  <= 이렇게 하면 문자열을 쉽게 사용할 수 있다. 
// 
// typedef와 #define의 가장 큰 차이는 #define은 전처리기 preprocessor이다. 
// 전처리기는 컴파일하기 전에 처리가 된다. 
// 전처리기는 단순히 내부적으로 복사해서 붙여 넣기를 해 주는 형태이다. 
// 
// 하지만 typedef는 컴파일러가 처리를 해 준다. 
// 
// typedef char* STRING;
// STRING name = "John Wick", sign = "World";
// <= typedef를 사용하면, name도 STRING이고 sign도 STRING이다. 
//    STRING은 char*이다. 포인터이다. 
// 
// 전처리기 #define을 사용할 경우에는, 
// #define STRING char*
//  <= typedef에서와 똑같이 #define으로 적어 줬다. 
//     #define에서는 STRING을 먼저 적고 char*을 뒤에 써 준다. 
//  <= 컴파일을 하기 전에 전처리기가 STRING이라는 문자열을 코드에서 발견하면,
//     char*로 바꿔 버린다. 
// 
	/*
	#define STRING char*

	STRING name, sign;
	char* name, sign; // Note the type of sign
	*/
//
// STRING name, sign;
//  <= 이렇게 코딩했다고 가정해 보자. 
//     그러면 컴파일러 전에 작동하는 전처리기가 STRING을 char*로 바꿔 버린다. 
//     
// char* name, sign; // Note the type of sign
//  <= 바뀌면 이렇게 된다. 
//     그러면 문법상 sign은 포인터가 아니다. name만 포인터이다. 
//     둘 다 포인터로 해 주고 싶다면, 
//     <= char* name, *sign; 이렇게 해야 한다. 
//  <= 전처리기를 사용했다면, name은 포인터지만 sign은 포인터가 아니다. 
//     큰 문제가 발생할 수 있다. 
// 
// 이는 전처리기를 사용했을 때의 대표적인 사례를 하나 소개한 것이다. 
// 대부분 typedef를 사용하는 것을 선호한다. 
// 
// 강의 초반에 COMPLEX라는 자료형에 대해서 소개한 적이 있다. 
// 
	/*
	typedef struct complex {
		float real;		<= real number
		float imag;		<= imaginary number
	} COMPLEX;	// typedef struct complex COMPLEX
	 <= COMPLEX라는 자료형이 표준에 들어오기 전에는, 수학하는 프로그래머들이
	    이런 식으로 구조체를 만들어서 사용하는 것이 일반적이었다. 
		아직도 이렇게 직접 만들어서 사용하는 사람들이 많이 있다. 
	 <= real, imag 두 가지 멤버를 갖는 구조체의 이름이 complex이다. 
	    complex를 어떤 자료형의 이름인 것처럼 사용하기 위해서 
		대문자 COMPLEX로 typedef를 해 주고 있는 것이다. 
	 <= typedef struct complex COMPLEX 이렇게 써 줘야 하는 코드가 한 줄 줄어든다.
	    이런 문법은 앞에서 구조체 설명할 때 다뤘다. 
		typedef를 구조체와 함께 사용할 때는 이렇게 사용할 수 있다. 
	 <= struct라는 키워드 없이 보다 편리하게 사용할 수 있다. 

	typedef struct { double width; double height; } rect;	// No tag
	rect r1 = { 1.1, 2.2 };
	rect r2 = r1;

	printf("%f %f\n", r2.width, r2.height);
	*/
// 
// 보다 복잡한 선언을 이해할 때, typedef를 어떻게 이해할 수 있는지
// 한 가지 더 살펴 보겠다. 