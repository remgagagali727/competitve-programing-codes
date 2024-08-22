#include <bits/stdc++.h>

#define nl          "\n"
#define pb          push_back
#define ll          long long

using namespace std;

ll trueVal(ll a, ll b){
    a -= b;
    if(a < 0) return -a;
    return a;
}

void sol(){
    int n;
    int expected;
    cin >> n >> expected;
    vector<bool> array(n);
    string s;
    cin >> s;
    int amount = 0;
    for(int i = 0;i < n;i++){
        array[i] = s[i]=='B';
        amount += array[i]?1:0;
    }
    int index;
    char change;
    if(expected==amount){
        cout << 0 << nl;
    } else {
        if(expected > amount) {
            change = 'B';
            for(int i = 0;i < n;i++){
                if(expected==amount) break;
                if(!array[i]){
                    index = i;
                    amount++;
                }
            }
        } else {
            change = 'A';
            for(int i = 0;i < n;i++){
                if(expected==amount) break;
                if(array[i]){
                    index = i;
                    amount--;
                }
            }
        }
        cout << 1 << nl << index+1 << " " << change << nl;
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
