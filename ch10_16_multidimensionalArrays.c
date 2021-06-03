#include <stdio.h>
#define ROWS 3
#define COLS 4  // 기호적 상수

int sum2d_1(int ar[ROWS][COLS]);        // ROWS의 정보는 컴파일러에 전달X
int sum2d_2(int ar[][COLS], int row);   // ROWS의 정보는 다른 parameter로
                                        // 전달해 줄 수도 있다. 
              // 행의 정보는 전달해 줘 봐야 무시되는 것이다. 
              // 배열의 이름은 변수가 아니라 배열 첫 주소이기 때문에, 
              // 포인터로 변환이 된다.  
              // 주의할 점은 행의 정보만 생략해 줄 수 있고, 
              // 나머지는 써 줘야 한다. 
// 동적 할당에서는 어차피 1차원 포인터를 다차원 배열인 것처럼 쓰기 때문에, 
// 실용적인 측면에서 큰 문제는 없다. 
// C++에서는 용법이 더 쉬워진다. 

// int sum2d_2(int [][COLS], int row); 
              // <= 프로포타입에서 이름 ar을 생략할 수 있다.

// int sum2d_2(int (*ar)[COLS], int row); 
              // ar is a SINGLE pointer to the array of COLS ints
              // COLS의 개수만큼의 원소를 갖는 배열에 대한 싱글 포인터이다. 
              // 이렇게 복잡하게 쓰는 건 선호하지 않는다. 
              // ar[][COLS] 이렇게 쓰면 될 것을 
              // 굳이 (*ar)[COLS] 이렇게 쓸 필요는 없다. 

int sum2d_3(int* ar, int row, int col); // 동적 할당에서 많이 사용하는 방식
              // 실질적으로 다차원 배열을 사용할 때, 많이 사용한다. 
              // C++에서는 보다 편하게 쓸 수 있는 방법이 있다. 
              // deep learning이나 computer vision에서는 
              // 이런 식으로 다차원의 배열을 사용한다.
              //  
// int sum2d_3(int*, int, int); 
              // <= 이것도 마찬가지로 변수의 이름 정도는 생략할 수 있다. 

int main() {

    int data[ROWS][COLS] = {    // 컴파일 때 배열의 사이즈가 결정된다.
                                {1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12} };   

    printf("%d\n", data[2][3]);

    int* ptr = &data[0][0];

    // 포인터 ptr 하나, 즉 data[0][0]의 첫 번째 원소에 대한 포인터를 이용해서
    // 포인터 연산을 통해서 접근을 한다. 
    printf("%d\n", *(ptr + 3 + COLS * 2));  // 컬럼의 개수만큼 점프를 한다.
                      // 2차원 array를 1차원 array인 것처럼 접근할 수 있다. 
    // 동적 할당은 모두 1차원으로 받아 온다. 
    // 1차원으로 받아온 array를 
    // 마치 2차원, 3차원, 4차원 array인 것처럼 사용한다.  

    printf("Sum of all elements = %d\n", sum2d_1(data));
    printf("Sum of all elements = %d\n", sum2d_2(data, ROWS));
    printf("Sum of all elements = %d\n", sum2d_3(&data[0][0], ROWS, COLS));

    return 0;
}

int sum2d_1(int ar[ROWS][COLS]) {

    int r, c, tot = 0;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];
    return tot;
}

int sum2d_2(int ar[][COLS], int row) {

    int r, c, tot = 0;
    for (r = 0; r < row; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];
    return tot;
}

// row와 colums을 변수로 넘겨주고 있다. 
// symbolic 상수 같은 것을 미리 선언해 둘 필요가 없다. 
// 동적 할당에서는 이렇게 사용한다. 
// *ar은 1차원 배열의 포인터 혹은 큰 메모리 덩어리, 대표 주소, 첫 번째 주소로
// 이해하면 된다. 
// *(ar + c + col * r); 이런 식으로 접근한다는 것을 알아 둬라. 
// *(ar + c + col * r); 는 ar[c + col * r];와 동일하다. 
int sum2d_3(int* ar, int row, int col) {

    int r, c, tot = 0;
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)
            tot += *(ar + c + col * r); // ar[c + col * r] 
    return tot;
}

/*
        In higher demensions,
        you may omit the value in the left-most bracket

        int my_function(int ar[][3][5][8], int rows);
        // 맨 왼쪽의 원소 개수는 비워 두고, 변수로 넣어 주는 것이 일반적이다.

        int my_function(int (*ar)[][3][5][8], int rows);
*/

// tensorflow에서는 고차원 배열을 사용한다. 

// 지금까지 다차원 배열을 함수에 전달하는 방법을 살펴 봤다. 
// 다차원 배열의 메모리 구조는 결국은 1차원 배열의 메모리 구조와 동일한데,
// 1차원 배열을 다차원인 것처럼 사용하는 것에 대해 살펴 봤다. 
// 뒤에서 동적 할당 받은 메모리를 다차원 배열인 것처럼 사용하는 방법에 대해서
// 살펴 볼 것이다. 
