#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 열거형, Enumerated Types
// 
// 정수형 상수가 마치 이름이 있는 것처럼 사용할 수 있도록 해 주는 열거형 문법을 살펴 보자.

/** Motivation
int c = 0;	// red: 0, orange: 1, yellow: 2, green: 3, ....

if (c == 0)
	printf("red");
else if (c == 1)
	printf("orange");
else if (c == 2)
	printf("yellow");
...
*/

/*
#define RED		1
#define ORANGE	2
#define YELLOW	3

int c = YELLOW;
if (c == YELLOW)
	printf("yellow");

*/

int main() {
	/*
		Enumerated type
		- Symbolic names to represent integer constants
		- Improve readability and make it easy to maintain
		- enum-specifier (struct-specifier, union-specifier)

		Enumerators
		- The symbolic constants
	*/

	enum spectrum { red, orange, yellow, green, blue, violet };
	//				0    1       2       3      4     5

	enum spectrum color;
	color = blue;
	
	if (color == yellow)
		printf("yellow");		// Note: enumerators are not strings

	for (color = red; color <= violet; color++)//Note: ++operator aren't allowed in c++
		printf("%d\n", color);

	printf("red = %d, orange = %d\n", red, orange);

	enum kids { jackjack, dash, snoopy, nano, pitz };
	// nina has a value of 3
	enum kids my_kid = nano;
	printf("nano %d %d\n", my_kid, nano);

	enum levels { low = 100, medium = 500, high = 2000 };

	int score = 800;	// TODO: user input
	if (score > high)
		printf("High score!\n");
	else if (score > medium)
		printf("Good job\n");
	else if (score > low)
		printf("Not bad\n");
	else
		printf("Do your best\n");

	enum pet { cat, dog = 10, lion, tiger };
	// lion has a value of 11
	printf("cat %d\n", cat);
	printf("lion %d\n", lion);

	return 0;
}

// 열거형을 왜 사용하는지 살펴 보자.
/** Motivation
int c = 0;	// red: 0, orange: 1, yellow: 2, green: 3, ....
 <= 여러 가지 색깔이 들어가는 프로그램을 만든다고 해 보자. 
    red: 0, orange: 1, yellow: 2, green: 3, .... 이런 식으로 색깔에 숫자를 배정해 줄 수 있다. 
	숫자를 배정해 주는 이유는 문자로 일일이 코딩하기가 조금 힘들 것이기 때문에,
	각각의 색깔에다가 0, 1, 2, 3, 4 정수를 하나씩 배정해 주고,
	배정된 정수를 이용해서 이게 무슨 색깔이구나라고 판단을 하는 방식을 쓴다. 
 <= c라는 color에다가 red 값을 넣어 주고 싶다. 
    그런데 color라는 자료형이 존재하지 않으므로, 각각의 색깔에 어떤 정수가 대응이 된다고 
	생각하는 것이다.
 <= int 타입 변수 c에다가 0을 대입한다는 것은, c가 red 값을 의미한다고 간주하는 것이다. 
    프로그래머가 이렇게 생각을 하고 프로그래밍을 하는 것이다.
    
if (c == 2)
	printf("yellow");
 <= 어떤 과정을 거처서 혹은 사용자로부터 입력을 받아서,
    2일 경우에는 yellow를 출력한다. <= 이런 프로그램을 생각할 수 있다. 
 <= 하지만 이렇게 숫자로 컬러를 표시할 경우, 실수할 확률이 높아지게 된다. 
    2가 yellow라는 것을 잊어 버리지 않고 기억을 하면서 프로그래밍을 해야 하는데,
	이는 프로그래머 입장에서는 상당히 부담스럽다.
	나중에 유지, 보수할 때도 매우 힘들게 되고 가독성도 좋지 않다. 
*/
// 이때 define을 이용해서 symbolic constants를 만드는 방법을 생각해 볼 수 있다. 
/*
#define RED		1
#define ORANGE	2
#define YELLOW	3
 <= define을 사용해서 매크로로 선언을 하는 것은, YELLOW를 3과 같이 문자 단위로 교체해 주는 것이다.
    전처리기의 특징이다.
	컴파일러 입장에서는 YELLOW가 나타나면, 
	그냥 int c = 3; 처럼 컴파일한다.
	<= 그래서 컴파일러가 오류가 있는 것을 잡아 주지 못한다. 
	   컴파일 타임에 해 줄 수 있는 게 없다. 

int c = YELLOW;
if (c == YELLOW)
	printf("yellow");
<= 이 코드는 컴파일러 입장에서는,
int c = 3;
if (c == 3)
	printf("yellow");
<= 코드를 이렇게 본다. 
   우리가 의도하는 것과는 조금 차이가 생긴다. 
*/
// 그래서 열거형이라는 문법을 사용하면 조금 더 편하게 프로그래밍을 할 수 있다. 
// 프로그램을 읽을 때 가독성이 증가하고, 유지, 보수도 조금 더 편해지는 장점이 있다. 
// 
/*
		Enumerated type
		- Symbolic names to represent integer constants
		  <= 정수 상수에게 기호적인 이름을 붙여 주는 것이다. 
		- Improve readability and make it easy to maintain
		- enum-specifier (struct-specifier, union-specifier)
		  <= 열거형-지정자, 구조체-지정자, 공용체-지정자
		  <= specifier: 구체화한다.
		  <= enum: 나열한다. 
		Enumerators
		- The symbolic constants
	*/
