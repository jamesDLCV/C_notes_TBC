#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ 함수의 매개 변수 자리에 배열을 선언하는 경우
//
// 함수의 매개 변수 자리에 배열을 선언하면 배열의 저장 공간이 할당되지 않으며,
// 배열명은 컴파일 과정에서 첫 번째 배열 요소를 가리키는 포인터로 바뀐다. 
//
// void func(int ptr_a[5]) { ... }     ---->  void func(int *ptr_a) { ... }
// void func(int ptr_a[10]) { ... }    ---->  void func(int *ptr_a) { ... } 
// void func(int ptr_a[]) { ... }      ---->  void func(int *ptr_a) { ... }
// void func(double ptr_a[5]) { ... }  ---->  void func(double *ptr_a) { ... }
//   
// 따라서, 매개 변수 자리에 선언된 배열에서 배열 요소의 개수는 의미가 없으며,
// 생략도 가능하다. 
// 이런 자동 변환 기능 때문에 배열과 포인터에 대한 깊은 이해가 없어도 
// 배열을 처리하는 함수를 쉽게 만들 수 있다. 
// 
// 즉, 함수의 매개 변수에 처리할 배열과 '같은 배열'을 선언하고 
// 함수 안에서 배열처럼 사용하면 된다.
// 
// 컴파일러는 배열명을 자동으로 포인터로 바꾸고 
// 모든 배열 요소를 사용할 수 있도록 포인터 연산을 수행한다. 
// 
// 함수 정의
void print_arr(int ptr_a[5], int size);

int main() {

	// 배열 선언과 함수 호출
	int arr[5] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	print_arr(arr, size);					// 배열명을 주고 함수 호출     

	return 0;
}

void print_arr(int ptr_a[5], int size) {	// 매개 변수 자리에 
	for (int i = 0; i < size; ++i) {		// arr 배열과 같은 배열 선언 
		printf("%d ", ptr_a[i]);			// *(ptr_a + i)
	}
	puts("");

	for (int i = 0; i < size; ++i) {
		printf("%d ", *(ptr_a + i));
	}
}

// 매개 변수 자리에 선언된 배열은 포인터로 바뀌므로, 
// 함수 안에서 siezof 연산자로 배열의 크기를 알 수 없다. 
// 
// 배열명에 sizeof 연산을 수행하면 단지 포인터 하나의 크기만 구해진다. 
// 
// 따라서 배열 요소의 개수와 무관하게 배열을 처리하는 함수를 만들려면, 
// 반드시 배열 요소의 개수를 따로 받아야 한다. 
// 
//$ 마무리
// 배열을 출력하는 함수에 필요한 것은 배열명이다. 
// 배열에 입력하는 함수에 필요한 것도 배열명이다. 
// 배열의 크기가 달라도 입출력이 가능하려면 배열 요소의 개수를 알아야 한다. 
// 
//$ 배열에 입출력하는 함수
// 
//			     배열을 출력하는 함수            
// 호출    int arr[5] = {10, 20, 30, 40, 50};  
//        print_arr(arr, 5);                  
//
// 정의    void print_arr(int* ptr_a, int size) 
//        {
//            for (int i = 0; i < size; ++i)
//            {
//                printf("%d ", ptr_a[i]);
//            }
//        }
//
//              배열에 입력하는 함수 
// 호출    int arr[5];
//        input_arr(arr, 5);
// 
// 정의    void input_arr(int* ptr_a, int size)
//        {
//            for (int i = 0; i < size; ++i)
//            {
//                scanf("%d", ptr_a + i);
//            }
//        }