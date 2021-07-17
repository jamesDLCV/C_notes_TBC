#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// duration�� ���ؼ� ���캻��.
// duration��, �޸𸮸� ������ ������ �ִ� ���� ���� �Ⱓ�� �ǹ��Ѵ�. 

/*
	Storage duration:
	- static storage duration	// ���⿡���� static�� 
								// �Ʒ� Note������ static�� �ǹ̰� �ٸ���.
	(Note: 'static' keyword indicates the linkage type, not the storage duration)
	- automatic storage duration
	- allocated storage duration
	- thread storage duration
*/

// storage duration�� ���� �� ������ �ִ�. 
// - static storage duration
//		���α׷��� ������ �� ��, �޸𸮿� �ڸ��� ��� 
//		���� ������ ��� static�ϰ� �ӹ���. 
//      ������ ������ ���� ������ �޸𸮿� ��� ���������� �ڸ��� ��� �ִ�. 
// 
//		���� �տ� ���̴� static key word�ϰ�� �ǹ̰� ���� �ٸ���. 
//		static key word�� linkage type�� �ǹ��ϰ�, ���� ������ ����� ���ϵ���
//		������ ��Ų��. Scope�� �о����� �ʵ��� ���ƹ����ٴ� �ǹ��̴�. 
//		storage duration�� �ǹ̿ʹ� �ٸ���. Static storage duration�� static��
//		�׳� ������ static�� �ǹ��Ѵ�.  
// 
// - automatic storage duration�� ���� ���������� �ǹ��Ѵ�. 
//		�޸� ���̾ƿ��� Stack�� ������ �ȴ�. 
//		
// - allocated storage duration
//		�����Ҵ�� ������ �ִ�. �� �κ��� �� �����ؾ� �Ѵ�. 
// 
// - thread storage duration
//		multi threading �����̴�. 
//		�⺻ ���ǿ����� �ٷ��� �ʴ´�. �Ŀ� ���� ���ǿ��� �ٷ�ڴ�. 
// 


void count() {
	int ct = 0;
	printf("count = %d\n", ct);
	ct++;
}

void static_count() {
	static int ct = 0;	// static�� ���̸�, ���α׷��� ���۵� �� �޸𸮿� ������,
						// ���α׷��� ���� ������ ��� ���õȴ�. 
						// �ٽ� �������� �ʴ´�. 
	printf("static count = %d\n", ct);
	ct++;
}

int main() {
	count();			// count = 0
	count();			// count = 0
						// ���⿡���� ct�� ���� ���۵� �� ������ �Ǹ鼭 ���ܳ��ٰ�
						// ���� ������ �ڵ����� �������. 

	static_count();		// static count = 0
	static_count();		// static count = 1
						// �и��� ������ ��������, ct�� ������� �ʰ� ���� �ִ�.
						// ���α׷��� ������ �� ��򰡿� �ڸ��� ��� �ְ�,
						// ���α׷��� ���� �� �������. 
						// 
						// ���⿡���� ct�� ���� ���۵� �� ������ �Ǹ鼭 ���ݳ���
						// ���α׷��� ���� ������ ������� �ʰ� ���� �ִٰ� 
						// ���α׷��� ����� �� �������. 

	return 0;
}

// ������ ����, 
// ������ ���� ����, 
// ��ü�� ���� �Ⱓ
// �� �� ������ ���ؼ� ���� �ô�. 
