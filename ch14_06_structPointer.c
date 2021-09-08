#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

// ����ü�� ������
// 
// ����ü�� ���� �����ʹ� �ռ� ���¿��� �Ұ��� ���� �ִ�. 
// �����ؾ� �� �� ���ַ� �� �� �� ���� ����. 

struct names{
	char given[LEN];
	char family[LEN];
};

struct friend {
	struct names full_name;		// nested struct
	char mobile[LEN];
};

int main() {
	struct friend my_friends[2] = {
		{ {"Ariana", "Grande"}, "1234-1234" },
		{ {"Taylor", "Swift"}, "6550-8888" }
	};

	struct friend* girl_friend;

	girl_friend = &my_friends[0];

	printf("%zd\n", sizeof(struct friend));
	printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
	// -> : indirect member access operator

	girl_friend++;

	printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.family);
	// . has higher precedence than *

	printf("\n\n************ example1 ************\n\n");

	main_example();

	return 0;
}

// ����ü ������ �迭�� �ϳ� �������. 
// 
//	struct friend my_friends[2] = {
//		{ {"Ariana", "Grande"}, "1234-1234" },
//		{ {"Taylor", "Swift"}, "6550-8888" }
//	};
// 
// <= full_name�� names�̰�, names�� given, family �� ���� �� �����Ƿ�, 
//    �̿� ���� �ʱ�ȭ�� �� ���. (nested struct �ʱ�ȭ�� �� ���) 
// 
// �̷��� my_friends��� ����ü ������ �迭[2]�� �������. 
// 
// struct friend* girl_friend;
// <= girl_friend��� '����ü friend Ÿ���� ������ ���� ������'�� �����ߴ�.
//    �����ϰ� �ٿ���, friend��� ����ü�� ����Ű�� ������ �����̴�. 
//    �� ���δٸ�, ����ü�� ���� �������̴ٶ�� �� �� �ִ�. 
//
// girl_friend = &my_friends[0];
// <= addressof �����ڸ� ����ؼ� ������ �Ѵ�. 
//    my_friends �迭���� ���� �������� ���ؼ� [0] indexing�� �ϰ�,
//    �ٽ� &�� �ּҸ� �������� �ִ�. 
//    �տ��� �迭, ������ �������� ���� �ٷＭ �ͼ��� ���̴�. 
//  
// printf("%zd\n", sizeof(struct friend));
// <= friend ����ü�� ����� ��� ����.
// 
// printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
//						// -> : indirect member access operator 
// <= girl_friend�� �ּҸ� ����Ѵ�. 
//    girl_friend�� ����ü�� ���� �������̱� ������, 
//    dot(.) operator�� ������� ���ϰ�, indirect operator(->)�� ����Ѵ�. 
// 
//    full_name�� �����Ͱ� �ƴϹǷ� dot(.) operator�� ����ؼ� 
//    names �ȿ� �ִ� given�� �����Ѵ�.
// 
//    �������� ���, �����Ͱ� �ƴ� ��찡 ��� �Ұ��ǰ� �ִ�. 
// 
// girl_friend++;
// <= ������ �����̴�. 
// 
// printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.family);
// <= ������ ���� �� ������ girl_friend�� �ּҸ� ����Ѵ�. 
//    (*girl_friend).full_name.family)��
//	  indirection�� �� �� �� �� dot operator�� ����� �����ϰ� �ִ�. 
//    dot operator�� indirection operator���� �켱 ������ ���� ������, 
//    ��ȣ�� �� ��� �Ѵ�.  
//    girl_friend->full_name.given�� �����ϴ�. 
// 
// �����ϸ�, ������ ���� ��µȴ�. 
// 60                     <=  sizeof(struct friend)�� 60�̴�.
// 214246292400 Ariana    <= 
// 214246292460 Swift     <= ����� 60�̴�. 
// 
// ������ ���꿡�� �ϳ��� ���Ѵٴ� ���� �� �ڷ����� �����ŭ ���������� 
// �޸� �ּҸ� ����(�ٲ�) �ش�. 
// 
// ���� ������ ����.