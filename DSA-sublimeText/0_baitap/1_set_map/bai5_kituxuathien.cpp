#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string s;
        getline(cin, s);
        map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }
        char result = '\0';
        int maxFreq = 0;
        // Duyệt qua map để tìm ký tự có số lần xuất hiện nhiều nhất và có thứ tự từ điển nhỏ nhất
        for (auto &entry : freq) {
            if (entry.second > maxFreq || (entry.second == maxFreq && entry.first < result)) {
                result = entry.first;
                maxFreq = entry.second;
            }
        }
        cout << result << endl;
    }
    return 0;
}
