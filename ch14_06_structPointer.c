#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

// 구조체와 포인터
// 
// 구조체에 대한 포인터는 앞선 강좌에서 소개한 적이 있다. 
// 주의해야 할 점 위주로 한 번 더 살펴 본다. 

struct names{
	char given[LEN];
	char family[LEN];
};

struct friend {
	struct names full_name;		// nested struct
	char mobile[LEN];
};

int main() {
	struct friend my_friends[2] = {
		{ {"Ariana", "Grande"}, "1234-1234" },
		{ {"Taylor", "Swift"}, "6550-8888" }
	};

	struct friend* girl_friend;

	girl_friend = &my_friends[0];

	printf("%zd\n", sizeof(struct friend));
	printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
	// -> : indirect member access operator

	girl_friend++;

	printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.family);
	// . has higher precedence than *

	printf("\n\n************ example1 ************\n\n");

	main_example();

	return 0;
}

// 구조체 연산의 배열을 하나 만들었다. 
// 
//	struct friend my_friends[2] = {
//		{ {"Ariana", "Grande"}, "1234-1234" },
//		{ {"Taylor", "Swift"}, "6550-8888" }
//	};
// 
// <= full_name이 names이고, names가 given, family 두 개로 돼 있으므로, 
//    이와 같이 초기화를 해 줬다. (nested struct 초기화를 해 줬다) 
// 
// 이렇게 my_friends라는 구조체 변수의 배열[2]을 만들었다. 
// 
// struct friend* girl_friend;
// <= girl_friend라는 '구조체 friend 타입의 변수에 대한 포인터'를 선언했다.
//    간단하게 줄여서, friend라는 구조체를 가리키는 포인터 변수이다. 
//    더 줄인다면, 구조체에 대한 포인터이다라고 할 수 있다. 
//
// girl_friend = &my_friends[0];
// <= addressof 연산자를 사용해서 대입을 한다. 
//    my_friends 배열에서 값을 가져오기 위해서 [0] indexing을 하고,
//    다시 &로 주소를 가져오고 있다. 
//    앞에서 배열, 포인터 사용법에서 많이 다뤄서 익술할 것이다. 
//  
// printf("%zd\n", sizeof(struct friend));
// <= friend 구조체의 사이즈를 찍어 본다.
// 
// printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
//						// -> : indirect member access operator 
// <= girl_friend의 주소를 출력한다. 
//    girl_friend가 구조체에 대한 포인터이기 때문에, 
//    dot(.) operator를 사용하지 못하고, indirect operator(->)를 사용한다. 
// 
//    full_name은 포인터가 아니므로 dot(.) operator를 사용해서 
//    names 안에 있는 given에 접근한다.
// 
//    포인터인 경우, 포인터가 아닌 경우가 모두 소개되고 있다. 
// 
// girl_friend++;
// <= 포인터 연산이다. 
// 
// printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.family);
// <= 포인터 연산 후 포인터 girl_friend의 주소를 출력한다. 
//    (*girl_friend).full_name.family)는
//	  indirection을 한 번 한 후 dot operator로 멤버에 접근하고 있다. 
//    dot operator가 indirection operator보다 우선 순위가 높기 때문에, 
//    괄호를 쳐 줘야 한다.  
//    girl_friend->full_name.given와 동일하다. 
// 
// 실행하면, 다음과 같이 출력된다. 
// 60                     <=  sizeof(struct friend)는 60이다.
// 214246292400 Ariana    <= 
// 214246292460 Swift     <= 사이즈가 60이다. 
// 
// 포인터 연산에서 하나를 더한다는 것은 그 자료형의 사이즈만큼 내부적으로 
// 메모리 주소를 더해(바꿔) 준다. 
// 
// 다음 예제를 보자.