// 
// enum spectrum { red, orange, yellow, green, blue, violet };
//  			   0    1       2       3      4     5
// <= 이렇게 숫자를 대신해서 이름을 가지고 프로그래밍을 할 수 있기 때문에,
//    사람이 알아 보기 쉽다. 
//    0이 red라는 것을 외우지 않아도 되므로 부담이 많이 줄어든다. 
// <= 태그 sepctrum 앞에 enum을 붙여 준다. 구조체와 공용체에서와 동일하다. 
// <= 나열돼 있는 정수에 기호적인 이름을 붙여 준다. 
//    그래서 Enumerated type이라고 부른다. 
// <= red, orange, yellow, green, blue, violet 같은 것을 
//    Enumerators라고 부른다. 
//    이름이 붙어 있는 정수형 상수이다. 사실은 내부적으로 정수이다. 
//    내부적으로 사용할 때 정수처럼 사용할 수 있다. 
// 
// 구조체나 공용체에서와 마찬가지로, enumerator에 대한 변수를 다음과 같이 사용할 수 있다.
/*
enum spectrum color;
 <= 이렇게 선언한다. 
    color에다가 { red, orange, yellow, green, blue, violet } enumerators를
	대입해 줄 수 있다.
	<= 앞에서부터 0, 1, 2, 3, ... 이렇게 자동으로 배정이 된다. 
color = blue;
 <= color에다가 blue를 대입할 수도 있고, 
if (color == yellow) <= color와 yellow를 비교할 수도 있다. 
	printf("yellow");		// Note: enumerators are not strings
	<= printf(yellow); 처럼 사용해도 될 수 있는 것처럼 느껴지지만,
	   yellow는 문자열이 아니다. 그냥 정수일 뿐이다. 
	   2라는 정수에 yellow라는 이름을 붙여 줘서,
	   yellow라는 이름으로 2라는 정수를 사용할 수 있는 것이지, 
	   문자열과 그대로 대응이 되지는 않는다. 
	   <= 이점 헤깔리면 안 된다. 

for (color = red; color <= violet; color++)//Note: ++operator aren't allowed in C++, use type int.
    <= 대신에 정수이기 때문에 이와 같이 for문 안에 넣고 
	   비교 연산자, 증감 연산자에 쓸 수 있다. 
	   red는 시작, violet은 끝이다. 
	<= C++에서는 안타깝게도 열거형에 대해서 증감 연산자를 사용할 수 없다.
	   위와 같이 쓸 수 없고, color를 int형으로 써야 한다. 

	printf("%d\n", color);

printf("red = %d, orange = %d\n", red, orange);
 <= red는 내부적으로 정수니까 정수로 출력이 될 수밖에 없다.
    출력을 할 때는 %d와 같이 정수형으로 해야 한다. 
    red, yellow 등 enumerators는 문자열이 아니다. 
*/
// 
// yellow enumerator에 마우스를 갖다 대면, 
// (enum spectrum)yellow = 2와 같이 알려 준다. 
// 최근에는 통합 개발 환경이 좋아져서 알려 주지만 예전에는 알져 주지 않아서,
// 위로 올라가서 확인하고 다시 내려와서 코딩하는 일이 많았다. 
// 
/*
enum kids { jackjack, dash, snoopy, nano, pitz };
            0         1     2       3     4
 <= 마우스를 enumerators에 갖다 대면 할당된 정수가 뜬다. 

// nina has a value of 3
enum kids my_kid = nano;
 <= nano는 컴퓨터 내부에서는 그냥 숫자 3이다. 
    단지 프로그래머의 가독성을 높여 주기 위해서 문자로 된 이름이 있는 것처럼 
	다룰 수 있게 해 주는 문법이다. 

printf("nano %d %d\n", my_kid, nano);

enum levels { low = 100, medium = 500, high = 2000 };
 <= 점수를 상, 중, 하로 나누는데, 2000점이 넘으면 high, 
    500점이 넘고 2000점보다 작으면 medium이다. 이렇게 점수 구분을 한다고 해 보자. 
	이렇게 열거형으로 해 둬야 나중에 수정이 용이하다. 
	<= 아래의 조건문에 숫자가 들어가면 나중에 수정할 때 조금 불편하다. 
	<= 아래처럼 high, medium, low와 같이 이름이 붙어 있으면, 
	   코든를 수정, 즉 유지, 보수할 때 용이하다. 
	   코드를 한 번 만들어 놓고 그냥 쭉 사용하는 것보다는, 
	   계속 필요에 따라서 수정을 하게 돼 있다. 
	<= 열거형을 사용하면 가독성을 엄청나게 높여 준다. 

int score = 800;	// TODO: user input

if (score > high)   <= 점수가 high보다 높으면이라는 뜻으로 가독성이 높다. 
                       만약 score > 2000으로 돼 있다면, 2000의 의미가 모호하다.
	printf("High score!\n");
else if (score > medium)
	printf("Good job\n");
else if (score > low)
	printf("Not bad\n");
else
	printf("Do your best\n");
<= 이런 예제를 보건데 열거형을 사용하면 가독성이 높아진다. 

// 문법상 enumerators에 정수를 배정할 때 
   꼭 0, 1, 2, 3, ... 순서로 해야만 하는 것은 아니다. 
enum pet { cat, dog = 10, lion, tiger };
 <= 중간에 dog = 10과 같이 지정을 해 줄 수도 있다. 
// lion has a value of 11
   1 ~ 9까지는 없다. lion에 11이 배정된다. 
   tiger에는 12가 배정된다. 
printf("cat %d\n", cat);
printf("lion %d\n", lion);

*/
// 
// 열거형이 필요한 이유와 기본적인 문법을 살펴 봤다. 