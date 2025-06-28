#include <iostream>
#include <fstream>
using namespace std;

void saveArray(int arr[], int size, const string& filename) {
    ofstream file(filename);
    for (int i = 0; i < size; ++i)
        file << arr[i] << " ";
    file << endl;
    file.close();
}

void growFront(int arr[], int& size, int value) {
    for (int i = size; i > 0; --i)
        arr[i] = arr[i - 1];
    arr[0] = value;
    ++size;
    saveArray(arr, size, "updated_array.txt");
}

void growEnd(int arr[], int& size, int value) {
    arr[size++] = value;
    saveArray(arr, size, "updated_array.txt");
}

void growAtPosition(int arr[], int& size, int value, int pos) {
    if (pos >= 0 && pos <= size) {
        for (int i = size; i > pos; --i)
            arr[i] = arr[i - 1];
        arr[pos] = value;
        ++size;
    }
    saveArray(arr, size, "updated_array.txt");
}

void shrinkFront(int arr[], int& size) {
    if (size > 0) {
        for (int i = 0; i < size - 1; ++i)
            arr[i] = arr[i + 1];
        --size;
    }
    saveArray(arr, size, "updated_array.txt");
}

void shrinkEnd(int arr[], int& size) {
    if (size > 0)
        --size;
    saveArray(arr, size, "updated_array.txt");
}

void shrinkAtPosition(int arr[], int& size, int pos) {
    if (pos >= 0 && pos < size) {
        for (int i = pos; i < size - 1; ++i)
            arr[i] = arr[i + 1];
        --size;
    }
    saveArray(arr, size, "updated_array.txt");
}

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
    int arr[100] = { 1, 2, 3 };
    int size = 3;
    growFront(arr, size, 0);      // Insert 0 at front
    growEnd(arr, size, 4);        // Add 4 at end
    growAtPosition(arr, size, 99, 2);  // Insert 99 at position 2
    shrinkFront(arr, size);       // Remove front element
    shrinkEnd(arr, size);         // Remove last element
    shrinkAtPosition(arr, size, 1);   // Remove element at position 1

    return 0;
}
