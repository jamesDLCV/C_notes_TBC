#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Structures, 구조체의 기본적인 사용법
// 구조체 선언, 초기화, 맴법 접근 방법을 문법 위주로 살펴 본다. 

#define MAX 41

struct person	/* Person is a tag of structure */
{
	char name[MAX];		// member
	int age;			// member
	float height;		// member
};

// 코딩 스타일은 팀과 협의해서 결정한다. {}의 위치, 대문자 tag 혹은 소문자 tag 등.
/*
struct Person {
	...
};
*/

int main() {

	int flag;	// Receives return value of scanf()

	/* Structure variable */
	struct person genie;

	/* dot(.) is structure membership operator (member access operator, member operator*/
	strcpy(genie.name, "Will Smith");
	//strncpy(genie.name, "Will Smith", MAX);

	genie.age = 1000;

	// dot(.) has higher precedence than &
	flag = scanf("%f", &genie.height);	// &(genie.height)
	printf("%f\n", genie.height);

	/* Initialization */

	struct person princess = { "Naomi Scott", 18, 160.0f };

	struct person princess2 = {
		"Naomi Scott",
		18,
		160.0f
	};

	strcpy(princess.name, "Naomi Scott");
	princess.age = 18;
	princess.height = 160.0f;

	/* Designated initializers */

	struct person beauty = {
		.age = 19,
		.name = "Bell",
		.height = 150.0f
	};

	//struct person beauty = { .age = 19, .name = "Bell",	.height = 150.0f };

	/* Pointer to a structure variable */

	struct person* someone;

	someone = &genie;
	//someone = (struct Person*)malloc(sizeof(struct Person)); // and free later

	/* Indirect member(ship) operator (or structure pointer operator) */

	someone->age = 1001;	// arrow(->) operator
	printf("%s %d\n", someone->name, (*someone).age);

	/* Structure declaration in a function */

	struct book
	{
		char title[MAX];
		float price;
	};

	/* No tag */

	struct {
		char farm[MAX];
		float price;
	} apple, apple2;

	strcpy(apple.farm, "Trade Joe");
	apple.price = 1.2f;

	strcpy(apple2.farm, "Safeway");
	apple2.price = 5.6f;

	/* typedef and structure */

	typedef struct person my_person;

	my_person p3;

	typedef struct person person;

	person p4;

	typedef struct {
		char name[MAX];
		char hobby[MAX];
	} friend;

	friend f4;

	return 0;
}

