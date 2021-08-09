#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 2차원 배열을 사용하는 게 조금 문제가 될 수 있다. <= 어려울 수 있다. 
// 딥러닝과 그래픽스에서 다차원 배열을 많이 사용한다. 

int main() {

	/*
		2D array
	*/

	int row = 3, col = 2;
	int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);
	//int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);
	// 열을 숫자가 아닌 변수로 받으려면, 컴파일러가 VLA를 지원해 줘야 한다. 

	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			ptr2d[r][c] = c + col * r;
		}
	}

	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			printf("%d ", ptr2d[r][c]);
		}
		printf("\n"); 
	}

	return 0;
}

// 다차원 배열을 사용하는 경우가 많으므로 소개를 한다. 
// 
// 앞에서 배운 배열을 사용하는 방법을 응용해서 사용하는 방법이 있다. 
// 
// int row = 3, col = 2; 행이 3개이고 열이 2개인 2차원 배열이다. 
// 메모리 전체 사이즈는 3 * 2 * int의 사이즈(4) = 24
// 원하는 메모리 사이즈를 받아오는 것은 쉽다. 
// 하지만 이것을 2차원 배열의 포인터로 받아오려면, 
// int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);
//             <= 열의 숫자를 맞춰 줘야 한다. 열의 개수를 숫자(상수)로 넣어 줘야 한다. 
// 컬럼 개수여야 한다. 배열 강의에서 설명했다. 
// 
// 컬럼을 변수로 넣어 주려면, 컴파일러가 VLA을 지원해 줘야 한다. 
// GCC에서는 지원을 해 주나, visual studio에서는 지원을 안 한다. 
// 실용적인 측면에서도 VLA 쓰는 거보다는 동적 할당 쓰는 게 더 편한다.
// 
// int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);
// 이렇게 받아오면, 2차원 배열인 것처럼 사용할 수 있다. 
// 
// 하지만 컬럼을 constant로 넣을 거면 동적 할당을 쓰는 의미가, 
// 많이 퇴색하게 된다. visual studio에서는 컬럼에 변수를 넣어 줄 수가 없다. 
// 
// 그러므로 실용적인 측면에서, 어떻게 하는가?
// 1차원 배열을 2차원처럼 사용하기도 하고, 
// 1차원 배열을 3차원처럼 사용하기도 한다. 
// 그 이상은 직접 응용해 보거나 라이브러리를 봐라. 
// 
// 컴퓨터의 메모리 구조는 1차원이기 때문에, 1차원을 다차원처럼 사용한다. 