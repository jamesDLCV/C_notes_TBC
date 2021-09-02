#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Structures, ����ü�� �⺻���� ����
// ����ü ����, �ʱ�ȭ, �ɹ� ���� ����� ���� ���ַ� ���� ����. 

#define MAX 41

struct person	/* Person is a tag of structure */
{
	char name[MAX];		// member
	int age;			// member
	float height;		// member
};

// �ڵ� ��Ÿ���� ���� �����ؼ� �����Ѵ�. {}�� ��ġ, �빮�� tag Ȥ�� �ҹ��� tag ��.
/*
struct Person {
	...
};
*/

int main() {

	int flag;	// Receives return value of scanf()

	/* Structure variable */
	struct person genie;

	/* dot(.) is structure membership operator (member access operator, member operator*/
	strcpy(genie.name, "Will Smith");
	//strncpy(genie.name, "Will Smith", MAX);

	genie.age = 1000;

	// dot(.) has higher precedence than &
	flag = scanf("%f", &genie.height);	// &(genie.height)
	printf("%f\n", genie.height);

	/* Initialization */

	struct person princess = { "Naomi Scott", 18, 160.0f };

	struct person princess2 = {
		"Naomi Scott",
		18,
		160.0f
	};

	strcpy(princess.name, "Naomi Scott");
	princess.age = 18;
	princess.height = 160.0f;

	/* Designated initializers */

	struct person beauty = {
		.age = 19,
		.name = "Bell",
		.height = 150.0f
	};

	//struct person beauty = { .age = 19, .name = "Bell",	.height = 150.0f };

	/* Pointer to a structure variable */

	struct person* someone;

	someone = &genie;
	//someone = (struct Person*)malloc(sizeof(struct Person)); // and free later

	/* Indirect member(ship) operator (or structure pointer operator) */

	someone->age = 1001;	// arrow(->) operator
	printf("%s %d\n", someone->name, (*someone).age);

	/* Structure declaration in a function */

	struct book
	{
		char title[MAX];
		float price;
	};

	/* No tag */

	struct {
		char farm[MAX];
		float price;
	} apple, apple2;

	strcpy(apple.farm, "Trade Joe");
	apple.price = 1.2f;

	strcpy(apple2.farm, "Safeway");
	apple2.price = 5.6f;

	/* typedef and structure */

	typedef struct person my_person;

	my_person p3;

	typedef struct person person;

	person p4;

	typedef struct {
		char name[MAX];
		char hobby[MAX];
	} friend;

	friend f4;

	return 0;
}

