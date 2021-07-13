#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �� ������ ����.
// ��ü�� �ĺ��ڰ� ��� �ٸ��� �˾� ����. 
// L-value, R-value�� ���ؼ��� ���� ����. 
// 

int main() {
	/*
		Object ��ü
		- "An object is simply a block of memory that can store a value."
			(KNK p487) C������ objectsms, �޸𸮿� ������ ������ ������ object�̴�. 
		- Object has more developed meaning in C++ and 
			Object Oriented Programming (OOP) object�� ������ Ȯ��ȴ�. 

		Identifiers �ĺ���, �ν���; �̸��̴�, ������ �̸�, �Լ��� �̸�.
		- Names for variables, functions, macros, and other entities. 
			(KNK p25)	
	*/

	int var_name = 3;		// creates an object called 'var_name.'

	int* pt = &var_name;	// pt is an identifier.
	*pt = 1;				// *pt is not an identifier.
							// *pt designates an object.

	int arr[100];			// arr is an identifier. Is arr an object?
	arr[0] = 7;				// arr[0] is an object.

	/*
		lvalue is an expression 'referring' to an object. (K&R p197)

		L-value: left side of an assignment
		R-value: right side, variable, constant, expressions (KNK p67)
	*/

	var_name = 3;	// modifiable lvalue
	int temp = var_name;	// var_name�� rvalue, var_name�� ���� ������ �� ���̴�.
	temp = 1 + 2;	// 1 + 2�� expression�̴�. 				

	pt = &var_name;
	int* ptr = arr;
	*pt = 7;	// *pt is not an identifier but an modifiable lvalue expression

	int* ptr2 = arr + 2 * var_name;	// address rvalue
	*(arr + 2 * var_name) = 456;	// lvalue expression

	const char* str = "Constant string";	// str is a modifiable lvalue.
	str = "Second string";	
	// "Constant string" = "Second String" <= impossible, �� �ȴ�. 

	//str[0] = 'A';	// Error
	puts(str);

	char str2[] = "String in an array";
	str2[0] = 'A';	// OK
	puts(str2);

	/*
		Identifiers have scope.
		Objects have storage duration.
		Variables and functions have one of the following linkages:
			external linkage, internal linkage, or no linkage.	
	*/

	return 0;
}

