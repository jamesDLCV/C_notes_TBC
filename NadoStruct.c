#include <stdio.h>

// �� �� ���簡 �Ǿ�� from ���� �ڵ�
// ����ü

// struct, ��� ���� ������ ����α����� ���� �ָ� �ȴ�.
// �׷��� GameInfo��� ����ü�� ������� ���̴�. 
struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame;	// ���� ��ü ����
};

// typedef�� ����ü �տ� ���� �� �ִ�. 
// ������ ���� ����Ѵ�. �߰�ȣ �ڿ� GAME_INFO;�� �ٿ� ���. 
// struct GameInfomation�� GAME_INFO���� ġȯ�ϰڴ�. 
typedef struct GameInfomation {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame;	// ���� ��ü ����
} GAME_INFO;

// ������ ���� �ٷ� ������ �ٿ��� ����ϸ� �����ϴ�. 
typedef struct {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame;	// ���� ��ü ����
} GAME_INFO2;

int main_struct_nado() {

	// ���� ���
	// �̸�: ��������
	// �߸� ����: 2017��
	// ����: 50��
	// ���ۻ�: ����ȸ��

	char* name = "��������";
	int year = 2017;
	int price = 50;
	char* company = "����ȸ��";

	// �� �ٸ� ���� ���
	// �̸�: �ʵ�����
	// �߸� ����: 2017��
	// ����: 1000��
	// ���ۻ�: �ʵ�ȸ��

	char* name2 = "�ʵ�����";
	int year2 = 2017;
	int price2 = 1000;
	char* company2 = "�ʵ�ȸ��";

	// ����� ������ �������� ���� ���� ������ �� �ִ�. 
	// ���� �ִ� ������ �ϳ��� ������ �Ǹ� ���ڴ�. 
	// �̶� �ʿ��� ���� ����ü�̴�. 
	
	// ����ü ���
	// struct GameInfo������ �ڷ����̶�� ���� �ǰ�,
	// ���� gameInfo1�� �������̶�� ���� �ȴ�. 
	struct GameInfo gameInfo1;
	//struct GameInfo gameInfo2;	// <= �̷��� gameInfo2�� ó���� �� �ִ�. 

	gameInfo1.name = "��������";
	gameInfo1.year = 2017;
	gameInfo1.price = 50;
	gameInfo1.company = "����ȸ��";

	// ����ü ���
	printf("-- ���� ��� ���� --\n");
	printf("���Ӹ�: \t%s\n", gameInfo1.name);
	printf("�߸� ����: \t%d\n", gameInfo1.year);
	printf("����: \t\t%d\n", gameInfo1.price);
	printf("���ۻ�: \t%s\n", gameInfo1.company);
	printf("\n");

	// ����ü�� �迭ó�� �ʱ�ȭ
	struct GameInfo gameInfo2 = { "�ʵ�����", 2017, 1000, "�ʵ�ȸ��" };
	printf("-- �� �ٸ� ���� ��� ���� --\n");
	printf("���Ӹ�: \t%s\n", gameInfo2.name);
	printf("�߸� ����: \t%d\n", gameInfo2.year);
	printf("����: \t\t%d\n", gameInfo2.price);
	printf("���ۻ�: \t%s\n", gameInfo2.company);

	// ����ü �迭
	// �� �� ȸ���� ������ �迭�� ����. 
	struct GameInfo gameArray[2] = {
		{ "��������", 2017, 50, "�ʵ�ȸ��" },
		{ "�ʵ�����", 2017, 1000, "�ʵ�ȸ��" }
	};
	
	// ����ü ������
	struct GameInfo* gamePtr;	// �̼Ǹ�
	gamePtr = &gameInfo1;

	printf("\n-- �̼Ǹ��� ���� ��� ���� --\n");
	//printf("���Ӹ�: \t%s\n", (*gamePtr).name);	// *ptr�� ����, (*gamePtr).name
	//printf("�߸� ����: \t%d\n", (*gamePtr).year);
	//printf("����: \t\t%d\n", (*gamePtr).price);
	//printf("���ۻ�: \t%s\n", (*gamePtr).company);

	printf("���Ӹ�: \t%s\n", gamePtr->name);		 
	printf("�߸� ����: \t%d\n", gamePtr->year);
	printf("����: \t\t%d\n", gamePtr->price);
	printf("���ۻ�: \t%s\n", gamePtr->company);

	// ���� ��ü ���� �Ұ�
	gameInfo1.friendGame = &gameInfo2;	// �ּҸ� ����Ű�� �Ѵ�. 
	printf("\n-- ���� ��ü�� ���� ��� ���� --\n");
	printf("���Ӹ�: \t%s\n", gameInfo1.friendGame->name);
	printf("�߸� ����: \t%d\n", gameInfo1.friendGame->year);
	printf("����: \t\t%d\n", gameInfo1.friendGame->price);
	printf("���ۻ�: \t%s\n", gameInfo1.friendGame->company);

	// typedef
	// �ڷ����� ������ �����Ѵ�. 
	int i = 1;
	typedef int ����;
	typedef int �Ǽ�;

	���� �������� = 3;		// int i = 3;
	�Ǽ� �Ǽ����� = 3.23f;	// float f = 3.23f;

	printf("\n\n��������: %d, �Ǽ�����: %.2f\n\n", ��������, �Ǽ�����);

	typedef struct GameInfo ��������;		// ���������� ������ ���� �� �ִ�. 
	�������� game1;
	game1.name = "�ѱ� ����";
	game1.year = 2015;
	game1.price = 250;
	game1.company = "meTooCorporation";

	printf("\n-- typedef game1 ��ü�� ���� ��� ���� --\n");
	printf("���Ӹ�: \t%s\n", game1.name);
	printf("�߸� ����: \t%d\n", game1.year);
	printf("����: \t\t%d\n", game1.price);
	printf("���ۻ�: \t%s\n", game1.company);

	// ����ü �տ� typedef�� ���̰�, �������� ���� GAME_INFO�� ���� ���. 
	GAME_INFO game2;
	game2.name = "�ѱ� ����2";
	game2.year = 2016;
	game2.price = 550;
	game2.company = "meThreeCorporation";

	printf("\n-- typedef game2 ��ü�� ���� ��� ���� --\n");
	printf("���Ӹ�: \t%s\n", game2.name);
	printf("�߸� ����: \t%d\n", game2.year);
	printf("����: \t\t%d\n", game2.price);
	printf("���ۻ�: \t%s\n", game2.company);

	// (GAME_INFO ����) struct GameInfomation�� �� ���� �ִ�. 
	struct GameInfomation game3;
	game3.name = "�ѱ� ����3";
	game3.year = 2017;
	game3.price = 750;
	game3.company = "meFourCorporation";

	printf("\n-- typedef game3 ��ü�� ���� ��� ���� --\n");
	printf("���Ӹ�: \t%s\n", game3.name);
	printf("�߸� ����: \t%d\n", game3.year);
	printf("����: \t\t%d\n", game3.price);
	printf("���ۻ�: \t%s\n", game3.company);

	// typed struct {} GAME_INFO2;
	GAME_INFO game4;
	game4.name = "�ѱ� ����4";
	game4.year = 2018;
	game4.price = 950;
	game4.company = "meFiveCorporation";

	printf("\n-- typedef game4 ��ü�� ���� ��� ���� --\n");
	printf("���Ӹ�: \t%s\n", game4.name);
	printf("�߸� ����: \t%d\n", game4.year);
	printf("����: \t\t%d\n", game4.price);
	printf("���ۻ�: \t%s\n", game4.company);

	return 0;
}

