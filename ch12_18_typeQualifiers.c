#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// memcpy
#include "ch12_18_header.h"	// constants �ҷ�����

// Type Qualifiers �ڷ��� ������
// const, volatile, restrict
// 
// Qualify��� ���� �ڰ��� �ο��Ѵٴ� �ǹ��̴�. 
// �ڷ� �����ڶ�� ���� �������� �Ѵ�. 

//const double gravity = 9.8;
//const double PI = 3.141592;

int main() {
	/*
		Qualified types
		const, volatile, restrict, _Atomic
	*/

	/*
		const
	*/

	// C99 ideompotent, Ÿ�� �����ڸ� ���� �� �ᵵ �ȴ�. 
	const const const int n = 6;	// <= const int n = 6;�� �����ϴ�.

	typedef const int zip;	// ���α׷��Ӱ� zip���� ������ ���̴�.
	const zip q = 8;		// const const int zip

	// const int i;			// NOT initialized!
	// i = 12;				// Error
	// printf("%d\n", i);	// Error

	const int j = 123;  // <= const�� ���� ������ ���� �� �ݵ�� �ʱ�ȭ�� �� ��� �Ѵ�.
	const int arr[] = { 1, 2, 3 };

	float f1 = 3.14f, f2 = 1.2f;

	const float* pf1 = &f1;
	//*pf1 = 5.0f;	// Error
	pf1 = &f2;		// Allowed

	float* const pf2 = &f1;

	*pf2 = 6.0f;	// Allowed
	//pf2 = &f2;	// Error

	const float* const pf3 = &f1;
	//*pf3 = 7.0f;	// Error
	//pf3 = &pf2;	// Error

	/*
		Global constants
	*/

	double area_circle = PI * 2.0f * 2.0f; 


	/*
		volatile
		- Do not optimize
		- (ex: hardward clock)
	*/

	volatile int vi = 1;		// volatile location
	volatile int* pvi = &vi;	// pionts to a volatile location

	int i1 = vi;

	// ...

	int i2 = vi;

	/*
		restrict (_restrict in VS)
		- sole initial means of accessing a data object
		- compiler can't check this restriction
	*/

	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* par = ar;

	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar)	exit(1);

	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8;

	restar[0] += 3;
	restar[0] += 5;
	// restar[0] += 8;	// Equalivalent

	free(restar);

	return 0;
}

