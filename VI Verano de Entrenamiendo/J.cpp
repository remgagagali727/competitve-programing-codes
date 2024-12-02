#include <bits/stdc++.h>

#define ll long long
#define nl "\n"

using namespace std;


int getVal(string s) {
    if(s == "S") return 0;
    if(s == "M") return 1;
    if(s == "L") return 2;
    if(s == "XL") return 3;
    if(s == "XXL") return 4;
    if(s == "XXXL") return 5;
    if(s == "S,M") return 6;
    if(s == "M,L") return 7;
    if(s == "L,XL") return 8;
    if(s == "XL,XXL") return 9;
    if(s == "XXL,XXXL") return 10;
    return -1;
}

void sol() {
    vector<int> xd(6);
    for(int i = 0;i < 6;i++) {
        cin >> xd[i];
    }
    int n;
    cin >> n;
    vector<int> xd2(11);
    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        xd2[getVal(s)]++;
    }
    for(int i = 0;i < 6;i++) {
        xd[i] -= xd2[i];
    }
    for(int i = 0;i < 5;i++) {
        if(xd[i] >= xd2[i]) {
            xd2[i] = 0;
            xd[i] -= xd2[i];
        } else {
            xd2[i] -= xd[i];
            xd[i] = 0;
            xd[i + 1] -= xd2[i];
        }
    }
}


int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    sol();
    return 0;
}