#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Union, 공용체의 원리
// 
// 공용체의 기본적인 문법을 공부할 것이다. 
// 공용체의 원리를 이해하기 위해서 메모리 구조를 살펴 보는 것부터 시작하도록 하겠다.
  
int main() {

	/*
		Union
		- Store different data types in the same memory space
		- Structure vs Union
	*/

	union my_union {
		int i;
		double d;
		char c;
	};

	union my_union uni;

	printf("%zd\n", sizeof(union my_union));
	printf("%lld\n", (long long)&uni);
	printf("%lld %lld %lld\n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);

	union my_union save[10];

	printf("%zd\n", sizeof(save));

	/*
		Union of different types
	*/

	union my_union uni1;

	uni1.c = 'A';
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// A 41 -858993599
	// 0xCCCCCC41 = -858993599

	uni1.i = 0;
	uni1.c = 'A';
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// A 41 65
	// 0xCCCCCC41 = 65

	uni1.d = 1.2;	
	printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);
	// 33 33 33 33 33 33 f3 3f
	// 0x3ff3333333333333 = 1.19999999999999995559107901499E0
	// 0x33333333 = 858993459 (decimal)
	// 0x33 = 51 = '3'

	/*
		Initializing unions
	*/

	union my_union uni2 = uni1;			// Copy another union
	union my_union uni3 = { 10 };		// First element (member) only
	union my_union uni4 = { .c = 'A' };	// Designated initializer
	union my_union uni5 = { .d = 1.23, .i = 100 };	// Do NOT recommend

	printf("%d %f %c\n", uni5.i, uni5.d, uni5.c);

	uni.i = 123;
	uni.d = 1.2;
	uni.c = 'k';

	printf("%d %f %c\n", uni.i, uni.d, uni.c);

	union my_union* pu = &uni;	// Pointer to union
	int x = pu->i;				// -> operator, same as x = fit.digit

	uni.c = 'A';
	double real = 3.14 * uni.d;	// do NOT recommend



	return 0;
}

// 공용체 union은 구조체 struct와 비교되는 경우가 많다. 
// 문법적으로 비슷한 부분이 있다. 
// 
// 서로 다른 자료형을 가진 멤버들을 묶을 수 있다. 
// 
// 공용체와 구조체의 차이점은?
// 구조체는 여러 멤버들이 순서대로 메모리에 따로 자리를 차지하고 있다. 
// 패딩도 들어갈 수 있다. 
//
// 공용체에서는 멤버들이 메모리를 어떻게 차지할까?
// unite 뭘 하나로 모은다는 뜻인가? 
// 메모리를 같이 사용한다는 의미이다. 
// 
	/*
	union my_union {
		int i;
		double d;
		char c;
	};
	*/
// <= int i, double d, char c가 메모리를 같이 사용한다. 
//    이렇게 멤버들이 메모리를 같이 사용하는 것이 union이다. 
//    
//    서로 다른 데이터 타입이 같은 메모리 공간을 사용하도록 해 주는 것이 union이다. 
// 
// union my_union uni;
// <= union variable을 선언하는 것도 구조체 변수를 선언하는 것과 동일하다. 
// 
	/*
	printf("%zd\n", sizeof(union my_union));
	<= union의 size를 출력한다.
	   결괏값은 8이다. 구조체였다면 최소 13이상(패딩이 됐다면 16)이었을 것이다.

	   int i, double d, char c가 메모리를 공유해야 하니까,
	   가장 큰 자료형의 사이즈 double이 배정된 것이다. 
	   적어도 8바이트가 있어야 하는 것이다. 

	printf("%lld\n", (long long)&uni);
	<= union variable 자체의 주소를 출력한다. 
	   결괏값은 1098774477720이다. 
	   cf) 구조체에서는 
	       구조체 변수의 주소와, 공용체 변수의 첫 번째 멤버의 주소가 동일하다. 

	printf("%lld %lld %lld\n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);
	<= 각각 멤버들의 주소를 출력한다. 
	   결괏값은 1098774477720 1098774477720 1098774477720이다.
	   공용체에서는 
	   공용체 변수의 첫 번째 주소와 두 번째 주소와 세 번째 주소가 모두 동일하다. 	   
	   메모리를 공유하는 것이다. 

	union my_union save[10];
	printf("%zd\n", sizeof(save));
	<= 배열을 선언하면, 하나가 8이니까 8 * 10 = 80바이트가 된다. 

	구조체의 배열과 유하하게 공용체의 배열을 사용할 수 있다. 
	*/
