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

void deleteElement(int arr[MAX_ROWS][MAX_COLS], int& rows, int& cols, int rowToDelete, int colToDelete) {
    // Di chuyển các phần tử sau vị trí cần xóa
    for (int i = rowToDelete; i < rows - 1; ++i) {
        for (int j = colToDelete; j < cols; ++j) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    // Lấp đầy phần tử cuối cùng của mảng
    arr[rows - 1][cols - 1] = 0; // Hoặc giá trị mặc định của phần tử

    // Giảm số hàng và cột của mảng
    rows--;
    cols--;
}

int main() {
    int array[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = MAX_ROWS;
    int cols = MAX_COLS;

    cout << "Mảng trước khi xóa phần tử:" << endl;
    displayArray(array, rows, cols);

    // Xóa phần tử 5 ở hàng 1, cột 1 (chỉ mục bắt đầu từ 0)
    deleteElement(array, rows, cols, 1, 1);

    cout << "\nMảng sau khi xóa phần tử:" << endl;
    displayArray(array, rows, cols);

    return 0;
}
