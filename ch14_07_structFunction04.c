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
double sum(struct fortune* mf);	// <= 수정!

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
		sum(&my_fortune));	// <= 수정! 주소를 넣어 줘야 한다.

	struct fortune my_fortune2;
	my_fortune2 = my_fortune;

	return 0;
}

double sum(const struct fortune* mf) { // <= 수정!

	// dot operator를 arrow operator로 바꿔 준다.
	return mf->bank_saving + mf->fund_invest;

}

// arrow operator는 indirect member access operator이다. 
// 
// double sum(struct fortune* my_fortune) 함수의 목표는, 
// mf에 있는 멤버 두 개의 값을 합해서, 더한 값을 리턴해 주는 것이지, 
// mf의 멤버들이 가지고 있는 값을 바꾸려고 하는 것은 아니다. 
// 그러므로 const를 붙여 주는 것이 좋겠다. 
// <= double sum(const struct fortune* mf)와 같이 const를 붙여 준다.
// 
// 구조체를 함수에 전달해 줄 때, 
// 구조체의 멤버를 하나 하나 전달할 수도 있고, 
// 구조체 멤버들의 포인터를 전달해 줄 수도 있다. 
// 
// 포인터를 전달해 줄 때의 주의점은, 
// 그 포인터를 받은 함수가, 그 포인터가 가리키고 있는 메모리 주소에 저장돼 있는 값을
// 가져다 쓰려고 하기만 하는 건지, 아니면 바꾸기도 할 의도가 있는 건지를 파악해서,
// 만약 함수가 가지고 있는 기능이 (함수가 해야 하는 일이)
// 값을 바꾸는 것이 아니라면 앞에다가 const를 붙여 주는 것이 좋다. 
// 
// 구조체를 함수에 전달할 때도, 
// 구조체의 데이터 양이 많을 때는, call by value 값에 의한 호출을 하게 되면, 
// 구조체에 있는 내용을 한 번 복사해서, 다른 메모리에 사본을 저장하는 것이기 때문에, 
// 메모리도 더 차지할 수 있고, 시간도 많이 걸릴 수 있다. 
// 
// 그래서 C-style 프로그래밍에서 선호하는 방식은 위와 같이 포인터를 활용하는 것이다.
// 
// 포인터를 넘겨 줄 때, 구조체의 포인터도 마찬가지로 
// 이 함수가 구조체의 멤버들의 값을 바꾸려는 의도를 가지고 있지 않다면, 
// 앞에 const를 붙여서 못 바꾸도록 막아 줘야 한다. 
// 
// 함수에 구조체를 전달해 주는 방법에 대해서 살펴 봤다.