// 
	/*
	union my_union uni1;

	uni1.c = 'A';
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// A 41 -858993599
	// 0xCCCCCC41 = -858993599

	uni1.d = 1.2;
	printf("%d %f %d %c\n", uni1.c, uni1.d, (int)uni1.c, uni1.c);
	*/
//  
// 공용체의 원리를 이해하기 위해 메모리를 자세히 들여다 보자. 
// uni1.c = 'A'; 왼쪽에 break point를 찍고 디버거를 돌려 보자. 
// 
// Debug > Windows > Memory > Memory1 
// <= Address가 찍히는 창을 띄운다. 
// 
// visual studio 하단 탭에서 Watch1으로 간다. 
// Watch1에서 &uni1을 검색한다. 
// 주소를 우클릭 copy한다. 
// 
// Memory1 창으로 가서 copy한 주소를 붙여 넣는다. 
// 붙여 넣기를 한 후 주소외의 필요 없는 부분은 삭제한다. 
// 
// cc cc cc cc cc cc cc cc  ????????
// <= &uni1의 값이다. uni1의 주소값인데, 아직 쓰레기값이 들어가 있다. 
// 
// F10을 눌러 다음으로 넘어가 보면, 
// &uni1의 주소에 41이 찍힌다. 
// 
// uni1.c = 'A';의 A에 마우스를 갖다 대 보면, 65가 뜬다.
// <= 65를 16진수로 바꾸면 41이다. 
// 
// printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
//	<= A 41 -858993599 이 출력된다.
//     A는 우리가 의도한 대로 잘 나온다. 
//     정수로 A를 출력해 보면, 41이 나온다.  
//     이 공용체가 사용하는 것은 8바이트이다. 
//     그런데 여기에서 41, 1바이트만 사용하고 있다. 
// 
//	<= 0xCCCCCC41 = -858993599
//     <= 16진수 41CCCCCC인데 순서가 뒤집혀 있다. 
//     <= 이를 십진수로 바꾸면 -858993599가 된다. 
// 
// binary to decimal이라고 구글 검색을 하면, 변환기가 검색된다. 
// 이런 변환기로 16진수 CCCCCC41를 십진수로 변환해 보면 -858993599가 된다. 
// <= 이 부분이 공용체의 특징을 정확하게 보여 주고 있다. 
// 
// F10을 한 번 더 누르면,
// 
// uni1.i = 0;
//	<= 4바이트에 0을 대입했다. 
//     Memory1 창의 값이 00 00 00 00 cc cc cc ~으로 바뀐다. 
// 
// uni1.c = 'A';
//  <= 다시 'A'를 대입한다. 
//     그러면 메모리를 공유하고 있기 때문에, 
//     4바이트의 첫 번째 바이트만 41로 바뀐다. 
//     Memory1 창의 값이 41 00 00 00 cc cc cc ~
// 
// 다시 F10을 누르면,
// 
// printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
//	<= A 41 65
//     이번에는 정수로 출력을 해도 숫자가 65가 나온다. 
//     
//	<= 0x00000041 = 65
//     16진수 00000041을 10진수로 바꾸면 65가 된다. 
// 
// 위에서 사용한 공용체는 8바이트 짜리이다. 
// 
	/*
	uni1.i = 0;		// 정수 4바이트에다가 0을 대입했다. 00000000
	uni1.c = 'A';
	 <= 다시 'A'를 대입한다. 
	    메모리를 공유하고 있기 때문에, 4바이트의 첫 번째 바이트만 41로 바뀐다. 

	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// A 41 65
	  <= 이번에는 정수로 출력을 해도 65가 나온다. 
	// 0x00000041 = 65

	uni1.d = 1.2;
	<= double 값을 하나 넣어 보자. 
	   char도 잘 나오는 값을 고생해서 찾았다. 

	printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);
	// 33 33 33 33 33 33 f3 3f
	  <= 8바이트 공간이 전부 바뀌었다. 
	     실제로 사용하는 인간의 숫자로는 뒤집혀야 한다. 
		 3f f3 33 33 33 33 33 33 

	// 0x3ff3333333333333 = 1.19999999999999995559107901499E0
	  <= 변환기로 십진수로 바꾸면 이렇게 된다. <= 64비트 double?
	      Double(IEEE754 Double precision 64-bit) <= http://binaryconvert.com/
		 내가 변환기로 바꾸니 이런 값이 나오지 않았다. 
		 1.2로 딱 떨어지지 않고 저런 값이 나오는 것은 부동소수에서 설명했다. 

	// 0x33333333 = 858993459 (decimal)
	   <= 메모리를 4바이트만 읽으면 0x33333333이 되고, 
	      32비트 정수로 바꾸면 858993459이 된다. 

	// 0x33 = 51 = '3'
	   <= 858993459의 앞 부분 1바이트(33, 8)만 가져다가 십진수로 바꾸면, 51이 된다. 
	      즉 이 멤버를 1바이트 char 타입으로 읽으면 51이 되고, 
		  아스키 코드에서 51을 찾아 보면 문자 '3'이 나온다. 숫자 3이 아니다. 
		  같은 메모리를 4바이트만 읽으면 32비트 정수 858993459이 된다. 

	<= 실행을 하면 858993459 1.200000 51 3 이 나온다. 
	   상식대로 출력이 된다. 

	   웹서비스로 지수 변환을 해 봐라. 
	*/
