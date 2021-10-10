#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// qsort()

// qsort() 함수 포인터 연습 문제
//
// 함수 포인터의 장점을 좀 더 깊이 있게 살펴 보기 위해서
// qsort(), quick sort 함수에 대해서 연습 문제 형태로 살펴 보겠다.  
//
// 기본적인 qsort() 함수의 개념과 사용 방법에 대해서 설명을 하고, 
// 그다음 문제를 풀어 보도록 하겠다. 

//TODO: try increasing/decreasing order
int compare(const void* first, const void* second) {
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main() {
	int arr[] = { 8, 2, 5, 3, 6, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	

	return 0;
}

// compare()라는 함수가 있다. 
// compare()라는 함수는 규격이 정해져 있다. 
	/*
	int compare(const void* first, const void* second) {
	 <= void 타입의 포인터가 두 개가 들어오게 돼 있다. 
	    우리가 다루려는 데이터가 정수형인 예제이기 때문에, 
		if (*(int*)first > *(int*)second)
		 <= int pointer로 casting을 하고, 그다음 indirection을 해서, 
		    비교를 하고 있다. 
			return 1;
		else if (*(int*)first < *(int*)second)
			return -1;
		else
			return 0;
	}
	*/
//
// 문제는 다음과 같다. 
	/*
	int arr[] = { 8, 2, 5, 3, 6, 11 };
	 <= 먼저 데이터가 있다. 임의의 수가 나열돼 있는 형태이다. 
	    프로그래밍을 하다 보면, 데이터의 순서를 오름차순이나 내림차순으로 
		만들어 줘야 하는 경우가 많이 있다. 
		나중에 자료 구조를 공부할 때 qsort()를 직접 구현해 볼 것이다. 
		정렬 알로리즘 같은 것들을 많이 활용할 것이다. 

	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare);
	 <= sorting은 정렬이다. 순서를 맞춰 주는 것이다. 
	    qsort는 quick sort이다. 
	    정렬 sorting하는 알고리즘 중에서 가장 빠른 알고리즘 중 하나이다. 
		qsort() 알고리즘은 #include <stdlib.h>에 이미 구현이 돼 있다. 
		C언어에서 간단하게 사용할 수 있도록 준비가 돼 있다. 
	<= qsort() 함수를 사용하기 위해서는 
	   규칙에 맞춰서 compare() 함수를 구현해 줘야 한다. 
	   좀 더 편하게 int arr[] 배열의 원소들을 정렬해 주는 함수를 만들면 될 텐데, 
	   왜 이렇게 귀찮게 하는가라고 생각할 수도 있다. 
	   그러나 이렇게 해 주면, int 말고 다른 자료형을 정렬할 때도 사용할 수 있다. 
	   <= 이것이 연습 문제이다. 	    

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	*/
// 
// compare 비교한다는 것을 함수로 만들고, 
// 이것을 함수 포인터로 넣어 주면, 
// qsort() 함수가 compare 함수를 함수 포인터로 사용해서 정렬을 하게 된다. 
// 
// 위에서 실행시킨 것은 작은 숫자에서 큰 숫자로 정렬하는 오름차순 정렬이었다. 
// compare() 함수에서 부등호를 반대 방향으로 바꾸면, 내림차순 정렬로 바뀐다. 
// 
// compare() 함수가 어떻게 만들어져 있느냐에 따라서 정렬의 결과가 달라진다. 
	/*
	int compare(const void* first, const void* second) {
		if (*(int*)first > *(int*)second)
			return 1;
		else if (*(int*)first < *(int*)second)
			return -1;
		else
			return 0;
	}
	*/
//  <= 이 compare() 함수와 유사한 경우의 함수를 이전 강의에서 다뤘었다. 
//     <= 문자열을 비교하는 함수 strcmp() 함수가 있었다. 비슷한 구조이다. 
// 
// compare() 함수를 만들고 이 compare() 함수를 통해서 qsort()를 실행시키면, 
// 정렬이 되도록 qsort() 함수가 내부에 이미 구현이 돼 있다. 
// 
// qsort(arr, n, sizeof(int), compare); 이 규칙에 맞춰서 구현을 하면,
// 원하는 자료형의 정렬을 할 수 있다. 
// 
// 한 가지 연습 문제를 해 보자. 
// 위에서는 int로 구현이 돼 있는데 float 오름차순으로 바꾸어 보아라.
// <= 위 코드에서 int를 float으로 바꾸고 배열의 값도 float으로 바꿔 주면 된다. 