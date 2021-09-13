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
double sum(struct fortune* mf);	// <= ����!

int main() {

	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	//printf("Total : $%.2f.\n", sum(&my_fortune.bank_saving, &my_fortune.fund_invest));

	printf("Total : $%.2f.\n",
		// sum(&my_fortune.bank_saving, &my_fortune.fund_invest)
		sum(&my_fortune));	// <= ����! �ּҸ� �־� ��� �Ѵ�.

	struct fortune my_fortune2;
	my_fortune2 = my_fortune;

	return 0;
}

double sum(const struct fortune* mf) { // <= ����!

	// dot operator�� arrow operator�� �ٲ� �ش�.
	return mf->bank_saving + mf->fund_invest;

}

// arrow operator�� indirect member access operator�̴�. 
// 
// double sum(struct fortune* my_fortune) �Լ��� ��ǥ��, 
// mf�� �ִ� ��� �� ���� ���� ���ؼ�, ���� ���� ������ �ִ� ������, 
// mf�� ������� ������ �ִ� ���� �ٲٷ��� �ϴ� ���� �ƴϴ�. 
// �׷��Ƿ� const�� �ٿ� �ִ� ���� ���ڴ�. 
// <= double sum(const struct fortune* mf)�� ���� const�� �ٿ� �ش�.
// 
// ����ü�� �Լ��� ������ �� ��, 
// ����ü�� ����� �ϳ� �ϳ� ������ ���� �ְ�, 
// ����ü ������� �����͸� ������ �� ���� �ִ�. 
// 
// �����͸� ������ �� ���� ��������, 
// �� �����͸� ���� �Լ���, �� �����Ͱ� ����Ű�� �ִ� �޸� �ּҿ� ����� �ִ� ����
// ������ ������ �ϱ⸸ �ϴ� ����, �ƴϸ� �ٲٱ⵵ �� �ǵ��� �ִ� ������ �ľ��ؼ�,
// ���� �Լ��� ������ �ִ� ����� (�Լ��� �ؾ� �ϴ� ����)
// ���� �ٲٴ� ���� �ƴ϶�� �տ��ٰ� const�� �ٿ� �ִ� ���� ����. 
// 
// ����ü�� �Լ��� ������ ����, 
// ����ü�� ������ ���� ���� ����, call by value ���� ���� ȣ���� �ϰ� �Ǹ�, 
// ����ü�� �ִ� ������ �� �� �����ؼ�, �ٸ� �޸𸮿� �纻�� �����ϴ� ���̱� ������, 
// �޸𸮵� �� ������ �� �ְ�, �ð��� ���� �ɸ� �� �ִ�. 
// 
// �׷��� C-style ���α׷��ֿ��� ��ȣ�ϴ� ����� ���� ���� �����͸� Ȱ���ϴ� ���̴�.
// 
// �����͸� �Ѱ� �� ��, ����ü�� �����͵� ���������� 
// �� �Լ��� ����ü�� ������� ���� �ٲٷ��� �ǵ��� ������ ���� �ʴٸ�, 
// �տ� const�� �ٿ��� �� �ٲٵ��� ���� ��� �Ѵ�. 
// 
// �Լ��� ����ü�� ������ �ִ� ����� ���ؼ� ���� �ô�.