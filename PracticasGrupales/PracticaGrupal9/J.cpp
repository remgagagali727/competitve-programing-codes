#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> adj;
vector<int> subtree_size;
vector<int> min_dist;
vector<int> val_dist;
vector<bool> is_removed;
vector<vector<pair<int, int>>> ancestors;

int get_subtree_size(int node, int parent = -1) {
	subtree_size[node] = 1;
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

int get_centroid(int node, int tree_size, int parent = -1) {
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		if (subtree_size[child] * 2 > tree_size) {
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}

/**
 * Calculate the distance between current `node` and the `centroid` it belongs
 * to. The distances between a node and all its centroid ancestors are stored
 * in the vector `ancestors`.
 * @param cur_dist the distance between `node` and `centroid`
 */
void get_dists(int node, int centroid, int parent = -1, int cur_dist = 1) {
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		cur_dist++;
		get_dists(child, centroid, node, cur_dist);
		cur_dist--;
	}
	ancestors[node].push_back({centroid, cur_dist});
}

void build_centroid_decomp(int node = 0) {
	int centroid = get_centroid(node, get_subtree_size(node));

	/*
	 * For all nodes in the subtree rooted at `centroid`, calculate their
	 * distances to the centroid
	 */
	for (int child : adj[centroid]) {
		if (is_removed[child]) { continue; }
		get_dists(child, centroid, centroid);
	}

	is_removed[centroid] = true;
	for (int child : adj[centroid]) {
		if (is_removed[child]) { continue; }
		// build the centroid decomposition for all child components
		build_centroid_decomp(child);
	}
}

// void paint(int node) {
// 	for (auto &[ancestor, dist] : ancestors[node]) {
// 		min_dist[ancestor] = min(min_dist[ancestor], dist);
// 	}
// 	min_dist[node] = 0;
// }

void paint(int node) {
	for (auto &[ancestor, dist] : ancestors[node]) {
        if(dist < min_dist[ancestor]) {
    		min_dist[ancestor] = dist;
            val_dist[ancestor] = node;
        } else if(dist == min_dist[ancestor] && val_dist[ancestor] > node) {
            val_dist[ancestor] = node;
        }
	}
	min_dist[node] = 0;
    val_dist[node] = node;
}

int query(int node) {
	int ans = min_dist[node];
    int pans = val_dist[node];
	for (auto &[ancestor, dist] : ancestors[node]) {
		if (!dist) { continue; }
        if(dist + min_dist[ancestor] < ans) {
            ans = dist + min_dist[ancestor];
            pans = val_dist[ancestor];
        } else if((dist + min_dist[ancestor] == ans) && val_dist[ancestor] < pans) {
            pans = val_dist[ancestor];
        }
	}
	return pans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
	adj.assign(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	subtree_size.assign(n, 0);
	ancestors.assign(n, vector<pair<int, int>>());
	is_removed.assign(n, false);
	build_centroid_decomp();

	min_dist.assign(n, INF);
    val_dist.resize(n);
    vector<int> ans;
    ans.push_back(n);
    for(int i = n - 1;i > 0;i--) {
        paint(i);
        ans.push_back(query(i - 1) + 1);
    }
    for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i] << " ";
}