#include <bits/stdc++.h>

using namespace std;

using ll = long long;   

vector<vector<ll>> adj;
vector<bool> visited1;

// vector<vector<ll>> biconnected_components(vector<vector<ll>>& g, vector<bool>& is_cutpoint, vector<ll>& id) {
//     int n = g.size();

//     vector<vector<ll>> comps;
//     vector<ll> stk;
//     vector<ll> num(n);
//     vector<ll> low(n);
//     vector<bool> visited(n);

//     is_cutpoint.resize(n);

//     function<void(int, int, int &)> dfs = [&](int node, int parent, int &timer) {
//         visited[node] = true;
// 		num[node] = low[node] = ++timer;
// 		stk.push_back(node);
// 		for (int son : g[node]) {
// 			if (son == parent) { continue; }
// 			if (num[son]) {
// 				low[node] = min(low[node], num[son]);
// 			} else {
// 				dfs(son, node, timer);
// 				low[node] = min(low[node], low[son]);
// 				if (low[son] >= num[node]) {
// 					is_cutpoint[node] = (num[node] > 1 || num[son] > 2);
// 					comps.push_back({node});
// 					while (comps.back().back() != son) {
// 						comps.back().push_back(stk.back());
// 						stk.pop_back();
// 					}
// 				}
// 			}
// 		}
// 	};

// 	int timer = 0;
//     for(int i = 0;i < n;i++) {
//         if(!visited[i]) dfs(i, -1, timer);
//     }
// 	id.resize(n);

// 	function<vector<vector<ll>>()> build_tree = [&]() {
// 		vector<vector<ll>> t;
// 		int node_id = 0;
// 		for (int node = 0; node < n; node++) {
// 			if (is_cutpoint[node]) {
// 				id[node] = node_id++;
// 				t.push_back({});
// 			}
// 		}

// 		for (auto &comp : comps) {
// 			int node = node_id++;
// 			t.push_back({});
// 			for (int u : comp)
// 				if (!is_cutpoint[u]) {
// 					id[u] = node;
// 				} else {
// 					t[node].push_back(id[u]);
// 					t[id[u]].push_back(node);
// 				}
// 		}
// 		return t;
// 	};

// 	return build_tree();
// }

int dfs(int v, int p, vector<vector<ll>> const& g) {
    int ans = 0;
    visited1[v] = true;
    ll hijos = 0;
    for(auto u : g[v]) {
        if(u == p) continue;
        hijos++;
        if(visited1[u]) {
            hijos--;
            continue;
        }
        ans += dfs(u, v, g);
    }
    if(hijos == 0) ans++;
    return ans;
}

int main() {
    iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited1.resize(n);
    // vector<ll> id;
    // vector<bool> is_cutpoint;
    // vector<vector<ll>> blockcut_tree = biconnected_components(adj, is_cutpoint, id);
    // n = blockcut_tree.size();
    vector<ll> hojas;
    for(int i = 0;i < n;i++) {
        if(visited1[i]) continue;
        hojas.push_back(dfs(i, -1, adj));
    }
    ll ans;
    if(hojas.size() == 1) {
        if(hojas[0] < 2) ans = hojas[0];
        else {
            ans = hojas[0] - 1;
        }
    } else {
        ans = hojas.size();
        ll hojasSobrantes = 0;
        for(auto x : hojas) {
            if(x > 2) hojasSobrantes += x - 2;
        }
        ans += (hojasSobrantes < 2 ? hojasSobrantes : hojasSobrantes - 1);
    }
    cout << ans << '\n';
}