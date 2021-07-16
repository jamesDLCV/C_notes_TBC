#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// linkage에 대해서 살펴 본다.
// 이렇게 코딩하는 일은 많지 않다. 
// 한 프로젝트 밑에 C 파일이 두 개가 있다. 
// 보통은 파일 단위로 코딩을 한다. 
// 
// 이 파일은, 컴파일러가 컴파일을 하는 최소 단위이다. 
// tanslation unit이라고 한다. 
// 컴파일러는 일종의 번역기이다. 
// 프로그래밍 언어로 작성한 문서를 기계어로 번역을 해 주는 것이다. 
// tanslation unit의 단위가 파일인 것이다. 
// 
// 그러므로 동일 프로젝트 아래에 있는 C 파일 두 개는 
// 컴파일러가 따로 따로 컴파일을 한다.
// 그러므로 파일 내에 뭐가 있는지 서로 알 방법이 없다. 
// 이 두 개의 파일을 연결해 주는 것이 linker이다. 

/*
	Linkage

	Variable with block scope, function
	- No linkage

	File scope variables
	- External or internal linkage
*/

// 파일 전체에서 사용할 수 있는 scope에 선언돼 있다. 
// 특정 함수나, 특정 블록의 scope에 선언돼 있지 않다. 
int el;		// file scope with external linkage (global)
static int il;	// file scope with internal linkage				

void testLinkage();	// 다른 파일에 있는 함수의 몸체를 main() 함수에서 사용하기 위해, 
					// prototype만 선언을 해 주었다. linking하는 구조이다. 

int main() {

	el = 1024;

	testLinkage();

	printf("%d\n", el);	// 다른 파일에서 처리된 el 값이 출력된다. 
						// el 변수가 내부적으로 가지고 있는 object에서 
						// 값이 또 바뀐 것이다. 
		// 이 파일의 변수 el과 다른 파일의 el이 object를 공유하고 있다.
		// 어느 파일에서든, 어느 translation unit에서든, 사용할 수 있다.
		// <= global variable이라고 한다. 
						

	return 0;
}

/* 
int el;		// file scope with external linkage (global)
			// el이 선언돼 있다는 것을 같은 프로젝트 내의 다른 파일에서는 알수가 없다.
			// 다른 파일에서 접근하기 위해서는 extern이라는 키워드를 사용한다.
	// file scope에 있는 변수는, 마치 프로그램 전체에서 사용할 수 있는 것처럼,
	// 즉 전역변수처럼 사용할 수 있어서 <= 전역변수라고 부른다.
	// 전역변수로 쓰일 수도 있지만, file scope로 쓰일 수도 있다.
	// 다른 파일에서 extern을 사용해서 이 전역변수를 사용할 수 있다.

static int il;	// file scope with internal linkage
				// 다른 파일에서는 볼 수가 없으므로 internal linakge이다.
				// 키워드로서의 static은,
				// 이 변수의 범위가 현재 scope에 제한된다라는 의미가 있다.
				// 정적이다.
				// 다른 파일 scope에서 사용할 수 없다.
				// 다른 파일에서 extern으로 접근할 수 없다.
				// 다른 파일에서 사용하면, unresolved externals Error가 뜬다.

*/

