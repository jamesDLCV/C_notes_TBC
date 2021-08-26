#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 파일 임의 접근 Random Access
// 
// 파일의 임의의 위치에 직접 접근해서 데이터를 읽어 올 수 있는 
// 파일의 임의 접근에 대해서 살펴 보겠다. 
//
// text.txt에는 ABCDEFGHIJKLMNOPQRSTUVWXYZ 이 입력돼 있다. 

/*
	ABCDEF ...
	Current position 0 and read -> A
	Cureent position 1 and read -> B
	...
*/

int main() {
	int ch;
	long cur;

	FILE* fp = fopen("test.txt", "r");

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	/* SEEK_SET */
	printf("\n*** SEEK_SET ***\n");

	fseek(fp, 2L, SEEK_SET);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* SEEK_CUR */
	printf("\n*** SEEK_CUR ***\n");

	fseek(fp, -2L, SEEK_CUR);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* SEEK_END */
	printf("\n*** SEEK_END ***\n");

	fseek(fp, 0L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -1L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -2L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* fsetpos(), fgetpos() */
	printf("\n*** fsetpos() ***\n");

	fpos_t pt;
	pt = 10;
	fsetpos(fp, &pt);		// returns 0 ok
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	printf("\n*** fsetpos() ***\n");

	fgetpos(fp, &pt);		// returns 0 ok
	printf("%lld\n", pt);	//NOTE: not meant to be read directly

	return 0;
}

// test.txt에는 A부터 Z까지가 대문자로 입력돼 있다. <= text.txt 파일을 만들어 둔다.
// 처음에 이 test.txt 파일을 열면, 
// 0번째 위치에 있고, 한 글자를 읽으면 1byte 옆으로 이동한다. 
// <= 파일의 시작으로부터 1byte만큼 떨어져 있게 된다. 
// 
// 파일의 시작으로부터 2byte만큼 떨어져 있다면 어디인가?
// AB여기C, <= 여기이다. 여기에서 한 글자를 읽는다면, C를 읽고, 
// C를 읽었기 때문에 한 칸 이동한다. 
// <= 이 정도만 알면 위 코드를 이해할 수 있다. 
// 
// FILE* fp = fopen("test.txt", "r"); <= 파일을 연다
// cur = ftell(fp);
//	ftell()이라는 함수를 호출하면, 현재의 위치를 알려 준다. 
//  현재 어디에서 읽을 준비가 돼 있는지 알려 준다. 
//  실행 시키면 ftell() = 0 이렇게 0이 출력된다. 
//  <= 시작점으로부터 0byte만큼 떨어져 있다. 즉 시작점에 있다라는 의미가 된다. 
// 
// 그다음,
// fseek(fp, 2L, SEEK_SET); 
//  fseek() 함수를 사용하면, 이동을 할 수 있다. 
//  SEEK_SET flag를 세 번째 인수로 넣고, 파일 포인터 fp를 첫 번째 인수로 넣고, 
//  두 번재 인수로 long을 넣고 있는데 bytes이다. 
//  <= 시작점(SEEK_SET)으로부터 2bytes 떨어질 곳으로 이동한다. 2bytes(?)
//     그리고 읽을 준비를 한다는 의미이다. 
// 
// 그리고, 읽으면?
// cur = ftell(fp);
// printf("ftell() = %ld\n", cur);
//  출력) ftell() = 2  <= 2를 출력한다. 
//
// ch = fgetc(fp);				<= 읽어 들인다. 
// printf("%d %c\n", ch, ch);   
//		<= c를 출력하고, 
//      <= 읽었기 때문에 한 byte를 더 이동해서 
//         시작점으로부터 3bytes 떨어진 곳에서 읽을 준비를 한다.
// 
// cur = ftell(fp);					<= 그리고 다시 한 번 읽어 들이고
// printf("ftell() = %ld\n", cur);  <= 출력을 하면, 3이 나온다. 
//		<= 한 글자 읽으면서 한 byte 더 이동을 한 것이다.  
// 
// fseek(fp, -2L, SEEK_CUR);		<= SEEK_CUR을 넣으면, 
//                                     현재 위치에서 -2L 숫자만큼 이동한다. 
//									   3에서 -2만큼 거꾸로 간다.  
// cur = ftell(fp);                 <= 읽어 들이면, 
// printf("ftell() = %ld\n", cur);  <= 1이 출력된다. 
// 
// ch = fgetc(fp);                  <= 1에서 다시 읽어 들이면,  
// printf("%d %c\n", ch, ch);       <= B가 나온다.
// 
// SEEK_END도 있다. 
// 
// fseek(fp, 0L, SEEK_END);			<= 끝에서부터 찾는다. 
//                                  <= 끝으로 이동을 한 후 0만큼 이동을 하고,
// ch = fgetc(fp);                  <= 읽어 들이면, 
// printf("%d %c\n", ch, ch);       <= -1이 출력된다. EOF이 나온다. 
// 
// fseek(fp, -1L, SEEK_END);		<= EOF에서 -1만큼 이동하고,
// ch = fgetc(fp);					<= 읽어 들이면, 
// printf("%d %c\n", ch, ch);       <= 90 Z가 출력된다. 
//
// fseek(fp, -2L, SEEK_END);        <= EOF에서 -2만큼 이동하고,
// ch = fgetc(fp);				    <= 읽어 들이면,
// printf("%d %c\n", ch, ch);		<= 89 Y가 출력된다. 
//
// 여기까지는 두 번째 인수로 long을 썼는데, 
// 파일이 어마어마하게 클 경우에는 long 대신에 fpos_t 타입을 사용할 수 있다. 
// 
// fpos_t pt;		<= visual studio에서는 fpos_t의 타입을 long long으로 해 놨다.
// pt = 10;
//  용법은 위의 것과 조금 다르다. 
// fsetpos(fp, &pt);		// returns 0 ok
//  <= fseek()과 비슷하나 포인터를 넣어 주고 있다.  
// 
// ch = fgetc(fp);            <= 읽어 들이고 
// printf("%d %c\n", ch, ch); <= K를 출력, 위치는 10
// 
// fgetpos(fp, &pt);		// returns 0 ok
//                            <= 현재 위치를 본다. 
//                            <= 위 10에서 K를 읽었으므로 한 칸 더 간 11이 된다. 
//  <= ftell()과 비슷하나 두 번째 인수로 포인터를 넣어 주고 있다. 
// printf("%lld\n", pt);	//NOTE: not meant to be read directly
//                            <= 11을 출력
//  <= fpos_t를 lld로 받고 있지만, fpos_t에 대한 형식 지정자는 존재하지 않는다.
//     의도적이라고 한다. 아주 큰 숫자, 숫자들의 조합일 수도 있으므로,
//     format specifier를 지정해 주지 않았다고 한다. 
//     여기에서는 출력을 보여 주기 위해 lld로 하고 강제로 출력을 했다. 
// 
// 다음에는 바이너리 파일에서 random access를 어떻게 하는지 보겠다. 