#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> re(n, vector<int>(m));
    vector<vector<int>> ma(n, vector<int>(m));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            ma[i][j] = i * m + 1 + j;
        }
    }   
    if(n == m && n == 1) {
        cout << "YES \n";
        cout << "1" << '\n';
        return 0;
    }
    if(n < m) {
        if(n < 2 || m < 3 || (n == 2 && m == 3)) {
            cout << "NO" << '\n';
            return 0;
        }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(i & 1) {
                    if(j & 1) {
                        re[i][j] = ma[(i + 1) % n][(j + 2) % m];
                    } else {
                        re[i][j] = ma[i][(j + 2) % m];
                    }
                } else {
                    if(j & 1) {
                        re[i][j] = ma[(i + 1) % n][j];
                    } else {
                        re[i][j] = ma[i][j];
                    }
                }
            }
        }
        cout << "YES" << '\n';
        for(auto x : re) {
            for(auto y : x) {
                cout << y << ' ';
            }
            cout << '\n';
        }
    } else {
        if(m < 2 || n < 3) {
            cout << "NO" << '\n';
            return 0;
        }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(i & 1) {
                    if(j & 1) {
                        re[i][j] = ma[(i + 2) % n][(j + 1) % m];
                    } else {
                        re[i][j] = ma[i][(j + 1) % m];
                    }
                } else {
                    if(j & 1) {
                        re[i][j] = ma[(i + 2) % n][j];
                    } else {
                        re[i][j] = ma[i][j];
                    }
                }
            }
        }
        cout << "YES" << '\n';
        for(auto x : re) {
            for(auto y : x) {
                cout << y << ' ';
            }
            cout << '\n';
        }
    }   
}