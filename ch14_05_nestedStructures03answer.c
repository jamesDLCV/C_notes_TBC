#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

// answer

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

int main_answer_answer() {

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


	const char* formatted = 
		"\
Dear %s %s,\n\
I would like to serve you %s.\n\
Please visit %s on %d/%d/%d at %d:%d.\n\
Sincerely,\n\
%s %s\n\
";
			
	printf(formatted, res.guest.given, res.guest.family, res.food, res.place, res.day, res.month, res.year, res.hours, res.minutes, res.host.given, res.host.family);

	return 0;
}

// printf()에다가 format string을 다른 변수(formatted)로 집어 넣을 수도 있다.
// 엄밀히 말하면 문자열에 대한 포인터이다. 
// 
// 위에서처럼 중첩된 구조체의 멤버도 사용할 수 있다. 
// names라는 구조체를 guest에서도 사용하고 host에서도 사용할 수 있다. 
// 또 다른 waitress가 있다고 하더라도 또 사용할 수 있다. 
// 
// 구조체의 장점 중 하나가, 한 번 만들어 놓고, 
// 여러 번 재사용해서 프로그램을 보다 간결하게 하고, 
// 프로그래머의 코딩 시간을 줄여 줄 수 있다. 
// 
// 앞으로 계속 이런 식으로 코딩 스타일을 만들어 나가야 한다. 
// 객체지향에서 보다 깊이 있게 공부하게 될 것이다. 
// 
// 중첩 구조체, nested structure에 대해서 살펴 봤다. 