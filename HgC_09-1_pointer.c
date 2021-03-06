#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 09-1. 포인터의 기본 개념
// C언어는 메모리에 접근해서 데이터를 사용할 수 있는 언어이다. 
// 메모리에 접근하는 가장 쉬운 방법은 변수를 사용하는 것이었으나, 
// 여기에서는 메모리의 주소 값을 이용하는 포인터에 대해서 살펴 본다. 

int main() {

	//$ 변수
	// 변수 선언으로 메모리 공간을 확보하고, 그 공간을 데이터를 넣어 놓고 꺼내 쓰는 용도로 사용했다.
	// 변수명은 그 메모리 공간을 식별할 수 있는 이름이다. 

	// 그러나 변수는 블록 {}, 함수 내부로 사용이 제한되어 있다. 
	// 같은 변수명을 사용했다 하더라도 블록이나 함수가 다르면 
	// 별도의 저장 공간을 확보한 전혀 다른 변수로 사용된다. 

	// 포인터는 사용 범위를 벗어난 경우에도 데이터를 공유할 수 있는 방법이다. 

	//$ 메모리의 주소
	// 메모리라는 것은, 데이터를 넣어 놨다가 꺼내 쓰는 공간이다. 
	// 메모리는 그 위치를 식별할 수 있어야 한다. 위치를 식별할 수 없다면 사용할 수 없다. 
	// 
	// 메모리의 위치는 주솟값으로 식별할 수 있다. 
	// 메모리의 위치를 식별하는 주솟값은 바이트 단위로 구분된다. 
	// 
	// 메모리의 주솟값은 0부터 시작하고 바이트 단위로 1씩 증가하므로, 
	// 2바이트 이상의 크기를 갖는 변수는 여러 개의 주솟값에 걸쳐 할당된다. 
	// 
	// int 형 변수 a가 메모리 100번지부터 할당되었다면, 
	// 100번지부터 103번지까지 4바이트에 걸쳐 할당이 된다. 
	// <= 변수 선언 이후에는 4바이트 전체를 a라는 이름으로 사용한다. 
	/*
		변수 a가 할당된 영역
		|****|****|****|****|    |
		100  101  102  103  104  105

		100부터 103까지 4bytes가 할당된다.
	*/
	{
		int a;
		a = 10;
		a = a + 20;
	}
	printf("\n");
	// 이렇게 변수명으로 메모리 공간과 값을 간단하게 사용할 수 있었다. 

	//$ 주소 연산자: &, address of 연산자 
	// 
	// 이제 저장된 공간을 이름(변수명)이 아닌 주소로 사용해 보자. 
	// 주소란 변수가 할당된 메모리 공간의 시작 주소를 의미한다. <= 시작 주소!
	// 
	// 시작 주소를 알면 그 위치부터 변수의 크기만큼 메모리를 사용할 수 있다. 
	// 주소는 주소 연산자 &를 사용해서 구한다. 
	// 
	{
		// 변수의 메모리 주소 확인
		int a;		// 위 블록에 있는 int a;와는 전혀 다른 변수이다. 주소를 찍어 보면 확인 가능.
		double b;   // 변수를 선언하면 각 자료형의 크기만큼 메모리에 저장 공간이 할당된다. 
		char c;

		printf("int 형 변수의 주소: \t%p\n", &a);	// 변수가 메모리의 어디에 할당되었는지 궁금하면?
		printf("int 형 변수의 주소: \t%u\n", &a); // <= 이렇게 주소 연사자 &를 사용해서 찾는다.  
		printf("int 형 변수의 주소: \t%lld\n", &a);	// 주소 연산자는 단항 연산자이며,
													// 변수만을 피연산자로 사용하여 
		printf("double 형 변수의 주소: \t%p\n", &b);	// 주소값을 구한다. 
		printf("double 형 변수의 주소: \t%u\n", &b);
		printf("double 형 변수의 주소: \t%lld\n", &b);

		printf("char 형 변수의 주소: \t%p\n", &c);
		printf("char 형 변수의 주소: \t%u\n", &c);
		printf("char 형 변수의 주소: \t%lld\n", &c);

	}
	// 위 printf() 함수 안의 출력 변환 문자가 맞지 않아서 파란색 물결 표시 경고가 뜬다. 
	// <= 일단 무시한다. 10진수로 출력하기 위해서 출력 변환 문자 %u를 사용했다. 

	/*
		// 주소 연산자 & 사용 방법

		&변수명

	*/
	// &는 단항 연산자, 피연산자로 변수명만을 사용한다. 

	// 변수가 메모리의 어디에서부터 어디까지 할당되었는지 확인하는 방법은?
	// 주소 연산자 &를 사용하여 변수에 할당된 메모리의 시작 주소를 확인하고, 
	// 그 시작 주소에 변수의 자료형 크기를 더하면, 
	// 변수가 어디에서부터 어디까지 할당되었는지 알 수 있다. 
	{
		int a;
		int a1 = &a;
		int a2 = &a + 1;			// &a 주소에서 int 바이트 크기만큼 한 칸 이동한다. 
		int a3 = a2 - a1;
		int a4 = (&a + 1) - &a;		// 이렇게는 주소 연산이 안 된다. 그냥 1이 출력된다.
		int a5 = &a + 2;			// &a 주소에서 int 바이트만큼 두 칸 이동한다.

		printf("\nint a는 %u부터 %u까지 %u바이트가 할당되었다.\n", a1, a2, a3);	// 4bytes 할당
		//printf("(&a + 1) - &a의 값은? %u\n", d);
		printf("\n(&a + 2)의 값은 %u이다. &a의 주소 %u로부터 %u바이트 떨어져 있다.\n", a5, a1, a5 - a1);
	}

	{
		double b;
		int b1 = &b;
		int b2 = &b + 1;			// &b 주소에서 double 바이트 크기만큼 한 칸 이동한다.
		int b3 = b2 - b1;

		printf("\ndouble b는 %u부터 %u까지 %u바이트가 할당되었다.\n", b1, b2, b3);
	}

	{
		char c;
		int c1 = &c;
		int c2 = &c + 1;			// &c 주소에서 char 바이트 크기만큼 한 칸 이동한다.
		int c3 = c2 - c1;

		printf("\nchar c는 %u부터 %u까지 %u바이트가 할당되었다.\n\n", c1, c2, c3);
	}
	// 위에서 int, double, char 자료형 변수가 메모리에 어떻게 할당이 되는지 확인할 수 있다. 

	//$ 메모리 주소의 출력 변환 문자
	// 주소는 보통 16진수로 표기한다. 
	// 따라서 주소를 출력할 때는 전용 변환 문자인 %p를 사용하는 것이 좋다. 
	// %p는 주솟값의 데이터 크기에 따라 자릿수를 맞춰 16진수 대문자로 출력한다.
	//
	// 시스템에서 주솟값 자체를 4바이트로 처리한다면, 
	// 16진수 한 자리는 4비트에 해당하므로 주솟값 10번지는 0000000A와 같이 16진수 8자리로 출력한다.
	// 위에서 주소 출력에 %u를 사용한 것은, 편의상 10진수로 출력을 하고자 한 것이고,
	// 주소는 음수가 없으므로 %u 변환 문자를 사용했다. 

	//$ 포인터와 간접 참조 연산자: * asterisk
	// 
	// 변수에 할당된 메모리 주소를 활용하는 방법을 살펴 보자.
	// 메모리의 주소는, 사용할 때마다 매번 주소 연산을 수행하는 것 보다는 
	// 한 번 구한 주소를 저장해서 사용하는 것이 편리하다. 
	// 
	// 포인터가 바로 변수의 메모리 주소를 저장하는 변수이다. <= !!!!!
	// 따라서 포인터도 변수처럼 선언하고 사용한다. 
	// 다만 선언할 때 변수 앞에 *를 붙여 줘야 한다. 
	{
		int a;			// 일반 변수 선언		
		int* ptr_a;		// 포인터 선언

		ptr_a = &a;		// 포인터에 a의 주소를 대입 <= a의 시작 주소를 저장하는 문장이다
		*ptr_a = 10;	// 포인터로 변수 a에 10을 대입

		printf("포인터로 a 값 출력:\t%d\n", *ptr_a);
		printf("변수명으로 a 값 출력:\t%d\n", a);		// 변수 a 값 출력
		printf("a의 주솟값 출력:\t%u\n\n", ptr_a);
	}
	/*
		{
			// 포인터 선언

			자료형 *변수명;	// 자료형은 주소 위치에 있는 변수의 자료형
							// *는 포인터를 선언할 때 변수명 앞에 붙인다.

		}
	*/
	// 포인터의 자료형은 저장할 주소의 변수의 자료형을 적는다. 
	// int 형 변수의 주소를 저장하면, int를 사용하고,
	// double 형 변수의 주소를 저장하면, double을 사용한다. 
	// 
	// 포인터 변수가 선언되면, 일반 변수와 마찬가지로 메모리에 저장 공간이 할당되고 
	// 그 이후에는 변수명으로 사용할 수 있다. 
	// 
	// ptr_a = &a; <= 포인터 ptr_a에 a의 시작 주소를 저장한다. 
	// 
	// 만약 변수 a가 메모리 100번지부터 103번지까지 할당되었다면, 
	// 주솟값 100이 ptr_a에 저장된다. <= a 변수의 시작 주솟값이 저장된다. 
	// 
	//                          100  101  102  103 
	// |    | 100|    |    |    |****|****|****|****|    |
	//      포인터 ptr_a가        변수 a가  
	//      할당된 영역           할당된 영역
	// 
	// 포인터 ptr_a는 변수 a가 메모리의 어디에 할당되었는지 그 위치를 기억하게 된다. 
	// 
	// 이렇게 포인터가 어떤 변수의 주소를 저장한 경우 '가리킨다'라고 하고 
	// 둘의 관계를 pa -> a 처럼 화살표로 간단히 표현한다. 
	// 
	// x -> y 라고 표현하면, x는 y를 가리킨다고 말할 수 있다. 
	// x는 포인터이며 변수 y의 주소를 저장하고 있다는 뜻이 된다. 
	// 
	// <= 포인터가 어떤 변수의 주소를 저장하면 
	//    '가리킨다'라고 말하고 화살표를 그려서 간단히 표현한다. 
	// 
	// 포인터가 어떤 변수를 가리키면, 포인터로 가리키는 변수를 사용할 수 있다. 
	// 즉 포인터 ptr_a로 변수 a를 사용할 수 있는 것이다. 
	// 
	// 포인터가 가리키는 변수를 사용할 때는, 포인터에 특별한 연산자를 사용한다. 
	// <= 이 연산자를 간접 참조 연산자 * 라고 한다. 
	//    또는 포인터 연산자라고도 한다. 
	//  
	// *ptr_a = 10; <= 이런 식으로 간접 참조 연산자를 사용한다. 
	//                 이것이 간접 참조 연산자를 사용하는 문장이다. 
	// 
	// *ptr_a가 a를 가리키므로(a의 주소를 저장하고 있으므로),
	// *ptr_a에 10을 대입하면, 결국 변수 a에 10을 대입하는 것과 동일하다.  
	// 
	// *ptr_a를 출력하면, 변수 a의 값이 출력된다. <= 동일한 값이 출력된다. 
	// 즉 *ptr_a == a, 동일하다. 
	// 
	// *ptr_a도 변수 a의 쓰임과 마찬가지로, 
	// 대입 연산자의 왼쪽에 올 때는, 
	// ptr_a가 가리키는 변수의 저장 공간 l-value로 사용되고, 
	// 오른쪽에 올 때는 ptr_a가 가리키는 변수의 값 r-value로 사용된다. 
	// 
	// 입력할 때는 주의할 사항이 있다. 
	// scanf() 함수는 입력할 변수가 메모리 어디에 할당되었는지 저장 공간의 위치를 알아야 한다. 
	// 따라서 입력할 변수의 주소를 인수로 준다. 
	// 
	// 포인터 ptr_a를 통해서 변수 a에 입력을 할 때도 마찬가지이다. 
	// *ptr_a는 a와 같다. 그러므로 &a는 &*Ptr_a와 같다. 
	// 
	// 즉, 간접 참조 연산자로 ptr_a가 가리키는 변수를 구하고, 
	// 다시 주소 연산자로 주소를 구한다. 
	// 
	// 그러나 ptr_a가 a의 주소를 저장하고 있으므로 바로 ptr_a를 사용해도 된다.  
	{
		int a;
		int* ptr_a;
		ptr_a = &a;

		printf("변수 a에 대입될 값을 입력하세요: ");
		int input = scanf("%d", &a);

		printf("a == %d\n", a);
		printf("ptr_a == %d\n\n", *ptr_a);

		printf("a의 포인터 ptr_a에 대입될 값을 입력하세요: ");
		int input2 = scanf("%d", ptr_a);

		printf("ptr_a == %d\n", *ptr_a);
		printf("a == %d\n", a);


	}
	// scanf("%d", &a);		<= &a로 변수 a의 저장 공간 찾기
	// 
	// scanf("%d", ptr_a)	<= 포인터 ptr_a로 변수 a의 저장 공간 찾기
	//                         포인터 ptr_a의 값은 &a이다. 
	// 
	// &a의 값이 100이라면, 
	// ptr_a에는 100이 대입된다. 
	// 
	// <= ptr_a는 &a와 동일한 값을 같는다. 

	return 0;
}

// l-value(left value)는 공간으로 쓰일 때, 
// r-value(right value)는 값으로 쓰일 때. 