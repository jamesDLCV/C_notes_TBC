#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �͸� ����ü, Anonymous Structures
//
// �տ��� ����ü�� ����ü�� ����� ����ϴ� ����� ���� �ô�. 
// <= ��ø�� ����ü ��� nested structure member

struct names {
	char first[20];
	char last[20];
};

struct person {
	int id;
	struct names name;	// nested structure member
};

struct person2 {
	int id;
	struct { char first[20]; char last[20]; };	// anonymous structure
};

int main() {

	struct person ted = { 123, {"Bill", "Gates"} };
	struct person ted3 = { 125, "Robert", "Hand" };

	puts(ted.name.first);
	puts(ted3.name.first);

	struct person2 ted2 = { 124, {"Steve", "Wozniak"} };
	struct person2 ted4 = { 124, "James", "Hwang" };	// also works

	puts(ted2.first);
	puts(ted4.first);

	return 0;
}

// ����ü�� ����,
	/*
	struct person {
		int id;
		struct names name;	// nested structure member
	};
	*/
// <= �� ����ü�� �̸� person�� �������� ��Ī�� tag�̴�. 
//	
// nested structure member�� ����� ����
// (�� ��������) struct person�� struct names �ȿ� 
// first, last ����� ���� ������ �����ؾ� �ߴ�. 
//  
	/*
	struct person ted = { 123, {"Bill", "Gates"} };
	struct person ted3 = { 125, "Robert", "Hand" };

	puts(ted.name.first);
	puts(ted3.name.first);
	*/
// <= ted.name.first�� ���� dot operators�� �� �� ����ؼ� �����ߴ�. 
// 
// �׷���, 
	/*
	struct person2 {
		int id;
		struct { char first[20]; char last[20]; };	// anonymous structure
	};
	*/
// <= person2��� ����ü������, structure�� structure �ȿ� ���� ���� 
//    struct person�� �����ѵ�, ����ü�� �̸��� ����. 
// 
//    struct { char first[20]; char last[20]; };
//    <= ���� �ٿ� ���� struct�� tag�� �پ� ���� �ʴ�. �̸��� ����. 
//       �̸��� �����Ƿ� anonymous structure��� �Ѵ�. 
//       �̸��� ���� ����� ������ �ִ� �����̴�. 
// 
//	  struct { char first[20]; char last[20]; }; �� ������ 
//    ���߿� ����ü�� ������ �ȴ�. 
// 
// struct person2 ted2 = { 124, {"Steve", "Wozniak"} };
// puts(ted2.first);
// <= ����� ������ �� �̷��� ted2.first�� ���� ������ �� �ִ�. 
//    
// nested structure�� ��쿡��, 
// ted, nested structure name, �״��� ����� ���� ������ ������ �ƴ�. 
// <= member access�� �� �� �ؾ� �ߴ�. 
// 
// puts(ted2.first); �� member access�� �� ���� �ϸ� �Ǵ� ������ �����̴�. 
// 
// �ʱ�ȭ�ϴ� �����, 
// struct person ted = { 123, {"Bill", "Gates"} };
// struct person ted3 = { 125, "Robert", "Hand" };
// 
// struct person2 ted2 = { 124, {"Steve", "Wozniak"} };
// struct person2 ted2 = { 124, "Steve", "Wozniak" };
// <= ��� ����� ���δ�. 
// 
// anonymous structure�� �̸��� ���� ����(tag�� ���� ����)��, 
// member�� ���� �����ؼ� ����� �� �ִ� ����̴�. 
// 
// �͸� ����ü�� ���ؼ� ������ ���� �ô�. 