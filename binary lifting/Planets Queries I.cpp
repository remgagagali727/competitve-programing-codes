#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> padre(n, vector<int>(30));
    for(int i = 0;i < n;i++) {
        cin >> padre[i][0];
        padre[i][0]--;
    }
    for(int i = 1;i < 30;i++) {
        for(int j = 0;j < n;j++) {
            padre[j][i] = padre[padre[j][i - 1]][i - 1];
        }
    }
    while(q--) {
        long n, k;
        cin >> n >> k;
        n--;
        int idx = 0;
        while(k >= 1 << idx) {
            if(k & 1 << idx) {
                n = padre[n][idx];
            }
            idx++;
        }
        cout << n + 1 << '\n';
    }
}