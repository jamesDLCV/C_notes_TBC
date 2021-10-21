#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/* $ 2의 보수 표현법 확인해 보기

부호가 있는 정수를 2진수로 처리하기 위해서, 2의 보수 표현법을 사용한다. */

/*
Signed Integers

- Signed-magnitude representation
00000001 is 1 and 10000001 is -1
00000000 is +0, 10000000 is -0
Two zeros +0, -0, from -127 to +127

- One's complement method
To reverse the sign, invest each bit.
0000001 is 1 and 1111110 is -1.
1111111 is -0
from -127 to +127

- Two's complement method (commonly used in most systems)
To reverse the sign, invert each bit and add 1.
from -128 to +127                                                 */

/* 위 Signed-magnitude representation을 보면,
+0, -0처럼 0이 두 개 있는 것처럼 보이는 단점을 보완하기 위해 2의 보수 표현법을 사용한다.

2의 보수 표현법은 -128에서부터 +127까지 되는데,
위의 다른 두 가지 방법은 -127에서부터 +127까지로 표현 범위가 1개 적다.

2의 보수 표현법에서는 숫자의 부호를 바꾸기 위해서,
양수를 음수로 바꾸거나 음수를 양수로 바꾸기 위해서,
일단 2진수로 표현된 상태에서, 각각의 bit를 0이면 1로, 1이면 0으로 바꾼다.
그다음 1을 더해 준다.                                              */

/* 앞에서 사용했던 print_binary() 함수를 사용해 보겠다. 
mask에게 signed, unsigned가 중요하지 않으므로 unsigned는 삭제했다. 
하지만 unsigned로 바꿔서 실행해 봐도 결과는 동일하게 나온다. 

*/

void print_binary(const char num);

int main() {

	print_binary(127);
	print_binary(-127);
	print_binary(~127 + 1);

	print_binary(12);
	print_binary(-12);
	print_binary(~12 + 1);

	/* 음수를 양수로 바꿔 보자 */
	print_binary(7);
	print_binary(-7);
	print_binary(~-7 + 1);

	return 0;
}

void print_binary(const char num) {

	printf("Decimal %3d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;	// x64 unsigned long long, x86 unsigned int

	for (size_t i = 0; i < bits; ++i) {
		const char mask = (char)pow((double)2, (double)(bits - 1 - i));

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}

	printf("\n");
}

/* 실행 결과:
Decimal 127     == Binary 01111111
Decimal -127    == Binary 10000001
Decimal -127    == Binary 10000001
Decimal  12     == Binary 00001100
Decimal -12     == Binary 11110100
Decimal -12     == ~127 + 1 11110100
Decimal   7     == Binary 00000111
Decimal  -7     == Binary 11111001
Decimal   7     == Binary 00000111               */

/* 
실행 결과를 보면 ~127 + 1의 Binary 값이 -127의 Binary 값과 동일하다는 것을 확인할 수 있다.  
~12 + 1의 Binary 값 또한 -12의 Binary 값과 정확히 일치한다. 

~(-7)의 Binary 값은 7의 Binary 값과 동일하다. 

앞에서 2의 보수 표현법 Two's complement methode를 배우기는 했지만, 
실제 컴퓨터에서 그렇게 작동하고 있는지는 확인을 하지 않았었다. 

위 예제에서 실제로 Two's complement methode가 작동되는지 확이해 봤다.    */