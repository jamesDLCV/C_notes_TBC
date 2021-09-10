#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FUNDLEN 50

// 구조체를 함수로 전달하는 방법
// 함수의 parameters를 포인터로 해 보자. 

struct fortune {
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;
};

// 더하기를 해 주는 함수
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

// double sum(double x, double y) 함수의 parameters를 포인터로 바꿔 보자.
// visual studio에서는 쉽게 매개변수를 바꿔 줄 수 있다. 
// sum에 마우스 hover over한 후 Quick Actions and Refactoring을 클릭 > 
// Change Signature 클릭 > Modify > 
// double에 *를 추가하여 매개변수를 포인터로 바꾼다.
// 
// printf("Total : $%.2f.\n", sum(my_fortune.bank_saving, my_fortune.fund_invest));
// <= 이렇게 하면 Warning이 뜬다. 
//    인자에 포인터를 넣어 줘야 한다. 
//    앞에 & addressof operator를 넣어 줘야 한다. 
// 
// 함수 안에도 return x + y; <= 경고가 뜬다. Indirection을 해 줘야 한다.
// 
// 실행을 시키면 결과는 잘 나온다. 
// Total : $12576.21.
//
// 주의할 점이 있다. 
// sum() 함수 안에서 *x = 0.0f; *y = 0.0f; 와 같이 값을 바꿔 줄 수 있다. 
// 프로그래밍을 여러 사람이 하다 보면, 우연히 실수를 할 수도 있다. 
// <= 이런 우연에 의한 실수는 미리 방지를 해 놔야 한다.
// 
// double sum(const double* x, const double* y)
// <= 이렇게 const로 막아 놔야 한다. 발생할 수 있는 실수를 미리 방지해야 한다. 
// 
// 아래 코드를 다시 보자,
// printf("Total : $%.2f.\n", sum(my_fortune.bank_saving, my_fortune.fund_invest));
// <= my_fortune.bank_saving, my_fortune.fund_invest를 넣어 주는 게 
//    조금 번거로울 수 있다. 
//    sum() 함수에다가 my_fortune만 넣어 주고, 
//    bank_saving과 fund_invest를 내부에서 더해 주면, 
//    사용하기 좀 더 편하지 않을까?
//    sum(my_fortune); 이렇게 처리할 수 있으면 더 간단할 것이다.
// 
// 그래서 함수를 조금 고쳐 보자.