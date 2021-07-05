#include <stdio.h>

// 선택 정렬 Selection Sort
// 오름차순, 내림차순으로 정렬하는 것이다. 

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main() {
    /*
        Selection Sort Algorithm 
        https://www.geeksforgeeks.org/selection-sort/
    */

    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);      // ascending order
    printArray(arr, n);

    return 0;
}

void swap(int* xp, int* yp) {
    int tmp;
    tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; ++i) {
        min_idx = i;
        for (j = i  + 1; j < n; ++j) {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

//// 이렇게 하면 swap() 함수는 필요없다. 
//void selectionSort(int arr[], int n) {
//    int i, j, min_idx;
//    for (i = 0; i < n - 1; ++i) {
//        min_idx = i;
//        for (j = i + 1; j < n; ++j) {
//            if (arr[min_idx] > arr[j])
//                min_idx = j;
//        }
//        int tmp = arr[i];
//        arr[i] = arr[min_idx];
//        arr[min_idx] = tmp;
//    }
//}

////이렇게 하면 비교를 하면서 계속 복사를 해야 하므로, 느리다.
//void selectionSort(int arr[], int n) {
//    int i, j, min_idx;
//    for (i = 0; i < n - 1; ++i) {    
//        for (j = i + 1; j < n; ++j) {
//            if (arr[i] > arr[j]) {
//                swap(&arr[j], &arr[i]);
//            }
//        }        
//    }
//}


