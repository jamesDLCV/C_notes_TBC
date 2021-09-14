#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NLEN 30

// ����ü�� �Լ��� �Բ� ����ؾ� �� �� ���� ������ 
// ���� ������ ���ؼ� ���� ����. 
//
// ���� Ǯ�̰� �� �ܰ�� �̷���� �ִ�.
// 
// ù ��° ������ ����.

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

	receive_input(&user_name);		// ����ü ������ �ּҸ� �־� �ش�.
	count_characters(&user_name);   // ���� ���� ���� num�� �����Ѵ�.
	show_result(&user_name);		// ����� ���� �ش�.

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


// ��� ���ô� ���� �� ����. 
// Input your first name:
// >> Jeong-mo
// Input your last name;
// >> Hong
// Hi, Jeong-mo Hong. Your name has 12 characters/
// 
// s_gets() �Լ��� ����, ���� ���ŷο,
// flag = scanf("%[^\n]%*c", ptr_nc->first);
// <= �̿� ���� scanf() �Լ� �ϳ��� ��ü�� �� �ִ�. 
//
// flag = scanf("%[^\n]%*c", ptr_nc->first);
// <= [^\n]�� �ǹ̴�, \n�� ��Ÿ�� ������ �Է��� ������� �ǹ��̴�. 
//    %*c �� �ǹ̴�, c�� �ϳ� �����϶��̴�. �տ� �ִ� �ٹٲ� ��ȣ �ϳ��� �����϶�.
//    <= %*c �� �տ� �ִ� \n ��ȣ�� �Ծ� ������ ���̴�. 
// 
//    ptr_nc->first ����ڰ� �Է��� ���ڿ����� �ٹٲ��� ����, �Է��� �޾� �ش�.
//    ���� �Լ��̴�. �����δ� �� �Լ��� �������. 
// 
//    s_gets(ptr_nc->first, NLEN); �̿� ���� ����ϴ� �� 
//	   �������� c ��Ÿ���̱�� ������, �⺻���� ������ ������ �Ŀ���, 
//     ���α׷��� ȿ���� ���̴� �� �߿��ϱ� ������, 
//     flag = scanf("%[^\n]%*c", ptr_nc->first); �� ����Ѵ�. 
// 
// void receive_input(struct name_count* ptr_nc) �Լ��� ����,
// ptr_nc�� �����ͷ� �޾����Ƿ�,
// ptr_nc->first ����� ���� scanf()�� ��Ʈ�� �Է��� �޴´�. 
// 
// ���������� �Ʒ� �Լ��� ptr_nc �����ͷ� ������ ���� �ֱ� ������, 
 /*
	void count_characters(struct name_count* ptr_nc) {

		ptr_nc->num = strlen(ptr_nc->first) + strlen(ptr_nc->last);

	}
 /*
// <= �׳� ���� �ٲ� ���� �� �ִ�.
//
// ����� ����� ���� ����������, �Ʒ��� ���� ���ϰ� ������ �� �ִ�.
 /*
	void show_result(const struct name_count* ptr_nc) {

		printf("Hi, %s %s. Your name has %d characters.\n", ptr_nc->first, ptr_nc->last, ptr_nc->num);

	}
 */
 // ���߿� ��ü������ ��� �� ������ ���� �϶�.
 // �� �Լ����� first, last, num�� ��� struct name_count�� ������̴�. 
 // �׷��� ��ü���⿡���� �� void show_result() �Լ��� structure �ȿ� �־� ������. 
 // C������ ���������� �� ������, C++���� ����ü�� ����� ����, 
 // ����ü �ȿ��� �Լ��� ���� �� �ִ�. <= ��ü���� ���� �����ϰ� �ȴ�. 
 // 
 // ����ü�� �����͸� ���� ����. 
 // �� �����͸� ������ �� �� �ִ� �ϵ��� ��ɱ��� ���� ���� ���� ��ü���⿡�� ���ϴ�
 // ��ü, ������Ʈ, Ŭ�����̴�.  
 // 
 // �� ��° ������ ���� ����. 