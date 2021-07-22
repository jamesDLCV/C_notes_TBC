#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int* count() {
	int ct = 0;	
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;
}

int* static_count() {
	static int ct = 0;	

	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;
}

void counter_caller() {
	count();
}

void static_counter_caller() {
	static_count();
}

int main() {
	count();			
	count();			
	count();			
	counter_caller();	  

	static_count();				
	static_count();				
	static_count();				
	static_counter_caller();	

	return 0;
}

// ���� ��ȯ�� �� ��, ������ ��ȯ�� �ϰ� ��ȯ ���� �޴� �ʿ��� �̹� �޸𸮸� ������ �ְ�,
// �ű⿡ �����ϴ� ���·� ���� �Ѵ�. 
// 
// ������, �����͸� ��ȯ�ϴ� ��쵵 �� �ִ�. 
// API�� ����ϰų�, �ϵ���� ���� �� API�� ����� ���
// ���� ������ ���� ��� ���콺�� ������ �� �ִ� �����͸� ������ �´� ���.
//  <= �����͸� ��ȯ�ϴ� ���� ����. 
//
// // warning C4172: returning address of local variable or temporary: ct
// �����ϸ� �̿� ���� warning�� ���. 
// 
// ���� �����ϱ�?
// 
// �޴� �ʿ��� �����͸� �޴´ٴ� ����, �� �޸𸮿� ���ؼ� ���� �۾��� �ϰ� ���� ��, 
// �����ͷ� �޴� ���̴�. 
// ct�� ���� ������ ������ &ct�� ��ȯ�� �ְ� �ִµ�, 
// ������, ���� ct�� ����� �����, �������. 
// 
// stack frame ��ü�� ����� �� �ִ� �޸𸮸� �̸� ��� ���� ��찡 �ֱ� ������, 
// �����ͷ� ������ �ؼ� ������ ������ ��쵵 �ִ�. 
// ������ �װ��� �����Ϸ��� ���α׷��� �����ϱ� ���ؼ� 
// ����ϴ� ����� ���� �ǿ�(?) �����ϴ� ���α׷��� ����̴�. 
//
//int* count() {
//	int ct = 0;
//	printf("count = %d %lld\n", ct, (long long)&ct);
//	ct++;
//
//	return &ct;
//}
// �̷��� ���α׷����ϴ� ���� ���� ������ �ʴ�.  
// �Ǵ���� �̷��� �ϴ� ���� �� ����. �ٸ� ����� ���� �� �ǵ��� �����ϱⰡ ���� �ʴ�. 
// ���� ���߿� ���� �����ϱ� ��ư�, ���� �����ϴٰ� ������ ���ɼ��� ũ��. 
// ���� return &ct; <= �̷� ����� ��ȯ �� ����� ���� ���� �ʴ�. 
// 
//	int* static_count() {
//		static int ct = 0;
//
//		printf("static count = %d %lld\n", ct, (long long)&ct);
//		ct++;
//
//		return &ct;
//	}
// ������ �̰��� ��찡 ���� �ٸ���. 
// ��¥ �� �ʿ��� ���, ��¿ �� ���� ����ؾ߸� �ϴ� ��쿡�� ����� �� �ִ�. 
// 
// �� �����ϴ���? static int ct = 0;�� �޸𸮿� ������ �ڸ�(�ּ�)�� ������ �����Ƿ�
// �����ͷ� ��ȯ�ؼ� �ٸ� ������ �� ���� �ִ�.  
// ������ �̷��Ա��� �ؼ� static int ct�� �ۿ��� �����ϰ� ���� ����,
// ���� ���� ������ ���� ���� ����. 
// 