// ����ü��� ���� ������� �� �ٸ����� ����� �Ϲ� ������ ���� ����ϴ�. 
// ����ü�� �ִ� ������ �����ϱ� ���ؼ��� . ���� ����Ѵ�. 
// ����ü �������� ������, ����ü�� �ִ� ������ �����ϱ� ���ؼ� ->�� ����Ѵ�. 
// 
// ����ü �ȿ��� �Ȱ��� ����ü�� ������ ���� �� �ִ�. 
// ���� ����ȸ�� �����ε� ģ���� ȸ���� �ʵ�ȸ���� ���ӵ� �Ұ��ϰ� �ʹٸ�, 
// �ڱⰡ ���� ����ü ���� �ڱ� ����ü�� �ٽ� �� �� �����Ѵ�. 
//	(������ ����ü ������ friendGame)
// 
// gameInfo1.friendGame = &gameInfo2;����
// friendGame�̶�� ����ü ��ü�� �������̴�. 
// gameInfo1.friendGame�� ����Ű�� ���� &gameInfo2�̹Ƿ�
// gameInfo2�� ������ �ִ� ������ ����� ���̴�. 
// 
// struct GameInfo �̷��� �� �ַ��� �� ������. 
// <= typedef�� ����� �� �ִ�. 
// 
// typedef struct GameInfo ��������;
// <= struct GameInfo�� ����������� ������ �޾� �޶�. 
//    ���ĺ��ʹ� ���������� ������ ���� �� �ִ�. 
// 
// �� ��� ���� �� �ٸ� ������� ���� �� �ִ�. 
// ����ü �տ� typedef�� ���̰� �������� ����ü�� ������ ���� �ָ� �ȴ�. 
// <= ���� ���õ� �ִ�. 