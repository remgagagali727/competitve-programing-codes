#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    vector<ll> tams;
    vector<bool> visited(n + 1);
    for(int i = 1;i <= n;i++) {
        if(visited[i]) continue;
        visited[i] = true;
        ll tAns = 1;
        int goingto = a[i];
        while(goingto != i) {
            visited[goingto] = true;
            goingto = a[goingto];
            tAns ++;
        }
        tams.push_back(tAns);
    }
    tams.push_back(0);
    sort(tams.begin(), tams.end());
    n = tams.size();
    ll ans = 0;
    for(int i = 0;i < n - 2;i++) {
        ans += tams[i] * tams[i];
    }
    ans += (tams[n - 1] + tams[n - 2]) * (tams[n - 1] + tams[n - 2]);
    cout << ans << '\n';
}