#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 6;
    vector<string> tams(n);
    vector<string> respuesta(0);
    for(int i = 0;i < n;i++) {
        cin >> tams[i];
    }
    for(int i = 0;i < 6;i++) {
        for(int j = 0;j < 6;j++) {
            if(j == i) continue;
            for(int k = 0;k < 6;k++) {
                if(k == j || k == i) continue;
                for(int a = 0;a < 6;a++) {
                    if(a == k || a == j || a == i) continue;
                    for(int b = 0;b < 6;b++) {
                        if(b == a || b == k || b == j || b == i) continue;
                        for(int c = 0;c < 6;c++) {
                            if(c == b || c == a || c == k || c == j || c == i) continue;
                            if(tams[c].size() == tams[b].size() + tams[a].size() - 1) {
                                if(tams[k].size() == tams[i].size() + tams[j].size() - 1) {
                                    if(tams[a][0] == tams[i][0] && tams[a][tams[a].size() - 1] == tams[k][0]
                                        && tams[c][0] == tams[i][tams[i].size() - 1] && tams[c][tams[a].size() - 1] == tams[k][tams[i].size() - 1]
                                        && tams[c][tams[c].size() - 1] == tams[j][0] && tams[k][tams[k].size() - 1] == tams[b][0]
                                        && tams[b][tams[b].size() - 1] == tams[j][tams[j].size() - 1]) 
                                    {   
                                        vector<string> tres;
                                        tres.push_back("");
                                        int size = 0;
                                        int it = 0;
                                        int jt = 0;
                                        for(;it < tams[a].size();it++) {
                                            tres[size].push_back(tams[a][it]);
                                        }
                                        for(;it < tams[c].size();it++) {
                                            tres[size].push_back('.');
                                        }
                                        tres.push_back("");
                                        size++;
                                        for(it = 1;it < tams[i].size() - 1;it++) {
                                            tres[size].push_back(tams[i][it]);
                                            for(jt = 1;jt < tams[a].size() - 1;jt++) {
                                                tres[size].push_back('.');
                                            }
                                            tres[size].push_back(tams[k][it]);
                                            jt++;
                                            for(;jt < tams[c].size();jt++) {
                                                tres[size].push_back('.');
                                            }
                                            tres.push_back("");
                                            size++;
                                        }
                                        for(auto x : tams[c]) {
                                            tres[size].push_back(x);
                                        }
                                        tres.push_back("");
                                        size++;
                                        for(it = 1;it < tams[j].size() - 1;it++) {
                                            for(jt = 1;jt < tams[a].size();jt++) tres[size].push_back('.');
                                            tres[size].push_back(tams[k][it + tams[i].size() - 1]);
                                            for(jt = 1;jt < tams[b].size() - 1;jt++) tres[size].push_back('.');
                                            tres[size].push_back(tams[j][it]);
                                            tres.push_back("");
                                            size++;
                                        }
                                        for(jt = 1;jt < tams[a].size();jt++) tres[size].push_back('.');
                                        for(auto x : tams[b]) tres[size].push_back(x);
                                        tres.push_back("");
                                        size++;
                                        if(respuesta.size() == 0) {
                                            respuesta = move(tres);
                                        } else {
                                            if(tres < respuesta) respuesta = move(tres);
                                        }              
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(respuesta.size() == 0)
        cout << "Impossible\n";
    else {
        for(auto x : respuesta) cout << x << '\n';
    }
}