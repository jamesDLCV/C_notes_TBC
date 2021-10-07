#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>	// time()

// typedef
// �ڷ����� ������ �ٿ� �ִ� typedef�� ���� ���� ����� ���� ����.

int main() {

	/*
		typedef specifier
		- Give symbolic names (or aliases) to types
		- Does not create new types.
	*/

	typedef unsigned char BYTE;	// Note the scope of BYTE

	BYTE x, y[10] = { 0, }, * z = &x;

	{
		typedef unsigned char byte;	// You can use lowercases as well.

		/* Portable data types */

		size_t s = sizeof(byte);//unsigned int (x86), unsigned long long (x64)
		// unsigned int s = sizeof(byte);			// x86
		// unsigned long long s = sizeof(byte);		// x64
	}
	 //byte b;	// typedef definition has a scope

	/*
		This function returns the time since 00:00:00 UTC, January 1, 1970 (Unix timestamp)
	*/

	time_t t = time(NULL);

	printf("%lld\n", t);

	/*
		typedef vs #define
	*/

	typedef char* STRING;

	STRING name = "John Wick", sign = "World";

	/*
	- typedef interpretation is performed by the compiler, not the preprocessor
	- More flexible than #define

	#define STRING char*

	STRING name, sign;
	char* name, sign; // Note the type of sign
	*/

	typedef struct complex {
		float real;
		float imag;
	} COMPLEX;	// typedef struct complex COMPLEX

	typedef struct { double width; double height; } rect;	// No tag
	rect r1 = { 1.1, 2.2 };
	rect r2 = r1;

	printf("%f %f\n", r2.width, r2.height);

	return 0;
}

// typedef�� �⺻���� ����� �ڷ����� �� �ٸ� �̸�(����)�� �ٿ� �ִ� ���̴�. 
// �̸��� �ٲ� �ְ�, �ٸ� �̸����� �θ��� �ͻ�����, 
// ���ο� �ڷ����� ����� �ִ� ���� �ƴϴ�. 
// 
// �⺻ �ڷ���(int, float, double, char) �ܿ� ������ ���� �ڷ����� 
// ����ó�� ���Ӱ� ��Ÿ���� ���� �ƴѴ�. 
// ���� �̸��� �ٲ㼭 �θ� �� �ִٴ� ���̴�. 
// 
// typedef unsigned char BYTE;	// Note the scope of BYTE
//  <= �̸��� �ٲ� �θ��� ���� �ڷ��� unsigned char�� ���� �ְ�, 
//     �ٲ㼭 �θ��� ���� �̸� BYTE�� �ڿ� ���� �ش�. 
//     �̸��� �ϳ� �� ���� ���� ���̴�. 
//     unsigned char�� �� ���� �� ���� �ƴϴ�. 
//     unsigned char�� �� �� �ְ� ���ο� �̸� BYTE�� �� �� �ִ�. 
//     �� ���� �� �� �� �ִ�.  
// 
// BYTE x, y[10] = { 0, }, * z = &x;
//  <= ������ ������ ���� �ְ�, �迭�� ������ ���� �ְ�, 
//     * z = &x �����ͷ� �����ؼ� ����� ���� �ִ�. 
//  <= BYTE ���� ���콺�� ���� ��� Ÿ���� unsigned char�̶�� ���. 
//     �̸��� �ٲ���� ������ unsigned char�� �ٸ� �ڷ������� �۵��ϴ� ���� �ƴϴ�. 
//     �̸��� �ٲ� �θ� Ÿ�����ϴ� ���� �پ�� �� �ִ�. 
// 
// �ݺ��ؼ� �� �ڷ����� �̸��� ����ؾ� �� ����, typedef�� ª�� �ٿ��� ���� ��찡 �ְ�,
// �� unsigned char ��ü�� ���ڷ� ����ϱ⺸�ٴ�, 
// BYTE��� ������ ���� �����ϴ� �����μ�, �� 1����Ʈ¥�� �ڷḦ ������ �� ����
// �⺻ �ڷ������μ��� �����ϰ� ���� ���� �ִ�. 
// ���߿� ��Ʈ��ŷ�� ������ ��, �������� API ���� ���� �о߸� ������ ��,  
// ���� ������ �ȴ�. 
// 
	/*
	{
		typedef unsigned char byte;	// You can use lowercases as well.
		 <= byte�� �ҹ��ڷ� ����ص� �ȴ�. 

		//// Portable data types 
		 <= typedef�� �߿��� ��� �� �ϳ��� Portable data types�̴�. 
		    �̽ļ��� ���� ������ Ÿ���̶�� �ǹ��̴�. 

		���� ���, 
		size_t s = sizeof(byte);//unsigned int (x86), unsigned long long (x64)
		 <= sizeof(byte)�� x86������ unsigned int������, 
		    x64������ unsigned long long�̴�. 
		�׷���, 
		// unsigned int s = sizeof(byte);			// x86
		   <= x86������ �̷��� �ڵ��ϰ�, 
		// unsigned long long s = sizeof(byte);		// x64
		   <= x64������ �̷��� �ڵ��ؾ� �ϴ��İ� ������ �� �ִ�.  
		x86���� �� ���� x64 �� �� �ٸ��� �ڵ��� ��� �ұ�?

		�̷� ���ŷο��� ���ֱ� ���ؼ�, size_t��� �ڷ����� �ִ� ��ó�� 
		typedef�� �̸��� ���� �ش�. 

		x64���� size_t�� ���콺�� ���� ���, 
		typedef unsigned long long size_t��� ���. 

		x86���� �ٲٰ� size_t�� ���콺�� ���� ���, 
		typedef unsigned int size_t��� �ٲ��. 

		�������ϴ� ȯ�濡 ���� �ٸ� �ڷ������� ����� �� �ִ�.  

		size_t�� ��Ŭ���ϰ� Go to Defition���� ���� ��� �� �ִ��� Ȯ���� ����. 

		// Definitions of common types
		#ifdef _WIN64	<= ��ó�����̴�.
		                <= 64��Ʈ��� _WIN64 �� ���ǿ� �ɷ��� ���Ⱑ Ȱ��ȭ�� �ִ�.
			typedef unsigned __int64 size_t;
			  <= __int64�� 8����Ʈ¥�� ������� ���̴�. 
			typedef __int64          ptrdiff_t;
			typedef __int64          intptr_t;
		#else			<= 64��Ʈ������ ��Ȱ��ȭ�� �ִ�. 
			typedef unsigned int     size_t;
			typedef int              ptrdiff_t;
			typedef int              intptr_t;
		#endif
		 <= ��ó���⿡ ���ؼ��� �ٸ� ���¿��� �ٷ��. 

		typedef�� �̿��ؼ�, 
		�̽ļ�(portable data type)�� ���� ���α׷����� �� �� �ִ�.

	}
	//byte b;	// typedef definition has a scope
	*/
