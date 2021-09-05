#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_TITLE 40	// 39 ���� + '\0'(null character)
#define MAX_AUTHOR 40	// 39 ���� + '\0'(null character)
#define MAX_BOOKS 3		/* maximum number of books */

// ����ü�� �迭 ���� ����
//
// ���ڿ��� �Է¹޴� �Լ�
char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);	// vs. scanf()�δ� �Է� ���� �� ����.
	if (ret_val) {
		find = strchr(st, '\n');	// look for newline
		if (find)					// if the address is not NULL
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;			// dispose of rest of line
	}
	return ret_val;
}

struct book {
	char title[MAX_TITLE];
	char author[MAX_AUTHOR];
	float price;
};

int main() {

	struct book library[MAX_BOOKS] = {
		{ "Empty", "Empty", 0.0f, }
	};	/* array of book structures */

	int count = 0;

	while (1) {
		printf("Input a book title or press [Enter] to stop. \n>> ");
		//TODO: input titile
		if (s_gets(library[count].title, MAX_AUTHOR) == NULL)
			break;
		//TODO: break if the first character of the input title is '\0'
		if (library[count].title[0] == '\0')
			break;

		printf("Input the author.\n>> ");
		//TODO: input author name
		s_gets(library[count].author, MAX_AUTHOR);

		printf("Input the price.\n>> ");
		//TODO: input price
		int flag = scanf("%f", &library[count].price);
		
		//TODO: clear buffer
		while (getchar() != '\n')
			continue;	/* clear input line */
		
		count++;

		if (count == MAX_BOOKS) {
			printf("No more books.\n");
			break;
		}
	}

	if (count > 0) {
		printf("\nThe list of books: \n");
		for (int index = 0; index < count; ++index)
			printf("\"%s\" written by %s: $%.1f\n", library[index].title, library[index].author, library[index].price);
	}
	else
		printf("No books to show.\n");

	return 0;
}

// ������ ����ü�� �����Ϸ��� indexing�� �ؾ� �Ѵ�. 
// <= library[count].title[0]
//    �ε����� ����ü�� ������ member access operator�� �̿��ؼ� 
//    titile�� ������ �� �ִ�. 
//    title�� �迭�̴�. 
// 
// library[count].title[0] == '\0'
// <= title�� ù ��° ���ڿ� �����ϱ� ���ؼ� �̷��� �ε����ϰ�, 
//    �� ù ��° ���ڰ� null character '\0'�̸� break�Ѵ�. 
//    <= if (library[count].title[0] == '\0')
//           break;
// 
// �������� ũ�� ����� �κ��� ����. 
// s_gets() �Լ� ����ؼ� �Է� ������ �ȴ�. 
// 
// int flag = scanf("%f", &library[count].price);
// <= scanf() �Է��� ���� �Ŀ�,
// 
// while (getchar() != '\n')
//     continue;	/* clear input line */
// <= ���۸� ���� ������. 
// 
// �̰� �ܿ��� �ٸ� ������� © ���� ������, �̷��� while()������ ¥�� �� �����ϴ�. 
// 
// ����ü�� �迭 ���� ������ Ǯ�� �ô�.  
// ���� ���� �����͸� ó���� ��, �̷��� ����ü�� �迭�� ����� �� �ִ�. 