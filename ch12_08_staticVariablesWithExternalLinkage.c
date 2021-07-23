#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 정적 변수의 외부 연결
// Static variables with External linkage
// 
// 고정적(static)이고 외부 연결인 storage class. 
// static이므로 지속 기간 duration은 고정적이다(프로그램이 시작할 때부터 끝날 때까지).
// 
// 영역 scope가 기본적으로 파일 안이다. 
// 그런데 연결을 통해서 외부에서도 사용이 가능하다. 
// 무엇의 외부냐? 
// 번역 단위 translation unit의 외부이다. 번역 단위는 파일이다. 
// 확장자가 c로 돼 있는 파일이다.  
// 앞서 컴파일러와 링커 강의에서 설명했다. 
// 컴파일러가 컴파일을 할 때는, c 파일 단위로 하게 된다. 따로 따로이다. 
// 
// 우리가 프로그래밍을 할 때에는 여러 개의 파일을 사용한다. 
// header files도 여러 개를 쓰고, c 파일도 여러 개로 나눠서 사용한다. 
// 문서 작성과 비슷하다. 일기를 쓸 때도 일 년치 내용을 하나의 문서 파일에 넣지는 않는다. 
// 하나의 문서 파일에 넣으면 너무 커져서 관리하기가 힘들어진다. 
// 
// 프로그래밍을 할 때에는 여러 개 파일로 사람이 이해하기 쉬운 구조로 만든다.  
// 각각의 파일은 컴파일러가 따로 따로 컴파일을 해서 obj 파일을 만든다. 
// 그 다음, 실행 파일을 만들기 전에 linker가 연결을 해 준다. 
// 무엇을 연결해 주는가?
// external linkage를 갖는 변수들을 연결해 준다. 
// 변수 외에 함수도 연결해 준다. 
// 기본적으로 scope는 파일 안이지만, 외부 연결이 가능하다. 
// 파일 밖에서도 사용할 수 있다. 
// 메모리에서의 위치는 데이터 또는 BSS이다. 
// 선언을 하는 방법은 모든 함수들의 밖이다. <= 전역 변수이다. 
// 
// 코드로 살펴 보자. 
// second.c 파일을 만들었다. 
// 프로젝트 안에 있는 c 파일들을 각각 컴파일해서 obj 파일을 따로 만들고, 
// 이 파일들 사이에 연결시켜 줘야 하는 것들이 있다면, linking을 해서 exe 파일을 만든다. 
// 
// 파일 간에 뭔가 연결을 시켜 준다는 것이 어떤 개념인지 정리해 두자. 
// 

/*
	Static variable with external linkage
	- File scope, external linkage, static storage duration
	- External storage class
	- External variables
*/

int g_int;				// <= file scope 	
						// 하지만 0으로라도 초기화를 해 주는 것을 권장한다. 
// int g_int = 7;

double g_arr[1000];     // 자동으로 0으로 초기화 된다.
						// double g_arr[1000] = { 0.0, };

/*
	Initializing External Variables
*/

int x = 5;				// ok, constant expression
int y = 1 + 2;			// ok, constant expression
size_t z = sizeof(int);	// ok, sizeof is a constant expression
//int x2 = 2 * x;		// not ok, x is a variable

void func() {
	printf("g_int in func() %d %p\n", g_int, &g_int);
	g_int += 10;
}

void fun_sec();

int main() {
	/*
		defining declaration vs. referencing declaration
	*/

	extern int g_int;			// optional
	//extern int g_int =  1024;	// Error in block scope

	// int g_int = 123;			// hides global g_int

	extern double g_arr[];		// optional, size is not necessary

	printf("g_int in main() %d %p\n", g_int, &g_int);
	g_int += 1;

	printf("g_int in main() %d %p\n", g_int, &g_int);
	g_int += 1;

	func();

	//int g_int = 123;			// hides global g_int
								// extern 키워드와 함수 내에서 동시에 사용될 수 없다. 

	printf("g_int after initializing %d %p\n", g_int, &g_int);

	fun_sec();

	return 0;
}