// 
// �� �� ���� ������ ������ ���� ����, 
// typedef�� scope�� ������. 
//
	/*
	{
		typedef unsigned char byte;
	}

	byte b;	<= ����� �� ����. 
	*/
// <= { } �ȿ� ����� byte�� { } scope�� ����� ����� �� ����. 
// 
// portable data type�� �ٸ� ���� ���� ����. 
	/*
	time_t t = time(NULL);
	 <= ��ǻ�Ͱ� ���� �� �������� �˷� �ִ� time() �Լ��� �ִ�. 
	    �� �Լ��� 1970�� 1�� 1�� 00:00:00�ú��� ���ݱ��� �� �ʰ� �������� 
		�˷� �ִ� �Լ��̴�. 
		���� �����Ϸ��� 32��Ʈ�� �������� �߰�, ������ 64��Ʈ�� �������Ѵ�. 
	 
		time_t�� ��Ŭ���� �� Go To Definition���� �� ����, 

		#ifndef _CRT_NO_TIME_T
		#ifdef _USE_32BIT_TIME_T
			typedef __time32_t time_t;
		#else
			typedef __time64_t time_t;
		#endif
		<= �̷��� 64��Ʈ�� 64��Ʈ __time64_t�� ����ϰ� ���ǵ� �ִ�. 
		   __time64_t�� ��Ŭ���ϰ� Go To Definition���� �� �� �� �� ����,

		   typedef long                          __time32_t;
		   typedef __int64                       __time64_t;
		   <= �̷��� typedef�� �̿��ؼ� 64��Ʈ�� ����� �� �ֵ��� ���ǵ� �ִ�. 

	�̷� ������ typedef�� �̿��ؼ� �̽ļ��� ���� �ڵ带 ����� �� �ֵ��� ������ �޴´�.

	���߿� C++������ ���� �� ���� ����ϰ� �ȴ�. 

	printf("%lld\n", t);
	*/
// 
// �׷� typedef�� ����ϴ� �Ͱ� #define�� ����ϴ� ���� ���� ���̰� ������?
// �̸��� ��ü�� �Ǵ� ���̰� ���ο� ����� �߰��Ǵ� ���� �ƴϹǷ�
// ��ũ�� #define�� �̿��ؼ� �ٲ� �ִ� �Ͱ� ���� ���̰� ������?
// �⺻�����δ� typedef�� ����ϴ� ���� �����Ѵ�. 
// ���� ���̸� ���� ����. 
	/*
		typedef vs #define
	*/
