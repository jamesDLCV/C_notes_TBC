#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_TITLE 40	// 39 글자 + '\0'(null character)
#define MAX_AUTHOR 40	// 39 글자 + '\0'(null character)
#define MAX_BOOKS 3		/* maximum number of books */

// 구조체의 배열 연습 문제
//
// 문자열을 입력받는 함수
char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);	// vs. scanf()로는 입력 받을 수 없다.
	if (ret_val) {
		find = strchr(st, '\n');	// look for newline
		if (find)					// if the address is not NULL
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;			// dispose of rest of line
	}
	return ret_val;
}

struct book {
	char title[MAX_TITLE];
	char author[MAX_AUTHOR];
	float price;
};

int main() {

	struct book library[MAX_BOOKS] = {
		{ "Empty", "Empty", 0.0f, }
	};	/* array of book structures */

	int count = 0;

	while (1) {
		printf("Input a book title or press [Enter] to stop. \n>> ");
		//TODO: input titile
		if (s_gets(library[count].title, MAX_AUTHOR) == NULL)
			break;
		//TODO: break if the first character of the input title is '\0'
		if (library[count].title[0] == '\0')
			break;

		printf("Input the author.\n>> ");
		//TODO: input author name
		s_gets(library[count].author, MAX_AUTHOR);

		printf("Input the price.\n>> ");
		//TODO: input price
		int flag = scanf("%f", &library[count].price);
		
		//TODO: clear buffer
		while (getchar() != '\n')
			continue;	/* clear input line */
		
		count++;

		if (count == MAX_BOOKS) {
			printf("No more books.\n");
			break;
		}
	}

	if (count > 0) {
		printf("\nThe list of books: \n");
		for (int index = 0; index < count; ++index)
			printf("\"%s\" written by %s: $%.1f\n", library[index].title, library[index].author, library[index].price);
	}
	else
		printf("No books to show.\n");

	return 0;
}

// 각각의 구조체에 접근하려면 indexing을 해야 한다. 
// <= library[count].title[0]
//    인덱싱한 구조체의 변수를 member access operator를 이용해서 
//    titile에 접근할 수 있다. 
//    title이 배열이다. 
// 
// library[count].title[0] == '\0'
// <= title의 첫 번째 글자에 접근하기 위해서 이렇게 인덱싱하고, 
//    이 첫 번째 글자가 null character '\0'이면 break한다. 
//    <= if (library[count].title[0] == '\0')
//           break;
// 
// 나머지는 크게 어려운 부분이 없다. 
// s_gets() 함수 사용해서 입력 받으면 된다. 
// 
// int flag = scanf("%f", &library[count].price);
// <= scanf() 입력을 받은 후에,
// 
// while (getchar() != '\n')
//     continue;	/* clear input line */
// <= 버퍼를 지워 버린다. 
// 
// 이거 외에도 다른 방식으로 짤 수도 있지만, 이렇게 while()문으로 짜는 게 간결하다. 
// 
// 구조체의 배열 연습 문제를 풀어 봤다.  
// 많은 양의 데이터를 처리할 때, 이렇게 구조체의 배열을 사용할 수 있다. 