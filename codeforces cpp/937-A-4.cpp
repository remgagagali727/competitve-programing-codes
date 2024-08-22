#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long

using namespace std;

string answers[] = {"STAIR","PEAK","NONE"};

void sol(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a < b&&b < c) cout << answers[0];
    else if(a < b&&b > c)cout << answers[1];
    else cout << answers[2];
    cout << nl;
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
