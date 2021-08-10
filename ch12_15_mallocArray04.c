#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 2차원 배열을 사용하는 게 조금 문제가 될 수 있다.
// 딥러닝과 그래픽스에서 다차원 배열을 많이 사용한다. 
// 컴퓨터의 메모리 구조는 1차원이기 때문에, 1차원을 다차원처럼 사용한다. 
// 1차원을 다차원으로 사용하는 방법을 살펴 보자.

int main() {

	/*
		Using 1D arrays as 2D arrays

		row = 3, col = 2

		(r, c)

		2D
		(0, 0) (0, 1)
		(1, 0) (1, 1)
		(2, 0) (2, 1)

		1D
		(0, 0) (0, 1) (1, 0) (1, 1) (2, 0) (2, 1)
		0	   1      2      3      4      5       = c + col * r
	*/

	int row = 3, col = 2;
	int* ptr = (int*)malloc(row * col * sizeof(int));
	if (!ptr) exit(1);
	
	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			ptr[c + col * r] = c + col * r;
		}
	}

	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			printf("%d ", *(ptr + c + col * r));
		}
		printf("\n");
	}

	return 0;
}

// 다차원 배열에서 설명한 적이 있다. 
// 인덱스를 우리가 찾고자 하는 row와 column의 함수로 만들면, 
// c + col * r 과 같이 된다. 위에서 col은 2이다. 
// 
// 예제를 보면, ptr[c + col * r] 이런 식으로 접근하고 있다. 
// 포인터 연산을 할 때도 *(ptr + c + col * r) 이렇게 할 수 있다. 
// 
// 실행을 해 보면, 
// 0 1
// 2 3
// 4 5
// row 값이 바뀔 때마다 줄 바꿈을 하고 있다. 
// 
// 여기까지는 손으로 그려 보면 쉽게 이해가 간다. 