#include <iostream>
#include <fstream>
using namespace std;

void save2DArray(int arr[][100], int rows, int cols, const string& filename) {
    ofstream file(filename);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            file << arr[i][j] << " ";
        file << endl;
    }
    file.close();
}

void grow2DFront(int arr[][100], int& rows, int cols, int rowData[]) {
    for (int i = rows; i > 0; --i)
        for (int j = 0; j < cols; ++j)
            arr[i][j] = arr[i - 1][j];
    for (int j = 0; j < cols; ++j)
        arr[0][j] = rowData[j];
    ++rows;
    save2DArray(arr, rows, cols, "updated_2d.txt");
}

void grow2DEnd(int arr[][100], int& rows, int cols, int rowData[]) {
    for (int j = 0; j < cols; ++j)
        arr[rows][j] = rowData[j];
    ++rows;
    save2DArray(arr, rows, cols, "updated_2d.txt");
}

void grow2DAt(int arr[][100], int& rows, int cols, int rowData[], int pos) {
    if (pos >= 0 && pos <= rows) {
        for (int i = rows; i > pos; --i)
            for (int j = 0; j < cols; ++j)
                arr[i][j] = arr[i - 1][j];
        for (int j = 0; j < cols; ++j)
            arr[pos][j] = rowData[j];
        ++rows;
    }
    save2DArray(arr, rows, cols, "updated_2d.txt");
}

void shrink2DFront(int arr[][100], int& rows, int cols) {
    if (rows > 0) {
        for (int i = 0; i < rows - 1; ++i)
            for (int j = 0; j < cols; ++j)
                arr[i][j] = arr[i + 1][j];
        --rows;
    }
    save2DArray(arr, rows, cols, "updated_2d.txt");
}

void shrink2DEnd(int arr[][100], int& rows) {
    if (rows > 0)
        --rows;
    save2DArray(arr, rows, 100, "updated_2d.txt");
}

void shrink2DAt(int arr[][100], int& rows, int cols, int pos) {
    if (pos >= 0 && pos < rows) {
        for (int i = pos; i < rows - 1; ++i)
            for (int j = 0; j < cols; ++j)
                arr[i][j] = arr[i + 1][j];
        --rows;
    }
    save2DArray(arr, rows, cols, "updated_2d.txt");
}

int main() {
    int arr2D[100][100] = { {1, 2}, {3, 4} };
    int rows = 2, cols = 2;
    int newRow[] = { 5, 6 };

    grow2DFront(arr2D, rows, cols, newRow);
    grow2DEnd(arr2D, rows, cols, newRow);
    grow2DAt(arr2D, rows, cols, newRow, 1);
    shrink2DFront(arr2D, rows, cols);
    shrink2DEnd(arr2D, rows);
    shrink2DAt(arr2D, rows, cols, 1);
    cout << "file update sucessfully";
    return 0;
}
