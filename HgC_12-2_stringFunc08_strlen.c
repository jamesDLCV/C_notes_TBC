#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//$ ���� ����� strlen() �Լ�
//$ ���� ����� strcmp() �Լ�

int my_strlen(char* ptr_s);
int my_strcmp(char* ptr_a, char* ptr_b);

int main() {

	// my_strlen()
	char str[80] = "straw";
	char str2[80] = "pineapple";

	int cnt = my_strlen(str);
	int cnt2 = my_strlen(str2);

	printf("%s�� ������ %d�Դϴ�.\n", str, cnt);
	printf("%s�� ������ %d�Դϴ�.\n", str2, cnt2);	
	puts("");

	// my_strcmp()
	char str3[80] = "pear";
	char str4[80] = "peach";

	printf("������ ���߿� ������ ���� �̸�: ");

	if (my_strcmp(str3, str4) > 0)	// str3�� str4���� ũ��
		printf("%s\n", str3);
	else							// str3�� str$���� ũ�� ������,
		printf("%s\n", str4);

	return 0;
}

int my_strlen(char* ptr_s) {    // ptr_s�� �迭���� �����ϰ� 
									// ù ��° �迭 ��Ҹ� ����Ŵ.
	int cnt = 0;				// ���ڸ� ���� ���� ����
	while (*ptr_s != '\0') {	// ptr_s�� ����Ű�� ���ڰ� �� ���ڰ� �ƴϸ�, 
		cnt++;
		ptr_s++;
	}
	
	return cnt;					// ��ü ���� �� ��ȯ
}

int my_strcmp(char* ptr_a, char* ptr_b) {

	while ((*ptr_a == *ptr_b) && (*ptr_a != '\0')) { // �� ���ڰ� ������
		ptr_a++;										// �� ���ڰ� �ƴ� ���
		ptr_b++;
	}

	// �ݺ��� ���� �� ���������� �� ���ڰ� �ٸ��ų� �� �� �� ������
	if (*ptr_a > *ptr_b) return 1;
	else if (*ptr_a < *ptr_b) return -1;
	else return 0;
}

//$ �ٽ� ����Ʈ
//
// strcpy() ���ڿ��� ���� �޴� ���� �迭�̾�� �Ѵ�. 
// strcat() ���ڿ��� ���ʷ� ���� ���� �ʱ�ȭ�� �ؾ� �Ѵ�. 
// �迭�� ����� ���� ���ڿ��� ���̸� �˰� ���� �� strlen() �Լ��� ����. 
// strcmp() ���ڿ��� ���� ��� ������ Ȯ���� �� �ִ�. 
//
// strcpy(str1, str2);	���ڿ� str2�� str1�� ����						!����
// strlen(str);			���ڿ� str�� ����(���� ��)�� ���ؼ� ��ȯ		!���� ���
// strcat(str1, str2);	���ڿ� str2�� str1 ���ڿ� �ڿ� �̾ ����		!���̱�
// strcmp(str1, str2);	���ڿ� str1�� str2���� ũ�� 1 ��ȯ		    !��
//                             str1�� str2���� ������ -1 ��ȯ
//                             str1�� str2�� ���� ���ڿ��̸� 0 ��ȯ