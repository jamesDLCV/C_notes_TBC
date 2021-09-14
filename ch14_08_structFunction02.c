#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);

int main() {

	struct name_count user_name;

	user_name = receive_input();
	user_name = count_characters(user_name);
	show_result(user_name);

	return 0;
}

struct name_count receive_input() {

	struct name_count nc;

	int flag;

	printf("Input your first name:\n>> ");

	s_gets(nc.first, NLEN);
	/*
	flag = scanf("%[^\n]%*c", nc.first);
	if (flag != 1)
		prinf("Wrong input");
	*/

	printf("Input your last name:\n >> ");

	s_gets(nc.last, NLEN);
	/*
	flag = scanf("%[^\n]%*c", nc.last);
	if (flag != 1)
		prinf("Wrong input");
	*/

	return nc;
}

struct name_count count_characters(struct name_count nc) {

	nc.num = strlen(nc.first) + strlen(nc.last);

	return nc;
}

void show_result(const struct name_count nc) {

	printf("Hi, %s %s. Your name contains %d characters.\n", nc.first, nc.last, nc.num);

}

// 다음 s_gets()는 사용을 안 해도 된다. 
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


// user_name = receive_input();
// <= receive_input()의 parameter가 없다. 
//    반환값으로 구조체를 반환해 주고 있다. 
//    user_name이 receive_input()로부터 구조체의 값을 받아오고 있다. 
//
// user_name = count_characters(user_name);
// <= count_characters(user_name)로부터 받아오고 있다. 
// 
// show_result(user_name);
// <= 주소가 아니고 user_name 구조체 변수(struct variable) 자체를 받아가고 있다.  
// 
// 구조체는 대입을 할 때, 멤버들의 값을 전부 복사해 준다. 
// 그 성질을 이용해서 코드를 짜 보아라. 
//
//
	/*
	struct name_count receive_input() {

		struct name_count nc; <= structure variable을 하나 만들어 준다.

		int flag;

		printf("Input your first name:\n>> ");

		s_gets(nc.first, NLEN); <= 입력을 받고,

		//flag = scanf("%[^\n]%*c", nc.first);
		//if (flag != 1)
		//    prinf("Wrong input");


		printf("Input your last name:\n >> ");

		s_gets(nc.last, NLEN);	<= 입력을 받고,

		//flag = scanf("%[^\n]%*c", nc.last);
		//if (flag != 1)
		//    prinf("Wrong input");

		return nc;				<= 그다음 리턴을 해 주고 있다.
	}
	*/
	// 
	// 위 함수에서 nc 값이 반환이 되면,
	// user_name = receive_input();
	// <= 받는 쪽에서 내부적으로 복사가 돼서 user_name에 있는 멤버들의 값들이 
	//    receive_input()에서 반환해 준 값으로(입력받은 값으로) 바뀌게 된다. 
	//    <= 주소가 궁금하면 앞선 강의에서처럼 디버거로 찍어 보면 된다. 
	// 
	// 
	//  struct name_count count_characters(struct name_count nc) {
	//     nc.num = strlen(nc.first) + strlen(nc.last);
	//     return nc;
	//  }
	// <= nc로 받아 왔고, 합을 구해서 이 nc에 넣고 이것을 그대로 return을 한다. 
	//    그러면, 
	//    user_name = count_characters(user_name); 받는 쪽에서 
	//      count_characters(user_name)을 복사해서 user_name에 넣는다.
	//    count_characters가 구조체 변수를 반환을 하면, 
	//    대입을 해서 user_name에 복사가 된다.
	//
	// 다음 show_result() 함수를 보면,
	// void show_result(const struct name_count nc) {
	//     printf("Hi, %s %s. Your name contains %d characters.\n", nc.first, nc.last, nc.num);
	// }
	// <= 내부적으로 nc를 받아오고, nc를 이용해서 출력을 하고 있다. 
	// 
	// 이 코드를 보면, 이전의 포인터를 사용한 것과 스타일이 다르다. 
	// 
	// user_name = receive_input();
	// <= 이렇게 함수가 뭔가 기능을 수행하고 결과를 출력해 주고, 
	// 
	// user_name = count_characters(user_name);
	// <= user_name으로 뭔가 입력을 받아오고 그것을 가지고 count_characters() 함수로
	//    기능을 수행하고, 그 결과를 user_name에 반환해 준다. 
	// 
	// 이런 식으로 프로그래밍을 할 수도 있다. 
	// 
	// 이 두 가지 예제를 통해서, 문법적으로도 몇 가지 공부를 했고, 
	// 이렇게 다른 스타일로도 구현을 할 수 있다는 것을 알아 둬라. 
	// 
	// 구조체와 함수를 같이 사용하는 방법을 살펴 봤다. 