#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SLEN 101

// 구조체의 배열을 사용하는 함수

struct book {
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book books[], int n);

int main() {

	struct book my_books[3];	// = { {The Great Gatsby", "F. Scott Fitzgerald"}, ...};
	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_books, 3);

	return 0;
}

void print_books(const struct book books[], int n) {

	for (int i = 0; i < n; ++i) {
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
	}
}

// print_books() 함수는 위와 같이 구현했다. 
// 여기까지만 구현하면 조금 부족한 것 같다. 
// 
// 동적 할당 배열을 사용하면 어떻게 바뀌는지 간단한게 구현해 봐라.