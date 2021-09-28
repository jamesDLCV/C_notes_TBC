#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// union and struct
// ����ü�� ��� ����ϴ� ���� �����ұ�?
// 
// ����ü�� ����ü�� �Բ� ����ϴ� ���� ���� ����. 

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

// �ڵ����� ���� ������ ����ü�� �����. 
// 
	/*
	struct car_data {
		char model[15];
		 <= �ڵ��� ��ü�� ��
		int status;			// 0 = personal, 1 = company
		 <= ���� ��������, ȸ�� �������� �����Ϸ��� �Ѵ�.
			���� �����̸� 0, ȸ�� �����̸� 1�� ǥ�ø� �� �ְ� �ִ�.
		union data ownerinfo;
		 <= �̶� owner info�� union���� �����ϰ� �ִ�.
			data��� ���Ͽ� �ȿ��� ����ü�� �� �� �ִ�.
			���⼭���� ���� ��� �� �ִ�. �����ϰ� ������ ���� ���� ������ ���� ������ �� �ִ�.
	};
	<= �̷��� union�� ����ü�� �Բ� ����ϴ� ���� ���� ����ϴ� ������ ����̴�.
	<= ���� ������ �͸� ����ü�� ���� ���� ����ϴ� ����̴�.
	*/
//
	/*
	struct personal_owner { // ���� ������ ���
		char rrn1[7];		// Resident Registration Number
		char rrn2[8];		// ex: 830422-1185600
	};

	struct company_owner {  // ���� ������ ��� Company Registration Number
							// ex: 111-22-33333
		char crn1[4];		// 111
			<= 3�ڸ� + null character = 4
		char crn2[3];		// 22
			<= 2�ڸ� + null character = 3
		char crn3[6];       // 33333
			<= 5�ڸ� + null character = 6
	};

	union data {
		struct personal_owner po; <= ���� ������ �ֹε�� ��ȣ�� ������ �ִ�.
		struct company_owner co;  <= ���� ��� ��ȣ�� �� �ڸ��� ǥ�õȴ�.
	};
	<= data��� union�� ������ ���� ����ü�� ���� ���Ҵ�.
		�� ���� ���� ��Ÿ���̴�. ���� �����̸鼭 ȸ�� ������ ���� ���ٰ� �����Ѵ�.
	*/
//  
// �� ���� ������ ����ϴ� �Լ��� �������. 
// 
	/*
	void print_car(struct car_data car) { // �Ű������� struct car_data car�� ����.
		printf("-------------------------------------------\n");
		printf("Car model: %s\n", car.model);

		if (car.status == 0)	// 0 = personal, 1 = companry
			printf("Personal owner: %s-%s\n", car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);	   // �ֹε�� ��ȣ
		else
			printf("Company owner: %s-%s\n", car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);	   // ���ε�� ��ȣ
			<= ownerinfo�� personal info�� ��ó�� ����ϰ� �ִ�.
		printf("-------------------------------------------\n");
	}
	*/
//  <= �ʱ�ȭ�� �� ��� ����� ����� �ǵ��� �ؾ� �Ѵ�. 
//     ����ü�� �� ���ǿ��� ���� �� ��ó�� �߸� ����ϸ� ������ ���� ���� �� �ִ�. 
// 
// ����ü�� ���� \��ü�� �׷��� �������� �ʴ�. ����ü�� ������ �������� �ʴ�.
// ���α׷��� �ٷ�� �������� ������ ���������� �ִ�. 
// 
// ����ü�� ����ü�� ���� ����� �Ǹ鼭 ��� ����ü �ϳ��� 
// personal owner, company owner�� ���� �� ������ ����ü�� ��ó�� ���Ǵ� �߿��� ������ ���� �ô�.
// 
// ���α׷����� �� �� �̷��� �ϳ��� ������ �� ������ ��ó�� ����ϴ� ��Ŀ� ���ؼ� 
// ���߿� ��ü������ ������ �� �ξ� �ڼ��ϰ� �پ��� ������� ���� �� ���̴�. 
// 
// �̹� ���ǿ��� �ٷ� ���� ���������� �׷��� �������� �ʴ�. 
// �� ������ �� �α� �ٶ���. 
// 
// ����ü�� ����ü�� �Բ� ����ϴ� ���, ��� ���� �ְ� ����ϴ����� ���ؼ� ���� �ô�.