//  
//
	/*
		Initializing unions
	*/
//	
//	union my_union uni2 = uni1;			// Copy another union
//	 <= 공용체를 초기화할 때는 다른 공영체를 이용해서 복사하면서 복사 대입 생성을
//		할 수 있다. 카피를 하면서 초기화를 하는 것이다.
//
	// 공용체의 선언을 다시 보자, 
		/*
			union my_union {
				int i;
				double d;
				char c;
			};
		*/
	//  <= 공용체를 선언을 할 때는, 마치 세 가지가 있는 것처럼 선언을 하지만
	// 	   실제로는 메모리를 공유하고 있기 때문에, 한 가지 밖에 안 된다. 
	// 
	// 	   그래서 첫 번째 원소처럼만 초기화를 할 수 있다. 문법이 이렇게 돼 있다. 
	// 
	// union my_union uni3 = { 10, 3.141593 };
	// <= 이렇게 두 개를 초기화해 줄 수 없다. 한 가지만 가능하다.
	//    컴파일러가 경고를 해 준다.
	// 
	// union my_union uni3 = { 10 };
	// <= first element, 하나만 초기화 할 수 있다. 
// 
//	union my_union uni3 = { 10 };		// First element (member) only
//	 <= 구조체와 동일하게 중괄호 {}를 통해서 초기화할 수 있다.
//		element와 member는 혼용을 하기도 한다.
//		구조체에서는 member라는 용어를 더 많이 쓰고,
//		객체지향에서 클래스를 배우게 되면, member라는 용어를 더 많이 사용한다.
//		element는 보다 일반적인 의미이다.
//
//	union my_union uni4 = { .c = 'A' };	// Designated initializer
//	 <= 좀 더 정확하게 할 수 있는 것은 Designated initializer를 사용하는 것이다.
//		구조체에서 사용했는데 공용체에서도 사용할 수 있다.
//
//	union my_union uni5 = { .d = 1.23, .i = 100 };	// Do NOT recommend
//	 <= 구조체인 것처럼 이렇게 Designated initializer를 여러 개 사용할 수 있는데,
//		공용체에서는 절대로 권장을 하지 않는다!!!
//		출력을 해 보면, .i = 100에 맞춰서 결과가 나온다.
//
//	 	프로그래머의 의도가 .d = 1.23를 초기화하려고 하는 것인지
//		.i = 100을 초기화하려고 하는 것인지 또는
//		구조체로 구현을 해야 할 것을 실수로 공영체로 구현한 것인지 등등이
//		헤깔리기 때문에, 이 문법은 사용하지 말기를 바란다.
//
//	printf("%d %f %c\n", uni5.i, uni5.d, uni5.c);
//
//	uni.i = 123;
//	uni.d = 1.2;
//	uni.c = 'k';
//	 <= 각각의 멤버에 값을 대입할 수가 있다. 
//	    하지만 앞선 강의에서 메모리를 찍어 서 살펴 봤 듯이, 
//		uni.c = 'k'로 쓰겠다는 의도인 것이다. 
//
//	printf("%d %f %c\n", uni.i, uni.d, uni.c);
//	<= 출력을 하면, 858993515 1.200000 k 이런 값이 나온다. 
//	   123 1.2 k 이렇게 나오지 않는다. 
//	   맨마지막에 한 k만 제대로 나오고 uni.i와 uni.d는 엉뚱한 값이 나온다. 
//	   1.200000도 내부적으로는 바뀌어 있을 것이다. 
//
//	<= 이렇게 
//		uni.i = 123;
//		uni.d = 1.2;
//		uni.c = 'k';
//		<= 마지막 'k'는 정확하게 나오지만 나머지는 정확도가 떨어진다. 
//
//		   이렇게 사용하려고 공용체를 사용하는 것이다. 
//		   공용체가 쓸모가 있는 부분에 대해서는 다음 강의에서 설명한다. 
//
//		   일단 어떻게 작동하는지 원리 위주로 설명하고 있다.
//
//	union my_union* pu = &uni;	// Pointer to union
//	 <= 포인터 사용하는 문법도 구조체와 비슷하다.	    
//
//	int x = pu->i;				// -> operator, same as x = fit.digit
//	 <= pu의 멤버에 접근할 때, 포인터일 경우는 -> operator를 사용하고, 
//	    변수일 경우는 dot operator를 사용한다.  
//		구조체에서와 똑같다. 
//
//	공용체가 어떻게 보면 유용하고 편리한 문법이지만 실수할 가능성도 크다. 
//	그 실수가 의도적인 건지 진짜 실수인지 구분하기 어려울 수도 있다. 
//
//	uni.c = 'A';
//	 <= 값을 대입할 때는 char 'A'를 대입해 놓고, 
//
//	double real = 3.14 * uni.d;	// do NOT recommend
//	 <= 사용할 때는 double을 사용한다. 
//	    그러면, 프로그램을 다시 보는 입장에서 프로그램의 의도가 뭔지 
//		트릭을 사용하는 건지, 비트 단위로 메모리를 조작하기 위해서 사용하는 건지 
//		또눈 uni.c = 'A' c에 'A'를 대입해 놓고, d로 사용하는 건지 
//		아니면 단순한 실수인지, 구분하기 어려울 수도 있다. 
//
//	<= 이렇게 c에 'A'를 대입해 놓고, uni.d를 사용하는 것은 절대 권장하지 않는다. 
//
// 
// 공용체의 기본적인 문법과 구조체와의 차이, 
// 기본적인 사용법에 대해서 설명했다. 
// 
// 다음 강의에서 공용체를 좀더 쓸모 있게 사용하는 방법에 대해서 다룬다. 