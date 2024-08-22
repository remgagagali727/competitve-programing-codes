#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    string s,c;
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    cin >> s;
    for(int i = 0;i < m;i++) cin >> a[i];
    cin >> c;
    sort(all(c));
    sort(all(a));
    int prev = 0;
    int j = 0;
    for(int i : a) {
        if(i == prev) continue;
        s[i - 1] = c[j++];
        prev = i;
    }
    cout << s << nl;

}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
