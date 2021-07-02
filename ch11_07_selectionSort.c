#include <stdio.h>

// 선택 정렬 Selection Sort
// 오름차순, 내림차순으로 정렬하는 것이다. 

int main() {
    /*
        Selection Sort Algorithm

        Youtube search "Selection Sort", "CS50"

        64 25 12 22 11 (min_idx = 0)
           64          (min_idx = 0)
           25          (min_idx = 1)
              25       (min_idx = 1)
              12       (min_idx = 2)
                 12    (min_idx = 2)
                    12 (min_idx = 2)
                    11 (min_idx = 4)
        11 25 12 22 64 (swap arr[0] and arr[4])    

        11 25 12 22 64 (min_idx = 1)
              25       (min_idx = 1)
              12       (min_idx = 2)
                 12    (min_idx = 2)
                    12 (min_idx = 2)
        11 12 25 22 64 (swap arr[1] and arr[2])    
        ...
    */

    // 이렇게 작동이 되는구나 하는 것은 어떤 자료를 보고 해도 되지만, 
    // 코드는 직접 구현해 보기를 바란다. 

    char ch[5] = { 64, 25, 12, 22, 11 };
    int i, j, tmp;

    for (i = 0; i < (sizeof(ch) - 1); ++i) {
        for (j = i + 1; j < sizeof(ch); ++j) {
            if (ch[i] > ch[j]) {
                tmp = ch[i];
                ch[i] = ch[j];
                ch[j] = tmp;
            }
        }            
    }

    for (i = 0; i < 5; ++i)
        printf("%d ", ch[i]);

    return 0;
}