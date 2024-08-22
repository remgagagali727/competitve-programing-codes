#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    int n, m, k;
    ll cur = 0;
    ll ans = 0;
    cin >> n >> m >> k;
    vector<ll> a(n);
    multiset<ll> A;
    multiset<ll> B;
    multiset<ll> P;


    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    for(int i = 0;i < m;i++) {
        ll h;
        cin >> h;
        B.insert(h);
    }

    for(int i = 0;i < m;i++) {
        auto t = B.find(a[i]);
        if(t != B.end()) {
            B.erase(t);
            P.insert(a[i]);
            cur++;
        } else {
            A.insert(a[i]);
        }
    }
    if(cur >= k) ans++;
    for(int i = m;i < n;i++){
        auto t = A.find(a[i-m]);
        if(t != A.end()){
            A.erase(t);
        } else {
            t = P.find(a[i-m]);
            P.erase(t);
            B.insert(a[i-m]);
            cur--;
        }
        t = B.find(a[i]);
        if(t != B.end()) {
            B.erase(t);
            P.insert(a[i]);
            cur++;
        } else {
            A.insert(a[i]);
        }
        if(cur >= k) ans++;
    }

    cout << ans << nl;

}

int main() {
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
