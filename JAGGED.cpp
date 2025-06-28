#include <iostream>
#include <fstream>
using namespace std;

void saveJaggedArray(int* arr[], int rowSizes[], int rows, const string& filename) {
    ofstream file(filename);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rowSizes[i]; ++j)
            file << arr[i][j] << " ";
        file << endl;
    }
    file.close();
}

void growJaggedFront(int* arr[], int rowSizes[], int& rows, int newRow[], int newSize) {
    for (int i = rows; i > 0; --i) {
        arr[i] = arr[i - 1];
        rowSizes[i] = rowSizes[i - 1];
    }
    arr[0] = newRow;
    rowSizes[0] = newSize;
    ++rows;
    saveJaggedArray(arr, rowSizes, rows, "updated_jagged.txt");
}

void growJaggedEnd(int* arr[], int rowSizes[], int& rows, int newRow[], int newSize) {
    arr[rows] = newRow;
    rowSizes[rows] = newSize;
    ++rows;
    saveJaggedArray(arr, rowSizes, rows, "updated_jagged.txt");
}

void growJaggedAt(int* arr[], int rowSizes[], int& rows, int newRow[], int newSize, int pos) {
    if (pos >= 0 && pos <= rows) {
        for (int i = rows; i > pos; --i) {
            arr[i] = arr[i - 1];
            rowSizes[i] = rowSizes[i - 1];
        }
        arr[pos] = newRow;
        rowSizes[pos] = newSize;
        ++rows;
    }
    saveJaggedArray(arr, rowSizes, rows, "updated_jagged.txt");
}

void shrinkJaggedFront(int* arr[], int rowSizes[], int& rows) {
    if (rows > 0) {
        for (int i = 0; i < rows - 1; ++i) {
            arr[i] = arr[i + 1];
            rowSizes[i] = rowSizes[i + 1];
        }
        --rows;
    }
    saveJaggedArray(arr, rowSizes, rows, "updated_jagged.txt");
}

void shrinkJaggedEnd(int* arr[], int rowSizes[], int& rows) {
    if (rows > 0)
        --rows;
    saveJaggedArray(arr, rowSizes, rows, "updated_jagged.txt");
}

void shrinkJaggedAt(int* arr[], int rowSizes[], int& rows, int pos) {
    if (pos >= 0 && pos < rows) {
        for (int i = pos; i < rows - 1; ++i) {
            arr[i] = arr[i + 1];
            rowSizes[i] = rowSizes[i + 1];
        }
        --rows;
    }
    saveJaggedArray(arr, rowSizes, rows, "updated_jagged.txt");
}

int main() {
    int r0[] = { 1 };
    int r1[] = { 2, 3 };
    int* jagged[100] = { r0, r1 };
    int rowSizes[100] = { 1, 2 };
    int jaggedRows = 2;

    int rNew[] = { 7, 8, 9 };
    growJaggedFront(jagged, rowSizes, jaggedRows, rNew, 3);
    growJaggedEnd(jagged, rowSizes, jaggedRows, rNew, 3);
    growJaggedAt(jagged, rowSizes, jaggedRows, rNew, 3, 1);
    shrinkJaggedFront(jagged, rowSizes, jaggedRows);
    shrinkJaggedEnd(jagged, rowSizes, jaggedRows);
    shrinkJaggedAt(jagged, rowSizes, jaggedRows, 1);

    return 0;
}
