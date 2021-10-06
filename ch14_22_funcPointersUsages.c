#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>	// toupper(), tolower()

// Function Pointers, 함수 포인터의 사용 방법
//
// 함수 포인터가 프로그래밍을 얼마나 유연하게 만드는지 살펴 보겠다.

// toupper() 함수를 사용해서 문자열에 들어 있는 모든 문자를 대문자로 바꿔 준다.
void ToUpper(char* str) {		
	while (*str) {
		*str = toupper(*str);	// ctype.h에 들어 있는 함수 toupper()
		str++;
	}
}

// 한 글자씩 바꿔 주는 tolower() 함수를 이용해서 문자열 전체를 소문자로 바꿔 준다.
void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);	// ctype.h에 들어 있는 함수 lower()
		str++;
	}
}

int main() {

	char str[] = "Hello, World!";

	void (*pf)(char*);

	pf = ToUpper;	// Name of a function is a pointer
	// pf = &ToUpper;		// Acceptable
	// pf = ToUpper(str);	//Not acceptable in C

	printf("String literal %lld\n", (long long)("Hello, World!"));
	printf("Function pointer %lld\n", (long long)ToUpper);
	printf("Variable %lld\n", (long long)str);

	(*pf)(str);
	//pf(str);	//K&R X, ANSI OK

	printf("ToUpper %s\n", str);

	pf = ToLower;

	//(*pf)(str);
	pf(str);

	printf("ToLower %s\n", str);

	/*
		passing function pointers to functions
	*/

	return 0;
}

// 위 void ToUpper(char* str) 함수와 
// void ToLower(char* str) 함수의 특징은,
// 입력이 문자열이다. 문자의 포인터로 돼 있는 문자열이다. 
// 문자열을 입력 받으려고 char* str와 같이 해 놨다. 
// 그리고 반환값 타입은 void이다. 반환값이 없다. 
// 두 함수는 parameter와 return type이 동일하다. 
// 
// 즉, 동일한 함수 포인터를 통해서 
// void ToUpper(char* str)을 사용할 수도 있고, 
// void ToLower(char* str)을 사용할 수도 있다. 
// 
// 
	/*
	char str[] = "Hello, World!"; <= 대소문자가 섞여 있는 문자열

	void (*pf)(char*); <= 함수 포인터를 선언했다. 
	 <= 함수 포인터의 이름(식별자, identifier)는 pf이고,
	    함수 포인터이므로 앞에 asterisk *를 붙여 놨다. 
		parameter에 대한 정도 char*도 넣어 줬다. 
		반환값 정보 void도 넣어 줬다. 	    

	pf = ToUpper;	// Name of a function is a pointer
	 <= ToUpper()라는 함수를 이미 선언하고 정의해 놨다. 
	    포인터 pf가 ToUpper() 함수를 가리키도록 대입을 해 줄 수 있다. 
     <= 대입을 해 줄 때 두 가지 관점이 있다고 앞 강의에서 언급했다. 
	    하나는 pf = ToUpper;이고 또 다른 하나는 pf = &ToUpper;이다. 	 
	 <= pf = &ToUpper;		// Acceptable
		함수 이름(식별자) 앞에 addressof operator를 붙여서 사용할 수도 있다.
		즉 ToUpper로부터 주소를 가져 와서 그 주솟값을 포인터에 대입할 수 있다. 
	 <= 내부 작동 원리 측면에서 살펴 보면, 
		함수의 이름 자체가 그 함수가 저장돼 있는 메모리의 주소이다. 
		마치 배열의 이름이 첫 번째 원소의 주소처럼 사용되는 것과 비슷하다.
		함수의 이름 자체가 주소이기 때문에 그냥 주소를 대입할 수 있다. pf = ToUpper; 

	// pf = ToUpper(str);	//Not acceptable in C
	 <= 하지만 ToUpper(str) 이것은 함수를 실행시킨 것이다. 
	    괄호 안에 parameter가 들어 있다. 
	    위 pf = ToUpper;와 pf = &ToUpper;는 괄호가 없다. 

		pf = ToUpper(str);의 의미는 ToUpper(str) 함수를 실행시켜서 
		그 반화값을 pf에 대입시키겠다는 뜻이다. 
		왼쪽에 있는 pf는 함수 포인터이고, ToUpper(str)는 반환값이 없는 함수이므로
		타입도 안 맞고, ToUpper(str)는 함수를 실행시킨다는 의미이므로 
		pf = ToUpper(str);는 대입이 되지를 않는다. 
     <= pf = ToUpper;와 같이 인식자만 넣어 주어야, 
	    함수 포인터에 함수의 주소를 대입해서 넣어 줄 수가 있다. 

    // 주소를 출력해 보자. 
	printf("String literal %lld\n", (long long)("Hello, World!"));
	 <= String literal 140701715045752
	printf("Function pointer %lld\n", (long long)ToUpper);
	 <= Function pointer 140701715010471
	
	<= "Hello, World!"와 ToUpper는 TEXT Segment에 저장돼 있다.

	printf("Variable %lld\n", (long long)str);
	 <= Variable 56036948168
	    str 자체는 배열의 이름이기 때문에 주소이다. 

	<= str는 stack에 저장이 된다. 그래서 주소가 TEXT Segment와는 멀리 떨어져 있다.

	함수 포인터를 선언할 때 왜 이렇게 복잡한가?
	void (*pf)(char*);
	그냥 모든 function을 다 가리킬 수 있는 함수 포인터를 만들면 좋지 않을까?

	함수 포인터에 기본적으로 어떤 parameter가 들어오는지, 
	반환값의 타입이 뭔지를 미리 지정을 해 줘야 하는 이유는,
	이 함수 포인터를 통해서 실행을 시키려면 parameter가 뭐가 들어가는지, 
	반환값이 뭐인지를 알아야 하기 때문이다. 

	(*pf)(str);
	 <= str을 parameter로 넣어주면 ToUpper(str)과 똑같은 효과를 낼 수 있다. 
	    왜냐하면 pf라는 포인터가 ToUpper를 가리키고 있기 때문이다. 

	pf = ToUpper;와 pf = &ToUpper;가 모두 허용이 된다고 앞에서 언급했다.
	함수 포인터를 통해서 함수를 실행시킬 때도, 이 두 가지 관점이 모두 허용이 된다. 
	pf(str);	//K&R X, ANSI OK
	 <= 허용
	
	첫 번째 관점은, pf는 포인터이다. 함수 포인터도 포인터이다. 
	그러므로 indirection *을 한 다음에 *pf(str) 이렇게 실행을 시켜야 한다는 관점이다.

	두 번째 관점은, 어차피 함수 이름 자체도 주소이다. 
	그러므로 pf(str) 이렇게 바로 실행을 시켜도 된다는 관점이다. 
	K&R 표준에서는 pf(str)를 허용하지 않았으나, ANSI에서는 허용한다. 

	이제 아주 옛날 컴파일러를 사용할 일은 없을 것이기 때문에 
	pf(str)는 허용되는 것으로 간주하면 된다. 

	printf("ToUpper %s\n", str);

	pf = ToLower;
	*/
