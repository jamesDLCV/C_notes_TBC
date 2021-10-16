#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h>	// strlen()
#include <stdlib.h>	// exit()

/*���� ����
������ -> ������ ��ȯ

��Ʈ ���� �����ڿ� ���� �̾����� ���Ǹ� ���� ���� ������ �� �ֵ��� �ϱ� ����,
�������� �������� ��ȯ�ϴ� �Լ��� ������ ����.               */

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

/* ���� ����
�������� ���ڿ� ���·� �Է��� �ϸ�, 
unsigned char ������ ������ �ٲ㼭 
��ȯ�� �� �ִ� to_decimal()�̶�� �Լ��� ������ ����. 

��� ������,
Binary (string) to Decimal conversion\n
6
22
148

Note: ^ (caret) means power in math. 
<= ^�� C������ power�� �ƴϴ�. ������ ǥ������ �ʴ´�. 

Hint: (int)pow(2, 3) == 8
<= pow() �Լ��� power�� ����Ѵ�. 
    pow() �Լ��� �⺻������ �Ǽ��� �ڷḦ �ٷ�Ƿ� 
    ������ ǥ���ϱ� ���ؼ� (int) casting�� �� �ش�. 
    pow() �Լ��� ����ϸ� to_decimal() �Լ��� �� �� ���ϰ� ������ �� �ִ�. 
 
������ ������ �� ���ƶ�.                                              */