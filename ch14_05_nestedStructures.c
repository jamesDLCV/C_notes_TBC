#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

// ����ü�� �ٸ� ����ü�� ����� ����ϱ�, Nested Structures
// ��ø ����ü��� �Ѵ�. 
//
// ���� ��ü�� �������̰� �����ϴ�.

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
	* �Ʒ��� ���� ����� �ǰ� �϶�
	
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

// �̸��� ���� ����ü�� �ִ�. struct names
// �׸��� ���࿡ ���� ����ü�� �ִ�. struct reservation
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
//    <= �մ��� �̸��� �̷��� �����ߴ�. 
//       ����ü ����(name)�� �� �ٸ� ����ü(reservation)�� ����� �־� ����.
//       struct names�� �� �ٸ� ����ü���� �����ϰ� �ִ�. 
// 
// �ʴ��� ����� �̸��� ������ ��,  
// struct names host; �� ���� ����ü ����(names)�� �� ����� �� �ִ�. 
// 
// struct names�� guest��� ���, host��� ����� �� �� ���ƴ�. 
// <= ������ struct names�� �� �� ������ ����, �Ʒ� ����ü���� �� �� ����ϰ� �ִ�. 
// 
// char food[LEN];	<= ���� �̸�
// char place[LEN];	<= �ʴ��ϴ� ���
// 
// �״��� �ð� ������ ���� ������ �����Ѵ�. 
// ����ü�� ���� ���� ������ ������ �ִ�. 
// 
// �ʱ�ȭ�ϴ� �����?
// 
	/*
	struct reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"the Gatsby mansion"},
		.food = {"Escargot"},	// ������ �丮
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};
	*/
// <= �� �����ص� ������, ����� �����Ƿ� ����� �ʱ� ���ؼ�
//    designated initializer�� ����ߴ�. 
// 
// �ʴ��� ���� ������ ������ ����� �� ����.