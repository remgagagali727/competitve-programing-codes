#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long

using namespace std;

void sol(){
    int n; 
    cin >> n;
    string s;
    cin >> s;
    int ans;
    for(int i = 1;i <= n;i++){
        if(n%i!=0) continue;
        vector<set<int>> ayuda(i);
        int flag = 0;
        for(int j = 0;j < n/i;j++){
            
            for(int k = 0;k < i;k++){
                ayuda[k].insert(s[j*i+k]);
                flag = max((int)ayuda[k].size(), flag);
                if(flag == 2) break;
            }
            if(flag == 2) break;
        }
        if(flag<=1) {
            ans = i;
            break;
        }
    }
    cout << ans << nl;
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
