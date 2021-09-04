#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 구조체의 메모리 할당, memory allocation
//
// 배열에서는 자료형이 같은 원소들이 배열돼 있는 형태였으므로 이해가 쉬웠으나
// 구조체에서는 자료형이 서로 다른 멤버들이 나열돼 있는 형태이므로, 
// 내부적으로 효율성을 높이기 위해서 메모리 padding 패딩이라는 것을 사용한다. 

int main() {
	/*
		Well aligned structure
	*/

	struct Aligned
	{
		int a;
		float b;
		double c;
	};

	/*
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
	|int a  |float b|double c             |
	4 + 4 + 8 = 16
	*/

	struct Aligned a1, a2;

	printf("struct Aligned a1\n");
	printf("Sizeof %zd\n", sizeof(struct Aligned));
	printf("%lld\n", (long long)&a1);
	printf("%lld\n", (long long)&a1.a);
	printf("%lld\n", (long long)&a1.b);
	printf("%lld\n", (long long)&a1.c);

	printf("\nstruct Aligned a2\n");
	printf("Sizeof %zd\n", sizeof(a2));
	printf("%lld\n", (long long)&a2);
	printf("%lld\n", (long long)&a2.a);
	printf("%lld\n", (long long)&a2.b);
	printf("%lld\n", (long long)&a2.c);

	/*
		padding (struct member alignment)
		- 1 word: 4 bytes in x86, 8 bytes in x64
	*/

	struct Padded1 {
		char a;
		float b;
		double c;
	};

	/* Without padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|a|float b|double c          | ?  ?  ?
	1 + 4 + 8 = 13	
	*/

	/* With padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|char a |float b|double c             | 
	4(char?) + 4 + 8 = 16
	*/

	struct Padded1 p1;

	printf("\nstruct Padded1 p1\n");
	printf("Sizeof %zd\n", sizeof(p1));	// 4 + 4 + 8
	printf("%lld\n", (long long)&p1);
	printf("%lld\n", (long long)&p1.a);
	printf("%lld\n", (long long)&p1.b);
	printf("%lld\n", (long long)&p1.c);

	struct Padded2 {
		float a;				
		double b;
		char c;
	};

	/* 
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|float a        |double b             |char c
	8(float?) + 8 + 8 = 24
	*/

	struct Padded2 p2;

	printf("\nstruct Padded2 p2\n");
	printf("Sizeof %zd\n", sizeof(p2));	// 4 + 4 + 8
	printf("%lld\n", (long long)&p2);
	printf("%lld\n", (long long)&p2.a);
	printf("%lld\n", (long long)&p2.b);
	printf("%lld\n", (long long)&p2.c);

	struct Padded3 {
		char a;
		double b;
		double c;
	};

	/*
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|char a         |double b             |double c
	8(char?) + 8 + 8 = 24
	*/

	struct Padded3 p3;

	printf("\nstruct Padded3 p3\n");
	printf("Sizeof %zd\n", sizeof(p3));	// 4 + 4 + 8
	printf("%lld\n", (long long)&p3);
	printf("%lld\n", (long long)&p3.a);
	printf("%lld\n", (long long)&p3.b);
	printf("%lld\n", (long long)&p3.c);

	struct Person {
		char name[41];	// member
		int age;		// member
		float height;	// member
	};

	struct Person mommy;

	printf("\nstruct Person\n");
	printf("Sizeof %zd\n", sizeof(mommy));	// 41 + 4 + 4 = 49?
	printf("%lld\n", (long long)&mommy.name[0]);
	printf("%lld\n", (long long)&mommy.age);
	printf("%lld\n", (long long)&mommy.height);
	
	struct Person f[4];

	printf("\nSiezof a structure array %zd\n", sizeof(f));

/*
|f[0].name |f[0].age |f[0].height|... ...|f[3].name |f[3].age |f[3].height|
*/

	return 0;
}

// struct Aligned
// {
//  	int a;
//  	float b;
//  	double c;
// };
// 
// <= 구조체가 이렇게 4bytes, 4bytes, 8bytes 세 개의 멤버를 가지고 있다. 
//    총 16bytes의 멤버를 가지고 있다. 
// 
	/*
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
	|int a  |float b|double c             |
	4 + 4 + 8 = 16
	*/

