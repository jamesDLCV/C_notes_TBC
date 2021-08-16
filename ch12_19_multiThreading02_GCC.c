/******************************************************************************

�̰��� GCC������ GDB Online���� ���� �����ϴ�. 
Dev C++������ ���� �����ϴ�. 
visual studio������ �� �ȴ�. 

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

// GCC���� �������ϰ� �ʹٸ�, pthread��� ���̺귯���� �߰��� �޶�� ������ ����� ����.

To compile
$ gcc <file - name.c> -o <output - file - name> -lpthread

To run
$ . / <output - file - name>


// C++�� ������ �� ���ƿͼ� �ϸ�, <pthread.h>�� ���� ������� �ս��� ����� �� �ִ�. 
// 
// pthread_t thread_id1, thread_id2;
// <= thread_id1, thread_id2�� ������ thread�� �ĺ��Ѵ�.
// <= thread�� identification���� ����Ѵ�.
//    ���������δ� ������ó�� ����� �Ѵ�. (�����Ͷ�� �ϱ�� ���� �ָ��ϴ�)
//    (�������� ��� �����Ϳʹ� �ٸ�����, �뵵�� ���� ���� �����带 ������ �� �ִ�)
//    (�����带 �ĺ��� �� ����� �� �ִ�)
// �̿� ���� �ڵ�� C++ �� �ٸ� ������ ������ �����̴ϱ� �� �� �ֶ�. 
// 
// pthread_create(&thread_id1, NULL, myThreadFun, NULL);
// <= myThreadFun()�� �����Ű�� Thread�� �����Ų��.  
//    �׸��� �� Thread�� ���� �ĺ��ڸ� &thread_id1�� �־� �ش�.
//    �����ͷ� �־� �ְ� �ִ�. (�ּҷ� �־� �ְ� �ִ�) 
//    �׷��� �̰��� &thread_id1�� �޾� �´�. 
// �Լ��� �Ű������μ� �����͸� ����ϴ� ����� ���ؼ� ���� ���ǿ��� �����ߴ�. 
// 
// pthread_create(&thread_id1, NULL, myThreadFun, NULL);
// pthread_create(&thread_id2, NULL, myThreadFun, NULL);
// <= �� ���� ���� �ִ�. 
//    �׷��� �Ͻ������� �� ���� �Լ��̹Ƿ�, �޸𸮿� CPU���� �� copies�� �۵��ϰ� �ȴ�. 
//    myThreadFun() �Լ� ���� ����, ���� ���� n�� �ִ�. (1�� �ִ�)
//    &thread_id1, &thread_id2���� ��� 
//    int n = 1 ������ �����ϴ� �޸𸮸� ������ �ִ�.  
//    thread�� �� ����, �� copies�� �����. 
//    n�� ���� �����̹Ƿ� �� �Լ��� ������, ������� �ȴ�. 
//    stack���� �������� ���̴�. 
//    <= �̷� ������ thread storage duration�� ���� �з��ϱ⵵ �Ѵ�. 
//    
//    �׳� ���� �����ε� thread�� ���ÿ� ���� ���� ����ǰ� �����ϱ�, 
//    ���� �� ����Ǵ� �Լ��� ���� ���� �޸𸮸� ���� �ִ� ���� �翬�ϴ�. 
// 
// _Atomic int acnt = 0;   // atomic type qualifer (C11)
// => ���� ���� thread���� (���� ���� �Լ��� ����� �ٵ�)
//    ������ thread�� ������ ���� ������ �����ؼ�, ���� ���� �ٲٰų� �о������ �� ��,
//    CPU�� �޸𸮰� �и��� �ִ� ������ ���ؼ� �ϰ����� ���� ���� �ִ�. 
//    <= �̷��� ���ϰ����� �����ϱ� ���ؼ� _Atomic�̶�� qualifier�� ����� �� �ִ�.
//    _Atomic�� �ٿ� �ָ�, ���� ���� thread���� �� ������ �����ϴ� ���� ���� ������. 
//      <= racing condition�� ���� ������ �����Ѵ�. (���� �߻� ����)
//  
// ������ _Atomic ������ �Ϲ����� ���꿡 ���� ���� ������. 
// 
// acnt += n; <= �� myThreadFun() �Լ� ���� �̷��� ����ó��
//               �� thread �ȿ��� ����ϰ� �ϴ� ���꿡 ���ؼ���,  
//               ��ó�� Atomic ������ ������� �ʴ� ���� ����. 
//               ������ʹ� C++�� �Ѿ�� �� �� ȿ�����̴�. 
// 
// pthread_join(thread_id1, NULL);
// pthread_join(thread_id2, NULL);
// <= �ٸ� tread�� ���� ������ ��ٷ� �ֱ� ���ؼ� _join�� �̷��� ����Ѵ�. 
//    join�̶�� �Ѵ�. ���� ó���� �� ���� ����ϰ� �ȴ�. 
//    ��ٸ��ٴ� �ǹ̴�. �ٸ� thread�� ������ ���ƿͼ� �շ��� ������ ��ٸ���. 
//    ������ ������ �׷��� ������ٰ� �ٽ� �շ��Ѵٴ� �������� �����϶�. 
// 
// ���� thread�� �ϴ� ���� ��û ���� ��, 
// main thread�� �ٸ� thread���� ���� �϶�� ���� ���⸸ �ϰ�, 
// �ڱⰡ ���� ���� ������, (main() �Լ��� ������ ���α׷��� ���� ������)
// thread�� �� ���� ��������, ���α׷��� ���� ���� ������, �ſ� ��Ȳ������ ���� �߻��Ѵ�.
// <= �̷��� ���� �����ϱ� ���ؼ� ��ó�� pthread_join()�� ����ؼ� 
//    thread���� ������ ���� ��ٸ��� ���̴�.