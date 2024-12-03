#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1005];
int n, m;
/*
5 4
2 5
4 1
4 2
4 3
*/
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    for(int i=1; i<=n; ++i){
        cout << i << " : ";
        sort(ke[i].begin(), ke[i].end());
        for(int x : ke[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}