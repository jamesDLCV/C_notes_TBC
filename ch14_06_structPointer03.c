#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//

struct my_data {
	int a;
	char c;
	float* arr;		// 포인터이다
};

int main() {

	struct my_data d1 = { 1234, 'A', NULL };

	d1.arr = (float*)malloc(sizeof(float) * 2);	// 동적 할당으로 메모리를 받는다.
	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	printf("%f %f\n", d1.arr[0], d1.arr[1]);
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);

	struct my_data d2 = d1;

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	printf("%f %f\n", d2.arr[0], d2.arr[1]);
	printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

	return 0;
}

// float* arr; arr를 포인터로 선언해 주고, 
// 동적 할당으로 메모리를 받는 거 외에는 모두 이전 예제와 동일하다.
// 
// 동적 할당으로 받고 배열처럼 사용하고 있다. 
// 
// array의 이름은 주소처럼(포인터처럼) 사용할 수 있다.
// d1.arr <= printf() 하면 주솟값이 출력된다. 
// 
// d1.arr[0], d1.arr[1]과
// d2.arr[0], d2.arr[1]은 동일한 값을 갖는다. 
// 
// 여기에서는 주솟값이 모두 동일하다. 
// <= 동적 할당으로 받아온 메모리의 주솟값을 복사하고 있다. 
//    struct my_data d2 = d1;에서 float* arr에 있는 주솟값을 복사한다.
// 
// struct my_data d2 = d1;
// <= 결과적으로 d1과 d2가 메모리를 공유하고 있다. 
//    d1.arr과 d2.arr가 가지고 있는 주솟값이 동일하다. 
//    같은 공간에 있는 메모리를 가리키고 있다. 
// 
// 이 성질을 주의 깊게 잘 기억을 해 둬라.
// 이 개념은 어떤 언어를 공부하든지 앞으로 할 수 있는 많은 실수를 예방해 줄 수 있다.
// 
// 구조체와 포인터와 관련해서 주의해야 할 사항 몇 가지를 살펴 봤다. 