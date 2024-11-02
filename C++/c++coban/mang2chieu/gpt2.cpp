#include <iostream>

using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

void displayArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void insertElement(int arr[MAX_ROWS][MAX_COLS], int& rows, int& cols, int rowToInsert, int colToInsert, int value) {
    // Di chuyển các phần tử sau vị trí chèn để mở đường cho phần tử mới
    for (int i = rows; i > rowToInsert; --i) {
        for (int j = cols; j > colToInsert; --j) {
            arr[i][j] = arr[i - 1][j - 1];
        }
    }

    // Chèn phần tử mới
    arr[rowToInsert][colToInsert] = value;

    // Tăng số hàng và số cột của mảng
    rows++;
    cols++;
}

int main() {
    int array[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = MAX_ROWS;
    int cols = MAX_COLS;

    cout << "Mảng trước khi chèn phần tử:" << endl;
    displayArray(array, rows, cols);

    // Chèn phần tử 10 vào hàng 1, cột 1 (chỉ mục bắt đầu từ 0)
    insertElement(array, rows, cols, 1, 1, 10);

    cout << "\nMảng sau khi chèn phần tử:" << endl;
    displayArray(array, rows, cols);

    return 0;
}
