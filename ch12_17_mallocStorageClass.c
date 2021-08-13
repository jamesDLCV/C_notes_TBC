#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���� �Ҵ� �޸𸮿� ���� ���� �з�
// ���������� �����ϰ� �����Ѵ�. 
// 
// ���� �Ҵ� �޸𸮴� �ν��ڰ� ���� ������, (���� �̸��� ���� ������)
// Storage class ���� ���� �з����� �з��� �ټ� ������ �ش������ �ʴ´�. 
// 
// ���� �߿��� ���̴� Heap �޸𸮿� �����ϰ� �Ǵµ�, 
// �ü������ ���� �� ���� ũ���� �޸𸮰� �ʿ��ϴ�, �޸� ������ �Ҵ��� �޶�� 
// �䱸�ϸ�, �ü���� �����͸� �Ѱ� �ش�. 
// 
// malloc(), calloc(), realloc() ���� �Լ��� ����ϸ�, 
// �����͸� �Ѱ� �ش�. 
// �� �����͸� �ν��ڶ�� �� ���� �ְ� ���� �̸�ó�� ������ ���� �ִ�.
// �ּҸ� ���� �ִ� ������ ������, �ν���ó�� Ư�� �ڵ� ����ó�� 
// �ڵ����� duration�� ������ ������ �ʴ´�. <= �޸� �������� �����ߴ�. 
// 
// ���� �������� ��ġ�ϰ� �� �޸𸮴�, ���α׷��Ӱ� ������ �޶�, �� ���, 
// ���� ����� �䱸�� ������, �� �޸𸮿� ��� �ڸ��� ��� �ְ� �ȴ�. 
// 
// �� ������ �ٽ� �ѹ� ����.  

int g = 123;

void func() {
	int i = 123;
	printf("Local variable		\t%lld\n", (long long)&i);
}

int main() {
	const char* message = "Banana";

	void (*f_ptr)() = func;	// address of a function

	printf("Local pointer		\t%lld\n", (long long)& message);
	printf("Function pointer	\t%lld\n", (long long)& f_ptr);
	printf("String data		\t%lld\n", (long long)message);
	printf("Function address	\t%lld\n", (long long)f_ptr);
	printf("Function address	\t%lld\n", (long long)main);
	printf("Global variabe		\t%lld\n", (long long)& g);

	func();

	int* ptr = (int*)malloc(100 * sizeof(int));
	if (!ptr) exit(EXIT_FAILURE);

	printf("Allocated memory	\t%lld\n", (long long)ptr);

	free(ptr);
	
	return 0;
}

// ������ �ϸ�, ������ ����. 
// Local pointer                   153944980120
// Function pointer                153944980152
// String data                     140700016745868
// Function address                140700016710047
// Function address                140700016710252
// Global variabe                  140700016754688
// Local variable                  153944979828
// Allocated memory                2311734362880
// 
// �ּҰ��� ���⼺�� ����, 
// Local pointer, Function pointer, Local variabldl�� ������,
// String data, Function address�� �ּҰ� ������. 
// Global variable <= GCC������ �ٸ� ��ġ�� ������, ���⿡���� ����� ��ġ�� ���δ�.
// Allocated memory�� �� �ٸ� ���� ��ġ�ϰ� �ִ� �ּ�ó�� ���δ�. 
// 
// printf("Local pointer		\t%lld\n", (long long)& message);
//	message pointer ��ü�� �ּҸ� ��� �ִ�. 
//  ������ ��ü�� ���� ������. <= stack���� ����. GCC������ �ּڰ��� ����.
// 
// printf("Function pointer	\t%lld\n", (long long)&f_ptr);
//	function pointer ��ü�� �ּҸ� ����ϰ� �ִ�. 
//	function ��ü�� �޸𸮿� ����ȴ�. <= stack���� ����. GCC������ �ּڰ��� ����.
// 
// printf("String data		\t%lld\n", (long long)message);
//	message ��ü�� �ּҸ� ���.
//  message = "Banana"�� �������� �� exe ���Ͽ� ���� ž�簡 �ȴ�.   
//  ���α׷� �ڵ尡 �ε��� �� �� ���� ����. <= TEXT segment�� ����. 
//  <= GCC������ �ּҰ� ����. 
// 
// printf("Function address	\t%lld\n", (long long)f_ptr);
//  function ��ü�� �ּ�, function pointer ������ ����� �ִ� �ּҸ� ���. 
//  func() �Լ��� �޸� ���̾ƿ��� ��� ��ġ�ϰ� �ִ��� ���.
//  function address�� ���α׷� �ڵ忡 �ִ�. 
//  <= "Banana"�� ��ġ�� TEXT segment�� ����.
// 
// printf("Function address	\t%lld\n", (long long)main);
//	main() �Լ��� ��� ��ġ�ϰ� �ִ��� ���. 
// 
// printf("Global variabe		\t%lld\n", (long long)&g);
//  file scope variable g�� �޸��� ��� �ִ��� �ּҸ� ���. 
//  <= DATA segment �������� ����. TEXT segment���ٴ� �뷫 ���� �ּ� ��ġ�� �ִ�. 
// 
// func(); �Լ��� �����ϸ�, �Լ� �ȿ��� �ڽ��� local variable�� �ּҸ� ���.
//  <= stack�� ��ġ�Ѵ�. 
// 
// printf("Allocated memory	\t%lld\n", (long long)ptr);
//	���� �Ҵ� �޸� ��ü ptr�� �ּڰ��� ���� ���.
//  <= ������ ����. 
//  <= stack�� Data segment ������ ������ �ּڰ��� ���´�. 
// 
// �� �޸𸮰� ���� ���� ������ ������ ���鼭 �޸� ������ �޾� �´�.  
// ���� �Ҵ����� �޾ƿ� �޸𸮴� ���� ��ġ�ϰ�, 
// �ü���� �׶� �׶� ��Ȳ�� ���� �Ҵ��� �ش�. 
// 
// storage size�� ��Ȳ�� ���� ũ�Ⱑ �޶�����.
// ���α׷� �ڵ尡 ũ�ٸ�, TEXT segment�� ������ Ŀ�� ���̴�.
// ���������� ���ٸ�, DATA segment, BSS�� ������ Ŀ�� ���̴�. 
// �׶� �׶� �޶�����. 
// 
// �� �ڼ��� ������ �����ϰ� ������, �����Ϸ�, �ü�� ���� ������ ������ �ȴ�. 
// 
// ���� �Ҵ� �޸𸮰� �ٸ� ��ҵ���� �޸�, 
// �ٸ� ���� ���� �з������ �޸�, 
// ���� ����� Ư���� ���� �ǰ�, 
// �׷� ���ؼ� �����̶�� ���� �ڵ����� �����Ǵ� ���� �ƴϰ�, 
// ���α׷��Ӱ� �������� ������ ��� �Ѵ�. 