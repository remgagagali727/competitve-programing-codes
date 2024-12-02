#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<pair<int, int>> rangos(n);
        for(int i = 0;i < n;i++) {
            cin >> rangos[i].first >> rangos[i].second;
        }
        vector<pair<int, int>> powerUps(m);
        for(int i = 0;i < m;i++) {
            cin >> powerUps[i].first  >> powerUps[i].second;
        }
        int i = 0, j = 0;
        priority_queue<int> pq;
        int pw = 0;
        int ans = 0;
        bool posible = true;
        while(i < n) {
            if(j < m) {
                while(powerUps[j].first < rangos[i].first) {
                    pq.push(powerUps[j].second);
                    j++;
                    if(j == m) break;
                }
            }
            if(!pq.empty())
            while(pw <= rangos[i].second - rangos[i].first) {
                pw += pq.top();
                ans++;
                pq.pop();
                if(pq.empty()) break;
            }
            if(pw <= rangos[i].second - rangos[i].first) {
                posible = false;
                break;
            }
            i++;
        }
        if(posible) {
            cout << ans << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}