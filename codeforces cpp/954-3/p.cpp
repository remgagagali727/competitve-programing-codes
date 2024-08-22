#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define lll     __int128_t
#define all(a)  a.begin(),a.end()

using namespace std;



void sol() {
    ll n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    int k, p;
    cin >> k >> p;
    int l = 0, r = n-1;
    multiset<ll> ms;
    while(k--) {
        if(ms.size() < p) {
            if(a[l] + b[l] > a[r] + b[r]) {
                ms.insert(b[l]);
            } else {
                
            }
        } else {

        }
    }
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
