#include <bits/stdc++.h>
using namespace std;

bool daDuyet[300][300]; // Đánh dấu các ô đã duyệt
int soHang;
int soCot;
int islandCount = 0;

// Kiểm tra xem vị trí (i, j) có hợp lệ không
bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < soHang && j < soCot;
}

// Hàm DFS để tìm các ô thuộc cùng một hòn đảo
void DFS(vector<vector<char>>& a, int i, int j) {
    // Kiểm tra nếu vị trí không hợp lệ
    if (!isValid(i, j)) return;
    if (a[i][j] == '0' || daDuyet[i][j]) return;

    // Đánh dấu vị trí này đã được duyệt
    daDuyet[i][j] = true;

    // Gọi đệ quy tìm các ô lân cận
    DFS(a, i, j + 1); // phải
    DFS(a, i, j - 1); // trái
    DFS(a, i - 1, j); // trên
    DFS(a, i + 1, j); // dưới
}

// Hàm chính để đếm số hòn đảo
int numIslands(vector<vector<char>>& a) {
    soHang = a.size();      // Số hàng của mảng
    soCot = a[0].size();    // Số cột của mảng

    // Duyệt qua toàn bộ lưới
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            // Nếu gặp '1' và ô chưa được duyệt, đó là một hòn đảo mới
            if (a[i][j] == '1' && !daDuyet[i][j]) {
                DFS(a, i, j); // Tìm toàn bộ hòn đảo
                islandCount++; // Đếm hòn đảo
            }
        }
    }
    return islandCount;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Số lượng hòn đảo: " << numIslands(grid) << endl;

    return 0;
}
