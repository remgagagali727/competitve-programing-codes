#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        stack<ll> a;
        stack<ll> b;
        for(int i = 0;i < n;i++) {
            if(s[i] == '0') {
                ans += i + 1;
                a.push(i + 1);
            } else {
                b.push(i + 1);
            }
        }
        while(!b.empty()) {
            if(!a.empty()) {
                while(a.top() > b.top()) {
                    a.pop();
                    if(a.empty()) break;
                }
            }
            if(a.empty()) break;
            a.pop(); b.pop();
        }
        int rem = b.size() / 2;
        while(rem--) b.pop();
        while(!b.empty()) {
            ans += b.top();
            b.pop();
        }
        cout << ans << '\n';
    }
}