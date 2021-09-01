#include <stdio.h>

// 너 내 집사가 되어라 from 나도 코딩
// 구조체

// struct, 블록 안의 변수는 선언부까지만 적어 주면 된다.
// 그러면 GameInfo라는 구조체가 만들어진 것이다. 
struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame;	// 연관 업체 게임
};

// typedef를 구조체 앞에 븥일 수 있다. 
// 다음과 같이 사용한다. 중괄호 뒤에 GAME_INFO;를 붙여 줬다. 
// struct GameInfomation를 GAME_INFO으로 치환하겠다. 
typedef struct GameInfomation {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame;	// 연관 업체 게임
} GAME_INFO;

// 다음과 같이 바로 별명을 붙여서 사용하면 간단하다. 
typedef struct {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame;	// 연관 업체 게임
} GAME_INFO2;

int main_struct_nado() {

	// 게임 출시
	// 이름: 나도게임
	// 발매 연도: 2017년
	// 가격: 50원
	// 제작사: 나도회사

	char* name = "나도게임";
	int year = 2017;
	int price = 50;
	char* company = "나도회사";

	// 또 다른 게임 출시
	// 이름: 너도게임
	// 발매 연도: 2017년
	// 가격: 1000원
	// 제작사: 너도회사

	char* name2 = "너도게임";
	int year2 = 2017;
	int price2 = 1000;
	char* company2 = "너도회사";

	// 비슷한 종류의 변수들이 따로 따로 설정이 돼 있다. 
	// 관련 있는 정보가 하나로 관리가 되면 좋겠다. 
	// 이때 필요한 것이 구조체이다. 
	
	// 구조체 사용
	// struct GameInfo까지가 자료형이라고 보면 되고,
	// 뒤의 gameInfo1이 변수명이라고 보면 된다. 
	struct GameInfo gameInfo1;
	//struct GameInfo gameInfo2;	// <= 이렇게 gameInfo2도 처리할 수 있다. 

	gameInfo1.name = "나도게임";
	gameInfo1.year = 2017;
	gameInfo1.price = 50;
	gameInfo1.company = "나도회사";

	// 구조체 출력
	printf("-- 게임 출시 정보 --\n");
	printf("게임명: \t%s\n", gameInfo1.name);
	printf("발매 연도: \t%d\n", gameInfo1.year);
	printf("가격: \t\t%d\n", gameInfo1.price);
	printf("제작사: \t%s\n", gameInfo1.company);
	printf("\n");

	// 구조체를 배열처럼 초기화
	struct GameInfo gameInfo2 = { "너도게임", 2017, 1000, "너도회사" };
	printf("-- 또 다른 게임 출시 정보 --\n");
	printf("게임명: \t%s\n", gameInfo2.name);
	printf("발매 연도: \t%d\n", gameInfo2.year);
	printf("가격: \t\t%d\n", gameInfo2.price);
	printf("제작사: \t%s\n", gameInfo2.company);

	// 구조체 배열
	// 두 개 회사의 정보가 배열에 들어간다. 
	struct GameInfo gameArray[2] = {
		{ "나도게임", 2017, 50, "너도회사" },
		{ "너도게임", 2017, 1000, "너도회사" }
	};
	
	// 구조체 포인터
	struct GameInfo* gamePtr;	// 미션맨
	gamePtr = &gameInfo1;

	printf("\n-- 미션맨의 게임 출시 정보 --\n");
	//printf("게임명: \t%s\n", (*gamePtr).name);	// *ptr와 동일, (*gamePtr).name
	//printf("발매 연도: \t%d\n", (*gamePtr).year);
	//printf("가격: \t\t%d\n", (*gamePtr).price);
	//printf("제작사: \t%s\n", (*gamePtr).company);

	printf("게임명: \t%s\n", gamePtr->name);		 
	printf("발매 연도: \t%d\n", gamePtr->year);
	printf("가격: \t\t%d\n", gamePtr->price);
	printf("제작사: \t%s\n", gamePtr->company);

	// 연관 업체 게임 소개
	gameInfo1.friendGame = &gameInfo2;	// 주소를 가리키게 한다. 
	printf("\n-- 연관 업체의 게임 출시 정보 --\n");
	printf("게임명: \t%s\n", gameInfo1.friendGame->name);
	printf("발매 연도: \t%d\n", gameInfo1.friendGame->year);
	printf("가격: \t\t%d\n", gameInfo1.friendGame->price);
	printf("제작사: \t%s\n", gameInfo1.friendGame->company);

	// typedef
	// 자료형의 별명을 지정한다. 
	int i = 1;
	typedef int 정수;
	typedef int 실수;

	정수 정수변수 = 3;		// int i = 3;
	실수 실수변수 = 3.23f;	// float f = 3.23f;

	printf("\n\n정수변수: %d, 실수변수: %.2f\n\n", 정수변수, 실수변수);

	typedef struct GameInfo 게임정보;		// 게임정보로 변수를 만들 수 있다. 
	게임정보 game1;
	game1.name = "한글 게임";
	game1.year = 2015;
	game1.price = 250;
	game1.company = "meTooCorporation";

	printf("\n-- typedef game1 업체의 게임 출시 정보 --\n");
	printf("게임명: \t%s\n", game1.name);
	printf("발매 연도: \t%d\n", game1.year);
	printf("가격: \t\t%d\n", game1.price);
	printf("제작사: \t%s\n", game1.company);

	// 구조체 앞에 typedef를 붙이고, 마지막에 별명 GAME_INFO을 적어 줬다. 
	GAME_INFO game2;
	game2.name = "한글 게임2";
	game2.year = 2016;
	game2.price = 550;
	game2.company = "meThreeCorporation";

	printf("\n-- typedef game2 업체의 게임 출시 정보 --\n");
	printf("게임명: \t%s\n", game2.name);
	printf("발매 연도: \t%d\n", game2.year);
	printf("가격: \t\t%d\n", game2.price);
	printf("제작사: \t%s\n", game2.company);

	// (GAME_INFO 말고) struct GameInfomation을 쓸 수도 있다. 
	struct GameInfomation game3;
	game3.name = "한글 게임3";
	game3.year = 2017;
	game3.price = 750;
	game3.company = "meFourCorporation";

	printf("\n-- typedef game3 업체의 게임 출시 정보 --\n");
	printf("게임명: \t%s\n", game3.name);
	printf("발매 연도: \t%d\n", game3.year);
	printf("가격: \t\t%d\n", game3.price);
	printf("제작사: \t%s\n", game3.company);

	// typed struct {} GAME_INFO2;
	GAME_INFO game4;
	game4.name = "한글 게임4";
	game4.year = 2018;
	game4.price = 950;
	game4.company = "meFiveCorporation";

	printf("\n-- typedef game4 업체의 게임 출시 정보 --\n");
	printf("게임명: \t%s\n", game4.name);
	printf("발매 연도: \t%d\n", game4.year);
	printf("가격: \t\t%d\n", game4.price);
	printf("제작사: \t%s\n", game4.company);

	return 0;
}

