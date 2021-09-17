#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// strlen(), strcmp()
#include <stdlib.h>	// malloc(), free()
#define SLEN 81

struct namect {
	char* fname;	// use malloc()
	char* lname;	// use malloc()
	int letters;
};

void getinfo(struct namect*);	// allcoate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);	// free memory when done
//char* s_gets(char* st, int n);

int main() {
	
	/* Exercise */
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}

void getinfo(struct namect* pst) {
	int flag;
	char temp[SLEN] = { 0, };

	printf("Please enter your first name.\n");
	// s_gets(pst->fname, NLEN);
	flag = scanf("%[^\n]%*c", temp);
	if (flag != 1)
		printf("Wrong input");	// TODO: receive input again
	else {
		pst->fname = (char*)malloc(strlen(temp) + 1);	// + 1 is for '\0'
		if (pst->fname != NULL)
			strcpy(pst->fname, temp);
		else
			printf("Malloc() failed");
	}

	printf("Please enter your last name.\n");
	// s_gets(pst->fname, NLEN);
	flag = scanf("%[^\n]%*c", temp);
	if (flag != 1)
		printf("Wrong input");	// TODO: receive input again
	else {
		pst->lname = (char*)malloc(strlen(temp) + 1);	// + 1 is for '\0'
		if (pst->lname != NULL)
			strcpy(pst->lname, temp);
		else
			printf("Malloc() failed");
	}
}

void makeinfo(struct namect* pst) {

	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect* pst) {

	printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);

}

void cleanup(struct namect* pst) {
	free(pst->fname);
	free(pst->lname);
}

// 
// flag = scanf("%[^\n]%*c", temp);
// <= scanf() �Է��� �޴� �� �����, �ϳ��� ���ڿ��� �Է��� �������� �ϴ� ���ε�, 
// 
// �ٸ� ���� ���� �شٸ�, 
// if (flag != 1)
//     printf("Wrong input");	// TODO: receive input again
// scanf()�� �� ���� �׸��� �Է� �޾ҳ� ������ �� �ش�.
// ������ �ƴٸ�, �ٽ� �Է��� �޴� �ڵ带 �߰��� ���� ������, 
// �⺻ ���� ������ ���� �׷� ��Ȳ�� �߻��� ���� ���� ������, 
// printf("Wrong input"); �̷��� ����ϴ� ������ ó���ߴ�. 
// 
// flat�� 1�̴�. <= ������ ����. �ϳ��� �׸��� �� �Է� �޾Ҹ�, 
// else {
//     pst->fname = (char*)malloc(strlen(temp) + 1);	// + 1 is for '\0'
//       <= strlen(temp)�� ���̸� �� ����, +1�� null character�� �� �ڸ��� 
//          �߰��� �ش�. sizeof(char)�� �� �ʿ䰡 ����. �̴� 1�̴�. 
//          malloc���� �ް� pst->fname�� fname �����͸� ����Ű�� �� �ش�. 
//       
//  ���� �Ҵ� ���� ����, ����� ���� �Ҵ翡 � ������ �־ �޸𸮸� �޾ƿ��� ���ϸ�
//  null pointer�� ���� �ȴ�. 
//     if (pst->fname != NULL)
//         strcpy(pst->fname, temp);
//     <= null pointer�� �ƴ϶��, string copy�� �ؼ� scanf()���� �Է� ����
//        temp ���� ���� �Ҵ� ���� �޸� pst->fname���ٰ� ������ �ְ� �ִ�. 
//     else
//         printf("Malloc() failed");
//     <= ������ �ִٸ�, malloc()�� �����ߴٴ� �޽����� ����.
// }
// 
// �Ʒ� �κ� �ڵ嵵 �����ϴ�. 