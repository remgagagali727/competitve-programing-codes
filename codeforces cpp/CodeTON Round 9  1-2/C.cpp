#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x;
        ll m;
        cin >> x >> m;
        ll n = 1;
        while(n <= x) n *= 2;
        n = min(n, m);
        ll count = 0;
        for(int i = 1;i <= n;i++) {
            if(x == i) continue;
            int xr = i ^ x;
            if(i % xr == 0 || x % xr == 0) count++;
        }
        cout << count << '\n';
    }
}