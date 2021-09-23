#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		// <= include 해 줘야 한다. 
#define SLEN 101

// 구조체의 배열을 사용하는 함수
// malloc()으로 구현해 봐라.

struct book {
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book *books, int n);

int main() {

	//struct book my_books[3];	// = { {The Great Gatsby", "F. Scott Fitzgerald"}, ...};
	struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);

	// my_books가 NULL일 때의 처리
	// 이 처리를 안 해 주면 아래의 my_books[0]에 경고 표시가 뜬다.
	if (!my_books) {
		printf("Malloc failed.");
		exit(1);
	}

	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_books, 3);

	return 0;
}

void print_books(const struct book *books, int n) {

	for (int i = 0; i < n; ++i) {
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
	}
}

// #include <stdlib.h>	<= include해 준다.
// 
// void print_books(const struct book books[], int n);를
// void print_books(const struct book *books, int n);으로
// <= *books 포인터로 바꿔 준다. 
// 
	/*
	void print_books(const struct book* books, int n) {

		for (int i = 0; i < n; ++i) {
			printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
		}
	}
	*/
// <= 매개변수를 *books 포인터로 가져 와도, books[i].name 배열처럼 쓸 수 있다. 
// 
// my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
// <= my_books[0] = (struct book)에 파란색 물결 표시가 뜬다. 
//    만약에 my_books가 NULL이면 어떡하냐는 경고를 주고 있다. 
//    visual studio의 개발 환경이 컴파일하기 전에 경고를 주는 것이다. 
// 
// 그러므로, 
	/*
	if (!my_books) {
		printf("Malloc failed.");
		exit(1);
	}
	*/
// <= NULL일 때의 처리를 넣어 준다. 
//    통합 개발 환경이 좋아져서 malloc()이 실패했을 경우에는 exit(1);가 실행이 되니,
//    그 아래에서는 안전하게 작동할 수 있다고 보고 경고 물결을 없애 준다. 
// 
// 구조체의 배열을 함수에 전달해 주는 방법을 살펴 봤다. 