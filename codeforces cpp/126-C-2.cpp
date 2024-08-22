#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long

using namespace std;

void sol() {
    int n;
    int maxV = INT_MIN;
    int odds = 0;
    int totalDiference = 0;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
        maxV = max(maxV, nums[i]);
    }
    for(int i = 0;i < n;i++){
        if((maxV-nums[i])%2==1) odds++;
        totalDiference+= maxV - nums[i];
    }
    
    totalDiference -= odds*3 - 2;

    int days = odds * 2 - 1;



}

int main() {
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
