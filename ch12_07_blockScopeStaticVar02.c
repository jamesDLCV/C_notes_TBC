#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int* count() {
	int ct = 0;	
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;
}

int* static_count() {
	static int ct = 0;	

	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;
}

void counter_caller() {
	count();
}

void static_counter_caller() {
	static_count();
}

int main() {
	count();			
	count();			
	count();			
	counter_caller();	  

	static_count();				
	static_count();				
	static_count();				
	static_counter_caller();	

	return 0;
}

// 보통 반환을 할 때, 값으로 반환을 하고 반환 값을 받는 쪽에서 이미 메모리를 가지고 있고,
// 거기에 복사하는 형태로 많이 한다. 
// 
// 하지만, 포인터를 반환하는 경우도 꽤 있다. 
// API를 사용하거나, 하드웨어 관련 된 API를 사용할 경우
// 게임 엔진을 만들 경우 마우스를 제어할 수 있는 포인터를 가지고 온다 등등.
//  <= 포인터를 반환하는 값을 쓴다. 
//
// // warning C4172: returning address of local variable or temporary: ct
// 실행하면 이와 같은 warning이 뜬다. 
// 
// 뭐가 문제일까?
// 
// 받는 쪽에서 포인터를 받는다는 것은, 그 메모리에 대해서 뭔가 작업을 하고 싶을 때, 
// 포인터로 받는 것이다. 
// ct의 지역 변수의 포인터 &ct를 반환해 주고 있는데, 
// 문제는, 변수 ct는 블록을 벗어나면, 사라진다. 
// 
// stack frame 전체가 사용할 수 있는 메모리를 미리 잡아 놓는 경우가 있기 때문에, 
// 포인터로 접근을 해서 접근이 가능한 경우도 있다. 
// 하지만 그것은 컴파일러가 프로그램을 추적하기 위해서 
// 사용하는 기법을 조금 악용(?) 오용하는 프로그래밍 방식이다. 
//
//int* count() {
//	int ct = 0;
//	printf("count = %d %lld\n", ct, (long long)&ct);
//	ct++;
//
//	return &ct;
//}
// 이렇게 프로그래밍하는 것은 아주 좋지가 않다.  
// 되더라다 이렇게 하는 것은 안 좋다. 다른 사람이 봤을 때 의도를 이해하기가 쉽지 않다. 
// 내가 나중에 봐도 이해하기 어렵고, 유지 관리하다가 망가질 가능성도 크다. 
// 따라서 return &ct; <= 이런 방식의 반환 값 사용은 아주 좋지 않다. 
// 
//	int* static_count() {
//		static int ct = 0;
//
//		printf("static count = %d %lld\n", ct, (long long)&ct);
//		ct++;
//
//		return &ct;
//	}
// 하지만 이것은 경우가 조금 다르다. 
// 진짜 꼭 필요한 경우, 어쩔 수 없이 사용해야만 하는 경우에는 사용할 수 있다. 
// 
// 왜 가능하느냐? static int ct = 0;은 메모리에 고정된 자리(주소)를 가지고 있으므로
// 포인터로 반환해서 다른 곳에서 쓸 수가 있다.  
// 하지만 이렇게까지 해서 static int ct를 밖에서 접근하고 싶을 때는,
// 차라리 전역 변수를 쓰는 것이 낫다. 
// 