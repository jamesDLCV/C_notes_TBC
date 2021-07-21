#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 블록 영역의 static 정적 변수 
// 고정적이면서 블록 scope를 갖는 변수를 사용할 수 있다. 
// <= storage class 분류 표의 다섯 번째 static with no linkage 분류 영역. 
// 
// 고정적이라는 말은 프로그램의 시작부터 끝까지 메모리에 계속 자리를 잡고 있다는 뜻이다. 
// 전역 변수처럼 사용할 수 있다고 생각할 수 있다. 
// 하지만 static with no linkage 같은 경우는 블록 안에서만 사용할 수 있다. 
// 이 경우 메모리의 위치가 데이터 또는 BSS에 있고 지속 기간도 고정적이지만, 
// Linkage는 없다. 
// 하지만 duration이 고정적이므로, 포인터를 사용해서 간접적으로 접근해서 사용할 수 있다. 
// 다만, 블록 안에서 선언해서 사용하는 static variable인데, 
// 굳이 블록 밖에서 사용하고 싶다면, 이 것을 사용할 필요가 없다. 
// 그냥 global variable로 선언해서 사용하면 된다. 
// 
// 코드를 보면 생각보다 간단하고 쓸모가 많다. 
//  

void count() {
	int ct = 0;	// <= 이 블록을 벗어나면 접근할 수 없다. 스택에서 빠져나가 버린다.
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//TODO: return &ct;
}

void static_count() {
	static int ct = 0;	// initialized only once! 초기화가 한 번만 된다. 
					
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//TODO: return &ct;
}

void counter_caller() {
	count();
}

void static_counter_caller() {
	static_count();
}

int main() {
	count();			// 0 7338816
	count();			// 0 7338816 
	count();			// 0 7338816
	counter_caller();	// 0 7338604 <= count() 함수를 호출하는 다른 함수이다.
							   	  // <= 새로운 메모리가 배정됐다.  

	static_count();				// 0 1220920
	static_count();				// 1 1220920
	static_count();				// 2 1220920
	static_counter_caller();	// 3 1220920 <= static_count() 함수를 호출하는 함수
										  // <= 이렇게 해도 메모리 위치가 똑같다. 
	// static과 non-static은 메모리 주소를 보건대, 좀 멀리 떨어져 있다. 

	return 0;
}

int func(static int i) // Warning (Error in GCC)
{

}
// (63,22): warning C4042: 'i': has bad storage class

//int ct = 0;	// <= stack에 위치한다. 
// 
//static int ct = 0;	// initialized only once! 초기화가 한 번만 된다. 
						// int ct = 0;는 수시로 초기화가 가능하다. <= 큰 차이점이다. 
						// 정적 메모리에 있으므로 당연히 한 번만 초기화되는 것이다. 
						// stack이 아닌 DATA이나 BSS 같은 영역에 저장된다. 
						// 프로그램이 끝날 때까지 고정적으로 계속 유지되는, 
						// static하게 유지되는 영역에 저장된다. 
//
// static int ct = 0; 과
// static int ct;
// ct = 0; 은 문법적으로 많이 다르다. 
// 
// int ct = 0; 과
// int ct;
// ct = 0; 은 완전히 동일하다.
// 
// static int ct = 0;
// ct = 0; <= 이것은 그냥 대입하는 형태다. 초기화가 아니다. 
// 
// int ct = 0;은 스택에 올라올 때마다 계속 초기화가 된다. 
// 블록을 벗어나면 스택에서 빠져나갔다가 다시 호출이 되면 다시 초기화가 된다. 
// 
// static int ct = 0; 은 정적 메모리에 오므로, 초기화가 한 번만 된다. 
// 
// int func(static int i) // Warning in Visual studio (Error in GCC)
// 함수의 parameter로 static을 사용할 수 없다. 
// 
// 함수가 실행될 때는 새로운 statck frame이 배정된다. 
// 그러므로 parameter 변수는 함수가 실행될 때 메모리를 배정받는 구조이다. 
// stack frame 안에 자기 메모리를 갖는 구조로 돼 있다. 
// 그런데, parameter 앞에 static을 붙이면, parameter 변수를 static한 메모리 공간에 
// 집어 넣겠다는 뜻이 된다. <= 뭔가 안 맞는다. 
// 
// 만약 이런 식으로 쓰고 싶다면, 전역 변수를 쓰든가 다른 방법을 사용해야 한다. 
// 
