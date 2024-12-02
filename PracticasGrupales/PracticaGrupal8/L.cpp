#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    ll k;
    cin >> s >> k;
    string pattern;
    pattern = s[0];
    ll idx = 1;
    ll ans = 1;
    for(ll i = 1;i < s.size();i++) {
        if(idx < k) {
            pattern += s[i];
            idx++;
        } else {
            if(pattern[idx % k] == s[i]) {
                idx++;
            } else {
                pattern = s[i];
                idx = 1;
                ans++;
            }
        }
    }
    cout << ans << '\n';
}