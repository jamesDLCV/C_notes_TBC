#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ����ü�� �޸� �Ҵ�, memory allocation
//
// �迭������ �ڷ����� ���� ���ҵ��� �迭�� �ִ� ���¿����Ƿ� ���ذ� ��������
// ����ü������ �ڷ����� ���� �ٸ� ������� ������ �ִ� �����̹Ƿ�, 
// ���������� ȿ������ ���̱� ���ؼ� �޸� padding �е��̶�� ���� ����Ѵ�. 

int main() {
	/*
		Well aligned structure
	*/

	struct Aligned
	{
		int a;
		float b;
		double c;
	};

	/*
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
	|int a  |float b|double c             |
	4 + 4 + 8 = 16
	*/

	struct Aligned a1, a2;

	printf("struct Aligned a1\n");
	printf("Sizeof %zd\n", sizeof(struct Aligned));
	printf("%lld\n", (long long)&a1);
	printf("%lld\n", (long long)&a1.a);
	printf("%lld\n", (long long)&a1.b);
	printf("%lld\n", (long long)&a1.c);

	printf("\nstruct Aligned a2\n");
	printf("Sizeof %zd\n", sizeof(a2));
	printf("%lld\n", (long long)&a2);
	printf("%lld\n", (long long)&a2.a);
	printf("%lld\n", (long long)&a2.b);
	printf("%lld\n", (long long)&a2.c);

	/*
		padding (struct member alignment)
		- 1 word: 4 bytes in x86, 8 bytes in x64
	*/

	struct Padded1 {
		char a;
		float b;
		double c;
	};

	/* Without padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|a|float b|double c          | ?  ?  ?
	1 + 4 + 8 = 13	
	*/

	/* With padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|char a |float b|double c             | 
	4(char?) + 4 + 8 = 16
	*/

	struct Padded1 p1;

	printf("\nstruct Padded1 p1\n");
	printf("Sizeof %zd\n", sizeof(p1));	// 4 + 4 + 8
	printf("%lld\n", (long long)&p1);
	printf("%lld\n", (long long)&p1.a);
	printf("%lld\n", (long long)&p1.b);
	printf("%lld\n", (long long)&p1.c);

	struct Padded2 {
		float a;				
		double b;
		char c;
	};

	/* 
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|float a        |double b             |char c
	8(float?) + 8 + 8 = 24
	*/

	struct Padded2 p2;

	printf("\nstruct Padded2 p2\n");
	printf("Sizeof %zd\n", sizeof(p2));	// 4 + 4 + 8
	printf("%lld\n", (long long)&p2);
	printf("%lld\n", (long long)&p2.a);
	printf("%lld\n", (long long)&p2.b);
	printf("%lld\n", (long long)&p2.c);

	struct Padded3 {
		char a;
		double b;
		double c;
	};

	/*
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|char a         |double b             |double c
	8(char?) + 8 + 8 = 24
	*/

	struct Padded3 p3;

	printf("\nstruct Padded3 p3\n");
	printf("Sizeof %zd\n", sizeof(p3));	// 4 + 4 + 8
	printf("%lld\n", (long long)&p3);
	printf("%lld\n", (long long)&p3.a);
	printf("%lld\n", (long long)&p3.b);
	printf("%lld\n", (long long)&p3.c);

	struct Person {
		char name[41];	// member
		int age;		// member
		float height;	// member
	};

	struct Person mommy;

	printf("\nstruct Person\n");
	printf("Sizeof %zd\n", sizeof(mommy));	// 41 + 4 + 4 = 49?
	printf("%lld\n", (long long)&mommy.name[0]);
	printf("%lld\n", (long long)&mommy.age);
	printf("%lld\n", (long long)&mommy.height);
	
	struct Person f[4];

	printf("\nSiezof a structure array %zd\n", sizeof(f));

/*
|f[0].name |f[0].age |f[0].height|... ...|f[3].name |f[3].age |f[3].height|
*/

	return 0;
}

// struct Aligned
// {
//  	int a;
//  	float b;
//  	double c;
// };
// 
// <= ����ü�� �̷��� 4bytes, 4bytes, 8bytes �� ���� ����� ������ �ִ�. 
//    �� 16bytes�� ����� ������ �ִ�. 
// 
	/*
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
	|int a  |float b|double c             |
	4 + 4 + 8 = 16
	*/

