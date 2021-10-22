#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 비트 연산자와 그 외의 멋진 연산자

int main() {

	// 형변환 연산자
	// 피연산자를 한 개 취하는 연산자이다.
	// 피연산자의 형태를 바꿔 준다. 변환시킨다.

	{
		int a = 10;
		int res = a / 3;		// 4bytes
		double res2 = a / 3.0;	// 8bytes

		printf("%d %f\n", res, res2);
	}
	printf("\n");

	// <= a는 정수 4바이트, 3.0은 실수 8바이트이다. 
	//    이런 경우에는 연산을 할 수 없다. 
	//    그래서 피연산자의 형태를 맞춰 주는 작업을 해야 한다. 
	// <= a가 실수값으로 바뀐다. 컴파일러가 자동으로 바꿔 준다.
	//    그렇다고 a가 8바이트 double 형으로 바뀌는 것은 아니다. 
	//    변수 안에 있는 값이 바뀐다는 것이지, 변수의 형태가 바뀌는 것은 아니다. 
	//    a에서 값을 꺼내와서 3.0이랑 연산하기 직전에 실수로 바꿔 주는 것이다. 
	// 피연산자의 형태가 다를 경우에 컴파일러가 자동으로 형태를 바꿔 주는 것을, 
	// <= 자동형 변환, 암시적인 형변환, 묵시적인 형변환이라고 한다. 

	// 정수 3과 실수 3.0은 엄청난 차이가 있다. 크기도 다르고 비트열도 다르다.

	// 졸업생 취업률: 졸업생 100명, 취업한 학생 90명	
	{
		int grad = 100, empl = 90;
		double res;
		res = empl / grad * 100;

		printf("졸업생 %d\n취업자 수 %d\n취업률: %.1f\n", grad, empl, res);
		// 0.000000 이 출력된다. int / int = int이기 때문이다.
	}
	printf("\n");

	// res = empl / grad * 100; 는 취업률이 0 아니면 100이다. <= 문제가 생긴다. 
	// grad와 empl 둘 중 하나는 실수라야 제대로 된 계산이 된다. 
	// 
	// 하지만 grad와 empl은 정수형으로 충분하다. 
	// 취업률 연산을 위해서 자료형까지 바꾸고 싶지는 않다.
	// <= 취업률을 구하는 이 연산에서만 double 형으로 바뀌었으면 좋겠다. 
	// 
	// int grad = 100, empl = 90; 이 변수의 형태는 프로그램이 끝날 때까지 바뀌지 않는다. 
	// 단지 취업률 계산할 때만 잠깐 실수로 바뀌었으면 좋겠다는 것이다. 
	// <= 이럴 때 형변환 연산자를 쓴다. 
	// 
	// res = (double)empl <= 이렇게 바꾸고자 하는 자료형을 괄호 안에 넣어 주고,
	//                       피연산자는 바로 옆에 써 준다. 
	{
		int grad = 100, empl = 90;
		double res;
		res = (double)empl / grad * 100;
		// <= 이렇게 잠깐 형변환해 준다. grad도 실수 100.0으로 자동 변환된다. 
		//    하나만 바꿔 주면 나머지는 컴파일러가 알아서 바꿔 준다. 
		// 이런 식으로 해 줘야 제대로 연산이 된다. 

		printf("%.1f\n", res);	// 90.000000 이 출력된다. int / int = int이기 때문이다.

		int res2 = res;	// 소숫점 이하는 버리겠다. double 값을 int 형 변수에 넣는다. Warning

		printf("%d\n", res2);	// 90, 자동 형변환이 됐다. 

		// 하지만 int res2 = res; 이런 경우 컴파일러가 실수한 게 아닌지 물을 수도 있고, 
		// 다른 사람이 봤을 때도 실수를 한 것인지 헤깔릴 수가 있다. 
		// warning C4244: 'initializing': conversion from 'double' to 'int', possible loss of data
		// 컴파일러가 이런 경고를 보낸다. 

		int res3;
		res3 = (int)res;		// 이렇게 명시적으로 형변환 연산자 (int)를 넣어 주면 명확해진다.
		printf("(int)res = %d\n", res3);
	}
	printf("\n");

	// 위에서 형변환한 경우를 보면,
	// empl 변수는 원래의 int 형 변수로 사용하는 것 맞다. 
	// 단지 어떤 상황의 요구에 따라 잠시 다른 자료형 (double)empl으로 사용되는 것이다. 
	// <= empl 변수 자체가 double로 변하는 것은 아니다. 여전히 int 형이다. 
	// 
	// 소숫점 이하는 버리고 싶을 때는 double 형 값을 int 형 변수에 넣어 줄 수 있다. 
	// int res2 = res;	
	// <= 무조건 왼쪽에 있는 자료형에 맞춰서 오른쪽 값의 자료형이 바뀐다. 
	//    이렇게 해 주니 Warning이 뜬다. 
	// 
	// res2 = (int)res; <= 이런 식으로 명확하게 형변환을 표시해 주면, 
	//                     오타나 실수한 것이 아님을 명확하게 표시할 수 있다.
	// 
	// (char)피연산자: char 형으로 변환
	// (int*)피연산자: 포인터 형으로 변환
	// 구조체 형으로 변환할 수도 있다. 


	// sizeof 연산자
	// 피연산자의 크기를 바이트 단위로 연산해 준다. 
	// 연산자가 sizeof 이렇게 생겼다. 
	// 아래 출력 예시는 내가 해 본 것이다. 
	{
		int a = 10;
		double b = 3.4;
		char c = 'a';

		int size = sizeof a;
		printf("int 형 변수 a의 크기: %d\n", size);	// 4, 
													// 컴파일러에 따라서 2가 출력될 수도 있다.
		int size2 = sizeof b;
		printf("double 형 변수 b의 크기: %d\n", size2);	// 8	

		int size3 = sizeof c;
		printf("char 형 변수 c의 크기: %d\n", size3);		// 1	

		int size4 = sizeof a;
		printf("정수 형 상수 10의 크기: %d\n", size4);		// 4

		int size5 = sizeof 3.5;
		printf("실수 형 상수 3.5의 크기: %d\n", size5);	// 8, 실수이므로			

		int size6 = sizeof(3.5 + 10);
		printf("size of (3.5 + 10) = %d\n", size6);		// 8, 실수이므로

		int size7 = sizeof 3.5 + 10;
		printf("size of 3.5 + 10 = %d\n", size7);		// 18, 8 + 10으로 계산됨.
		// <= sizeof는 단항 연산자 +는 이항 연산자이므로, 단항 연산자의 우선 순위가 높다.

		int size8 = sizeof(int);
		printf("int 자료형의 크기: %d\n", size8);			// 4

		int size9 = sizeof(double);
		printf("double 자료형의 크기: %d\n", size9);		// 8

		int size10 = sizeof(char);
		printf("char 자료형의 크기: %d\n", size10);		// 1
	}
	printf("\n");
	// 
	// int의 size를 구할 수도 있다. 비교의 편의를 위해 위 코딩 예제에 추가해 놨다. 
	{
		// sizeof int <= 오류! 컴파일러가 보면 int 네, 변수 선언해야지 할 수 있다. 
		// sizeof (int) <= 반드시 괄호를 붙여 줘야 한다. sizeof의 피연산자임을 표시하기 위해.
		int size = sizeof(int);
		printf("size of (int) = %d\n\n", size);
	}
	// sizeof a;와 sizeof(a)는 같은 결과가 나온다.
	// 옆에 괄호가 있다고 해서 sizeof()를 함수로 오해할 수 있으나, sizeof는 연산자이다. 
	// 
	// 이렇게 변수나 상수나, 수식이나 자료형에 대한 사이즈를 구할 수 있다. 
	// 배열의 크기도 구할 수 있다. 
	{
		char str[20];

		// 배열의 크기
		int size_str = sizeof str;
		printf("size of char str[20] = %d\n", size_str);	// 20

		// 문자의 크기
		int size = sizeof("A");
		printf("size of \"A\" = %d\n", size);				// 2

	}
	printf("\n");
	// 
	// int size = sizeof("A"); 가 2인 이유는?
	// <= null character를 포함하기 때문이다. 
	// 문자열은 컴파일되고 나면 뒤에 널문자 하나를 붙인다.
	// 
	// 문자열, 포인터, 구조체 등 기타 모든 자료형의 크기가 궁금하다?
	// <= sizeof를 사용하면 크기를 구할 수 있다. 
	// 
	// 복합 대입 연산자
	{
		int a = 10;
		a = a + 1;	// 여기의 =과 + 두 연산자를 하나로 묶어서 +=와 같이 쓸 수 있다. 

		a += 1;		// +=를 복합 연산자라고 한다. 왼쪽의 1은 피연산자이다. 

		printf("a += 1의 값은 %d입니다.\n", a);

		// 다섯 개의 복합 연산자가 있다. 
		// 산출 연산자와 함께 쓴다. 비트 연산자에도 쓴다. 
		// +=, -=, *=, /=, %=

		// 복합 연산자를 사용할 때는, 연산자 우선 순위에 주의해야 한다. 
		int b = 2;
		int c = 5;

		b *= c + 5;	// (c + 5)를 먼저 연산한 후 복합 연산자 *=를 연산한다. 
					// 복합 연산자의 우선 순위는 대입 연산자의 우선 순위와 같다. 
					// 다른 것을 모두 연산한 후 마지막에 대입, 복합 연산자를 수행한다. 

		printf("b *= c + 5의 값은 %d입니다.\n", b);	// 20	
	}
	printf("\n");
	// 
	// 콤마 연산자
	// 나열해 준다. 
	//  , , , , , , <= 왼쪽에서부터 오른쪽으로 차례대로 연산해 준다. 
	// 
	// 여러 개의 문장을 하나의 줄에다가 연산하고 싶을 때, 사용한다.
	{
		int a = 10;
		int b;
		++a, b = a;		// <= 이렇게 comma 연산자로 한 줄에 써 줄 수 있다. 
						// 가장 마지막에 연산한 가장 우측에 있는 피연산자가 최종 연산자가 된다.
						// 하지만 이렇게 콤마로 쭉 나열하면 가독성이 떨어진다. 

		printf("++a, b = a;  %d %d\n", a, b);	// 11 11

		// 가독성을 위해서는 수식을 줄을 달리해서 나눠서 작성하는 것이 더 좋다. 
		++a;
		b = a;
		printf("++a, b = a;  %d %d\n", a, b);	// 12 12 

	}
	printf("\n");
	// 콤마 연산자는 대입 연산자보다 우선 순위가 낮은 유일한 연산자이다. 
	// 
	// 유일한 삼항 연산자인 조건 연산자
	{
		int a = 10, b = 20;
		int max;

		max = (a > b) ? a : b;		// (a > b)를 하나의 피연산식으로 쓴다. 
									// 조건 연산자 ?
									// 피연산자가 (a > b), a, b 세 개가 된다. 
									// 연산자는 ?, : 두 개이다. 
		printf("max = %d\n", max);

		(a > b) ? (max = a) : (max = b); // 위처럼 써 주는 게 보기 좋다 .
		printf("max = %d\n", max);

		// 이렇게 쓸 수도 있다. 
		(a > b) ? printf("max = %d\n", a) : printf("max = %d\n", b);
		// 하지만 아무 함수나 쓸 수 있는 것은 아니다. 
		// 함수가 반환하는 값이 있는 경우에만 쓸 수 있다. 
	}
	printf("\n");


	// 비트 연산자에 대해서 살펴 보자. 
	// 비트 단위로 연산을 수행한다. 
	// 비트 논리 연산자 &, |, ^, ~
	// 비트 이동 연산자 <<, >>
	{
		// 비트 논리 곱 (&) 연산
		int a = 10, b = 6;	// a      1010	<= 참
							// b      0101	<= 참
							// a & b  0000	<= 거짓
							// 
							// if (a & b)	<= 거짓이므로, 실행이 안 된다. 
							// 논리 관계에 사용하면 안 된다. 
							// 비트별 논리 연산자이기 때문이다. 
		// if (a && b)를 if (a & b)로 잘못 써도 컴파일 에러가 나지 않는다. 
		// <= 비트 단위 연산으로 다르게 연산이 된다. 

		printf("(a & b) == %d\n", (a & b));
	}
	{
		// 비트 논리 합 (|) 연산
		int a = 10, b = 6;	// a      1010	<= 참
							// b      0110	<= 참
							// a | b  1110	<= 참	
		printf("(a | b) == %d\n", (a | b));
	}
	{
		// 비트 논리 XOR 연산자, exclusive or
		// 둘이 다를 때만, 1이 된다. 둘이 같을 때는 거짓이 된다. 
		int a = 10, b = 6;	// a      1010	
							// b      0110	
							// a ^ b  1100		
		printf("(a ^ b) == %d\n", (a ^ b));
	}
	{
		// 비트 논리 ~ 연산자
		// 비트 논리 연산자 중 유일한 단항 연산자
		// 1이면 0으로, 0이면 1로 바꾼다. 
		// 비트를 반전시킬 필요가 있을 때 사용한다. 
		int a = 10;	// a      0000 1010			
							// ~a     1111 0101		
		printf("~a == %d\n", (~a));		// -11
	}
	printf("\n");
	// 
	{
		// 비트 이동 연산자
		int a = 10;			// a      0000 1010	
							// a << 1 0001 0100, 왼쪽으로 한 칸 이동
							// 왼쪽으로 1을 이동하면 2를 곱한 것과 같게 된다. 
							// 왼쪽으로 2를 이동하면 4를 곱한 것과 같게 된다.	
							// 왼쪽으로 3를 이동하면 8을 곱한 것과 같게 된다.	

							// 오른쪽으로 1을 이동하면, 맨오른쪽은 양수일 때는 0을 채우고,
							//                                 음수일 때는 1을 채운다.

							// 오른쪽으로 1을 이동하면 2로 나눈 몫이 된다. 
							// 오른쪽으로 2를 이동하면 4로 나눈 몫이 된다. 나머지는 잘려 나간다.

		// <<
		printf("(a << 1) == %d\n", (a << 1));	// 20
		printf("(a << 2) == %d\n", (a << 2));	// 40

		// >>
		printf("(a >> 1) == %d\n", (a >> 1));	// 5
		printf("(a >> 2) == %d\n", (a >> 2));	// 2, 나머지는 잘려 나갔다. 
		printf("\n");

		// 복합 연산자를 사용할 수 있다. 

		{	// <<=
			int a = 10;			// b      0000 1010
			a <<= 1;

			printf("a <<= 1 == %d\n", a);
		}

		{	// >>=
			int a = 10;
			a >>= 1;

			printf("a >>= 1 == %d\n", a);
		}


		{	// &=
			int a = 10, b = 6;
			a &= b;

			printf("a &= b == %d\n", a);
		}

		{	// |=
			int a = 10, b = 6;
			a |= b;

			printf("a |= b == %d\n", a);
		}

		{	// ^=
			int a = 10, b = 6;
			a ^= b;

			printf("a ^= b == %d\n", a);
		}
	}
	// 
	// 대입 연산자의 종류, 총 11개
	{
		int a = 10, b = 6;

		a = b;

		a += b;
		a -= b;
		a *= b;
		a /= b;
		a %= b;

		a &= b;
		a |= b;
		a ^= b;
		a <<= b;
		a >>= b;
	}
	printf("\n");
	//
	// 연산자를 여러 개 같이 사용할 경우에는 우선 순위를 고려해야 한다. 
	// 40여개의 연산자가 우선 순위가 있다. 다 외울 수가 없다. 
	// 
	// 우선 사용하고 싶은 것은 () 괄호로 감싸 준다. 
	// 단항 연산자가 이항 연산자보다 우선 순위가 높다. 
	// 이항 연산자는 삼항 연산자보다 우선 순위가 높다. 
	// 
	// 연산자를 기능에 따라서 다음의 순으로 살펴 봤다. 
	// 우선 순위도 다음과 같은 순서이다. 
	// 산술 연산자 > 비트 연산자 > 논리 연산자 > 관계 연산자 
	// 
	// 산술 연산자 *, /, %, +, - <= ( *, /, % )가 ( + - )보다 우선 순위가 높다. 
	//							 <= ++, --는 단항 연산자이므로 ( *, /, %, +, - )보다 높다.
	//            
	// 논리 연산자 &&, ||, ~ <= 단항 연산자 ~ 가 (&&, ||)보다 우선 순위가 높다. 
	//                         그리고 &&가 ||보다 우선 순위가 높다. 
	// 
	// 관계 연산자 ( >, <, >=, <= )는 ( ==, != )보다 우선 순위가 높다. 
	// 
	// 비트 연산자 <<, >>는 ( >, <, >=, <=, ==, != )보다 우선 순위가 높다. 
	//		      비트 연산자는 우선 순위가 산술 연산자 바로 아래에 있다. 

	// 연산자 우선 순위 예제
	{
		int a = 10, b = 5;
		int res;

		res = a / b * 2;		// 우선 순위가 동일하므로 왼쪽에서부터 차례로 연산
		printf("a / b * 2 = %d\n", res);			// 4

		res = ++a * 3;			// ++가 *보다 우선 순위가 높다. a를 1 증가시킨 후 3을 곱한다.
								// 단항 연산자 > 이항 연산자
		printf("++a * 3 = %d\n", res);				// 33

		res = a > b && a != 5;	// 관계 연산자 > 논리 연산자 
		printf("a > b && a != 5 의 값은 %d\n", res);	// 1

		res = a % 3 == 0;		// a % 3의 값이 0과 같은가?
								// 산술 연산자 > 관계 연산자 
		printf("a % 3 == 0 의 값은 %d\n", res);		// 0
	}

	return 0;
}