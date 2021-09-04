#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_TITLE 40	// 39 ���� + '\0'(null character)
#define MAX_AUTHOR 40	// 39 ���� + '\0'(null character)
#define MAX_BOOKS 3		/* maximum number of books */

// ����ü�� �迭 ���� ����
// 
// ������ �ϸ� ������ ������ ���.
// Input a book titile or press [Enter] to stop.
// <= ���͸� ������ �����Ѵ�. 
//    ����� ��, 
//    No more books. <= �̷� ������ ���. 
// >> å �̸��� �Է��Ѵ�. (���� ó���� �����Ѵ�)
// Input the author.
// >> ���� �̸��� �Է��Ѵ�. 
// Input the price
// >> å ������ �Է��Ѵ�.
// �ٽ� �Ʒ� ������ �߸鼭 �Է��� �ݺ��ȴ�.
// Input a book titile or press [Enter] to stop.
// <= �ٽ� å �̸��� �Է��� ���� �ְ� enter�� ġ�� ������ ���� �ִ�. 
// ���Ḧ �ϸ�, ������ ���� ����� �ȴ�. 
// The list of books:
// "A Song of Ice and Fire" written by George R. R. Martin: $100.0
// ...
// ...
// 
// �̷��� ����� �Ǵ� ���α׷��� ����ü�� �ۼ��϶�.

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
		//TODO: break if the first character of the input title is '\0'

		printf("Input the authorl.\n >> ");
		//TODO: input author name

		printf("Input the price.\n >> ");
		//TODO: input price
		//TODO: clear buffer

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

// scanf()�� ��ĭ�� �Է¹��� ���ϹǷ� ����� �� ����.
// fgets(st, n, stdin); n���� �Է� �ѵ� ����, stdin���� �ܼ� �Է�
//	��ĭ�� �ִ� ���ڿ��� new line�� �ִ� ������ �Է��� ���� �� �ִ�. 
//
  /*
	if (ret_val) {
		find = strchr(st, '\n');	// look for newline
		if (find)					// if the address is not NULL
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;			// dispose of rest of line 
  */
//
// <= �ٹٲ�(\n)�� ã�� �װ��� \0 null character�� �ٲ㼭, 
//    C���� ����ϴ� ���ڿ��� ����� �ִ� �κе� ������ �� �ִ�.
// 
// while (getchar() != '\n')
//    continue;
// <= (���� �׷��� ���� ��쿡��) buffer�� �� ���� ������. 
// 
// �� �Լ���, ��ĭ�� �ִ� ���ڿ��� new line�� ���� ������ �Է��� �޾Ƽ�, 
// �װ��� ������ st�� �����ϰ�, ������ �� �ִ� �Լ��̴�. 
// 
// �� �Լ��� �̿��ؼ� å �̸��� ������ �̸��� �Է� ������ �ȴ�. 
// 
// struct book {
//	  char title[MAX_TITLE];
//	  char author[MAX_AUTHOR];
//	  float price;
// };
// <= å �� ���� ������ �� �ʿ��� �������� ������ ����ü�� �����ߴ�. 
// 
//	struct book library[MAX_BOOKS] = { { "Empty", "Empty", 0.0f, } };	
//                                              /* array of book structures */
// <= ����ü�� �迭�� �����ߴ�. 
//    { { "Empty", "Empty", 0.0f, } }; �̷��� �ʱ�ȭ���� �� ���. 
//    struct book library[MAX_BOOKS]; �̷��� ���� �ϸ�, 
//    �ֱ� visual studio���� �ʱ�ȭ�� �� �� ��ٰ� Warning�� ����. 
//    �Է¹��� ���� ������ �ʱ�ȭ�� ���. 
// 
// int count = 0; �� �� �Է��� ������ ���� �ϹǷ� count ������ �����ϰ� �ʱ�ȭ�� �ش�.
//
// if (count == MAX_BOOKS) {
//  	printf("No more books.\n");
//  	break;
// }
// <= �ִ� �Է¹޴� ���� �����ϸ�, break�� ���� ������. 
// 
// TODO: input titile
//  Ÿ��Ʋ�� �Է� �޴´�.
// TODO: break if the first character of the input title is '\0'
//  �Է¹��� Ÿ��Ʋ�� ù ���ڰ� null character���, ����� �Է��� ���� ���� �ƴϰ�,
//  ����ڰ� ���Ḧ �ϱ� ���ؼ� enter�� ���� ���̹Ƿ� break�� while()������ ������.
//  <= '\0'�� �ԷµǸ� break�Ǵ� �� ��� �ڵ����� ����� ����. 
// 
// ����ڰ� ���Ḧ ���� �ʾҴٸ�, ����� �ϰڴٴ� ������ ���� ���̹Ƿ�, 
// printf("Input the authorl.\n >> "); //TODO: input author name
//  <= ������ �̸��� �Է� �ް�,  
//
// printf("Input the price.\n >> ");
//	TODO: input price
//   <= ������ �Է¹޴´�. ���ڿ��� �ƴ� float�� �Է��� �޴´�. 
//      scanf()�� �Է¹޴� �� ���� ���ϴ�. 
//	TODO: clear buffer
//   <= scanf()�� �Է��� ���� �Ŀ��� ���۸� ���� ��� �Ѵ�. 
// 
// count++;
//
// if (count == MAX_BOOKS) {
//     printf("No more books.\n");
//	   break;
// }
// <= �ִ�� �Է¹��� �� �ִ� ���� �����ϸ�, break�� ���� ������. 
// 
// å�� �� �� �̻� �Է��� �޾Ҵٸ�,  
// if (count > 0) {
//	   printf("\nThe list of books: \n");
//	   for (int index = 0; index < count; ++index)
//		   printf("\"%s\" written by %s: $%.1f\n", library[index].title,			 library[index].author, library[index].price);
// }
// else
//     printf("No books to show.\n");
// 
// <= å�� ������ ����Ѵ�. 
//    ����ü�� �迭�� ���� ���� indexing�� �ϰ� ����� �̷��� �����ϸ� �ȴ�.  
//    
// �� TODO �κи� �����ϸ�, ���� ������ �ڵ带 �ϼ��� �� �ִ�. 
// ������ ������ ���� �ٶ���. 