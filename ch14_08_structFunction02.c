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

// ���� s_gets()�� ����� �� �ص� �ȴ�. 
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
// <= receive_input()�� parameter�� ����. 
//    ��ȯ������ ����ü�� ��ȯ�� �ְ� �ִ�. 
//    user_name�� receive_input()�κ��� ����ü�� ���� �޾ƿ��� �ִ�. 
//
// user_name = count_characters(user_name);
// <= count_characters(user_name)�κ��� �޾ƿ��� �ִ�. 
// 
// show_result(user_name);
// <= �ּҰ� �ƴϰ� user_name ����ü ����(struct variable) ��ü�� �޾ư��� �ִ�.  
// 
// ����ü�� ������ �� ��, ������� ���� ���� ������ �ش�. 
// �� ������ �̿��ؼ� �ڵ带 ¥ ���ƶ�. 
//
//
	/*
	struct name_count receive_input() {

		struct name_count nc; <= structure variable�� �ϳ� ����� �ش�.

		int flag;

		printf("Input your first name:\n>> ");

		s_gets(nc.first, NLEN); <= �Է��� �ް�,

		//flag = scanf("%[^\n]%*c", nc.first);
		//if (flag != 1)
		//    prinf("Wrong input");


		printf("Input your last name:\n >> ");

		s_gets(nc.last, NLEN);	<= �Է��� �ް�,

		//flag = scanf("%[^\n]%*c", nc.last);
		//if (flag != 1)
		//    prinf("Wrong input");

		return nc;				<= �״��� ������ �� �ְ� �ִ�.
	}
	*/
	// 
	// �� �Լ����� nc ���� ��ȯ�� �Ǹ�,
	// user_name = receive_input();
	// <= �޴� �ʿ��� ���������� ���簡 �ż� user_name�� �ִ� ������� ������ 
	//    receive_input()���� ��ȯ�� �� ������(�Է¹��� ������) �ٲ�� �ȴ�. 
	//    <= �ּҰ� �ñ��ϸ� �ռ� ���ǿ���ó�� ����ŷ� ��� ���� �ȴ�. 
	// 
	// 
	//  struct name_count count_characters(struct name_count nc) {
	//     nc.num = strlen(nc.first) + strlen(nc.last);
	//     return nc;
	//  }
	// <= nc�� �޾� �԰�, ���� ���ؼ� �� nc�� �ְ� �̰��� �״�� return�� �Ѵ�. 
	//    �׷���, 
	//    user_name = count_characters(user_name); �޴� �ʿ��� 
	//      count_characters(user_name)�� �����ؼ� user_name�� �ִ´�.
	//    count_characters�� ����ü ������ ��ȯ�� �ϸ�, 
	//    ������ �ؼ� user_name�� ���簡 �ȴ�.
	//
	// ���� show_result() �Լ��� ����,
	// void show_result(const struct name_count nc) {
	//     printf("Hi, %s %s. Your name contains %d characters.\n", nc.first, nc.last, nc.num);
	// }
	// <= ���������� nc�� �޾ƿ���, nc�� �̿��ؼ� ����� �ϰ� �ִ�. 
	// 
	// �� �ڵ带 ����, ������ �����͸� ����� �Ͱ� ��Ÿ���� �ٸ���. 
	// 
	// user_name = receive_input();
	// <= �̷��� �Լ��� ���� ����� �����ϰ� ����� ����� �ְ�, 
	// 
	// user_name = count_characters(user_name);
	// <= user_name���� ���� �Է��� �޾ƿ��� �װ��� ������ count_characters() �Լ���
	//    ����� �����ϰ�, �� ����� user_name�� ��ȯ�� �ش�. 
	// 
	// �̷� ������ ���α׷����� �� ���� �ִ�. 
	// 
	// �� �� ���� ������ ���ؼ�, ���������ε� �� ���� ���θ� �߰�, 
	// �̷��� �ٸ� ��Ÿ�Ϸε� ������ �� �� �ִٴ� ���� �˾� �ֶ�. 
	// 
	// ����ü�� �Լ��� ���� ����ϴ� ����� ���� �ô�. 