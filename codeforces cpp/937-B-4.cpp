#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long

using namespace std;

string answers[] = {"STAIR","PEAK","NONE"};

void sol(){
    int n;
    cin >> n;
    n *= 2;
    bool value;
    for(int i = 0;i < n;i++){
        value = (i/2)%2==0;
        for(int j = 0;j < n;j++){
            bool tempValue = value ^ ((j/2)%2!=0);
            if(tempValue) cout << "#";
            else cout << ".";
        }
        cout << nl;
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
