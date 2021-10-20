#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <math.h>		// pow()
#include <string.h>		// strlen()
#include <stdlib.h>		// exit()
#include <stdbool.h>

// 15.3. 비트 단위 논리 연산자 확인해 보기
// 앞에서 직접 구현해 본 함수를 통해서, 비트 단위 논리 연산자가 배운 대로 작동하는지
// 확인해 보는 시간을 가져 보자. 

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main() {

	/*
		Regular Logical Operators: &&, ||, and !

		bool have_apple = true;
		bool like_apple = true;
		if (have_apple && like_apple)
			eat_apple();

		Bitwise Logical Operators:
		- Bitwise Not			~
		- BItwise And			&
		- Bitwise Or			|
		- Bitwise EXCLUSIVE OR	^	
	*/

	unsigned char a = 6;
	unsigned char b = 5;

	printf("%hhu\n", a);		// %hhu <= char를 숫자 unsigned로 출력한다. 
	print_binary(a);

	printf("%hhu\n", b);
	print_binary(b);

	printf("%hhu\n", a & b);
	print_binary(a & b);

	printf("%hhu\n", a | b);
	print_binary(a | b);

	printf("%hhu\n", a ^ b);
	print_binary(a ^ b);

	printf("%hhu\n", ~a);
	print_binary(~a);
	puts("");

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
}

/* 출력 결과: 
6
Decimal   6 == Binary 00000110
5
Decimal   5 == Binary 00000101
4
Decimal   4 == Binary 00000100
7
Decimal   7 == Binary 00000111
3
Decimal   3 == Binary 00000011
249
Decimal 249 == Binary 11111001   */


/*  C / C++ Format Specifier
 
signed: d, unsigned: u
int a; => scanf("%d", &a);
 
앞에 접두사만 붙는다.
char이면, hh
short이면, h
long이면, l
long long이면, ll
 
char unsigned이면, hhu
char signed이면, hhd
long unsinged이면, lu

eg) unsigned char를 받는다고 하면, scanf("%hhu", &a);가 된다. 
    <= 만약 3을 넣어 주면, 숫자 3이 들어간다.
  
    char를 scanf("%c", &a);로 받으면, 
    <= 3을 입력하면, 아스키코드 값 51이 들어간다. 즉 문자로 들어간다.  */