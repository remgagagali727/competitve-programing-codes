#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<bool> exist(n + 1);
        for(int i = 0;i < n;i++) {
            int a; cin >> a;
            exist[a] = true;
        }
        int sq = sqrt(n) + 1;
        int a, b;
        n-=2;
        for(int i = 1;i <= sq;i++) {
            if(n % i) continue;
            if(exist[i] && exist[n / i]) {
                a = i;
                b = n / i;
                break;
            }
        }
        cout << a << " " << b << '\n';
    }
}