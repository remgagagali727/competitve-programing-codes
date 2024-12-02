#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y, k;
        cin >> x >> y >> k;
        int maxv = min(x, y);
        cout << 0 << " " << 0 << " " << maxv << " " << maxv << '\n';
        cout << 0 << " " << maxv << " " << maxv << " " << 0 << '\n';
    }
}