#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Namespace, 이름 공간 공유하기 
//
// 번역할 때는 이름 공간 혹은 명칭 공간이라고 한다.
// C++에서는 단순한 개념적인 용어가 아니라, 실제 문법에 들어 있는 내용이다.  

int iamfunction() {
	return 0;
}

int main() {
	/*
		namespace 
		- Identify parts of a program in which a name is recognized
		- You can use the same name for one variable and one tag.
		- C++: use 'namespace' to use the same identifiers in the duplicated scopes.
	*/

	int myname = 123;

	{
		int myname = 345;
		// double myname = 3.14;	//ERROR
	}

	struct rect { double x; double y; };

	// int rect = 123;		// OK in C (Not ok in C++)
	struct rect rect = { 1.1, 2.2 };	// struct rect and rect are in different categories

	/*
	typedef struct rect rect;
	rect rect = { 1.1, 2.2 };	// Not OK
	*/

	//int iamfunction = iamfunction();	//ERROR

	/*
		Namespace pollution (KNK, p.465)
		- Nmaes in different files accidentally conflicting with each other
	*/

	//printf("%d\n", a);	// other.c


	return 0;
}

// 
	/*
		namespace
		- Identify parts of a program in which a name is recognized
		- You can use the same name for one variable and one tag.
		- C++: use 'namespace' to use the same identifiers in the duplicated scopes.
	*/
//
	/*
	{
		int myname = 345;
		// double myname = 3.14;	//ERROR
		<= 같은 block 내에서는 동일한 이름의 변수 사용을 불허한다. 
	}
	<= myname이라는 변수의 영역 scope는 이 block 중괄호 {} 안이다. 
	   <= myname이라는 이름이 인식될 수 있는 공간은 이 block만큼이다. 
	      myname이라는 이름의 namespace는 이 block이다. 
	   같은 block 안에 같은 이름의 변수를 선언할 수 없다. 
	   type이 달라도 이름이 같으면 선언을 할 수 없다. 
	   
    변수와 함수도 이름이 겹치면 안 된다. 
	하지만 변수 variable과 tag는 같은 이름을 쓸 수 있다. 
	struct, union 같은 것들은 category 자체가 다르므로 문법적으로 허용한다. 
	<= C에서만 허용이 되고 C++에서는 카테고리가 다른 것들 끼리도 
	   같은 이름을 사용하는 것이 허용 안 된다. 

	struct rect { double x; double y; };

	// int rect = 123;		// OK in C (Not ok in C++)
	struct rect rect = { 1.1, 2.2 };	// struct rect and rect are in different categories

	*/
//
// 복잡한 프로그램을 만들 게 되면 중복된 변수명이 나타나는 경우가 생기므로
// 같은 공간 안에 같은 이름(같은 인식자)를 갖는 것들을 여러 개 둘 수 있도록
// namespace로 구분해 주는 것이다. 
// <= 나중에 C++ 공부할 때, 공부하게 된다. 
// 
	/*
	int myname = 123;

	{
		int myname = 345;
		// double myname = 3.14;	//ERROR
		<= myname = 123;은 이 block 안에서는 name hiding이 된다. 
	}
	*/
//  
// 구조체와 관련된 걸 조금 살펴 보자.
// 
	/*
	struct rect { double x; double y; };
	 <= 구조체의 tag가 rect이다. 

	// int rect = 123;		// OK in C (Not ok in C++)
	struct rect rect = { 1.1, 2.2 };	// struct rect and rect are in different categories
	 <= struct의 tag가 rect인데도, 
	    struct variable name을 rect로 선언이 된다. 
     <= 왜냐하면, struct의 rect와 struct rect의 rect는 다르기 때문이다. 
	    rect는 struct의 tag 이름이고, 
		rect는 strcut rect의 variable name이다. 
		이 둘은 category가 다르다. 
	*/
// 
	/*
	struct rect { double x; double y; };

	int rect = 123;		// OK in C (Not ok in C++)
	 <= struct의 tag가 rect인데도, 
	    변수 이름을 rect로 또 쓸 수 있다. <= C언어에서는 허용한다. 
		C++에서는 허용하지 않는다. 좀 더 엄격해졌다. 
	 <= C언어에서 이런 식으로 이름을 중복 사용하는 것을 허용하더라도 
	    중복 사용은 권장하지는 않는다.
		이름이 같으면 매우 헤깔린다.
	*/
// 
	/*
	typedef struct rect rect;
	rect rect = { 1.1, 2.2 };	// Not OK
	 <= typedef로 struct rect를 rect라는 type 이름을 갖도록 만들어 놓고, 
	    rect rect = { .. };와 같은 식으로 사용하면 안 된다. 
	 <= 헤깔리는 걸 방지하기 위해 문법적으로 막아 놨다고 생각하면 된다. 
	 <= struct rect는 구조체라서 허용이 됐지만, 이와 같은 것은 안 된다. 
	    
    컴파일러 입장에서 생각해 보면, 납득을 할 수 있을 것이다. 
	*/
//
// int iamfunction = iamfunction();	//ERROR
// <= 함수의 이름과 동일한 변수 이름을 선언하려고 하면, 충돌이 난다. 
//    같은 이름 공간 안에서 명칭이 충돌이 나서 문제가 생긴 것이다. 
// 
	/*
		Namespace pollution (KNK, p.465)
		 <= 이름 공해라는 개념이 있다. 
		    큰 프로그램을 작성하다 보면, 쓸 만한 이름을 이미 다른 곳에서 
			다 사용해 버린 경우가 발생한다. 
			이름을 반복해서 쓰고 싶은 경우가 발생한다. 
			C언어 공부하다 보면, 전역변수가 안 좋다는 말을 듣게 된다. 
			이름을 가급적 작은 scope 안에 가둬 놔야 이름을 재사용할 수 있다. 


		- Nmaes in different files accidentally conflicting with each other
	*/

	//printf("%d\n", a);	// other.c 
// 
// 전역변수로 int a = 123;이 선언돼 있는데
// main() 함수 내에서 다시 a라는 변수를 사용한다면, 
// 컴파일 할 때는 넘어가지만 링킹할 때 에러가 발생하게 된다. 
// 
// 전역변수로 많은 변수가 선언돼 있으면, 
// scope 내에 새로운 변수를 선언하기 힘들어지게 되는데 이런 것을,
// namespace pollution이라고 한다. 
// 
// C언어에서는 가급적 전역변수를 적게 사용하면 방지를 할 수 있고, 
// static으로 막아 둬서 다른 곳에서 사용하지 못하게 하는 방법도 있다. 
// 
// C++나 다른 언어에서는 좀 더 고급 문법을 사용해서  
// namespace와 관련해서 덜 스트레스를 받도록 도와주는 장치가 준비돼 있다. 
// 
// C언어에서는 이런 불편함이 있었는데 
// 이후에 나온 언어에서는 이런 불편함을 보완해 주고 있다. 
// 
// namespace라는 용어에 대해서 살펴 봤다. 