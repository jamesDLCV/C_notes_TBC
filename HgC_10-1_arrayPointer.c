#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 10-1. �迭�� �������� ����
// �迭�� �����͸� �����Ӱ� �ٷ�� ���ؼ��� �迭�� ���� ������ ������ �ʿ䰡 �ִ�. 
// �迭�� �������� ���踦 ������, �����ͷ� �迭�� ����ϴ� ����� ���� ����.

int main() {

	// �迭�� �ڷ����� ���� ������ �޸𸮿� �������� �Ҵ��Ѵ�. <= ���� �ڷ����� ����!!!
	// ���� �� �迭 ��Ҵ� ������ �������� �ּҸ� ���� �ȴ�. 
	// 
	// int arr[5];�� �迭�� �޸� 100�������� �Ҵ�ǰ�, 
	// int �� ������ ũ�Ⱑ 4����Ʈ���, 
	// �� �迭 ����� �ּҴ� 100, 104, 108, 112, 116������ �ȴ�. 
	// 
	// �迭 ����� �ּ�    100     104     108     112     116
	// �迭�� arr         |       |       |       |       |       |  
	// �迭 ���          arr[0]  arr[1]  arr[2]  arr[3]  arr[4]  
	//
	// ù ��° ����� �ּҸ� �˸� ������ ����� �ּҵ� ���� �� �� �ְ�,
	// �� �ּҿ� ���� ���� ������ �����ϸ�, ��� �迭 ��Ҹ� ����� �� �ִ�. 
	// 
	// ���� �����Ϸ��� ù ��° �迭 ����� �ּҸ� ���� ����ϱ� ���ؼ�,
	// ������ �������� �迭���� ù ��° �迭 ����� �ּҷ� �����Ѵ�.                  !!!!!
	// 
	//$ ����
	//  �迭���� ù ��° �迭 ����� �ּڰ�
	//  �迭���� ù ��° �迭 ��Ҹ� ����Ų��. 
	//  *arr�� ù ��° �迭 ����̴�. 
	//
	//$ �迭������ �迭 ��� ����ϱ�
	// �ּҴ� ����ó�� �������� �ڷ����� ���� ������ ���� �ִ� Ư���� ���̴�. 
	// ���� �����ο� ������ �� �� ����, ������ ���길 �����ϴ�. 
	// ���� ������ ��ǥ���ε�, ������ ���� ��Ư�� ������� ����ȴ�. 
	//
	// �ּ� + ���� ----> �ּ� + (���� * �ּҸ� ���� ������ ũ��)                   !!!!!
	// 
	// ��) ũ�Ⱑ 4����Ʈ�� int �� ���� a�� �ּ� 100������ 1�� ���� �����?
	//    <= 104�� �ȴ�. 
	//       100 + (1 * 4)   <= �ּ� + (���� * �ڷ����� ũ��)
	//       101�� �ƴϴ�. 
	// 
	//            100  101  102  103   
	// ���� a      |    |    |    |    | 
	// 
	//     &a      a�� �ּڰ� (100����).
	//             a�� ����Ų��. 
	//             int ���� ����Ų�� (a�� int ���̹Ƿ�).
	// 
	//     &a + 1  ----> 100 + (1 * sizeof(int)) ----> 104
	//             int ���� ����Ű�� �ּ� 104����
	//             104�������� 107�������� 4����Ʈ ���� ������ �ּڰ�
	// 
	// �̷� ���� ��ġ�� �迭�� ����� �� �����ϴ�.
	// 
	// �迭���� �ּ��̹Ƿ� ������ ���ʷ� ���ϸ� ���ӵ� �迭 ����� �ּҸ� ���� �� �ְ�,
	// ���⿡ ���� ���� ������ �����ϸ�, ��� �迭 ��Ҹ� ����� �� �ִ�. 
	// 
	// �迭���� �ּҷ� Ȱ���ϴ� ���� ���� ����.
	{
		// �迭���� ���� ������ �����Ͽ� �迭 ��� ���
		int arr[3];
		int i;

		*(arr + 0) = 10;				// arr[0] = 10
		*(arr + 1) = *(arr + 0) + 10;	// arr[1] = arr[0] + 10

		printf("�� ��° �迭 ��ҿ� Ű���� �Է�: ");

		int input = scanf("%d", arr + 2);  // warning �Ķ����� ���� input�� �־� ��

		for (int i = 0; i < 3; ++i) {
			printf("%5d", *(arr + i));	// arr[i]
		}
	}
	// ���)
	// �� ��° �迭 ��ҿ� Ű���� �Է�: 30
	//      10   20   30
	// 
	//            100  101  102  103  104  105  106  107  108  109  110  111
	// �迭�� arr  |    |    |    |    |    |    |    |    |    |    |    |
	//            arr[0]              arr[1]              arr[2]
	// 
	// �迭���� ù ��° �迭 ����� �ּ��̹Ƿ�, �迭���� �ּڰ��� 100�̴�. 
	// (arr + 0)�� ù ���� �迭 ����� �ּ��̹Ƿ� 100�̴�. 
	// 
	// (arr + 0)�� ���� ���� ������ �����ϸ�, ù ��° �迭 ��� ��ü�� �ȴ�. 
	// <= *arr�� �����ϴ�. 
	// <= arr[0]���� �����ϴ�. 
	// 
	// *(arr + 0) == *arr == arr[0]                                        !!!!!
	// 
	// (arr + 1)�� �� ��° �迭 ����� �ּҰ� �ȴ�. <= 104����
	// *(arr + 1)�� ���� ���� ���� ������ �����ϸ�, �� ��° �迭 ��Ҹ� ����� �� �ִ�.
	// 
	// *(arr + 1) == arr[1] 
	// 
	// *(arr + 1) = *(arr + 0) + 10;                                  
	//     arr[1] = arr[0]     + 10;   <= �� ���� ������ ������ �����Ѵ�. 
	// 
	// <= ù ��° �迭 ����� ���� 10�� ���ؼ� �� ��° �迭 ��ҿ� �����Ѵ�. 
	//
	// scanf("%d", arr + 2)
	// scanf("%d", &arr[2]);           <= �� ���� �����ϴ�. 
	// 
	// arr + 2 == &arr[2]
	// 
	// <= �� ��° �迭 ����� ���� Ű����� �Է� �޴´�.  
	//
	// �迭�� ���ȣ []�� ������ ������ '���� ����, ��ȣ, ���ϱ�' ���� ����� ������. 
	// <= �迭 ��ҿ� ����ϴ� ���ȣ�� ������̴�. 
	// 
	// �迭 ��� ǥ����             ������ ����� 
	//     arr[1]      <---->      *(arr + 1)                              !!!!!
	// 
	// �迭 ��Ҹ� ����� ���� ��Ȳ�� ���� ���ȣ�� ������ ����� �� ������ ���� 
	// ��� ���� �ȴ�. Ư���� ��찡 �ƴϸ�, ���ȣ�� ���� ���� ����. 
	// 
	// &arr[2]�� ���� ����, arr + 2�� ���� ���� ������ ���� �� �ִ�. 
	// 
	//$ �迭�� �Ҵ� ������ ����� ������ ������� ����� �� �ִ°�?
	// 
	// ����� �� ������ ����ϸ� �� �ȴ�.                                      !!!!!
	// ���������� ������ �����Ƿ� �������� ������, ������ �� ����� ������ �� ���� �ȴ�. 
	// 
	// eg) �迭 ����� ������ 3�� arr �迭����,
	//     (arr + 3)�� �� ��° �迭 ����� �ּҰ� �ǰ�, 
	//     *(arr + 3)�� �� ��° �迭 ��Ұ� �ȴ�. 
	// 
	//           arr + 0  arr + 1  arr + 2  arr + 3
	// arr �迭  |        |        |        |    ?   | 
	//           arr[0]   arr[1]   arr[2]   arr[3]
	// 
	// �� ��° �迭 ��Ҵ� arr �迭�� �Ҵ�� ������ �ƴϹǷ�, ����ϸ� �� �ȴ�. 
	// ���� �� ������ �ٸ� ������ �迭�� �Ҵ�Ǿ� �ִٸ�, �� ���� �ٲ� ���� �ְ�, 
	// �ü���� �����ϴ� �����̶��, ���α׷��� ���� ����� ���� �ִ�. 
	// 
	// arr[3]�� �迭 ��� ǥ���ĵ� �ᱹ ������ ��������� �ٲ�Ƿ�, 
	// ���������� ����� �� �����ؾ� �Ѵ�. 

	return 0;
}