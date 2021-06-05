#include <stdio.h>
#define ROWS 3
#define COLS 4


int sum2d_4(int row, int col, int ar[row][col]);

int main() {
	
	//int n = 5;
	//float my_arr[n];
	
	int n, i;
	
	printf("Input array length: ");
	scanf("%d", &n);
	
	float my_arr[n];	// Note: cannot change length after declaration
	
	// 배열을 선언할때는 symbolic constant나 literal을 넣어줘야 했다.
	// compile time에 알 수 있는 값만 넣어 줘야 했다.  
	// 하지만 VALs에서는 된다.
	// 이거보다는 동적할당을 더 많이 사용한다 
	  
	
	for (i = 0; i < n; ++i)
		my_arr[i] = (float)i;
		
	for (i = 0; i < n; ++i)
		printf("%f\n", my_arr[i]);
	
	int data[ROWS][COLS] = {
				{ 1, 2, 3, 4 }, 
				{ 5, 6, 7, 8 }, 
				{ 9, 10, 11, 12 }
	                   		    	};
		
	printf("%d ", sum2d_4(ROWS, COLS, data));
	
	
	return 0;
}

// it's more simple way than the way using macro. 
int sum2d_4(int row, int col, int ar[row][col]) {
	
	printf("%zd %p\n", sizeof(ar), ar);
	printf("%zd %p\n", sizeof(ar[0]), ar[0]);
	int r, c, tot = 0;
	
	for (r = 0; r < row; r++
		for (c = 0; c < col; c++)
			tot += ar[r][c];
			 
	return tot;
}
