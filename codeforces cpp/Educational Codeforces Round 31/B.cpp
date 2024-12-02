#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    int ans = n - 1;
    for(int i = 0;i < n;i++) {
        int a; cin >> a;
        ans += a;
    }
    if(ans == l) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
}