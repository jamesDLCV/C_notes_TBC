#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Bitwise Logical Operators
 
���ݱ����� �ڷ��� ������ �̷������ ���� ���ַ� �̷������ ���θ� �� �Դ�. 
 
���ݺ��ʹ� ��Ʈ ������ �̷������ ���꿡 ���ؼ� ���� ���ڴ�. 
���� ��Ʈ ���� �� �����ڿ� ���ؼ� ���� ����. 
 
���ݱ��� ����� �� �� �����ڴ� � �ڷ����� ������ ����� ������ �Ǵ�
�� ���꿡 ���� �͵��̾���. 
 
Regualr Logical Operators: &&, ||, and ! 
bool have_apple = true;
bool like_apple = true;
  
if (have_apple && like_apple)
	eat_apple();
 
��Ʈ �����ڴ� ������ ����. �Ϲ����� �� �����ڿ� ���ؼ� �� ������ �ֶ�.
Bitwise Logical Operators:
- Bitwise NOT			  ~ tilde
- Bitwise AND			  & ampersand
- Bitwise OR			  | vertical bar
- Bitwise EXCLUSIVE OR	  ^ caret
 
��Ʈ������ �����ڰ� �� �ʿ��Ѱ�?
 
������ ����ٰų� �� ��, Į�� ������ �ִ� ���ٸ� ��Ÿ���� ���ؼ���,
unsigned char has_sword = 1; Ȥ��
unsigned char has_sword = 0; �� ������ ������ �ȴ�. 
�� 1, 0 �� ������ ��Ÿ���� 1bit�� ������ ����ϴ�.
 
unsigned char has_sword ������ 8 bits�̴�. (char�̹Ƿ� 1byte)
�ʿ��� �뷮�� 1bit�� �ǹǷ� ������ 7bits�� ���� �ȴ�. 
 
�̷��� ���� ���� ���ؼ� bitwise �����ڸ� ����� �� �ִ�.  */

int main() {

	// Bitwise AND &
	// �� �� 1�� ���� �����ϰ�� ��� 0�� �ȴ�. 
	unsigned char a = 6;		// 6 = 2^2 + 2^1 (decimal), 00000110(binary) 
	unsigned char b = 5;		// 5 = 2^2 + 2^0          , 00000101

	printf("%hhu\n", a & b);    // 4 = 2^2                , 00000100

	// Bitwise OR |
	// �� �� �ϳ��� 1�̸� 1�� �ȴ�. 
	unsigned char a2 = 6;		// 6 = 2^2 + 2^1 (decimal), 00000110(binary) 
	unsigned char b2 = 5;		// 5 = 2^2 + 2^0          , 00000101

	printf("%hhu\n", a2 | b2);  // 7 = 2^2 + 2^1 + 2^0    , 00000111
	
	// Bitwise XOR ^, Exclusive OR ^
	// �� �� 1�̸� 0�� ������ �� �� �ϳ��� 1�̸� 1�̴�. 
	unsigned char a3 = 6;		// 6 = 2^2 + 2^1 (decimal), 00000110(binary) 
	unsigned char b3 = 5;		// 5 = 2^2 + 2^0          , 00000101

	printf("%hhu\n", a3 ^ b3);  // 3 = 2^1 + 2^0          , 00000011

	// Bitwise Not ~	 
	unsigned char a4 = 6;		// 6 = 2^2 + 2^1 (decimal), 00000110(binary) 
	
	printf("%hhu\n", ~a4);	    // 249                    , 11111001
	                            // 249 = 2^7 + 2^6 + 2^5 + 2^4 + 2^3 + 2^0

	return 0;
}

// ��Ʈ ���� �� �����ڰ� � ��Ģ�� ���� ����� �Ǵ��� ���� �ô�.
// �̾����� ���ǿ��� ���� ������ �ٷ� ���ڴ�. 