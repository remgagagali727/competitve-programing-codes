#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    vector<int> valores(4);
    ll ans = 0;

    for(int i = 0;i < 4;i++){
        cin >> valores[i];
    }

    for(int i = 0;i < 4;i++){
        ans+=valores[i]/2;
    }

    if(valores[0] % 2 == 1 && valores[1] % 2 == 1 && valores[2] % 2 == 1) ans++;

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
