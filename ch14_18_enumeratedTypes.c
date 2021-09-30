#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ������, Enumerated Types
// 
// ������ ����� ��ġ �̸��� �ִ� ��ó�� ����� �� �ֵ��� �� �ִ� ������ ������ ���� ����.

/** Motivation
int c = 0;	// red: 0, orange: 1, yellow: 2, green: 3, ....

if (c == 0)
	printf("red");
else if (c == 1)
	printf("orange");
else if (c == 2)
	printf("yellow");
...
*/

/*
#define RED		1
#define ORANGE	2
#define YELLOW	3

int c = YELLOW;
if (c == YELLOW)
	printf("yellow");

*/

int main() {
	/*
		Enumerated type
		- Symbolic names to represent integer constants
		- Improve readability and make it easy to maintain
		- enum-specifier (struct-specifier, union-specifier)

		Enumerators
		- The symbolic constants
	*/

	enum spectrum { red, orange, yellow, green, blue, violet };
	//				0    1       2       3      4     5

	enum spectrum color;
	color = blue;
	
	if (color == yellow)
		printf("yellow");		// Note: enumerators are not strings

	for (color = red; color <= violet; color++)//Note: ++operator aren't allowed in c++
		printf("%d\n", color);

	printf("red = %d, orange = %d\n", red, orange);

	enum kids { jackjack, dash, snoopy, nano, pitz };
	// nina has a value of 3
	enum kids my_kid = nano;
	printf("nano %d %d\n", my_kid, nano);

	enum levels { low = 100, medium = 500, high = 2000 };

	int score = 800;	// TODO: user input
	if (score > high)
		printf("High score!\n");
	else if (score > medium)
		printf("Good job\n");
	else if (score > low)
		printf("Not bad\n");
	else
		printf("Do your best\n");

	enum pet { cat, dog = 10, lion, tiger };
	// lion has a value of 11
	printf("cat %d\n", cat);
	printf("lion %d\n", lion);

	return 0;
}

// �������� �� ����ϴ��� ���� ����.
/** Motivation
int c = 0;	// red: 0, orange: 1, yellow: 2, green: 3, ....
 <= ���� ���� ������ ���� ���α׷��� ����ٰ� �� ����. 
    red: 0, orange: 1, yellow: 2, green: 3, .... �̷� ������ ���� ���ڸ� ������ �� �� �ִ�. 
	���ڸ� ������ �ִ� ������ ���ڷ� ������ �ڵ��ϱⰡ ���� ���� ���̱� ������,
	������ ���򿡴ٰ� 0, 1, 2, 3, 4 ������ �ϳ��� ������ �ְ�,
	������ ������ �̿��ؼ� �̰� ���� �����̱������ �Ǵ��� �ϴ� ����� ����. 
 <= c��� color���ٰ� red ���� �־� �ְ� �ʹ�. 
    �׷��� color��� �ڷ����� �������� �����Ƿ�, ������ ���� � ������ ������ �ȴٰ� 
	�����ϴ� ���̴�.
 <= int Ÿ�� ���� c���ٰ� 0�� �����Ѵٴ� ����, c�� red ���� �ǹ��Ѵٰ� �����ϴ� ���̴�. 
    ���α׷��Ӱ� �̷��� ������ �ϰ� ���α׷����� �ϴ� ���̴�.
    
if (c == 2)
	printf("yellow");
 <= � ������ ��ó�� Ȥ�� ����ڷκ��� �Է��� �޾Ƽ�,
    2�� ��쿡�� yellow�� ����Ѵ�. <= �̷� ���α׷��� ������ �� �ִ�. 
 <= ������ �̷��� ���ڷ� �÷��� ǥ���� ���, �Ǽ��� Ȯ���� �������� �ȴ�. 
    2�� yellow��� ���� �ؾ� ������ �ʰ� ����� �ϸ鼭 ���α׷����� �ؾ� �ϴµ�,
	�̴� ���α׷��� ���忡���� ����� �δ㽺����.
	���߿� ����, ������ ���� �ſ� ����� �ǰ� �������� ���� �ʴ�. 
*/
// �̶� define�� �̿��ؼ� symbolic constants�� ����� ����� ������ �� �� �ִ�. 
/*
#define RED		1
#define ORANGE	2
#define YELLOW	3
 <= define�� ����ؼ� ��ũ�η� ������ �ϴ� ����, YELLOW�� 3�� ���� ���� ������ ��ü�� �ִ� ���̴�.
    ��ó������ Ư¡�̴�.
	�����Ϸ� ���忡���� YELLOW�� ��Ÿ����, 
	�׳� int c = 3; ó�� �������Ѵ�.
	<= �׷��� �����Ϸ��� ������ �ִ� ���� ��� ���� ���Ѵ�. 
	   ������ Ÿ�ӿ� �� �� �� �ִ� �� ����. 

int c = YELLOW;
if (c == YELLOW)
	printf("yellow");
<= �� �ڵ�� �����Ϸ� ���忡����,
int c = 3;
if (c == 3)
	printf("yellow");
<= �ڵ带 �̷��� ����. 
   �츮�� �ǵ��ϴ� �Ͱ��� ���� ���̰� �����. 
*/
// �׷��� �������̶�� ������ ����ϸ� ���� �� ���ϰ� ���α׷����� �� �� �ִ�. 
// ���α׷��� ���� �� �������� �����ϰ�, ����, ������ ���� �� �������� ������ �ִ�. 
// 
/*
		Enumerated type
		- Symbolic names to represent integer constants
		  <= ���� ������� ��ȣ���� �̸��� �ٿ� �ִ� ���̴�. 
		- Improve readability and make it easy to maintain
		- enum-specifier (struct-specifier, union-specifier)
		  <= ������-������, ����ü-������, ����ü-������
		  <= specifier: ��üȭ�Ѵ�.
		  <= enum: �����Ѵ�. 
		Enumerators
		- The symbolic constants
	*/
