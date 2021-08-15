#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>	// <= 윈도우즈에서는 include해 줘야 한다. 
						// C언어 표준에는 멀티 쓰레딩이 아직 안 들어와 있다.
						// 대부분의 경우, 운영체제에서 제공하는 API를 쓴다.
// Multi-Threading
// 멀티 쓰레딩
// 
// C언어에서 사용되는 멀티 쓰레딩을 간단하게 살펴 보겠다.
// C++에서 멀티 쓰레딩을 용이하게 사용할 수 있다. 
// 
// 멀티 쓰레딩의 개념
// 프로그램을 만들고 실행시키면, 그 프로그램은 Process에서 실행이 된다. 
// Process는 운영체제와 관련된 용어이다. 
// 
// Process에서 프로그램이 실행되면, Main Thread 주된 쓰레드로부터 흐름이 쭉 이어진다. 
// (Thread: 프로그램을 실행시켜 나가는 흐름)
//
// 흐름이 가다가 Main Thread가 다른 Thread를 또 만들어서 띄울 수 있다. 
// (이야기가 병렬로 진행되는 것과 유사하다) <= 동시성 프로그래밍이라고도 한다. 
// Main Thread가 다른 Thread를 띄워서 일을 시키고, 
// 새로 띄운 Thread는 일을 다하면, 종료한 후 사라진다. 
// Main Thread는 또 다른 Thread를 띄우고, 또 다른 Thread를 또 띄울 수 있다.
// 그러므로 제시된 그림에서는 4개의 Thread가 존재하는 형태가 된다. 
// 
// 동시에 여러 가지 일을 할 수가 있다. 
// 
// computing 기술의 발전에 따라서, 최근에는 멀티 코어 cpu가 일반적이다. 
// 그러므로 최근에는 멀티 쓰레딩을 이용한 동시성 프로그래밍, 혹은 병렬 처리가 
// 보편적이 되어 있다. <= 개념만 알아 두라. 
// 
// 멀티 쓰레딩에 대해서 여기서 알아 둬야 할 것은 크게 두 가지이다. 
// 
// 1. 함수를 구현하는데, 같은 함수를 여러 개의 thread가 동시에 작동시킬 경우가 있다. 
//    그러면 그 함수 안에 어떤 지역 변수가 있을 수 있다. (대부분의 경우 지역 변수가 있다)
//    그 지역 변수는 어떤 storage class를 갖는가? (어떤 저장 공간 분류를 갖는가?)
//    Thread0, Thread1, Thread2와 같이 세 개의 Thread가 
//	  하나의 함수를 동시에 실행시킨다면, 메모리 상에는 그 함수를 실행시키기 위한 데이터가
//    세 copies가 있어야 한다. (세 개의 사본이 있어야 한다)
//    그래서 그 함수 안에 들어 있는 변수들도 세 개가 동시에 생겨나 있다. 
// 
// 2. 하나의 전역 변수를 여러 개의 Thread가 동시에 접근해서 사용하려고 한다면?
//	  경쟁이 생긴다. 앞에서 CPU의 작동 원리에 대해서 공부를 했다. 
//    기본적으로 CPU는 메모리와 일을 하기 때문에, (데이터가 메모리에 저장돼 있고)
//    메모리에 저장돼 있는 값을 CPU로 전송을 하면, CPU에 있는 register라는 임시 공간에
//    값을 잠깐 올려 놓고 작업을 하고 그 결과를 다시 메모리로 보낸다. 
//    그러면 메모리하고 CPU 사이를 왔다 갔다하는 사이에, 문제가 생길 수 있다. 
//    첫 번째 Thread가 메모리로부터 CPU로 data를 가지고 와서 작업을 하는 동안에
//    다른 Thread가 메모리에 있는 값을 바꿔 버린다면, 문제가 생긴다. 
//    <= 이런 경우를 어떻게 방지할까?
// 
// 이 두 가지의 경우에 대해서 주로 살펴 보겠다.
// 
// C언어 표준에는 멀티 쓰레딩이 아직 안 들어와 있다.
// 대부분의 경우, 운영체제에서 제공하는 API를 쓴다.
// <= 운영체제에 따라서, 작성한 프로그램이 어떤 운영체제에서 작동할지에 따라서,
//    사용하는 프로그래밍 기술이 달라지게 된다. 
//	  약간 안타까운 측면이 있다. 
// 윈도우즈에서는 #include <windows.h>를 하고, 
// main() 함수 내의 문법을 사용해서 구현을 한다.  

// _Atomic int acnt = 0;	// NA

DWORD WINAPI ThreadFunc(void* data) {
	int n = 1;
	Sleep(1000);

	//acnt += n;			// NA
	printf("Printing from Thread \n");

	return 0;
}


int main() {
	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	if (thread)
		WaitForSingleObject(thread, INFINITE);
}

// 윈도우즈에서는 위와 같이 실행시키면 된다. 
// 이것보다 조금 더 일반적으로 사용되는 것이, 
// GCC 리눅스에서 사용하는 posix 표준(portable operating system interface?)
// 를 따르는 것이다. 
// 온라인 컴파일러 중에서 이것이 되는 OnlineGDB에서 실행시켜 보자.  
// 
// 윈도우즈용 코드와 GCC의 코드가 다르다. 
// 윈도우즈에서는 windows.h를 include해 줘야 하고, 
// windows에서 할 때는 두 가지 불편함이 있다.  
// _Atomic 한정자를 쓸 수가 없다. 
// pthread를 기본으로 제공해 주지 않기 때문에, 따로 설치해서 실행시켜야 한다.
// 
// _Atomic을 사용하지 않고 전역 변수의 충돌이 생기는 것을 어떻게 방지하는가?
// 이는 병렬 처리 멀티 쓰레딩을 공부할 때 가장 중요한 기법 중 하나이다. 
// 각 thread가 코드의 일정 부분을 동시에 접근하지 못하도록 막는 방법이 있다. 
// 잠궈 버린다, lock한다 하는 방법이 있다. 
// <= 나중에 멀티 쓰레드를 제대로 공부할 때 공부하면 된다. 
// 
// 전체 코드를 보면,
// HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
// <= (CreateThread로) 만들면, thread가 함수 (ThreadFunc)를 실행을 시키고, 
// 그 다음,
// if (thread)
//     WaitForSingleObject(thread, INFINITE);
// <= 끝날 때까지 기다리는 것이다 .
// 
// 이 패턴은 GCC와 동일하다. 
// C언어에서 멀티 쓰레딩하는 방법에 대해 몇 가지 개념과 함께 간단하게 소개를 했다.  
// 

/*
	OnlineGDB에서의 코드는 visual studio에서와 다르다. 
*/