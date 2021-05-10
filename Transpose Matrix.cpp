#include <iostream>
using namespace std;

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** mRs = new int *[cols];
    mRs[0] = new int [rows * cols];

    for(unsigned i = 1; i < cols; ++i)
        mRs[i] = mRs[i - 1] + rows;

    for(unsigned i = 0; i < cols; ++i)
        for(unsigned j = 0; j < rows; ++j)
            mRs[i][j] = m[j][i];

    return mRs;
}

int main() {

    int cols = 0, rows = 0;

    cout << "Enter cols and rows: \n> ";
    cin >> cols >> rows;

    int **arr = new int*[rows];
    arr[0] = new int[rows * cols];

    for(int i = 1; i < rows; ++i)
        arr[i] = arr[i - 1] + cols;

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            arr[i][j] = i+1;

    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j];
        cout << endl;
    }
    cout << endl;

    arr = transpose(arr,rows,cols);

    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j];
        cout << endl;
    }
    cout << endl;

    delete [] arr[0];
    delete [] arr;
    arr = nullptr;
    return 0;
}