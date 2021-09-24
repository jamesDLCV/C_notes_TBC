#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	
#include <conio.h>

#define SLEN 101

// 구조체 파일 입출력 연습 문제
//
// 구조체를 파일에 저장하기도 하고 
// 파일에 저장했던 구조체를 다시 읽어들이는 방법에 대해서 살펴 본다.
// 파일 입출력은 앞에서 살펴 봤다. 
// 연습 문제를 통해서 구조체의 파일 입출력을 살펴 본다. 

struct book {
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main() {

	int temp;		// _getch(); 입력을 위해서 선언한 변수.
	int n = 3;
	
	struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

	if (!my_books) {
		printf("Malloc failed");
		exit(1);
	}

	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_books, n);

	printf("\nWriting to a file.\n");
	write_books("books.txt", my_books, n);
	free(my_books);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	my_books = read_books("books.txt", &n);
	//read_books2("books.txt", &my_books, &n);

	print_books(my_books, n);
	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n) {
	/* 직접 구현 */
}

void write_books(const char* filename, const struct book* books, int n) {
	/* 직접 구현 */
}

struct book* read_books(const char* filename, int* n) {
	/* 직접 구현 */
	return NULL;
}

void read_books2(const char* filename, struct book** books_dptr, int* n) {
	/* 직접 구현 */
}