// ���α׷��� �� ������ ���θ� �ϰ� �Ǹ�, 
// ���� �̸���, �׷��ϱ� �ĺ��ڿ� �޸� ������ �ִ� object�� ���Ͻ��ϰ� �ȴ�. 
// �ֱٿ� ������ �� �� ���� ���α׷��� ������, 
// ���α׷��Ӱ� �׷��� �����ϵ��� ��ġ�ϴ� ���⵵ �ִ�. �׷��� �� ���� ���δ�. 
// 
// �̹� ���ǿ����� object�� identifier�� ���� ���ַ� ���캼 ���̰�,
// �̾� ���� ���ǿ��� �� ���� ���̸� �����ϱ� ���� 
// ������ ������ object�� ���� �Ⱓ�� ���̿� ���ؼ� �ٷ� ���̴�. 
// 
// int var_name = 3; �� �޸� ������ 3�̶�� ���� �����ؼ� �־� �ִ� ���̴�. 
// �޸� ������ ������ �� ��, �� ���� �̸��� ���ؼ� ������ �ϰ� �ִ�. 
// �� ������ �̸��� �Ұ������� ��ġ object�� ���� ����ϴ� ��ó�� 
// C�� �츮�� �����ְ� �ִ� ���̴�. 
//	���������� �ּҸ� ������ ���� ���� �����ϰ�, �ű�� �ߴ�.
// 
// int* pt = &var_name;
// ������ ���� pt�� �ּҸ� ���´�.  
// ������ ������ �޸� ������ ����, ������ ������ �ּڰ��� �����ϴ� ���̴� .
// �׷��Ƿ� pt��� ������ ���� �̸��� �ĺ����̴�. 
// �ű⿡ �ٸ� ������ �ּڰ��� �����Ѵ�. 
// 
// *pt = 1; �̰��� ���� ��� �� �ִ�. Indirection���ִ� expression�̴�. 
// *pt�� �ּҰ� ����Ű�� �ִ� �޸� ������ �ǹ��ϹǷ�, 
// *pt, �� �� ���ڸ� �ĺ��ڷ� ������ �� ������, ������ �ĺ��ڴ� �ƴϴ�. 
// �տ� *�� ���� ���� expression ǥ�����̴�. 
// ������ *pt�� object�� ������ �� �ִ�. 
//	(�����Ϳ��� ����Ų�ٶ�� ���� ���Ƿ� �����Ѵٶ�� ����)
// 
// *pt��, ��ġ ������ ��ó�� ����� �� ������, 
// *pt ��ü�� identifier �ĺ��ڴ� �ƴϰ�, 
// indirection *�� ���ؼ� object�� ������ �� �ִ�.
// �ݸ�, pt�� �ּڰ��� �����ϴ� identifier�̴�. 
// �����п����� referring�̶�� �� ���� ����Ѵ�. 
// 
// int arr[100]; �� ����, �迭�� �����ߴ�. 
// arr�� �迭�� �̸��̴�. �׷��Ƿ� �ĺ��ڰ� �´�. 
// 
// arr�� object�ΰ�? 
// arr�� �迭�� ù ��° ������ �ּ��̴�. 
// �� ��ü�� �޸� ������ ���� object�� �ƴϴ�. 
//	arr ��ü�� object�� �ƴ� ���̴�. ��, �迭�� �̸��� object�� �ƴϴ�. 
// �׷��� �迭�� �̸��� �ĺ��ڷ� �� ���� �ִ�. �̸��� �̸��̹Ƿ�. 
// 
// arr[0]�� identifier�� �ƴϴ�, expression������, object�̴�. 
// identifier�� �ƴ����� expression�� ���ؼ� �޸� ������ ������ �� �ִ�. 
//	0�� index�� ����Ű�� �޸� ������ ����� �� �ֱ� ������, 
//	�޸� ������ �����ؼ� 7�̶�� ���� ���� ���� ���� �ִ�. 
// ���� arr[0]�� object�̴�. 
// 
// object�� identifier�� �ٸ� �������� ���ȴ�. 
// 
// lvalue�� object�� referring�ϴ� expression�̴�. 
// refer�� C++���� ������� �Ѵ�. ������ �θ��µ� �ٸ� ������� �θ���. 
// 
// �����͸� ���ؼ� �������Ѵٰ� �ϸ�, �ּҷ� �ű⸦ ã�ư��� �ű⿡�� ���� ���� �´�. 
// �� �޸� �������ٰ� ������ �Ѵٶ�� �ǹ̰� �ȴ�. 
// 
// refer�̶�� �ϸ�, �� �ٸ� �̸�ó�� ����Ѵ� ������ ������ �ֶ�.
//  
// var_name = 3; �� ����, var_name�� �޸� ������ refer�� �ش�. 
// ���� �̸��� �޸� ������ �ƴϴ�. 
// ���� �̸��� ���������� ����Ű�� �ִ�(referring ���ִ�) �޸� �������ٰ� 
// 3�̶�� ���� �����ؼ� �ִ� ���̴�. <= �� ������ �� �����ص���. 
// 
// var_name = 3;	// modifiable lvalue, ������ �� �ִ� lvalue�̴�. 
// int temp = var_name; ���� �����ʿ� �� var_name�� 
// ���� �޾ƴٰ� ���� temp�� ���޸� �� �ش�. 
// temp�� ������ �ִ� �޸� ������ �����ؼ� ����. <= ���� ���� ���صֶ�. 
// 
// ������ lvalue�� �ǰ�, rvalue�� �Ǵµ� ravlue�� ���� ���� �Ű��ִ� ������ �Ѵ�.
// temp = 1 + 2;	// 1 + 2�� ����ó�� �޸� ������ ���� �ʴ´�. 
					// expression�� ���̴�. 
