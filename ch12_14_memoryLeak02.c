#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 동적 할당 메모리의 특징을 이용하는 방법도 있다. 
// 블록을 벗어나도 free(ptr);을 하지 않으면 메모리에 그대로 남아 있다. 
// 이것을 이용하려면, 다음과 같이 할 수 있다. 
// <= 권장하지는 않는다. 블록을 벗어나면 메모리에서 사라지는 것이 깔끔하다.
// 사라져야 실수를 할 여지가 줄어든다.  

int main() {

	printf("Dummy Output\n");

	int* ptr_backup = NULL; // 어떤 포인터를 만든다.

	{
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));

		if (!ptr)	// if(ptr == NULL) 
		{
			printf("Malloc() failed");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i)
			ptr[i] = i + 1;

		printf("%d %d\n", ptr[0], ptr[1]);

		ptr_backup = ptr;	// block을 빠져나가기 전에 backup을 해 둔다.

		//free(ptr);		// <= free(ptr);을 하면 안 된다.
		//ptr = NULL;
	}
	// What happens?

	printf("%d %d\n", ptr_backup[0], ptr_backup[1]);
	printf("Dummy Output\n");

	return 0;
}

// 동적 할당 메모리의 특징을 이용하는 방법은 다음과 같다. 
// int* ptr_backup = NULL; // 어떤 포인터를 블록 밖에 만들어 둔다.
// ptr_backup = ptr;   // 블록을 빠져나가기 전에 backup을 해 둔다.
// free(ptr);을 하면 안 된다. 
// <= 블록 밖에서도 동적 할당된 메모리를 사용하려고 하므로.
// 
// 실행을 해 보면,
// Dummy Output
// 1 2
// 1 2
// Dummy Output
// 
// 이렇게 블록 밖에서도 동적 할당으로 받은 메모리에 접근할 수 있다. 
// 블록 안의 ptr[0], ptr[1]의 값과 
// 블록 밖의 ptr_backup[0], ptr_backup[1]의 값이 동일하다. 
// 
// ptr은 포인터 변수(주소를 적어 놓은 쪽지)이므로 블록을 벗어나면 사라진다. 
// 하지만, 동적 할당 메모리 자체는 힙에 그냥 남아 있다. 
// 그래서 블록을 벗어나기 전에 주소를 옮겨 적어 놨다면, 
// 그 메모리에 있는 데이터를 그대로 사용할 수 있다. 
// 값을 대입할 수도 있고 바꿀 수도 있다. 
// 
// 그런데, ptr_backup = ptr;로 backup을 해 둔 후 free(ptr)을 해 주면???
// printf("%d %d\n", ptr_backup[0], ptr_backup[1]);
// 의 ptr_backup[0]에 밑줄이 생긴다. <= visual studio가 띄워 주는 것이다.
// GCC나, 리눅스에서 작업하거나 개발 도구의 지원이 약하면 경고가 안 뜬다.
// 
// 쪽지에 주소를 옮겨 적어서, 아무리 여러 개의 주소를 갖고 있다 한들, 
// 그 주소에 살고 있는 사람이 이사를 가 버리면, 
// 그 주소를 찾아 가 봐도 소용이 없다. 
// <= free(ptr);을 해 주면 이런 상태가 된다. 
//    주소는 갖고 있으나, 힙에서의 메모리는 사라지고 없는 상태이다. 
// 
// 실행을 하면, Exception Thrown: read access violation.
// 에러가 뜬다. 
// 운영체제가 봤을 때, 왜 너에게 할당이 안 된 메모리를 건드리려고 하느냐고
// 에러 메시지를 띄우는 것이다. 
// 
// 자료 구조 공부할 때, linked list에서 많이 하는 실수가 이런 것이다. 
// <= printf("%d %d\n", ptr_backup[0], ptr_backup[1]);
// free(ptr);를 한 다음에 이렇게 메모리를 사용하는 실수를 할 수 있다. 
// 
// 다음은 메모리 누수를 돌려 보겠다. 
//