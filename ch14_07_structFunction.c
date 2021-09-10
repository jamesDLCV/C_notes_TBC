#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FUNDLEN 50

// 구조체를 함수로 전달하는 방법

struct fortune {
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;
};

// 더하기를 해 주는 함수
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

// 재산 fortune에 대한 구조체를 하나 만들었다. 
// bank에 저축이 있고, 펀드에 투자한 금액이 있다. 
// bank_saving하고 fund_invest를 합했을 때 얼마가 나오는지 계산해 보자.
// 
// double sum(double, double); 함수를 통해서 더하기를 한다. 
// 여기까지는 어려운 것이 없다. 
// 
// printf("Total : $%.2f.\n", sum(my_fortune.bank_saving, my_fortune.fund_invest));
// <= sum() 이라는 함수에서 더한 값을 리턴해 주고 있다. 
// 
// sum() 함수는 double 두 개를 parameters로 가지고 있다. 
// 
// my_fortune.bank_saving와 my_fortune.fund_invest를 arguments로 넣어 주면,
// sum()의 parameters로 복사해서 들어고게 된다. 
// 그러면 x + y가 리턴이 되게 되고, 그 결과로 printf() 함수로 합이 출력된다. 
// 
// 앞에서 구조체와 포인터를 배웠다. 
// arguments를 포인터로 넘겨 주면 어떨까 하는 생각을 할 수 있다. 
// 
// 이 코드를 포인터 parameters로 바꿔 보자.