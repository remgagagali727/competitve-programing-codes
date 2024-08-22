#include <bits/stdc++.h>

#define nl          "\n"
#define pb          push_back
#define ll          long long

using namespace std;

int vals[] =  {15,10,6,3,1};

int fastest(int n, int index){
    if(n==0) return 0;
    if(index == 5) return 10;
    return min(fastest(n%vals[index],index+1)+n/vals[index],fastest(n,index+1));
}

void sol(){
    int n;
    cin >> n;
    int ans = n/15;
    n%=15;
    if(ans>=1) {
        n+=15;
        ans--;
    }
    ans+=fastest(n,0);
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