// 실행을 하면, 다음과 같이 출력이 되게 작성을 하라.
// 
// Book 1 : "The Great Gatsby" written by "F. Scott Fitzgerald"
// Book 2 : "Hamlet" written by "William Shakespeare"
// Book 3 : "The Odyssey" written by "Homer"
//	<= 이렇게 출력이 되고, 
// Writing to a file.	<= 파일에 저장이 된 후
// Done.                <= 저장이 됐다고 출력이 된다. 
//
// 파일을 열어 보면, 
// 파일에는 다음이 저장돼 있다. 
// 3
// The Gread Gatsby
// F. Scott Fitzgerald
// Hamlet
// William Shakespeare
// The Odyssey
// Homer
// 
// Press any key to read data from a file.
//  <= 이렇게 파일로부터 데이터를 더 읽어들이겠다는 메시지가 출력되고, 
//      
// 원한다면 파일에 책을 더 추가할 수도 있다. 
// 4                          <= 한 권 더 추가, txt 파일에서 추가해 준다.
// The Gread Gatsby
// F. Scott Fitzgerald
// Hamlet
// William Shakespeare
// The Odyssey
// Homer 
// OpenGL Superbible          <= 한 권 더 추가, txt 파일에서 추가해 준다.
// Graham Sellers
// 
// 아무 키나 누르면, 
// Book 1 : "The Great Gatsby" written by "F. Scott Fitzgerald"
// Book 2 : "Hamlet" written by "William Shakespeare"
// Book 3 : "The Odyssey" written by "Homer"
// Book 4 : "OpenGl Superbible" written by "Graham Sellers"
// <= 이렇게 출력이 된다. 
// 
// 책 3권이 저장돼 있고, text file을 열어서 수정을 했더니
// 수정을 한 내용까지 반영이 돼 있는 프로그램이다. 
// 기본적인 구조는 앞 강의에서 소개를 했다. 
// 
// 아래 세 함수는 새로 구현을 해야 한다. 
// 
// void print_books(const struct book* books, int n); 
// <= 이 함수는 앞 강의에서 구현을 했다.
//    int n는 몇 개를 출력할지를 받고 있다. 
// 
// void write_books(const char* filename, const struct book* books, int n);
//  <= write을 하는 함수이다. 
//     저장할 파일을 char* filename으로 입력 받고,
//     그다음 저장할 books의 array를 받고 있는데, 
//     동적 할당을 받으므로 포인터로 받고 있다. <= const struct book* books
//     int n은 몇 개를 출력할지를 받고 있다. 
// 
// struct book* read_books(const char* filename, int* n);
//  <= write하는 함수가 위에 있으니 read 읽어 들이는 함수도 필요하다. 
//     
// void read_books2(const char* filename, struct book** books_dptr, int* n);
//  <= 이것도 read 읽어 들이는 함수이다. 
// 
// 읽어 들이는 함수를 두 개 구현해 놨는데 이 두 개는 signature가 좀 다르다 .
// 기능은 거의 동일하다. 코드도 거의 동일하다. 
// 차이가 뭔지 잠깐 보자. 
// 
// struct book* read_books(const char* filename, int* n);
// <= 파일 이름 char* filname하고 
//    몇 개를 읽어 들였는지를 int* n 포인터로 알려 주고 있다. 
//    (개수를 받아오기 위해서 parameter가 포인터로 돼 있다)
//    그다음 struct book*은 반환값으로 저장이 돼 있는 메모리의 주소를 
//    포인터로 받아오고 있다. 
// 
// void read_books2(const char* filename, struct book** books_dptr, int* n);
// <= 이 함수도 기능이 거의 동일하다. 
//    하지만 반환값으로 위 함수와 같은 포인터가 아니고, 
//    대신에 인수로 이중 포인터 struct book** books_dptr를 받아 들이고 있다. 
// 
// 일단
// struct book* read_books(const char* filename, int* n);
// 이 함수로 일단 구현을 해 봐라. 이것이 조금 더 편할 수 있다. 
// 그다음 위 함수를 변형시켜서, 다음처럼 이중 포인터로까지
// void read_books2(const char* filename, struct book** books_dptr, int* n);
// 함수까지 구현해 보면, 텍스트 파일 입출력은 해 봤다고 볼 수 있다. 
// 
// 메인 함수까지 제시해 주겠다. 
// 
// 아래의 _getch() 함수는 사용자에게 키보드로 하나의 키를 입력 받는 함수이다. 
//   만약 int temp = _getch();에 a를 입력하면 
//   a 키에 해당하는 ASCII 코드 값 97이 temp에 저장된다. 
//   cf) getch() 함수는 Enter 키를 눌러야 반응하지만, 
//       _getch() 함수는 어떤 키를 누르든지 해당 키 값을 반환하면서 즉시 종료된다.
// 
// int temp;	<= _getch(); 입력을 위해서 선언한 변수.
// int n = 3;   <= n은 3으로 시작한다.
//
// struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);
//
// if (!my_books) {
//     printf("Malloc failed");
//	   exit(1);
// }
//
// 다음 책 세 권에 대한 정보는 앞 강의에서 다룬 것과 동일하다.
// my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
// my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
// my_books[2] = (struct book){ "The Odyssey", "Homer" };
//
// print_books(my_books, n); <= 책을 전부 출력하는 함수이다. 
//                              여기까지는 앞 강의와 동일하다.
//
// printf("\nWriting to a file.\n");
// write_books("books.txt", my_books, n);
//  <= write_books() 함수를 이용해서 books.txt 파일에 my_books의 정보를 
//     n에 저장돼 있는 값만큼 저장한다. 여기에서는 3이다. 
// 
// free(my_books);
//  <= 동적 할당했던 메모리를 free()한다. 다시 반환하고, 
// 
// n = 0;	<= n을 0으로 바꿔 준다.
//  
// printf("Done.\n"); <= 일단 끝난다. 
//
// printf("\nPress any key to read data from a file.\n\n");
//  <= 그다음 다시 읽어 들일 것이면, 키를 눌러라.
//     키를 누르기 전에 폴더로 가서 books.txt 파일을 열고 편집을 한다. 
// temp = _getch();
//  <= 키 입력을 받는다. 
//
// my_books = read_books("books.txt", &n);
//  <= 포인터 n을 받아 와서 이렇게 대입한다. 
// 
// 만약 이중 포인터를 사용하는 함수를 사용한다면, 
// read_books2("books.txt", &my_books, &n); 
//  <= 이런 형태로 구현하면 된다. 
// 
// my_books = read_books("books.txt", &n);나 
// read_books2("books.txt", &my_books, &n); 둘 중 한 형태로 구현을 해도
// 괜찮다. 이중 포인터로 구현하는 것은 조금 까다로울 수 있다. 
// 
// print_books(my_books, n);
//  <= 읽어 들인 내용이 제대로 들어왔는지 확인하는 함수를 만든다. 
// 
// free(my_books);
//  <= 할 일이 다 끝났으므로 메모리를 지워 준다. 
// n = 0;
// 
// 위 함수를 직접 구현해 봐라. 