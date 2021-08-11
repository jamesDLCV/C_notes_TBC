#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 컴퓨터의 메모리 구조는 1차원이기 때문에, 1차원을 다차원처럼 사용한다. 
// 1차원을 다차원으로 사용하는 방법을 살펴 보자.
// 
// 3차원이 되면 조금 복잡해진다. 
// 4차원 이후로는 그림으로 표현하기 어렵다. 머릿속에서 추상적으로 상상을 해야 한다. 
// 3차원은 앞에서 보여 준 2차원 배열이 두 개 있는 것이다. 

int main() {

	/*
		Using 1D arrays as 3D arrays

		row = 3, col = 2, depth = 2

		(r, c, d)

		3D
		-------------------
		(0, 0, 0) (0, 1, 0)
		(1, 0, 0) (1, 1, 0)
		(2, 0, 0) (2, 1, 0)
		-------------------
		(0, 0, 1) (0, 1, 1)
		(1, 0, 1) (1, 1, 1)
		(2, 0, 1) (2, 1, 1)
		-------------------

		1D
		(0, 0, 0) (0, 1, 0) (1, 0, 0) (1, 1, 0) (2, 0, 0) (2, 1, 0) (0, 0, 1) (0, 1, 1) (1, 0, 1) (1, 1, 1) (2, 0, 1) (2, 1, 1)
		0	   1      2      3      4      5     6 .... 11 = c + col * r + (col * row) * d

		4D
		row, col, depth, height
		(r, c, d, h)
		index = c + col * r + (col * row) * d + (row * col * depth) * h
	*/

	int row = 3, col = 2, depth = 2;
	int* ptr = (int*)malloc(row * col * depth * sizeof(int));
	if (!ptr) exit(1);

	for (int d = 0; d < depth; ++d) {
		for (int r = 0; r < row; ++r) {
			for (int c = 0; c < col; ++c) {
				ptr[c + col * r + (col * row) * d] = c + col * r + (col * row) * d;
			}
			
		}
	}

	/*
		매번 c + col * r + (col * row) * d을 넣기가 불편하므로 함수로 만들어서 쓴다.

		int idx2(int c, int r) {
			return c + col * r;
		}

		int idx3(int c, int r, int d) {
			static const int cr = col * row;
			return c + col * r + cr * d;
		}	
	*/

	for (int d = 0; d < depth; ++d) {
		for (int r = 0; r < row; ++r) {
			for (int c = 0; c < col; ++c) {
				printf("%d ", *(ptr + c + col * r + (col * row) * d));
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}

// 인덱스는 c + col * r + (col * row) * d 과 같이 나타낼 수 있다. 
// 3차원을 1차원 인덱싱으로 바꿀 수 있는 것이다. 
// 같은 요령으로 4차원, 5차원 그 이상도 모두 가능하다. 
// 
// row(r)가 증가할 때마다 column(col) 개수만큼 건너뛰는 방식이다. 
// 그림을 그려 가면서, 스스로 이해해야 한다. 
// col의 위치를 잘 봐 둬라. 
// 
// vision, graphics, deep learning 등을 공부할 예정이라면, 이것을 이해해 두는 것이 좋다. 
// 
// 4차원 배열도 1차원 배열을 사용하는 것처럼 할 수 있다. 
// index = c + col * r + (col * row) * d + (row, col, depth) * h
// <= 1차원 배열을 4차원 배열인 것처럼 사용할 수 있는 것이다. 
// 
// (row * col * depth) * h <= row, col, depth 세 개를 곱한 후 h만큼 건너뛰는 것이다.
// 4차원은 3차원을 건너뛰는 방식이고, 3차원은 2차원을 건너뛰는 방식이다. 
// 
// 이외 다차원 배열은 스스로 정리를 한 후 숙지해야 한다. 
//
// 매번 c + col * r + (col * row) * d을 넣기가 불편하므로 함수로 만들어서 쓴다.
// 큰 프로그램을 만들 때는 이렇게 함수로 만들어서 쓰게 될 것이다. 
// 
// int idx2(int c, int r) {
//	 return c + col * r;
// }
//
// int idx3(int c, int r, int d) {
//	 static const int cr = col * row;
//	 return c + col * r + cr * d;
// }
//  
// static const int cr = col * row;
// col * row을 연산하는 시간이 아까워서, 
// 연산 시간을 줄이고 싶으면 static에 넣어 놓으면 된다. 
// 
// 뒤에서 인라인을 배운다. 인라인을 써서 가속을 하는 경우도 있다. 
// 최근 코드에서는 그렇게까지는 안 한다. 
// 예전 코드를 보면, 빈번하게 사용되는 코드는 인라인을 사용하는 경우가 있었다. 
// <= 위 다차원 배열 코드 같은 경우
// 
// 위 다차원 배열 코드는 1차원적으로 증가하면서 접근을 하므로, 
// 포인터 ptr에다가 1씩 더해 가면서 좀 더 빠르게 접근하는 방법도 있다. 
// 이를 최적화하는 것은 나중에 필요하면, 머리를 쥐어짜면서 하게 될 것이다. 
// 
// 실행을 해 보면, 
// 0 1
// 2 3
// 4 5
//
// 6 7
// 8 9
// 10 11
// 이렇게 출력이 된다. 
// 
// 동적 할당으로 받아온 메모리를 다차원 배열처럼 사용하는 방법을 살펴 봤다. 
// 