#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct my_data {
	int a;
	char c;
	float arr[2];
};

int main_example() {
	struct my_data d1 = { 1234, 'A', };

	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	printf("%f %f\n", d1.arr[0], d1.arr[1]);
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);

	struct my_data d2 = d1;

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	printf("%f %f\n", d2.arr[0], d2.arr[1]);
	printf("%lld %lld\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

	return 0;
}

// 좀 추상적인 구조체 my_data가 있다. 
//  float arr[2] <= float로 배열 arr[2]을 가지고 있다. 
//  다음 예제에서는 이것을 포인터로 바꿔서 동적 할당을 받을 것이다. 
// 
// 다음과 같이 초기화를 해 줄 수도 있지만,
// struct my_data d1 = { 1234, 'A', {1.1f, 2.2f} };
// 
// 아래와 같이 
// struct my_data d1 = { 1234, 'A', };
// <= float arr[2]에 대한 초기화는 아래와 같이 따로 떼어서 해 줄 수도 있다. 
// 
// d1.arr[0] = 1.1f;
// d1.arr[1] = 2.2f;
//
// 그다음 d1.a, d1.c, 그리고 (long long)d1.arr 주소를 출력해 본다.  
	/*
	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	printf("%f %f\n", d1.arr[0], d1.arr[1]);
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);
	*/
// 그리고 대입한 값과 주소도 출력해 본다. 
// 
// struct my_data d2 = d1;
// <= 대입 연산자로 구조체를 대입한다. 
//    구조체를 대입하면 내부적으로 복사를 해 준다. 아주 편리하다.
//    d2에 d1을 대입해 준다.
//    d1이 가지고 있는 값들을 d2에 복사를 하는 것이다. 
//    
// 만약 대입 연산자가 정의가 안 돼 있다면, 
// struct my_data d2;
// d2.a = d1.a;
// d2.c = d1.c;
// d2.arr[0] = d1.arr[0];
// d2.arr[1] = d1.arr[1];
// <= 이렇게 일일이 멤버를 대입해 줘야 한다. 
//  
// 출력을 해 보면, 
// printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
// printf("%f %f\n", d2.arr[0], d2.arr[1]);
// printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);
// 
// d1.arr, d2.arr 
// <= array의 이름은 주소처럼(포인터처럼) 사용할 수 있다.
//  
// d1과 d2의 주소는 서로 다르다.
// 대입을 해 준다고 해서 주소가 동일해지는 것은 아니다.
// 메모리에 저장돼 있는 값들만 복사가 된다. 
// d1과 d2는 다른 메모리를 가지고 있다. 
// 
// printf("%f %f\n", d1.arr[0], d1.arr[1]); 과
// printf("%f %f\n", d2.arr[0], d2.arr[1]); 의 값은 
// <= 동일한 값이 출력된다. 
//    배열이 가지고 있는 값을 복사를 해 줬기 때문이다. 
// 
// 실행해 보면, 
// 1234 A 1036424771696
// 1.100000 2.200000
// 1036424771696 1036424771700	<= 4 바이트 차이가 난다. float가 4 바이트이므로.
//
// 1234 A 1036424771744
// 1.100000 2.200000
// 1036424771744 1036424771748	<= 4 바이트 차이가 난다. 배열이다. 
// 
// 아주 옛날 오래된 컴파일러를 사용하면,
// struct my_data d2 = d1; 이 안 될 수도 있다. 
// <= 예전에는 멤버를 하나 하나 일일이 복사해 줘야 했다. 
// 
// 조금 다른 예제를 살펴 보자.