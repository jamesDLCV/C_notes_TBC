#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	
#include <conio.h>

#define SLEN 101

// 구조체 파일 입출력 연습 문제
// 앞에서 제시한 대로 출력이 되는 함수를 구현해 봐라.

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
	for (int i = 0; i < n; ++i)
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
}

void write_books(const char* filename, const struct book* books, int n) {
	FILE* file = fopen(filename, "w");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fprintf(file, "%d\n", n);	// number of books

	for (int i = 0; i < n; ++i)
		fprintf(file, "%s\n%s\n", books[i].name, books[i].author);

	fclose(file);
}

struct book* read_books(const char* filename, int* n_ptr) {

	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	int flag;
	flag = fscanf(file, "%d%*c", n_ptr);	// Remove last \n

	if (flag != 1) {
		printf("File read failed");
		exit(1);
	}

	struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);
		// Note: calloc()

	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	for (int i = 0; i < *n_ptr; ++i) {
		flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

		if (flag != 2) {
			printf("File read failed");
			exit(1);
		}
	}

	fclose(file);

	return books;
}

void read_books2(const char* filename, struct book** books_dptr, int* n_ptr) {
	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	int flag;
	flag = fscanf(file, "%d%*c", n_ptr);	// Remove last \n

	if (flag != 1) {
		printf("File read failed");
		exit(1);
	}

	struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr); //Note: calloc()

	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	for (int i = 0; i < *n_ptr; ++i) {
		flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

		if (flag != 2) {
			printf("File read failed");
			exit(1);
		}
	}

	fclose(file);

	*books_dptr = books;
}

// 코드를 살펴 보자.
// 
	/*
	void write_books(const char* filename, const struct book* books, int n) {
		FILE* file = fopen(filename, "w");
		<= 파일을 연다. "w"로 연다

		if (file == NULL) {
			fputs("Can't open file.", stderr);
			 <= 안 열렸을 때는 에러 메시지를 출력하라.
			exit(1);
		}		

		fprintf(file, "%d\n", n);	// number of books
		<= fprintf(), fscanf() 외의 다른 종류의 파일 입출력 함수들을 사용해도 괜찮다.
		<= 책이 몇 권인지 정수 하나를 출력하고 있다. 

		for (int i = 0; i < n; ++i)
			fprintf(file, "%s\n%s\n", books[i].name, books[i].author);
		<= 구조체의 멤버들을 하나 하나 출력하고 있다. 		
	    텍스트 포멧으로 구조체를 파일에 저장할 때는 멤버를 하나 하나 저장하는 방식이다. 
		지금은 문자열 name과 author만 저장하고 있다. 
		float, int 이런 것들 다 텍스트 파일에 저장했다가 읽어 들일 수 있다. 

		fclose(file);
	}
	*/
//
// write와 read는 대칭이 되는 측면이 있지만 약간 다르다. 
// 읽어 들인 데이터를 어디에 저장하는지가 다르다. 
// 
	/*
	struct book* read_books(const char* filename, int* n_ptr) {

		FILE* file = fopen(filename, "r");
		<= fopen() 함수 read로 열었다. 

		if (file == NULL) {
			fputs("Can't open file.", stderr);
			exit(1);
		}

		int flag;
		flag = fscanf(file, "%d%*c", n_ptr);	// Remove last \n
		<= fscanf()으로 책이 몇 개인지 n_ptr로 읽어 들이고 있다. 
		   n_ptr로 읽어 들인 값이 함수의 매개변수 int* n_ptr에 저장이 된다. 
		   main() 함수의 
		   my_books = read_books("books.txt", &n);
		   <= 이 n에 포인터를 넣어 줬으므로 n의 값이 바뀌는 것이다. 
		   <= "%d%*c" 마지막에 있는 \n 줄바꿈을 제거해 준다.
		      *가 붙으면 읽어 들인 걸 버린다. c 한 글자를 버린다. 

		if (flag != 1) {
			printf("File read failed");
			exit(1);
		}

		struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);
		// Note: calloc()
		<= printf_books()에 n을 넣어 주면, 
		   읽어 들인 책의 개수만큼 출력을 할 수 있다. 

		   write_books() 함수의 fprintf(file, "%d\n", n);에서
		   책이 몇 권인지 파일을 저장하고, \n을 넣어서 줄바꿈을 했다. 

        <= 책이 몇 권인지 *n_ptr로 입력을 받았다. 
		   파일로부터 입력을 받은 게 아니고, 파일로부터 읽어 들였다. 
		   
		<= 그 책 내용들을 읽어 들일 메모리 공간을 동적 할당으로 받아왔다. 
		   *n_ptr은 n_ptr을 dereferencing 혹은 indirection해서 
		   값을 가지고 오고 있다. 

		if (!books) {
			printf("Malloc() failed.");
			exit(1);
		}

		for (int i = 0; i < *n_ptr; ++i) {
			flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);
			<= for문을 돌면서 한 권 한 권 읽어 들이고 있다. 
			   구조체의 멤버들을 하나 하나 읽어 들일 수 있다. 
			   %[^\n]%*c는 scanf()에서도 fscanf()에서도 사용할 수 있다. 

			if (flag != 2) {
				printf("File read failed");
				exit(1);
			}
		}
		
		fclose(file); <= 끝내고 있다. 

		return books;
	}
	*/