// 1 + 2�� cpu���� 3�̶�� ������ �ٲ��ְ�, 3�̶�� ���� temp�� ������ ���̴�. 
// ����, 1 + 2�� object�� �ƴϴ�. 
// 1 + 2 = temp; <= �̷� �� �� �ȴ�. 
// 1 + 2�� �޸� ������ �ǹ��ϴ� object�� �ƴϱ� �����̴�. 
// 
// lvalue�� rvalue�� �ٺ����� ���̴�?
// lvalue�� object�̴�. �޸𸮿� ������ ������ �ִ�.  
// �׷��Ƿ� �� �޸� �������ٰ� ��� ���� assignment�� �� �ִ�. 
// 
// object�� �ĺ��ڸ� ���ؼ� rvalue�� ���� ������, 
// ���� ������ �ͼ� �Ѱ��ִ� ���̴�. 
// �̷��� �������� �κ��� C++�� ���� ���� �� ����������. 
// 
// pt = &var_name; �� �����Ϳ��ٰ� ������ �ּڰ��� �����ϰ� �ִ�. 
// ���� ������ pt�� modifiable lvalue�̴�. 
// const�� ���̸�, non-modifiable lvalue�� ���� �� �ִ�. 
// 
// int* ptr = arr; ��, �����Ϳ��ٰ� �迭�� �̸�(identifier�̳� object�� �ƴϴ�, 
// �ּ��̱� �����̴�), �ּڰ��� rvalue�ν� lvalue�� ptr�� �����Ѵ�. 
// ������ ���� ptr�� ������ �ִ� �޸𸮿� arr�� �˷��ִ� �ּڰ��� ������ �� �ִ�. 
// 
// *pt = 7; �� ����, *pt ��ü�� identifier�� �ƴ�����, 
// modifiable lvalue�μ� ����� �� �ִ� expression�̴�. 
// modifiable lvalue expression���μ� object�� ���� �ٲ� ���� �ִ�.  
// 
// int* ptr2 = arr + 2 * var_name; �� ����, 
// arr�� �������� �̸��̴�. �迭�� �̸��̴�. 
// ������ ������ Ȱ���ؼ� ���� �ٲ㺸�Ҵ�. 
// arr + 2 * var_name�� �ּҴ�. rvalue�̴�. 
// ������ ������ ���� ���� �ּڰ��̹Ƿ� rvalue�μ��� ���� �� �ִ�. 
// 
// �׷���, *(arr + 2 * var_name) = 456; ����ó�� 
// �տ����ٰ� indirection operator *�� �ٿ��ָ�,
// modifiable lvalue expression�� ��ó���� ����� �� �ִ�. 
// 
// identifier, object; lvalue, rvalue �� �����ص���. 
// 
// const char* str = "Constant string"; �迭�̴�. 
// �迭 str�� string�� �����Ͽ� �ʱ�ȭ�� �� �ִ�. 
// ���� ���ǿ��� �޸� �ּұ��� ���鼭 �����ߴ�. 
// str ��ü�� modifiable lvalue�̴�. �׷��Ƿ�
// str = "Second string"; ó�� �ٸ� string���� ��ü���� �� �ִ�. 
// 
// "Constant string" = "Second String";�� �� �ȴ�. 
// "Constant string"�� rvalue�θ� ����� �� �ְ� lvalue�δ� ����� �� ����. 
// "Constant string"�� data object�� ���������� �ʴ´�. const�� �����Ѵ�. 
// 
// str[0] = 'A'; �̷� ������ ������ �ٲٷ��� �ϸ�, ������ �����. 
//	<= debugger ��忡���� ������ ��������, release ��忡���� �Ѿ �� �ִ�. 
// const�� ���� str[0]�� �����Ϸ��� �ϸ� ������ �����. �տ��� �ٷ����. 
// 
// const char* str = "Constant string"; ���� 
// const�� ��� ���̴��Ŀ� ���� �޶�����. 
// 
// char str2[] = "String in an array"; �� ���� 
// str2[0] = 'A';					   ���� �ٲ� ���� �ִ�. 
// 
// str2�� array�μ� ���� �޸� �Ҵ��� �ް�, 
// str2��� identifier�� 
// ���ڿ��� ����Ǳ� ����� �޸� ������ ���� �ĺ��� ������ �Ѵ�.
// 
// const char* str = "Constant string";
// char str2[] = "String in an array";
// �� �� ���� ���������� �۵��ϴ� ����� �ٸ��ٰ� ���� ���ǿ��� �����ߴ�. 
// 
// object�� �޸𸮿� ��ġ�ϴ� ���̴�. duration�� ���� �� �ִ�. 
// Identifier�� object�� ���� �̸� ������ �Ѵ�. 
// �̸��� �������� ���� �ƴϴ� �ٲ� �� �ִ�. �̸��� ���� ���� �ִ�. 
// 
// linkage��� �� ���� ���ǿ��� ���캻��. 
// ���������� ����ϴ� ���� �׸� ����� �ʴ�.  
//
