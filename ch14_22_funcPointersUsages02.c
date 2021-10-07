#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>	// toupper(), tolower()

// Function Pointers, 함수 포인터의 사용 방법
//
// 함수 포인터가 프로그래밍을 얼마나 유연하게 만드는지 살펴 보겠다.

void ToUpper(char* str) {
	while (*str) {
		*str = toupper(*str);	// ctype.h에 들어 있는 함수 toupper()
		str++;
	}
}

void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);	// ctype.h에 들어 있는 함수 lower()
		str++;
	}
}

// 공통 패턴을 활용해서 위 ToUpper() 함수와 ToLower() 함수를 합친다. 
void UpdateString(char* str, int(*pf)(int)) {
	while (*str) {
		*str = (*pf)(*str);
		str++;
	}
}

int main() {

	char str[] = "Hello, World!";

	void (*pf)(char*);

	pf = ToUpper;	// Name of a function is a pointer
	// pf = &ToUpper;		// Acceptable
	// pf = ToUpper(str);	//Not acceptable in C

	printf("String literal %lld\n", (long long)("Hello, World!"));
	printf("Function pointer %lld\n", (long long)ToUpper);
	printf("Variable %lld\n", (long long)str);

	(*pf)(str);
	//pf(str);	//K&R X, ANSI OK

	printf("ToUpper %s\n", str);

	pf = ToLower;

	//(*pf)(str);
	pf(str);

	printf("ToLower %s\n", str);
	printf("\n");

	/*
		passing function pointers to functions
	*/

	UpdateString(str, toupper);

	printf("ToUpper %s\n", str);

	UpdateString(str, tolower);

	printf("ToLower %s\n", str);

	//Note: __cdecl is function calling convention

	return 0;
}

//
// 공통 패턴을 활용해서 합친다. 
	/*
	void UpdateString(char* str, int(*pf)(int)) {
	 <= char* str는 공통 parameters이다. 
	    int(*pf)(int) parameter가 하나 추가되었다. 
		<= UpdateString()에 사용될 함수 자체를 parameter로 받고 있다. 
		   포인터를 통해서 기능을 수행할 함수 자체를 parameter로 받고 있고, 
		   그 *pf를 통해서 뭔가를 실행시킨다는 의미이다. <= *str = (*pf)(*str);
     
	 <= 다른 것은 toupper(), tolower() 함수만 다르다.
	 
		while (*str) {
			*str = (*pf)(*str);
			 <= 실행시킬 함수를 parameter int(*pf)(int)로 받아와서
			    두 개의 함수를 합친다. 
			str++;
		}
	}
	*/
//
// 
	/*
		//	passing function pointers to functions	

	UpdateString(str, toupper);
	 <= UpdateString()이라는 함수를 호출하는데, 
	    argument로 문자열 string str뿐만 아니라, 
		함수의 주소 toupper도 인수로 넣어서 UpdateString() 함수를 호출한다. 
		toupper를 넣고 실행을 시키고, 결과를 본다. 

	printf("ToUpper %s\n", str);

	UpdateString(str, tolower);
	 <= tolower 함수의 주소를 인수로 넣고 실행시킨 후 결과를 본다. 

	printf("ToLower %s\n", str);

	//Note: __cdecl is function calling convention
	*/
// <= 실행해 보면 UpdateString() 함수를 통해서 대문자와 소문자가 제대로 출력이 된다. 
// 
// 마치 함수들을 조립해서 사용하는 느낌이 난다. 
// 함수 포인터 의 중요한 용법 중 하나이다. 
// 
// Note: __cdecl is function calling convention
// 함수 포인터를 선언할 때 __cdecl 이 부분은 무시를 하고 함수 포인터를 선언해 왔다. 
// <= 이것을 함수 호출 규약이라고 한다. 
// 나중에 윈도우즈 API를 공부할 때, 자세하게 공부하게 될 것이다. 
// __cdecl은 없어도 컴파일러가 내부적으로 컴파일 되도록 처리를 해 준다. 
// 
// void UpdateString(char* str, int(*pf)(int)) 함수의 
// 인수는 int(*pf)(int), int (*pf)(int) 두 가지 모두 되는데, 
// 
// int (__cdecl *pf)(int) 처럼 __cdecl을 넣어 줘도 똑같이 작동한다. 
// 기본 문법에서는 __cdecl까지 사용하지 않아도 된다. 
// 
// 함수 포인터의 기본적인 사용 방법에 대해서 살펴 봤다. 