#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SLEN 101

// ����ü�� �迭�� ����ϴ� �Լ�

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

	/* �ϼ��� ���� */

}

// struct book my_books[3];	// = { {The Great Gatsby", "F. Scott Fitzgerald"}, ...};
// <= books�� �� �� �ִ�. 
// 
// my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
// my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
// my_books[2] = (struct book){ "The Odyssey", "Homer" };
// <= �� books�� ���� ������ �ִ�. ���� ���ͷ��� �ʱ�ȭ�� �� ���. 
// 
// struct book my_books[3] = { {The Great Gatsby", "F. Scott Fitzgerald"}, ...}; <= �� �� ���� å ������ ������ �߰�ȣ {} �ȿ� �־ 
//                       �ʱ�ȭ�� �� ���� �ִ�. 
//                       �׷��� �̷��� �ϸ� �ʹ� �������. 
//            �迭�� ���̰� ���� ������ٸ�, �ǹ������� �̷��� ��� ������ ���� ���̴�. 
//  
// �׷��� ��ó�� ���� ���ͷ��� �̿��ؼ� �ʱ�ȭ�� �ߴ�. 
// 
// print_books()��� �Լ��� �ϼ��� ���ƶ�.
// 
// void print_books(const struct book books[], int n); 
// <= const struct book books[] �ñ״�ó ����, �迭�� ����ϴٴ� �� �� �� �ִ�.
// 
// ������ �ϸ�,
// Book 1 : "The Great Gatsby" written by "F. Scott Fitzgerald"
// Book 2 : "Hamlet" written by "William Shakespeare"
// Book 3 : "The Odyssey" written by "Homer"
// <= �̷��� ����� �ǵ��� �Լ��� �ۼ��϶�. 