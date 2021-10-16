#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h>	// strlen()
#include <stdlib.h>	// exit()

/*연습 문제
이진수 -> 십진수 변환

비트 단위 연산자에 대한 이어지는 강의를 보다 쉽게 이해할 수 있도록 하기 위해,
이진수를 십진수로 변환하는 함수를 구현해 본다.               */

unsigned char to_decimal(const char bi[]);

int main() {

	printf("Binary (string) to Decimal conversion\n");

	printf("%d\n", to_decimal("00000110"));	// 1*(2^2) + 1*(2^1) = 4 + 2 = 6
	printf("%d\n", to_decimal("00010110"));	// 1*(2^4) + 1*(2^2) + 1*(2^1) =
											// 16 + 4 + 2 = 22

	// Note: ^ (caret) means power in math.
	// Hint: (int)pow(2, 3) == 8

	printf("%d\n", to_decimal("10010100"));	// 148

	return 0;
}

unsigned char to_decimal(const char bi[]) 
{
	return 0;
}

/* 연습 문제
이진수를 문자열 형태로 입력을 하면, 
unsigned char 십진수 정수로 바꿔서 
반환을 해 주는 to_decimal()이라는 함수를 구현해 봐라. 

출력 예제는,
Binary (string) to Decimal conversion\n
6
22
148

Note: ^ (caret) means power in math. 
<= ^가 C언어에서는 power가 아니다. 제곱을 표시하지 않는다. 

Hint: (int)pow(2, 3) == 8
<= pow() 함수가 power를 계산한다. 
    pow() 함수는 기본적으로 실수형 자료를 다루므로 
    정수로 표시하기 위해서 (int) casting을 해 준다. 
    pow() 함수를 사용하면 to_decimal() 함수를 좀 더 편하게 구현할 수 있다. 
 
스스로 구현을 해 보아라.                                              */