// 구조체라는 것은 생김새가 좀 다르지만 용법은 일반 변수와 거의 흡사하다. 
// 구조체에 있는 변수에 접근하기 위해서는 . 점을 사용한다. 
// 구조체 포인터일 때에는, 구조체에 있는 변수에 접근하기 위해서 ->를 사용한다. 
// 
// 구조체 안에서 똑같은 구조체를 변수로 가질 수 있다. 
// 내가 나도회사 사장인데 친구네 회사인 너도회사의 게임도 소개하고 싶다면, 
// 자기가 가진 구조체 내에 자기 구조체를 다시 한 번 선언한다. 
//	(위에서 구조체 변수는 friendGame)
// 
// gameInfo1.friendGame = &gameInfo2;에서
// friendGame이라는 구조체 자체가 포인터이다. 
// gameInfo1.friendGame가 가리키는 곳이 &gameInfo2이므로
// gameInfo2이 가지고 있는 정보를 출력할 것이다. 
// 
// struct GameInfo 이렇게 써 주려니 좀 귀찮다. 
// <= typedef를 사용할 수 있다. 
// 
// typedef struct GameInfo 게임정보;
// <= struct GameInfo에 게임정보라는 별명을 달아 달라. 
//    이후부터는 게임정보로 변수를 만들 수 있다. 
// 
// 이 방법 말고 또 다른 방법으로 줄일 수 있다. 
// 구조체 앞에 typedef를 붙이고 마지막에 구조체의 별명을 적어 주면 된다. 
// <= 위에 예시돼 있다. 