// typedef const int zip;	// ���α׷��Ӱ� zip���� ������ ���̴�.
// const zip q = 8;	<= �ᱹ const const int zip�� ���� �ǹ̰� �ȴ�. 
// const const int zip�� ������ �� �Ǵ� ������ �����ϱ� ���ؼ�, 
// �����ڸ� �ߺ��ؼ� �ᵵ �ǵ��� C99���� �߰��� �Ǿ���. 
// 
// const int i;	<= const�� ���� �ٲ� �� ���� ������ 
//				   ������ �� �ݵ�� �ʱ�ȭ�� �� ��� �Ѵ�.
// �ʱ�ȭ�� �� �� �ָ�, �ᱹ�� ����� �� ���� �ȴ�. 
// 
// const int i;			// NOT initialized!
// i = 12;				// Error, ���� �ٲ� ���� ����. 
// printf("%d\n", i);	// Error, ���� ����� ���� ����. 
// 
// �������� const�� ������ ���� ������ ���� �ִ�. 
// 
// float f1 = 3.14f, f2 = 1.2f;
// const float* pf1 = &f1;
// <= pf1 ������ ���� ��ü�� �ٸ� ���� ���� �� �ִ�.
//  
// *pf1 = 5.0f;		// Error, <= indirection�� �� �������� ���� �ٲ� �� ����.
// pf1 = &f2;		// Allowed
// <= �ٸ� ������ �����ͷ� ���� �ٲ� ���� �ִ�. 
// 
// �׷� �ݴ��� ����?
// float* const pf2 = &f1;	<= �̷��� const�� �ٿ� �ָ�, 
// *pf2 = 6.0f;	// Allowed	<= indirection�� �� �Ŀ��� ���� �ٲ� �� ������,
// pf2 = &f2;	// Error	<= ������ ���� ��ü�� �ٸ� ���� ���� �� ����. 
// 
// indirection���ε� ���� �ٲ� �� ����, ������ ���� ��ü�� ���� �� �ٲٰ� �Ϸ���?
// const float* const pf3 = &f1;	<= �̷��� const�� �� �� ���̸� �ȴ�.
// *pf3 = 7.0f;	// Error
// pf3 = &pf2;	// Error/  
// 
// global const��?
// ù ��°�� ������ �� �ִ� ����, ������ ���� ���� ������ ���� ��,
// �ٱ� file���� ����� ���� extern Ű���带 ����Ѵ�. 
// const double gravity = 9.8;
// const double PI = 3.141592;
// 
// ������, �̷��� �ϸ� �ٸ� ���α׷��� ���� �� ���ŷο�����. 
// �̰� �� ã�ƾ� �ϱ� �����̴�. 
// 
// ��Ȱ���� �� �ִ� ���� �����, 
// ���� ���� global const�� c file�� ���� ����, header file�� �ִ� ���̴�. 
// 
// static const double gravity = 9.8;
// static const double PI = 3.141592;
// <= ��� ���Ͽ� �� constants�� �־� ����, 
// #include "ch12_18_header.h" �̷��� include�ؼ� ���� �ȴ�. 
// gravity�� �̿��ؼ� �̵��ϰ� �Ѵٵ���, PI�� ����ؼ� ���� ũ�⸦ ����� �� ����Ѵ�. 
// 
// volatile �� ���� ����.
// ������ �ǹ̴� �ֹ߼��̴�, ���� �� �ִ�. �Ҿ����� �ǹ̸� �����ϸ� �ȴ�. 
// 
// volatile int vi = 1;		// volatile location
// volatile int* pvi = &vi;	// pionts to a volatile location
// int i1 = vi;
// 
// ...						<= �� �ٸ� �۾��� �� ������, vi�� ���� �ٲ� �� �ִ�.
// 
// � ���� vi�� ������ ��, �� ������ ���� �� ���α׷��� �ƴ� �ٸ� ���α׷�����
// �ٲ� �� �ִ�. 
// �����Ϸ��� �𸣴� ��Ȳ���� �� ���� �ٲ� ���� �ִٰ� ǥ�⸦ �� �ִ� ���̴�. 
// 
// �ٸ� ��⿡�� Ȥ�� �ü������ ���� vi�� �����͸� �����ٰ�, 
// ���� ��� �ð��� �־� �شٸ�, �ð��� �귯���� ���� ���� ��� ���ϰ� �ȴ�. 
// 
// vi�� �����Ϸ��� �� �� ���� ������ ���ؼ� ���� �ٲ� �� �ִٴ� �ǹ��̴�. 
// �׷��Ƿ� ��������� �����Ϸ����� �װ� ����ȭ�� ���� ����� �ǹ̰� �ȴ�. 
// �ǵ帮�� ����. 
// 
// int i1 = vi;

// ...			<= ��� �۾�. 

