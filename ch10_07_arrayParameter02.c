#include <stdio.h>

double average(double data_arr[], int n) { 

    printf("Size = %zd in function average\n", sizeof(data_arr));

    double avg = 0.0;
    for (int i = 0; i < n; ++i) {
        avg += data_arr[i];
    }
    avg /= (double)n;
    
    return avg; 
}

int main() {
    double arr1[5] = { 10, 13, 12, 7, 8 };
    //double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    double arr2[3] = { 1.8, -0.2, 6.3 };  // size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));   // 40
    printf("\n");

    printf("Address = %p\n", arr2);
    printf("Size = %zd\n", sizeof(arr2));   // 24
    printf("\n");

    // array의 평균값을 구해 보자.    

    printf("Avg = %f\n\n", average(arr1, 5));
    printf("Avg = %f\n\n", average(arr2, 3));
    printf("\n");
    return 0;
}

