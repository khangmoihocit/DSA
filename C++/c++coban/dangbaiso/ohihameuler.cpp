#include <iostream>
#include <cmath>
using namespace std;

// Hàm tính chỉ số Euler (phi function) của một số nguyên dương n
int phi(int n) {
    int result = n; // Khởi tạo kết quả bằng n

    // Duyệt qua các số từ 2 đến căn bậc hai của n
    for (int i = 2; i <= sqrt(n); ++i) {
        // Kiểm tra xem i có phải là thừa số nguyên tố của n không
        if (n % i == 0) {
            // Nếu i là thừa số nguyên tố của n, cập nhật kết quả
            result -= result / i;

            // Loại bỏ tất cả các lần xuất hiện của i trong n
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // Nếu n là một số nguyên tố lớn hơn 1, cập nhật kết quả
    if (n > 1) {
        result -= result / n;
    }

    // Trả về kết quả cuối cùng
    return result;
}

int main() {
    // In ra giá trị của phi(120)
    cout << "Giá trị của phi(120): " << phi(120) << endl;

    return 0;
}
