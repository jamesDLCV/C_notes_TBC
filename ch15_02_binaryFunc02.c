#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h>	// strlen()
#include <stdlib.h>	// exit()

// 연습 문제
// 이진수 -> 십진수 변환

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

unsigned char to_decimal(const char bi[]) {

	const size_t bits = strlen(bi);
	unsigned char sum = 0;
	for (size_t i = 0; i < bits; ++i) {
		if (bi[i] == '1') {
			sum += (int)pow(2, bits - 1 - i);
		} 
		else if (bi[i] != '0') {
			printf("Wrong character: %c", bi[i]);
			exit(1);
		}
	}

	return sum;
	printf("Binary %s == Decimal %d\n", bi, sum);
}

/*
unsigned char to_decimal(const char bi[]) { 
     // const char bi[]로 문자열 입력을 받고 있다.
     // 반환 자료형은 unsigned char로 했다. 
	 // bi[] 길이에 따라서 unsigned char일 수도 있고, unsigned int일 수도 있고,
	 // unsigned long일 수도 있다. <= 구현하기 나름이다. 
	 // 너무 많이 적으면 어지럽기 때문에, 8 글자만 적기 위해서 unsigned char로 했다. 
	 
	const size_t bits = strlen(bi);
     // 입력 받은 문자열이 몇 개 인지, 그러니까 몇 bits 짜리 2진수를 변환하려고 하는지
	 // 확인을 하기 위해서 strlen() 함수 사용.  
	 // size_t는 x86에서는 unsigned int이고 x64에서는 unsigned long long이다. 
	 // C언어의 이식성을 높여 주는 자료형이다. 


	unsigned char sum = 0;	// 합을 구해야 하므로 sum을 선언, 초기화해 줬다.
	for (size_t i = 0; i < bits; ++i) {
	 // <= bits의 길이를 구할 때, size_t를 사용했으므로, 
	 //    반복에 사용되는 변수 i도 size_t로 선언했다. 
	 //    C++에서는 x86에서 x64로, 윈도우즈에서 리눅스로 옮겨 다니면서 컴파일하는 
	 //    경우가 많으므로, 이렇게 size_t를 사용하는 경우가 점점 많아지고 있다.
	 //    C++ STL에서도 size_t를 많이 사용한다. 
	 // 지금부터 눈에 익숙하게 봐 두면, 도움이 될 것이다. 
	 // 문법 강의에서는 int로 하는 것이 일반적이다. 

		if (bi[i] == '1') {
			sum += (int)pow(2, bits - 1 - i);
			// <= 2진수를 십진수로 도출하는 과정을 pow() 함수로 구현.
			// (int)pow(2, bits - 1 - i);
			//   <= 이 수식이 나오는 과정도 잘 정리해 둬라.

			// 보충) pow() 관련 경고(warning)을 없애고 싶다면, 
			// 아래와 같이 형변환을 하라.
            // sum += (unsigned char)pow((double)2, (double)(bits - 1 - i));
			
			// 0일 때는 뭔가를 입력할 필요가 없으므로 아무 작업도 없다. 

		} else if (bi[i] != '0') {
			// 0과 1만 입력이 돼야 하는데, 그외 다른 문자나 숫자를 입력했을 때에는,		
			printf("Wrong character: %c", bi[i]);
			// <= 입력이 잘못됐다는 메시지를 출력해 준다. 
			//    기능 구현에 반드시 필요한 것은 아니다. 
			// 프로그래밍을 할 때는 사용자의 실수도 고려하는 것이 좋다. 

			exit(1);
			// 이 함수가 아주 중요한 부분일 경우에는, 
			// 이런 예외가 발생하면 더 이상 실행해 나갈 수가 없으므로, 
			// 강제 종료시킨다. 
		}
	}

	return sum;
	printf("Binary %s == Decimal %d\n", bi, sum);
}
*/

// 기능이 정상적으로 작동한다면, 구현한 함수와 이와 똑같지 않아도 된다. 
//
// 이진수를 십진수를 변환하는 함수를 간단하게 만들어 봤다.
// 다음 강의에서는 이 함수를 이용해서 비트 단위 연산자에 대해서 더 살펴 본다.