// 
// enum spectrum { red, orange, yellow, green, blue, violet };
//  			   0    1       2       3      4     5
// <= �̷��� ���ڸ� ����ؼ� �̸��� ������ ���α׷����� �� �� �ֱ� ������,
//    ����� �˾� ���� ����. 
//    0�� red��� ���� �ܿ��� �ʾƵ� �ǹǷ� �δ��� ���� �پ���. 
// <= �±� sepctrum �տ� enum�� �ٿ� �ش�. ����ü�� ����ü������ �����ϴ�. 
// <= ������ �ִ� ������ ��ȣ���� �̸��� �ٿ� �ش�. 
//    �׷��� Enumerated type�̶�� �θ���. 
// <= red, orange, yellow, green, blue, violet ���� ���� 
//    Enumerators��� �θ���. 
//    �̸��� �پ� �ִ� ������ ����̴�. ����� ���������� �����̴�. 
//    ���������� ����� �� ����ó�� ����� �� �ִ�. 
// 
// ����ü�� ����ü������ ����������, enumerator�� ���� ������ ������ ���� ����� �� �ִ�.
/*
enum spectrum color;
 <= �̷��� �����Ѵ�. 
    color���ٰ� { red, orange, yellow, green, blue, violet } enumerators��
	������ �� �� �ִ�.
	<= �տ������� 0, 1, 2, 3, ... �̷��� �ڵ����� ������ �ȴ�. 
color = blue;
 <= color���ٰ� blue�� ������ ���� �ְ�, 
if (color == yellow) <= color�� yellow�� ���� ���� �ִ�. 
	printf("yellow");		// Note: enumerators are not strings
	<= printf(yellow); ó�� ����ص� �� �� �ִ� ��ó�� ����������,
	   yellow�� ���ڿ��� �ƴϴ�. �׳� ������ ���̴�. 
	   2��� ������ yellow��� �̸��� �ٿ� �༭,
	   yellow��� �̸����� 2��� ������ ����� �� �ִ� ������, 
	   ���ڿ��� �״�� ������ ������ �ʴ´�. 
	   <= ���� ��򸮸� �� �ȴ�. 

for (color = red; color <= violet; color++)//Note: ++operator aren't allowed in C++, use type int.
    <= ��ſ� �����̱� ������ �̿� ���� for�� �ȿ� �ְ� 
	   �� ������, ���� �����ڿ� �� �� �ִ�. 
	   red�� ����, violet�� ���̴�. 
	<= C++������ ��Ÿ���Ե� �������� ���ؼ� ���� �����ڸ� ����� �� ����.
	   ���� ���� �� �� ����, color�� int������ ��� �Ѵ�. 

	printf("%d\n", color);

printf("red = %d, orange = %d\n", red, orange);
 <= red�� ���������� �����ϱ� ������ ����� �� ���ۿ� ����.
    ����� �� ���� %d�� ���� ���������� �ؾ� �Ѵ�. 
    red, yellow �� enumerators�� ���ڿ��� �ƴϴ�. 
*/
// 
// yellow enumerator�� ���콺�� ���� ���, 
// (enum spectrum)yellow = 2�� ���� �˷� �ش�. 
// �ֱٿ��� ���� ���� ȯ���� �������� �˷� ������ �������� ���� ���� �ʾƼ�,
// ���� �ö󰡼� Ȯ���ϰ� �ٽ� �����ͼ� �ڵ��ϴ� ���� ���Ҵ�. 
// 
/*
enum kids { jackjack, dash, snoopy, nano, pitz };
            0         1     2       3     4
 <= ���콺�� enumerators�� ���� ��� �Ҵ�� ������ ���. 

// nina has a value of 3
enum kids my_kid = nano;
 <= nano�� ��ǻ�� ���ο����� �׳� ���� 3�̴�. 
    ���� ���α׷����� �������� ���� �ֱ� ���ؼ� ���ڷ� �� �̸��� �ִ� ��ó�� 
	�ٷ� �� �ְ� �� �ִ� �����̴�. 

printf("nano %d %d\n", my_kid, nano);

enum levels { low = 100, medium = 500, high = 2000 };
 <= ������ ��, ��, �Ϸ� �����µ�, 2000���� ������ high, 
    500���� �Ѱ� 2000������ ������ medium�̴�. �̷��� ���� ������ �Ѵٰ� �� ����. 
	�̷��� ���������� �� �־� ���߿� ������ �����ϴ�. 
	<= �Ʒ��� ���ǹ��� ���ڰ� ���� ���߿� ������ �� ���� �����ϴ�. 
	<= �Ʒ�ó�� high, medium, low�� ���� �̸��� �پ� ������, 
	   �ڵ縦 ����, �� ����, ������ �� �����ϴ�. 
	   �ڵ带 �� �� ����� ���� �׳� �� ����ϴ� �ͺ��ٴ�, 
	   ��� �ʿ信 ���� ������ �ϰ� �� �ִ�. 
	<= �������� ����ϸ� �������� ��û���� ���� �ش�. 

int score = 800;	// TODO: user input

if (score > high)   <= ������ high���� �������̶�� ������ �������� ����. 
                       ���� score > 2000���� �� �ִٸ�, 2000�� �ǹ̰� ��ȣ�ϴ�.
	printf("High score!\n");
else if (score > medium)
	printf("Good job\n");
else if (score > low)
	printf("Not bad\n");
else
	printf("Do your best\n");
<= �̷� ������ ���ǵ� �������� ����ϸ� �������� ��������. 

// ������ enumerators�� ������ ������ �� 
   �� 0, 1, 2, 3, ... ������ �ؾ߸� �ϴ� ���� �ƴϴ�. 
enum pet { cat, dog = 10, lion, tiger };
 <= �߰��� dog = 10�� ���� ������ �� �� ���� �ִ�. 
// lion has a value of 11
   1 ~ 9������ ����. lion�� 11�� �����ȴ�. 
   tiger���� 12�� �����ȴ�. 
printf("cat %d\n", cat);
printf("lion %d\n", lion);

*/
// 
// �������� �ʿ��� ������ �⺻���� ������ ���� �ô�. 