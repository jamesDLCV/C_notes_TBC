#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		// strcmp (HINT!)
#include <stdbool.h>	// C99

// ������ ���� ����

enum spectrum { red, orange, yellow, green, blue };
const char* colors[] = { "red", "orange", "yellow", "green", "blue" };

#define LEN 30

int main() {
	char choice[LEN] = { 0, };
	enum spectrum color;
	bool color_is_found = false;

	while (1) {



	}

	return 0;
}

// ����� ������ ���� �ȴ�. 
// Input a color name (empty line to quit):
// red
// Red roses
// Input a color name (empty line to quit):
// orange
// Please try different color orange.
// Input a color name (empty line to quit):
// yellow
// Yellow sunflowers
// Input a color name (empty line to quit):
// green
// Green apples
// Input a color name (empty line to quit):
// blue
// Blue ocean
// Input a color name (empty line to quit):
// hi
// Please try different color hi.
// Input a color name (empty line to quit):
// road
// Please try different color road.
// 
// <= ��ĭ���� ���͸� ������ ������ �̷��� ��� �Է��� �޴´�.
//     
// ���� ������ Ǫ�� ��Ʈ��, strcmp()�� �� ����ؾ� �Ѵ�. 
// color[]�� ���ڷ� �������� �˾ƾ� �Ѵ�. 
// 
// enum spectrum { red, orange, yellow, green, blue };���� 
// red, orange, yellow, green, blue�� ���ڿ��� �ƴϴ�. 
//
// const char* colors[] = { "red", "orange", "yellow", "green", "blue" };
// <= �������� enumerators�� ������ ��Ű�� ���ؼ� ���ڿ� �迭�� ����� �ξ���. 
// 
// bool color_is_found = false;
// <= ���� color_is_found�� bool Ÿ������ �ִ�. 
// 
// ���ĺ��ʹ� ���� ������ �� ���⸦ �ٶ���. 