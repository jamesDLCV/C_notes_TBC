#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ��� ������ static ���� ���� 
// �������̸鼭 ��� scope�� ���� ������ ����� �� �ִ�. 
// <= storage class �з� ǥ�� �ټ� ��° static with no linkage �з� ����. 
// 
// �������̶�� ���� ���α׷��� ���ۺ��� ������ �޸𸮿� ��� �ڸ��� ��� �ִٴ� ���̴�. 
// ���� ����ó�� ����� �� �ִٰ� ������ �� �ִ�. 
// ������ static with no linkage ���� ���� ��� �ȿ����� ����� �� �ִ�. 
// �� ��� �޸��� ��ġ�� ������ �Ǵ� BSS�� �ְ� ���� �Ⱓ�� ������������, 
// Linkage�� ����. 
// ������ duration�� �������̹Ƿ�, �����͸� ����ؼ� ���������� �����ؼ� ����� �� �ִ�. 
// �ٸ�, ��� �ȿ��� �����ؼ� ����ϴ� static variable�ε�, 
// ���� ��� �ۿ��� ����ϰ� �ʹٸ�, �� ���� ����� �ʿ䰡 ����. 
// �׳� global variable�� �����ؼ� ����ϸ� �ȴ�. 
// 
// �ڵ带 ���� �������� �����ϰ� ���� ����. 
//  

void count() {
	int ct = 0;	// <= �� ����� ����� ������ �� ����. ���ÿ��� �������� ������.
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//TODO: return &ct;
}

void static_count() {
	static int ct = 0;	// initialized only once! �ʱ�ȭ�� �� ���� �ȴ�. 
					
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//TODO: return &ct;
}

void counter_caller() {
	count();
}

void static_counter_caller() {
	static_count();
}

int main() {
	count();			// 0 7338816
	count();			// 0 7338816 
	count();			// 0 7338816
	counter_caller();	// 0 7338604 <= count() �Լ��� ȣ���ϴ� �ٸ� �Լ��̴�.
							   	  // <= ���ο� �޸𸮰� �����ƴ�.  

	static_count();				// 0 1220920
	static_count();				// 1 1220920
	static_count();				// 2 1220920
	static_counter_caller();	// 3 1220920 <= static_count() �Լ��� ȣ���ϴ� �Լ�
										  // <= �̷��� �ص� �޸� ��ġ�� �Ȱ���. 
	// static�� non-static�� �޸� �ּҸ� ���Ǵ�, �� �ָ� ������ �ִ�. 

	return 0;
}

int func(static int i) // Warning (Error in GCC)
{

}
// (63,22): warning C4042: 'i': has bad storage class

//int ct = 0;	// <= stack�� ��ġ�Ѵ�. 
// 
//static int ct = 0;	// initialized only once! �ʱ�ȭ�� �� ���� �ȴ�. 
						// int ct = 0;�� ���÷� �ʱ�ȭ�� �����ϴ�. <= ū �������̴�. 
						// ���� �޸𸮿� �����Ƿ� �翬�� �� ���� �ʱ�ȭ�Ǵ� ���̴�. 
						// stack�� �ƴ� DATA�̳� BSS ���� ������ ����ȴ�. 
						// ���α׷��� ���� ������ ���������� ��� �����Ǵ�, 
						// static�ϰ� �����Ǵ� ������ ����ȴ�. 
//
// static int ct = 0; ��
// static int ct;
// ct = 0; �� ���������� ���� �ٸ���. 
// 
// int ct = 0; ��
// int ct;
// ct = 0; �� ������ �����ϴ�.
// 
// static int ct = 0;
// ct = 0; <= �̰��� �׳� �����ϴ� ���´�. �ʱ�ȭ�� �ƴϴ�. 
// 
// int ct = 0;�� ���ÿ� �ö�� ������ ��� �ʱ�ȭ�� �ȴ�. 
// ����� ����� ���ÿ��� ���������ٰ� �ٽ� ȣ���� �Ǹ� �ٽ� �ʱ�ȭ�� �ȴ�. 
// 
// static int ct = 0; �� ���� �޸𸮿� ���Ƿ�, �ʱ�ȭ�� �� ���� �ȴ�. 
// 
// int func(static int i) // Warning in Visual studio (Error in GCC)
// �Լ��� parameter�� static�� ����� �� ����. 
// 
// �Լ��� ����� ���� ���ο� statck frame�� �����ȴ�. 
// �׷��Ƿ� parameter ������ �Լ��� ����� �� �޸𸮸� �����޴� �����̴�. 
// stack frame �ȿ� �ڱ� �޸𸮸� ���� ������ �� �ִ�. 
// �׷���, parameter �տ� static�� ���̸�, parameter ������ static�� �޸� ������ 
// ���� �ְڴٴ� ���� �ȴ�. <= ���� �� �´´�. 
// 
// ���� �̷� ������ ���� �ʹٸ�, ���� ������ ���簡 �ٸ� ����� ����ؾ� �Ѵ�. 
// 
