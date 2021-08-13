#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 동적 할당 메모리와 저장 공간 분류
// 마지막으로 간단하게 정리한다. 
// 
// 동적 할당 메모리는 인식자가 없기 때문에, (변수 이름이 없기 때문에)
// Storage class 저장 공간 분류에서 분류한 다섯 가지에 해당되지는 않는다. 
// 
// 가장 중요한 차이는 Heap 메모리에 저장하게 되는데, 
// 운영체제에게 지금 이 정도 크기의 메모리가 필요하다, 메모리 공간을 할당해 달라고 
// 요구하면, 운영체제는 포인터를 넘겨 준다. 
// 
// malloc(), calloc(), realloc() 등의 함수를 사용하면, 
// 포인터만 넘겨 준다. 
// 그 포인터를 인식자라고 할 수도 있고 변수 이름처럼 생각할 수도 있다.
// 주소를 갖고 있는 변수일 뿐이지, 인식자처럼 특히 자동 변수처럼 
// 자동으로 duration을 관리해 주지는 않는다. <= 메모리 누수에서 설명했다. 
// 
// 힙에 동적으로 위치하게 된 메모리는, 프로그래머가 해제해 달라, 다 썼다, 
// 가져 가라고 요구할 때까지, 힙 메모리에 계속 자리를 잡고 있게 된다. 
// 
// 그 과정을 다시 한번 보자.  

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

// 실행을 하면, 다음과 같다. 
// Local pointer                   153944980120
// Function pointer                153944980152
// String data                     140700016745868
// Function address                140700016710047
// Function address                140700016710252
// Global variabe                  140700016754688
// Local variable                  153944979828
// Allocated memory                2311734362880
// 
// 주소값의 경향성을 보면, 
// Local pointer, Function pointer, Local variabldl가 가깝고,
// String data, Function address의 주소가 가깝다. 
// Global variable <= GCC에서는 다른 위치에 있으나, 여기에서는 비슷한 위치로 보인다.
// Allocated memory은 또 다른 곳에 위치하고 있는 주소처럼 보인다. 
// 
// printf("Local pointer		\t%lld\n", (long long)& message);
//	message pointer 자체의 주소를 찍고 있다. 
//  포인터 자체는 지역 변수다. <= stack으로 간다. GCC에서는 주솟값이 높다.
// 
// printf("Function pointer	\t%lld\n", (long long)&f_ptr);
//	function pointer 자체의 주소를 출력하고 있다. 
//	function 자체도 메모리에 저장된다. <= stack으로 간다. GCC에서는 주솟값이 높다.
// 
// printf("String data		\t%lld\n", (long long)message);
//	message 자체의 주소를 출력.
//  message = "Banana"는 컴파일할 때 exe 파일에 같이 탑재가 된다.   
//  프로그램 코드가 로딩이 될 때 같이 들어간다. <= TEXT segment로 간다. 
//  <= GCC에서는 주소가 낮다. 
// 
// printf("Function address	\t%lld\n", (long long)f_ptr);
//  function 자체의 주소, function pointer 변수에 저장돼 있는 주소를 출력. 
//  func() 함수가 메모리 레이아웃의 어디에 위치하고 있는지 출력.
//  function address는 프로그램 코드에 있다. 
//  <= "Banana"가 위치한 TEXT segment로 간다.
// 
// printf("Function address	\t%lld\n", (long long)main);
//	main() 함수는 어디에 위치하고 있는지 출력. 
// 
// printf("Global variabe		\t%lld\n", (long long)&g);
//  file scope variable g는 메모리의 어디에 있는지 주소를 출력. 
//  <= DATA segment 영역으로 간다. TEXT segment보다는 대략 높은 주소 위치에 있다. 
// 
// func(); 함수를 실행하면, 함수 안에서 자신의 local variable의 주소를 출력.
//  <= stack에 위치한다. 
// 
// printf("Allocated memory	\t%lld\n", (long long)ptr);
//	동적 할당 메모리 자체 ptr의 주솟값이 뭔지 출력.
//  <= 힙으로 간다. 
//  <= stack과 Data segment 사이의 영역의 주솟값을 갖는다. 
// 
// 힙 메모리가 자유 공간 쪽으로 넗혀져 가면서 메모리 공간을 받아 온다.  
// 동적 할당으로 받아온 메모리는 힙에 위치하고, 
// 운영체제가 그때 그때 상황에 따라서 할당해 준다. 
// 
// storage size는 상황에 따라서 크기가 달라진다.
// 프로그램 코드가 크다면, TEXT segment의 영역이 커질 것이다.
// 전역변수가 많다면, DATA segment, BSS의 영역이 커질 것이다. 
// 그때 그때 달라진다. 
// 
// 더 자세한 내용을 공부하고 싶으면, 컴파일러, 운영체제 같은 수업을 들으면 된다. 
// 
// 동적 할당 메모리가 다른 요소들과는 달리, 
// 다른 저장 공간 분류들과는 달리, 
// 힙에 저장된 특성을 갖게 되고, 
// 그로 인해서 영역이라는 것이 자동으로 관리되는 것이 아니고, 
// 프로그래머가 수동으로 관리해 줘야 한다. 