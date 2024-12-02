#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define nl          "\n"
#define pb          push_back
#define ll          long long
#define ull         unsigned long long
#define ld          long double
#define uld         unsigned long double
#define lll         __int128_t
#define ulll        unsigned __int128_t
#define all(a)      a.begin(),a.end()
#define rall(a)     a.rbegin(),a.rend()
#define swap(a,b)   auto t = a; a = b; b = t
#define tswap(a,b)  t = a; a = b; b = t
#define ullinf      LONG_LONG_MAX
#define INF         INT_MAX
#define in(x,a,b)   x > a && x < b
#define unqueue(a)  a.front(); a.pop();
#define unstack(a)  a.top(); a.pop();

using namespace std;
using namespace __gnu_pbds;

const ll mod = 1000000007;

bool sepuede(int tam, vector<ll>& stalls, int caballos) {
    int last = -tam;
    for(int i = 0;i < stalls.size();i++) {
        if(stalls[i] - tam >= last) {
            last = stalls[i];
            caballos--;
        }
    }
    return caballos <= 0;
}

void sol() {
    int n, c;
    cin >> n >> c;
    vector<ll> stalls(n);
    for(int i = 0;i < n;i++) cin >> stalls[i];
    sort(all(stalls));
    int l = 1, r = stalls[n - 1] + 1;
    while(l + 1 < r) {
        int m = (r + l) / 2;
        if(sepuede(m, stalls, c)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << nl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}