// int i2 = vi;
// 
// �̷��� ��� �����Ϸ� ���忡���� ����ȭ�� �ϱ� ���ؼ�, 
// �� ��° vi�� �޸𸮿��� �о�ٰ� i2�� ������ �� �ִ� ���� ��Ģ�ε�, 
// �����Ϸ��� �߰��� ��� �۾��� ���ٸ�, ù ��° vi�� ���� �� �ٲ� ������ �����ϰ�, 
// vi�� �ӽ� ���� ������ �����ؼ� �ڵ带 �� ������ ����� �ַ��� ����ȭ�� �� �ִ�. 
// <= cach�� �Ѵ�. caching. �ӽ� ���� ������ ��� �����ؼ� �ӵ��� ������ �ϴ� ��.
// 
// �׷��� �����Ϸ��� �𸣴� ��Ȳ���� �ü���� vi�� ���� ������ �ٲ� ���� ��, 
// caching�� �ϸ� ������ �����.  
// �׷��Ƿ� caching�� �� �ϰ�, ����ȭ�� �� �ϰ� ���� ������! <= volatile
// ��������� ����ȭ�� �� �ϰ� �ȴ�. 
// 
// �ϵ��� �ٷ�ٰų� �κ��� ����ٰų� ���ǿ��� �ڵ��� �Ѵٰų� imbeded �ڵ��� 
// �Ѵٸ�, volatile type�� ���� ����ϰ� �ȴ�. 
// 
// restrict�� ���� ����.
// �ǹ̴� data object�� �����ϴ� �� �̰� �ϳ����̴ٶ�� �ǹ��̴�. 
// 
// int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
// int* par = ar;
// ��ó�� � array�� �ִٸ� �� array�� ���� �����͸� ������ �� �� �ִ�. 
// 
// �׷���,
// 	ar[0] += 3;		<= �� array�� ���ؼ� ���� �ٲٴ� �Ͱ�
// par[0] += 5;		<= �����͸� ���ؼ� ���� �ٲٴ� ���� ����� �����ϴ�. 
// <= �� ���� par[0] += 8;�� ����. 
// �����Ϸ� ���忡���� �� �� ������ par[0] += 8;�� ����ȭ�� �ϰ� ���� �� �ִ�. 
// 
// ������ par(ar�� ���� ������)�� ������ ar[10]�� ù ��° �ּҸ� ����Ű�� �ֱ� ������,
// ar[0]�� par[0]�� ������, 
// �����Ϸ� ���忡���� �� ���� �ٸ� �̸��̴�. 
// �׷��Ƿ� par[0] += 8;�� ���� ����ȭ�� �� �� �� ����. 
// 
// int* __restrict restar = (int*)malloc(10 * sizeof(int));
// if (!restar)	exit(1);
// 
// restar[0] += 3;
// restar[0] += 5;
// restar[0] += 8;	// Equalivalent
// 
// ������, ��ó�� ���� �Ҵ���� �޸𸮸� __restrict �� �ָ�, 
// ���� �Ҵ����� �޾ƿ� (int*)malloc(10 * sizeof(int)) �޸𸮸�, 
// �ٸ� �����ͳ� ���� �ٸ� ������ �̿��ؼ� �������� �ʰ�, 
// restar�� ���ؼ��� �����ϰڴٴ� �ǹ̰� �ȴ�. 
// 
// restar[0] += 3;
// restar[0] += 5;
// <= �� ���� �����Ϸ� ���忡����, restar[0] += 8; �̷��� ����ȭ�� �� �� ���� �ִ�.
// <= ���� �Ҵ�� �޸𸮿� �����ϴ� ������ restar�� �����ϴ� �� �̿ܿ��� ���� �����̴�. 
// __restrict restar���� ����ȭ�� ������ �� �ִ�. 
// 
// compiler can't check this restriction
// ������ ����, �����Ϸ� ���忡���� ���� �� restrict�� �������� �ִ��� 
// ���� �Ҵ���� �޸𸮿� ���ؼ� �����Ͱ� restar �ۿ� ������, 
// ��¥ restar �ۿ� �������� üũ�� �� ���� ����. 
// 
// ���α׷��Ӱ� __restrict Ű���带 ����, 
// �ٸ� �����͸� ���ؼ��� �̰Ϳ� ������ ���� ���ڰ� ���Ѿ߸� �ϴ� ������ �ִ�. 
// restrict�� �����Ϸ��� ���� �ִ� ���̴�. 
// visual studio���� ����� ���� Ű���� �տ� underscore �� ���� �ٿ� ��� �Ѵ�. 
// 
// ���ݱ��� �ڷ��� ������ const, volatile, restrict�� ���ؼ� ���� �ô�.
// 