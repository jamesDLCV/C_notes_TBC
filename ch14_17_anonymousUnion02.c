#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ������ �ϳ� �� ����.
//
// Vector2D��� ����ü�� �ϳ� �� �����Ϸ��� �Ѵ�. 

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

	// �迭�� ����ؼ� �����ϴ� ���� �� ȿ������ ���� �ִ�. 
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
// <= Vector2D��� ����ü�� �����Ϸ��� �Ѵ�.
//    vector��� �ϸ� x, yó�� ����� ���� �ְ�, i, jó�� ����� ���� �ִ�. 
//    �� arr[2] �迭ó�� ����� ���� �ִ�. 
//    �̰��� ����ü�� �����Ѵ�. 
// 
// typedef struct Vector2D vec2;
// <= vec2�� �ٿ��� ���� �ʹ�. �̸��� �ٿ� �ִϱ� ���ϴ�. 
//    ���� ���� ����ü�� ��쿡�� �̸��� �ٿ��� ���� ���ϴ�. 
// 
// vec2 v = { 3.14, 2.99 };
// <= �ʱ�ȭ�� �� �ش�. 
// 
// printf("%.2f %.2f\n", v.x, v.y);				<= 3.14 2.99
// printf("%.2f %.2f\n", v.i, v.j);				<= 3.14 2.99
// printf("%.2f %.2f\n", v.arr[0], v.arr[1]);	<= 3.14 2.99
// <= x, y�� �ص� i, j�� �ص�, arr[] �迭�� �ص� ����� �ȴ�. 
// �Ʒ��� ���� for������ �迭�� ����� ���� �ִ�. 
	/*
	// �迭�� ����ؼ� �����ϴ� ���� �� ȿ������ ���� �ִ�. 
	for (int d = 0; d < 2; ++d)
		printf("%.2f ", v.arr[d]);

	return 0;
	*/
//  <= ���� �ִ� ���� �� �ϳ��̴�. 
// 
// �͸� ����ü�� ������ �� ���� ����� ���� �ô�. 