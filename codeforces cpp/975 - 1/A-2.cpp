#include <bits/stdc++.h>

#define ll long long

using namespace std;

void casito() {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxv = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        maxv = max(maxv, a[i]);
    }
    ll ans = 0;
    bool tomado = !(n % 2);
    for(int i = 0;i < n;i += 2){
        ans++;
        if(a[i] == maxv) tomado = true;
    }
    if(!tomado) ans--;
    cout << ans + maxv << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) casito();
}