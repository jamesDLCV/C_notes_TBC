#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* $ scanf 함수 반환값 사용
 프로그램의 사용자가 키보드로 한 줄을 입력할 때 입력을 끝내려면 Enter를 누르면 된다.
 그런데 개행 문자 또한 하나의 입력 데이터로 쓴다면
 입력을 종료하는 별도의 신호가 필요하다.

 <= 이때 scanf() 함수의 반환값을 사용한다.

 scanf() 함수는 키보드로 ctrl + z를 누르면 -1을 반환한다.
 운영체제에 따라 키보드 입력 방식이 달라질 수 있는데,
 ctrl + z를 누르고 Enter를 누른 후에 ctrl + z를 한 번 더 입력해야 -1이 반환될 수 있다.

 또한 유닉스나 리눅스 시스템에서는 ctrl + d를 사용한다.

 결국 scanf() 함수가 -1을 반환하기 전까지 반복 입력하면,
 개행 문자를 포함한 모든 데이터로 사용할 수 있다. */

int main() {

	// 손코딩 11-5. 직접 해 보는 손코딩
	int result;						// scanf() 함수의 반환값을 저장할 변수
	char ch;						// 문자를 입력할 변수

	while (1) {
		result = scanf("%c", &ch);	// 문자 입력, ctrl + z를 누르면 -1 반환
		if (result == -1) break;	// 반환값이 -1이면 반복 종료
		printf("%d ", ch);			// 입력된 문자의 아스키 코드 값 출력
	}

	return 0;
}
// 실행 결과:
// A
// 65 10 cat
// 99 97 116 10 ^ Z  <= ctrl + z
// ^ Z               <= ctrl + z

/*
 $ note
	실습 환경이 윈도우 10인 경우 ctrl + z를 누르고 Enter를 누른 후에
	ctrl + z를 한 번 더 입력해야 -1이 반환된다.

 scanf() 함수는 기본적으로 입력한 값의 개수를 반환한다.
 즉,
 result = scanf("%c", &ch);에서 문자를 제대로 입력한 경우 1을 반환한다.

 그러나 ctrl + z를 동시에 누르면 -1을 반환한다.
 따라서 반환값을 조건식에 사용하면 ctrl + z를 누를 때까지
 입력하는 모든 문자의 아스키 코드 값을 출력할 수 있다.

 실행 결과는 입력과 출력이 Enter를 기준으로 반복된다.
 첫 번째 행의 입력은 두 번째 행에서 아스키 코드 값을 출력하고 새로운 입력을 기다린다.

 입력한 데이터는 Enter를 누르는 순간 버퍼로 저장되고,
 반복문이 수행면서 버퍼의 문자를 하나씩 가져다 아스키 코드 값을 출력한다.

 버퍼의 데이터를 모두 처리하면
 다시 키보드로부터 새로운 데이터를 입력 받기 위해 대기 상태가 된다.

 두 번째 행의 입력도 같다. 마지막으로 ctrl + z를 누르면,
 scanf() 함수는 -1을 반환하고, if 문의 조건식이 참이 되어 반복을 종료한다.

								버퍼
	_________              _______________________                _______
   |  65 10  | <--------  | A | \n|   |   |   |   | <----------- |   A   |
   |_________|            |___|___|___|___|___|___|              |_______|
		|       아스키                               개행 문자까지
		|       코드 값 출력                          버퍼에 저장
		|
		| 버퍼가 비었으므로
		| 새로운 데이터 입력
  ______v____              _______________________               ______________
 | 65 10 cat | ---------> | c | a | t | \n|   |   | ----------> | 65 10 cat    |
 |___________|            |___|___|___|___|___|___|             | 99 97 116 10 |
			   개행 문자까지             아스키 코드 값 출력       |______________|
			   버퍼에 저장                                             |
													 버퍼가 비었으므로  |
													 새로운 데이터 입력 |
															  _________v_______
															 | 65 10 cat       |
			scanf() 함수가             <--------------------  | 99 97 116 19 ^z |
			-1을 반환하여 반복 종료        ctrl + z를 누르고    |_________________|
										  Enter

 키보드로 숫자를 입력하는 경우에도 일단 문자열의 형태로 버퍼에 저장된다.
 그 후에 문자열이 실제 연산이 가능한 값으로 변환되어 변수에 저장된다.

 예를 들어 int 형 변수 a에 20을 입력하는 경우
 문자 '2'와 '0'이 각각 아스키 코드 값으로 코드화되어 버퍼에 저장된다.
 그 후에 변환 문자의 지시에 따라 연산이 가능한 숫자로 변환되어 변수에 저장된다.

	 키보드 입력                문자열로 표현한 버퍼 상태
	____________               _______________________
   |     20     |  ------>    | 2 | 0 | \n|   |   |   |
   |____________|           --|___|___|___|___|___|___|
				  각 문자가 |    |   |   |________________
				코드화 되어 |     |   |________           |
					  저장 |   ___|____________|__________|__________
						   -->| 00110010 | 00110000 | 00001010 |
						   ---|__________|__________|__________|_____
					%d로  |    버퍼에 실제 저장된 비트열
					변환  |    __________________________________________
						   -->|  00000000  00000000  00000000  00010100  |
							  |__________________________________________|
								변수 a에는 연산이 가능한 2진수의 비트열로 저장된다.

 결국 변환 문자는 코드화된 문자열을 숫자로 변환하는 방법을
 scanf() 함수에 알려 주는 역할을 한다.

 만약 같은 입력에 대해 %lf 변환 문자를 쓰고 실수형 변수에 입력한다면,
 버퍼에 저장된 상태는 같지만 IEEE 754 표준에 따라 변환되므로,
 변수에 저장되는 비트열의 크기와 형태는 달라진다.

 $ scanf() 함수의 반환값과 비교하는 값 EOF
  scanf() 함수의 반환값과 비교하는 값으로 -1 대신 EOF를 쓸 수 있다.
  앞서 손코딩 11-5의 첫 번째 행에 사용한 stdio.h 헤더 파일에는
  소스 코드에 있는 EOF라는 이름을 -1로 바꾸는 전처리 지시자가 있다.

  따라서 다음과 같이 작성하는 것도 가능하다.

	  result = scanf("%c", &ch);	// scanf() 함수의 반환값을 result에 저장
	  if (result == EOF) break;		// EOF는 -1로 바뀌므로
									   결국 result와 -1을 비교한다.

  EOF는 End Of File의 뜻이므로 -1 대신에,
  입력의 끝을 의미하는 이름으로 사용하면 좀 더 읽기 쉬운 코드를 작성할 수 있다. */