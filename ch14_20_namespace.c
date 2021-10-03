#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Namespace, �̸� ���� �����ϱ� 
//
// ������ ���� �̸� ���� Ȥ�� ��Ī �����̶�� �Ѵ�.
// C++������ �ܼ��� �������� �� �ƴ϶�, ���� ������ ��� �ִ� �����̴�.  

int iamfunction() {
	return 0;
}

int main() {
	/*
		namespace 
		- Identify parts of a program in which a name is recognized
		- You can use the same name for one variable and one tag.
		- C++: use 'namespace' to use the same identifiers in the duplicated scopes.
	*/

	int myname = 123;

	{
		int myname = 345;
		// double myname = 3.14;	//ERROR
	}

	struct rect { double x; double y; };

	// int rect = 123;		// OK in C (Not ok in C++)
	struct rect rect = { 1.1, 2.2 };	// struct rect and rect are in different categories

	/*
	typedef struct rect rect;
	rect rect = { 1.1, 2.2 };	// Not OK
	*/

	//int iamfunction = iamfunction();	//ERROR

	/*
		Namespace pollution (KNK, p.465)
		- Nmaes in different files accidentally conflicting with each other
	*/

	//printf("%d\n", a);	// other.c


	return 0;
}

// 
	/*
		namespace
		- Identify parts of a program in which a name is recognized
		- You can use the same name for one variable and one tag.
		- C++: use 'namespace' to use the same identifiers in the duplicated scopes.
	*/
//
	/*
	{
		int myname = 345;
		// double myname = 3.14;	//ERROR
		<= ���� block �������� ������ �̸��� ���� ����� �����Ѵ�. 
	}
	<= myname�̶�� ������ ���� scope�� �� block �߰�ȣ {} ���̴�. 
	   <= myname�̶�� �̸��� �νĵ� �� �ִ� ������ �� block��ŭ�̴�. 
	      myname�̶�� �̸��� namespace�� �� block�̴�. 
	   ���� block �ȿ� ���� �̸��� ������ ������ �� ����. 
	   type�� �޶� �̸��� ������ ������ �� �� ����. 
	   
    ������ �Լ��� �̸��� ��ġ�� �� �ȴ�. 
	������ ���� variable�� tag�� ���� �̸��� �� �� �ִ�. 
	struct, union ���� �͵��� category ��ü�� �ٸ��Ƿ� ���������� ����Ѵ�. 
	<= C������ ����� �ǰ� C++������ ī�װ��� �ٸ� �͵� ������ 
	   ���� �̸��� ����ϴ� ���� ��� �� �ȴ�. 

	struct rect { double x; double y; };

	// int rect = 123;		// OK in C (Not ok in C++)
	struct rect rect = { 1.1, 2.2 };	// struct rect and rect are in different categories

	*/
//
// ������ ���α׷��� ���� �� �Ǹ� �ߺ��� �������� ��Ÿ���� ��찡 ����Ƿ�
// ���� ���� �ȿ� ���� �̸�(���� �ν���)�� ���� �͵��� ���� �� �� �� �ֵ���
// namespace�� ������ �ִ� ���̴�. 
// <= ���߿� C++ ������ ��, �����ϰ� �ȴ�. 
// 
	/*
	int myname = 123;

	{
		int myname = 345;
		// double myname = 3.14;	//ERROR
		<= myname = 123;�� �� block �ȿ����� name hiding�� �ȴ�. 
	}
	*/
//  
// ����ü�� ���õ� �� ���� ���� ����.
// 
	/*
	struct rect { double x; double y; };
	 <= ����ü�� tag�� rect�̴�. 

	// int rect = 123;		// OK in C (Not ok in C++)
	struct rect rect = { 1.1, 2.2 };	// struct rect and rect are in different categories
	 <= struct�� tag�� rect�ε���, 
	    struct variable name�� rect�� ������ �ȴ�. 
     <= �ֳ��ϸ�, struct�� rect�� struct rect�� rect�� �ٸ��� �����̴�. 
	    rect�� struct�� tag �̸��̰�, 
		rect�� strcut rect�� variable name�̴�. 
		�� ���� category�� �ٸ���. 
	*/
// 
	/*
	struct rect { double x; double y; };

	int rect = 123;		// OK in C (Not ok in C++)
	 <= struct�� tag�� rect�ε���, 
	    ���� �̸��� rect�� �� �� �� �ִ�. <= C������ ����Ѵ�. 
		C++������ ������� �ʴ´�. �� �� ����������. 
	 <= C���� �̷� ������ �̸��� �ߺ� ����ϴ� ���� ����ϴ��� 
	    �ߺ� ����� ���������� �ʴ´�.
		�̸��� ������ �ſ� ��򸰴�.
	*/
// 
	/*
	typedef struct rect rect;
	rect rect = { 1.1, 2.2 };	// Not OK
	 <= typedef�� struct rect�� rect��� type �̸��� ������ ����� ����, 
	    rect rect = { .. };�� ���� ������ ����ϸ� �� �ȴ�. 
	 <= ��򸮴� �� �����ϱ� ���� ���������� ���� ���ٰ� �����ϸ� �ȴ�. 
	 <= struct rect�� ����ü�� ����� ������, �̿� ���� ���� �� �ȴ�. 
	    
    �����Ϸ� ���忡�� ������ ����, ������ �� �� ���� ���̴�. 
	*/
//
// int iamfunction = iamfunction();	//ERROR
// <= �Լ��� �̸��� ������ ���� �̸��� �����Ϸ��� �ϸ�, �浹�� ����. 
//    ���� �̸� ���� �ȿ��� ��Ī�� �浹�� ���� ������ ���� ���̴�. 
// 
	/*
		Namespace pollution (KNK, p.465)
		 <= �̸� ���ض�� ������ �ִ�. 
		    ū ���α׷��� �ۼ��ϴ� ����, �� ���� �̸��� �̹� �ٸ� ������ 
			�� ����� ���� ��찡 �߻��Ѵ�. 
			�̸��� �ݺ��ؼ� ���� ���� ��찡 �߻��Ѵ�. 
			C��� �����ϴ� ����, ���������� �� ���ٴ� ���� ��� �ȴ�. 
			�̸��� ������ ���� scope �ȿ� ���� ���� �̸��� ������ �� �ִ�. 


		- Nmaes in different files accidentally conflicting with each other
	*/

	//printf("%d\n", a);	// other.c 
// 
// ���������� int a = 123;�� ����� �ִµ�
// main() �Լ� ������ �ٽ� a��� ������ ����Ѵٸ�, 
// ������ �� ���� �Ѿ���� ��ŷ�� �� ������ �߻��ϰ� �ȴ�. 
// 
// ���������� ���� ������ ����� ������, 
// scope ���� ���ο� ������ �����ϱ� ��������� �Ǵµ� �̷� ����,
// namespace pollution�̶�� �Ѵ�. 
// 
// C������ ������ ���������� ���� ����ϸ� ������ �� �� �ְ�, 
// static���� ���� �ּ� �ٸ� ������ ������� ���ϰ� �ϴ� ����� �ִ�. 
// 
// C++�� �ٸ� ������ �� �� ��� ������ ����ؼ�  
// namespace�� �����ؼ� �� ��Ʈ������ �޵��� �����ִ� ��ġ�� �غ�� �ִ�. 
// 
// C������ �̷� �������� �־��µ� 
// ���Ŀ� ���� ������ �̷� �������� ������ �ְ� �ִ�. 
// 
// namespace��� �� ���ؼ� ���� �ô�. 