#include <stdio.h>
#define TEST "A string from #define."

int main() {
        
    /* puts() and fputs() */

    //char line[100];
    //while (gets(line))      // while (gets(line) != NULL)
    //    puts(line);

    char line[100];
    while (fgets(line, 100, stdin))
        fputs(line, stdout);           


    return 0;
}

