#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// register 변수에 대해서 알아 보자
// 앞서 CPU가 일하는 방법 강좌에서 register를 다룬 적이 있다. 
// register는 CPU의 일부이다. 
// CPU가 가지고 있는 임시 작업 공간이다. 
// 메모리는 물리적으로 CPU와 분리가 돼 있다. 
// 메인보드에 깔려 있는 통로를 통해서, 버스를 통해서 데이터를 주고 받는다. 
// 따라서 주고 받을 때 시간이 걸린다. 
// register는 메모리처럼 데이터를 가지고 있을 수가 있다. 
// 하지만 CPU의 일부이기 때문에, 엄청 빠르게 작동한다. 
// 빠르게 작동해야 할 프로그램을 만들 때는, 특정한 변수를 직접 register의 어딘가에다가
// 두고 싶을 때가 있다. 메모리에 두는 것이 아니라 CPU에 두고 싶을 때가 있다. 
// 
// register 변수에 대해서 살펴 보자. 
// 저장 공간 분류에 따르면, register storage class에 해당된다. 
// 자동 automatic 변수와 묶어서 설명하는 경우가 많다. 
// 레지스터는 지속 기간하고 영역이 자동 변수와 똑같다. 
// linkage가 없는 것도 똑같다. 
// 하지만 메모리에서의 위치가 스택이 아니고, register에 위치를 시키려고 하는 게
// 중요한 차이이다. 
// 프로그래머가 변수 앞에 register 키워드를 붙여서 register에 위치하게 해 달라고 요청은
// 할 수 있지만, 컴파일러가 그것을 반드시 받아들이지는 않는다. 
// 컴파일러가 상황을 보고 register에 넣어 줄 수 있으면 넣어 주고, 
// 여의치 않으면 그냥 stack에 넣어서 자동 변수처럼 처리한다. 
// 

void temp(register int r) {
	// do something with r
}

int main() {
	register int r;	// register에 위치하게 해 달라.
	r = 123;

	//printf("%p\n", &r);
	int* ptr = &r;

	return 0;
}

// register int r;	// 프로그래머가 컴파일러에게 이 변수는 
					// 가급적이면 register에 위치하게 해 달라고 요청하는 것이다. 
// 항상 register에 올라가는 것은 아니다. 
// 하드웨어와 밀접하게 작동을 하거나, 특수한 컴파일러를 사용하거나 하지 않는 한
// 잘 사용하지 않는다. 
// 
// 빠른 프로그램을 짜고 싶다면, 
// 병렬 처리, 분산 처리, GPU, SIMD로 intrinsic operator를 쓴다. 
// 최후의 수단으로는 인라인으로 어셈블리어를 쓴다. <= C++의 경우이다. 
// 
// embeded나 하드웨어를 직접 제어하는 쪽에서 C 프로그래밍을 한다면, 
// 이 register를 사용하게 될 수도 있다. 
// 
// 문법적으로 잘 봐 두어야 할 것은,
// int* ptr = &r; <= 주소를 가지고 올 수가 없다. 
// address of operator를 사용할 수가 없다. 
// 사용하려고 하면 Error가 뜬다. 
// register는 메모리에 위치하고 있는 게 아니므로 가져올 수가 없다. 
// 
// 이 외에는 우리가 일반적으로 사용하는 변수처럼 사용하면 된다. 
// 
// 컴파일러에 따라서 double 같은 경우는 컴파일 자체가 안 될 수도 있다고 한다. 
// 