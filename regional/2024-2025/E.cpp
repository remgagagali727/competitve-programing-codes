#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> valores;
    vector<int> a(n);
    bool assending = true;
    bool posible = true;
    vector<bool> xxx(n + 1);
    int last = 0;
    for(int i= 0; i <n;i++) {
        cin >> a[i];
        if(a[i] != 0) {
            xxx[a[i]] = true;
            valores.push_back({a[i], i});
            if(last < a[i]) {
                if(!assending) {
                    posible = false;
                }
            } else {
                if(assending) {
                    assending = false;
                }
            }
        }
    }
    int lv = 0, rv = n - 1;
    int p = 1;
    if(posible) {
        int l = 0, r = valores.size() - 1;
        int vl, vr;
        while(l < r) {
            vl = valores[l].first, vr = valores[r].first;
            if(a[lv] == 0 && a[rv] == 0) {
                if(xxx[p]) {
                    // cout << "case 1" << endl;
                    posible = false;
                    break;
                }
                if(vl < vr) {
                    a[lv++] = p++;
                } else {
                    a[rv--] = p++;
                }
            } else if(a[lv] == 0) {
                if(xxx[p]) {
                    if(a[rv] == p) {
                        p++;
                        rv--;
                        r--;
                    } else {
                    // cout << "case 2" << endl;
                        posible = false;
                        break;
                    }
                } else {
                    a[lv++] = p++;
                }
            } else if(a[rv] == 0){
                if(xxx[p]) {
                    if(a[lv] == p) {
                        p++;
                        lv++;
                        l++;
                    } else {
                    // cout << "case 3" << endl;
                        posible = false;
                        break;
                    }
                } else {
                    a[rv--] = p++;
                }
            } else {
                if(xxx[p]) {
                    if(p == a[lv]) {
                        lv++;
                        l++;
                        p++;
                    } else if(p == a[rv]) {
                        rv--;
                        r--;
                        p++;
                    } else {
                        // cout << "case 4" << endl;
                        posible = false;
                        break;    
                    }
                } else {
                        // cout << "case 5" << endl;
                    posible = false;
                    break;
                }
            }
        }
        if(posible) {
            if(l == r) {
                if(valores[l].second - lv < rv - valores[l].second) {
                    for(int i = lv;i < valores[l].second;i++) {
                        if(xxx[p]) {
                            posible = false;
                            break;
                        }
                        a[i] = p++;
                    }
                    for(int i = rv;i > valores[l].second;i--) {
                        if(xxx[p]) p++;
                        a[i] = p++;
                    }
                } else {
                    for(int i = rv;i > valores[l].second;i--) {
                        if(xxx[p]) {
                            posible = false;
                            break;
                        }
                        a[i] = p++;
                    }
                    for(int i = lv;i < valores[l].second;i++) {                        
                        if(xxx[p]) p++;
                        a[i] = p++;
                    }
                    
                }
            } else {
                for(int i = 0;i < n;i++) a[i] = p++;
            }
        }
    }
    if(posible) {
        for(auto x : a) cout << x << " ";
        cout << '\n';
    } else {
        cout << "*\n";
    }
}