#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FUNDLEN 50

// ����ü�� �Լ��� �����ϴ� ���
// 
// sum(my_fortune);���� ó���ϵ��� �Լ��� �ٲ� ����.

struct fortune {
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;
};

// ���ϱ⸦ �� �ִ� �Լ�
double sum(struct fortune my_fortune);

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
		sum(my_fortune));

	struct fortune my_fortune2;
	my_fortune2 = my_fortune;

	return 0;
}

double sum(struct fortune my_fortune) {	// sum(struct fortune mf)�� �ص� �ȴ�.

	return my_fortune.bank_saving + my_fortune.fund_invest;

}

// double sum(double* x, double* y);��
// double sum(struct fortune my_fortune);�� �ٲ۴�.
// <= �Ű������� struct fortune my_fortune�� �ٲپ���.
// 
// double sum(struct fortune my_fortune)�� ���Ǻθ� ������ �ش�.
// return *x + *y;��
// return my_fortune.bank_saving + my_fortune.fund_invest;�� �ٲ۴�.
// 
// ������ ���� �Ȱ��� ���������� �۵��ȴ�. 
// 
// ����ü�� ������ �ϸ�, ���簡 �ȴ�. 
// struct fortune my_fortune2;
// my_fortune2 = my_fortune;
// <= �̷��� �ϸ�, my_fortuen�� ������� ��� my_fortune2�� ���簡 �ȴ�.
// 
// �׷��Ƿ�, ����ü ���� my_fortune�� sum() �Լ��� ���ڷ� �־� �ָ�,
// double sum(struct fortune my_fortune)���� value�� �޴´�.
// ��, my_fortune�� value (������� value) ������ ���� ���簡 �ȴ�.
// 
// sum()�� argument�� �־��� my_fortune�� 
// �޴� ���� double sum(struct fortune my_fortune) parameter���ٰ� ���縦 �Ѵ�.
// 
// return my_fortune.bank_saving + my_fortune.fund_invest;
// <= �׷��� my_fortune.bank_saving, my_fortune.fund_invest�� �ȴ�.
// 
// �̶� ������ ���� ����ü�� �ʱ�ȭ�� �ִ� struct fortune my_fortune������
// my_fortune �ּ��ϰ�, 
// double sum(struct fortune my_fortune) para
// meter�� my_fortune�� �ּҴ�,
// ���� �ٸ���.
// 
// ����Ÿ� ����ؼ� �ּҰ� �ٸ��� Ȯ���� ����. <= (7:35) ����
// �̸��� my_fortune���� ���������� �� �� �޸𸮴� �ٸ���. 
// ���빰�� ���� (���縦 �ߴ�) ������ �ּҴ� �ٸ���.
// 
	/*
	double sum(struct fortune my_fortune) {	//TODO: try pointers

		return my_fortune.bank_saving + my_fortune.fund_invest;

	}
	*/
// �� �Լ����� �Ű������� ����� �ʵ��� �Ʒ��� ���� ������ �� ���� �ִ�.
	/*
	double sum(struct fortune mf) {	//TODO: try pointers

		return mf.bank_saving + mf.fund_invest;

	}
	*/
// ������ �ᱣ���� ��µȴ�.
// 
// �̶� ���縦 �ϱ� ������, �޸𸮸� �� �����ϰ� �ȴ�. 
// �Լ��� stack�� fortune mf �޸𸮸� �ϳ� �� ����ϴ� ���ε�, 
// ���������� ũ�� �δ��� ���� ���� ���� �ִ�. 
// 
// �װͺ��� �� �δ��� �Ǵ� ��������, ������ �� �ִٴ� ���̴�. 
// �׻� ���� ���� �ƴ�����, struct fortune�� ����� ���ϰ� ���� ��쿡��,
// ������ �� �ð��� �ɸ� �� �ִ�. 
// ���� ��� FUNDLEN array�� ũ�Ⱑ 5õ ���� �Ѵ´ٸ� ���縦 �� ��� ������ �� �� �ִ�.
// 
// �� ���� �� �˾� �־� �� ����, (�� ���ǿ��� �Ұ��ߴ�)
// ����ü�� ����� float* arr;�� �ְ�,
// 
// my_fortune.arr = (float*)malloc(sizeof(float)*100000);
// �̷��� ��û ���� �����͸� ������ �ִٰ� ����. 
// 
// �׷��� double sum(struct fortune mf);���� 
// mf�� ���縦 �ؿ� ��, my_fortune.arr�� �ּҸ� ������ �´�.
// (float*)malloc(sizeof(float)*100000); �� �����͸� ��°�� �����ؿ��� �ʴ´�.
// 
// �׷��Ƿ� 
// double sum(struct fortune mf)���ٴ�
// double sum(struct fortune *mf) �̷��� �����͸� ���� ����. 