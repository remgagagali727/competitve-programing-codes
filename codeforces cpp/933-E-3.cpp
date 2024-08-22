#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long

using namespace std;


int getCosto(int m, int d){
    multiset<int> costos;
    vector<int> valores(m);
    for(int i = 0;i < m;i++){
        cin >> valores[i];
    }
    vector<int> dp(m);
    dp[m-1] = 1;
    costos.insert(valores[m-1]);
    for(int i = m-2;i >= 0;i--){
        int right = i+d+1;
        dp[i] = valores[i] + (int)(costos.begin()) + 1;
        if(right<=m-1) costos.erase(valores[right]);
        costos.insert(dp[i]);
    }
    return dp[0];
}


void sol(){
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<int> costos(n);
    vector<int> totales(n-k+1);
    for(int i = 0;i < n;i++){
        costos[i] = getCosto(m,d);
    }
    totales[0] = 0;
    for(int i = 0;i < k;i++){
        totales[0]+=costos[i];
    }
    for(int i = 1;i < n-k) {

    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }    
    return 0;
}
