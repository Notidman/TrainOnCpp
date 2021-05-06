#include <iostream>

using namespace std;

unsigned strlen(const char *str) {
    unsigned len = 0;
    for (; *str != '\0'; len++, str++);

    return len;
}

int main() {

    string test = "KekLol";
    char *tPtr = &test[0];
    unsigned l;

    l = strlen(tPtr);

    cout << l << endl;

    return 0;
}