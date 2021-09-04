#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_TITLE 40	// 39 글자 + '\0'(null character)
#define MAX_AUTHOR 40	// 39 글자 + '\0'(null character)
#define MAX_BOOKS 3		/* maximum number of books */

// 구조체의 배열 연습 문제
// 
// 실행을 하면 다음의 문구가 뜬다.
// Input a book titile or press [Enter] to stop.
// <= 엔터를 누르면 종료한다. 
//    종료될 때, 
//    No more books. <= 이런 문구가 뜬다. 
// >> 책 이름을 입력한다. (예외 처리는 생략한다)
// Input the author.
// >> 저자 이름을 입력한다. 
// Input the price
// >> 책 가격을 입력한다.
// 다시 아래 문구가 뜨면서 입력이 반복된다.
// Input a book titile or press [Enter] to stop.
// <= 다시 책 이름을 입력할 수도 있고 enter를 치고 종료할 수도 있다. 
// 종료를 하면, 다음과 같이 출력이 된다. 
// The list of books:
// "A Song of Ice and Fire" written by George R. R. Martin: $100.0
// ...
// ...
// 
// 이렇게 출력이 되는 프로그램을 구조체로 작성하라.

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
		//TODO: break if the first character of the input title is '\0'

		printf("Input the authorl.\n >> ");
		//TODO: input author name

		printf("Input the price.\n >> ");
		//TODO: input price
		//TODO: clear buffer

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

// scanf()는 빈칸을 입력받지 못하므로 사용할 수 없다.
// fgets(st, n, stdin); n으로 입력 한도 지정, stdin으로 콘솔 입력
//	빈칸이 있는 문자열을 new line이 있는 데까지 입력을 받을 수 있다. 
//
  /*
	if (ret_val) {
		find = strchr(st, '\n');	// look for newline
		if (find)					// if the address is not NULL
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;			// dispose of rest of line 
  */
//
// <= 줄바꿈(\n)을 찾고 그것을 \0 null character로 바꿔서, 
//    C언어에서 사용하는 문자열로 만들어 주는 부분도 구현이 돼 있다.
// 
// while (getchar() != '\n')
//    continue;
// <= (만약 그렇지 않을 경우에는) buffer를 다 지워 버려라. 
// 
// 이 함수는, 빈칸이 있는 문자열을 new line을 만날 때까지 입력을 받아서, 
// 그것을 포인터 st에 저장하고, 리턴을 해 주는 함수이다. 
// 
// 이 함수를 이용해서 책 이름과 저자의 이름을 입력 받으면 된다. 
// 
// struct book {
//	  char title[MAX_TITLE];
//	  char author[MAX_AUTHOR];
//	  float price;
// };
// <= 책 한 권을 저장할 때 필요한 정보들을 가지고 구조체를 선언했다. 
// 
//	struct book library[MAX_BOOKS] = { { "Empty", "Empty", 0.0f, } };	
//                                              /* array of book structures */
// <= 구조체의 배열을 선언했다. 
//    { { "Empty", "Empty", 0.0f, } }; 이렇게 초기화까지 해 줬다. 
//    struct book library[MAX_BOOKS]; 이렇게 선언만 하면, 
//    최근 visual studio에서 초기화를 안 해 줬다고 Warning을 띄운다. 
//    입력받을 저장 공간을 초기화해 줬다. 
// 
// int count = 0; 몇 번 입력을 받을지 세야 하므로 count 변수를 선언하고 초기화해 준다.
//
// if (count == MAX_BOOKS) {
//  	printf("No more books.\n");
//  	break;
// }
// <= 최대 입력받는 수에 도달하면, break로 끊고 나간다. 
// 
// TODO: input titile
//  타이틀을 입력 받는다.
// TODO: break if the first character of the input title is '\0'
//  입력받은 타이틀의 첫 글자가 null character라면, 제대로 입력을 받은 것이 아니고,
//  사용자가 종료를 하기 위해서 enter를 누룬 것이므로 break로 while()문에서 나간다.
//  <= '\0'가 입력되면 break되는 걸 어떻게 코딩할지 고민해 봐라. 
// 
// 사용자가 종료를 하지 않았다면, 사용을 하겠다는 의지를 보인 것이므로, 
// printf("Input the authorl.\n >> "); //TODO: input author name
//  <= 저자의 이름을 입력 받고,  
//
// printf("Input the price.\n >> ");
//	TODO: input price
//   <= 가격을 입력받는다. 문자열이 아닌 float로 입력을 받는다. 
//      scanf()로 입력받는 게 가장 편리하다. 
//	TODO: clear buffer
//   <= scanf()로 입력을 받은 후에는 버퍼를 지워 줘야 한다. 
// 
// count++;
//
// if (count == MAX_BOOKS) {
//     printf("No more books.\n");
//	   break;
// }
// <= 최대로 입력받을 수 있는 수에 도달하면, break로 끊고 나간다. 
// 
// 책을 한 권 이상 입력을 받았다면,  
// if (count > 0) {
//	   printf("\nThe list of books: \n");
//	   for (int index = 0; index < count; ++index)
//		   printf("\"%s\" written by %s: $%.1f\n", library[index].title,			 library[index].author, library[index].price);
// }
// else
//     printf("No books to show.\n");
// 
// <= 책의 내용을 출력한다. 
//    구조체의 배열은 위와 같이 indexing을 하고 멤버도 이렇게 접근하면 된다.  
//    
// 위 TODO 부분만 구현하면, 연습 문제의 코드를 완성할 수 있다. 
// 스스로 구현해 보기 바란다. 