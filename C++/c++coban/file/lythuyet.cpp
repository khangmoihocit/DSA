#include "bits/stdc++.h"
using namespace std;
// ifstream : doc file
// ofstream : ghi file, tao moi file
// fstream : ca doc va ghi file
int main(){
    // ios::in : doc file
    // ios::out : ghi file
    // ios::binary : mo file kieu nhi phan
    // ios::app : mo file de ghi nhung ghi vao cuoi file
    // ios::ate : doc vi cua con tro vao cuoi file, neu ma mode k duoc bat len thi vi tri con tro la dau file 
    // ios::trunc : mo file de doc, nhung noi dung truoc do trong file se bi mat het truoc khi ghi noi dung moi
    // if (in.is_open()) : ktra xem file co ton tai
    // in.close();
    // out.close(); dong file
    // in.open("datakhang.txt", ios::app); // file da co san
    // out.open("test.txt", ios::out); // tao file moi
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    // int n; in >> n;
    // out << n << endl;
    // for (int i=0; i<n; i++){
    //     int x; in >> x;
    //     out << x << ' ';
    // }
    string s, a;
    getline(in, s);
    getline(in, a);
    cout << s << endl << a;
    in.close();
    out.close();
}
