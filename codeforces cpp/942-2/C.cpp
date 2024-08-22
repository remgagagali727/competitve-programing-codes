#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    ll n, k;
    ll ans;
    cin >> n >> k;
    vector<ll> a(n);
    int i;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(i = 1;i < n;i++){
        ll remove = (a[i] - a[i-1])*i;
        if(remove > k) {
            a[0] += k / i + a[i-1];
            i -= k % i;
            break;
        }
        k -= remove;
    }

    if(i == n) {
        ans = a[i - 1] * n + k;
    } else {
        ans = a[0] * n + (n - i);
    }

    cout << "i - 1  : " << a[i-1] << " ans : " << ans << " ";

    cout << (ans - n + 1) << nl;

}

int main() {
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