//
// 위 코드의 실행을 순서대로 살펴 보면 다음과 같다. 
// pf = ToUpper; <= ToUpper 함수의 주솟값을 함수 포인터에 대입해서 저장해 놨다가 
// (*pf)(str);	 <= 여기에서 실행을 시키고,                
// printf("ToUpper %s\n", str); <= 그다음 str이 어떻게 변했는지 출력을 해 본다.
// 
// pf = ToLower; <= 함수 포인터 pf에다가 ToLower 함수의 주솟값을 대입해 놓고,  
// pf(str);      <= 이 포인터를 통해서 실행을 시킨다. 
// printf("ToLower %s\n", str);
// 
// pf = ToUpper;
// (*pf)(str)	 <= pf가 가리키고 있는 것이 ToUpper 함수이므로, 
//                  마치 ToUpper 함수를 실행시킨 것처럼 실행이 된다. 
// pf = ToLower; <= pf가 ToLower 함수를 가리키고 있기 때문에, 
// pf(str);      <= 마치 ToLower 함수를 실행시킨 것처럼 실행이 된다. 
// 
// 실행을 시키면,
// ToUpper HELLO, WORLD!
// ToLower hello, world!
// 가 출력된다. 
// 
// void ToUpper(char* str) 
// void ToLower(char* str) 
// <= 이 두 함수의 바디를 보면 내용이 거의 비슷하다. 
//    차이는 toupper() 함수를 사용하느냐, tolower() 함수를 사용하느냐이다. 
//    그러면 이 두 함수를 합쳐서 하나의 함수처럼 어떤 틀을 만들 수 있을까?
// 
// 공통되는 패턴을 묶어서 하나의 함수로 만들고, 
// 바뀌어야 하는 부분만 바꿔 넣을 수 있게 만들어 주면, 
// 코딩하는 분량이 줄어 들고, 
// 유지, 보수를 할 때 노력이 적게 들고, 
// 실수를 할 확률이 줄어든다. 
// 
// 함수 포인터, 이후에 나오는 여러 가지 응용 기법들(객체지향의 다형성)을 
// 이해하고 잘 활용한다면 프로그램이 훨씬 유연해지고 편해진다. 
// 
// 위 두 함수를 어떻게 합칠까? 
// 함수 포인터를 통해서 합친다. 