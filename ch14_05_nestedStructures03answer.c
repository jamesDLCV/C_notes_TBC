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
	* �Ʒ��� ���� ����� �ǰ� �϶�

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

// printf()���ٰ� format string�� �ٸ� ����(formatted)�� ���� ���� ���� �ִ�.
// ������ ���ϸ� ���ڿ��� ���� �������̴�. 
// 
// ������ó�� ��ø�� ����ü�� ����� ����� �� �ִ�. 
// names��� ����ü�� guest������ ����ϰ� host������ ����� �� �ִ�. 
// �� �ٸ� waitress�� �ִٰ� �ϴ��� �� ����� �� �ִ�. 
// 
// ����ü�� ���� �� �ϳ���, �� �� ����� ����, 
// ���� �� �����ؼ� ���α׷��� ���� �����ϰ� �ϰ�, 
// ���α׷����� �ڵ� �ð��� �ٿ� �� �� �ִ�. 
// 
// ������ ��� �̷� ������ �ڵ� ��Ÿ���� ����� ������ �Ѵ�. 
// ��ü���⿡�� ���� ���� �ְ� �����ϰ� �� ���̴�. 
// 
// ��ø ����ü, nested structure�� ���ؼ� ���� �ô�. 