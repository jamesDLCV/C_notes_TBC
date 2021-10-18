#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h>	// strlen()
#include <stdlib.h>	// exit()

// ���� ����
// ������ -> ������ ��ȯ

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
     // const char bi[]�� ���ڿ� �Է��� �ް� �ִ�.
     // ��ȯ �ڷ����� unsigned char�� �ߴ�. 
	 // bi[] ���̿� ���� unsigned char�� ���� �ְ�, unsigned int�� ���� �ְ�,
	 // unsigned long�� ���� �ִ�. <= �����ϱ� �����̴�. 
	 // �ʹ� ���� ������ �������� ������, 8 ���ڸ� ���� ���ؼ� unsigned char�� �ߴ�. 
	 
	const size_t bits = strlen(bi);
     // �Է� ���� ���ڿ��� �� �� ����, �׷��ϱ� �� bits ¥�� 2������ ��ȯ�Ϸ��� �ϴ���
	 // Ȯ���� �ϱ� ���ؼ� strlen() �Լ� ���.  
	 // size_t�� x86������ unsigned int�̰� x64������ unsigned long long�̴�. 
	 // C����� �̽ļ��� ���� �ִ� �ڷ����̴�. 


	unsigned char sum = 0;	// ���� ���ؾ� �ϹǷ� sum�� ����, �ʱ�ȭ�� ���.
	for (size_t i = 0; i < bits; ++i) {
	 // <= bits�� ���̸� ���� ��, size_t�� ��������Ƿ�, 
	 //    �ݺ��� ���Ǵ� ���� i�� size_t�� �����ߴ�. 
	 //    C++������ x86���� x64��, ��������� �������� �Ű� �ٴϸ鼭 �������ϴ� 
	 //    ��찡 �����Ƿ�, �̷��� size_t�� ����ϴ� ��찡 ���� �������� �ִ�.
	 //    C++ STL������ size_t�� ���� ����Ѵ�. 
	 // ���ݺ��� ���� �ͼ��ϰ� �� �θ�, ������ �� ���̴�. 
	 // ���� ���ǿ����� int�� �ϴ� ���� �Ϲ����̴�. 

		if (bi[i] == '1') {
			sum += (int)pow(2, bits - 1 - i);
			// <= 2������ �������� �����ϴ� ������ pow() �Լ��� ����.
			// (int)pow(2, bits - 1 - i);
			//   <= �� ������ ������ ������ �� ������ �ֶ�.

			// ����) pow() ���� ���(warning)�� ���ְ� �ʹٸ�, 
			// �Ʒ��� ���� ����ȯ�� �϶�.
            // sum += (unsigned char)pow((double)2, (double)(bits - 1 - i));
			
			// 0�� ���� ������ �Է��� �ʿ䰡 �����Ƿ� �ƹ� �۾��� ����. 

		} else if (bi[i] != '0') {
			// 0�� 1�� �Է��� �ž� �ϴµ�, �׿� �ٸ� ���ڳ� ���ڸ� �Է����� ������,		
			printf("Wrong character: %c", bi[i]);
			// <= �Է��� �߸��ƴٴ� �޽����� ����� �ش�. 
			//    ��� ������ �ݵ�� �ʿ��� ���� �ƴϴ�. 
			// ���α׷����� �� ���� ������� �Ǽ��� ����ϴ� ���� ����. 

			exit(1);
			// �� �Լ��� ���� �߿��� �κ��� ��쿡��, 
			// �̷� ���ܰ� �߻��ϸ� �� �̻� ������ ���� ���� �����Ƿ�, 
			// ���� �����Ų��. 
		}
	}

	return sum;
	printf("Binary %s == Decimal %d\n", bi, sum);
}
*/

// ����� ���������� �۵��Ѵٸ�, ������ �Լ��� �̿� �Ȱ��� �ʾƵ� �ȴ�. 
//
// �������� �������� ��ȯ�ϴ� �Լ��� �����ϰ� ����� �ô�.
// ���� ���ǿ����� �� �Լ��� �̿��ؼ� ��Ʈ ���� �����ڿ� ���ؼ� �� ���� ����.