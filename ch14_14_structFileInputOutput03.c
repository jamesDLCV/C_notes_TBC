#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	
#include <conio.h>

#define SLEN 101

// 앞에서 만든 텍스트 파일의 구조체를 바이너리로 바꿔 보아라.

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
	//write_books("books.txt", my_books, n);
	write_books("books.dat", my_books, n);
	free(my_books);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	//my_books = read_books("books.dat", &n);
	read_books2("books.dat", &my_books, &n);

	print_books(my_books, n);
	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n) {
	for (int i = 0; i < n; ++i)
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
}

void write_books(const char* filename, const struct book* books, int n) {

	FILE* file = fopen(filename, "wb");	// Binary

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fwrite(&n, sizeof(n), 1, file);	// number of books
	fwrite(books, sizeof(struct book), n, file);
		
	fclose(file);
}

struct book* read_books(const char* filename, int* n_ptr) {

	FILE* file = fopen(filename, "rb");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fread(n_ptr, sizeof(*n_ptr), 1, file);

	struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);
	// Note: calloc()

	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	fread(books, sizeof(struct book), *n_ptr, file);

	fclose(file);

	return books;
}

void read_books2(const char* filename, struct book** books_dptr, int* n_ptr) {
	FILE* file = fopen(filename, "rb");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fread(n_ptr, sizeof(*n_ptr), 1, file);

	struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr); //Note: calloc()

	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	fread(books, sizeof(struct book), *n_ptr, file);

	fclose(file);

	*books_dptr = books;
}

// 코드를 살펴 보자.
// 훨씬 간단해졌다. 
/*
void write_books(const char* filename, const struct book* books, int n) {
	FILE* file = fopen(filename, "w");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fwrite(&n, sizeof(n), 1, file);	// number of books
	 <= n, 사이즈, 개수, file에 출력

	fwrite(books, sizeof(struct book), n, file);
	<= 이 부분이 훨씬 간단해졌다. 
	   멤버들을 하나 하나 파일에 저장하는 것이 아니고, 
	   메모리를 그냥 통째로 저장해 버린다. 
	   읽어 들일 때도 마찬가지다. 

	fclose(file);
}
*/
//
// 읽을 때도 마찬가지다. 
/*
struct book* read_books(const char* filename, int* n_ptr) {

	FILE* file = fopen(filename, "rb");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fread(n_ptr, sizeof(*n_ptr), 1, file);
	<= 개수를 읽어 들인다. 

	struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);
	// Note: calloc()
	<= 메모리를 할당 받는다. 

	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	fread(books, sizeof(struct book), *n_ptr, file);
	<= 읽어 들일 때, sizeof(struct book)이 *n_ptr 개수만큼 있다. 
	   이런 식으로 한 번에 읽어 버리고 끝난다. 
	   binary file을 이용해서 입출력을 하면 구현이 훨씬 간단해진다. 

	fclose(file);

	return books;
}
*/
// 바이너리 포멧을 사용하는 걸 추천한다. 
// 하지만 초보 때나, 복잡한 프로그램을 만들 때, 
// 처음에는 차근 차근 만들게 된다. 
// 디버깅하는 단계에서는 입출력 포멧을 바이너리로 사용하면 들여다 보기가 어렵기 때문에,
// 텍스트 파일로 하는 경우가 있다. 
// 
// 텍스트 포멧을 사용하지 말라는 건 아니다. 유리한 경우도 많다. 
// 하지만 데이터 양이 많고, 입출력 속도가 중요하고, 편리성을 고려하면, 
// 바이너리 포멧으로 구조체를 저장하고, 다시 읽어 들이는 것이 유리한 점이 있다. 
// 
// 구조체의 파일 입출력에 대해서 살펴 봤다. 