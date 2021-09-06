#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

// 구조체를 다른 구조체의 멤버로 사용하기, Nested Structures
// 중첩 구조체라고도 한다. 
//
// 문법 자체는 직관적이고 간단하다.

struct names {			// A structure
	char given[LEN];	// first name
	char family[LEN];	// last name
};

struct reservation {	// Another structure
	struct names guest;	// a nested structure
	struct names host;	// a nested structure
	char food[LEN];
	char place[LEN];

	// time
	int year;
	int month;
	int day;
	int hours;
	int minutes;
};

int main() {

	struct reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"the Gatsby mansion"},
		.food = {"Escargot"},
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};

	/*
	* 아래와 같이 출력이 되게 하라
	
	Dear Nick Carraway,
	I would like to serve you Escargot.
	Please visit the Gatsby mansion on 10/4/1925 at 18:30.
	Sincerely,
	Jay Gatsby

	*/

	main_answer_try();

	printf("\n\n");

	main_answer_answer();

	return 0;
}

// 이름에 대한 구조체가 있다. struct names
// 그리고 예약에 대한 구조체가 있다. struct reservation
// 
	/*
	struct names {			// A structure
		char given[LEN];	// first name
		char family[LEN];	// last name
	};

	struct reservation {	// Another structure
		struct names guest;	// a nested structure
		struct names host;	// a nested structure
		char food[LEN];
		char place[LEN];
	*/
//
// <= struct names guest;
//    <= 손님의 이름을 이렇게 선언했다. 
//       구조체 변수(name)를 또 다른 구조체(reservation)의 멤버로 넣어 놨다.
//       struct names를 또 다를 구조체에서 재사용하고 있다. 
// 
// 초대한 사람의 이름을 저장할 때,  
// struct names host; 와 같이 구조체 변수(names)를 또 사용할 수 있다. 
// 
// struct names가 guest라는 멤버, host라는 멤버에 두 번 사용됐다. 
// <= 위에서 struct names를 한 번 선언해 놓고, 아래 구조체에서 두 번 사용하고 있다. 
// 
// char food[LEN];	<= 음식 이름
// char place[LEN];	<= 초대하는 장소
// 
// 그다음 시간 정보에 관한 변수를 선언한다. 
// 구조체는 위와 같은 정보를 가지고 있다. 
// 
// 초기화하는 방법은?
// 
	/*
	struct reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"the Gatsby mansion"},
		.food = {"Escargot"},	// 달팽이 요리
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};
	*/
// <= 쭉 나열해도 되지만, 멤버가 많으므로 헤깔리지 않기 위해서
//    designated initializer을 사용했다. 
// 
// 초대장 같은 느낌이 나도록 출력을 해 봐라.