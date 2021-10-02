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
		puts("Input a color name (empty line to quit): ");
		
		if (scanf("%[^\n]%*c", choice) != 1)
			break;

		for (color = red; color <= blue; color++) {
			if (strcmp(choice, colors[color]) == 0) {
				color_is_found = true;
				break;
			}
		}

		if (color_is_found) {
			switch (color) {
			case red:
				puts("Red roses");
				break;
			case orange:
				puts("Oranges are delicious");
				break;
			case yellow:
				puts("Yellow sunflowers");
				break;
			case green:
				puts("Green apples");
				break;
			case blue:
				puts("Blue ocean");
				break;
			}
		}			
		else
			printf("Please try different color %s.\n", choice);
		color_is_found = false; // 계속 루프를 돌므로 false로 해 준다. 
	}

	puts("Goodbye!");

	return 0;
}

//
// iif (scanf("%[^\n]%*c", choice) != 1) 
//     break;
// <= 다르게 입력 받는 방법도 있으나, 이렇게 입력 받는 게 간단하다. 
//
// 입력 받은 문자열이 색깔의 이름과 정확히 일치하는지를 비교하는 데 for문을 사용한다.
	/*
	for (color = red; color <= blue; color++) {
		if (strcmp(choice, colors[color]) == 0) {
		 <= choice와 colors[color]가 같을 때 0을 리턴해 준다. 
			color_is_found = true;
			break;
		}
	}
	*/
// 
// 다음은 switch()문을 사용해서 출력되는 값을 결정한다. 



