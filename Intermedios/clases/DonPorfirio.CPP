#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct dsun{
    ll tam = 1;
    dsun() {
        tam = 1;
    }
};

vector<dsun> dsu;
vector<int> parent;

const ll mod = 1e9 + 7;

int find(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

ll unir(int u, int v, int peso) {
    u = find(u);
    v = find(v);
    if(u == v) return 0;
    if(dsu[u].tam > dsu[v].tam) swap(u,v);
    ll toRet = dsu[u].tam * dsu[v].tam * peso;
    parent[u] = v;  
    dsu[v].tam += dsu[u].tam;
    return toRet;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> aristas(n - 1);
    dsu.resize(n + 1);
    parent.resize(n + 1);
    for(int i = 1;i <= n;i++) parent[i] = i;
    for(int i = 0;i < n - 1;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        aristas[i] = {w, u, v};
    }
    sort(aristas.begin(), aristas.end());
    ll ans = 0;
    for(int i = 0;i < aristas.size();i++) {
        ans += unir(aristas[i][1], aristas[i][2], aristas[i][0]);
        ans %= mod;
    }
    cout << ans << '\n';
}