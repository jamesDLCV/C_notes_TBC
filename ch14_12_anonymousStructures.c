#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 익명 구조체, Anonymous Structures
//
// 앞에서 구조체를 구조체의 멤버로 사용하는 방법을 살펴 봤다. 
// <= 중첩된 구조체 멤버 nested structure member

struct names {
	char first[20];
	char last[20];
};

struct person {
	int id;
	struct names name;	// nested structure member
};

struct person2 {
	int id;
	struct { char first[20]; char last[20]; };	// anonymous structure
};

int main() {

	struct person ted = { 123, {"Bill", "Gates"} };
	struct person ted3 = { 125, "Robert", "Hand" };

	puts(ted.name.first);
	puts(ted3.name.first);

	struct person2 ted2 = { 124, {"Steve", "Wozniak"} };
	struct person2 ted4 = { 124, "James", "Hwang" };	// also works

	puts(ted2.first);
	puts(ted4.first);

	return 0;
}

// 구조체를 보면,
	/*
	struct person {
		int id;
		struct names name;	// nested structure member
	};
	*/
// <= 이 구조체의 이름 person의 공식적인 명칭은 tag이다. 
//	
// nested structure member를 사용할 때는
// (위 예에서는) struct person의 struct names 안에 
// first, last 멤버와 같은 식으로 접근해야 했다. 
//  
	/*
	struct person ted = { 123, {"Bill", "Gates"} };
	struct person ted3 = { 125, "Robert", "Hand" };

	puts(ted.name.first);
	puts(ted3.name.first);
	*/
// <= ted.name.first와 같이 dot operators를 두 번 사용해서 접근했다. 
// 
// 그런데, 
	/*
	struct person2 {
		int id;
		struct { char first[20]; char last[20]; };	// anonymous structure
	};
	*/
// <= person2라는 구조체에서는, structure를 structure 안에 넣은 것은 
//    struct person과 동일한데, 구조체의 이름이 없다. 
// 
//    struct { char first[20]; char last[20]; };
//    <= 보는 바와 같이 struct에 tag가 붙어 있지 않다. 이름이 없다. 
//       이름이 없으므로 anonymous structure라고 한다. 
//       이름이 없이 멤버만 나열돼 있는 형태이다. 
// 
//	  struct { char first[20]; char last[20]; }; 이 문법은 
//    나중에 공영체와 연결이 된다. 
// 
// struct person2 ted2 = { 124, {"Steve", "Wozniak"} };
// puts(ted2.first);
// <= 멤버에 접근할 때 이렇게 ted2.first로 직접 접근할 수 있다. 
//    
// nested structure일 경우에는, 
// ted, nested structure name, 그다음 멤버와 같은 순으로 접근이 됐다. 
// <= member access를 두 번 해야 했다. 
// 
// puts(ted2.first); 은 member access를 한 번만 하면 되는 간결한 형태이다. 
// 
// 초기화하는 방법은, 
// struct person ted = { 123, {"Bill", "Gates"} };
// struct person ted3 = { 125, "Robert", "Hand" };
// 
// struct person2 ted2 = { 124, {"Steve", "Wozniak"} };
// struct person2 ted2 = { 124, "Steve", "Wozniak" };
// <= 모두 비슷해 보인다. 
// 
// anonymous structure는 이름이 없는 형태(tag가 없는 형태)로, 
// member에 직접 접근해서 사용할 수 있는 방법이다. 
// 
// 익명 구조체에 대해서 간단히 살펴 봤다. 