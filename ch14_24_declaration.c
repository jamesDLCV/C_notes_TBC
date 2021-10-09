#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Declaration
// ������ ������ �ؼ��ϴ� ���
// 
// C���� ���� ������ �Ǵ� ������ ���̴� ������ ��� �ؼ��ؾ� �Ǵ��� 
// ����� ���� ���ڴ�. 
//
// �� ���� typedef���� ������ ���̴� ���� ���ؼ� ����� �ߴ�. 

int temp(int a) {
	return 0;
}

int (*g(int a))(int) {
	return temp;
}
 
int main() {
	/*
		*	indicates a pointer
		()	indicates a function
		[]	indicates an array
	*/

	/* Deciphering Complex Declarations (KNK 18.4)
	   - Always read declarations from the inside out.
	   - When there's a choice, always favor [] and () over *(asterisk).	
	*/

	int* ap[10];	// Identifier ap is an array of pointers

	typedef int* pint;
	pint ap2[10];

	float* fp(float);	// fp is a function that returns a pointer

	typedef float* pfloat;
	pfloat fp2(float);

	void (*pf)(int);
	/*
		void (*pf)(int);
		      1           1. pointer to
			       2      2. function with int argument
	    3                 3. returning void
	*/

	int* (*x[10])(void);
	/*
		int* (*x[10])(void);
		         1				1. array of
		      2                 2. pointers to
			          3         3. functions with no arguments
		4						4. returning pointer to int
	*/

	/* A function can't return an array */

	//int f(int)[];	// Wrong

	/* But it can return a pointer to an array */

	int(*f(int))[];

	/* A function can't return a function */

	// int g(int)(int);		// Wrong

	/* But it can return a pointer to a function */

	int (*g(int))(int);

	/* An array of functions aren't possbile */

	//int a[10](int);		// Wrong

	/* But an array of function pointers are possible */

	int (*x2[10])(int);

	/* Using typedef to simplify declarations */

	typedef int FCN(int);
	typedef FCN* FCN_PTR;
	typedef FCN_PTR FCN_PTR_ARRAY[10];
	FCN_PTR_ARRAY x3;

	/* More examples */

	int board[6][4];	// an array of arrays of int
	int** ptr;

	int* risks[10];		// A 10-element array of pointers to int
	int(*rusk)[10];		// A pointer to an array of 10 ints

	int* off[3][4];		// A 4x3 array of pointers to int
	int(*uff)[3][4];	// a pointer to a 3x4 array of ints
	int(*uof[3])[4];	// a 3-element array of pointers 
	                    // to 4-element arrays of int

	char* fump(int);	// function returning pointer to char
	char (*frump)(int);	// pointer to a function that returns type char
	char (*flump[3])(int);	// array of 3 pointers to functions 
	                        // that return type char

	typedef int arr5[5];
	typedef arr5* p_arr5;
	typedef p_arr5 arrp10[10];

	arr5 togs;
	p_arr5 p2;
	arrp10 arp;

	return 0;
}

//
	/*
	int (*g(int a))(int) {
		return temp;
	}
	*/