//  <= 이와 같은 순서로 4바이트, 4바이트, 8바이트로 메모리에 들어 있을 것이다. 
// 
// 하지만 이렇게 구조체를 선언하는 것만으로는 메모리를 차지하지 않는다. 
// 변수를 선언하는 것처럼 보여서 메모리 오브젝트가 생성이 될 것이라고 생각할 수 있지만, 
// 이렇게 메모리를 사용하겠다, 
// 이렇게 구조가 짜여져 있는 데이터 오브젝트를 만들겠다는 
// 템플릿(틀)만 제시하는 것이다. 
// 
// struct Aligned a1, a2;
// <= 실제로 구조체 변수가 만들어질 때, 메모리가 실제로 자리가 잡히고,
//    데이터 오브젝트가 생성이 되고, 
//    그 데이터 오브젝트를 a1, a2라는 인식자를 통해서 접근해서 사용할 수 있게 된다. 
// 
// 메모리를 얼마나 사용하는지 sizeof를 찍어 본다. 
// 
//struct Aligned a1
//Sizeof 16
//337150671272
//337150671272
//337150671276
//337150671280
//
//struct Aligned a2
//Sizeof 16
//337150671320
//337150671320
//337150671324
//337150671328
//
// a1 자체의 주소와 a1.a(a1의 첫 번째 멤버)의 주소가 동일하다. 
// 다음 주소와의 차이가 4bytes씩 생긴다. 
// int a와 float b가 각각 4bytes씩 차지하고 
// double c가 나머지 8bytes를 차지하는 것이다. 
//
// 구조체를 선언한 것은 이렇게 메모리를 사용하겠다라고 틀을 선언한 것이고, 
// 실제로 쿠키 틀을 이용해서 쿠키를 찍어내는 것은, 
// struct Aligned a1, a2; 이렇게 변수 a1, a2를 선언하는 것이다. 
// a1과 a2는 동일한 메모리 형태로 사용된다. 
// 
// 메모리 패딩 padding에 대해서 살펴 보자. 
// 조금 의외의 사태가 발생한다. 
// 
// 	struct Padded1 {
//		char a;
//		float b;
//		double c;
//	};
// 
// <= 이 struct를 보면 1 + 4 + 8 = 13 bytes이지만,
//    사이즈를 실제로 찍어 보면, 16 bytes가 나온다. 
//    기대와는 다르게 13 바이트가 아닌 16 바이트가 나온다. 
// 
// 컴파일러가 char a에다가 빈공간 세 개를 넣어 버린다. 

	/* With padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|char a |float b|double c             |
	4(char?) + 4 + 8 = 16
	*/

// 그래서 p1.a는 char 임에도 불구하고 4 bytes의 공간을 갖는다. 
// 컴파일러가 3 bytes를 더 넣어 준 것이다. padding을 넣어 준 것이다. 
// 1 byte 짜리가 마치 4 bytes 짜리인 것처럼 안 쓰는 공간을 억지로 넣어 줬다. 
// 
// 왜 컴파일러가 이러한 padding을 넣어 주는가?
// 
    /*
		padding (struct member alignment)
		- 1 word: 4 bytes in x86, 8 bytes in x64
	*/
// 
// 패딩은 struct member alignment라고도 한다. 
// alignment는 줄맞춤을 해 주는 것이다. 
// 
// 줄맞춤은 왜 해 주는가?
// 
// 정보를 표현하는 최소 단위는 bit, 0이냐 1이냐를 표현하는 단위.
// 메모리에서 주소를 배정하는 최소 단위가 8 bits, 8 bits를 묶어서 1 byte라고 한다.
// 
// 메모리와 CPU가 데이터를 주고 받을 때, 1 bit나 1 byte씩 주고 받지 않는다. 
// 데이터를 묶어서 보내야 효율성이 높다. 
// 그러면 얼마나 많은 양의 데이터를 묶어서 보낼까?
// 
// 데이터를 묶어서 보내는 단위가 word이다. 
// 1 word: 4 bytes in x86, 8 bytes in x64
// <= 32비트에서는 4 바이트, 64비트에서는 8 바이트이다. 
// 
// 예를 들어 4명씩 탈 수 있는 놀이기구에서 혼자 온 사람이 있고 뒤에 4명의 가족이 있다면,
// 한 사람을 먼저 태우고 세 자리는 비워 둔 채로 뒷줄의 4인 가족을 태우게 된다. 
// 
// 데이터를 보낼 때 8 바이트씩 보낸다고 생각해 보자,
// 패딩을 하지 않는다면, 
// 제일 처음 char 1바이트를 넣고, 그 다음 float b를 넣는다. 그럼 3바이트가 남는다.
// 만약 남는 3 바이트 공간에 double을 집어 넣는다면, 
// 나머지 5 바이트는 다음 메모리에 저장이 된다. 짤리게 된다. 
// 그리고 맨 마지막도 애매해진다. 
// 
	/* Without padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|a|float b|double c          | ?  ?  ?
	1 + 4 + 8 = 13
	*/
// 이와 같이 패딩을 안 해 주면 효율성이 높지 않게 된다. 
// 마지막에 빈공간이 생길 것이라면, 이 빈공간을 char 공간에 넣어 줘서,
// 줄을 맞춰 주겠다는 것이다. 
// 그러면 double을 연산할 때 효율성이 높을 것이라는 게 기본적인 아이디어이다. 
// 
	/* With padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|char a |float b|double c             |
	4(char?) + 4 + 8 = 16
	*/
