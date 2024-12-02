#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 2, vector<int>(m + 2));
    set<int> moviments;
    vector<bool> vis(n * m + 1);
    vector<pair<int, int>> mp(n * m + 1);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> arr[i][j];
            mp[arr[i][j]] = {i, j};
        }
    }
    int ans = 0;
    int tAns = 0;
    moviments.insert(INT_MAX);
    for(int i = 1;i <= n * m;i++) {
        if(vis[i]) continue;
        moviments.insert(i);
        while(1 < moviments.size()) {
            tAns += 1;
            auto v = *moviments.begin();
            vis[v] = true;
            moviments.erase(moviments.find(v));
            auto p = mp[v];
            if(arr[p.first - 1][p.second] > v) {
                moviments.insert(arr[p.first - 1][p.second]);
            }
            if(arr[p.first + 1][p.second] > v) {
                moviments.insert(arr[p.first + 1][p.second]);
            }
            if(arr[p.first][p.second - 1] > v) {
                moviments.insert(arr[p.first][p.second - 1]);
            }
            if(arr[p.first][p.second + 1] > v) {
                moviments.insert(arr[p.first][p.second + 1]);
            }
        }
        ans = max(tAns, ans);
        tAns = 0;
    }
    cout << ans << '\n';
}