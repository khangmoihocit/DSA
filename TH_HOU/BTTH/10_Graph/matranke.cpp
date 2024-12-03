#include <bits/stdc++.h>
using namespace std;

int a[1005][1005];
int n, m; //n: số đỉnh, m: số cạnh
/*
5 4
4 3
3 1
4 2
5 4
*/
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int x, y; cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
}