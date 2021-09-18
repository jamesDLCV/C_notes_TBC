#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 신축성 있는 배열 멤버, Flexible Array Members
//
// 구조체의 배열 멤버를 신축성 있게 사용하는 방법을 살펴 보겠다. 
// 배열이 flexible 하다는 것은 길이가 변할 수 있다는 것이다. 

int main() {
	/*
		Flexible array member (struct hack in GCC)
	*/

	struct flex {
		size_t count;
		double average;
		double values[];	// flexbile array member (last member!)
	};

	const size_t n = 3;

	struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf == NULL) exit(1);

	printf("\nFlexible array member\n");
	printf("Sizeof struct flex %zd\n", sizeof(struct flex));
	printf("Sizeof *pf %zd\n", sizeof(*pf));
	printf("Sizeof malloc %zd\n", sizeof(struct flex) + n * sizeof(double));
	printf("\n------------------------------\n");

	printf("%lld\n", (long long)pf);
	printf("%lld\n", (long long)&pf->count);
	printf("%zd\n", sizeof(pf->count));
	printf("%lld\n", (long long)&pf->average);
	printf("Address of pf->values %lld\n", (long long)&pf->values);
	printf("Value of pf->values %lld\n", (long long)pf->values);
	printf("Sizeof pf->values %zd\n", sizeof(pf->values));
	
	pf->count = n;
	pf->values[0] = 1.1;
	pf->values[1] = 2.1;
	pf->values[2] = 3.1;

	pf->average = 0.0;
	for (unsigned i = 0; i < pf->count; ++i)
		pf->average += pf->values[i];
	pf->average /= (double)pf->count;

	printf("Average = %f\n", pf->average);

	/*
	struct nonflex
	{
		size_t count;
		double average;
		double *values;		// Use malloc()
	};

	struct nonflex nf;
	nf.value = (double*)malloc(sizeof(double) *n); 
	*/

	/*
	struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf2 == NULL) exit(1);

	*pf2 = *pf1;	// Don't copy flexible members, use memcpy() instead

	free(pf);
	free(pf2);
	*/

	return 0;
}

