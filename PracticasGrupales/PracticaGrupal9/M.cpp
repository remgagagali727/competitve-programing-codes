#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, p, g;
    cin >> n >> m >> p >> g;
    vector<vector<pair<ll,ll>>> adj(n + 1);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<ll> d(n + 1, LLONG_MAX);
    vector<int> active(n + 1); 
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[p] = 0;
    active[g] = 1;
    active[p] = 2;
    pq.push({0, p});
    while(!pq.empty()) {
        ll v = pq.top().second;
        ll dv = pq.top().first;
        pq.pop();
        if(dv != d[v]) continue;
        for(auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;
            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                active[to] = active[v];
                if(to == g) active[to] = 1;
                pq.push({d[to], to});
            } else if((d[v] + len == d[to]) && (active[to] == 1) && (active[v] == 2) && (to != g)) {
                active[to] = active[v];
                pq.push({d[to], to});
            }
        }
    }
    set<pii> st;
    for(int i = 1;i <= n;i++) {
        if(active[i] == 1) {
            st.insert({d[i], i});
        }
    }
    vector<ll> imprimir;
    auto it = st.lower_bound({d[g] * 2, 0});
    while(it != st.end()) {
        if((*it).first > d[g] * 2) break;
        imprimir.push_back((*it).second);
        it++;
    }
    if(imprimir.size() == 0) {
        cout << "*\n";
    } else {
        for(auto x : imprimir) cout << x << " ";
        cout << '\n';
    }
}