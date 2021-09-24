#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	
#include <conio.h>

#define SLEN 101

// ����ü ���� ����� ���� ����
//
// ����ü�� ���Ͽ� �����ϱ⵵ �ϰ� 
// ���Ͽ� �����ߴ� ����ü�� �ٽ� �о���̴� ����� ���ؼ� ���� ����.
// ���� ������� �տ��� ���� �ô�. 
// ���� ������ ���ؼ� ����ü�� ���� ������� ���� ����. 

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
	/* ���� ���� */
}

void write_books(const char* filename, const struct book* books, int n) {
	/* ���� ���� */
}

struct book* read_books(const char* filename, int* n) {
	/* ���� ���� */
	return NULL;
}

void read_books2(const char* filename, struct book** books_dptr, int* n) {
	/* ���� ���� */
}

// ������ �ϸ�, ������ ���� ����� �ǰ� �ۼ��� �϶�.
// 
// Book 1 : "The Great Gatsby" written by "F. Scott Fitzgerald"
// Book 2 : "Hamlet" written by "William Shakespeare"
// Book 3 : "The Odyssey" written by "Homer"
//	<= �̷��� ����� �ǰ�, 
// Writing to a file.	<= ���Ͽ� ������ �� ��
// Done.                <= ������ �ƴٰ� ����� �ȴ�. 
//
// ������ ���� ����, 
// ���Ͽ��� ������ ����� �ִ�. 
// 3
// The Gread Gatsby
// F. Scott Fitzgerald
// Hamlet
// William Shakespeare
// The Odyssey
// Homer
// 
// Press any key to read data from a file.
//  <= �̷��� ���Ϸκ��� �����͸� �� �о���̰ڴٴ� �޽����� ��µǰ�, 
//      
// ���Ѵٸ� ���Ͽ� å�� �� �߰��� ���� �ִ�. 
// 4                          <= �� �� �� �߰�, txt ���Ͽ��� �߰��� �ش�.
// The Gread Gatsby
// F. Scott Fitzgerald
// Hamlet
// William Shakespeare
// The Odyssey
// Homer 
// OpenGL Superbible          <= �� �� �� �߰�, txt ���Ͽ��� �߰��� �ش�.
// Graham Sellers
// 
// �ƹ� Ű�� ������, 
// Book 1 : "The Great Gatsby" written by "F. Scott Fitzgerald"
// Book 2 : "Hamlet" written by "William Shakespeare"
// Book 3 : "The Odyssey" written by "Homer"
// Book 4 : "OpenGl Superbible" written by "Graham Sellers"
// <= �̷��� ����� �ȴ�. 
// 
// å 3���� ����� �ְ�, text file�� ��� ������ �ߴ���
// ������ �� ������� �ݿ��� �� �ִ� ���α׷��̴�. 
// �⺻���� ������ �� ���ǿ��� �Ұ��� �ߴ�. 
// 
// �Ʒ� �� �Լ��� ���� ������ �ؾ� �Ѵ�. 
// 
// void print_books(const struct book* books, int n); 
// <= �� �Լ��� �� ���ǿ��� ������ �ߴ�.
//    int n�� �� ���� ��������� �ް� �ִ�. 
// 
// void write_books(const char* filename, const struct book* books, int n);
//  <= write�� �ϴ� �Լ��̴�. 
//     ������ ������ char* filename���� �Է� �ް�,
//     �״��� ������ books�� array�� �ް� �ִµ�, 
//     ���� �Ҵ��� �����Ƿ� �����ͷ� �ް� �ִ�. <= const struct book* books
//     int n�� �� ���� ��������� �ް� �ִ�. 
// 
// struct book* read_books(const char* filename, int* n);
//  <= write�ϴ� �Լ��� ���� ������ read �о� ���̴� �Լ��� �ʿ��ϴ�. 
//     
// void read_books2(const char* filename, struct book** books_dptr, int* n);
//  <= �̰͵� read �о� ���̴� �Լ��̴�. 
// 
// �о� ���̴� �Լ��� �� �� ������ ���µ� �� �� ���� signature�� �� �ٸ��� .
// ����� ���� �����ϴ�. �ڵ嵵 ���� �����ϴ�. 
// ���̰� ���� ��� ����. 
// 
// struct book* read_books(const char* filename, int* n);
// <= ���� �̸� char* filname�ϰ� 
//    �� ���� �о� �鿴������ int* n �����ͷ� �˷� �ְ� �ִ�. 
//    (������ �޾ƿ��� ���ؼ� parameter�� �����ͷ� �� �ִ�)
//    �״��� struct book*�� ��ȯ������ ������ �� �ִ� �޸��� �ּҸ� 
//    �����ͷ� �޾ƿ��� �ִ�. 
// 
// void read_books2(const char* filename, struct book** books_dptr, int* n);
// <= �� �Լ��� ����� ���� �����ϴ�. 
//    ������ ��ȯ������ �� �Լ��� ���� �����Ͱ� �ƴϰ�, 
//    ��ſ� �μ��� ���� ������ struct book** books_dptr�� �޾� ���̰� �ִ�. 
// 
// �ϴ�
// struct book* read_books(const char* filename, int* n);
// �� �Լ��� �ϴ� ������ �� ����. �̰��� ���� �� ���� �� �ִ�. 
// �״��� �� �Լ��� �������Ѽ�, ����ó�� ���� �����ͷα���
// void read_books2(const char* filename, struct book** books_dptr, int* n);
// �Լ����� ������ ����, �ؽ�Ʈ ���� ������� �� �ôٰ� �� �� �ִ�. 
// 
// ���� �Լ����� ������ �ְڴ�. 
// 
// �Ʒ��� _getch() �Լ��� ����ڿ��� Ű����� �ϳ��� Ű�� �Է� �޴� �Լ��̴�. 
//   ���� int temp = _getch();�� a�� �Է��ϸ� 
//   a Ű�� �ش��ϴ� ASCII �ڵ� �� 97�� temp�� ����ȴ�. 
//   cf) getch() �Լ��� Enter Ű�� ������ ����������, 
//       _getch() �Լ��� � Ű�� �������� �ش� Ű ���� ��ȯ�ϸ鼭 ��� ����ȴ�.
// 
// int temp;	<= _getch(); �Է��� ���ؼ� ������ ����.
// int n = 3;   <= n�� 3���� �����Ѵ�.
//
// struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);
//
// if (!my_books) {
//     printf("Malloc failed");
//	   exit(1);
// }
//
// ���� å �� �ǿ� ���� ������ �� ���ǿ��� �ٷ� �Ͱ� �����ϴ�.
// my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
// my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
// my_books[2] = (struct book){ "The Odyssey", "Homer" };
//
// print_books(my_books, n); <= å�� ���� ����ϴ� �Լ��̴�. 
//                              ��������� �� ���ǿ� �����ϴ�.
//
// printf("\nWriting to a file.\n");
// write_books("books.txt", my_books, n);
//  <= write_books() �Լ��� �̿��ؼ� books.txt ���Ͽ� my_books�� ������ 
//     n�� ����� �ִ� ����ŭ �����Ѵ�. ���⿡���� 3�̴�. 
// 
// free(my_books);
//  <= ���� �Ҵ��ߴ� �޸𸮸� free()�Ѵ�. �ٽ� ��ȯ�ϰ�, 
// 
// n = 0;	<= n�� 0���� �ٲ� �ش�.
//  
// printf("Done.\n"); <= �ϴ� ������. 
//
// printf("\nPress any key to read data from a file.\n\n");
//  <= �״��� �ٽ� �о� ���� ���̸�, Ű�� ������.
//     Ű�� ������ ���� ������ ���� books.txt ������ ���� ������ �Ѵ�. 
// temp = _getch();
//  <= Ű �Է��� �޴´�. 
//
// my_books = read_books("books.txt", &n);
//  <= ������ n�� �޾� �ͼ� �̷��� �����Ѵ�. 
// 
// ���� ���� �����͸� ����ϴ� �Լ��� ����Ѵٸ�, 
// read_books2("books.txt", &my_books, &n); 
//  <= �̷� ���·� �����ϸ� �ȴ�. 
// 
// my_books = read_books("books.txt", &n);�� 
// read_books2("books.txt", &my_books, &n); �� �� �� ���·� ������ �ص�
// ������. ���� �����ͷ� �����ϴ� ���� ���� ��ٷο� �� �ִ�. 
// 
// print_books(my_books, n);
//  <= �о� ���� ������ ����� ���Դ��� Ȯ���ϴ� �Լ��� �����. 
// 
// free(my_books);
//  <= �� ���� �� �������Ƿ� �޸𸮸� ���� �ش�. 
// n = 0;
// 
// �� �Լ��� ���� ������ ����. 