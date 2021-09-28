#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �͸� ����ü, Anonymous Unions
// 
// ����ü�� ���ϰ� ����� �� �ִ� �͸� ����ü�� ���ؼ� ���� ����.
// �͸� ����ü�� ������ �͸� ����ü�� ������ ����� ���� ����.
// �� ���ǿ��� �ٷ�� ������ �͸� ����ü�� �̿��ؼ� �� �� �����ϰ� �ٲ� ���ڴ�. 

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
// �� ���� �������� ������ ���� �����Ѵ�. 
	/*
	union data {
		struct personal_owner	po;
		struct company_owner	co;
	};
	<= �� ����ü ������ ���ְ�,

	struct car_data {
		char model[15];
		int status;				// 0 = personal, 1 = company 
		union data ownerinfo;	<= union data ����ü�� ���ְ� ���⿡ �ٷ� �ִ´�. 
	};
	*/
//  
// �׷���, �� �ڵ�� �Ʒ��� ���� �����ȴ�.	
//
	/*
	struct car_data {
		char model[15];
		int status;					// 0 = personal, 1 = company 
		union {
			struct personal_owner	po;
			struct company_owner	co;
		};
		 <= ����ü�� �̸��� ��������, ownerinfo�� ���ݴ�. �ڵ尡 �ξ� ����������. 
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
// <= ���� �ڵ��̴�. �� �ڵ忡�� ownerinfo�� �����Ѵ�. 
//    main() �Լ������� ownerinfo�� �����Ѵ�. 
// 
// �������ϰ� �����Ű�� �� ������ �ڵ�� �����ϰ� �۵��Ѵ�. 
// ����� ������ �����ϰ� �۵��ϴµ� �ڵ�� �ξ� ����������. 
// 
// ������ �͸� ����ü�� ���� ����ϴ�. �ξ� ���ϰ� ����� �� �ִ�. 
// 
// ������ �ϳ� �� ����.