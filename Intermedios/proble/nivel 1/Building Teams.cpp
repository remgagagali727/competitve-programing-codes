#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
bool pos = true;

bool dfs(int v, int p, int c) {
    bool ans = true;
    visited[v] = c;
    for(auto u : adj[v]) {
        if(u == p) continue;
        if(visited[u] == c) {
            ans = false;
            continue;
        }
        if(visited[u]) continue;
        ans &= dfs(u, v, (c == 1 ? 2 : 1));
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++) {
        if(!visited[i]) {
            pos &= dfs(i, -1, 1);
        }
    }
    if(pos) {
        for(int i = 1;i <= n;i++) cout << visited[i] << " ";
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    } 
}
