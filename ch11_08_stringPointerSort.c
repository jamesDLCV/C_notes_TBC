#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // strcmp()를 이용하면 문자열간의 순서를 정할 수 있다

// 앞 강의에서 공부한 선택 정렬을 이용하여,
// 문자열을 정렬해 본다. 
// 문자열 자체를 정렬하기보다는, 
// 문자열의 포인터를 정렬할 것이다. 
// 문자열 자체를 정렬하면, 문자열을 계속 복사해 줘야 한다. 
// 앞 강의에서도 min_idx만 가지고 다녔다. 
// 값 자체를 복사하게 되면, 연산량이 더 많아지기 때문이다. 
// 연산량을 조금이라도 줄이기 위해서  min_idx만 가지고 비교를 했다.
// 이번에는 포인터를 가지고 다니면서 비교를 한다. 복사를 하지 않는다. 
// 
void swap(char** xp, char** yp);    //Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {
    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" }; 
            // 문자열의 배열,
            // 문자열에 대한 포인터의 배열
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);
    selectionSort(arr, n);      // ascending order

    printStringArray(arr, n);

    return 0;
}

void swap(char** xp, char** yp) {
    int tmp;
    tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void printStringArray(char* arr[], int size) {
    int i;
    for (i = 0; i < size; ++i)
        puts(arr[i]);
    printf("\n");
}

void selectionSort(char* arr[], int n) {
    int i, j, min_idx;
    // one bye one move boundary of unsorted subarray
    for (i = 0; i < n - 1; ++i) {
        // Find the minimum element in unsorted array
        min_idx = i; 
        for (j = i + 1; j < n; ++j) {
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        /*char* tmp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = tmp;*/
        // 위 이중 포인터는 아래의 것과 동일하게 작동한다. 

        swap(&arr[i], &arr[min_idx]);
    }
}