// 
// typedef char* STRING;
//  <= ���ڿ��� �ٷ� �� char* (char pointer)�� ���� ����Ѵ�. 
//     ��ġ STRING�̶�� �ڷ����� �ִ� ��ó�� ����Ѵ�. // 
// 
// STRING name = "John Wick", sign = "World";
//  <= �̷��� �ϸ� ���ڿ��� ���� ����� �� �ִ�. 
// 
// typedef�� #define�� ���� ū ���̴� #define�� ��ó���� preprocessor�̴�. 
// ��ó����� �������ϱ� ���� ó���� �ȴ�. 
// ��ó����� �ܼ��� ���������� �����ؼ� �ٿ� �ֱ⸦ �� �ִ� �����̴�. 
// 
// ������ typedef�� �����Ϸ��� ó���� �� �ش�. 
// 
// typedef char* STRING;
// STRING name = "John Wick", sign = "World";
// <= typedef�� ����ϸ�, name�� STRING�̰� sign�� STRING�̴�. 
//    STRING�� char*�̴�. �������̴�. 
// 
// ��ó���� #define�� ����� ��쿡��, 
// #define STRING char*
//  <= typedef������ �Ȱ��� #define���� ���� ���. 
//     #define������ STRING�� ���� ���� char*�� �ڿ� �� �ش�. 
//  <= �������� �ϱ� ���� ��ó���Ⱑ STRING�̶�� ���ڿ��� �ڵ忡�� �߰��ϸ�,
//     char*�� �ٲ� ������. 
// 
	/*
	#define STRING char*

	STRING name, sign;
	char* name, sign; // Note the type of sign
	*/
//
// STRING name, sign;
//  <= �̷��� �ڵ��ߴٰ� ������ ����. 
//     �׷��� �����Ϸ� ���� �۵��ϴ� ��ó���Ⱑ STRING�� char*�� �ٲ� ������. 
//     
// char* name, sign; // Note the type of sign
//  <= �ٲ�� �̷��� �ȴ�. 
//     �׷��� ������ sign�� �����Ͱ� �ƴϴ�. name�� �������̴�. 
//     �� �� �����ͷ� �� �ְ� �ʹٸ�, 
//     <= char* name, *sign; �̷��� �ؾ� �Ѵ�. 
//  <= ��ó���⸦ ����ߴٸ�, name�� ���������� sign�� �����Ͱ� �ƴϴ�. 
//     ū ������ �߻��� �� �ִ�. 
// 
// �̴� ��ó���⸦ ������� ���� ��ǥ���� ��ʸ� �ϳ� �Ұ��� ���̴�. 
// ��κ� typedef�� ����ϴ� ���� ��ȣ�Ѵ�. 
// 
// ���� �ʹݿ� COMPLEX��� �ڷ����� ���ؼ� �Ұ��� ���� �ִ�. 
// 
	/*
	typedef struct complex {
		float real;		<= real number
		float imag;		<= imaginary number
	} COMPLEX;	// typedef struct complex COMPLEX
	 <= COMPLEX��� �ڷ����� ǥ�ؿ� ������ ������, �����ϴ� ���α׷��ӵ���
	    �̷� ������ ����ü�� ���� ����ϴ� ���� �Ϲ����̾���. 
		������ �̷��� ���� ���� ����ϴ� ������� ���� �ִ�. 
	 <= real, imag �� ���� ����� ���� ����ü�� �̸��� complex�̴�. 
	    complex�� � �ڷ����� �̸��� ��ó�� ����ϱ� ���ؼ� 
		�빮�� COMPLEX�� typedef�� �� �ְ� �ִ� ���̴�. 
	 <= typedef struct complex COMPLEX �̷��� �� ��� �ϴ� �ڵ尡 �� �� �پ���.
	    �̷� ������ �տ��� ����ü ������ �� �ٷ��. 
		typedef�� ����ü�� �Բ� ����� ���� �̷��� ����� �� �ִ�. 
	 <= struct��� Ű���� ���� ���� ���ϰ� ����� �� �ִ�. 

	typedef struct { double width; double height; } rect;	// No tag
	rect r1 = { 1.1, 2.2 };
	rect r2 = r1;

	printf("%f %f\n", r2.width, r2.height);
	*/
// 
// ���� ������ ������ ������ ��, typedef�� ��� ������ �� �ִ���
// �� ���� �� ���� ���ڴ�. 