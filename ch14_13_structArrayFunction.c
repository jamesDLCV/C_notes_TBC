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

	/* 완성해 보라 */

}

// struct book my_books[3];	// = { {The Great Gatsby", "F. Scott Fitzgerald"}, ...};
// <= books이 세 권 있다. 
// 
// my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
// my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
// my_books[2] = (struct book){ "The Odyssey", "Homer" };
// <= 그 books에 대한 정보가 있다. 복합 리터럴로 초기화를 해 줬다. 
// 
// struct book my_books[3] = { {The Great Gatsby", "F. Scott Fitzgerald"}, ...}; <= 위 세 권의 책 정보를 여기의 중괄호 {} 안에 넣어서 
//                       초기화를 할 수도 있다. 
//                       그러나 이렇게 하면 너무 길어진다. 
//            배열의 길이가 아주 길어진다면, 실무에서도 이렇게 길게 넣지는 않을 것이다. 
//  
// 그래서 위처럼 복합 리터럴을 이용해서 초기화를 했다. 
// 
// print_books()라는 함수를 완성해 보아라.
// 
// void print_books(const struct book books[], int n); 
// <= const struct book books[] 시그니처 보면, 배열과 비슷하다는 걸 알 수 있다.
// 
// 실행을 하면,
// Book 1 : "The Great Gatsby" written by "F. Scott Fitzgerald"
// Book 2 : "Hamlet" written by "William Shakespeare"
// Book 3 : "The Odyssey" written by "Homer"
// <= 이렇게 출력이 되도록 함수를 작성하라. 