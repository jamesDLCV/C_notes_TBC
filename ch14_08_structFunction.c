#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NLEN 30

// 구조체와 함수를 함께 사용해야 할 때 주의 사항을 
// 연습 문제를 통해서 살펴 보자. 
//
// 문제 풀이가 두 단계로 이루어져 있다.
// 
// 첫 번째 예제를 보자.

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main() {

	struct name_count user_name;

	receive_input(&user_name);		// 구조체 변수의 주소를 넣어 준다.
	count_characters(&user_name);   // 글자 수를 세고 num에 저장한다.
	show_result(&user_name);		// 결과를 보여 준다.

	return 0;
}

void receive_input(struct name_count* ptr_nc) {
	int flag;

	printf("Input your first name:\n>> ");

	// s_gets(ptr_nc->first, NLEN);
	flag = scanf("%[^\n]%*c", ptr_nc->first);	// ^ : cap operator
	if (flag != 1)
		printf("Wrong input");

	printf("Input your last name:\n>> ");

	// s_gets(ptr_nc->last, NLEN);
	flag = scanf("%[^\n]%*c", ptr_nc->last);
	if (flag != 1)
		printf("Wrong input");
}

void count_characters(struct name_count* ptr_nc) {

	ptr_nc->num = strlen(ptr_nc->first) + strlen(ptr_nc->last);

}

void show_result(const struct name_count* ptr_nc) {

	printf("Hi, %s %s. Your name has %d characters.\n", ptr_nc->first, ptr_nc->last, ptr_nc->num);

}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);	// vs. scanf()
	if (ret_val) {
		find = strchr(st, '\n');	// look for newline
		if (find)					// if the address is not NULL
			*find = '\0';			// place a null character there
		else
			while (getchar() != '\n')
				continue;			// dispose of rest of line
	}

	return ret_val;
}


// 출력 예시는 다음 과 같다. 
// Input your first name:
// >> Jeong-mo
// Input your last name;
// >> Hong
// Hi, Jeong-mo Hong. Your name has 12 characters/
// 
// s_gets() 함수를 보면, 조금 번거로운데,
// flag = scanf("%[^\n]%*c", ptr_nc->first);
// <= 이와 같이 scanf() 함수 하나로 교체할 수 있다. 
//
// flag = scanf("%[^\n]%*c", ptr_nc->first);
// <= [^\n]의 의미는, \n이 나타날 때까지 입력을 받으라는 의미이다. 
//    %*c 의 의미는, c를 하나 무시하라이다. 앞에 있는 줄바꿈 기호 하나를 무시하라.
//    <= %*c 가 앞에 있는 \n 기호를 먹어 버리는 것이다. 
// 
//    ptr_nc->first 사용자가 입력한 문자열에서 줄바꿈을 빼고, 입력을 받아 준다.
//    편리한 함수이다. 앞으로는 이 함수를 사용하자. 
// 
//    s_gets(ptr_nc->first, NLEN); 이와 같이 사용하는 게 
//	   정통적인 c 스타일이기는 하지만, 기본적인 원리를 이해한 후에는, 
//     프로그램의 효율을 높이는 게 중요하기 때문에, 
//     flag = scanf("%[^\n]%*c", ptr_nc->first); 를 사용한다. 
// 
// void receive_input(struct name_count* ptr_nc) 함수를 보면,
// ptr_nc를 포인터로 받았으므로,
// ptr_nc->first 멤버로 직접 scanf()로 스트림 입력을 받는다. 
// 
// 마찬가지로 아래 함수도 ptr_nc 포인터로 가지고 오고 있기 때문에, 
 /*
	void count_characters(struct name_count* ptr_nc) {

		ptr_nc->num = strlen(ptr_nc->first) + strlen(ptr_nc->last);

	}
 /*
// <= 그냥 값을 바꿔 버릴 수 있다.
//
// 결과를 출력할 때도 마찬가지로, 아래와 같이 편하게 구현할 수 있다.
 /*
	void show_result(const struct name_count* ptr_nc) {

		printf("Hi, %s %s. Your name has %d characters.\n", ptr_nc->first, ptr_nc->last, ptr_nc->num);

	}
 */
 // 나중에 객체지향을 배울 때 다음을 참고 하라.
 // 위 함수에서 first, last, num은 모두 struct name_count의 멤버들이다. 
 // 그래서 객체지향에서는 위 void show_result() 함수를 structure 안에 넣어 버린다. 
 // C언어에서는 문법적으로 안 되지만, C++에서 구조체를 사용할 때는, 
 // 구조체 안에도 함수를 넣을 수 있다. <= 객체지향 언어에서 공부하게 된다. 
 // 
 // 구조체는 데이터를 묶어 놨다. 
 // 그 데이터를 가지고 할 수 있는 일들을 기능까지 집어 넣은 것이 객체지향에서 말하는
 // 객체, 오브젝트, 클래스이다.  
 // 
 // 두 번째 예제를 살펴 보자. 