// struct person
// <= struct�� structure�� �����̴�.
//    person�� ����ü�� �̸����� ����ϰ� ���� �ܾ ���� �ȴ�. 
//    person�� ����ü�� tag��� �Ѵ�. <= �̸����� �����ϸ� �ȴ�. 
//    ������ �ν��ڸ� ���ϴ� �Ͱ� �Ȱ��� ��Ģ�� ����ȴ�. 
// 
// �״���, 
// �߰�ȣ �ȿ� ����� ������ �ָ� �ȴ�. 
// <= ����ü person�� ����� ���� ������ �� �ش�. ���� �� �ش�. 
//    ����ü �ȿ��� ����� ������ �ִ� ���������δ� �޸𸮸� ���� �ʴ´�. 
//	  ����ü�� ������ ������ �� ��, �޸𸮸� ���� �ȴ�. 
//    ����ü�� ����� �����ϴ� �ܰ迡���� �޸𸮸� ���� �ʴ´�. 
//    �̷� ������ ����ü�� ������� ���̶�� ���� �� �δ� ���̴�. 
//    ��Ű�� ���� ���� ��Ű Ʋ�� ����� �δ� ���̴�. ��縸 ��� �δ� ���̴�. 
//    
// ����ü�� �޸𸮿� ���ؼ��� ���� ���ǿ��� �ٷ��. 
// 
// C++�� ����, ����ü�� ��ü template�� ����� Ŭ������ �ִµ�, 
// Ŭ������ ���� ���� ù ���ڸ� �빮�ڷ� ���� �� �Ϲ����̴�. 
// Ŭ������ structure�� ���缺�� ���� �ִ�. 
// 
// C++���� ����ü�� ����� ���� tag�� ù ���ڸ� �빮�ڷ� ����ϴ� ��찡 ����. 
// �̰͵� ������ �����ؼ� ������ �����̴�. ������ ���������� ������ ���� �ʴ�. 
// 
// int flag;	// Receives return value of scanf()
// <= scanf()�� ��ȯ���� �ޱ� ���ؼ� ������ �����̴�. 
// 
// ����ü�� ���� �����ϴ� ���:
// struct person genie; 
// <= struct�� �� �ش�. �� ���� tag�� ���δ�. ���⿡�� tag�� person(����ü�� �̸�),
//    struct person �� �� ���� ���ļ� ��ġ �ڷ����� ��ó�� ����Ѵ�. 
//    strucut person (�ڷ���) �ڿ� genie ������ �����Ѵ�. 
//    <= struct�� ��� name, age, height�� �޸𸮰� genie ������ �����ϴ� ����
//       �Ҵ��� �ȴ�. 
// 
// ����ü �ȿ� name, age, height �� ���� ����� �ִ�. 
// �� ����� �����ؼ� ����ؾ� �� �ٵ�, 
// �� �� ����ϴ� �����ڰ� structure membership operator�̴�. 
// �� �� ��������� ���� member access operator��� �Ѵ�.
// (����� acess�ϱ� ���� ������) <= �ٿ��� member operator��� �Ѵ�.
// 
// genie.name <= �̷��� struct�� name ����� �����Ѵ�. 
// 
// strcpy(genie.name, "Will Smith");
// strncpy(genie.name, "Will Smith", MAX);
// <= �� �� ���� ��� ����� �� �ִ�.  
//    name�� char�� �迭�̾����Ƿ�, strcpy �Ǵ� strncpy�� ����� �� �ִ�. 
//    ���ڿ��� �ٷ�� ������ ���� ���ǿ��� �ٷ����. 
// 
// genie.age = 1000; <= age�� int�̹Ƿ� �̷��� 1000�̶�� ���� ������ �� �� �ִ�.
// <= age�� ���콺�� hover over�� ����, int person::age��� ���. 
//    �̴� age��� ������ person�� ����ü��� ���̴�. 
//    age�� genie��� ������ ���ؼ� �����ϰ� �ִ�. 
// 
// name, age, height �� ���� ������ �ϳ��� structure�� ������� �ְ�, 
// �� structure ���� �ȿ��� ������ ����� �����ؼ� ����ϴ� �����̴�. 
// �׷��Ƿ� membership operator�� ���ؼ� �����ؾ� �Ѵ�. 
// 
// ���� ���ǿ��� �޸� ������ �ٷ��. 
// 
// dot(.) has higher precedence than &
// <= dot operator�� &(address of) operator���� ������ �켱 ������ ����. 
// 
// &genie.height
// <= height ����� ���� ������ �� �Ŀ� �ּҸ� ������ �´�. 
//    &(genie.height)�� �����ϴ�.
// 
// ����ü ���� structure variable�� �ʱ�ȭ�ϴ� ���
// 
// struct person princess = { "Naomi Scott", 18, 160.0f };
// <= princess��� ����ü ������ �����ϸ鼭 ���ÿ�, �ʱ�ȭ���� �ϰ� �ִ�. 
//    structure variable�� �̸��� princess�̴�. 
//    �̷��� { } �ȿ���ó�� �ʱ�ȭ�� �� �ִ�. 
//    �迭�� ����� ���������, �迭������ ������ �ڷ����� ��� �����ؾ� �Ѵ�. 
//    �� int �迭�̶�� ���Ұ� ��� int���� �Ѵ�. 
//    ������, ����ü�� �پ��� �ڷ������ �̷���� ������� �����̹Ƿ�, 
//    ù ��° ���Ҵ� ���ڿ�, �� ��° ���Ҵ� int, �� ��° ���Ҵ� float�� �����ϴ�.  
//    name�� ù ��°, age�� �� ��°, height�� �� ��°�� �ȴ�. 
// 
//    <= ������ ���� struct�� ����� ������ ������ �ʱ�ȭ�� �ִ� ������ �����ؾ� �Ѵ�. 
// 
//	struct person princess2 = {
//		"Naomi Scott",
//		18,
//		160.0f
//	};
//  <= �ڵ� ��Ÿ�Ͽ� ���� �̷��� ó���� ���� �ִ�. 
//     struct person princess = { "Naomi Scott", 18, 160.0f };�� �����ϴ�.
//     �����Ϸ��� ��ĭ�� �ٹٲ��� ��� ���� �����Ƿ� �� �� ���� ������ �����̴�. 
// 
// ���� ���� ������ �ϸ鼭 ���ÿ� �ʱ�ȭ�ϴ� ����� �ְ�, 
// ������ ���� �ϴ� ������ �� ������ ������ �ϳ� �ϳ� ������ �� �ִ� ����� �ִ�. 
// 
// strcpy(princess.name, "Naomi Scott");
// princess.age = 18;
// princess.height = 160.0f;
//   
// ����ü�� ���� �ڷ����� �ٸ� ������� ���� �� �����Ƿ� ���� ��򸰴�. 
// �׷��� Designated initializers��� ������ �ִ�. (C99, C11)
// 
// 	struct person beauty = {
//		.age = 19,
//		.name = "Bell",
//		.height = 150.0f
//	};
// 
// � ����� � ������ �ʱ�ȭ���� ������ �� �� �ִ�. 
// ������ ������ �ٲ� �ȴ�. (� ������� � ���� ������ ������ ������ �����Ƿ�)
// ������ �ʱ�ȭ�� �� �� ���� ������ �ٲ�� �� �ƴ�. 
// 
// struct person beauty = { .age = 19, .name = "Bell", .height = 150.0f };
// <= �̷��� �� �ٷ� �ʱ�ȭ�� �ص� �ȴ�. 
//    ������ �޸�(,)�� dot(.)�� ������ �־ �������� ������ �� �ִ�. 
//    ���� �ٲ� �ִ� �� ���� �� �������� ����. 
// 
// �����Ϳ� ���ؼ��� ���� ����. �翬�� �����ͷε� ������ �� �ִ�. 
// 
// /* Pointer to a structure variable */ 
// ����ü ������ ���� �����͸� ������ ������, 
// struct person* someone;
//	<= struct person�� �ڷ����� ��ó�� �̰Ϳ��ٰ� *�� �ٿ� �ش�. 
//     �׷��� person�̶�� tag�� ���� ����ü ������ �����Ͱ� �ȴ�. 
// 
// someone = &genie;
// <= &(address of) �����ڸ� �̿��ؼ� �̹� ������ �� �ٸ� structure variable��
//    �ּҸ� �����ٰ� �̷��� ������ �� �ִ�. 
// 
// someone = (struct Person*)malloc(sizeof(struct Person)); // and free later
// <= ���� �Ҵ��� �̿��ؼ� �޸� �Ҵ��� �Ǹ鼭 �ּҸ� �����ٰ� 
//    �̷��� ���� ���� �ִ�. ���� ����� �ڿ��� �ٽ� �Ұ��Ѵ�. 
// 
// �� �ܿ��� �Ϲ����� �������� ����� ����ѵ�, �ٸ� ���� �ϳ� �ִ�. 
// membership operator�� �޶�����. 
// 
// someone->age = 1001;
// <= someone�� �������̴�. 
//    �������� ��쿡�� �����ڷ� dot(.) ��� ȭ��ǥ(->)�� ����Ѵ�. 
//    �����͸� ���ؼ� access�ϴ� ���̱� ������, 
//    Indirect member(ship) operator (or structure pointer operator)
//    ��� �̸��� ����Ѵ�. Indirect member operator�� ���ذ� �� ���� �� ����. 
// 
// �������� ��쿡�� -> (arrow operator)�� �� �ְ�, 
// �Ϲ� ������ ��쿡�� .�� ��� �ָ� ����� ������ �� �ִ�. 
// 
// someone->name; �̷��� ȭ��ǥ �����ڷ� ����� ������ ���� �ְ�,
// (*someone).age; �̷��� someone�� indirection�� ������ dot operator�� ����� 
// ������ ���� �ִ�. 
// �� �� ���� ��� memeber access�� �� ���δ�. 
// 
// ����ü�� �Լ� �ȿ��� ������ ���� �ִ�. 
// struct book
// {
//     char title[MAX];
//	   float price;
// };
// <= �Լ� �ȿ� �̷��� ����ü�� �����ϰ� �� �Լ� �ȿ����� ����Ѵ�. 
//    �� �Լ��� ����� �� ����ü�� ����� �� ����. 
// 
// tag�� ������� ���� ���� �ִ�. 
// 
// struct {
//     char farm[MAX];
//     float price;
// } apple, apple2;
// <= tag�� �־�� �� �ڸ��� �ƹ� �͵� ����. 
//    tag�� ������ structure variable�� ��� ����ϴ°�?
//    �߰�ȣ�� ������ �ڸ��� �̷��� structure variables�� ���� �Է��ؼ� 
//    ������ �� ���� ���� �ִ�. ���� ����ϴ� ����̴�. 
//    <= tag ���� structure variable�� ����Ѵ�. 
//    ��� ���� �� ����ü��� �̷��� �� ���� �ִ�. 
//    apple3�� �� �����ϰ� ������, 
// 
// struct {
//     char farm[MAX];
//     float price;
// } apple3; 
// 
//    �̷��� �� ���� ��� �ϹǷ� ���ŷο� �� �ִ�. 
// 
// ����ü�� ����ڰ� ������ ���ο� �ڷ����� ��ó�� ����� �� �ִ�. 
// structure variable�� ������ ������, 
// �տ��ٰ� struct�� �� �ٿ� ��� �ߴ�. 
// 
// typedef�� ����ϸ� �� struct�� ���� �� �ִ�. 
// 
// typedef struct person my_person;
// <= struct person�̶�� Ÿ���� my_person���� ������ �� �ش�. 
//    �׷��� my_person�̶�� �ڷ����� �ִ� ��ó��, 
// my_person p3;
//    <= �̷��� ���� p3�� ������ �� �ִ�. 
//       ���������δ� struct person�̶�� struct�� ����������, 
//       �ڵ带 ���� ���� my_person�̶�� �ڷ����� ������ �����ϰ� ������ �� �ִ�. 
// 
// typedef struct person person;
// <= ������ struct person�� typedef�� �׳� person�̶�� �ڷ����� ��ó��
//    �̸��� �ٲ� ���� ���� �ִ�. 
//    �̷��Ե� �� ���� ����Ѵ�.   
// person p4;
// <= ������ �̷��� ����� �� �ִٴ� �͵� �˾� �ֶ�. 
//
// ����ü�� ������ �� �ƿ� �̷��� typedef�� ������ ���� �ִ�. 
// 
// typedef struct {
//     char name[MAX];
//	   char hobby[MAX];
// } friend;
//
// friend f4;
// 
// <= struct ������ tag�� ����. 
//    struct ����({})�� friend��� Ÿ�� �̸����� ������ �ϰ�, 
//    friend�� ��ġ ���ο� �ڷ����� ��ó�� �̷��� ������ ������ �� �ִ�. 
//    �� ����� ���� ���ȴ�. 
// 
// ����ü�� �⺻���� ��� ����� ���ؼ� ���� �ô�. 