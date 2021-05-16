#include <iostream>
#include <string>
using namespace std;

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int mPtr = 0;
    int min = **m;
    unsigned i = 0, j = 0;

    for(i = 0; i < rows*cols; i++) {
        if (min >= m[i/cols][i%cols]) {
            mPtr = i/cols;
            min = m[i/cols][i%cols];
        }
    }
    int *temp = *m;
    *m = m[mPtr];
    m[mPtr] = temp;
}


int main() {

    int cols = 0, rows = 0;

    //srand(time(NULL));

    cout << "Enter cols and rows: \n> ";
    cin >> cols >> rows;

    int **arr = new int*[rows];
    arr[0] = new int[rows * cols];

    for(int i = 1; i < rows; ++i)
        arr[i] = arr[i - 1] + cols;

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            arr[i][j] = 1 + rand() % 20;

    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    swap_min(arr,rows,cols);

    cout << endl;

    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    delete [] arr;
    arr = nullptr;
    return 0;
}