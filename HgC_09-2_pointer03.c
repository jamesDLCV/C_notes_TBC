#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 키보드로 실수 3개를 입력한 다음 큰 숫자부터 작은 숫자로 정렬한 뒤 출력하라.
// line_up() 함수, swap() 함수를 작성해서 구현하라.

void swap(double* ptr_a, double* ptr_b);
void line_up(double* max_p, double* mid_p, double* min_p);

int main() {

	double max, mid, min;

	printf("실수 값 3개 입력: ");
	scanf("%lf %lf %lf", &max, &mid, &min);

	printf("\n%u %u %u\n", &max, &mid, &min);	// 주소값 확인

	line_up(&max, &mid, &min);
	printf("정렬된 값 출력: %.1lf, %.1lf, %.1lf\n", max, mid, min);

	return 0;
}

void swap(double* ptr_a, double* ptr_b) {
	double temp;

	temp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = temp;
}

void line_up(double* max_p, double* mid_p, double* min_p) {
	// 매개변수 자리에 포인터를 선언하면, 함수가 호출될 때, 
	// 포인터가 만들어지면서, 호출할 때 주는 주소로 바로 초기화가 된다.

	if (*max_p < *mid_p) { swap(max_p, mid_p); }
	if (*max_p < *min_p) { swap(max_p, min_p); }
	if (*mid_p < *min_p) { swap(mid_p, min_p); }

	/*
	if (*max_p < *mid_p) { swap(&max_p, &mid_p); }	//<= 이렇게 하면 작동하지 않는다.
	if (*max_p < *min_p) { swap(&max_p, &min_p); }  //
	if (*mid_p < *min_p) { swap(&mid_p, &min_p); }  //
	*/

	printf("\n%u %u %u\n", max_p, mid_p, min_p);	  // &max, &mid, &min 주소값과 동일
	printf("\n%u %u %u\n\n", &max_p, &mid_p, &min_p); // &max_p는 max_p 자체의 주소값
}

// 1. 포인터는 변수라 일반 변수와 같이 선언한 후에 쓴다. 
//    선언할 때 별이 붙는다는 것이 다르다. 
//    
//    int* p; 이렇게 p 앞에 별이 붙는다.
//    선언한 후에는 p = 주소; 와 같이 이름 p를 사용하는 것은 일반 변수와 같다.
//    다만 포인터 변수 자체 p를 사용하는 것 보다* p를 더 많이 사용하는데 
//    이건 p에 저장한 주소 위치에 할당한 변수를 쓰겠다는 것이다.
// 
//    이때 *p의 별과 선언할 때의 별은 전혀 관계가 없다.
//    따라서 포인터에 붙는 별이 선언하는 별이냐 아니면
//    p가 가리키는 변수를 사용하는 것의 별이냐를 반드시 구분해야 한다. !!!!!
//
// 2. 주소값을 받는 함수의 매개변수로 포인터를 선언했다.
//    <= void line_up(double* max_p, double* mid_p, double* min_p) 
//    
//    매개변수 자리에 포인터를 선언하면 함수가 호출될 때, 
//    포인터가 만들어지면서 호출할 때 주는 주소로 바로 초기화가 된다. !!!!!
//    
//    즉, void line_up(double* maxp, double* midp, double* minp) { ... }에서 
//    double* maxp 는 포인터 선언이라 이 때의 별은 당연히 선언에 사용하는 별이다.
//    따라서 *max_p가 아니다.
//
// 3. 포인터를 사용할 때 별을 붙이는데, 
//    이 때 *p는 p가 가리키는 값만 의미하는 것은 아니다. 
//    *p = 10; 과 같이 사용하면 p가 가리키는 변수가 된다.
//    즉, 별 연산자는 포인터가 가리키는 값을 구하는 연산자가 아니고 
//    포인터가 가리키는 변수를 사용할 수 있게 해주는 연산자로 이해하는 것이 정확하다.
//    
//    이 부분은 변수의 엘벨류(L-value), 알벨류(R-value)에 대한 이야긴데 
//    자세한 내용은 아래 영상을 참고하면 좋을 듯하다.
//    당장에는 큰 이해의 필요성을 느끼지 못할지라도 
//    응용 포인터에 가면 중요해지므로 정리하고 넘어가는 것이 좋다.
//    
//    - 포인터의 엘벨류, 알벨류 https://youtu.be/rKPM00upr_o
//    - 변수의 엘벨류, 알벨류 https://youtu.be/RF4UhnXQFkE
//
// 4. if (*max_p < *mid_p) { swap(max_p, mid_p); }에서 
//    왜 max_p, mid_p와 같이 사용한 것인가?
// 
//    int a = 10;
//    int* p = &a;
//
//    이 경우 p로 a의 값을 출력한다면 
//    printf("%d", *p); 와 같이 p앞에 별(*)을 붙여 p가 가리키는 대상인 a를 출력한다.
//    
//    그런데 출력하는 기능을 func라는 함수로 만들고 호출한다면 
//    func(*p)도 가능하고 func(p)도 가능하다.
//    전자는 a의 값 10을 넘겨 주는 것이고, 후자는 a의 주소를 넘겨 준다.
// 
//    p가 a의 주소를 갖고 있으므로 func(p)는 a의 주소를 넘겨 주는 것이다. 
//    
//    이렇게 단지 값을 출력하는 기능의 함수라면 
//    포인터 자체(p)를 써도 되고 포인터가 가리키는 것(*p)을 써도 된다.
// 
//    하지만 swap 함수처럼 원본의 값에 변화를 주는 함수라면 
//    반드시 포인터를 직접 사용해야 한다. 
//    *p와 같이 포인터 인수를 사용하면 a 값의 복사본이 넘어가므로 
//    절대 a의 값에 변화를 줄 수 없다.
//
//    위의 예도 같은 문제이다. 두 번에 걸쳐 함수를 호출하므로 복잡해보이는 것뿐이다.
//
//    swap 함수는 바꾸고자 하는 대상의 주소가 필요하므로 
//    어떤 함수에서 호출하든지 바꾸고자 하는 대상이 무엇인지를 파악하여 
//    그 주소가 넘어갈 수 있도록 호출해야 한다.                        <= !!!!!
//
//    line_up 함수에서 swap함수를 호출할 때
//    바꾸고자 하는 대상이 main 함수의 max, mid, min이므로
//    swap 함수를 호출할 때는 원래 swap(&max, &mid); 와 같이 사용해야 한다.
//    
//    하지만 line_up 함수에서 main 함수의 이름인 max, mid, min을 사용할 수 없으니까,
//    대신 그 주소를 갖고 있는 max_p, mid_p, min_p를 사용하는 것이다.  <= !!!!!
// 
//    따라서 max_p, mid_p, min_p를 사용할 때는
//    swap(max_p, mid_p); 와 같이 그 값을 그대로 swap 함수에 줘야 한다.
//    max_p와 mid_p가 바꾸고자 하는 대상인 max와 mid의 주소를 갖고 있기 때문이다.