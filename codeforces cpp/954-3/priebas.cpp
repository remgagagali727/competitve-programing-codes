#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define lll     __int128_t
#define all(a)  a.begin(),a.end()

using namespace std;

class Graph {
public:
    Graph(int n) : adjList(n), numNodes(n) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void convertToDAG() {
        unordered_set<int> visited;
        unordered_set<int> recStack;
        for (int i = 0; i < numNodes; ++i) {
            if (visited.find(i) == visited.end()) {
                detectAndRemoveCycles(i, visited, recStack);
            }
        }
    }

    int countNodesWithoutParents() const {
        unordered_set<int> nodesWithParents;
        for (const auto& neighbors : adjList) {
            for (int neighbor : neighbors) {
                nodesWithParents.insert(neighbor);
            }
        }

        int count = 0;
        for (int i = 0; i < numNodes; ++i) {
            if (nodesWithParents.find(i) == nodesWithParents.end()) {
                ++count;
            }
        }

        return count;
    }

    int countNodesWithoutChildren() const {
        int count = 0;
        for (const auto& neighbors : adjList) {
            if (neighbors.empty()) {
                ++count;
            }
        }
        return count;
    }

private:
    vector<vector<int>> adjList;
    int numNodes;

    bool detectAndRemoveCycles(int v, unordered_set<int>& visited, unordered_set<int>& recStack) {
        visited.insert(v);
        recStack.insert(v);

        for (auto it = adjList[v].begin(); it != adjList[v].end(); ) {
            int neighbor = *it;
            if (visited.find(neighbor) == visited.end()) {
                if (detectAndRemoveCycles(neighbor, visited, recStack)) {
                    return true;
                }
                ++it;
            } else if (recStack.find(neighbor) != recStack.end()) {
                // Ciclo detectado, eliminar la arista v -> neighbor
                it = adjList[v].erase(it);
                return true;
            } else {
                ++it;
            }
        }

        recStack.erase(v);
        return false;
    }
};

void sol() {
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    while(m--){
        ll a, b;
        cin >> a >> b;
        g.addEdge(a-1,b-1);
    }
    g.convertToDAG();
    cout << max(g.countNodesWithoutChildren(),g.countNodesWithoutParents());
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
