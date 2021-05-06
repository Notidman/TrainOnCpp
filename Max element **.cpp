#include <iostream>

#define size 5

using namespace std;

bool max_element(int *p, int *q, int **res) {
    if (p == q)
        return false;
    *res = p;
    for (; p != q; p++)
        if (*p > **res)
            *res = p;

    return true;
}

int main() {
    int m[size] = {5, 3, 6, 1, 4};
    int *maxPtr = nullptr;
    if (max_element(m, m + size, &maxPtr))
        cout << "Max element: " << *maxPtr << endl;

    return 0;
}