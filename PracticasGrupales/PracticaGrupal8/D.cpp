#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, w;
    cin >> n >> k >> w;
    for(int i = 0;i < n;i++) {
        char we; cin >> we;
        if(we == 'Y' || w == 0) {
            w++;
            k--;
            cout << "Y" << ' ';
        } else {
            cout << "N" << ' ';
        }
        cin >> we;
        if(we == 'Y' || k == 0) {
            k++;
            w--;
            cout << "Y" << '\n';
        } else {
            cout << "N" << '\n';
        }
    }
}