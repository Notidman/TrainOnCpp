#include <iostream>

using namespace std;

unsigned strlen(const char *str) {
    unsigned len = 0;
    for (; *str != '\0'; len++, str++);

    return len;
}

void strcat(char *to, const char *from)
{
    int i,j;
    for (i = 0; to[i] != '\0'; i++);

    for (j = 0; from[j] != '\0'; j++)
        to[i+j] = from[j];

    to[i+j] = '\0';
}

int main() {

    char test[255] = "Hello ";
    char test2[255] = "World!";
    char *tPtr = &test[0];
    char *tPtr2 = &test2[0];
    unsigned l;

    strcat(tPtr,tPtr2);
    strcat(tPtr, "...");
    cout << test << endl;

    return 0;
}
