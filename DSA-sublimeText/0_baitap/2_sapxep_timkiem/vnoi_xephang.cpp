#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, q;
    cin >> n >> q;

    // Sử dụng multiset để lưu các học sinh ban đầu
    multiset<ll> heights;

    // Đọc chiều cao của các học sinh ban đầu
    for (ll i = 0; i < n; i++) {
        ll height;
        cin >> height;
        heights.insert(height);
    }

    // Duyệt qua từng học sinh đến trễ
    while (q--) {
        ll x;
        cin >> x;

        // Tìm vị trí chèn của học sinh mới
        auto pos = heights.upper_bound(x);

        // In ra vị trí của học sinh mới (lưu ý vị trí bắt đầu từ 1)
        cout << distance(heights.begin(), pos) + 1 << endl;

        // Chèn học sinh mới vào multiset
        heights.insert(x);
    }

    return 0;
}