//int g_int; // 이 파일 안에서 이 변수를 사용할 수 있다 <= file scope이다. 
			 // 이 파일의 어떤 함수에서도 이 변수를 사용할 수 있다면 이 변수는 file scope이다.
// 
// external likage를 사용하면 second.c 파일에서도 사용할 수 있다. 
//
// 정의하는 방법을 먼저 살펴 보자. (정의하는 선언이라고 하기도 한다)
// 지역 변수 automatic variable은 stack에 올라가기 때문에,   
// 컴파일러가 초기화를 알아서 해 주게 되면, overhead가 발생한다. 
//	오버헤드(overhead)는 어떤 처리를 하기 위해 들어가는 간접적인 처리 시간 · 메모리 등을 말한다.
// 그러면 프로그래머는 이건 내가 원하는 것이 아니다. 정밀하게 해야 되기 때문에, 
// 자동으로 초기화하지 말아라고 할 수 있다. 
// 
// int g_int; 위 이와 같은 static variable, 프로그램 시작부터 끝까지 계속 있는 변수들은,
// 처음에 한 번만 초기화를 하면 되기 때문에, 위와 같이 초기화를 해 주지 않아도, 
// 컴파일러가 알아서 0으로 초기화를 해 준다. 
// 하지만, 
// 
// int g_int = 0; 이렇게 직접 초기화를 해 주는 것을 권장한다. 
// 
// double g_arr[1000];  // array도 초기화를 안 해 주면 자동으로 0으로 초기화 된다.
						// ouble g_arr[1000] = { 0.0, };