//  <= �̿� ���� ������ 4����Ʈ, 4����Ʈ, 8����Ʈ�� �޸𸮿� ��� ���� ���̴�. 
// 
// ������ �̷��� ����ü�� �����ϴ� �͸����δ� �޸𸮸� �������� �ʴ´�. 
// ������ �����ϴ� ��ó�� ������ �޸� ������Ʈ�� ������ �� ���̶�� ������ �� ������, 
// �̷��� �޸𸮸� ����ϰڴ�, 
// �̷��� ������ ¥���� �ִ� ������ ������Ʈ�� ����ڴٴ� 
// ���ø�(Ʋ)�� �����ϴ� ���̴�. 
// 
// struct Aligned a1, a2;
// <= ������ ����ü ������ ������� ��, �޸𸮰� ������ �ڸ��� ������,
//    ������ ������Ʈ�� ������ �ǰ�, 
//    �� ������ ������Ʈ�� a1, a2��� �ν��ڸ� ���ؼ� �����ؼ� ����� �� �ְ� �ȴ�. 
// 
// �޸𸮸� �󸶳� ����ϴ��� sizeof�� ��� ����. 
// 
//struct Aligned a1
//Sizeof 16
//337150671272
//337150671272
//337150671276
//337150671280
//
//struct Aligned a2
//Sizeof 16
//337150671320
//337150671320
//337150671324
//337150671328
//
// a1 ��ü�� �ּҿ� a1.a(a1�� ù ��° ���)�� �ּҰ� �����ϴ�. 
// ���� �ּҿ��� ���̰� 4bytes�� �����. 
// int a�� float b�� ���� 4bytes�� �����ϰ� 
// double c�� ������ 8bytes�� �����ϴ� ���̴�. 
//
// ����ü�� ������ ���� �̷��� �޸𸮸� ����ϰڴٶ�� Ʋ�� ������ ���̰�, 
// ������ ��Ű Ʋ�� �̿��ؼ� ��Ű�� ���� ����, 
// struct Aligned a1, a2; �̷��� ���� a1, a2�� �����ϴ� ���̴�. 
// a1�� a2�� ������ �޸� ���·� ���ȴ�. 
// 
// �޸� �е� padding�� ���ؼ� ���� ����. 
// ���� �ǿ��� ���°� �߻��Ѵ�. 
// 
// 	struct Padded1 {
//		char a;
//		float b;
//		double c;
//	};
// 
// <= �� struct�� ���� 1 + 4 + 8 = 13 bytes������,
//    ����� ������ ��� ����, 16 bytes�� ���´�. 
//    ���ʹ� �ٸ��� 13 ����Ʈ�� �ƴ� 16 ����Ʈ�� ���´�. 
// 
// �����Ϸ��� char a���ٰ� ����� �� ���� �־� ������. 

	/* With padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|char a |float b|double c             |
	4(char?) + 4 + 8 = 16
	*/

// �׷��� p1.a�� char �ӿ��� �ұ��ϰ� 4 bytes�� ������ ���´�. 
// �����Ϸ��� 3 bytes�� �� �־� �� ���̴�. padding�� �־� �� ���̴�. 
// 1 byte ¥���� ��ġ 4 bytes ¥���� ��ó�� �� ���� ������ ������ �־� ���. 
// 
// �� �����Ϸ��� �̷��� padding�� �־� �ִ°�?
// 
    /*
		padding (struct member alignment)
		- 1 word: 4 bytes in x86, 8 bytes in x64
	*/
