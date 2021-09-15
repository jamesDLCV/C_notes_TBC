#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// strlen(), strcmp()
#include <stdlib.h>	// malloc(), free()
#define SLEN 81

// 구조체와 할당 메모리
// 
// 구조체의 멤버로서 할당 메모리를 사용할 수 있도록 할당 메모리를 가리키는 포인터를
// 구조체의 멤버로 사용하는 경우에 대해서 살펴 본다.
// 
// 기본적인 내용 설명 후, 
// 앞에서 풀어 봤던 예제를 동적 할당 메모리를 사용하는 형태로 바꿔 봐라.
//
// 다음은 앞에서 살펴 본 예제와 거의 유사하다. 

struct namect {
	char* fname;	// use malloc()
	char* lname;	// use malloc()
	int letters;
};

int main() {
	/*
		Dangerous usage
	*/

	struct namect p = { "Jeong-Mo", "Hong" };
	printf("%s %s\n", p.fname, p.lname);

	//int f1 = scanf("%[^\n]%*c", p.lname); <= 이렇게 writing할 수 없다.
	//printf("%s %s\n", p.lname, p.fname);

	/*
		Recommended usage
	*/

	// 입력을 받으려면 이렇게 한다. 
	char buffer[SLEN] = { 0, };
	int f2 = scanf("%[^\n]%*c", buffer);
	p.fname = (char*)malloc(strlen(buffer) + 1);

	if (p.fname != NULL)
		strcpy(p.fname, buffer);
	printf("%s %s\n", p.fname, p.lname);

	return 0;
}

// #include <stdlib.h>	// malloc(), free()
// <= malloc()으로 메모리를 받아 오면, 어디에선가 free()로 메모리 해제를 해 줘야 한다.
//    이런 개념을 기초 공부할 때만이라도 머리 속에 잘 넣어 둬라.
//    기초를 잘 다져 놓는다는 느낌으로 꼼꼼하게 봐 두기 바란다.
//    나중에 실무를 하거나 다른 언어를 하게 되면, 이런 번거로운 것들은 많이 사라진다.
// 
// struct namect {}; 구조체는 앞에서 만든 구조체와 거의 동일하다. 
// 앞에서는 char fname[SLEN]; 이런 식으로 문자의 배열을 사용해서 문자를 저장했다. 
// 이번에는 동적 할당 메모리를 멤버로 가지고 있는 것처럼 구현할 수 있도록
// 포인터를 멤버로 가지고 있다. 
// 
   /*
   struct namect {
	   char* fname;	// use malloc()
	   char* lname;	// use malloc()
	   int letters;
   };
   */
// 
// 앞에서 만든 예제를 바꿀 때는 다음의 두 함수를 구현해야 한다. 
// 
// void getinfo(struct namect*);	// allcoate memory
// <= 조금 복잡할 수 있다. 
// 
// void cleanup(struct namect*);	// free memory when done
// <= malloc()으로 할당받은 메모리를 free()해 주는 함수이다. 
//    앞에서 공부했던 것을 참고해서 구현해 보아라. 
// 
// struct namect p = { "Jeong-Mo", "Hong" };
// <= 구조체를 초기화할 때, 문자열을 가지고 직접 초기화할 수도 있다. 
//    namect라는 구조체 안에는 문자열을 가리킬 수 있는 포인터가 들어 있었다.
//    "Jeong-Mo" 문자열이 저장된 공간에 대한 첫 주소를 가지고 있을 수 있고, 
//    "Hong" 문자열이 저장된 공간의 첫 주소도 가리킬 수 있을 것이다. 
// 
// 그런데 문제가 뭐냐면, p.fname이 "Jeong-Mo"을 가리키고 있을 것이고, 
// p.lname이 "Hong"의 첫 주소를 가리키고 있을 텐데, 
// 이렇게 상수(constant) 형태로 저장돼 있는 문자열("Jeong-Mo", "Hong")은
// 어디에 저장이 되는가이다. 
// 이는 앞에서 메모리 레이아웃 강의에서 설명했다.
// <= 프로그램과 함께 TEXT segment에 저장이 된다고 했다. 
// 
// TEXT segment는 어떤 특징을 가지고 있는가? 
// Read only이다. 읽기만 할 수 있다. 값을 바꿀 수가 없다. 
// 
// "Jeong-Mo" 문자열이 저장된 메모리 주소를 가리키고 있기는 하지만, 
// 그 주소를 이용해서 그 메모리 공간에 저장돼 있는 값을 바꾸려고 시도하면, 
// 문제가 생긴다. <= 운영체제가 Read only 영역에서의 Writing은 불허한다.
// 
// int f1 = scanf("%[^\n]%*c", p.lname);
// <= 앞에서 설명했 듯이, \n을 무시하므로, 
//    빈칸이 있는 문자열도 계속해서 입력을 받을 수 있다.
//    <= %*c 글자 하나를 무시해라. 무슨 글자를? \n 글자를 무시하라.
//    앞으로는 코드를 간단하게 하기 위해서 이것을 많이 사용하겠다. 
//    scanf()로 p.lname에다가 입력 받은 내용을 저장하려고 하는 것이다.  
// 
//    앞 강의에서 이와 동일하게 기능하는 s_gets() 함수도 소개했다.
// 
// int f1 = scanf("%[^\n]%*c", p.lname);
// printf("%s %s\n", p.lname, p.fname);
// <= 이것을 실행해 보자. 
// 실행 후 문자 입력을 하면, 
//  exited with code -1073741819.
// <= 이렇게 뜨며 이상하게 종료가 돼 버린다. 운영체제가 강제로 종료시켜 버린 것이다. 
//    왜냐하면, "Jeong-Mo", "Hong" 문자열이 저장된 공간은 건드리면 안 되는데, 
//    scanf()를 통해서 수정하려고 시도를 했기 때문이다. 
// 
// 그러므로 
// int f1 = scanf("%[^\n]%*c", p.lname);
// printf("%s %s\n", p.lname, p.fname);
// <= 이렇게는 사용할 수 없다. 
// 
// 그러면 어떻게 사용하는 것이 좋을까?
// 
// char buffer[SLEN] = { 0, }; 
// <= 입력 받을 최대 길이만큼 버퍼처럼 사용할 공간을 준비한다.
//  (여기에서의 버퍼는 기능으로서의 버퍼이다. 임시로 데이터를 저장하다는 의미이다), 
//  (temp로 사용해도 무방하다)
//  
// int f2 = scanf("%[^\n]%*c", buffer);
// <= 이 buffer에다가 scanf()로 입력을 받아서, 
// 
// p.fname = (char*)malloc(strlen(buffer) + 1);
// <= 입력 받은 것을 길이를 재 보고, 거기에 null character가 저장될 부분 1을 더해 준다.
//    string이니까 마지막에 null character가 필요하다. <= strlen() 함수의 특징이다.
//    그다음, 동적 할당을 받고, 포인터를 p.fname에 넣어 준다.
// 
// if (p.fname != NULL)
//     strcpy(p.fname, buffer);
//     printf("%s %s\n", p.fname, p.lname);
// 
// <= 그다음, strcpy()를 통해 p.fname에 복사를 해 준다. 
// 
// 그다음 출력을 해 보면 의도한 대로 출력이 된다.
// printf("%s %s\n", p.fname, p.lname);
// 
// 앞에서 배운 함수를 사용해서 
// 이와 동일한 결과가 나오도록 프로그램을 작성해 봐라.