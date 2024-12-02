#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];
        vector<int> cub(3);
        vector<pair<int, int>> ans;
        set<int> p1;
        set<int> p2;
        for(int i = 0 ;i < n;i++) {
            cub[a[i]]++;
            if(a[i] == 1) {
                p1.insert(i);
            }
            if(a[i] == 2) {
                p2.insert(i);
            }
        }
        int it = n - 1;
        int l1, l2;
        for(;cub[2] > 0;cub[2]--, it--) {
            if(a[it] == 2) continue;
            if(a[it] == 0) {
                l1 = *p1.begin();
                p1.erase(p1.find(l1));
                p1.insert(it);
                ans.push_back({l1 + 1, it + 1});
                a[it] = 1;
                a[l1] = 0;
            }
            l2 = *p2.begin();
            p2.erase(p2.find(l2));
            p2.insert(it);
            p1.erase(p1.find(it));
            p1.insert(l2);
            ans.push_back({l2 + 1, it + 1});
            a[it] = 2;
            a[l2] = 1;
        }
        for(;cub[1] > 0;cub[1]--, it--) {
            if(a[it] == 1) continue;
            l1 = *p1.begin();
            p1.erase(p1.find(l1));
            p1.insert(it);
            ans.push_back({l1 + 1, it + 1});
            a[it] = 1;
            a[l1] = 0;
        }
        cout << ans.size() << '\n';
        for(auto x : ans) {
            cout << x.first << " " << x.second << '\n';
        }
    }
}

