#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	
#include <conio.h>

#define SLEN 101

// �տ��� ���� �ؽ�Ʈ ������ ����ü�� ���̳ʸ��� �ٲ� ���ƶ�.

struct book {
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main() {

	int temp;		// _getch(); �Է��� ���ؼ� ������ ����.
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

// �ڵ带 ���� ����.
// �ξ� ����������. 
/*
void write_books(const char* filename, const struct book* books, int n) {
	FILE* file = fopen(filename, "w");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fwrite(&n, sizeof(n), 1, file);	// number of books
	 <= n, ������, ����, file�� ���

	fwrite(books, sizeof(struct book), n, file);
	<= �� �κ��� �ξ� ����������. 
	   ������� �ϳ� �ϳ� ���Ͽ� �����ϴ� ���� �ƴϰ�, 
	   �޸𸮸� �׳� ��°�� ������ ������. 
	   �о� ���� ���� ����������. 

	fclose(file);
}
*/
//
// ���� ���� ����������. 
/*
struct book* read_books(const char* filename, int* n_ptr) {

	FILE* file = fopen(filename, "rb");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fread(n_ptr, sizeof(*n_ptr), 1, file);
	<= ������ �о� ���δ�. 

	struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);
	// Note: calloc()
	<= �޸𸮸� �Ҵ� �޴´�. 

	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	fread(books, sizeof(struct book), *n_ptr, file);
	<= �о� ���� ��, sizeof(struct book)�� *n_ptr ������ŭ �ִ�. 
	   �̷� ������ �� ���� �о� ������ ������. 
	   binary file�� �̿��ؼ� ������� �ϸ� ������ �ξ� ����������. 

	fclose(file);

	return books;
}
*/
// ���̳ʸ� ������ ����ϴ� �� ��õ�Ѵ�. 
// ������ �ʺ� ����, ������ ���α׷��� ���� ��, 
// ó������ ���� ���� ����� �ȴ�. 
// ������ϴ� �ܰ迡���� ����� ������ ���̳ʸ��� ����ϸ� �鿩�� ���Ⱑ ��Ʊ� ������,
// �ؽ�Ʈ ���Ϸ� �ϴ� ��찡 �ִ�. 
// 
// �ؽ�Ʈ ������ ������� ����� �� �ƴϴ�. ������ ��쵵 ����. 
// ������ ������ ���� ����, ����� �ӵ��� �߿��ϰ�, ������ ����ϸ�, 
// ���̳ʸ� �������� ����ü�� �����ϰ�, �ٽ� �о� ���̴� ���� ������ ���� �ִ�. 
// 
// ����ü�� ���� ����¿� ���ؼ� ���� �ô�. 