// Flexible array member는,
// 예전에는 GCC에서 편법(struct hack in GCC)이었는데, 표준으로 들어 왔다.
// 
// double values[];
// <= 마지막 멤버를 배열로 선언을 하는데, 배열이 뭔가 좀 허전하다. 
//    길이가 없다. 반드시 마지막 멤버여야 한다. 
//    그리고 동적 할당을 해야 한다.
// 
// 원래 구조체의 크기만큼 동적 할당을 받는 게 아니고, 
// 내가 사용하고 싶은 길이만큼 추가로 동적 할당을 받는다. 
// struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
// <= n * sizeof(double) 만큼 동적 할당을 받는다. 
// 
// 그러면, struct flex에 
// size_t count;가 있고, 
// double average;가 있고,
// double values[]; <= 이 배열로 사용하고 싶은 메모리(여기에서는 3칸)가 있다. 
// 
// const size_t n = 3; n * sizeof(double)
// <= 여기에서는 double 3개가 나란히 있는 형태로 메모리에 배정이 될 것이다.
//  
// 그리고 배정 받은 세 칸을 values[]의 배열처럼 사용할 수 있다. 
// 
// 밑에 있는 사용 예부터 먼저 살펴 보자.
// pf->count = n;
//  <= count에다가 몇 개 있는지 저장해 놓는다.  
//     왜냐하면, 동적 할당을 받았기 때문에, 
//     한 번 할당을 받고 나면 사이즈를 측정할 수 없다.
//     할당 받은 직후에 count라는 별도의 변수에다가 몇 칸을 배정 받았는지 
//     저장을 해 놓는 것이 좋다.  
// 
// pf->values[0] = 1.1;
// pf->values[1] = 2.1;
// pf->values[2] = 3.1;
//  <= values는 이렇게 초기화를 하면 된다. 
// 
// pf->average = 0.0;
// for (unsigned i = 0; i < pf->count; ++i)
//	   pf->average += pf->values[i];
// pf->average /= (double)pf->count;
// <= 평균도 이렇게 구할 수 있다. 
//    배열처럼 사용할 수 있기 때문에 for문을 돌릴 수 있다. 
//    몇 개인지 count에 넣어 놓은 숫자를 이용해서 for문을 작성할 수 있다. 
// 
// 마치 구조체 맨 뒤에 배열이 있는데, 
// struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
// <= 이렇게 동적 할당을 받기 때문에 동적 할당 배열처럼 사용할 수 있다. 
// 
// 길이가 늘어났다 줄어들었다 할 수 있다. 
// 
// const size_t n = 3;
// <= 이 n 크기를 바꾸면, 
//    struct flex의 멤버 double values[]; 배열의 크기를 얼마든지 바꿀 수가 있다. 
// 
// 편리하게 사용할 수 있는 문법 중 하나이다. 
// 
// 메모리 구조가 어떻게 되는지 구체적인 내용을 코드 보면서 생각해 보도록 하겠다. 
// 위 코드를 실행해 보면, 
// 
// printf("\nFlexible array member\n");
// printf("Sizeof struct flex %zd\n", sizeof(struct flex));
// <= 사이즈를 찍어 보면 16이다. 
//    struct flex의 멤버 size_t에 마우스를 갖다 대면, 
//	  x64에서는 unsigned long long 8 바이트(x86에서는 unsigned int 4 바이트)이다.
//    다른 멤버 double average;는 8 바이트,
//    double values[];의 사이즈가 얼마더라도, 
//    sizeof(struct flex) struct flex의 사이즈가 16이 될 수는 없어 보인다. 
// 
// 아래에서 주소를 먼저 보자. 
// printf("%lld\n", (long long)pf);
//  <= 구조체 자체의 주소 pf(pf 자체가 주소이다)를 찍어 보면, 
//     1894688684752 가 나온다. (x64)   
// 
// printf("%lld\n", (long long)&pf->count);
//  <= 그다음, 구조체의 첫 번째 멤버의 주소를 찍어 보면, 
//     1894688684752 로 구조체 자체 pf의 주소와 동일하다. 
// 
// printf("%zd\n", sizeof(pf->count));
//  <= 첫 번째 멤버의 사이즈는, x64에서 unsinged long long 8 바이트,
//     x86에서는 unsigned int 4 바이트이다. 
//     다시 한 번 struct flex의 멤버 size_t에 마우스를 갖다 대 보면, 
//     typedef unsinged long long size_t라고 뜬다. 
//     <= typedef를 이용해서 unsigned long long을 size_t로 사용하고 있는 형태이다.
//        이 컴파일러에서는 size_t가 unsigned long long이라는 뜻이다. 
//        (x86에서는 size_t가 unsigned int이다)
// <= 출력) 사이즈는 8이 나왔다(x64). x86에서는 4가 나온다. 
// 
// printf("%lld\n", (long long)&pf->average);
// <= pf->average의 주소를 찍어 보면, 
//    1894688684760가 나온다. 
//    pf->count가 시작되는 주소로부터 pf->average가 시작되는 주소 사이가, 
//    pf->count가 차지하고 있는 주소가 된다. 
// 
//    pf->count의 주소는 1894688684752이고 
//    pf->average의 주소는 1894688684760으로 차이는 8이다. 
//    (x86에서도 8의 차이가 난다)
//    x86에서는 sizeof(pf->count)를 4라고 했는데, 
//    pf->count와 pf->average의 차이는 왜 4인가?
//    <= padding이 들어간 것이다. (Allignment를 해 주기 위해서)
//       이건 컴파일러나 컴파일할 때, allignment struct memory, 
//       allignment option에 따라서 달라질 수 있는 값이다. 
// 
// 일단 padding을 하는 것이 일반적이므로 x86에서도 8바이트씩 차이가 난다는 것을 
// 기억해 둬라. 
// 
// size_t는 8 바이트이고(x86에서는 4 + 4(패딩)), pf->average도 8 바이트이다.
// 그리고 Sizeof malloc 40으로 우리가 malloc으로 요청한 것은 40이다. 
// 
// 그럼 Sizeof struct flex가 16이라는 계산은 어떻게 나온 것인가?
//   
// 아래를 먼저 보자,
// printf("Address of pf->values %lld\n", (long long)&pf->values);
// <= pf->values의 주솟값은 1894688684768이다. 
//    pf->count의 주솟값(1894688684752)과의 차이는 16이다.  
// 
// printf("Value of pf->values %lld\n", (long long)pf->values);
// <= pf->values는 일종의 포인터이다. (배열이므로)
//    배열의 첫 번째 원소를 가리키는 포인터이다. 
//    
//    pf->values의 주소와 pf->values의 값이 
//    1894688684768으로 동일하다. 
// 
// printf("Sizeof pf->values %zd\n", sizeof(pf->values));
// <= 컴파일러(엄밀히는 개발환경)이 빨간색 물결 표시를 해서 경고를 해 주고 있다. 
//    출력 값은 0이 나온다. 즉 사이즈가 0이다. 
//    이상하다. 
// 
// 메모리에 동적 할당을 받는다.  
// 앞의 16은 size_t count와 double average에 할당하기로 돼 있었는데
// 거기에 동적 할당으로 n * sizeof(double) 만큼을 더 받아서, 
// values[]로부터 시작하는 배열로 사용하는 것이다. 
// 어떤 면에서는 동적 할당 배열과 비슷한 느낌이 난다. 
// 
// 주의 사항이 있다. 
// 
// 마지막 멤버를 double* values; <= 배열이 아닌 포인터로 해 놓고, 
// nf.value = (double*)malloc(sizeof(double) * n); 
// <= 이렇게 malloc으로 동적 할당으로 추가로 받는 것과 어떤 차이가 있겠는가?
// 
	/*
	struct nonflex
	{
		size_t count;
		double average;
		double* values;		// Use malloc()
	};

	struct nonflex nf;
	nf.value = (double*)malloc(sizeof(double) * n);
	*/