// 
// 지역 변수 local variable 같은 경우는 상황에 따라 다르기는 하지만, 
// 초기화가 안 됐을 때는, 컴파일러가 문제가 있다고 얘기를 하거나 run-time에서 오류가 나거나, 
// 뭔가 불안정한 일이 발생한다. 
// 
// 그러나 위 
// int g_int;
// double g_arr[1000]; <= 이것들은 괜찮다. 
// static variables는 초기화를 안 해 주면, 컴파일러가 알아서 0으로 초기화를 해 준다. 
// 하지만, 프로그래머가 모두 초기화를 해 주는 것이 더 좋다. 
// 
// 초기화를 할 때, 
// int x = 5;		<= constant로 초기화를 하는 것은 ok			
// int y = 1 + 2;	<= constant 결괏값이 나오는 계산식도 ok	
// 하지만,
// int x2 = 2 * x;  <= 변수가 들어가는 계산식으로 초기화를 하는 것은 안 된다. 
// 
// size_t z = sizeof(int);  <= sizeof(int)는 컴파일러가 보고 4bytes로 
//							   숫자로 바꿔서 바로 초기화한다. 
// 컴파일할 때 constant로 결정이 되는 것들이다. 
// 
// int g_int; <= file scope의 변수는, 파일 안의 어떤 함수에서도 사용할 수 있다. 
// 
// main() 함수 안의 
// printf("g_int in main() %d %p\n", g_int, &g_int);
// g_int += 1;
// 에서 g_int를 사용할 수 있다. 
// 또 void func() 함수에서도 사용할 수 있다. 
// 어디서 사용하든 g_int 변수의 주솟값은 동일하다. 
// 
// 프로그래머가 main() 함수 안에 아래와 같이 
// int g_int = 123;			// hides global g_int
// g_int를 다시 선언하고 초기화를 해 주면, 이름이 똑같은 지역 변수로 인해서, 
// file scope의 g_int는 name hiding이 된다. 숨겨진다. 
// 이때 지역 변수 g_int의 주솟값은 file scope g_int의 주솟값과 다르다.
// 
// 이런 name hiding을 방지하기 위해서, 
// referencing declaration 참조적인 선언을 이용한다. 
// 
// extern int g_int;	<= extern이 외부라는 의미이다. 
// 이 scope의 바깥에 g_int가 있다. 이 선언을 적어 놓은 main() 함수의 바깥에 있다. 
// main() 함수 바깥에 있는 g_int를 쓸 것이다. 바깥에서 찾아서 연결시키라는 의미이다. 
// 지금은 같은 file scope에 있기 때문에 linker가 굳이 나서서 연결시킬 필요는 없다. 
// 컴파일러가 봐서 같은 파일에 있는 g_int를 찾아서 사용한다. 
// main() 함수 내에 선언된
// extern int g_int; 을 <= referencing declaration이라고 한다. 
// 
// external int g_int; 가 main() 함수에서 사용될 때, 
// main() 함수 안에 int g_int = 123; 과 같이 지역 변수로 초기화해 줄 수 없다.
// <= Error	C2086 'int g_int': redefinition	
// 같은 scope 내에 이미 선언이 돼 있으므로 똑같은 변수 이름을 또 선언할 수 없다. 
// <= 동일한 식별자를 쓸 수가 없다. 
// extern을 이용해서 scope 내의 중복 선언을 방지할 수 있다. 
// 
// 이름이 똑같은 지역 변수를 만드는 실수를 하지 않는다면, 
// extern 키워드는 사용할 필요가 없다. 
// 하지만 내가 사용하는 식별자가 file scope에 있는 식별자라는 것을 
// 명확하게 하고 싶을 때는, extern int g_int; 와 같이 
// 명시해 주는 것이 좋다. <= extern을 사용하는 것을 추천한다. 
// 
// g_int; <= file scope이거나, 전역 변수이거나, external linkage가 있는 경우는
// 접두어 g_가 있는 변수를 보통 사용한다. 지역 변수에는 g_를 붙이지 않는다. 
// 
// external int g_int; 를 main() 함수에 써 주면, 
// main() 함수 내에서 int g_int = 123; 를 못 하도록 깔끔하게 막아 버린다.
// 
// extern double g_arr[]; 
// <= 배열 같은 경우에는 main() 함수에서 reference declaration할 때, 
// size가 필요 없다. 
// 왜냐하면, size는 이미 위 file scope인 double g_arr[1000]; 정의에서 
// 결정이 됐기 때문이다. 
// 
// 초기화가 되고 메모리 사이즈가 결정이 되고, 
// 초기 값을 갖게 된 메모리가 결정이 되는 것,
// 메모리가 첫 값을 갖게 되는 이러한 것을 definition이라고 한다. 
// 
// extern이 붙어 있는 것은 이러 이러한 것을 가져다 쓸 것이라고 선언만 해 주는 것이다. 
// 
// 이제부터 진정한 external, file scope를 넘어가는 것을 살펴 보자. 
// second.c 파일에 함수 fun_sec()을 만든다. 
// 
// defining declaration vs. referencing declaration
// 이 두 가지가 좀 헤깔릴 수 있다. 
// 
// extern이 붙어 있는 쪽에서는 초기화를 안 하는 것이 덜 헤깔린다. 
// extern이 없는 쪽에서 깔끔하게 초기화를 해 줘라. 
// 
// extern이 없는 다른 파일에서 referencing declaration을 해 주면 된다. 
// <= 다른 파일 어딘가에 있는 변수의 이름을 가져다 쓰는 것이다. 
// 
// 컴파일할 때는 g_int 변수가 어딘가에 있는 것처럼 컴파일을 하고, 
// linking할 때 연결을 시켜라. 
// 그리고 실행할 때, linking된 걸 따라서, 
// 실제로 메모리를 찾아가서, 값을 가져오기도 하고 값을 바꾸기도 한다.  
// <=이렇게 정리를 해 둬라. 
// 
// 고정적으로 메모리를 갖는 정적 변수 중에서 외부 연결을 갖는 경우에 대해서 살펴 봤다. 
//