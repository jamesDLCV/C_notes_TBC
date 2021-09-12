#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define FUNDLEN 50

// 구조체를 함수로 전달하는 방법
// 
// sum(my_fortune);으로 처리하도록 함수를 바꿔 보자.

struct fortune {
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;
};

// 더하기를 해 주는 함수
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

double sum(struct fortune my_fortune) {	// sum(struct fortune mf)로 해도 된다.

	return my_fortune.bank_saving + my_fortune.fund_invest;

}

// double sum(double* x, double* y);룰
// double sum(struct fortune my_fortune);로 바꾼다.
// <= 매개변수를 struct fortune my_fortune로 바꾸었다.
// 
// double sum(struct fortune my_fortune)의 정의부를 수정해 준다.
// return *x + *y;를
// return my_fortune.bank_saving + my_fortune.fund_invest;로 바꾼다.
// 
// 실행해 보면 똑같이 정상적으로 작동된다. 
// 
// 구조체도 대입을 하면, 복사가 된다. 
// struct fortune my_fortune2;
// my_fortune2 = my_fortune;
// <= 이렇게 하면, my_fortuen의 멤법들이 모두 my_fortune2로 복사가 된다.
// 
// 그러므로, 구조체 변수 my_fortune을 sum() 함수의 인자로 넣어 주면,
// double sum(struct fortune my_fortune)에서 value로 받는다.
// 즉, my_fortune의 value (멤버들의 value) 값들이 전부 복사가 된다.
// 
// sum()의 argument로 넣어준 my_fortune을 
// 받는 쪽의 double sum(struct fortune my_fortune) parameter에다가 복사를 한다.
// 
// return my_fortune.bank_saving + my_fortune.fund_invest;
// <= 그래서 my_fortune.bank_saving, my_fortune.fund_invest가 된다.
// 
// 이때 주의할 점은 구조체를 초기화해 주는 struct fortune my_fortune에서의
// my_fortune 주소하고, 
// double sum(struct fortune my_fortune) para
// meter인 my_fortune의 주소는,
// 서로 다르다.
// 
// 디버거를 사용해서 주소가 다른지 확인해 보자. <= (7:35) 참조
// 이름이 my_fortune으로 동일하지만 이 두 메모리는 다른다. 
// 내용물은 같다 (복사를 했다) 하지만 주소는 다르다.
// 
	/*
	double sum(struct fortune my_fortune) {	//TODO: try pointers

		return my_fortune.bank_saving + my_fortune.fund_invest;

	}
	*/
// 이 함수에서 매개변수를 헤깔리지 않도록 아래와 같이 수정해 줄 수도 있다.
	/*
	double sum(struct fortune mf) {	//TODO: try pointers

		return mf.bank_saving + mf.fund_invest;

	}
	*/
// 동일한 결괏값이 출력된다.
// 
// 이때 복사를 하기 때문에, 메모리를 더 차지하게 된다. 
// 함수가 stack에 fortune mf 메모리를 하나 더 사용하는 것인데, 
// 현실적으로 크게 부담이 되지 않을 수도 있다. 
// 
// 그것보다 더 부담이 되는 문제점은, 느려질 수 있다는 것이다. 
// 항상 느린 것은 아니지만, struct fortune의 멤버가 어마어마하게 많을 경우에는,
// 복사할 때 시간이 걸릴 수 있다. 
// 예를 들어 FUNDLEN array의 크기가 5천 개가 넘는다면 복사를 할 경우 문제가 될 수 있다.
// 
// 한 가지 더 알아 둬야 할 것은, (앞 강의에서 소개했다)
// 구조체의 멤버로 float* arr;가 있고,
// 
// my_fortune.arr = (float*)malloc(sizeof(float)*100000);
// 이렇게 엄청 많은 데이터를 가지고 있다고 하자. 
// 
// 그러면 double sum(struct fortune mf);에서 
// mf가 복사를 해올 때, my_fortune.arr의 주소만 복사해 온다.
// (float*)malloc(sizeof(float)*100000); 이 데이터를 통째로 복사해오지 않는다.
// 
// 그러므로 
// double sum(struct fortune mf)보다는
// double sum(struct fortune *mf) 이렇게 포인터를 많이 쓴다. 