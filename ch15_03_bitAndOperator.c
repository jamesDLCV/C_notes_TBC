#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>		// pow()
#include <string.h>		// strlen()
#include <stdlib.h>		// exit()
#include <stdbool.h>

// 15.3. 비트 단위 &를 이용해서 십진수를 이진수를 바꾸는 함수 만들기 연습 문제
// 
// 십진수를 이진수로 바꾸는 함수를 나머지 연산자를 이용해서 앞에서 만들어 봤다. 
// 이번에는 비트 단위 & 연산자를 이용해서 구현해 보겠다. 

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main() {

	unsigned char i = to_decimal("01000110");	 // 함수를 이용해서 이진수를 
	unsigned char mask = to_decimal("00000101"); // 십진수로 바꿔서 대입을 해 주고 있다. 

	print_binary(i);				// 이것을 만들어 봐라. 화면에 출력
	print_binary(mask);				// 화면에 이진수 형태로 출력해 봐라. 
	print_binary(i & mask);			// 비트 연산자가 배운 대로 작동하는지 확인한다. 

	// 변환하고 하는 수가 내부적으로는 이미 이진수로 저장돼 있다. 
	// 그 숫자의 자리 수별로 1인지 0인지를 알아서 출력을 해 주면 된다. 
	
	/*
		Decimal to binary
		     
			  Number     Mask	      Mask
		2^7: (01000110 & 10000000) != 10000000    print 0
		2^6: (01000110 & 01000000) == 01000000    print 1
		2^5: (01000110 & 00100000) != 00100000    print 0
		2^4: (01000110 & 00010000) != 00010000    print 0
		2^3: (01000110 & 00001000) != 00001000    print 0
		2^2: (01000110 & 00000100) == 00000100    print 1
		2^1: (01000110 & 00000010) == 00000010    print 1
		2^0: (01000110 & 00000001) != 00000001    print 0
	*/	 

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

// void print_binary(const unsigned char num) 함수를 스스로 직접 구현해 보라. 
void print_binary(const unsigned char num) {

	printf("Decimal %3d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;	// x64 unsigned long long, x86 unsigned int

	for (size_t i = 0; i < bits; ++i) {
		const unsigned char mask =
			(unsigned char)pow((double)2, (double)(bits - 1 - i));// warning 보기 싫으면
		                                                         // 이렇게 다 casting 해 준다.
											// 정수형 pow()를 만들어 써도 된다.
											// 사람이 보기 편하게 하기 위해서 해 주는 것이다. 
		// unsigned char mask = pow(2, (bits - 1 -i));	// C 언어는 자동 형변환을 해 주므로
									      // 이렇게 해 줘도 된다. warning이 떠도 괜찮다면...
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
	// for문을 구현할 때 큰 숫자에서 작은 숫자로 감소하게 만들 수도 있다. 
	// 
	// for (size_t i = bits -  1; i >= 0; --i) // size_t ERROR, 무한 루프가 발생한다. 
	//                                     // 0에서 --i를 해 주면 엄청 큰 숫자가 나온다. 
	//					                   // 이렇게 거꾸로 갈 때는 unsigned를 사용하면 안 된다. 
	// 
	// 위와 같이 for 문을 size_t로 구현할 때는 감소하는 for 문에 사용하면 안 된다. 
	// 위와 같이 size_t로 증가하는 for 문을 사용하거나 
	// 감소하는 for 문을 사용하고 싶다면, 아래와 같이 int i로 구현해야 한다.  
	/*
		for (int i = bits - 1; i >= 0; --i)
		{
			const unsigned char mask = 
				(unsigned char)pow((double)2, (double)i);
			if ((num & mask) == mask)
				printf("%d", 1);
			else
				printf("%d", 0);
		}	
	*/
	// 
	// bit 단위 & 연산자를 이용해서 십진수를 이진수로 바꾸는 함수를 만들어 봤다. 
	// 지금까지 구현한 함수를 이용해서 다른 bit 단위 연산자에 대해서도 확인해 보겠다. 

}

// size_t를 쓰면 이식성이 용이하다. 호환성을 높여 줄 수 있다. 