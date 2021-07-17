#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// duration에 대해서 살펴본다.
// duration은, 메모리를 실제로 가지고 있는 것의 지속 기간을 의미한다. 

/*
	Storage duration:
	- static storage duration	// 여기에서의 static과 
								// 아래 Note에서의 static은 의미가 다르다.
	(Note: 'static' keyword indicates the linkage type, not the storage duration)
	- automatic storage duration
	- allocated storage duration
	- thread storage duration
*/

// storage duration은 위의 네 가지가 있다. 
// - static storage duration
//		프로그램이 시작이 될 때, 메모리에 자리를 잡고 
//		끝날 때까지 계속 static하게 머문다. 
//      시작할 때부터 끝날 때까지 메모리에 계속 고정적으로 자리를 잡고 있다. 
// 
//		변수 앞에 붙이는 static key word하고는 의미가 조금 다르다. 
//		static key word는 linkage type을 의미하고, 현재 범위를 벗어나지 못하도록
//		고정을 시킨다. Scope가 넓어지지 않도록 막아버린다는 의미이다. 
//		storage duration의 의미와는 다르다. Static storage duration의 static은
//		그냥 영어의 static을 의미한다.  
// 
// - automatic storage duration은 보통 지역변수를 의미한다. 
//		메모리 레이아웃의 Stack에 저장이 된다. 
//		
// - allocated storage duration
//		동적할당과 관련이 있다. 이 부분을 잘 이해해야 한다. 
// 
// - thread storage duration
//		multi threading 개념이다. 
//		기본 강의에서는 다루지 않는다. 후에 보충 강의에서 다루겠다. 
// 


void count() {
	int ct = 0;
	printf("count = %d\n", ct);
	ct++;
}

void static_count() {
	static int ct = 0;	// static을 붙이면, 프로그램이 시작될 때 메모리에 들어오고,
						// 프로그램이 끝날 때까지 계속 무시된다. 
						// 다시 선언하지 않는다. 
	printf("static count = %d\n", ct);
	ct++;
}

int main() {
	count();			// count = 0
	count();			// count = 0
						// 여기에서의 ct는 블럭이 시작될 때 선언이 되면서 생겨났다가
						// 블럭이 끝나면 자동으로 사라진다. 

	static_count();		// static count = 0
	static_count();		// static count = 1
						// 분명이 영역이 끝났으나, ct가 사라지지 않고 남아 있다.
						// 프로그램이 시작할 때 어딘가에 자리를 잡고 있고,
						// 프로그램이 끝날 때 사라진다. 
						// 
						// 여기에서의 ct는 블럭이 시작될 때 선언이 되면서 생격나서
						// 프로그램이 끝날 때까지 사라지지 않고 남아 있다가 
						// 프로그램이 종료될 때 사라진다. 

	return 0;
}

// 변수의 영역, 
// 변수의 연결 상태, 
// 객체의 지속 기간
// 이 세 가지에 대해서 살펴 봤다. 
