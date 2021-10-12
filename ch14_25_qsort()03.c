#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// qsort()

// 구조체가 있고, 구조체의 데이터가 있다.
// struct kid my_friends[]의 데이터를 키에 따라서 정렬하도록 구현해 보아라.
// <= compare() 함수를 구현해 보아라. 

struct kid {
	char name[100];
	int height;
};

//TODO: try increasing/decreasing order
int compare(const void* first, const void* second);

int main() {
	struct kid my_friends[] = {
		"Jack Jack", 40, "Geenie", 300, "Aladdin", 170, "Piona", 150
	};

	const int n = sizeof(my_friends) / sizeof(struct kid);

	qsort(my_friends, n, sizeof(struct kid), compare);

	for (int i = 0; i < n; ++i)
		printf("%s    \t%d\n", my_friends[i].name, my_friends[i].height);

	return 0;
}

int compare(const void* first, const void* second) {
	if (((struct kid*)first)->height > ((struct kid*)second)->height)
		return 1;
	else if (((struct kid*)first)->height < ((struct kid*)second)->height)
		return -1;
	else
		return 0;
}

// if (((struct kid*)first)->height > ((struct kid*)second)->height)
//   <= struct kid의 포인터로 casting을 해 주고, height 멤버를 가져다가, 
//      비교를 해 주면, 간단하게 구현을 할 수 있다.  
//     return 1;  
// else if (((struct kid*)first)->height < ((struct kid*)second)->height)
//     return -1;
// else
//	   return 0;
// 
// qsort() 함수뿐 아니라, 어떤 함수의 포인터를 받아서 
// 그 함수 포인터를 이용해서 작동하는 함수를 사용할 때, 
// 이렇게 접근할 수 있다는 것을 알아 두면 좋겠다. 
// 
// 함수 포인터의 용법을 보다 자세하게 공부하기 위해서,
// qsort() 함수의 예제를 살펴 봤다. 