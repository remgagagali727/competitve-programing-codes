#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> fkt(n + 1);
    auto update = [&fkt](int r, int delta) -> void {
        int n = fkt.size();
        for(;r < n; r = r | (r + 1))
            fkt[r] += delta;
    };
    auto sum = [&fkt](int r) -> int {
        int toRet = 0;
        int n = fkt.size();
        for(;r >= 0; r = (r & (r + 1)) - 1)
            toRet += fkt[r];
        return toRet;
    };
    vector<int> last(m + 1, -1);
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector<vector<int>> queris(n);
    for(int i = 0;i < n;i++) {
        queris[last[a[i]] + 1].push_back(i);
        last[a[i]] = i;
    }
    ll ans = 0;
    ll used, notused;
    used = notused = 0;
    notused--;
    for(auto x : last) {
        if(x == -1) notused++;
        else used++;
    }
    // ans += used * notused;
    last = vector<int>(m + 1, n);
    vector<int> next(n);
    for(int i = n - 1;i >= 0;i--) {
        next[i] = last[a[i]];
        last[a[i]] = i;
    }
    vector<int> unique(n);
    vector<bool> vis(m + 1);
    unique[0] = 1;
    vis[a[0]] = true;
    for(int i = 1;i < n;i++) {
        unique[i] = unique[i - 1];
        if(!vis[a[i]]) {
            vis[a[i]] = true;
            unique[i]++;
        }
    }
    cout << ans << '\n';
    for(int i = 0;i < n;i++) {
        for(auto q : queris[i]) {
            cout << i << " " << q << '\n';
            cout << sum(q) << " " << unique[q] << '\n';
            cout << sum(i) << " " << unique[i] << '\n';
            cout << "------\n";
            ans += (sum(q) - sum(i) + unique[q] - unique[i]) * 2;
        }
        update(i, -1);
        update(next[i], 1);
    }
    cout << ans << '\n';
}