// 
// �е��� struct member alignment��� �Ѵ�. 
// alignment�� �ٸ����� �� �ִ� ���̴�. 
// 
// �ٸ����� �� �� �ִ°�?
// 
// ������ ǥ���ϴ� �ּ� ������ bit, 0�̳� 1�̳ĸ� ǥ���ϴ� ����.
// �޸𸮿��� �ּҸ� �����ϴ� �ּ� ������ 8 bits, 8 bits�� ��� 1 byte��� �Ѵ�.
// 
// �޸𸮿� CPU�� �����͸� �ְ� ���� ��, 1 bit�� 1 byte�� �ְ� ���� �ʴ´�. 
// �����͸� ��� ������ ȿ������ ����. 
// �׷��� �󸶳� ���� ���� �����͸� ��� ������?
// 
// �����͸� ��� ������ ������ word�̴�. 
// 1 word: 4 bytes in x86, 8 bytes in x64
// <= 32��Ʈ������ 4 ����Ʈ, 64��Ʈ������ 8 ����Ʈ�̴�. 
// 
// ���� ��� 4�� Ż �� �ִ� ���̱ⱸ���� ȥ�� �� ����� �ְ� �ڿ� 4���� ������ �ִٸ�,
// �� ����� ���� �¿�� �� �ڸ��� ��� �� ä�� ������ 4�� ������ �¿�� �ȴ�. 
// 
// �����͸� ���� �� 8 ����Ʈ�� �����ٰ� ������ ����,
// �е��� ���� �ʴ´ٸ�, 
// ���� ó�� char 1����Ʈ�� �ְ�, �� ���� float b�� �ִ´�. �׷� 3����Ʈ�� ���´�.
// ���� ���� 3 ����Ʈ ������ double�� ���� �ִ´ٸ�, 
// ������ 5 ����Ʈ�� ���� �޸𸮿� ������ �ȴ�. ©���� �ȴ�. 
// �׸��� �� �������� �ָ�������. 
// 
	/* Without padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|a|float b|double c          | ?  ?  ?
	1 + 4 + 8 = 13
	*/
// �̿� ���� �е��� �� �� �ָ� ȿ������ ���� �ʰ� �ȴ�. 
// �������� ������� ���� ���̶��, �� ������� char ������ �־� �༭,
// ���� ���� �ְڴٴ� ���̴�. 
// �׷��� double�� ������ �� ȿ������ ���� ���̶�� �� �⺻���� ���̵���̴�. 
// 
	/* With padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|char a |float b|double c             |
	4(char?) + 4 + 8 = 16
	*/
// <= �̷��� char a �������ٰ� ����� �� ���� �־� �� ���̴�. 
//    �׷��� char �� ������ ���� 1 ����Ʈ���ٰ� 3 ����Ʈ padding, 
//    �� 4 ����Ʈ�� �ǰ� �ű⿡�ٰ� float 4 ����Ʈ�� ���ؼ� �� 8 ����Ʈ�� �ȴ�. 
// 
//    �� 8 ����Ʈ�� ��� �� �� ������, 
//    �� ������ double c 8 ����Ʈ�� ������, 
//    cpu ���忡���� ����ϰ� �޾Ƽ� ����ϰ� ����� �� �� �ִ�. 
// 
// �е��� ��� 8 ����Ʈ�� ���� ������ without padding����ó�� ©�� ������, 
// (�е��� ��� alignment�� �� ���� �ʴ´ٸ�)
// 8 ����Ʈ ������ ©���� ������ cpu ���忡���� ������ �� �ִ�. 
// <= ȿ���� �������� �ȴ�. 
//    �׷��Ƿ� padding�� �ʿ��ϴٷ� ������ ����. 
// 
// 	struct Padded1 {
//		char a;
//		float b;
//		double c;
//	};
// <= ���� char, float, double ����� ������ �ٲ㵵 ȿ������ �޶�����. 
// 
	/*
		struct Padded2 {
			float a;
			double b;
			char c;
		};
	*/

// <= ����� ������ �ٲ��. 

	/*
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|float a        |double b             |char c
	8(float?) + 8 + 8 = 24
	*/

