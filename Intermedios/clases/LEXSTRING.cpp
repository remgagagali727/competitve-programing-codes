#include <bits/stdc++.h>

using namespace std;

string s;
vector<vector<int>> adj;
vector<string> sv;
vector<int> visited;

string dfs(int v, int id) {
    string ret(1, s[v]);
    visited[v] = id;
    for(auto u : adj[v]) {
        if(visited[u]) continue;
        ret = ret + dfs(u, id);
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> s;
        int n;
        cin >> n;
        adj.resize(s.size());
        for(int i= 0;i< n;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        sv.push_back("");
        int id = 1;
        visited = vector<int>(s.size());
        for(int i = 0;i < s.size();i++) {
            if(visited[i]) continue;
            sv.push_back(dfs(i, id++));
        }
        for(int i = 1;i < sv.size();i++) {
            sort(sv[i].begin(), sv[i].end());
        }
        vector<int> indice(sv.size());
        string ans = "";
        for(int i = 0;i < s.size();i++) {
            ans += sv[visited[i]][indice[visited[i]]++];
        }
        cout << ans << '\n';
    }    
}