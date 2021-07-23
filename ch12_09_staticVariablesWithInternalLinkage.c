#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 정적 변수의 내부 연결
// static variabes with internal linkage
// 앞 강의에서 살펴 본 static variables with external linkage와 
// 연결 상태 linkage 하나만 다르다. 
// 고정적, 내부 연결은 번역 단위의 내부에서만 사용할 수 있다. 
// 즉 같은 파일 안에서만 볼 수 있고, 사용할 수 있다. 
// 모든 함수 밖에서 static 키워드를 사용한다.
//  
// 프로젝트 내에 파일을 세 개 만들었다.

/*
	Static variable with internal linkage
	- File scope, external linkage, static storage duration
	- Internal storage class
*/

static int g_int = 123;	// defining declaration

void fun();
void fun_second();
void fun_third();

int main() {
	fun();
	fun_second();
	fun_third();

	return 0;
}

void fun() {
	extern int g_int;	// optional
	g_int += 1;
	printf("g_int in fun() \t\t%d %p\n", g_int, &g_int);
}

// 이 파일에서는 
// int g_int = 123;		// defining declaration
// 변수 g_int의 정의를 했다. 
// 
// 다른 파일에서는 
// extern int g_int;	// referencing declaration
// 참조적 정의를 한다. 
// 이렇게 해 주 면 linking을 하는 과정에서, 
// linker가 다른 파일이 컴파일돼서 만들어진 obj 파일에서 g_int를 찾아서, 
// 연결을 시켜 준다. 
// 
// void fun_second(void) 함수에서 main() 함수와 같은 메모리를 공유하게 된다. 
// 같은 변수, 같은 obj를 사용하게 된다. 
// 그러므로 main() 함수의 &g_int와 fun_second(void) 함수의 &g_int와,
// fun_third(void) 함수의 &g_int는 모두 같은 주솟값을 갖는다.  
// 
// g_int를 정의할 때, 
// main() 함수에서는 defining declaration이고, 
// 다른 함수에서는 referencing declaration이다. 
// 
// 하나만 진짜고 나머지는 이런 게 어디 있으니까 이것을 linking 시켜 달라는 것이다.
// extern 키워드를 써서 바깥에 이런 게 있으니까 linking을 시켜 달라. 
// main() 함수에 있는 것을 second.c나 third.c에 있는 것처럼 사용할 수 있게 해 달라.
// 
// g_int의 defining declartion 초기화는 한 곳에서만 해야 한다. 
// main() 함수에서 초기화를 했다면 다른 파일에서는 extern으로 가져다 쓸 수만 있다. 
// 동일한 변수 이름으로 초기화를 다시 할 수는 없다. 
// 만약 second.c 파일에서 초기화를 했다면 
// 다른 파일에서는 같은 변수명으로 초기화를 할 수 없다. 
// <= 앞 강의의 요약이다.
// 
// 하지만, 기본적으로 main() 함수 내의 int g_int = 123;과 같은
// 변수를 전역 변수로 사용하는 것은 권장하지 않는다. 
// 너무 복잡해지기 때문이다. 
// 똑같은 변수를 여기서 사용하고 저기서 바뀌고 하면 debugging을 하거나, 
// 프로그램 유지, 관리가 용이하지 않다. 
// 
// 어떤 경우에는 g_int를 file scope에서만 사용할 수 있도록 강제하는 경우도 있다. 
// 어떻게 하면 다른 파일에서는 사용하지 못하게 막아 버릴까?
// static int g_int = 123; 과 같이 
// 앞에다가 static 키워드를 써서 막아 버리면 된다. 
// 
// static이라는 키워드의 의미는, g_int 변수가 이 scope 안에 고정되도록 강제해 준다.
// 앞서 block scope에 있는 변수 앞에다 static을 붙여서, 
// 메모리에 계속 고정된 상태로 존재하게 하지만, 
// block scope 안에서만 작동하는(사용하는) 경우에 대해서 살펴 봤다. 
// 
// file scope를 갖는 변수 앞에 static를 붙이면, 
// linkage를 만들어 줄 수가 없다. 연결을 시켜 줄 수가 없다. 
// 다른 파일에서 extern 키워드를 사용하더라도 그 변수를 찾을 수 없게 된다. 
// 컴파일해서 linking을 시도하면, error LNK2001: ~ 와 같이 링킹 에러가 뜬다. 
// 
// main() 함수의 g_int에 static을 붙여 주면 (static int g_int = 123;), 
// second.c 파일의 int g_int는 다른 주소값을 갖는 새로운 변수가 된다. 
// third.c 파일에 있는 extern int g_int;는 second.c 파일의 g_int와 
// linking이 된다. 
// 
//g_int in fun()          124 00BEA000
//g_int in fun_second()   1 00BEA584
//g_int in fun_third()    2 00BEA584
// 
// 위 결괏값을 보면, fun_second()와 fun_third()의 g_int 변수의 주솟값이 같다. 
// 
// 만약 second.c의 g_int도 
// static int g_int; 와 같이 static으로 막아 버리면, 
// third.c에서는 extern int g_int;로 referencing declaration을 할 수 없다. 
// 컴파일하면 fatal error LNK1120: ~ 같은 링킹 error가 뜬다. 
// 
// 초기화 값을 안 넣어도 0으로 초기화가 되지만, 초기화 값을 넣어 주는 것을 권장한다.
// <= 초기화를 해 주는 것을 권장한다. 
// 
// 정적 변수의 내부연결을 살펴 봤다. 
//