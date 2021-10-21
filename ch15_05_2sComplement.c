#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/* $ 2�� ���� ǥ���� Ȯ���� ����

��ȣ�� �ִ� ������ 2������ ó���ϱ� ���ؼ�, 2�� ���� ǥ������ ����Ѵ�. */

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

/* �� Signed-magnitude representation�� ����,
+0, -0ó�� 0�� �� �� �ִ� ��ó�� ���̴� ������ �����ϱ� ���� 2�� ���� ǥ������ ����Ѵ�.

2�� ���� ǥ������ -128�������� +127���� �Ǵµ�,
���� �ٸ� �� ���� ����� -127�������� +127������ ǥ�� ������ 1�� ����.

2�� ���� ǥ���������� ������ ��ȣ�� �ٲٱ� ���ؼ�,
����� ������ �ٲٰų� ������ ����� �ٲٱ� ���ؼ�,
�ϴ� 2������ ǥ���� ���¿���, ������ bit�� 0�̸� 1��, 1�̸� 0���� �ٲ۴�.
�״��� 1�� ���� �ش�.                                              */

/* �տ��� ����ߴ� print_binary() �Լ��� ����� ���ڴ�. 
mask���� signed, unsigned�� �߿����� �����Ƿ� unsigned�� �����ߴ�. 
������ unsigned�� �ٲ㼭 ������ ���� ����� �����ϰ� ���´�. 

*/

void print_binary(const char num);

int main() {

	print_binary(127);
	print_binary(-127);
	print_binary(~127 + 1);

	print_binary(12);
	print_binary(-12);
	print_binary(~12 + 1);

	/* ������ ����� �ٲ� ���� */
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

/* ���� ���:
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
���� ����� ���� ~127 + 1�� Binary ���� -127�� Binary ���� �����ϴٴ� ���� Ȯ���� �� �ִ�.  
~12 + 1�� Binary �� ���� -12�� Binary ���� ��Ȯ�� ��ġ�Ѵ�. 

~(-7)�� Binary ���� 7�� Binary ���� �����ϴ�. 

�տ��� 2�� ���� ǥ���� Two's complement methode�� ����� ������, 
���� ��ǻ�Ϳ��� �׷��� �۵��ϰ� �ִ����� Ȯ���� ���� �ʾҾ���. 

�� �������� ������ Two's complement methode�� �۵��Ǵ��� Ȯ���� �ô�.    */