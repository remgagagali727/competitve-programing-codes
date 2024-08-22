#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

class Graph {

    const int INF = 1000000000;
    vector<vector<pair<int, int>>> adj;
    int n;

    public:

    Graph(int _n) {
        adj.resize(_n);
        n = _n;
    }

    void add(int u, int v, int weight) {
        adj[u].push_back(make_pair(v,weight));
        adj[v].push_back(make_pair(u,weight));
    }

    void dijkstra(int s, vector<int> & d, vector<int> & p) {
        d.assign(n, INF);
        p.assign(n, -1);
        vector<bool> u(n, false);

        d[s] = 0;
        for (int i = 0; i < n; i++) {
            int v = -1;
            for (int j = 0; j < n; j++) {
                if (!u[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            }

            if (d[v] == INF)
                break;

            u[v] = true;
            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n+1);
    vector<int> d(n), p(n);
    for(int i = 0;i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        g.add(u,v,w);
    }
    g.dijkstra(n,d,p);
    if(p[1]!=-1) {
        for(int t = 1;t != -1;t = p[t]) {
            cout << t << " ";
        };
    } else {
        cout << -1 << nl;
    }
    return 0;
}