// struct person
// <= struct는 structure의 약자이다.
//    person은 구조체의 이름으로 사용하고 싶은 단어를 쓰면 된다. 
//    person은 구조체의 tag라고도 한다. <= 이름으로 생각하면 된다. 
//    문법상 인식자를 정하는 것과 똑같은 규칙이 적용된다. 
// 
// 그다음, 
// 중괄호 안에 멤버를 선언해 주면 된다. 
// <= 구조체 person의 멤버로 사용될 변수를 써 준다. 선언만 해 준다. 
//    구조체 안에서 멤버를 선언해 주는 행위만으로는 메모리를 갖지 않는다. 
//	  구조체의 변수가 선언이 될 때, 메모리를 갖게 된다. 
//    구조체의 멤버를 선언하는 단계에서는 메모리를 갖지 않는다. 
//    이런 구조로 구조체가 만들어질 것이라고 선언만 해 두는 것이다. 
//    쿠키를 찍어내기 전에 쿠키 틀을 만들어 두는 것이다. 모양만 잡아 두는 것이다. 
//    
// 구조체의 메모리에 대해서는 다음 강의에서 다룬다. 
// 
// C++로 가면, 구조체와 객체 template을 만드는 클래스가 있는데, 
// 클래스를 만들 때는 첫 글자를 대문자로 쓰는 게 일반적이다. 
// 클래스와 structure는 유사성이 많이 있다. 
// 
// C++에서 구조체를 사용할 때는 tag의 첫 글자를 대문자로 사용하는 경우가 많다. 
// 이것도 팀원과 협의해서 결정할 문제이다. 무엇이 정답인지는 정해져 있지 않다. 
// 
// int flag;	// Receives return value of scanf()
// <= scanf()의 반환값을 받기 위해서 선언한 변수이다. 
// 
// 구조체의 변수 선언하는 방법:
// struct person genie; 
// <= struct를 써 준다. 그 다음 tag를 붙인다. 여기에서 tag는 person(구조체의 이름),
//    struct person 이 두 개를 합쳐서 마치 자료형인 것처럼 사용한다. 
//    strucut person (자료형) 뒤에 genie 변수를 선언한다. 
//    <= struct의 멤버 name, age, height의 메모리가 genie 변수를 선언하는 순간
//       할당이 된다. 
// 
// 구조체 안에 name, age, height 세 가지 멤버가 있다. 
// 이 멤버에 접근해서 사용해야 할 텐데, 
// 이 때 사용하는 연산자가 structure membership operator이다. 
// 좀 더 기능적으로 보면 member access operator라고도 한다.
// (멤버에 acess하기 위한 연산자) <= 줄여서 member operator라고도 한다.
// 
// genie.name <= 이렇게 struct의 name 멤버에 접근한다. 
// 
// strcpy(genie.name, "Will Smith");
// strncpy(genie.name, "Will Smith", MAX);
// <= 이 두 가지 모두 사용할 수 있다.  
//    name은 char의 배열이었으므로, strcpy 또는 strncpy를 사용할 수 있다. 
//    문자열을 다루는 문법은 이전 강의에서 다루었다. 
// 
// genie.age = 1000; <= age는 int이므로 이렇게 1000이라는 값을 대입해 줄 수 있다.
// <= age에 마우스를 hover over해 보면, int person::age라고 뜬다. 
//    이는 age라는 변수가 person의 구조체라는 뜻이다. 
//    age를 genie라는 변수를 통해서 접근하고 있다. 
// 
// name, age, height 세 개가 묶여서 하나의 structure로 만들어져 있고, 
// 그 structure 구조 안에서 각각의 멤버에 접근해서 사용하는 개념이다. 
// 그러므로 membership operator를 통해서 접근해야 한다. 
// 
// 다음 강의에서 메모리 구조를 다룬다. 
// 
// dot(.) has higher precedence than &
// <= dot operator는 &(address of) operator보다 연산자 우선 순위가 높다. 
// 
// &genie.height
// <= height 멤버에 먼저 접근을 한 후에 주소를 가지고 온다. 
//    &(genie.height)와 동일하다.
// 
// 구조체 변수 structure variable을 초기화하는 방법
// 
// struct person princess = { "Naomi Scott", 18, 160.0f };
// <= princess라는 구조체 변수를 선언하면서 동시에, 초기화까지 하고 있다. 
//    structure variable의 이름은 princess이다. 
//    이렇게 { } 안에서처럼 초기화할 수 있다. 
//    배열과 비슷한 모습이지만, 배열에서는 원소의 자료형이 모두 동일해야 한다. 
//    즉 int 배열이라면 원소가 모두 int여야 한다. 
//    하지만, 구조체는 다양한 자료형들로 이루어진 멤버들의 집합이므로, 
//    첫 번째 원소는 문자열, 두 번째 원소는 int, 세 번째 원소는 float이 가능하다.  
//    name이 첫 번째, age가 두 번째, height가 세 번째가 된다. 
// 
//    <= 주의할 점은 struct의 멤버를 선언한 순서와 초기화해 주는 순서가 동일해야 한다. 
// 
//	struct person princess2 = {
//		"Naomi Scott",
//		18,
//		160.0f
//	};
//  <= 코딩 스타일에 따라서 이렇게 처리할 수도 있다. 
//     struct person princess = { "Naomi Scott", 18, 160.0f };와 동일하다.
//     컴파일러가 빈칸과 줄바꿈을 모두 없애 버리므로 이 두 개는 동일한 문법이다. 
// 
// 위과 같이 선언을 하면서 동시에 초기화하는 방법도 있고, 
// 다음과 같이 일단 선언이 된 다음에 값들을 하나 하나 대입을 해 주는 방법도 있다. 
// 
// strcpy(princess.name, "Naomi Scott");
// princess.age = 18;
// princess.height = 160.0f;
//   
// 구조체는 서로 자료형들 다른 멤버들이 여려 개 있으므로 조금 헤깔린다. 
// 그래서 Designated initializers라는 문법이 있다. (C99, C11)
// 
// 	struct person beauty = {
//		.age = 19,
//		.name = "Bell",
//		.height = 150.0f
//	};
// 
// 어떤 멤버를 어떤 값으로 초기화할지 지정해 줄 수 있다. 
// 장점은 순서가 바뀌어도 된다. (어떤 멤버에게 어떤 값이 대응이 될지가 지정돼 있으므로)
// 위에서 초기화를 해 줄 때는 순서가 바뀌면 안 됐다. 
// 
// struct person beauty = { .age = 19, .name = "Bell", .height = 150.0f };
// <= 이렇게 한 줄로 초기화를 해도 된다. 
//    하지만 콤마(,)와 dot(.)이 인접해 있어서 가독성이 떨어질 수 있다. 
//    줄을 바꿔 주는 게 조금 더 가독성이 높다. 
// 
// 포인터에 대해서도 살펴 보자. 당연히 포인터로도 선언할 수 있다. 
// 
// /* Pointer to a structure variable */ 
// 구조체 변수에 대한 포인터를 선언할 때에는, 
// struct person* someone;
//	<= struct person이 자료형인 것처럼 이것에다가 *를 붙여 준다. 
//     그러면 person이라는 tag를 갖는 구조체 변수의 포인터가 된다. 
// 
// someone = &genie;
// <= &(address of) 연산자를 이용해서 이미 선언이 된 다른 structure variable의
//    주소를 가져다가 이렇게 대입할 수 있다. 
// 
// someone = (struct Person*)malloc(sizeof(struct Person)); // and free later
// <= 동적 할당을 이용해서 메모리 할당이 되면서 주소를 가져다가 
//    이렇게 넣을 수도 있다. 여러 용법을 뒤에서 다시 소개한다. 
// 
// 그 외에는 일반적인 포인터의 개념과 비슷한데, 다른 점이 하나 있다. 
// membership operator가 달라진다. 
// 
// someone->age = 1001;
// <= someone은 포인터이다. 
//    포인터일 경우에는 연사자로 dot(.) 대신 화살표(->)를 사용한다. 
//    포인터를 통해서 access하는 것이기 때문에, 
//    Indirect member(ship) operator (or structure pointer operator)
//    라는 이름을 사용한다. Indirect member operator가 이해가 좀 쉬울 것 같다. 
// 
// 포인터일 경우에는 -> (arrow operator)를 쳐 주고, 
// 일반 변수일 경우에는 .을 찍어 주면 멤버에 접근할 수 있다. 
// 
// someone->name; 이렇게 화살표 연산자로 멤버에 접근할 수도 있고,
// (*someone).age; 이렇게 someone을 indirection한 다음에 dot operator로 멤버에 
// 접근할 수도 있다. 
// 이 두 가지 모두 memeber access할 때 쓰인다. 
// 
// 구조체를 함수 안에서 선언할 수도 있다. 
// struct book
// {
//     char title[MAX];
//	   float price;
// };
// <= 함수 안에 이렇게 구조체를 선언하고 그 함수 안에서만 사용한다. 
//    그 함수를 벗어나면 이 구조체는 사용할 수 없다. 
// 
// tag를 사용하지 않을 수도 있다. 
// 
// struct {
//     char farm[MAX];
//     float price;
// } apple, apple2;
// <= tag가 있어야 할 자리에 아무 것도 없다. 
//    tag가 없으면 structure variable을 어떻게 사용하는가?
//    중괄호가 끝나는 자리에 이렇게 structure variables를 직접 입력해서 
//    선언을 해 버릴 수도 있다. 많이 사용하는 용법이다. 
//    <= tag 없이 structure variable만 사용한다. 
//    잠깐 쓰고 말 구조체라면 이렇게 쓸 수도 있다. 
//    apple3를 또 선언하고 싶으면, 
// 
// struct {
//     char farm[MAX];
//     float price;
// } apple3; 
// 
//    이렇게 또 적어 줘야 하므로 번거로울 수 있다. 
// 
// 구조체를 사용자가 정의한 새로운 자료형인 것처럼 사용할 수 있다. 
// structure variable을 정의할 때에는, 
// 앞에다가 struct를 꼭 붙여 줘야 했다. 
// 
// typedef를 사용하면 그 struct를 없앨 수 있다. 
// 
// typedef struct person my_person;
// <= struct person이라는 타입을 my_person으로 선언을 해 준다. 
//    그러면 my_person이라는 자료형이 있는 것처럼, 
// my_person p3;
//    <= 이렇게 변수 p3를 선언할 수 있다. 
//       내부적으로는 struct person이라는 struct의 변수이지만, 
//       코드를 읽을 때는 my_person이라는 자료형의 변수로 간략하게 생각할 수 있다. 
// 
// typedef struct person person;
// <= 문법상 struct person을 typedef로 그냥 person이라는 자료형인 것처럼
//    이름을 바꿔 버릴 수도 있다. 
//    이렇게들 더 많이 사용한다.   
// person p4;
// <= 문법상 이렇게 사용할 수 있다는 것도 알아 둬라. 
//
// 구조체를 선언할 때 아예 이렇게 typedef로 선언할 수도 있다. 
// 
// typedef struct {
//     char name[MAX];
//	   char hobby[MAX];
// } friend;
//
// friend f4;
// 
// <= struct 다음에 tag가 없다. 
//    struct 뭐뭐({})를 friend라는 타입 이름으로 선언을 하고, 
//    friend가 마치 새로운 자료형인 것처럼 이렇게 변수로 선언할 수 있다. 
//    이 용법도 많이 사용된다. 
// 
// 구조체의 기본적인 사용 방법에 대해서 살펴 봤다. 