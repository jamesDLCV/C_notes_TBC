#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// automatic variables
// 저장 공간의 5가지 분류 중에서, 자동적인 분류 공간을 사용하는, 그러니까
// automatic storage calss를 사용하는 자동 변수에 대해서 살펴 보자.
// 
// 자동, automatic <= 지금까지 사용한 지역 변수가 모두 automatic variables이다. 
// 지속 기간이 자동적으로 결정되는 것이 자동 변수이다. 
// 프로그램 전체에서 계속 사용하는 변수가 아니라면, 메모리를 계속 가지고 있을 필요가 없다.
// 메모리 공간을 보다 효율적으로 사용하기 위해서, 
// 사용하지 않을 때는 다른 변수가 사용할 수 있도록 메모리 공간을 내주는 것이다. 
// 앞 강의에서 스택에 쌓였다가 치웠다가, push를 했다가 pop했다가 하는 과정을 
// 보여 준 적이 있다. <= 이런 식으로 메모리 공간을 공유하면서 메모리 공간을 효율적으로 
// 사용할 수 있는 구조가 구현이 돼 있다. 
// 프로그래머 입장에서 정말 편하겠다라고 생각할 수 있다. 
// 하지만 프로그래머는 프로그래밍할 때 블록을 잘 정해 줘야 한다. 
// 이 변수는 이 블록 안에서만 사용되면 됩니다라는 방식으로 프로그래밍을 하게 된다. 
// 
// 지역 변수 혹은 자동 변수를 선언할 때는, 불록 안에다가 선언을 해야 한다. 
// 지금까지 지역 변수가 블록 안에 선언돼 있을 경우 그 블록을 벗어나면, 볼 수가 없었다. 
// visible하지가 않았다. 
// 자동 변수는 메모리에서 자동적으로 사라지기 때문에, 지속 기간에 계속 영구적으로
// static하게 있는 것이 아니라, 자동적으로 있다 없다하기 때문에, linkage 연결 상태를
// 유지할 수가 없다. 유지가 안 된다. 그래서 linkage가 없다. 외부로 연결할 수가 없다. 
// 
// stack에 메모리를 쌓았다가 뺐다가 하기 때문에, 더 효율적으로 메모리 공간을 관리할 수 있다. 
// 이 프로그램이 사용하는 총 메모리의 양, 전체 메모리의 양을 줄일 수 있다. 
// 
// 변수의 수명을, 변수의 지속 기간을, 블록에 따라서 블록을 벗어나면 자동으로 빼 준다. 
// <= 자동 변수 automatic variables이라고 한다. 
// 그냥 지역 변수라고 생각하면 편하다. 
// 
// ch09_05 지역 변수와 스택을 잘 학습했다면 이 부분을 이해하기 용이할 것이다. 
// 
// 앞에서 지역 변수 공부할 때와 비슷하다.
// 조금 더 체계적으로 몇 가지 용어와 함께 살펴 보자.   

/*
	Automatic storage class
	- Automatic storage duration, block scope, no linkage
	- Any variable declared in a block or function header
*/

void func(int k);

int main() {	//Note: main() is a function

	auto int a;	// keyword auto: a storage-class specifier
	a = 1024;

	printf("%d\n", a);	// what happens if uninitialized? Error
	auto int b = a * 3;	// what happens if uninitialized? Error

	int i = 1;
	int j = 2;

	printf("i %lld %lld\n", (long long)i, (long long)&i);

	{
		int i = 3;	// name hiding
		printf("i %lld %lld\n", (long long)i, (long long)&i);

		// j is visible here
		printf("j = %d\n", j);

		int ii = 12345;
	}

	// ii is not visible here, 블록을 벗어났다. 

	printf("i %lld\n", (long long)&i);	// which i??? 

	for (int m = 1; m < 2; m++) 
		printf("m %lld\n", (long long)&m);	// no block?
							 // block이 없어도 한 문장까지는 ;전까지가 scope가 된다. 
		
	func(5);	// cannot see any of the variabled defined so far.

	for (int m = 3; m < 4; m++) {
		printf("m %lld\n", (long long)&m);	// block?
	}

	// 위 for문에서와 같이 변수 m을 중복해서 사용할 수 있다. 
	// 블록을 벗어나면 메모리에서 빠져나가기 때문이다.

	return 0;
}

void func(int k) {
	int i = k * 2;
	// do something with i and k
	printf("i in func %lld\n", (long long)&i);
}