// 
//
	/*
	void read_books2(const char* filename, struct book** books_dptr, int* n_ptr) {
		FILE* file = fopen(filename, "r");

		if (file == NULL) {
			fputs("Can't open file.", stderr);
			exit(1);
		}

		int flag;
		flag = fscanf(file, "%d%*c", n_ptr);	// Remove last \n

		if (flag != 1) {
			printf("File read failed");
			exit(1);
		}

		struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr); //Note: calloc()

		if (!books) {
			printf("Malloc() failed.");
			exit(1);
		}

		for (int i = 0; i < *n_ptr; ++i) {
			flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

			if (flag != 2) {
				printf("File read failed");
				exit(1);
			}
		}

		fclose(file);
		*books_dptr = books; <= books_dptr에 *를 붙여서 indirection을 한 번 
		     해 주고, 거기에다가 books의 포인터를 저장하고 있다. 
			 이중 포인터를 사용한다.
	    

	}
	*/
// <= read_books2() 함수는 기능도 코드도 거의 동일한데 약간의 차이가 있다.  
//    여기에서는 struct book** books_dptr, 이중 포인터를 사용하고 있다. 
// 
// my_books = read_books("books.txt", &n);
// <= 이것은 반환값으로 포인터를 받아왔으나,
// read_books2("books.txt", &my_books, &n);
// <= 이중 포인터를 사용할 때는 &my_books 이렇게 반환값이 없이 
//    마치 parameter가 함수의 결과를 담아 주는 변수인 것처럼 사용했다. 
// 
// 여러 번 연습을 하다 보면 어느새 자기도 모르게 숙달이 된다. 
// 
// 이번에는 똑같은 기능을 binaray로 저장을 했다가 
// binary 파일을 읽어 들이는 코드로 바꿔 보아라. 
// 
// 코드와 구조는 거의 동일하다. 
// write_books()와 read_books2만 교체를 하면 된다. 
// read_books()나 read_books2() 둘 중 아무거나 수정해서 써도 된다. 
// 
// txt 파일이 아니라는 것을 나타내기 위해서, 
// 확장자를 dat로 한다. 
// 
// 바이너리 포멧을 사용할 때의 단점은, 수정할 수가 없다. 
// 
// txt 파일에서는 출력을 한 다음에 텍스트 파일을 열어서 편집기로 편집을 하고, 
// 그것을 다시 읽어 들이면, 편집한 내용이 반영이 돼서 화면에 출력이 됐지만,
// binarya 파일로는 이렇게 하기가 좀 불편하다. 
// 하지만 우리가 편집을 해 주는 프로그램을 만들 수도 있다. 
// 이는 후속 강의에서 다룬다. 
// 
// 텍스트 입출력을 위해 만들어 두었던 구조체를 수정해서
// 바이너리로 바꾸어 보아라. 
// 바이너리로 바꿔 보면 뭐가 더 좋은지 느낌이 올 것이다. 