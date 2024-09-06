#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi>
#define ppi pair<pi, int>
/*Xây dựng chương trình đặt tên tài khoản người dùng. Nếu tên người dùng muốn đặt
đã xuất hiện trong hệ thống thì sẽ đặt tên tài khoản theo cú pháp “tên người dùng
muốn đặt” +số tài khoản cùng tên trong hệ thống cộng thêm 1.
Ví dụ: Giả sử trong hệ thống đã tồn tại tên người dùng rech thì người dùng tiếp
theo muốn sử dụng tên tài khoản là rech sẽ được lưu ở hệ thống với tên rech1,
tương tự như vậy trong trường hợp có 2 tài khoản tên rech trong hệ thống thì người
dùng có tên rech sẽ được lưu với tên rech2.
Input
Dòng đầu tiên là n số lượng tên người dùng muốn cài đặt vào hệ thống, n dòng tiếp
theo sẽ là tên người dùng, tên người dùng chỉ bao gồm 1 từ duy nhất
Ouput
In kết quả là tên người dùng được lưu trong hệ thống.

14
an
binh
an
binh
long
huong
ngoc
thuan
nhung
nhung
ngoc thuan
nhung
nhung
nhung
*/
int main(){
	int n; cin >> n; cin.ignore();
	map<string, int> map;
	while(n--){
		string s; getline(cin, s);
		if(map.find(s) == map.end()){
			map[s] = 0;
			cout << s << endl;
		}else{
			map[s]++;
			cout << s << map[s] << endl;
		}
	}
	return 0;
}