// Automatic storage duration: 블록을 벗어나면 메모리를 반납한다. Stack에서 빼 버린다.
//							   다른 변수가 그 공간을 사용할 수 있다. 
// 결과적으로 전체적으로 사용되는 메모리의 최대 양이 줄어들고, 더 효율적으로 사용할 수 있다.
// block scope: 지역 변수를 만들기 위해 block scope를 만들었다고 생각해도 무방하다.
// C는 OS를 만들려고 만든 언어이고, OS를 만드는 사람 입장에서는 효율성이 아주 중요했다. 
// no linkage: 메모리에 있다 없다 하기 때문에 외부에 연결을 시킬 수 없다. 
// 
// Any variable declared in a block or function header: 블록이나 해더에 선언된 변수도
// automatic storage class에 해당이 된다. 
// 
// auto int a, 자료형 앞에 auto를 쓸 수 있다. 자동 변수라는 것을 명확하게 하기 위해서다.
// 하지만 안 붙여도 동일하므로, 보통은 붙이지 않는다. 
// 지금까지 사용한 모든 지역 변수 앞에 auto를 붙여도 된다. 
// 안 붙여도 되지만 지역 변수인 것을 강조하기 위해서 붙일 수도 있다.
// 
// C++에서는 auto라는 키워드가 완전히 다른 뜻으로 쓰인다. 
// C에서는 storage-class specifier라는 것을 강조하기 위해 앞에 auto를 붙여 줄 수 있다. 
// 하지만 대부분은 안 붙인다 정도로 정리하라. 
// 
// auto int b = a * 3;	<= 이런 자동 변수, 지역 변수들은 초기화를 꼭 해 줘야 한다. 
// 왜 그럴까?
// BSS segment에 들어 있는 전역 변수들은, 처음에 한 번만 초기화를 해 주면 된다. 
// 그 후는 컴파일러가 초기화를 해 준다. 
// 자동 변수들(지역 변수들)은 stack에 들어갔다 나왔다 빈번하게 사용되므로, 
// 들어갈 때마다 매번 0으로 초기화를 해 주게 되면, 많은 비용이 발생한다. 
// computing time을 조금이라도 더 잡아 먹는다. 
// C언어는 철학이 프로그래머를 믿는다이다. 프로그래머가 알아서 할 것이라고 믿는다.
// 그러므로 자동으로 초기화를 해 주지 않는다. 
// automatic variable은 초기화를 해 주지 않는다. 
// 스택에 들어왔다 나갈 때마다 초기화를 해 주면 overhead가 생길 수 있다. 
// 그래서 프로그래머가 초기화를 해 줘야 한다. 초기화를 해 주지 않으면 에러가 생긴다. 
// 
// 실무에서는 보다 편하게 사용할 수 있는 방법이 있다. 
// 
// int i = 1; <= i라는 이름을 가진 메모리 공간이 있다. 객체, 오브젝트라는 용어로 배웠다. 
// 사실은 변수의 이름이 중요한 것이 아니라 
// 변수의 이름을 통해서 접근하는 메모리 공간이 중요하다.
// i는 identifier일 뿐이다. 이름일 뿐이다. 
// 
// int i = 1;
// {
//	  int i = 3;	// name hiding
// }
// 
// 위처럼 영역이 바뀌면 똑같은 이름의 변수도 사용할 수 있다. 
// 다만 이때는 더 큰 넓은 영역에서 선언이 된 identifier는 hiding 돼 버린다. 
// name hiding돼 버린다. 
// 같은 이름이 중복되면 가장 안쪽 영역에서 선언된 변수를 의미하도록 한다.  
// 더 큰 영역에서의 i가 사라진 것은 아니다. 이름을 부르기가 애매해서 못 부르는 것뿐이다.
// 이름만 숨겨진 것이다.  
// 이 정도로 정리해 두면 되겠다. 
// 
// int j = 2;
// {
//    // j is visible here   <= j를 이 블록 안에서 볼 수 있다. 
//	  printf("j = %d\n", j);
// }
// 
// 위를 보면, printf() 함수의 영역에서는 j가 없다. 그러나 더 큰 영역에서는 j가 있다. 
// 이럴 경우 더 큰 영역에서의 j를 그대로 사용할 수 있다. 
// 어떻게 사용할 수 있는 것이냐?
// stack에 먼저 쌓아 두었기 때문이다. 
// 
// {
//    int ii = 123;
// }
//
// ii is not visible. <= 위 영역 밖에서는 ii를 볼 수 없다. 
// 블록을 벗어나면 stack에서 빠져나가기 때문에 사용할 수 없다. 
// 
// stack, stack frame 두 가지 용어를 같이 사용하고 있다. 
// stack frame은 함수 전체 (main() 함수 전체)에 필요한 메모리를 의미한다. 
// 변수 하나 하나 가 쌓이고 빠져나가고 하는 것은 stack 자료 구조를 생각하면 된다. 
// 
// 구체적으로 어떤 메모리를 어떻게 사용할지는 컴파일러에 따라 달라진다. 
// GCC를 사용해서 메모리 주소를 찍어 볼 때하고 MS의 컴파일러를 사용할 때가 
// 전반적으로 좀 다른 경향이 있다. 
// 
// 이론적인 컴파일러, 운영체제의 내용을 좀 더 구체적으로 공부할 때는 
// 리눅스 GCC로 공부하는 게 더 나을 수 있다. 
// visual studio는 실무에서 많이 사용한다. 
// 
// func(5); 가 호출이 되면 stack frame 자체가 바뀌어 버린다. 
// 그러므로 main() 함수 내의 변수들은 보이지 않게 된다. 
// 
// 함수 안에서는 왜 다른 함수에서 사용된 변수를 사용할 수 없는가?
// stack frame이 바뀌기 때문이다. 
// 함수에서 사용한 변수들이 함수의 block을 벗어나면(함수가 끝나면), 
// 메모리에서 빠져나가게 하기 위해서 (메모리를 아끼기 위해서),   
// 다른 함수에서 이 메모리를 사용하게 하기 위해서, 
// 이렇게 설계가 된 것이다.  
// 