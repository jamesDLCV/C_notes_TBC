#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// union and struct
// 공용체를 어디에 사용하는 것이 유용할까?
// 
// 공용체를 구조체와 함께 사용하는 예를 살펴 보자. 

/*
	Unions And Structures
*/

struct personal_owner {
	char rrn1[7];		// Resident Registration Number
	char rrn2[8];		// ex: 830422-1185600
};

struct company_owner {
	char crn1[4];		// Company Registration Number
	char crn2[3];		// ex: 111-22-33333
	char crn3[6];
};

union data {
	struct personal_owner po;
	struct company_owner co;
};

struct car_data {
	char model[15];
	int status;			/* 0 = personal, 1 = company */
	union data ownerinfo;
};

void print_car(struct car_data car) {
	printf("------------------------------------\n");
	printf("Car model: %s\n", car.model);

	if (car.status == 0)	// 0 = personal, 1 = companry
		printf("Personal owner: %s-%s\n", car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);
	else
		printf("Company owner: %s-%s-%s\n", car.ownerinfo.co.crn1, car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);
	printf("------------------------------------\n");
}

int main() {
	struct car_data my_car = { .model = "Avante", .status = 0, .ownerinfo.po = {"830422", "1185600"} };
	struct car_data company_car = { .model = "Sonata", .status = 1, .ownerinfo.co = {"111", "22", "33333"} };

	print_car(my_car);
	print_car(company_car);

	return 0;
}

// 자동차에 대한 정보를 구조체로 만든다. 
// 
	/*
	struct car_data {
		char model[15];
		 <= 자동차 자체의 모델
		int status;			// 0 = personal, 1 = company
		 <= 개인 소유인지, 회사 소유인지 구분하려고 한다.
			개인 소유이면 0, 회사 소유이면 1로 표시를 해 주고 있다.
		union data ownerinfo;
		 <= 이때 owner info를 union으로 선언하고 있다.
			data라는 유니온 안에는 구조체가 두 개 있다.
			여기서부터 조금 헤깔릴 수 있다. 차분하게 예제를 보고 직접 구현해 보면 이해할 수 있다.
	};
	<= 이렇게 union을 구조체와 함께 사용하는 것이 많이 사용하는 유용한 용법이다.
	<= 다음 강좌의 익명 공용체가 가장 많이 사용하는 용법이다.
	*/
//
	/*
	struct personal_owner { // 개인 소유일 경우
		char rrn1[7];		// Resident Registration Number
		char rrn2[8];		// ex: 830422-1185600
	};

	struct company_owner {  // 법인 소유일 경우 Company Registration Number
							// ex: 111-22-33333
		char crn1[4];		// 111
			<= 3자리 + null character = 4
		char crn2[3];		// 22
			<= 2자리 + null character = 3
		char crn3[6];       // 33333
			<= 5자리 + null character = 6
	};

	union data {
		struct personal_owner po; <= 개인 정보를 주민등록 번호로 가지고 있다.
		struct company_owner co;  <= 법인 등록 번호는 세 자리로 표시된다.
	};
	<= data라는 union에 위에서 만든 구조체를 묶어 놓았다.
		두 개는 서로 배타적이다. 개인 소유이면서 회사 소유인 경우는 없다고 전제한다.
	*/
//  
// 이 차의 정보를 출력하는 함수를 만들었다. 
// 
	/*
	void print_car(struct car_data car) { // 매개변수로 struct car_data car만 들어간다.
		printf("-------------------------------------------\n");
		printf("Car model: %s\n", car.model);

		if (car.status == 0)	// 0 = personal, 1 = companry
			printf("Personal owner: %s-%s\n", car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);	   // 주민등록 번호
		else
			printf("Company owner: %s-%s\n", car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);	   // 법인등록 번호
			<= ownerinfo가 personal info인 것처럼 사용하고 있다.
		printf("-------------------------------------------\n");
	}
	*/
//  <= 초기화해 준 대로 제대로 출력이 되도록 해야 한다. 
//     공용체는 앞 강의에서 살펴 본 것처럼 잘못 사용하면 엉뚱한 값이 나올 수 있다. 
// 
// 공용체의 문법 \자체는 그렇게 복잡하지 않다. 구조체의 문법도 복잡하지 않다.
// 프로그램이 다루는 데이터의 구조가 복잡해지고 있다. 
// 
// 공용체와 구조체가 같이 사용이 되면서 어떠한 구조체 하나가 
// personal owner, company owner와 같이 두 가지의 구조체인 것처럼 사용되는 중요한 예제를 살펴 봤다.
// 
// 프로그래밍을 할 때 이렇게 하나를 가지고 두 가지인 것처럼 사용하는 방식에 대해서 
// 나중에 객체지향을 공부할 때 훨씬 자세하고 다양한 기법들을 배우게 될 것이다. 
// 
// 이번 강의에서 다룬 것은 문법적으로 그렇게 복잡하지 않다. 
// 잘 정리를 해 두기 바란다. 
// 
// 공용체와 구조체를 함께 사용하는 경우, 어떻게 쓸모 있게 사용하는지에 대해서 살펴 봤다.