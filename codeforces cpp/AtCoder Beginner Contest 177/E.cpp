#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

vector<vector<int>> divs;

int main() {
    
    ll n;
    cin >> n;
    ll maxv = 0;
    map<ll,ll> mapita;
    for(int i = 0;i < n;i++) {
        ll a;
        ll count = 1;
        cin >> a;
        maxv = max(a,maxv);
        auto it = mapita.find(a);
        if(it != mapita.end()) count = it->second + 1;
        mapita.insert(a,count);
    }

    ll encontrado;

    for(int i = 2;i < maxv;i++){
        encontrado = 0;
        for(int j = i;j < maxv;j+=i) {
            
        }
    }

    return 0;
}
