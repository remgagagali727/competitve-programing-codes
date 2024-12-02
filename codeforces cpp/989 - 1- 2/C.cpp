#include <bits/stdc++.h>

using namespace std;

#define TRAPPED 3
#define CURRENT 2
#define EXIT 1
#define NOT_VIS 0

bool dfs(int i, int j, vector<string> const &  s, vector<vector<int>>& v) {
    if(i < 0 || i >= s.size() || j < 0 || j >= s[0].size()) return false;
    if(v[i][j] == CURRENT || v[i][j] == TRAPPED) {
        return true;
    }
    if(v[i][j] == EXIT) {
        return false;
    }
    bool ans = false;
    v[i][j] = CURRENT;
    if(s[i][j] == 'U') {
        ans = dfs(i - 1, j, s, v);
    } else if(s[i][j] == 'D') {
        ans = dfs(i + 1, j, s, v );
    } else if(s[i][j] == 'L') {
        ans = dfs(i, j - 1, s, v );
    } else if(s[i][j] == 'R') {
        ans = dfs(i, j + 1, s, v );
    } else {
        ans |= dfs(i - 1, j, s, v );
        ans |= dfs(i + 1, j, s, v );
        ans |= dfs(i, j + 1, s, v );
        ans |= dfs(i, j - 1, s, v );
    }
    if(ans) {
        v[i][j] = TRAPPED;
    } else {
        v[i][j] = EXIT;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> mx(n);
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i = 0;i < n;i++) {
            cin >> mx[i];
        }
        int ans = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(vis[i][j] != NOT_VIS) continue;
                dfs(i, j, mx, vis);
            }
        }
        for(auto x : vis) {
            for(auto y : x) {
                if(y == TRAPPED) ans ++;
            }
        }
        cout << ans << '\n';
    }
}