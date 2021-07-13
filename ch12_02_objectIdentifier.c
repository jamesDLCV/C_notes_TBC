#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 용어를 정리해 보자.
// 객체와 식별자가 어떻게 다른지 알아 본다. 
// L-value, R-value에 대해서도 살펴 본다. 
// 

int main() {
	/*
		Object 객체
		- "An object is simply a block of memory that can store a value."
			(KNK p487) C에서의 objectsms, 메모리에 공간을 가지고 있으면 object이다. 
		- Object has more developed meaning in C++ and 
			Object Oriented Programming (OOP) object의 개념이 확장된다. 

		Identifiers 식별자, 인식자; 이름이다, 변수의 이름, 함수의 이름.
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
	int temp = var_name;	// var_name은 rvalue, var_name은 값을 전달해 줄 뿐이다.
	temp = 1 + 2;	// 1 + 2는 expression이다. 				

	pt = &var_name;
	int* ptr = arr;
	*pt = 7;	// *pt is not an identifier but an modifiable lvalue expression

	int* ptr2 = arr + 2 * var_name;	// address rvalue
	*(arr + 2 * var_name) = 456;	// lvalue expression

	const char* str = "Constant string";	// str is a modifiable lvalue.
	str = "Second string";	
	// "Constant string" = "Second String" <= impossible, 안 된다. 

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

// 프로그래밍 언어를 가볍게 공부를 하게 되면, 
// 변수 이름과, 그러니까 식별자와 메모리 공간에 있는 object를 동일시하게 된다. 
// 최근에 나오는 좀 더 편한 프로그래밍 언어들은, 
// 프로그래머가 그렇게 오해하도록 방치하는 경향도 있다. 그래야 더 쉬워 보인다. 
// 
// 이번 강의에서는 object와 identifier의 차이 위주로 살펴볼 것이고,
// 이어 지는 강의에서 이 둘의 차이를 오해하기 쉬운 
// 변수의 영역과 object의 지속 기간의 차이에 대해서 다룰 것이다. 
// 
// int var_name = 3; 는 메모리 공간에 3이라는 값을 복사해서 넣어 주는 것이다. 
// 메모리 공간에 접근을 할 때, 이 변수 이름을 통해서 접근을 하고 있다. 
// 이 변수는 이름에 불과하지만 마치 object를 직접 사용하는 것처럼 
// C언어가 우리를 도와주고 있는 것이다. 
//	어셈블리어에서는 주소를 가지고 직접 값을 대입하고, 옮기고 했다.
// 
// int* pt = &var_name;
// 포인터 변수 pt도 주소를 갖는다.  
// 포인터 변수도 메모리 공간을 갖고, 포인터 변수에 주솟값을 저장하는 것이다 .
// 그러므로 pt라는 포인터 변수 이름도 식별자이다. 
// 거기에 다른 변수의 주솟값을 저장한다. 
// 
// *pt = 1; 이것이 조금 헤깔릴 수 있다. Indirection해주는 expression이다. 
// *pt는 주소가 가리키고 있는 메모리 공간을 의미하므로, 
// *pt, 이 세 글자를 식별자로 생각할 수 있으나, 문법상 식별자는 아니다. 
// 앞에 *가 붙은 것은 expression 표현식이다. 
// 하지만 *pt는 object를 지목할 수 있다. 
//	(포인터에서 가리킨다라는 말을 쓰므로 지목한다라고 했음)
// 
// *pt를, 마치 변수인 것처럼 사용할 수 있지만, 
// *pt 자체는 identifier 식별자는 아니고, 
// indirection *을 통해서 object를 지명할 수 있다.
// 반면, pt는 주솟값을 저장하는 identifier이다. 
// 전산학에서는 referring이라는 용어를 많이 사용한다. 
// 
// int arr[100]; 을 보자, 배열을 선언했다. 
// arr은 배열의 이름이다. 그러므로 식별자가 맞다. 
// 
// arr이 object인가? 
// arr은 배열의 첫 번째 원소의 주소이다. 
// 그 자체가 메모리 공간을 갖는 object는 아니다. 
//	arr 자체는 object가 아닌 것이다. 즉, 배열의 이름은 object가 아니다. 
// 그러나 배열의 이름은 식별자로 쓸 수는 있다. 이름은 이름이므로. 
// 
// arr[0]는 identifier는 아니다, expression이지만, object이다. 
// identifier는 아니지만 expression을 통해서 메모리 공간에 접근할 수 있다. 
//	0번 index가 가리키는 메모리 공간을 사용할 수 있기 때문에, 
//	메모리 공간에 접근해서 7이라는 값을 집어 넣을 수가 있다. 
// 따라서 arr[0]은 object이다. 
// 
// object와 identifier는 다른 개념으로 사용된다. 
// 
// lvalue는 object를 referring하는 expression이다. 
// refer는 C++에서 참조라고 한다. 뭔가를 부르는데 다른 방식으로 부른다. 
// 
// 포인터를 통해서 포인팅한다고 하면, 주소로 거기를 찾아가서 거기에서 값을 갖고 온다. 
// 그 메모리 공간에다가 뭔가를 한다라는 의미가 된다. 
// 
// refer이라고 하면, 또 다른 이름처럼 사용한다 정도로 정리해 둬라.
//  
// var_name = 3; 을 보면, var_name은 메모리 공간을 refer해 준다. 
// 변수 이름이 메모리 공간은 아니다. 
// 변수 이름이 내부적으로 가리키고 있는(referring 해주는) 메모리 공간에다가 
// 3이라는 값을 복사해서 넣는 것이다. <= 이 개념을 잘 정리해두자. 
// 
// var_name = 3;	// modifiable lvalue, 변경할 수 있는 lvalue이다. 
// int temp = var_name; 에서 오른쪽에 온 var_name은 
// 값을 받아다가 왼쪽 temp에 전달만 해 준다. 
// temp가 가지고 있는 메모리 공간에 복사해서 들어간다. <= 개념 정리 잘해둬라. 
// 
// 변수는 lvalue도 되고, rvalue도 되는데 ravlue일 때는 값만 옮겨주는 역할을 한다.
// temp = 1 + 2;	// 1 + 2는 변수처럼 메모리 공간을 갖지 않는다. 
					// expression일 뿐이다. 
// 1 + 2는 cpu에서 3이라는 값으로 바꿔주고, 3이라는 값을 temp에 대입할 뿐이다. 
// 따라서, 1 + 2는 object가 아니다. 
// 1 + 2 = temp; <= 이런 건 안 된다. 
// 1 + 2는 메모리 공간을 의미하는 object가 아니기 때문이다. 
// 
// lvalue와 rvalue의 근본적인 차이는?
// lvalue는 object이다. 메모리에 공간을 가지고 있다.  
// 그러므로 그 메모리 공간에다가 어떠한 값을 assignment할 수 있다. 
// 
// object가 식별자를 통해서 rvalue로 사용될 때에는, 
// 값만 가지고 와서 넘겨주는 식이다. 
// 이러한 문법적인 부분은 C++에 가면 조금 더 복잡해진다. 
// 
// pt = &var_name; 는 포인터에다가 변수의 주솟값을 대입하고 있다. 
// 따라서 포인터 pt도 modifiable lvalue이다. 
// const를 붙이면, non-modifiable lvalue로 만들 수 있다. 
// 
// int* ptr = arr; 는, 포인터에다가 배열의 이름(identifier이나 object는 아니다, 
// 주소이기 때문이다), 주솟값을 rvalue로써 lvalue인 ptr에 대입한다. 
// 포인터 변수 ptr이 가지고 있는 메모리에 arr이 알려주는 주솟값을 저장할 수 있다. 
// 
// *pt = 7; 를 보면, *pt 자체는 identifier는 아니지만, 
// modifiable lvalue로서 사용할 수 있는 expression이다. 
// modifiable lvalue expression으로서 object의 값을 바꿀 수는 있다.  
// 
// int* ptr2 = arr + 2 * var_name; 를 보면, 
// arr은 포인터의 이름이다. 배열의 이름이다. 
// 포인터 연산을 활용해서 값을 바꿔보았다. 
// arr + 2 * var_name은 주소다. rvalue이다. 
// 포인터 연산을 통해 나온 주솟값이므로 rvalue로서만 사용될 수 있다. 
// 
// 그러나, *(arr + 2 * var_name) = 456; 에서처럼 
// 앞에서다가 indirection operator *을 붙여주면,
// modifiable lvalue expression인 것처럼도 사용할 수 있다. 
// 
// identifier, object; lvalue, rvalue 잘 정리해두자. 
// 
// const char* str = "Constant string"; 배열이다. 
// 배열 str에 string을 대입하여 초기화할 수 있다. 
// 이전 강의에서 메모리 주소까지 찍어가면서 설명했다. 
// str 자체는 modifiable lvalue이다. 그러므로
// str = "Second string"; 처럼 다른 string으로 교체해줄 수 있다. 
// 
// "Constant string" = "Second String";는 안 된다. 
// "Constant string"는 rvalue로만 사용할 수 있고 lvalue로는 사용할 수 없다. 
// "Constant string"는 data object로 간주하지는 않는다. const로 간주한다. 
// 
// str[0] = 'A'; 이런 식으로 강제로 바꾸려고 하면, 문제가 생긴다. 
//	<= debugger 모드에서는 문제가 생기지만, release 모드에서는 넘어갈 수 있다. 
// const를 떼도 str[0]을 변경하려고 하면 문제가 생긴다. 앞에서 다루었다. 
// 
// const char* str = "Constant string"; 에서 
// const를 어디에 붙이느냐에 따라서 달라진다. 
// 
// char str2[] = "String in an array"; 이 경우는 
// str2[0] = 'A';					   값을 바꿀 수가 있다. 
// 
// str2은 array로서 따로 메모리 할당을 받고, 
// str2라는 identifier가 
// 문자열이 저장되기 충분한 메모리 공간에 대한 식별자 역할을 한다.
// 
// const char* str = "Constant string";
// char str2[] = "String in an array";
// 위 두 개는 내부적으로 작동하는 방식이 다르다고 이전 강의에서 설명했다. 
// 
// object는 메모리에 위치하는 것이다. duration을 가질 수 있다. 
// Identifier는 object에 대한 이름 역할을 한다. 
// 이름이 절대적인 것은 아니다 바뀔 수 있다. 이름은 없을 수도 있다. 
// 
// linkage라는 용어도 다음 강의에서 살펴본다. 
// 문법적으로 사용하는 것은 그리 어렵지 않다.  
//
