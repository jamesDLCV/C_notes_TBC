#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <math.h>		// pow()
#include <string.h>		// strlen()
#include <stdlib.h>		// exit()
#include <stdbool.h>

// 15.3. ��Ʈ ���� �� ������ Ȯ���� ����
// �տ��� ���� ������ �� �Լ��� ���ؼ�, ��Ʈ ���� �� �����ڰ� ��� ��� �۵��ϴ���
// Ȯ���� ���� �ð��� ���� ����. 

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

	printf("%hhu\n", a);		// %hhu <= char�� ���� unsigned�� ����Ѵ�. 
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
			(unsigned char)pow((double)2, (double)(bits - 1 - i));// warning ���� ������
															 // �̷��� �� casting �� �ش�.
											// ������ pow()�� ����� �ᵵ �ȴ�.
											// ����� ���� ���ϰ� �ϱ� ���ؼ� �� �ִ� ���̴�. 
		// unsigned char mask = pow(2, (bits - 1 -i));	// C ���� �ڵ� ����ȯ�� �� �ֹǷ�
										  // �̷��� �� �൵ �ȴ�. warning�� ���� �����ٸ�...
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}

/* ��� ���: 
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
 
�տ� ���λ縸 �ٴ´�.
char�̸�, hh
short�̸�, h
long�̸�, l
long long�̸�, ll
 
char unsigned�̸�, hhu
char signed�̸�, hhd
long unsinged�̸�, lu

eg) unsigned char�� �޴´ٰ� �ϸ�, scanf("%hhu", &a);�� �ȴ�. 
    <= ���� 3�� �־� �ָ�, ���� 3�� ����.
  
    char�� scanf("%c", &a);�� ������, 
    <= 3�� �Է��ϸ�, �ƽ�Ű�ڵ� �� 51�� ����. �� ���ڷ� ����.  */