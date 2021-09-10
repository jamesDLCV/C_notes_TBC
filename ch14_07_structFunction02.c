#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FUNDLEN 50

// ����ü�� �Լ��� �����ϴ� ���
// �Լ��� parameters�� �����ͷ� �� ����. 

struct fortune {
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;
};

// ���ϱ⸦ �� �ִ� �Լ�
double sum(double* x, double* y);

int main() {

	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f.\n", sum(&my_fortune.bank_saving, &my_fortune.fund_invest));

	return 0;
}

double sum(const double* x, const double* y) {	//TODO: try pointers

	return *x + *y;

}

// double sum(double x, double y) �Լ��� parameters�� �����ͷ� �ٲ� ����.
// visual studio������ ���� �Ű������� �ٲ� �� �� �ִ�. 
// sum�� ���콺 hover over�� �� Quick Actions and Refactoring�� Ŭ�� > 
// Change Signature Ŭ�� > Modify > 
// double�� *�� �߰��Ͽ� �Ű������� �����ͷ� �ٲ۴�.
// 
// printf("Total : $%.2f.\n", sum(my_fortune.bank_saving, my_fortune.fund_invest));
// <= �̷��� �ϸ� Warning�� ���. 
//    ���ڿ� �����͸� �־� ��� �Ѵ�. 
//    �տ� & addressof operator�� �־� ��� �Ѵ�. 
// 
// �Լ� �ȿ��� return x + y; <= ��� ���. Indirection�� �� ��� �Ѵ�.
// 
// ������ ��Ű�� ����� �� ���´�. 
// Total : $12576.21.
//
// ������ ���� �ִ�. 
// sum() �Լ� �ȿ��� *x = 0.0f; *y = 0.0f; �� ���� ���� �ٲ� �� �� �ִ�. 
// ���α׷����� ���� ����� �ϴ� ����, �쿬�� �Ǽ��� �� ���� �ִ�. 
// <= �̷� �쿬�� ���� �Ǽ��� �̸� ������ �� ���� �Ѵ�.
// 
// double sum(const double* x, const double* y)
// <= �̷��� const�� ���� ���� �Ѵ�. �߻��� �� �ִ� �Ǽ��� �̸� �����ؾ� �Ѵ�. 
// 
// �Ʒ� �ڵ带 �ٽ� ����,
// printf("Total : $%.2f.\n", sum(my_fortune.bank_saving, my_fortune.fund_invest));
// <= my_fortune.bank_saving, my_fortune.fund_invest�� �־� �ִ� �� 
//    ���� ���ŷο� �� �ִ�. 
//    sum() �Լ����ٰ� my_fortune�� �־� �ְ�, 
//    bank_saving�� fund_invest�� ���ο��� ���� �ָ�, 
//    ����ϱ� �� �� ������ ������?
//    sum(my_fortune); �̷��� ó���� �� ������ �� ������ ���̴�.
// 
// �׷��� �Լ��� ���� ���� ����.