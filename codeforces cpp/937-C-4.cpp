#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long

using namespace std;

void sol(){
    string hour;
    cin >> hour;
    int hourInt = (hour[0]-48)*10 + hour[1]-48;
    if(hourInt < 12) {
        if(hourInt == 0) {
            hour[0] = '1'; hour[1] = '2';
        }
        cout << hour << " AM" << nl;
    } else {
        if(hourInt != 12) {
            hourInt %=12;
            hour[0] = hourInt/10+48; hour[1] = hourInt%10+48;
        }
        cout << hour << " PM" << nl;
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
