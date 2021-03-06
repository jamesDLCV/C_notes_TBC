#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 파일 입출력의 작동 원리
// 
// 지금까지는 콘솔 입출력 위주로 공부해 왔다. 
// 파일 입출력에 대해서 살펴 보자.
//
// 파일 입출력의 개념부터 알아 보자. 
// C언어로 작성된 프로그램을 실행시키면 운영체제와의 사이에, 
// streams가 세 개가 열린다. (stdout, stderr, stdin)
// 
// data stream, 입출력 stream에 대해서는 다른 강의에서 언급했다. 
// data가 시냇물처럼 흘러서 왔다 갔다 할 수 있는 통로이다. 
// 
// 세 개가 열리는데, 
// stdout 표준 출력, stderr 표준 error, stdin 표준 입력이다. 
// 화면에 출력을 하는 함수 printf()는 내부적으로 std output stream을 사용한다. 
// 키보드로부터 입력을 받는 scanf() 같은 함수는 내부적으로 stdin stream을 사용한다.
// stderr의 용법 자체는 stdout과 거의 비슷하다. 
// 차이는, 이것은 오류이므로 좀 긴급하게 출력을 해야 한다거나, 
//  혹은 정상적으로 출력이 되는 것과는 구분돼서 다른 stream으로 출력이 되거나 
//  저장이 되면 좋겠을 때 사용한다. 
// 구체적인 용법은 뒤에서 살펴 본다. 
// 
// 앞에서 방향 재지정 Redirection도 공부를 했다. 
// stdout이나 stderr에서 stream이 오면 방향을 재지정해서, 
// 화면에 출력할 것을 끌어다가 파일에 저장할 수도 있다. 
// 
// 버퍼를 사용하는 개념에 대해서도 앞선 강의에서 설명을 했다. 
// 한 글자, 한 글자, 1 bit, 1 bit 이런 식으로 입력과 출력을 왔다 갔다 하게 되면,
// 너무 느리기 때문에, 버퍼를 사용한다. 
// 버퍼에 효율적으로 사용할 수 있을 만큼의 충분한 data가 쌓였을 때, 
// 한꺼번에 보내서 처리를 한다. 
// 한 명씩 왔다 갔다 하는 게 아니고, 버스에 태워서 한꺼번에 이동한다. 
// 
// 어떤 경우에는 파일로부터 데이터를 읽어 오거나 저장해야 할 때가 있다. 
// 아주 유용한 기능이다. 
// 휴대폰의 주소를 백업하고, 다시 사용할 때와 같은 경우이다. 
// 게임을 할 때도, 게임을 잠시 멈출 때 데이터를 저장 해 놨다가, 
// 다시 게임을 시작할 때 게임의 데이터를 다시 읽어 들이는 경우에도 파일 입출력을 사용한다.
// 
// C언어에서는 파일 입출력을 일종의 stream으로 다룬다. Buffered stream이다.
// 알고 보면, 콘솔에 출력을 하고, 콘솔로부터 입력을 받는 기능들과, 
// 파일에 출력을 하고 파일로부터 데이터를 읽어들이는 파일 스트림은  
// 결국 IO Streams로 생각할 수 있다. 
// 
// 운영체제가 중요한 역할을 한다. 
// C언어에서 이렇게 일관된 방식으로 작업을 할 수 있도록 허용해 주는 것은, 
// 운영체제가 내부적으로 귀찮은 일들을 대부분 처리해 주기 때문이다. 
// 작성한 프로그램은 운영체제와 왔다 갔다 하면서 기능을 수행하게 된다. 
// 
// C언어로 작성한 프로그램이 파일과 의사소통할 때는(데이터를 저장하거나 읽어올 때는),
// 두 가지 모드를 사용할 수 있다. 
// 1. 텍스트 파일 IO 스트림, 통로를 연다.
// 2. 바이너리 파일 IO 스트림
// 
// 이 두 가지를 보통 사용한다. 이 두 가지를 혼합해서 사용할 수도 있다. 
//  파일의 앞 부분은 텍스트 파일로 저장하고 뒷 부분은 바이너리 파일로 저장할 수 있다. 
// 어쨌거나 이 모드들은 운영체제를 통해서 진행하게 된다. 
// 
// 읽어오게만 하거나 저장하게만 옵션을 지정할 수도 있다. 
// 
// 제시한 그림을 참조하라,
// 메모장, 노트패드로 바로 읽을 수 있는 파일은 텍스트 파일이다. 
// 텍스트 파일로 읽을 수 있는 것조차도 운영체제가 도와 주기 때문이다. 
// 
// 텍스트 파일에 있는 것들이 문자로 저장된다고 하더라도, 
// 그 문자를 화면에 그려 주는(해독해서 문자로 나타내 주는) 프로그램이 없다면, 
// 사람이 읽을 수가 없다. 
// 텍스트 파일은 보통 사람이 편하게 읽을 수 있게 하기 위해 사용한다. 
// <= 다음 강의에서 코드로 보여 준다. 
// 
// 바이너리 파일 IO 스트림, 
// 바이너리는 2진수이다. 이 2진수를 그대로 저장하는 것이다. 
// 
// 텍스트 파일은 문자로 저장을 하고, 문자를 읽을 수 있게 운영체제가 어떤 프로그램을
// 제공을 해 주는데, 바이너리는 그냥 순수한 데이터이기 때문에, 
// 사람이 직접 읽을 수가 없다. 
// 
// 조금 더 구체적으로 살펴 보자.
// 
// int i = 34567; 이라고 초기화하면, 메모리 내부에서는 (10000111, 00000111) 이렇게
// 2진수로 바꿔서 데이터 형태로 가지고 있을 것이다.  
// 
// fprintf(fp, "%d\n", i); 파일 스트림에다가 "%d\n" 형식에 맞춰서 i를 저장해라.
// <= 숫자 하나와 줄바꿈 하나가 저장이 된다. 
// <= 텍스트 파일 스트림으로 가니까, 텍스트로 저장이 된다. 
// 
// 텍스트 파일 스트림에서는 이 데이터 자체를 저장하는 것이 아니고, 
// '3', '4', '5', '6', '7' 이렇게 문자로 저장한다. 
// 왜냐하면, 사람이 읽을 수 있어야 하기 때문이다. 
// 사람에게 '110011', '110100', ~ , (110111) 이렇게 주면 못 읽는다. 
// 텍스트 파일은 대부분의 경우 사람이 읽을 수 있도록 저장하는 것이 목표이다. 
// 
// 결국 34567(줄바꿈)(EOF)를 저장하면 문자로 저장이 된다. 
// 그 문자를 읽게 해 주는 것도 어떠한 프로그램이다.  
// 대부분의 경우 운영체제에 탑재돼 있는 프로그램이다. 
// 문자를 화면에 보여 주는 프로그램이 필요하다. 
// 운영체제에 따라서 (EOF) end of file이 들어가거나 들어가지 않거나 한다. 
// 
// 바이너리 파일은, fwrite(&i, sizeof(i), 1, fp) 함수를 사용할 수 있다. 
// (1000)(0111)(0000)(0111) 이런 바이너리 데어터 자체를 그대로 저장한다. 
// 사람이 읽을 수가 없다. 
// 
// 파일 입출력을 할 때 편한 점도 있고 불편한 점도 있다. 
// C언어를 이용해서 파일 입출력을 할 때는, 
// fprintf() 함수를 사용하면, 텍스트 파일로 저장이 된다. 
// 또 fwrite() 함수 등을 사용하면, 2진수가 그대로 저장이 된다. 
// 이 2진수 파일을 사람이 꺼내서 굳이 읽지 않으려고 하는 것은 아니다. 
// 
// 운영체제에 따라서 텍스트 파일을 저장하는 방법이 다르다.
// 조금씩 다르다. 또 언어에 따라서 다르다. 
// 예를 들어 윈도우즈가 영어만 사용하도록 설치가 됐는지, 
// 특수한 언어를 사용하도록 설치가 됐는지, 
// 운영체제 안에서도 프로그래머가 의도적으로 인코딩 방식을 바꿀 수도 있다.
// 
// 인코딩 방식은 아스키 코드 같은 경우는, 문자와 숫자를 대응시키는 표가 있다. 
// 그 대응시키는 방식이 더 다양하다. 
// 아스키 코드는 알파벳밖에 없었다. 한글, 러시아어는 어떻게 표현할까?
// 그러한 데이터, 문자를 나타내는 코드와 
// 실제 문자를 대응시켜 주는 더 많은 문자를 표현할 수 있는 표가 있어야 한다. 
// 
// 운영체제마다 인코딩 Encoding 방식이 다르다. (코드를 만든다 해서 Encoding) 
// 국제어를 사용할 때, 
// 문자를 코드로 바꾸고 코드를 문자로 바꾸는 인코딩 디코딩하는 방식이 필요한데, 
// 그것이 운영체제마다 다르다. 
// 그 운영체제가 알아서 처리해 준다. 
// <= 프로그래밍을 하다 보면, 이 인코딩 문제와 만나는 경우가 간혹 있다. 
//  
// (줄바꿈)도 운영체제마다 다르다.
// eg) MS Windows '\r''\n'
//     Mac '\r'
//     Linux '\n'
// 윈도우즈에서는 줄바꿈을 하기 위해서 \를 사용하는데, \r, \n 두 개를 사용한다. 
// 
// EOF도 운영체제마다 다르다. 
// eg) MS Windows '^Z'
//     Mac '^D'
//     Linux 없음
// 리눅스 같은 경우는 파일이 끝났는지의 판단에 관한 처리는 운영체제가 한다. 
// 
// C언어 문법에 맞게 프로그래밍을 하면 나머지는 운영체제가 알아서 처리를 한다. 
// 
// 텍스트 모드가 조금 더 복잡하고, 바이너리 모드도 운영체제에 따라서 
// 파일에 저장하는 방식이 달라질 수가 있다. 
// 바이너리 모드에서,
// Big Endian, Little Endian 같은 것도 나중에 만날 수가 있다. 
// 저장이 될 때, 2진수의 앞뒤 순서가 바뀌는 경우가 있다. 
// 여러 가지 운영체제의 내부 구조라든지, CPU의 구조에 따라서, 
// Little Endian으로 저장하는 것이 더 효율적일 때도 있다고 한다. 
// 이것은 나중에 컴파일러나 운영체제와 같은 다른 과목에서 배울 내용이다. 
// 
// 바이너리도 저장을 할 때는 프로그래머의 직관과 다르게 
// 순서가 바뀌어서 저장될 수 있다는 것만 알아 둬라.
// 순서가 바뀌어서 저장되더라도, 읽어들일 때는 원래대로 복원을 해 준다. 
// <= 어쨌든 운영체제가 알아서 해 주는 부분이다. 
// 
// 위에서 언급한 것과 같이 운영체제가 알아서 해 주는 부분이 있다는 것을 알고, 
// C언어 문법을 사용해서 파일 입출력을 진행하면 된다. 
// 
// 파일 입출력의 기본적인 작동 원리에 대해서 살펴 봤다. 

int main() {

	return 0;
}