#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// qsort()

// qsort() �Լ� ������ ���� ����
//
// �Լ� �������� ������ �� �� ���� �ְ� ���� ���� ���ؼ�
// qsort(), quick sort �Լ��� ���ؼ� ���� ���� ���·� ���� ���ڴ�.  
//
// �⺻���� qsort() �Լ��� ����� ��� ����� ���ؼ� ������ �ϰ�, 
// �״��� ������ Ǯ�� ������ �ϰڴ�. 

//TODO: try increasing/decreasing order
int compare(const void* first, const void* second) {
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main() {
	int arr[] = { 8, 2, 5, 3, 6, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	

	return 0;
}

// compare()��� �Լ��� �ִ�. 
// compare()��� �Լ��� �԰��� ������ �ִ�. 
	/*
	int compare(const void* first, const void* second) {
	 <= void Ÿ���� �����Ͱ� �� ���� ������ �� �ִ�. 
	    �츮�� �ٷ���� �����Ͱ� �������� �����̱� ������, 
		if (*(int*)first > *(int*)second)
		 <= int pointer�� casting�� �ϰ�, �״��� indirection�� �ؼ�, 
		    �񱳸� �ϰ� �ִ�. 
			return 1;
		else if (*(int*)first < *(int*)second)
			return -1;
		else
			return 0;
	}
	*/
//
// ������ ������ ����. 
	/*
	int arr[] = { 8, 2, 5, 3, 6, 11 };
	 <= ���� �����Ͱ� �ִ�. ������ ���� ������ �ִ� �����̴�. 
	    ���α׷����� �ϴ� ����, �������� ������ ���������̳� ������������ 
		����� ��� �ϴ� ��찡 ���� �ִ�. 
		���߿� �ڷ� ������ ������ �� qsort()�� ���� ������ �� ���̴�. 
		���� �˷θ��� ���� �͵��� ���� Ȱ���� ���̴�. 

	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare);
	 <= sorting�� �����̴�. ������ ���� �ִ� ���̴�. 
	    qsort�� quick sort�̴�. 
	    ���� sorting�ϴ� �˰��� �߿��� ���� ���� �˰��� �� �ϳ��̴�. 
		qsort() �˰����� #include <stdlib.h>�� �̹� ������ �� �ִ�. 
		C���� �����ϰ� ����� �� �ֵ��� �غ� �� �ִ�. 
	<= qsort() �Լ��� ����ϱ� ���ؼ��� 
	   ��Ģ�� ���缭 compare() �Լ��� ������ ��� �Ѵ�. 
	   �� �� ���ϰ� int arr[] �迭�� ���ҵ��� ������ �ִ� �Լ��� ����� �� �ٵ�, 
	   �� �̷��� ������ �ϴ°���� ������ ���� �ִ�. 
	   �׷��� �̷��� �� �ָ�, int ���� �ٸ� �ڷ����� ������ ���� ����� �� �ִ�. 
	   <= �̰��� ���� �����̴�. 	    

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	*/
// 
// compare ���Ѵٴ� ���� �Լ��� �����, 
// �̰��� �Լ� �����ͷ� �־� �ָ�, 
// qsort() �Լ��� compare �Լ��� �Լ� �����ͷ� ����ؼ� ������ �ϰ� �ȴ�. 
// 
// ������ �����Ų ���� ���� ���ڿ��� ū ���ڷ� �����ϴ� �������� �����̾���. 
// compare() �Լ����� �ε�ȣ�� �ݴ� �������� �ٲٸ�, �������� ���ķ� �ٲ��. 
// 
// compare() �Լ��� ��� ������� �ִ��Ŀ� ���� ������ ����� �޶�����. 
	/*
	int compare(const void* first, const void* second) {
		if (*(int*)first > *(int*)second)
			return 1;
		else if (*(int*)first < *(int*)second)
			return -1;
		else
			return 0;
	}
	*/
//  <= �� compare() �Լ��� ������ ����� �Լ��� ���� ���ǿ��� �ٷ����. 
//     <= ���ڿ��� ���ϴ� �Լ� strcmp() �Լ��� �־���. ����� �����̴�. 
// 
// compare() �Լ��� ����� �� compare() �Լ��� ���ؼ� qsort()�� �����Ű��, 
// ������ �ǵ��� qsort() �Լ��� ���ο� �̹� ������ �� �ִ�. 
// 
// qsort(arr, n, sizeof(int), compare); �� ��Ģ�� ���缭 ������ �ϸ�,
// ���ϴ� �ڷ����� ������ �� �� �ִ�. 
// 
// �� ���� ���� ������ �� ����. 
// �������� int�� ������ �� �ִµ� float ������������ �ٲپ� ���ƶ�.
// <= �� �ڵ忡�� int�� float���� �ٲٰ� �迭�� ���� float���� �ٲ� �ָ� �ȴ�. 