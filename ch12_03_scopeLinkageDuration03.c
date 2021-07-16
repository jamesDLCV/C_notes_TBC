#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// linkage�� ���ؼ� ���� ����.
// �̷��� �ڵ��ϴ� ���� ���� �ʴ�. 
// �� ������Ʈ �ؿ� C ������ �� ���� �ִ�. 
// ������ ���� ������ �ڵ��� �Ѵ�. 
// 
// �� ������, �����Ϸ��� �������� �ϴ� �ּ� �����̴�. 
// tanslation unit�̶�� �Ѵ�. 
// �����Ϸ��� ������ �������̴�. 
// ���α׷��� ���� �ۼ��� ������ ����� ������ �� �ִ� ���̴�. 
// tanslation unit�� ������ ������ ���̴�. 
// 
// �׷��Ƿ� ���� ������Ʈ �Ʒ��� �ִ� C ���� �� ���� 
// �����Ϸ��� ���� ���� �������� �Ѵ�.
// �׷��Ƿ� ���� ���� ���� �ִ��� ���� �� ����� ����. 
// �� �� ���� ������ ������ �ִ� ���� linker�̴�. 

/*
	Linkage

	Variable with block scope, function
	- No linkage

	File scope variables
	- External or internal linkage
*/

// ���� ��ü���� ����� �� �ִ� scope�� ����� �ִ�. 
// Ư�� �Լ���, Ư�� ����� scope�� ����� ���� �ʴ�. 
int el;		// file scope with external linkage (global)
static int il;	// file scope with internal linkage				

void testLinkage();	// �ٸ� ���Ͽ� �ִ� �Լ��� ��ü�� main() �Լ����� ����ϱ� ����, 
					// prototype�� ������ �� �־���. linking�ϴ� �����̴�. 

int main() {

	el = 1024;

	testLinkage();

	printf("%d\n", el);	// �ٸ� ���Ͽ��� ó���� el ���� ��µȴ�. 
						// el ������ ���������� ������ �ִ� object���� 
						// ���� �� �ٲ� ���̴�. 
		// �� ������ ���� el�� �ٸ� ������ el�� object�� �����ϰ� �ִ�.
		// ��� ���Ͽ�����, ��� translation unit������, ����� �� �ִ�.
		// <= global variable�̶�� �Ѵ�. 
						

	return 0;
}

/* 
int el;		// file scope with external linkage (global)
			// el�� ����� �ִٴ� ���� ���� ������Ʈ ���� �ٸ� ���Ͽ����� �˼��� ����.
			// �ٸ� ���Ͽ��� �����ϱ� ���ؼ��� extern�̶�� Ű���带 ����Ѵ�.
	// file scope�� �ִ� ������, ��ġ ���α׷� ��ü���� ����� �� �ִ� ��ó��,
	// �� ��������ó�� ����� �� �־ <= ����������� �θ���.
	// ���������� ���� ���� ������, file scope�� ���� ���� �ִ�.
	// �ٸ� ���Ͽ��� extern�� ����ؼ� �� ���������� ����� �� �ִ�.

static int il;	// file scope with internal linkage
				// �ٸ� ���Ͽ����� �� ���� �����Ƿ� internal linakge�̴�.
				// Ű����μ��� static��,
				// �� ������ ������ ���� scope�� ���ѵȴٶ�� �ǹ̰� �ִ�.
				// �����̴�.
				// �ٸ� ���� scope���� ����� �� ����.
				// �ٸ� ���Ͽ��� extern���� ������ �� ����.
				// �ٸ� ���Ͽ��� ����ϸ�, unresolved externals Error�� ���.

*/

