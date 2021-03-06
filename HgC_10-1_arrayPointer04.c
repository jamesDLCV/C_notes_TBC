#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ 포인터의 뺄셈과 관계 연산
// 포인터에는 정수 덧셈이나 증가 연산 외에도 다양한 연산을 수행할 수 있다. 
// eg) 가리키는 자료형이 같으면, 포인터끼리의 뺄셈이 가능하다. 
//     <= 일반 뺄셈과는 다른 방식으로 연산된다. 
// 
// 포인터 - 포인터 ----> 값의 차 / 가리키는 자료형의 크기
//
// 관계 연산자로 대소 관계도 확인할 수 있다. 
// 예제를 통해 포인터로 수행할 수 있는 연산을 살펴 보자.

int main() {

	{
		int arr[5] = { 10, 20, 30, 40, 50 };
		int* ptr_a = arr;					// 첫 번째 배열 요소의 주소
		int* ptr_b = ptr_a + 3;				// 네 번째 배열 요소의 주소

		printf("ptr_a: %u\n", ptr_a);		// 809366952
		printf("ptr_b: %u\n", ptr_b);		// 809366964
		printf("\n");

		ptr_a++;							// ptr_a를 다음 배열 요소로 이동

		printf("ptr_a: %u\n", ptr_a);		// 809366956

		printf("ptr_b - ptr_a: %u\n", ptr_b - ptr_a);	// 두 포인터의 뺄셈
														// 2 = (64 - 56) / 4
		printf("앞에 있는 배열 요소의 값 출력: ");

		if (ptr_a < ptr_b)	printf("%d\n", *ptr_a);	// ptr_a가 배열 앞에 있으면
													// *ptr_a 출력
		else printf("%d\n", *ptr_b);		// ptr_b가 배열 앞에 있으면,
											// *ptr_b 출력
	}

	// 위 예제를 그림으로 표현해 보자.
	//
	// arr 배열 == 52     56     60     64     68
	//            |  10  |  20  |  30  |  40  |  50  |
	//   ptr_a == 52           ptr_b == 64
	// 
	// ptr_a는 배열명으로 초기화하므로 첫 번째 배열 요소를 가리킨다. 
	// ptr_b는 ptr_a에 3을 더해 초기화하므로 64번지를 갖고 네 번째 요소를 가리킨다. 
	// 이 상태에서 ptr_a++;이 수행되면, 
	// ptr_a는 56으로 증가하면서 두 번째 배열 요소를 가리키게 된다. 
	//
	// arr 배열 == 52     56     60     64     68
	//            |  10  |  20  |  30  |  40  |  50  |
	//          ptr_a == 56    ptr_b == 64
	//
	// ptr_b - ptr_a의 연산은 다음과 같이 수행된다. 
	// 
	// ptr_b - ptr_a == (64 - 56) / sizeof(int) == 8 / 4 == 2
	//                    값의 차      가리키는 
	//                              자료형의 크기  
	//
	// 뺄셈 결과는 배열 요소 간의 간격 차이를 의미한다. 
	// 따라서 결괏값으로 포인터 ptr_a와 ptr_b가 가리키는 배열 요소의 위치가 
	// 2개 떨어져 있음을 알 수 있다. 
	// 
	// 배열은 배열 요소가 메모리에 순서대로 할당되므로 
	// 앞의 배열 요소가 뒤의 배열 요소보다 주솟값이 작다. 
	// 
	// 따라서 관계 연산의 결과로 두 포인터가 가리키는 배열 요소의 순서를 확인할 수 있다.
	// 배열의 덧셈은 의미가 없으므로 사용하지 않는다. <= 에러 발생!
	puts("");

	{
		// 확인 문제 3.
		// 포인터 ptr_b로 세 번째 배열 요소부터 마지막 배열 요소까지 출력해 봐라.
		double arr[5] = { 1.2, 3.5, 7.4, 0.5, 10.0 };
		double* ptr_a = arr;
		double* ptr_b = arr + 2;

		for (int i = 0; i < 3; ++i) {
			printf("%.1lf ", *ptr_b);
			ptr_b++;                       // ptr_b를 다음 배열 요소로 이동
		}
		puts("");
	}

	// 배열명은 첫 번째 배열 요소의 주소이다. 
	// 포인터와 배열의 관계는? 

	return 0;
}

//$ 마무리
// 
// 배열명은 첫 번째 배열 요소의 주소이다. 
// 포인터에 배열명을 저장하면, 포인터를 배열명처럼 사용할 수 있다. 
// 배열명의 정수 덧셈은 가리키는 자료형의 크기를 곱해서 더한다. 
// 포인터의 뺄셈 결과는 배열 요소 간의 간격 차이를 의미한다. 
// 
// 배열명
// int arr[3];
// arr == &arr[0];	<= 배열명은 첫 번째 요소의 주소
// 
// 배열명 + 정수
// int arr[3];
// arr + 1;			<= 가리키는 자료형의 크기를 곱해서 더한다. 
//                     arr + (1 * sizeof(*arr))
// 
// 배열명과 포인터는 같다. 
// int arr[3];
// int ptr_a = arr; <= 포인터에 배열명을 저장하면, 포인터를 배열명처럼 쓸 수 있다. 
// ptr_a[1] = 10;   <= 두 번째 요소에 10을 대입
// 
// 배열명과 포인터는 다르다. 
// arr++;			<= 안 된다. 배열명은 상수이므로 그 값을 바꿀 수 없지만, 
// ptr_a++;			<= 된다.    포인터는 그 값을 바꿀 수 있다. 