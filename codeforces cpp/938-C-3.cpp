#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    
    int n, k;
    int count = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    int front = (k - 1)/2 + 1;
    int end = k / 2;

    int i, m, j;
    for(i = 0;i < n;i++){
        front -= a[i];
        m = i;
        if(front < 0){
            a[i] = -front;
            break;
        }
        count++;
        //cout << "barco d" << count;
    }

    if(front <= 0) {

    

    //cout << end << "," << front << nl;

    //cout << nl << "m" << m << nl;

        for(j = n - 1;j >= m;j--){
            //cout << j << nl;
            end-=a[j];
            if(end < 0)
                break;
            count++;
            //cout << "barco a" << count;
        }
    }

    cout << count << nl;

}

int main() {
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
