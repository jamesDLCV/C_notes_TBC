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
// <= scanf() 입력을 받는 게 사실은, 하나의 문자열만 입력을 받으려고 하는 것인데, 
// 
// 다른 리턴 값을 준다면, 
// if (flag != 1)
//     printf("Wrong input");	// TODO: receive input again
// scanf()가 몇 개의 항목을 입력 받았나 리턴을 해 준다.
// 문제가 됐다면, 다시 입력을 받는 코드를 추가로 만들어도 되지만, 
// 기본 문법 공부할 때는 그런 상황이 발생할 일은 없기 때문에, 
// printf("Wrong input"); 이렇게 출력하는 것으로 처리했다. 
// 
// flat이 1이다. <= 문제가 없다. 하나의 항목을 잘 입력 받았면, 
// else {
//     pst->fname = (char*)malloc(strlen(temp) + 1);	// + 1 is for '\0'
//       <= strlen(temp)로 길이를 재 보고, +1로 null character가 들어갈 자리를 
//          추가해 준다. sizeof(char)을 할 필요가 없다. 이는 1이다. 
//          malloc으로 받고 pst->fname로 fname 포인터를 가리키게 해 준다. 
//       
//  동적 할당 받을 때도, 사실은 동적 할당에 어떤 문제가 있어서 메모리를 받아오지 못하면
//  null pointer를 갖게 된다. 
//     if (pst->fname != NULL)
//         strcpy(pst->fname, temp);
//     <= null pointer가 아니라면, string copy를 해서 scanf()에서 입력 받은
//        temp 값을 동적 할당 받은 메모리 pst->fname에다가 복사해 주고 있다. 
//     else
//         printf("Malloc() failed");
//     <= 문제가 있다면, malloc()이 실패했다는 메시지를 띄운다.
// }
// 
// 아래 부분 코드도 동일하다. 