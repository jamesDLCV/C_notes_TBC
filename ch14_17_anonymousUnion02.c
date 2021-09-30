#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 예제를 하나 더 보자.
//
// Vector2D라는 구조체를 하나 더 선언하려고 한다. 

struct personal_owner {
	char rrn1[7];	// Resident Registration Number
	char rrn2[8];	// ex: 830422-1185600
};

struct company_owner {
	char crn1[4];	// Company Registration Number
	char crn2[3];	// ex: 111-22-33333
	char crn3[6];
};

struct car_data {
	char model[15];
	int status;			// 0 = personal, 1 = company 
	union {
		struct personal_owner	po;
		struct company_owner	co;
	};
};

void print_car(struct car_data car) {
	printf("------------------------------------\n");
	printf("Car model: %s\n", car.model);

	if (car.status == 0)	// 0 = personal, 1 = companry
		printf("Personal owner: %s-%s\n", car.po.rrn1, car.po.rrn2);
	else
		printf("Company owner: %s-%s-%s\n", car.co.crn1, car.co.crn2, car.co.crn3);
	printf("------------------------------------\n");
}

int main() {
	struct car_data my_car = { .model = "Avante", .status = 0, .po = {"830422", "1185600"} };
	struct car_data company_car = { .model = "Sonata", .status = 1, .co = {"111", "22", "33333"} };

	print_car(my_car);
	print_car(company_car);

	// One more example
	struct Vector2D {
		union {
			struct { double x, y; };
			struct { double i, j; };
			struct { double arr[2]; };
		};
	};

	typedef struct Vector2D vec2;

	vec2 v = { 3.14, 2.99 };
	printf("%.2f %.2f\n", v.x, v.y);
	printf("%.2f %.2f\n", v.i, v.j);
	printf("%.2f %.2f\n", v.arr[0], v.arr[1]);

	printf("\n");

	// 배열을 사용해서 접근하는 것이 더 효율적일 때도 있다. 
	for (int d = 0; d < 2; ++d)
		printf("%.2f ", v.arr[d]);

	return 0;
}

// 
	/*
	// One more example
	struct Vector2D {
		union {
			struct { double x, y; };
			struct { double i, j; };
			struct { double arr[2]; };
		};
	};
	*/
// <= Vector2D라는 구조체를 선언하려고 한다.
//    vector라고 하면 x, y처럼 사용할 수도 있고, i, j처럼 사용할 수도 있다. 
//    또 arr[2] 배열처럼 사용할 수도 있다. 
//    이것을 공용체로 선언한다. 
// 
// typedef struct Vector2D vec2;
// <= vec2로 줄여서 쓰고 싶다. 이름을 줄여 주니까 편하다. 
//    많이 쓰는 구조체일 경우에는 이름을 줄여서 쓰면 편하다. 
// 
// vec2 v = { 3.14, 2.99 };
// <= 초기화를 해 준다. 
// 
// printf("%.2f %.2f\n", v.x, v.y);				<= 3.14 2.99
// printf("%.2f %.2f\n", v.i, v.j);				<= 3.14 2.99
// printf("%.2f %.2f\n", v.arr[0], v.arr[1]);	<= 3.14 2.99
// <= x, y로 해도 i, j로 해도, arr[] 배열로 해도 출력이 된다. 
// 아래와 같이 for문으로 배열을 출력할 수도 있다. 
	/*
	// 배열을 사용해서 접근하는 것이 더 효율적일 때도 있다. 
	for (int d = 0; d < 2; ++d)
		printf("%.2f ", v.arr[d]);

	return 0;
	*/
//  <= 쓸모 있는 문법 중 하나이다. 
// 
// 익명 공용체의 유용한 몇 가지 용법을 살펴 봤다. 