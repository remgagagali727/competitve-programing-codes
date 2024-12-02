#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct nodo{
    ll v;
    ll dis;
    nodo() {}
    nodo(ll _v, ll _dis) {
        v = _v;
        dis = _dis;
    }
};

vector<ll> res;
vector<vector<nodo>> adj;
vector<vector<pair<ll , ll>>> querys;

vector<ll> best_leaf;
vector<ll> best_dis;
vector<ll> second_leaf;
vector<ll> second_dis;

vector<ll> cantidad;

void precalculo(ll v, ll p) {
    if(adj[v].size() == 1) {
        best_leaf[v] = v;
        best_dis[v] = 0;
    } else {
        best_leaf[v] = best_dis[v] = INT_MAX;
    }
    second_dis[v] = second_leaf[v] = INT_MAX;
    for(auto u : adj[v]) {
        if(u.v == p) continue;
        precalculo(u.v, v);
        ll hijo = u.v;
        if(best_dis[hijo] + u.dis < second_dis[v] || (best_dis[hijo] + u.dis == second_dis[v] && best_leaf[hijo] < second_leaf[v])) {
            second_dis[v] = best_dis[hijo] + u.dis;
            second_leaf[v] = best_leaf[hijo];
            if(second_dis[v] + u.dis < best_dis[v] || (second_dis[v] + u.dis == best_dis[v] && second_leaf[v] < best_leaf[v])) {
                swap(second_dis[v], best_dis[v]);
                swap(second_leaf[v], best_leaf[v]);
            }
        }
    }
    cantidad[best_leaf[v]]++;
}

void responder(ll v, ll p) {
    for(auto q : querys[v]) {
        res[q.second] = cantidad[q.first];
    }
    for(auto u : adj[v]) {
        ll hijo = u.v;
        if(hijo == p) continue;
        if(best_leaf[hijo] == best_leaf[v]) {
            cantidad[best_leaf[v]]--;
            ll bl = best_leaf[v];
            ll bd = best_dis[v];
            best_leaf[v] = second_leaf[v];
            best_dis[v] = second_dis[v];
            cantidad[best_leaf[v]]++;
            responder(hijo, v);
            cantidad[best_leaf[v]]--;
            best_leaf[v] = bl;
            best_dis[v] = bd;
            cantidad[best_leaf[v]]++;
        } else {
            ll sd = best_dis[v];
            ll sl = best_leaf[v];
            ll cambio = 0;
            if(best_dis[v] + u.dis < best_dis[hijo] || (best_dis[v] + u.dis == best_dis[hijo] && best_leaf[v] < second_leaf[hijo])) {
                cambio = 1;
                sd = best_dis[hijo];
                sl = best_leaf[hijo];
                cantidad[best_leaf[hijo]]--;
                cantidad[best_leaf[v]]++;
                best_dis[hijo] = best_dis[v] + u.dis;
                best_leaf[hijo] = best_leaf[v];
            } else if(best_dis[v] + u.dis < second_dis[hijo] || (best_dis[v] + u.dis == second_dis[hijo] && best_leaf[v] < second_leaf[hijo])) {
                cambio = 2;
                sd = second_dis[hijo];
                sl = second_leaf[hijo];
                second_dis[hijo] = best_dis[v] + u.dis;
                second_leaf[hijo] = best_leaf[v];
            }
            responder(hijo, v);
            if(cambio == 1) {
                best_leaf[hijo] = sl;
                best_dis[hijo] = sd;
                cantidad[best_leaf[hijo]]++;
                cantidad[best_leaf[v]]--;
            } else if(cambio == 2) {
                second_leaf[hijo] = sl;
                second_dis[hijo] = sd;
            }
        }
    }
}

int main() {
    ll n;
    cin >> n;
    adj.resize(n + 1);
    best_dis.resize(n + 1);
    best_leaf.resize(n + 1);
    second_dis.resize(n + 1);
    second_leaf.resize(n + 1);
    querys.resize(n + 1);
    cantidad.resize(n + 1);
    for(ll i = 1;i < n;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(nodo(v,w));
        adj[v].push_back(nodo(u,w));
    }
    ll m;
    cin >> m;
    res.resize(m);
    for(ll i = 0;i < m;i++) {
        ll origen, destino;
        cin >> origen >> destino;
        querys[destino].push_back({origen, i});
    }
    precalculo(1, 0);
    responder(1, 0);
    for(auto x : res) {
        cout << x << " ";
    }
    cout << endl;
}