#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		// strcmp (HINT!)
#include <stdbool.h>	// C99

// 열거형 연습 문제

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

// 출력은 다음과 같이 된다. 
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
// <= 빈칸으로 엔터를 누르기 전까지 이렇게 계속 입력을 받는다.
//     
// 연습 문제를 푸는 힌트는, strcmp()를 잘 사용해야 한다. 
// color[]가 문자로 무엇인지 알아야 한다. 
// 
// enum spectrum { red, orange, yellow, green, blue };에서 
// red, orange, yellow, green, blue는 문자열이 아니다. 
//
// const char* colors[] = { "red", "orange", "yellow", "green", "blue" };
// <= 열거형의 enumerators와 대응을 시키기 위해서 문자열 배열도 만들어 두었다. 
// 
// bool color_is_found = false;
// <= 변수 color_is_found가 bool 타입으로 있다. 
// 
// 이후부터는 직접 구현을 해 보기를 바란다. 