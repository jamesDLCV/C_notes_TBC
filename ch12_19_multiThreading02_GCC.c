/******************************************************************************

이것은 GCC용으로 GDB Online에서 실행 가능하다. 
Dev C++에서도 실행 가능하다. 
visual studio에서는 안 된다. 

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // sleep()
#include <pthread.h>    // <= 윈도우즈에서도 쓸 수 있다. 
#include <stdatomic.h>

_Atomic int acnt = 0;   // atomic type qualifer (C11)

// A normal C function that is executed as a thread_local
// when it sname is specified in pthread_create()

void* myThreadFun(void* vargp)
{
    int n = 1, j;  // thread storage duration
    for (j = 0; j < 10; ++j)
    {
        sleep(1);
        acnt += n;
        printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
    }

    return NULL;
}

int main()
{
    pthread_t thread_id1, thread_id2;

    printf("Before Thread\n");

    pthread_create(&thread_id1, NULL, myThreadFun, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    printf("After Thread\n");
    printf("Atomic %d\n", acnt);

    return 0;
}

// GCC에서 컴파일하고 싶다면, pthread라는 라이브러리를 추가해 달라는 다음의 명령을 쓴다.

To compile
$ gcc <file - name.c> -o <output - file - name> -lpthread

To run
$ . / <output - file - name>


// C++를 공부한 후 돌아와서 하면, <pthread.h>를 여러 방법으로 손쉽게 사용할 수 있다. 
// 
// pthread_t thread_id1, thread_id2;
// <= thread_id1, thread_id2를 가지고 thread를 식별한다.
// <= thread의 identification으로 사용한다.
//    내부적으로는 포인터처럼 사용을 한다. (포인터라고 하기는 조금 애매하다)
//    (문법에서 배운 포인터와는 다르지만, 용도로 봤을 때는 쓰레드를 지정할 수 있다)
//    (쓰레드를 식별할 때 사용할 수 있다)
// 이와 같은 코드는 C++ 등 다른 언어에서도 나오는 패턴이니까 잘 봐 둬라. 
// 
// pthread_create(&thread_id1, NULL, myThreadFun, NULL);
// <= myThreadFun()을 실행시키는 Thread를 실행시킨다.  
//    그리고 그 Thread에 대한 식별자를 &thread_id1에 넣어 준다.
//    포인터로 넣어 주고 있다. (주소로 넣어 주고 있다) 
//    그러면 이것을 &thread_id1가 받아 온다. 
// 함수의 매개변수로서 포인터를 사용하는 방법에 대해서 이전 강의에서 설명했다. 
// 
// pthread_create(&thread_id1, NULL, myThreadFun, NULL);
// pthread_create(&thread_id2, NULL, myThreadFun, NULL);
// <= 두 개를 띄우고 있다. 
//    그러면 일시적으로 두 개의 함수이므로, 메모리와 CPU에서 두 copies가 작동하게 된다. 
//    myThreadFun() 함수 안을 보면, 지역 변수 n이 있다. (1개 있다)
//    &thread_id1, &thread_id2에서 모두 
//    int n = 1 변수가 차지하는 메모리를 가지고 있다.  
//    thread가 두 개면, 두 copies가 생긴다. 
//    n은 지역 변수이므로 이 함수가 끝나면, 사라지게 된다. 
//    stack에서 빠져나갈 것이다. 
//    <= 이런 변수를 thread storage duration로 따로 분류하기도 한다. 
//    
//    그냥 지역 변수인데 thread가 동시에 여러 개가 실행되고 있으니까, 
//    여러 개 실행되는 함수에 따로 따로 메모리를 갖고 있는 것은 당연하다. 
// 
// _Atomic int acnt = 0;   // atomic type qualifer (C11)
// => 여러 개의 thread에서 (여러 개의 함수가 실행될 텐데)
//    각각의 thread가 동일한 전역 변수에 접근해서, 뭔가 값을 바꾸거나 읽어오려고 할 때,
//    CPU와 메모리가 분리돼 있는 구조에 의해서 일관성이 깨질 수도 있다. 
//    <= 이러한 비일관성을 방지하기 위해서 _Atomic이라는 qualifier를 사용할 수 있다.
//    _Atomic을 붙여 주면, 여러 개의 thread에서 이 변수를 변경하는 것을 막아 버린다. 
//      <= racing condition에 의한 문제를 방지한다. (경쟁 발생 방지)
//  
// 단점은 _Atomic 연산은 일반적인 연산에 비해 조금 느리다. 
// 
// acnt += n; <= 위 myThreadFun() 함수 안의 이러한 연산처럼
//               한 thread 안에서 빈번하게 하는 연산에 대해서는,  
//               이처럼 Atomic 변수는 사용하지 않는 것이 좋다. 
//               여기부터는 C++로 넘어가는 게 더 효율적이다. 
// 
// pthread_join(thread_id1, NULL);
// pthread_join(thread_id2, NULL);
// <= 다른 tread가 끝날 때까지 기다려 주기 위해서 _join을 이렇게 사용한다. 
//    join이라고 한다. 병렬 처리할 때 많이 사용하게 된다. 
//    기다린다는 의미다. 다른 thread가 나한테 돌아와서 합류할 때까지 기다린다. 
//    여행을 떠났던 그룹이 흩어졌다가 다시 합류한다는 개념으로 이해하라. 
// 
// 만약 thread가 하는 일이 엄청 많을 때, 
// main thread가 다른 thread에게 일을 하라고 시켜 놓기만 하고, 
// 자기가 먼저 끝나 버리면, (main() 함수가 끝나면 프로그램이 끝나 버린다)
// thread는 할 일이 남았지만, 프로그램이 먼저 끝나 버리면, 매우 당황스러운 일이 발생한다.
// <= 이러한 것을 방지하기 위해서 위처럼 pthread_join()을 사용해서 
//    thread들이 끝나는 것을 기다리는 것이다.