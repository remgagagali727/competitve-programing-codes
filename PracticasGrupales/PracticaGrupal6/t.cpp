#include <bits/stdc++.h>

using ll = long long;
using namespace std;

vector<int> primos;
vector<ll> valores;
vector<vector<int>> adj(61);


int dfs(int v, int p, ll acum, int i) {
    acum *= primos[i];
    valores[v] = acum;
    for(auto u : adj[v]) {
        if(u == p) continue;
        i = dfs(u, v, acum, i);
    }
    i++;
    return i;
}

int main() {
    int n;
    cin >> n;
    valores.resize(n + 1);
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int a = 2;
    while(primos.size() < 60) {
        bool posible = true;
        for(auto x : primos) {
            if(a % x == 0) {
                posible = false;
                break;
            }
        }
        if(posible) primos.push_back(a);
        a++;
    }
    dfs(1, -1, 1, 0);
    for(int i = 1;i <= n;i++) {
        cout << valores[i] << " ";
    }
    cout << endl;
    return 0;
}
