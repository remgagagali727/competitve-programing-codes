#include <bits/stdc++.h>

using ll = long long;
using namespace std;

vector<ll> primos;
vector<ll> valores(62);
vector<ll> pesos(62);
vector<vector<ll>> adj(62);
vector<bool> visited(62);

ll dfst(ll v, ll p) {
    ll ans = 1;
    for(auto x : adj[v]) {
        if(x == p) continue;
        ans = max(1 + dfst(x, v), ans);
    }
    return pesos[v] = ans;
}

struct cosas{
    ll acum;
    ll nodo;
    ll miprimo;
};

bool compare(cosas a, cosas b) {
    if(pesos[a.nodo] == pesos[b.nodo]) {
        a.acum > b.acum;
    }
    return pesos[a.nodo] > pesos[b.nodo];
}

int main() {
    
    return 0;
}