// <= 이렇게 char a 공간에다가 빈공간 세 개를 넣어 준 것이다. 
//    그러면 char 이 원래의 공간 1 바이트에다가 3 바이트 padding, 
//    총 4 바이트가 되고 거기에다가 float 4 바이트를 더해서 총 8 바이트가 된다. 
// 
//    이 8 바이트를 묶어서 한 번 보내고, 
//    그 다음에 double c 8 바이트를 보내면, 
//    cpu 입장에서는 깔끔하게 받아서 깔끔하게 계산을 할 수 있다. 
// 
// 패딩이 없어서 8 바이트를 묶는 단위가 without padding에서처럼 짤려 버리면, 
// (패딩이 없어서 alignment가 잘 되지 않는다면)
// 8 바이트 단위가 짤리기 때문에 cpu 입장에서는 난감할 수 있다. 
// <= 효울이 떨어지게 된다. 
//    그러므로 padding이 필요하다로 정리해 두자. 
// 
// 	struct Padded1 {
//		char a;
//		float b;
//		double c;
//	};
// <= 에서 char, float, double 멤버의 순서를 바꿔도 효율성이 달라진다. 
// 
	/*
		struct Padded2 {
			float a;
			double b;
			char c;
		};
	*/

// <= 멤버의 순서를 바꿨다. 

	/*
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|float a        |double b             |char c
	8(float?) + 8 + 8 = 24
	*/

// 실행을 시켜 보면, 사이즈가 24가 나온다. 
// 어마어마하게 비효율적이다. 13이면 될 걸 24를 쓰고 있다. 
// float a가 8 바이트를 차지하고, double b가 또 8 바이트를 차지하고, 
// char 가 8 바이트를 차지하는 현상이 발생한다. 
// 
// 이렇게 되는 이유는? 
// 컴파일러가 double을 한 번에 한 word에 실어서 통째로 보내려고  
// float a에도 padding을 넣어 주고, char c에도 padding을 넣어 주게 된다. 
// 
// struct Padded1과 struct Padded2의 멤버는 동일하지만, 
// 패딩 때문에 Padded1의 효율이 더 높다. 
// 
// 8 바이트보다 작은 char와 float을 나열해서 넣었기 때문에, 
// 패딩이 char 하나에만 들어갔다. Padded2처럼 float에는 패딩이 들어가지 않았다. 
// 
// Padded2는 Padded1과 똑같은 정보량을 가지고 있는 structure이지만, 
// float과 char 두 군데에 패딩이 들어가서 사이즈가 커졌다. 덜 효율적이다. 
// 
// 프로그램 실력이 좋아지면 이런 것까지 고려해서 구조체를 설계하기 바란다. 
// 
// 아래와 같이 멤버가 선언이 되면, char의 빈공간에 7 바이트가 채워지게 된다. 
// <= 7 바이트가 추가로 패딩이 된다. 
	/*
	struct Padded3 {
		char a;
		double b;
		double c;
	};
	*/
//
	/*
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|char a         |double b             |double c
	8(char?) + 8 + 8 = 24
	*/
// 
// 아래와 같이 배열일 때도 패딩이 생긴다. 
// 
	/*
	struct Person {
		char name[41];	// member
		int age;		// member
		float height;	// member
	};
	*/
// 
// name의 배열이 41개이다. 조금 애매한 숫자이다. 
// 사이즈를 찍어 보면, 3 바이트가 추가로 들어가서 52 바이트가 된다. 
// <= 41 + 4 + 4 = 49여야 하나, 3 바이트가 추가돼서 52바이트가 됐다. 
// 
// name이 차지하는 메모리가 41이 아니고 44 바이트가 됐다. 
// <= 배열일 경우에도 struct에서 padding이 생길 수 있다. 
// 
// 아래는 패딩과는 조금 다른 얘기이다. 
// 구조체의 배열을 만들었을 때, 메모리가 어떻게 배정이 되는가?
// 
// struct Person f[4];
// 
// printf("\nSiezof a structure array %zd\n", sizeof(f));
//
// <= 구조체의 배열로 배정이 된다. 

/*
|f[0].name |f[0].age |f[0].height|... ...|f[3].name |f[3].age |f[3].height|
*/

// <= 이런 식으로 메모리를 사용하게 된다. 구조체의 배열도 사용할 수 있다. 
// f 자체가 배열이다. 
// 
// 지금까지의 패딩은 컴파일러가 만들어 준 것이다. 
// 컴파일러가 보기에 word 단위로 보내는 게 효율적이니까 
// 패딩을 넣어서라도 word 단위로 맞추자. 
// 특히 double 같이 8 바이트 짜리가 있을 경우에, 
// 한 번에 깔끔하게 갈 수 있도록 allignment를 시켜 주자는 의미이다. 
// 
// Solution Explorer 창에서 c 파일을 선택한 후 우클릭한다 > 
// C/C++의 All Options로 간다 > 검색 창에서 struct를 검색한다 >
// Struct Member Alignment가 Default로 돼 있는 것을 볼 수 있다. 
// 화살표를 눌러서 열어 보면, 1 Byte, 2 Bytes, 4 Bytes, 8 Bytes, 16 Bytes, defalut
// 가 있다. 
// <= 패딩을 꺼 버리려면 1 Byte를 선택하면 된다. 한번 해 보자. 
// 
// p1이 패딩을 하면 사이즈가 16이었지만, 13이 나온다. 
// 이렇게 옵션으로 패딩을 조정할 수도 있다. 
// 
// 구조체가 메모리를 어떻게 사용하는지 패딩 현상과 함께 살펴 봤다.