#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

    const int mod = 1'000'000'007;

    vector<ll> a(500'000+30);
    vector<ll> r(500'000+30);
    a[0] = 1;
    ll ans = 0;
    for(int i = 0;i <= 500'010;i++){
        //a[i]%=mod;
        if(a[i]!=0) {
            a[i+3] += a[i]*3;
            a[i+5] += a[i]*3;
            a[i+7] += a[i]*3;
            a[i+9] += a[i]*3;
            if(i >= 10) ans-= a[i-10];
            ans += a[i];
        }
        r[i] = ans;
    }

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        
        cout << r[n/2]%mod << "\n";
    }
}