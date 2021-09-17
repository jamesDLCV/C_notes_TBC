#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 31

// 복합 리터럴, Compound Literals
// 
// 구조체의 값을 임시로 잠깐 사용할 때 
// 편한게 활용할 수 있는 복합 리터럴에 대해서 살펴 본다.

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
// <= 이런 스타일은 왜 추천하지 않는지는 앞 강의에서 언급했다. 
// 
// struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f };
// <= 구조체를 초기화할 때는 {} 중괄호 안에다 다양한 자료형을 가진 멤버를 묶어서
//    한꺼번에 초기화를 할 수 있다. 
//    = 가 있으므로 대입이라고 생각할 수도 있는데, 초기화는 문법적으로 대입과 다르다 .
// 
// 한 번 초기화가 끝난 후에는, 다시 초기화를 할 수 없다. 
// book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3f };//Error
// <= 초기화가 끝난 후에 이런 식으로 값을 바꾸려고 하면(대입을 하려고 하면) 안 된다. 
//    문법적으로 허용이 안 된다. 
// 
// 그러면 초기화가 끝난 값을 어떻게 바꾸는가?
// 
// strcpy(book_to_read.title, "Alice in Wonderland");
// strcpy(book_to_read.author, "Lewis Carroll");
// book_to_read.price = 20.3f;
// <= 이렇게 멤버 각각에 원하는 값을 대입해 준다. 
//    하지만, 이렇게 바꾸는 것은 좀 번거롭다. 
// 
// 또 다른 방법은 무엇이 있는가?
// 
// struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
// book_to_read = book2;
// <= 변수를 하나 더 만들고 그 변수를 초기화해 준다. 
//    그리고 그 변수를 복사해서 book_to_read에 대입을 해 주는 방법이 있다. 
//    새롭게 초기화되는 멤버 값을 book_to_read에 직접 넣을 수 없으므로, 
//    변수를 하나 만들어서 그 변수에 넣고, 
//    그 변수 book2를 book_to_read에 복사해서 넣는 방법이다. 
//    book2라는 변수 하나를 거쳐갔으므로 조금 번거롭다.
//    이런 거쳐가는 임시 변수를 만드는 것이 낭비라고 생각할 수도 있다. 
// 
// 이럴 때 복합 리터럴을 사용할 수 있다. 
// 
// book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };
// <= 앞에 괄호(struct book)가 있고, 괄호 안에 자료형(struct book)을 넣는다. 
//    그리고 뒤에다가 구조체를 초기활 때 넣었던 것처럼 중괄호 {} 안에 
//    멤버 값을 넣어 주면 된다. 
//    <= 이렇게 하면 새로운 멤버 값이 book_to_read에 들어간다. 
//       대입이 가능하다. 
//       문법적으로 봤을 때, 
//       { "Alice in Wonderland", "Lewis Carroll", 20.3f };은
//       리터럴의 묶음이다. 
// 
//       구조체는 특성상 서로 다른 자료형을 멤버로 가질 수 있다. 
//       다양한 자료형의 리터럴을 묶어 놓은 것이다. 
//       <= 복합 리터럴, compound literals이라고 부른다.
// 
// 문법적으로 알아 두어야 할 사항은, 
// (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };은 
// L-value이다. 
// <= R-value가 아니다. 
// 
// 그래서 재미있는 성질이 생긴다. 
// 
// rect_area() 사각형의 넓이를 구하는 함수를 호출하고 싶다고 해 보자. 
// 앞에서 봤 듯이, rect_area() 함수는 구조체 변수를 argument로 넣어 줘야 
// 작동을 시킬 수가 있다. 
// 
// 이때, 
// struct rectangle rec1 = { 1.0, 2.0 };
// <= 구조체 변수 rec1를 선언하고 초기화를 하면, 
// 
// double area = rect_area(rec1);
// <= 여기에 rec1을 넣어 줄 수 있다. 
// 
// 만약 구조체 변수 rec1의 용도가 사각형의 넓이를 구하는 용도 외에는 없다면, 
// rec1을 구조체 변수로 선언하는 것은 조금 번거롭기도 하고 낭비일 수도 있다. 
// 
// 이럴 때, 
// area = rect_area((struct rectangle) { 1.0, 2.0 });
// <= 이렇게 복합 리터럴을 사용할 수도 있다. 
//    (struct rectangle) { 1.0, 2.0 }은 L-value이다. 
//    놀랍게도 이것의 주소를 가져올 수 있다. 
// 
// area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = 2.0 });
// <= 복합 리터럴의 주소를 가져와서 rect_area_ptr() 함수에게 전달해 주고 있다. 
//    또 이것은 L-value와는 다른 성질이지만, 
//    Designated initializers를 사용해서 값을 넣어 줄 수 있다. 
// 
//    이 복합 리터럴이 L-value 메모리의 공간을 차지하고 있는 존재이기 때문에, 
//    &(struct rectangle) {...}; 이렇게 주소를 가지고 올 수 있는 것이다. 
//  
//    rect_area_ptr 같이 포인터를 매개변수로 가지고 있는 함수를 호출할 때도, 
//    사용할 수 있다. 
// 
// 복합 리터럴 Compound Literals에 대해서 살펴 봤다. 