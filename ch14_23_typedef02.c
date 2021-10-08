#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	"One good way to synthesize declarations is
	in small steps with typedef, ..."
	- K&R book Chapter 5.12
*/
// <= 복잡한 선언문을 이해를 할 때, typedef로 잘게 쪼개서 이해하면 보다 편하다. 
//	  실제로도 많이 쓰이는 방법이다.
// 
// 복잡한 선언을 어떻게 이해하는지에 대해서는 이어지는 강의에서 좀 더 설명한다. 
// 
// 여기에서는 typedef가 뭔가를 간단하게 만들어 준다. 편리하다 정도로 정리하면 된다. 

/* Complicated Function Declartions */

char char3[3] = { 'A','B', 'C' };

char(*complicated_function1())[3]{ // Function Returns Pointer to Char[3]
	return &char3;	// Returns a pointer to char[3]
}
// <= 어떤 함수가 하나 있다. 함수 선언부가 좀 복잡하다. 
//    이 함수의 기능은 Char[3], char 세 개짜리 array에 대한 포인터를 리턴하는 함수이다.
//    이런 것을 어떻게 읽어 내는지는 다음 강의에서 살펴 볼 것이다. 
// 이번 강의에서는 char(*complicated_function1())[3] 이런 함수를 
// typedef를 사용해서 어떻게 편하게 사용할 수 있는지에 대해서 살펴 본다. 
// <= &char3는 char 세 개짜리 array이다. 
//    return &char3;는 char 세 개짜리 array를 반환하고 있다. 
//    char3의 포인터를 반환해 주는 함수이다. 
// 
// char(*complicated_function1())[3] 이 함수에 대한 포인터 변수를 선언한다고 하면,
// <= char(*(*fptr1)())[3] = complicated_function1; 이렇게 해야 한다. 
//    꽤 복잡하다. 
//	  char(*(*fptr1)())[3]을 어떻게 사용하는지에 대해서는 다음 강의에서 다룬다. 
// 
// 그러나 typedef를 사용하면, 
typedef char(*FRPTC3())[3];	// Function Returns Pointer To Char[3]
typedef char(*(*PTFRPTC3)())[3];

char(*(*fptr1)())[3] = complicated_function1;

FRPTC3* fptr2 = complicated_function1;
// <= 이렇게
PTFRPTC3 fptr3 = complicated_function1;
// <= 또는 이렇게 간결하게 사용할 수 있다. 

// char(*(*fptr1)())[3] = complicated_function1;보다
// FRPTC3* fptr2 = complicated_function1; 혹은
// PTFRPTC3 fptr3 = complicated_function1;이 훨씬 간결하다. 
//
// typedef를 사용하면 좋다. 구체적인 용법은 다음 강좌에서 살펴 본다. 
// 
// 여기에서 더 간결해질 수 있다. 
// char(*complicated_function1())[3] 이 함수 자체가 하는 기능이
// 세 개짜리 char 타입 array의 포인터를 리턴해 주는 함수이다. 
// 그래서 

/* Use typedef to make declarations simpler */

typedef char c3[3];
// <= char의 세 개짜리 배열을 c3라는 이름의 자료형으로 선언해 주는 것이다. 
//    [3]가 왜 뒤에 붙어 있나? 용법이 그렇게 돼 있고 다음 강의에서 자세히 다룬다. 
// <= c3라는 자료형이 char 세 개이다. 세 개인 것처럼 붙어 있다. 
// 
// 그러면 위에 있던 
// char(*complicated_function1())[3] 이 함수가 
// 아래와 같이 줄어든다.  

c3* complicated_function2() {
	return &char3;	// Return a pointer to char[3]
}
// <= 이렇게 사용하면 매우 직관적이다. 
//    함수 이름 있고, 매개변수는 현재 없다.
//    반환 자료형이 c3의 포인터이다. 
// 훨씬 이해하기 쉬워진다. 
// 실제로 사용할 때도 훨씬 편하다. 

int main() {
	char(*ret_val)[3] = fptr1();

	printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);

	c3* my_c3 = fptr2();
	// <= char(*ret_val)[3] = fptr1();와 동일한 기능을 하지만, 
	// 보다 매우 직관적이다. 
	// c3라는 어떤 자료형의 포인터이다. 
	// c3를 찾아서 위로 올라가 보면, typedef char c3[3];
	// char 세 개의 array인 것을 알 수 있다. 
	// 이렇게 읽어 들이면 이해하기 훨씬 쉽다. 
	// 
	printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]);
	//<= printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);과
	//	 동일하게 작동한다. 

	return 0;
}

// 실행을 해 보면, 
// A B C
// A B C
// <= 동일하게 출력되는 것을 확인할 수 있다. 
// 
// typedef의 여러 가지 용법을 살펴 봤다. 