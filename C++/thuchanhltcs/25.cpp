#include <bits/stdc++.h>
using namespace std;
struct SV{
	char hoten[40]; // ghi doc ghi tep tin voi cau truc nen su dung char[];
	int namsinh;
	float diemtb;
};
void nhapSV(SV &a){
    fflush(stdin);
	cout << "\n Ho ten:";
	fflush(stdin); // cin.ignore();
	cin.getline(a.hoten, 40);
	cout << "\n Nam sinh:"; cin >> a.namsinh;
	cout << "\n Diem TB:"; cin >> a.diemtb;
    cin.ignore(1);
}
void hienSV(SV a){
	cout << endl << setw(30) << setiosflags(ios::left) << a.hoten
	     << setw(10) << a.namsinh
	     << setw(10) << a.diemtb;
}
//---
void nhapDanhsach(SV arr[], int n){
    for(int i=0; i<n; ++i)
        nhapSV(arr[i]);
}
void hienDanhsach(SV arr[], int n){
    for(int i=0; i<n; ++i)
        hienSV(arr[i]);
}
fstream f;
void ghiFile(SV arr[], int n){
    f.open("SV23.data", ios::out|ios::binary);
    if(!f.is_open()){
        cout << "\n Loi mo tep tin";
        return;
    }
    for(int i=0; i<n; ++i){
        f.write((char *)&arr[i],sizeof(SV));
    }
    cout << "\n Ghi tep thanh cong";
    f.close();
}
/*void docFile(){
	f.open("F:\\SV23.data", ios::in|ios::binary);
	if(!f.is_open()){
		cout << "\n Loi mo tep!";
		return;
	}

	SV tmp;
	while(1){ // lap vo hoan
		f.read((char *)&tmp,sizeof(SV));
		if(f.eof()) break;
		hienSV(tmp);
	}
}*/

void docFile(SV arr2[], int &m){

	f.open("SV23.data", ios::in|ios::binary);
	if(!f.is_open()){
		cout << "\n Loi mo tep!";
		return;
	}
	//doc tep
	SV tmp;
	m=0;
	while(1){ // lap vo hoan
		f.read((char *)&tmp,sizeof(SV));
		if(f.eof()) break;
		arr2[m]=tmp;
		m++;
	}
}
void sapxepDS(SV arr[], int n){
	for(int i=0; i<n-1; ++i)
		for(int j=i+1; j<n; ++j){
			//if(arr[i].diemtb<arr[j].diemtb)
			if(strcmp(arr[i].hoten, arr[j].hoten)<0)
				swap(arr[i], arr[j]);
		}
}
int main(){
	SV arr[10],b[10];
	int n=2;
	int m=0;
    nhapDanhsach(arr,n);
    cout << "\n DANH SACH SINH VIEN";
    hienDanhsach(arr, n);
    ghiFile(arr,n);
	cout << "\n NOI DUNG TEP TIN";
//	docFile();
	docFile(b,m);
	hienDanhsach(b,m);
	sapxepDS(b,m);
	cout << "\n Danh sach sau sap xep";
	hienDanhsach(b,m);
	return 0;

}
