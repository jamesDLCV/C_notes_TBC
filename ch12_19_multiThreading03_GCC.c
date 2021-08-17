/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // sleep()
#include <pthread.h>    // <= ����������� �� �� �ִ�. 
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

// GCC���� �������ϰ� �ʹٸ�, pthread��� ���̺귯���� �߰��� �޶�� ����� ����.

To compile
$ gcc <file - name.c> -o <output - file - name> -lpthread

To run
$ . / <output - file - name>

