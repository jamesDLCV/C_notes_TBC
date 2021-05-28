#include <stdio.h>

int main() {

    char* name[] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie" };

    const int n = sizeof(name) / sizeof(char*);

    for (int i = 0; i < n; ++i)
        printf("%s at %u\n", name[i], (unsigned)name[i]);
    printf("\n");

    printf("%s\n", *name);
    printf("%s\n", *(name + 0));
    printf("%s\n", *(name + 1));
    printf("%s\n", *(name + 2));
    printf("%s\n", *(name + 3));
    printf("\n");
    printf("%s\n", name[0] + 1);
    printf("%s\n", *name + 1);

    printf("%s\n", name[0] + 3);
    printf("%s\n", *name + 3);

    printf("%s\n", name[1] + 3);
    printf("%s\n", *(name + 1) + 3);

    printf("%s\n", name[2] + 4);
    printf("%s\n", *(name + 2) + 4);

    printf("%s\n", name[1] + 4);
    printf("%s\n", *(name + 1) + 4);


    printf("\n\n======================\n");

    char aname[][15] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie", "Jafar" };
    //char aname[5][15] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie", "Jafar is over f" };

    const int an = sizeof(aname) / sizeof(char[15]);

    for (int i = 0; i < an; ++i)
        printf("%s at %u\n", aname[i], (unsigned)aname[i]);

    printf("\n");
    printf("%s\n", *aname);
    printf("%s\n", *(aname + 0));
    printf("%s\n", *(aname + 1));
    printf("%s\n", *(aname + 2));
    printf("%s\n", *(aname + 3));
    printf("%s\n", *(aname + 4));
    printf("\n");
    printf("%s\n", aname[0] + 1);
    printf("%s\n", *aname + 1);

    printf("%s\n", aname[0] + 3);
    printf("%s\n", *aname + 3);

    printf("%s\n", aname[1] + 3);
    printf("%s\n", *(aname + 1) + 3);

    printf("%s\n", aname[2] + 4);
    printf("%s\n", *(aname + 2) + 4);

    printf("%s\n", aname[1] + 4);
    printf("%s\n", *(aname + 1) + 4);

    printf("%s\n", aname[4] + 3);
    printf("%s\n", *(aname + 4) + 3);

    return 0;
}