// <= �̷� �Լ��� ����, ���������� ������ ������ �ʴ´�. 
//    �ǹ������� �̷� ������ �� ������� �ʴ´�. 
//    �̺��ٴ� typedef�� �̿��ؼ� �����ϱ� ���� ���·� �ٲ㼭 �ڵ��ϴ� ���� �Ϲ����̴�.
//	  ������ �⺻���� ������ �˾� �δ� ���� ����. 
// 
// ������ �� �� �����ϰ� ������ ���� ������ �� ������ �����̴�.
// *	indicates a pointer
//  <= ù ��°�� �������̴�. �����͸� ����� �ִ� ��ȣ * asterisk
// ()	indicates a function
//  <= �� ��°�� ��ȣ�̴�. �� ���� �ǹ̰� �ִ�. 
//     �ϳ��� ���� ����� �� �� �켱 ������ ǥ���ϱ� ���ؼ� ���� �ִ� ���̰�, 
//     �� �ϳ��� �Լ��� �Ű������� ���� �������μ��� ��ȣ�̴�.   
// []	indicates an array
//  <= bracket, ���ȣ. �迭�� �ǹ��Ѵ�. 
// 
// Deciphering Complex Declarations (KNK 18.4)
//  <= KNK 18.4�忡 ���� �� ���� ��Ģ�� ���� ���� ������ �Ұ��� �ִ�.  
// -Always read declarations from the inside out.
//  <= ù ��° ��Ģ�� ���ʿ������� �ٱ������� �о��. 
// - When there's a choice, always favor [] and () over *(asterisk).	
//  <= �� ��° ��Ģ�� ������ * asterisk���� []�� ()�� �켱 ������ ����. 
// 
// �� �� ������ �̿��ؼ� �ؼ��� �Ѵ�. 
// 
// int* ap[10];	// Identifier ap is an array of pointers
//  <= �ؼ��� �� ��, �̸�(�ĺ���, identifier)�� ���� ã�´�.
//	   �̸��� ap�̴�. �����ʿ��� *�� �ְ� ���ʿ��� []�� �ִ�. 
//     []�� *���� �켱 ������ ����. 
//     �׷��Ƿ� ap�� �迭�̴�. <= ap[]
//     ���� �迭�̳�? <= int�� ���� ������(int*)�� �迭�̴�. 
//	   �׷��Ƿ� int* ap[10]�� int pointer 10��¥�� �迭�̴�. 
//  <= �̷��� ���� ���� ������ �� �ִµ�, typedef�� ����ϸ� �����ϱ� �ξ� ����.   	
// 
// typedef int* pint;
//  <= �̷��� �����Ǹ� �Ѵ�.      
// 
// pint ap2[10];
//  <= �׷��� pint�� ������ ���� pint �ڷ����� 10��¥�� �迭�̶�� ������ �� �ִ�. 
//     pint�� ���� ���� ���ϱ� int�� ���� ������(int*)��� ���� �� �� �ִ�. 
//     �׷��Ƿ� int�� ���� ������ 10��¥�� �迭�̶�� ���� ������ �� �ִ�. 
//  <= �̷� ������ �����ϸ� �ξ� ��������. 
// 
// �Ʒ������� �Ȱ��� ������ �� �ִ�. 
// float* fp(float);	// fp is a function that returns a pointer
//  <= fp(float)�� �Լ��̴�. 
//     fp��� �̸�(�ĺ���, �ν���)�� ã�´�.
//     ���ʿ��� *�� �ְ� �����ʿ��� ()�� �ִ�. ()�� *���� �켱 ������ ����. 
//     �Ű������� float �ϳ��� ������ �Լ� fp�̴�. 
//     �� �Լ��� ��ȯ���� float�̴�.       
// 
// �̰͵� �Ʒ�ó�� typedef�� �ٲ� ���� ���� �ξ� �����ϱⰡ ����. 
// typedef float* pfloat;
// pfloat fp2(float);
// 
// void (*pf)(int);
//  <= �̸��� ã�´�. �̸��� pf�̴�. 
//     �̸� �տ� *�� �پ� �ְ� *pf�� ��ȣ�� ������ �ִ�. 
//     (*pf)�� �������̴�. �����ΰ��� ���� �������ΰ�?
//     �����ʿ� ��ȣ int, (int)�� �ִ�. 
//     �� ������ �ϳ��� �Ű������� ���� �Լ���� ���̴�. 
//     �׸��� ��ȯ���� void�̴�. 
//  <= �Ű������� ������(int)�̰� ��ȯ �ڷ����� void�� �Լ��� ���� ������ (*pf)�̴�. 
//     
// �Ʒ� ���� ���� �� ������ ���δ�. 
// int* (*x[10])(void);
//  <= ���� �̸��� ã�´�. �̸��� x�̴�. 
//     ���� []�� ������ *���� �켱 ������ �����Ƿ�, 
//     x�� �ϴ� x[] array�̴�. 
//     ������ array�ΰ�? <= �����Ϳ� ���� array�̴�. 
//     �׷��� �� �����Ͱ� ������ ���� ���������� �˾ƾ� �Ѵ�. 
//      <= �ؼ��� �� ���� �ȿ������� ������ �����鼭 �ؼ��� �϶�. 
//     (*x[10])�� ������ ���� ����, �����ʿ��� *�� �ְ� ���ʿ��� (void)�� �ִ�. 
//     ��ȣ�� *�� ���� �켱 ������ ����. 
//     ��ȣ (void)�� �Ű������� ���� �Լ��̴�. 
//     ��ȯ���� int�� �������̴�. 
// 
//  <= ��������� x��� ����, int�� ���� �����͸� ��ȯ�� �ִ� 
//     �Ű������� ���� �Լ��� ���� �������� �迭�� �ȴ�. 
//     
// �Լ��� ���� �������� �迭�� ���� ������ ���� �ٽ� ���� ����. 
// 
// �� �Ǵ� �͵鵵 �ִ�. ���⵵�� ���� �پ��� �ȴ�. 
// 
// �Լ��� �迭�� ��ȯ�� �� ����. �⺻������ �� �ȴ�. 
// int f(int)[];	// Wrong <= �̷��� �迭�� ��ȯ�� ���� ����. 
// 
// ������ �迭�� ���� �����͸� ��ȯ�� ���� �ִ�. 
// 
// int(*f(int))[]; <= �̷� ���´� �����ϴ�. �� ������ typedef���� ����ߴ�. 
// 
// �Լ��� �Լ��� ������ ���� ����. C������ �� �ȴ�. 
// �Լ��� �Լ��� ��ȯ�Ѵٴ� ���� ��ü�� C++�� �ٸ� ������ ������ �����̴�. 
// ������ ���������� ������ ���� ������ function pointer�� �����ϰ� �� �ִ�. 
// <= C���� �� �Ǵ� ������ �ٸ� ������ �� �Ǵ� ���� �ƴϴ�. 
// 
// int g(int)(int);		// Wrong
//  <= �Լ��� �Լ��� ��ȯ�ϴ� ���� ���� �����Ƿ� �̷��Դ� ����� �� ����. 
// 
// ������, �Լ��� �����ʹ� ������ �� �ִ�. 
// 
// int (*g(int))(int);
// <= �Լ��� �����Ͱ� �پ� �ִ�. 
//    �ؼ��ϴ� ����� �տ��� ���� �� �Ͱ� �����ϴ�. 
// 
// �Լ��� �迭�� �� �ȴ�. 
// 
// int a[10](int);		// Wrong
// <= �Լ��� �迭�̹Ƿ� ���� �ִ�. 
//
// ������ �Լ��� �������� �迭�� �����ϴ�. 
// 
// int* (*x2[10])(void);
// <= int (*g(int))(int);�� ��Ī�ǰ� �ٲ� ����, 
//    int (*x2[10])(int);�� �ȴ�. 
//    <= x2�� �迭�ε�, �������� �迭�̴�. �׷� ������ ���� �������̳�?
//       �Ű������� int Ÿ���� �ϳ� ������, int Ÿ�� �ϳ��� ��ȯ�� �ִ� 
//       �Լ��� �����Ϳ� ���� �迭�� 10���̴�.  
//
// ������ ���� ���� typedef���� ������ �Ͱ� ������ �����̴�. 
//
// /* Using typedef to simplify declarations */
//
// typedef int FCN(int);
//  <= �Լ��� �����Ѵ�. �Ű������� int�̰� ��ȯ Ÿ�Ե� int�̴�. 
// 
// typedef FCN* FCN_PTR;
//  <= �Լ��� ���� �����͸� �� �ش�.  
// 
// typedef FCN_PTR FCN_PTR_ARRAY[10];
//  <= ������ �� �Լ� FCN_PTR�� ���� �����Ͱ� 10�� �ִ�. 
// FCN_PTR_ARRAY x3;
//  <= ������ FCN_PTR���� x3�� �����ߴ�. 
//  <= x2�� x3�� Ÿ���� �Ȱ���.
//     �� �� int�� ������ int�� ��ȯ�ϴ� �Լ��� ���� ������ 10���� 
//     �迭�� ������ �� �ִ� �ڷ����� �ȴ�.  
// 
// �̷� ������ typedef�� �����ϱ� ���� ������ �� �� �ִ�. 
//
// �� �ܿ��� ���� ���� �������� �ִ�. 
// /* More examples */
// �� �������� ���� ������ �����ߴٸ� ������ �� �����Ƿ� ���� �ؼ��� ���� �ٶ���. 
// 
// ������ ������ �ؼ��ϴ� ����� ���ؼ� ���� �ô�. 
// �ǹ������� �̷��� ������ ������ ������ �Ӹ� �θŰ� ����� ���� ���� ���� ���̴�. 
// typedef�� �̿��ؼ� �����ϱ� ���� ���·� �����ϴ� ���� �ξ� �� ���� ����̴�. 
// �ٸ� ������ �� ���� �� �θ� ������ �� ���̴�. 