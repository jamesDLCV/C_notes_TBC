#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Bitwise Logical Operators
 
지금까지는 자료형 단위로 이루어지는 연산 위주로 이루어지는 공부를 해 왔다. 
 
지금부터는 비트 단위로 이루어지는 연산에 대해서 살펴 보겠다. 
먼저 비트 단위 논리 연산자에 대해서 살펴 본다. 
 
지금까지 사용해 온 논리 연산자는 어떤 자료형의 변수나 상수에 적용이 되는
논리 연산에 대한 것들이었다. 
 
Regualr Logical Operators: &&, ||, and ! 
bool have_apple = true;
bool like_apple = true;
  
if (have_apple && like_apple)
	eat_apple();
 
비트 연산자는 다음과 같다. 일반적인 논리 연산자와 비교해서 잘 정리해 둬라.
Bitwise Logical Operators:
- Bitwise NOT			  ~ tilde
- Bitwise AND			  & ampersand
- Bitwise OR			  | vertical bar
- Bitwise EXCLUSIVE OR	  ^ caret
 
비트와이즈 연산자가 왜 필요한가?
 
게임을 만든다거나 할 때, 칼을 가지고 있다 없다를 나타내기 위해서는,
unsigned char has_sword = 1; 혹은
unsigned char has_sword = 0; 두 가지만 있으면 된다. 
즉 1, 0 두 가지만 나타내는 1bit만 있으면 충분하다.
 
unsigned char has_sword 변수는 8 bits이다. (char이므로 1byte)
필요한 용량은 1bit면 되므로 나머지 7bits는 낭비가 된다. 
 
이러한 낭비를 막기 위해서 bitwise 연산자를 사용할 수 있다.  */

int main() {

	// Bitwise AND &
	// 둘 다 1일 때를 제외하고는 모두 0이 된다. 
	unsigned char a = 6;		// 6 = 2^2 + 2^1 (decimal), 00000110(binary) 
	unsigned char b = 5;		// 5 = 2^2 + 2^0          , 00000101

	printf("%hhu\n", a & b);    // 4 = 2^2                , 00000100

	// Bitwise OR |
	// 둘 중 하나만 1이면 1이 된다. 
	unsigned char a2 = 6;		// 6 = 2^2 + 2^1 (decimal), 00000110(binary) 
	unsigned char b2 = 5;		// 5 = 2^2 + 2^0          , 00000101

	printf("%hhu\n", a2 | b2);  // 7 = 2^2 + 2^1 + 2^0    , 00000111
	
	// Bitwise XOR ^, Exclusive OR ^
	// 둘 다 1이면 0이 나오고 둘 중 하나가 1이면 1이다. 
	unsigned char a3 = 6;		// 6 = 2^2 + 2^1 (decimal), 00000110(binary) 
	unsigned char b3 = 5;		// 5 = 2^2 + 2^0          , 00000101

	printf("%hhu\n", a3 ^ b3);  // 3 = 2^1 + 2^0          , 00000011

	// Bitwise Not ~	 
	unsigned char a4 = 6;		// 6 = 2^2 + 2^1 (decimal), 00000110(binary) 
	
	printf("%hhu\n", ~a4);	    // 249                    , 11111001
	                            // 249 = 2^7 + 2^6 + 2^5 + 2^4 + 2^3 + 2^0

	return 0;
}

// 비트 단위 논리 연산자가 어떤 규칙을 갖고 계산이 되는지 살펴 봤다.
// 이어지는 강의에서 실제 예제를 다뤄 보겠다. 