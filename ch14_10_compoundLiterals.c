#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 31

// ���� ���ͷ�, Compound Literals
// 
// ����ü�� ���� �ӽ÷� ��� ����� �� 
// ���Ѱ� Ȱ���� �� �ִ� ���� ���ͷ��� ���ؼ� ���� ����.

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	//char* title;			// Not recommended
	//char* author;			// Not recommended
	float price;
};

struct rectangle {
	double width;
	double height;
};

double rect_area(struct rectangle r) {
	return r.width * r.height;
}

double rect_area_ptr(struct rectangle* r) {
	return r->width * r->height;
}

int main() {
	
	struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f };

	/*
		Compound literals
		- Temporary structure values
	*/

	//book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3f };//Error

	strcpy(book_to_read.title, "Alice in Wonderland");
	strcpy(book_to_read.author, "Lewis Carroll");
	book_to_read.price = 20.3f;

	struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
	book_to_read = book2;

	book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };

	printf("%s %s\n", book_to_read.title, book_to_read.author);

	struct rectangle rec1 = { 1.0, 2.0 };
	double area = rect_area(rec1);
	area = rect_area((struct rectangle) { 1.0, 2.0 });

	area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = 2.0 }); // Designated initializers
	printf("%f\n", area);

	return 0;
}
 
// char* title;			// Not recommended
// char* author;			// Not recommended
// <= �̷� ��Ÿ���� �� ��õ���� �ʴ����� �� ���ǿ��� ����ߴ�. 
// 
// struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f };
// <= ����ü�� �ʱ�ȭ�� ���� {} �߰�ȣ �ȿ��� �پ��� �ڷ����� ���� ����� ���
//    �Ѳ����� �ʱ�ȭ�� �� �� �ִ�. 
//    = �� �����Ƿ� �����̶�� ������ ���� �ִµ�, �ʱ�ȭ�� ���������� ���԰� �ٸ��� .
// 
// �� �� �ʱ�ȭ�� ���� �Ŀ���, �ٽ� �ʱ�ȭ�� �� �� ����. 
// book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3f };//Error
// <= �ʱ�ȭ�� ���� �Ŀ� �̷� ������ ���� �ٲٷ��� �ϸ�(������ �Ϸ��� �ϸ�) �� �ȴ�. 
//    ���������� ����� �� �ȴ�. 
// 
// �׷��� �ʱ�ȭ�� ���� ���� ��� �ٲٴ°�?
// 
// strcpy(book_to_read.title, "Alice in Wonderland");
// strcpy(book_to_read.author, "Lewis Carroll");
// book_to_read.price = 20.3f;
// <= �̷��� ��� ������ ���ϴ� ���� ������ �ش�. 
//    ������, �̷��� �ٲٴ� ���� �� ���ŷӴ�. 
// 
// �� �ٸ� ����� ������ �ִ°�?
// 
// struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
// book_to_read = book2;
// <= ������ �ϳ� �� ����� �� ������ �ʱ�ȭ�� �ش�. 
//    �׸��� �� ������ �����ؼ� book_to_read�� ������ �� �ִ� ����� �ִ�. 
//    ���Ӱ� �ʱ�ȭ�Ǵ� ��� ���� book_to_read�� ���� ���� �� �����Ƿ�, 
//    ������ �ϳ� ���� �� ������ �ְ�, 
//    �� ���� book2�� book_to_read�� �����ؼ� �ִ� ����̴�. 
//    book2��� ���� �ϳ��� ���İ����Ƿ� ���� ���ŷӴ�.
//    �̷� ���İ��� �ӽ� ������ ����� ���� ������ ������ ���� �ִ�. 
// 
// �̷� �� ���� ���ͷ��� ����� �� �ִ�. 
// 
// book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };
// <= �տ� ��ȣ(struct book)�� �ְ�, ��ȣ �ȿ� �ڷ���(struct book)�� �ִ´�. 
//    �׸��� �ڿ��ٰ� ����ü�� �ʱ�Ȱ �� �־��� ��ó�� �߰�ȣ {} �ȿ� 
//    ��� ���� �־� �ָ� �ȴ�. 
//    <= �̷��� �ϸ� ���ο� ��� ���� book_to_read�� ����. 
//       ������ �����ϴ�. 
//       ���������� ���� ��, 
//       { "Alice in Wonderland", "Lewis Carroll", 20.3f };��
//       ���ͷ��� �����̴�. 
// 
//       ����ü�� Ư���� ���� �ٸ� �ڷ����� ����� ���� �� �ִ�. 
//       �پ��� �ڷ����� ���ͷ��� ���� ���� ���̴�. 
//       <= ���� ���ͷ�, compound literals�̶�� �θ���.
// 
// ���������� �˾� �ξ�� �� ������, 
// (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };�� 
// L-value�̴�. 
// <= R-value�� �ƴϴ�. 
// 
// �׷��� ����ִ� ������ �����. 
// 
// rect_area() �簢���� ���̸� ���ϴ� �Լ��� ȣ���ϰ� �ʹٰ� �� ����. 
// �տ��� �� ����, rect_area() �Լ��� ����ü ������ argument�� �־� ��� 
// �۵��� ��ų ���� �ִ�. 
// 
// �̶�, 
// struct rectangle rec1 = { 1.0, 2.0 };
// <= ����ü ���� rec1�� �����ϰ� �ʱ�ȭ�� �ϸ�, 
// 
// double area = rect_area(rec1);
// <= ���⿡ rec1�� �־� �� �� �ִ�. 
// 
// ���� ����ü ���� rec1�� �뵵�� �簢���� ���̸� ���ϴ� �뵵 �ܿ��� ���ٸ�, 
// rec1�� ����ü ������ �����ϴ� ���� ���� ���ŷӱ⵵ �ϰ� ������ ���� �ִ�. 
// 
// �̷� ��, 
// area = rect_area((struct rectangle) { 1.0, 2.0 });
// <= �̷��� ���� ���ͷ��� ����� ���� �ִ�. 
//    (struct rectangle) { 1.0, 2.0 }�� L-value�̴�. 
//    ����Ե� �̰��� �ּҸ� ������ �� �ִ�. 
// 
// area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = 2.0 });
// <= ���� ���ͷ��� �ּҸ� �����ͼ� rect_area_ptr() �Լ����� ������ �ְ� �ִ�. 
//    �� �̰��� L-value�ʹ� �ٸ� ����������, 
//    Designated initializers�� ����ؼ� ���� �־� �� �� �ִ�. 
// 
//    �� ���� ���ͷ��� L-value �޸��� ������ �����ϰ� �ִ� �����̱� ������, 
//    &(struct rectangle) {...}; �̷��� �ּҸ� ������ �� �� �ִ� ���̴�. 
//  
//    rect_area_ptr ���� �����͸� �Ű������� ������ �ִ� �Լ��� ȣ���� ����, 
//    ����� �� �ִ�. 
// 
// ���� ���ͷ� Compound Literals�� ���ؼ� ���� �ô�. 