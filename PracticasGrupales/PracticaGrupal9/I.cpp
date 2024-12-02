#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> bit;

ll ss;

const ll mod = 1e9 + 7;

ll expBin(ll base, ll exp, ll mod) {
    if(exp == 0) return 1;
    ll d = expBin(base, exp / 2, mod);
    d %= mod;
    d *= d;
    d %= mod;
    if(exp & 1) {
        d *= base;
        d %= mod;
    }
    return d;
}

void update(ll idx, ll delta) {
    for(;idx < ss;idx = idx | (idx + 1))
        bit[idx] += delta;
}

ll sum(ll r) {
    ll ret = 0;
    for(; r >= 0;r = (r & (r + 1)) - 1)
        ret+=bit[r];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    ll n;
    cin >> s >> n;
    n %= mod;
    ss = s.size();
    vector<ll> indices(ss);
    bit.resize(ss);
    for(ll i = 0;i < ss;i++) indices[i] = i;
    sort(indices.begin(), indices.end(), [&s](ll i, ll j){
        if(s[i] == s[j]) return i > j;
        return s[i] > s[j];
    });
    ll inversiones = 0;
    for(ll i = 0;i < ss;i++) {
        inversiones += sum(indices[i]);
        update(indices[i], 1);
        inversiones %= mod;
    }
    inversiones *= n;
    inversiones %= mod;
    sort(s.begin(), s.end());
    ll otrasInversiones = 0;
    ll conteo = 1;
    char last = s[0];
    for(ll i = 1;i < ss;i++) {
        if(s[i] == last) {
            conteo++;
        } else {
            otrasInversiones += conteo * (ss - i);
            otrasInversiones %= mod;
            conteo = 1;
        }
        last = s[i];
    }
    otrasInversiones *= expBin(2, mod - 2, mod);
    otrasInversiones %= mod;
    otrasInversiones *= n;
    otrasInversiones %= mod;
    otrasInversiones *= (n - 1);
    otrasInversiones %= mod;
    cout << (inversiones + otrasInversiones) % mod << '\n';
}