#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

//$ 배열에 값을 입력하는 함수
// 
// 배열에 값을 입력하는 함수도 배열의 값을 출력하는 함수와 구현 방법은 동일하다. 
// 
// 다만 입력 함수는 데이터를 저장할 배열의 위치가 필요하므로, 
// 함수 안에서 포인터를 직접 사용한다. 
// 
// 예제를 통해 실수 배열에 값을 입력하는 함수와 최댓값을 찾는 함수를 살펴 보자. 

void input_arr(double* ptr_a, int size);
double find_max(double* ptr_a, int size);
double find_max2(double* ptr_a, int size);
void print_arr(double* ptr_a, int size);

int main() {

	double arr[5];
	double max, max2;

	int size = sizeof(arr) / sizeof(arr[0]);	// 배열 요소의 개수 계산

	input_arr(arr, size);						// 배열에 값 입력
	max = find_max(arr, size);					// 배열의 최댓값 반환
	max2 = find_max2(arr, size);

	printf("\n");
	printf("배열의 최댓값: %.1lf\n", max);
	printf("배열의 최댓값: %.1lf\n", max2);
	printf("\n");

	print_arr(arr, size);

	return 0;
}

void input_arr(double* ptr_a, int size) {	// double 포인터를 매개 변수로 선언

	printf("%d개의 실수 값 입력: ", size);

	for (int i = 0; i < size; ++i) {		// size의 값에 따라 반복 횟수 결정
		scanf_s("%lf", ptr_a + i);			// &ptr_a[i]도 가능, 
	}                                       // 입력할 배열 요소의 주소를 전달
}

double find_max(double* ptr_a, int size) {

	double max;

	max = ptr_a[0];		// 첫 번째 배열 요소의 값을 최댓값으로 설정

	for (int i = 1; i < size; ++i) {
		if (max < ptr_a[i]) {
			max = ptr_a[i];
		}
	}
	return max;
}

double find_max2(double* ptr_a, int size) {

	double max;

	max = *ptr_a;		// 첫 번째 배열 요소의 값을 최댓값으로 설정

	for (int i = 1; i < size; ++i) {
		if (max < *(ptr_a + i)) {
			max = *(ptr_a + i);
		}
	}
	return max;
}

void print_arr(double* ptr_a, int size) {

	for (int i = 0; i < size; ++i) {
		printf("arr[%d] = %.1f\n", i, *(ptr_a + i));	// ptr_a[i] 
	}
}

// 첫 번째 배열 요소의 값을 ptr_a[0]으로 해도 되고, *ptr_a로 해도 된다.  
// 
// 이 예제는 double 형 배열에 값을 입력하는 함수와 
// 입력한 값 중에서 최댓값을 찾아 반환하는 함수를 만든다.
// 
// 이미 살펴 본 배열의 값을 출력하는 함수와 크게 다르지 않다. 
// 
// scanf_s("%lf", ptr_a + i);	
// <= ptr_a에 i를 더하여 각 배열 요소의 주소를 구하고, 
//    그 값을 그대로 scanf() 함수에 사용하는 특징이 있다. 
// 
// scanf() 함수는 입력한 값을 저장할 배열의 위치를 알아야 하므로, 
// 인수로 받은 ptr_a의 값을 그대로 사용한다. 
// 
// *(ptr_a + i)와 같은 연산으로 배열 요소를 구하고, 
// 다시 &(*(ptr_a + i))와 같이 주소 연산을 사용할 수도 있지만, 
// 불필요한 연산은 반복하지 않는 것이 좋다. 
// 
// 다만, &ptr_a[i]와 같이 대괄호를 사용한 배열 요소 표현식을 사용해도 나쁘지 않다. 
// 
// 간접 참조 연사(*)과 주소 연산(&)
//                     ptr_a + 2	세 번째 배열 요소 주소
//     *(ptr_a + 2) 또는 ptr_a[2]	세 번째 배열 요소
// &(*(ptr_a + 2)) 또는 &ptr_a[2]	세 번째 배열 요소 주소 
//
// 배열의 값을 출력하는 함수는 print_arr()에서 구현해 봤다. 