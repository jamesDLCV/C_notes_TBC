#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FUNDLEN 50

// ����ü�� �Լ��� �����ϴ� ���

struct fortune {
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;
};

// ���ϱ⸦ �� �ִ� �Լ�
double sum(double, double);

int main() {

	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f.\n", sum(my_fortune.bank_saving, my_fortune.fund_invest));

	return 0;
}

double sum(double x, double y) {	//TODO: try pointers

	return x + y;

}

// ��� fortune�� ���� ����ü�� �ϳ� �������. 
// bank�� ������ �ְ�, �ݵ忡 ������ �ݾ��� �ִ�. 
// bank_saving�ϰ� fund_invest�� ������ �� �󸶰� �������� ����� ����.
// 
// double sum(double, double); �Լ��� ���ؼ� ���ϱ⸦ �Ѵ�. 
// ��������� ����� ���� ����. 
// 
// printf("Total : $%.2f.\n", sum(my_fortune.bank_saving, my_fortune.fund_invest));
// <= sum() �̶�� �Լ����� ���� ���� ������ �ְ� �ִ�. 
// 
// sum() �Լ��� double �� ���� parameters�� ������ �ִ�. 
// 
// my_fortune.bank_saving�� my_fortune.fund_invest�� arguments�� �־� �ָ�,
// sum()�� parameters�� �����ؼ� ����� �ȴ�. 
// �׷��� x + y�� ������ �ǰ� �ǰ�, �� ����� printf() �Լ��� ���� ��µȴ�. 
// 
// �տ��� ����ü�� �����͸� �����. 
// arguments�� �����ͷ� �Ѱ� �ָ� ��� �ϴ� ������ �� �� �ִ�. 
// 
// �� �ڵ带 ������ parameters�� �ٲ� ����.