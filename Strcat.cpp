#include <iostream>

using namespace std;

unsigned strlen(const char *str) {
    unsigned len = 0;
    for (; *str != '\0'; len++, str++);

    return len;
}

void strcat(char *to, const char *from)
{
    int i;
    unsigned len = strlen(from);
    unsigned len2 = strlen(to);
    for(i = 0; i != len2; len++, i++)
        to[len] = from[i];
}

int main() {

    char test[255] = "Hello ";
    char test2[255] = "World!";
    char *tPtr = &test[0];
    char *tPtr2 = &test2[0];
    unsigned l;

    strcat(tPtr,tPtr2);

    cout << test << endl;

    return 0;
}