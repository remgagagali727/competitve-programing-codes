#include <bits/stdc++.h>

using ll = long long;
using namespace std;

vector<int> primos;
vector<ll> valores;
vector<vector<int>> adj(61);

bool qry(ll i) {
    cout << "buf[" << i << "]\n";
    cout.flush();
    ll x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll last = 2;
    ll next = 4;
    while(qry(next - 1)) {
        last = next;
        next *= 2;
    }
    ll l = last, r = next;
    while(l + 1 < r) {
        ll m = (l + r) / 2;
        if(qry(m - 1)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << "strlen(buf) =  " << l << endl;
}