// 
// <= 구조체 nf의 사이즈는 size_t에 패딩이 들어가고 double average가 8바이트이므로,
//    16바이트에다가 추가로 double* values; x86이면 포인터라서 4바이트, 
//    x64라면 8바이트가 될 것이다. 따라서 총 24바이트가 될 것이다. 
// 
// nf.value = (double*)malloc(sizeof(double) * n);
// <= 힙 메모리에 알 수 없는 어느 곳에 동적 할당을 
//    (double*)malloc(sizeof(double) * n); <= 이만큼을 받고
//    이것을 배열로 사용할 수 있는 동적 할당 배열이 하나 생겨나는 구조이다. 
// 
// 그럼 차이가 무엇인가?
// struct nonflex의 멤버 double* values;는 포인터 자체의 주소를 더 차지하고 있다.
// 
// struct flex의 멤버 double values[]는 이것 자체가 메모리를 차지하지는 않는다.
// 구조체의 앞에 있는 멤버 뒤에 동적 할당으로 메모리가 추가돼서 붙는 형태이기 때문에, 
// 이것을 배열로 사용할 수 있는 것이지 values[] 자체가 메모리를 차지하지는 않는다.
// 
// 그러나 struct nonflex의 멤버 double* values;는 포인터이므로, 
// 포인터 자체의 메모리를 차지하고 있다. <= 첫 번째 차이이다. 
// 
// 두 번째 차이는, 
// nf.value = (double*)malloc(sizeof(double) * n); 이 동적 할당 배열은, 
// 메모리의 어디에 위치할지 알 수가 없다. 
// 하지만,
// 
// struct flex의 멤버 double values[]가 추가로 받는 메모리는
// (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
// <= sizeof(struct flex)에다가 + n * sizeof(double)를 추가로 받은 것이기 때문에,
//    malloc()은 (sizeof(struct flex) + n * sizeof(double)) 사이즈만큼 
//    일열로 나열된 메모리를 준다. <= 그래서 어디에 있는지 확실하게 안다. 
//    <= 일열로 나열된 메모리를 받는다는 것을 기억하라. 
// 
// 그러나,마지막 멤버를 flexbile array 멤버가 아니라 동적 할당 배열처럼 포인터로
// 가지고 동적 할당을 받을 경우에는 구조체 struct nonflex의 세 개의 멤버가 차지하는
// 메모리와 마지막 멤버가 가리키는 메모리 (double*)malloc(sizeof(double) * n);이
// 엉뚱한 곳에 멀리 떨어져 있을 수 있다. 
// <= 메모리 구조와 관련해서 생각해 볼 수 있는 내용이다. 
// 
// 또 다른 주의 사항이 있다. 
// 
// *pf2 = *pf1; <= 이렇게 assignmnet를 하면, 복사가 잘 안 된다. 
// 앞에서
// printf("Sizeof struct flex %zd\n", sizeof(struct flex));
// <= struct flex의 사이즈를 찍어 보니까 16이었다. 
// 
// 동적 할당을 받을 것은 40이었는데, struct flex의 사이즈는 16이었다. 
// 그러므로 컴파일러 입장에서는  *pf2 = *pf1; 이렇게 대입을 시도했을 때, 
// 16바이트만 복사를 해 준다. 추가로 요청한 8 * 3 = 24바이트는 복사가 되지 않는다.
// 
// 컴파일러 입장에서는 동적 할당으로 받아왔기 때문에 사이즈를 알 수가 없다. 
// 그러므로, 
// memcpy()를 사용해서 
// struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double)); 이 메모리 전체를 memcpy()로 복사를 하는 게 좋다. 
// <= 이렇게 memcpy()로 복사해 주는 게 flexible array memeber를 사용하는 
//    옳바른 방법이다. 
// 
// flexible array member를 문법적으로 살펴 봤다. 