// ������ ���� ����, ����� 24�� ���´�. 
// ���ϰ� ��ȿ�����̴�. 13�̸� �� �� 24�� ���� �ִ�. 
// float a�� 8 ����Ʈ�� �����ϰ�, double b�� �� 8 ����Ʈ�� �����ϰ�, 
// char �� 8 ����Ʈ�� �����ϴ� ������ �߻��Ѵ�. 
// 
// �̷��� �Ǵ� ������? 
// �����Ϸ��� double�� �� ���� �� word�� �Ǿ ��°�� ��������  
// float a���� padding�� �־� �ְ�, char c���� padding�� �־� �ְ� �ȴ�. 
// 
// struct Padded1�� struct Padded2�� ����� ����������, 
// �е� ������ Padded1�� ȿ���� �� ����. 
// 
// 8 ����Ʈ���� ���� char�� float�� �����ؼ� �־��� ������, 
// �е��� char �ϳ����� ����. Padded2ó�� float���� �е��� ���� �ʾҴ�. 
// 
// Padded2�� Padded1�� �Ȱ��� �������� ������ �ִ� structure������, 
// float�� char �� ������ �е��� ���� ����� Ŀ����. �� ȿ�����̴�. 
// 
// ���α׷� �Ƿ��� �������� �̷� �ͱ��� ����ؼ� ����ü�� �����ϱ� �ٶ���. 
// 
// �Ʒ��� ���� ����� ������ �Ǹ�, char�� ������� 7 ����Ʈ�� ä������ �ȴ�. 
// <= 7 ����Ʈ�� �߰��� �е��� �ȴ�. 
	/*
	struct Padded3 {
		char a;
		double b;
		double c;
	};
	*/
//
	/*
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|char a         |double b             |double c
	8(char?) + 8 + 8 = 24
	*/
// 
// �Ʒ��� ���� �迭�� ���� �е��� �����. 
// 
	/*
	struct Person {
		char name[41];	// member
		int age;		// member
		float height;	// member
	};
	*/
// 
// name�� �迭�� 41���̴�. ���� �ָ��� �����̴�. 
// ����� ��� ����, 3 ����Ʈ�� �߰��� ���� 52 ����Ʈ�� �ȴ�. 
// <= 41 + 4 + 4 = 49���� �ϳ�, 3 ����Ʈ�� �߰��ż� 52����Ʈ�� �ƴ�. 
// 
// name�� �����ϴ� �޸𸮰� 41�� �ƴϰ� 44 ����Ʈ�� �ƴ�. 
// <= �迭�� ��쿡�� struct���� padding�� ���� �� �ִ�. 
// 
// �Ʒ��� �е����� ���� �ٸ� ����̴�. 
// ����ü�� �迭�� ������� ��, �޸𸮰� ��� ������ �Ǵ°�?
// 
// struct Person f[4];
// 
// printf("\nSiezof a structure array %zd\n", sizeof(f));
//
// <= ����ü�� �迭�� ������ �ȴ�. 

/*
|f[0].name |f[0].age |f[0].height|... ...|f[3].name |f[3].age |f[3].height|
*/

// <= �̷� ������ �޸𸮸� ����ϰ� �ȴ�. ����ü�� �迭�� ����� �� �ִ�. 
// f ��ü�� �迭�̴�. 
// 
// ���ݱ����� �е��� �����Ϸ��� ����� �� ���̴�. 
// �����Ϸ��� ���⿡ word ������ ������ �� ȿ�����̴ϱ� 
// �е��� �־�� word ������ ������. 
// Ư�� double ���� 8 ����Ʈ ¥���� ���� ��쿡, 
// �� ���� ����ϰ� �� �� �ֵ��� allignment�� ���� ���ڴ� �ǹ��̴�. 
// 
// Solution Explorer â���� c ������ ������ �� ��Ŭ���Ѵ� > 
// C/C++�� All Options�� ���� > �˻� â���� struct�� �˻��Ѵ� >
// Struct Member Alignment�� Default�� �� �ִ� ���� �� �� �ִ�. 
// ȭ��ǥ�� ������ ���� ����, 1 Byte, 2 Bytes, 4 Bytes, 8 Bytes, 16 Bytes, defalut
// �� �ִ�. 
// <= �е��� �� �������� 1 Byte�� �����ϸ� �ȴ�. �ѹ� �� ����. 
// 
// p1�� �е��� �ϸ� ����� 16�̾�����, 13�� ���´�. 
// �̷��� �ɼ����� �е��� ������ ���� �ִ�. 
// 
// ����ü�� �޸𸮸� ��� ����ϴ��� �е� ����� �Բ� ���� �ô�.