#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 익명 공용체, Anonymous Unions
// 
// 공용체를 편리하게 사용할 수 있는 익명 공용체에 대해서 살펴 본다.
// 익명 공용체의 문법은 익명 구조체의 문법과 비슷한 면이 많다.
// 앞 강의에서 다뤘던 예제를 익명 공용체를 이용해서 좀 더 간단하게 바꿔 보겠다. 

/*
	Unions And Structres
*/

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

	return 0;
}

//
// 앞 강의 예제에서 다음과 같이 변경한다. 
	/*
	union data {
		struct personal_owner	po;
		struct company_owner	co;
	};
	<= 이 공용체 선언을 없애고,

	struct car_data {
		char model[15];
		int status;				// 0 = personal, 1 = company 
		union data ownerinfo;	<= union data 공용체를 없애고 여기에 바로 넣는다. 
	};
	*/
//  
// 그러면, 위 코드는 아래와 같이 수정된다.	
//
	/*
	struct car_data {
		char model[15];
		int status;					// 0 = personal, 1 = company 
		union {
			struct personal_owner	po;
			struct company_owner	co;
		};
		 <= 공용체의 이름이 없어졌고, ownerinfo도 없앴다. 코드가 훨씬 간결해졌다. 
	};
	*/
//
	/*
	void print_car(struct car_data car) {
		printf("------------------------------------\n");
		printf("Car model: %s\n", car.model);

		if (car.status == 0)	// 0 = personal, 1 = companry
			printf("Personal owner: %s-%s\n", car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);
		else
			printf("Company owner: %s-%s-%s\n", car.ownerinfo.co.crn1, car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);
		printf("------------------------------------\n");
	}
	*/
// <= 이전 코드이다. 이 코드에서 ownerinfo를 삭제한다. 
//    main() 함수에서도 ownerinfo를 삭제한다. 
// 
// 컴파일하고 실행시키면 앞 강좌의 코드와 동일하게 작동한다. 
// 기능은 완전히 동일하게 작동하는데 코드는 훨씬 간결해졌다. 
// 
// 문법도 익명 구조체와 거의 비슷하다. 훨씬 편하게 사용할 수 있다. 
// 
// 예제를 하나 더 보자.