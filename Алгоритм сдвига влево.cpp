#include <iostream>
#include <math.h>

#define SIZE 5

using namespace std;

void SwAP(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(int a[], unsigned size, int shift)
{
    int c = shift%size;
    while(c)
    {
    for(int i = 0; i <= size - 2; i++)
        SwAP(&a[i],&a[i+1]);
        --c;
    }
}
void massOut(int *p,int s)
{
    for(int i = 0; i <= s - 1; i++)
        cout << p[i];
    cout << endl;
}

int main()
{
    int mass[5] = {1,2,3,4,5};
    massOut(mass, SIZE);
    rotate(mass,SIZE,2);
    massOut(mass,SIZE);

    return 0;
}
