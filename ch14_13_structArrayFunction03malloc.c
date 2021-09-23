#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		// <= include �� ��� �Ѵ�. 
#define SLEN 101

// ����ü�� �迭�� ����ϴ� �Լ�
// malloc()���� ������ ����.

struct book {
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book *books, int n);

int main() {

	//struct book my_books[3];	// = { {The Great Gatsby", "F. Scott Fitzgerald"}, ...};
	struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);

	// my_books�� NULL�� ���� ó��
	// �� ó���� �� �� �ָ� �Ʒ��� my_books[0]�� ��� ǥ�ð� ���.
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

// #include <stdlib.h>	<= include�� �ش�.
// 
// void print_books(const struct book books[], int n);��
// void print_books(const struct book *books, int n);����
// <= *books �����ͷ� �ٲ� �ش�. 
// 
	/*
	void print_books(const struct book* books, int n) {

		for (int i = 0; i < n; ++i) {
			printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
		}
	}
	*/
// <= �Ű������� *books �����ͷ� ���� �͵�, books[i].name �迭ó�� �� �� �ִ�. 
// 
// my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
// <= my_books[0] = (struct book)�� �Ķ��� ���� ǥ�ð� ���. 
//    ���࿡ my_books�� NULL�̸� ��ϳĴ� ��� �ְ� �ִ�. 
//    visual studio�� ���� ȯ���� �������ϱ� ���� ��� �ִ� ���̴�. 
// 
// �׷��Ƿ�, 
	/*
	if (!my_books) {
		printf("Malloc failed.");
		exit(1);
	}
	*/
// <= NULL�� ���� ó���� �־� �ش�. 
//    ���� ���� ȯ���� �������� malloc()�� �������� ��쿡�� exit(1);�� ������ �Ǵ�,
//    �� �Ʒ������� �����ϰ� �۵��� �� �ִٰ� ���� ��� ������ ���� �ش�. 
// 
// ����ü�� �迭�� �Լ��� ������ �ִ� ����� ���� �ô�. 