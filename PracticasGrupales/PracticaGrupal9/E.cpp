#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s;
    cin >> n >> s;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    for(int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<int, vector<int>, greater<int>> st;
    ll valor = 1;
    ll ans = 0;
    st.push(s);
    while(!st.empty()) {
        auto v = st.top(); st.pop();
        ans += v * valor;
        visited[v] = true;
        valor++;
        for(auto u : adj[v]) {
            if(visited[u]) continue;
            st.push(u);
        }
    }
    cout << ans << '\n';
}