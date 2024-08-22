#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> matrix(n,vector<ll>(m));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> matrix[i][j];

        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            ll val = matrix[i][j];
            ll neigh = 0;
            if(i != 0) neigh = matrix[i-1][j];
            if(i != n - 1) neigh = max(neigh,matrix[i+1][j]);
            if(j != 0) neigh = max(neigh,matrix[i][j-1]);
            if(j != m - 1) neigh = max(neigh,matrix[i][j+1]);
            matrix[i][j] = min(val,neigh);
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
