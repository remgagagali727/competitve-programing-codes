#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int red, blue;
        cin >> red >> blue;
        int conds;
        cin >> conds;
        vector<vector<int>> adj(conds + 2);
        vector<pii> c(conds + 2);
        for(int i = 0;i < conds;i++) {
            cin >> c[i].first >> c[i].second;
        }
        c[conds] = {red, blue};
        c[conds + 1] = {0, 0};
        for(int i = 0;i < conds;i++) {
            for(int j = 0;j < conds;j++) {
                if(c[i].first > c[j].first && c[i].second > c[j].second) {
                    adj[i].push_back(j);
                }
            }
        }
        for(int i = 0;i < conds + 2;i++) sort(adj[i].rbegin(), adj[i].rend());       
    }
}